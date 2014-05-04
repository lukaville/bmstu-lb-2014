#ifndef SIMPLEEVENT_H
#define SIMPLEEVENT_H

#include "event.h"
#include <QString>

class SimpleEvent : public Event
{
public:
    SimpleEvent();

    QString getDebugData() {
        return "";
    }
};

#endif // SIMPLEEVENT_H
