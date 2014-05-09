#include "node.h"

Node *Node::getNext() const
{
    return next;
}

void Node::setNext(Node *value)
{
    next = value;
}

Event *Node::getData() const
{
    return data;
}

void Node::setData(Event *value)
{
    data = value;
}
Node::Node()
{
}

Node::~Node()
{
    //delete data;
}

Node::Node(Event *data)
{
    this->data = data;
}
