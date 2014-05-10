#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <ctime>
#include <iostream>
#include <QDateTime>
#include <QString>

enum EventType { EVENT_TYPE_UNKNOWN,
                 EVENT_TYPE_CONFERENCE,
                 EVENT_TYPE_WORKSHOP,
                 EVENT_TYPE_LECTION,
                 EVENT_TYPE_MASTERCLASS,
                 EVENT_TYPE_TRAINING,
                 EVENT_TYPE_DISCUSSION,
                 EVENT_TYPE_WEBINAR,
                 EVENT_TYPES_COUNT };

constexpr static const char* EVENT_TYPE_TITLES[EVENT_TYPES_COUNT] = {"Неизвестный тип",
                                      "Конференция",
                                      "Семинар",
                                      "Лекция",
                                      "Мастер-класс",
                                      "Тренинг",
                                      "Круглый стол",
                                      "Вебинар"};

class Event
{
private:

    QString name;
    QString city;
    QDateTime timestamp;
    int eventType;

public:
    Event() {}
    virtual ~Event() {}

    Event(QString name, QString city, QDateTime timestamp, int eventType)
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

    QDateTime getTimestamp() const
    {
        return timestamp;
    }

    void setTimestamp(const QDateTime &value)
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
        return QString(EVENT_TYPE_TITLES[eventTypeCode]);
    }

    virtual QString getDebugData() = 0;
};

#endif // EVENT_H
