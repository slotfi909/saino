#ifndef STRUCTSAINO_H
#define STRUCTSAINO_H

#include <QByteArray>
#include <QStringList>
#include <cstdint>
#include <QList>
#include <QSerialPort>
#include <QRandomGenerator>
#include <QDebug>
#include <QVariant>
#include <QDataStream>

#define LOG_CURRENT_FUNCTION() qDebug() << "Current function: " << __FUNCTION__ << " at line " << __LINE__

struct units_info{
    // might need a flag to indicate wether return value is int or float
    // if needed, must be integrated to sainto_packet class
    public:
        uint8_t ID;
        uint8_t reserve;
        uint32_t data;
        uint32_t factor;

        // public functions
        QVariant getTrueValue();
};

inline QVariant units_info::getTrueValue()
{
    if(this->factor == 0)
        return QVariant(this->data);
    else
        return QVariant(this->data / this->factor);
}

#define VALID_HEADER 0xA5
#define VALID_FOOTER 0x55
#define RESERVE_VALUE 0
#define PACKET_MIN_LENGTH 19


struct saino_packet{

    public:
        QList<QString>::const_reference get_unit_name(uint8_t idx) const;

    private:
        QStringList units_names = {"zero idx", "OIL PRESSURE", "OIL TEMPRATURE", "FUEL FLOW",
        "FUEL", "EGT", "TORQUE", "INDICATED POWER", "Frictional Power", "Thermal Efficiency",
        "Air-fuel Ratio", "MOTOR SPEED"};

    QByteArray header;
    uint8_t msg_counter;
    uint8_t ID_number;
    QList<struct units_info> recieved_units_info;
    uint16_t checksum;
    uint8_t footer;

    // private functions
    bool _packetHeaderChecker();
    bool _packetFooterChecker();
    bool _packetChecksumChecker();


public:
    // functions

        // misc
            void fillWithRandomData();

        // constructor
            // saino_packet();

        // getters
            QVariant getUnitTrueValue(uint8_t unit_idx);

        // setters
            bool SetByQbyteArray(QByteArray input); // can return bool

        // helpers
            bool packetIsValid();

            uint8_t getMsg_counter() const;
            uint8_t getID_number() const;
};
// this struct is defined both here and in settingsdialog.h
struct Settings {
    QString name;
    qint32 baudRate;
    QString stringBaudRate;
    QSerialPort::DataBits dataBits;
    QString stringDataBits;
    QSerialPort::Parity parity;
    QString stringParity;
    QSerialPort::StopBits stopBits;
    QString stringStopBits;
    QSerialPort::FlowControl flowControl;
    QString stringFlowControl;
    bool localEchoEnabled;
};

inline QList<QString>::const_reference saino_packet::get_unit_name(uint8_t idx) const
{
    assert(idx > 0);
    return this->units_names[idx];
}

inline uint8_t saino_packet::getID_number() const
{
    return ID_number;
}

inline uint8_t saino_packet::getMsg_counter() const
{
    return msg_counter;
}

inline bool saino_packet::_packetHeaderChecker()
{
    QByteArray header_byte_array;
    header_byte_array.append(VALID_HEADER);
    for(int i = 0; i < 4; i++){
        if(this->header[i] != header_byte_array[0])
            return false;
    }
    return true;
}

inline bool saino_packet::_packetFooterChecker()
{
    if(int(this->footer) != VALID_FOOTER)
        return false;
    return true;
}

inline bool saino_packet::_packetChecksumChecker()
{
    uint16_t checksum = 0;
    checksum += this->msg_counter;
    checksum += this->ID_number;
    for(int unit_idx = 0; unit_idx < this->ID_number; unit_idx ++){
        checksum += this->recieved_units_info[unit_idx].ID;
        checksum += this->recieved_units_info[unit_idx].data;
        checksum += this->recieved_units_info[unit_idx].factor;
        checksum += this->recieved_units_info[unit_idx].reserve;
    }
    qDebug() << "recieved checksum: " << this->checksum;
    qDebug() << "calculated checksum: " << checksum;
    if(checksum == this->checksum)
        return true;
    return false;
}

