#include "sainoprotocol.h"
#include <QSerialPort>

bool sainoprotocol::getConnected() const
{
    return _connected;
}

QString sainoprotocol::getSerialPortLastError() const
{
    return this->_serialClient.errorString();
}

uint8_t sainoprotocol::getMsg_counter() const
{
    return this->_recieved_packet.getMsg_counter();
}

saino_packet sainoprotocol::recieved_packet() const
{
    return _recieved_packet;
}

void sainoprotocol::reset_num_recieved_packets()
{
    this->_seen_packet.fill(false);
    this->_num_recieved_packets = 0;
    this->_has_overflowed = false;
}



bool sainoprotocol::openSerialPort()
{
    bool opening_result = this->_serialClient.open(QIODevice::ReadOnly);
    if(opening_result){
        this->_connected = true;
        this->_serialClient.clear();
    }
    return opening_result;
}

bool sainoprotocol::closeSerialPort()
{
    this->_serialClient.clearError();
    this->_serialClient.close();
    QSerialPort::SerialPortError last_error = this->_serialClient.error();
    if(last_error == QSerialPort::NoError)
        return true;
    else
        return false;
}

QVariant sainoprotocol::getUnitTrueValue(uint8_t unit_idx)
{
    return this->_recieved_packet.getUnitTrueValue(unit_idx);
}

void sainoprotocol::fillWithRandomData()
{
    this->_num_recieved_packets++;
    struct saino_packet new_packet;
    new_packet.fillWithRandomData();
    // this->_recieved_packet.fillWithRandomData();
    this->_recieved_packet = new_packet;
    emit this->new_packet_arrived();
}

void sainoprotocol::setSrialPortSettings(Settings input_setting)
{
    this->_serialClient.setPortName(input_setting.name);
    this->_serialClient.setBaudRate(input_setting.baudRate);
    this->_serialClient.setDataBits(input_setting.dataBits);
    this->_serialClient.setParity(input_setting.parity);
    this->_serialClient.setStopBits(input_setting.stopBits);
    this->_serialClient.setFlowControl(input_setting.flowControl);
    return;
}

sainoprotocol::sainoprotocol()
{
    connect(&this->_serialClient, &QSerialPort::readyRead, this, &sainoprotocol::_serialPortNewDataArrived);
    this->_internal_buffer.clear();
}

uint8_t sainoprotocol::getNum_recieved_packets() const
{
    return this->_num_recieved_packets;
}

void sainoprotocol::_serialPortNewDataArrived()
{
    /*
    ////////////////////
    // first the algorithm needs to read all input data and append it to internal buffer
    // then the algorithm, must find the very first header in list
        // header_idx = find_header_idx(internal_buffer)
    // then in a little for loop, we must check for footer
        // for(int i =0; i<error_margin;i++){
            // footer_idx = find_footer_idx(internal_buffer)
            // isvalid = check_packet+_validity(header_idx, footer_idx)
            // if(isvalid)
                // break; found = true;
            // }
        // if found == false
            // find next header and remove all bytes before it
        // if found == true
            // extract these bytes and emit found_packet

    ////////////////////
    // last_header_idx = 0
    // while(input.indexOf(HEADER_BYTE_ARRAY, last_header_idx) != -1){
        // new_header_idx = input.indexOf(HEADER_BYTE_ARRAY, last_header_idx)
        // last_footer_idx = new_header_idx
        // for(int i = 0; i<err_margin;i++){
            // footer_idx = input.indexOf(FOOTER_BYTE_ARRAY, last_footer_idx)
            // if footer_idx == -1
                // return no footer
            // isvalid = checkpacketvalidity(header_idx, footer_idx)
            // if isvalid
                // input.remove(header, footer-header)
                // break
            // if isvalid == false
                // do not do anything
        // }
    // }

    ////////////////////
    /// */

    // it shouldn't read all the data it can, but there must be some sort of
    // checking before reading the data
    // all of first packet and half of next packet might come together

    if(_has_overflowed)
        return;
    if(this->_num_recieved_packets >= 255){
        this->_has_overflowed = true;
        this->_serialClient.clear();
        this->_internal_buffer.clear();
        emit this->message_overflow();
        return;
    }
    QByteArray recieved_data = this->_serialClient.readAll();
    this->_internal_buffer.append(recieved_data);

    // skip if footer hasn't arrived
    QByteArray footer;
    footer.append(VALID_FOOTER);
    if(this->_internal_buffer.contains(footer) == false)
        return;

    // else, try to update structure packet
    qDebug() << "packet footer recieved, packet: " << this->_internal_buffer.toHex();

    QByteArray header;
    for(int i =0; i<4; i++)
        header.append(VALID_HEADER);

    int header_idx = 0;
    int footer_idx = 0;
    while(this->_internal_buffer.indexOf(header, header_idx) != -1){
        header_idx = this->_internal_buffer.indexOf(header, header_idx);
        this->_internal_buffer.remove(0, header_idx);
        footer_idx = header_idx;
        for(int i = 0; i<this->_footer_error_margin; i++){
            footer_idx = this->_internal_buffer.indexOf(footer, footer_idx + 1);
            qDebug() << "i(footer error margin checker): " << i;
            qDebug() << "footer_idx: " << footer_idx;
            if (footer_idx == -1){ // all footers are extracted
                return;
            }
            QByteArray extracted_byte_array = this->_internal_buffer.mid(header_idx, footer_idx - header_idx + 1);
            qDebug() << "extracted_byte_array: " << extracted_byte_array.toHex();
            if(extracted_byte_array == QByteArray("a5a5a5a555"))
                qDebug() << "test";
            bool update_result = this->_recieved_packet.SetByQbyteArray(extracted_byte_array);
            if(update_result == true){
                this->_internal_buffer.remove(header_idx, footer_idx - header_idx + 1);
                if(this->_recieved_packet.packetIsValid()){
                    qDebug() << "packet is valid!";
                    uint8_t packet_msg_counter = this->_recieved_packet.getMsg_counter();
                    qDebug() << "packet_msg_counter: " << packet_msg_counter;
                    qDebug() << "this->_seen_packet.at(packet_msg_counter): " << this->_seen_packet.at(packet_msg_counter);
                    if(this->_seen_packet.at(packet_msg_counter) == false){
                        this->_num_recieved_packets++;
                        this->_seen_packet[packet_msg_counter] = true;
                        emit this->new_packet_arrived();
                    }
                }
            }
        }
    }
}
