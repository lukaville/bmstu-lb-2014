#include "eventcontainersmodel.h"
#include <QtAlgorithms>

EventContainersModel::EventContainersModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

void EventContainersModel::add(EventList* el)
{
    beginInsertRows(QModelIndex(), 0, 0);
    containers.append(el);
    endInsertRows();
}

void EventContainersModel::remove(QModelIndexList indexes)
{
    qSort(indexes.begin(), indexes.end());

    beginRemoveRows(QModelIndex(), 0, 0);
    for(int i = indexes.size() - 1; i >= 0; --i) {
        delete containers.at(indexes.at(i).row());
        containers.removeAt(indexes.at(i).row());
    }
    endRemoveRows();
}

void EventContainersModel::merge(QModelIndexList indexes)
{
    qSort(indexes.begin(), indexes.end());

    if(indexes.size() > 1) {
        for(int i = 1; i < indexes.size(); ++i) {
            for(int j = 0; j < containers.at(indexes.at(i).row())->size(); ++j) {
                containers.at(indexes.at(0).row())->add(containers.at(indexes.at(i).row())->get(j));
            }
            containers.at(indexes.at(i).row())->clear();
        }

        beginRemoveRows(QModelIndex(), 0, 0);
        for(int i = indexes.size() - 1; i > 0; --i) {
            delete containers.at(indexes.at(i).row());
            containers.removeAt(indexes.at(i).row());
        }
        endRemoveRows();
    }
}

void EventContainersModel::clear()
{
    beginRemoveRows(QModelIndex(), 0, 0);
    for(int i = 0; i < containers.size(); ++i) {
        delete containers.at(i);
    }
    containers.clear();
    endRemoveRows();
}

void EventContainersModel::clear(QModelIndexList indexes)
{
    for(int i = indexes.size() - 1; i >= 0; --i) {
        containers.at(indexes.at(i).row())->clear();
    }
}

EventList *EventContainersModel::get(int index)
{
    return containers.at(index);
}

int EventContainersModel::rowCount(const QModelIndex &parent) const
{
    return containers.size();
}

QVariant EventContainersModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return containers.at(index.row())->getName();
    }
    return QVariant();
}