inline void saino_packet::fillWithRandomData()
{
    QByteArray temp_byte_array;
    this->header.resize(4);
    for(int i = 0; i < 4; i++)
        this->header[i] = (VALID_HEADER);
    this->msg_counter = QRandomGenerator::global()->generate();
    this->ID_number = QRandomGenerator::global()->generate();
    struct units_info temp_units_info;
    uint8_t counter = 0;
    for(int i = 0; i < this->ID_number; i++){
        temp_units_info.ID = ++counter;
        temp_units_info.reserve = 0;
        temp_units_info.data = QRandomGenerator::global()->generate() % 200;
        if( i == 1)
            qDebug() << "random data generated for oil pressure: " << temp_units_info.data;
        temp_units_info.factor = 0;
        this->recieved_units_info.append(temp_units_info);
    }
    uint16_t checksum = 0;
    for(int unit_idx = 0; unit_idx < this->ID_number; unit_idx++){
        checksum += this->recieved_units_info[unit_idx].ID;
        checksum += this->recieved_units_info[unit_idx].data;
        checksum += this->recieved_units_info[unit_idx].factor;
        checksum += this->recieved_units_info[unit_idx].reserve;
    }
    this->checksum = checksum;
    this->footer = VALID_FOOTER;
}

inline QVariant saino_packet::getUnitTrueValue(uint8_t unit_idx)
{
    // in protocol, units start from index one
    // but we are using qlist so we need to subtract one
    // from each unit read request
    unit_idx -= 1;
    // also, we don't have unit 10(hex)
    // so we need to subtract again if unit_idx is larger than 10(hex)
    if(unit_idx >= 0x11)
        unit_idx -= 1;
    if (this->recieved_units_info.length() > unit_idx){
        QVariant return_val = this->recieved_units_info[unit_idx].getTrueValue();
        return return_val;
    }
    qWarning() << "requested unit_idx is more than units available";
    qDebug()  << "avilable uints: " << this->recieved_units_info.length();
    qDebug() << "requested unit: " << unit_idx;
    LOG_CURRENT_FUNCTION();
    return 1;
}

inline bool saino_packet::SetByQbyteArray(QByteArray input)
{
    qDebug() << "input.length(): " << input.length();
    if(input.length() < 4)  return false;
    this->header = input.mid(0, 4);
    qDebug() << "header complete";

    if(input.length() < 5)  return false;
    this->msg_counter = input.mid(4, 1).toHex().toInt(nullptr, 16);
    qDebug() << "msg counter complete";

    if(input.length() < 6)  return false;
    this->ID_number = input.mid(5,1).toHex().toInt(nullptr,16);
    qDebug() << "ID number complete";

    this->recieved_units_info.clear();
    uint32_t last_byte = 6;
    units_info temp_unit_info;
    for(int unit_idx = 0; unit_idx < this->ID_number; unit_idx++){
        // ID
            temp_unit_info.ID = input.mid(last_byte, 1).toHex().toInt(nullptr,16);
            last_byte += 1;
        // RESERVE
            temp_unit_info.reserve = input.mid(last_byte, 1).toHex().toInt(nullptr,16);
            last_byte += 1;
        // DATA
            // data needs to be interpreted as little endian
            QDataStream data_stream(input.mid(last_byte, 4));
            data_stream.setByteOrder(QDataStream::LittleEndian);
            uint32_t data_little_endian;
            data_stream >> data_little_endian;
            temp_unit_info.data = data_little_endian;
            last_byte += 4;
        // FACTOR
            // factor also needs to be interpreted as little endian
            QDataStream factor_stream(input.mid(last_byte, 4));
            factor_stream.setByteOrder(QDataStream::LittleEndian);
            uint32_t factor_little_endian;
            factor_stream >> factor_little_endian;
            temp_unit_info.factor = factor_little_endian;
            last_byte += 4;

        // append created unit info to list in saino_packet
            this->recieved_units_info.append(temp_unit_info);
    }

    if(input.length() < last_byte + 2)  return false;
    // checksum also needs to be interpreted as little endian!
    QDataStream checksum_stream(input.mid(last_byte, 4));
    checksum_stream.setByteOrder(QDataStream::LittleEndian);
    uint16_t checksum_little_endian;
    checksum_stream >> checksum_little_endian;
    this->checksum = checksum_little_endian;
    last_byte += 2;
    qDebug() << "checksum complete";

    if(input.length() < last_byte + 1)  return false;
    this->footer = input.mid(last_byte, 1).toHex().toInt(nullptr,16);
    qDebug() << "footer complete";
    qDebug() << "last byte: " << last_byte;
    if(last_byte + 1 == input.length())
        return true;
    else
        return false;
}

inline bool saino_packet::packetIsValid()
{
    bool is_valid = false;
    if(this->_packetHeaderChecker()){
        if(this->_packetFooterChecker()){
            if(this->_packetChecksumChecker()){
                is_valid = true;
            }
        }
    }
    return is_valid;
}


#endif // STRUCTSAINO_H
