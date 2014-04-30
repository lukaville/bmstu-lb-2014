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
class Event : public CObject
{
private:
	std::string name;
	CityType city;
	TimeType timestamp;
	int eventType;
public:
	Event() {
		this->name = "Тест";
		this->city = "Город";
		this->timestamp = 0;
		this->eventType = 0;
	}

	Event(std::string name, CityType city, TimeType timestamp, int eventType)
	{
		this->name = name;
		this->city = city;
		this->timestamp = timestamp;
		this->eventType = eventType;
	}

	Event(const Event &e) {
		this->name = e.getName();
		this->city = e.getCity();
		this->timestamp = e.getTimestamp();
		this->eventType = e.getEventType();
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

	friend std::ostream &operator<<(std::ostream &output, Event &e){
		output << std::endl << e.getName() << std::endl;
		output << "===========================" << std::endl;
		output << e.getCity() << std::endl;
		output << e.getTimestamp() << std::endl;
		output << e.getEventType() << std::endl << std::endl;

		return output;
	}

	bool operator<(Event<>* left) {
		return this->getTimestamp() < right->getTimestamp();
	}
};

#endif // EVENT_H