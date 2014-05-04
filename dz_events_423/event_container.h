#ifndef EVENT_CONTAINER_H
#define EVENT_CONTAINER_H

#include "simpleevent.h"
#include <QList>

class EventArray
{
private:
    std::vector<SimpleEvent> events;
public:
    EventArray();
    ~EventArray();
};

#endif // EVENT_CONTAINER_H
