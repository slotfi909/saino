#ifndef SAINOPROTOCOL_H
#define SAINOPROTOCOL_H

#include <QSerialPort>
#include "structsaino.h"
#include <QObject>
#include <qDebug>
#include <QList>
#include <QByteArray>
class sainoprotocol: public QObject
{
    Q_OBJECT

private:
    QByteArray _internal_buffer;
    QSerialPort _serialClient;
    bool _has_overflowed = false;
    uint8_t _footer_error_margin = 5;
    uint16_t _num_recieved_packets = 0;
    uint8_t _couldnt_update_by_bytearray = 0;
    QList<bool> _seen_packet = QList<bool>(256, false);
    struct saino_packet _recieved_packet;
    bool _connected = false;
    enum _errors{MALFORMED_PACKET};

public:
    // misc
    bool openSerialPort();
    bool closeSerialPort();
    //setters
        void setSrialPortSettings(Settings input_setting);

    // constructor
        sainoprotocol();


    // getters
        uint8_t getNum_recieved_packets() const;
        bool getConnected() const;
        QString getSerialPortLastError() const;
        uint8_t getMsg_counter() const;
        QVariant getUnitTrueValue(uint8_t unit_idx);
        saino_packet recieved_packet() const;

    // setters
        void reset_num_recieved_packets();

    // signals

    signals:
        void new_packet_arrived();
        void message_overflow();

    // slots
        // private
        private slots:
            void _serialPortNewDataArrived();

        // public
        public slots:
            void fillWithRandomData();

};



#endif // SAINOPROTOCOL_H
