#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <ctime>
#include <iostream>

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
    static std::string EVENT_TYPE_TITLES[8] = {"Неизвестный тип",
                                      "Конференция",
                                      "Workshop",
                                      "Лекция",
                                      "Мастер-класс",
                                      "Тренинг",
                                      "Дискуссия",
                                      "Вебинар"};

    std::string name;
    std::string city;
    time_t timestamp;
    int eventType;

public:
    Event(std::string name, std::string city, time_t timestamp, int eventType)
    {
        this->name = name;
        this->city = city;
        this->timestamp = timestamp;
        this->eventType = eventType;
    }

    std::string getName() const
    {
        return name;
    }

    void setName(const std::string &value)
    {
        name = value;
    }

    std::string getCity() const
    {
        return city;
    }

    void setCity(const std::string &value)
    {
        city = value;
    }

    std::time_t getTimestamp() const
    {
        return timestamp;
    }

    void setTimestamp(const time_t &value)
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
        output << e.getName() << std::endl;
        output << "===========================" << std::endl;
        output << e.getCity() << std::endl;
        output << e.getTimestamp() << std::endl;
        output << e.getEventType() << std::endl << std::endl;

        return output;
    }

    static std::string getEventTypeTitle(int eventTypeCode) {
        return EVENT_TYPE_TITLES[eventTypeCode];
    }
};

#endif // EVENT_H
