#ifndef EVENT_CONTAINER_H
#define EVENT_CONTAINER_H

#include "event.h"
#include "node.h"
#include <QAbstractListModel>
#include <QDebug>
#include <QIcon>

class EventList : public QAbstractListModel
{
    Q_OBJECT
private:
    Node* root_node = nullptr;
    QString name = "";
    bool isActive = true;
    bool isDebug = false;
    QString debugInformation = "";

public:
    explicit EventList(QObject *parent = 0) : QAbstractListModel(parent) {}

    EventList(QString name) {
        this->name = name;
    }

    ~EventList() {
        clear();
    }

    EventList(const EventList &el) : QAbstractListModel() {
        if (el.size() != 0) {
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
        beginRemoveRows(QModelIndex(), 0, 0);
        if (size() != 0) {
            Node* current_node = root_node;
            root_node = nullptr;
            while(current_node->getNext() != nullptr) {
                Node* temp = current_node->getNext();

                delete current_node;

                current_node = temp;
            }

            delete current_node;
        }
        endRemoveRows();
    }

    void add(Event *e)
    {
        beginInsertRows(QModelIndex(), 0, 0);
        if (root_node == 0) {
            root_node = new Node(e);
        } else {
            Node* last_node = root_node;
            while(last_node->getNext() != nullptr) {
                last_node = last_node->getNext();
            }
            last_node->setNext(new Node(e));
        }
        endInsertRows();
    }

    Event* get(int index) const {
        if (root_node != nullptr) {
            Node* current_node = root_node;
            for(int i = 0; i < index; ++i) {
                if(current_node->getNext() != nullptr) {
                    current_node = current_node->getNext();
                } else {
                    return nullptr;
                }
            }
            return current_node->getData();
        } else {
            return nullptr;
        }
    }

    void remove(int index) {
        beginRemoveRows(QModelIndex(), 0, 0);
        if (index < size()) {
            if (index == 0) {
                Node* new_root = root_node->getNext();

                delete root_node;

                root_node = new_root;

            } else {
                Node* current_prev_node = root_node;
                for(int i = 0; i < index - 1; ++i) {
                    if(current_prev_node->getNext() != nullptr) {
                        current_prev_node = current_prev_node->getNext();
                    } else {
                        return;
                    }
                }

                Node* new_next = current_prev_node->getNext()->getNext();

                delete current_prev_node->getNext();

                current_prev_node->setNext(new_next);
            }
        }
        endRemoveRows();
    }

    int size() const {
        if (root_node == nullptr) {
            return 0;
        } else {
            int i = 1;
            Node* current_node = root_node;
            while(current_node->getNext() != nullptr) {
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

    EventList* search(QString query) {
        EventList* result = new EventList("Результаты поиска");

        for(int i = 0; i < size(); ++i) {
            Event* e = get(i);
            if (e->getName().contains(query)) {
                result->add(e);
            }
        }

        return result;
    }

    EventList* search(QDateTime start, QDateTime end) {
        EventList* result = new EventList("Результаты поиска");

        for(int i = 0; i < size(); ++i) {
            Event* e = get(i);
            if (start <= e->getTimestamp() && e->getTimestamp() <= end) {
                result->add(e);
            }
        }

        return result;
    }

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
            Event* e = get(index.row());
            return e->getName() + " (" + e->getCity() + ")" + " - " + e->getTimestamp().toString("hh:mm, dd MMM yyyy");
        }
        if (role == Qt::DecorationRole) {
            static QIcon event_icon(":new/icons/page_icon");
            return event_icon;
        }
        return QVariant();
    }

    bool getIsActive() const
    {
        return isActive;
    }

    void setActive(bool value)
    {
        isActive = value;
    }
};

#endif // EVENT_CONTAINER_Hs
