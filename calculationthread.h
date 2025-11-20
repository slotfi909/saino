#ifndef CALCULATIONTHREAD_H
#define CALCULATIONTHREAD_H

#include <QObject>

class calculationThread : public QObject
{
    Q_OBJECT
public:
    explicit calculationThread(QObject *parent = nullptr);

signals:
};

#endif // CALCULATIONTHREAD_H
