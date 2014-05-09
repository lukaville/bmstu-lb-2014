#ifndef NODE_H
#define NODE_H

#include "event.h"

class Node
{
private:
    Node* next = NULL;
    Event* data = NULL;
public:
    Node();
    ~Node();
    Node(Event* data);
    Node *getNext() const;
    void setNext(Node *value);
    Event *getData() const;
    void setData(Event *value);
};

#endif // NODE_H
