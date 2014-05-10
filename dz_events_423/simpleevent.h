#ifndef SIMPLEEVENT_H
#define SIMPLEEVENT_H

#include "event.h"
#include <QString>

class SimpleEvent : public Event
{
public:
    SimpleEvent();
    SimpleEvent(QString name, QString city, QDateTime timestamp, int eventType) : Event(name, city, timestamp, eventType) {}

    QString getDebugData() {
        return "";
    }
};

#endif // SIMPLEEVENT_H
