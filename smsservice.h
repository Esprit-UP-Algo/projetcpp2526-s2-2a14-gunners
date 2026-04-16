#ifndef SMSSERVICE_H
#define SMSSERVICE_H

#include <QString>

class SmsService
{
public:
    SmsService();
    static void sendSMS(QString phoneNumber, QString message);
};

#endif // SMSSERVICE_H
