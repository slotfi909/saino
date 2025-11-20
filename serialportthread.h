#ifndef SERIALPORTTHREAD_H
#define SERIALPORTTHREAD_H

#include <QObject>

class serialPortThread : public QObject
{
    Q_OBJECT
public:
    explicit serialPortThread(QObject *parent = nullptr);

signals:
};

#endif // SERIALPORTTHREAD_H
