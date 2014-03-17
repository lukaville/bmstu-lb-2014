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
        return new _POSITION(0);
    }

    CObject* GetNext(POSITION &pos) {
        CObject* result = list.at(pos->getI());

        if ((unsigned) (*pos).getI() + 1 >= list.size()) {
            pos = NULL;
            //return list.at(0);
        } else {
            (*pos).plus();
        };


        return result;
    }

    void RemoveAt(POSITION pos) {
        list.erase(list.begin() + pos->getI());
    }

};

#endif // COBLIST_H
