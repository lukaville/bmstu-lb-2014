#ifndef EVENTARRAY_H
#define EVENTARRAY_H

#include "event.h"
#include <vector>

class EventArray
{
private:
    vector<Event> events;
public:
    EventArray();
    ~EventArray();
};

#endif // EVENTARRAY_H
