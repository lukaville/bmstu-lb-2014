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

template<typename TimeType = std::time_t, typename CityType = std::string>
class Event
{
private:
    std::string name;
    CityType city;
    TimeType timestamp;
    int eventType;
public:
    Event(std::string name, CityType city, TimeType timestamp, int eventType)
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

    void setCity(const CityType &value)
    {
        city = value;
    }

    std::time_t getTimestamp() const
    {
        return timestamp;
    }

    void setTimestamp(const TimeType &value)
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

    void print()
    {
        std::cout << name << std::endl;
        std::cout << "===========================" << std::endl;
        std::cout << city << std::endl;
        std::cout << timestamp << std::endl;
        std::cout << eventType << std::endl << std::endl;
    }
};

#endif // EVENT_H
