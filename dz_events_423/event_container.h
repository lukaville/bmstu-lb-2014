#ifndef EVENT_CONTAINER_H
#define EVENT_CONTAINER_H

#include "event.h"
#include "node.h"
#include <QAbstractListModel>
#include <QDebug>

class EventList : public QAbstractListModel
{
    Q_OBJECT
private:
    Node* root_node = NULL;
    QString name = "";
public:
    explicit EventList(QObject *parent = 0) : QAbstractListModel(parent) {}

    EventList(QString name) {
        this->name = name;
    }

    ~EventList() {
        clear();
    }

    EventList(const EventList &el){
        if (el.size() != NULL) {
            for(int i = 0; i < el.size(); ++i) {
                this->add(el.get(i));
            }
        }
        this->name = el.name;
    }

    EventList& operator=(const EventList& right) {
        if (this == &right) {
            return *this;
        }

        clear();

        for(int i = 0; i < right.size(); ++i) {
            this->add(right.get(i));
        }

        return *this;
    }

    void clear() {
        if (size() != 0) {
            Node* current_node = root_node;
            root_node = NULL;
            while(current_node->getNext() != NULL) {
                Node* temp = current_node->getNext();

                delete current_node;

                current_node = temp;
            }

            delete current_node;
        }
    }

    void add(Event *e)
    {
        if (root_node == NULL) {
            root_node = new Node(e);
        } else {
            Node* last_node = root_node;
            while(last_node->getNext() != NULL) {
                last_node = last_node->getNext();
            }
            last_node->setNext(new Node(e));
        }
    }

    Event* get(int index) const {
        if (root_node != NULL) {
            Node* current_node = root_node;
            for(int i = 0; i < index; ++i) {
                if(current_node->getNext() != NULL) {
                    current_node = current_node->getNext();
                } else {
                    return NULL;
                }
            }
            return current_node->getData();
        } else {
            return NULL;
        }
    }

    void remove(int index) {
        if (index < size()) {
            if (index == 0) {
                Node* new_root = root_node->getNext();

                delete root_node->getData();
                delete root_node;

                root_node = new_root;

            } else {
                Node* current_prev_node = root_node;
                for(int i = 0; i < index - 1; ++i) {
                    if(current_prev_node->getNext() != NULL) {
                        current_prev_node = current_prev_node->getNext();
                    } else {
                        return;
                    }
                }

                Node* new_next = current_prev_node->getNext()->getNext();

                delete current_prev_node->getNext()->getData();
                delete current_prev_node->getNext();

                current_prev_node->setNext(new_next);
            }
        }
    }

    int size() const {
        if (root_node == NULL) {
            return 0;
        } else {
            int i = 1;
            Node* current_node = root_node;
            while(current_node->getNext() != NULL) {
                current_node = current_node->getNext();
                ++i;
            }
            return i;
        }
    }

    friend QDebug operator<< (QDebug d, EventList &el) {
        d << "[";
        for(int i = 0; i < el.size(); ++i) {
            d << el.get(i)->getName();
        }
        d << "]";
        return d;
    }

    EventList* search(QString query);

    friend EventList operator+(EventList& left, EventList& right) {
        EventList result(left.getName());
        for(int i = 0; i < left.size(); ++i) {
            result.add(left.get(i));
        }
        for(int i = 0; i < right.size(); ++i) {
            result.add(right.get(i));
        }
        return result;
    }

    QString getName() const
    {
        return name;
    }

    void setName(const QString &value)
    {
        name = value;
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const {
        return size();
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const {
        if (role == Qt::DisplayRole) {
            return get(index.row())->getName();
        }
        return QVariant();
    }
};

#endif // EVENT_CONTAINER_H
