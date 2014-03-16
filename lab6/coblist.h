#ifndef COBLIST_H
#define COBLIST_H

#include <deque>
#include "cobject.h"
#include "position.h"

class CObList
{
private:
    std::deque<CObject*> list;
public:
    CObList() {}

    void AddTail(CObject* obj) {
        list.push_back(obj);
    }

    void AddHead(CObject* obj) {
        list.push_front(obj);
    }

    POSITION GetHeadPosition() {
        return new _POSITION(-1);
    }

    CObject* GetNext(POSITION &pos) {
        if ((*pos).getI() + 1 >= list.size()) {
            pos = NULL;
        };
        (*pos).plus();
        return list.at(pos->getI());
    }

};

#endif // COBLIST_H
