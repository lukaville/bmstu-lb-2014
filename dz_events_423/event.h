#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <ctime>
#include <iostream>
#include <QDate>
#include <QString>

#define EVENT_TYPE_UNKNOWN 0
#define EVENT_TYPE_CONFERENCE 1
#define EVENT_TYPE_WORKSHOP 2
#define EVENT_TYPE_LECTION 3
#define EVENT_TYPE_MASTERCLASS 4
#define EVENT_TYPE_TRAINING 5
#define EVENT_TYPE_DISCUSSION 6
#define EVENT_TYPE_WEBINAR 7

class Event
{
private:
    QString EVENT_TYPE_TITLES[8] = {"Неизвестный тип",
                                      "Конференция",
                                      "Семинар",
                                      "Лекция",
                                      "Мастер-класс",
                                      "Тренинг",
                                      "Круглый стол",
                                      "Вебинар"};

    QString name;
    QString city;
    QDate timestamp;
    int eventType;

public:
    Event() {}

    Event(QString name, QString city, QDate timestamp, int eventType)
    {
        this->name = name;
        this->city = city;
        this->timestamp = timestamp;
        this->eventType = eventType;
    }

    QString getName() const
    {
        return name;
    }

    void setName(const QString &value)
    {
        name = value;
    }

    QString getCity() const
    {
        return city;
    }

    void setCity(const QString &value)
    {
        city = value;
    }

    QDate getTimestamp() const
    {
        return timestamp;
    }

    void setTimestamp(const QDate &value)
    {
        timestamp = value;
    }

    int getEventType() const
    {
        return eventType;
    }

    void setEventType(int value)
    {
        eventType = value;
    }

    friend std::ostream &operator<<(std::ostream &output, Event &e){
        output << e.getName().toStdString() << std::endl;
        output << "===========================" << std::endl;
        output << e.getCity().toStdString() << std::endl;
        output << e.getTimestamp().toString().toStdString() << std::endl;
        output << e.getEventTypeTitle(e.getEventType()).toStdString() << std::endl << std::endl;

        return output;
    }

    QString getEventTypeTitle(int eventTypeCode) {
        return EVENT_TYPE_TITLES[eventTypeCode];
    }

    virtual QString getDebugData() = 0;
};

#endif // EVENT_H
