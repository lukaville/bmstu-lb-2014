#include "eventcontainersmodel.h"
#include <QtAlgorithms>

EventContainersModel::EventContainersModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

void EventContainersModel::add(EventList el)
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
        containers.removeAt(indexes.at(i).row());
    }
    endRemoveRows();
}

void EventContainersModel::merge(QModelIndexList indexes)
{
    qSort(indexes.begin(), indexes.end());

    if(indexes.size() > 1) {
        //containers.at(i)
    }
}

void EventContainersModel::clear()
{
    beginRemoveRows(QModelIndex(), 0, 0);
    containers.clear();
    endRemoveRows();
}

void EventContainersModel::clear(QModelIndexList indexes)
{
    for(int i = indexes.size() - 1; i >= 0; --i) {
        //containers.at(indexes.at(i).row()).clear();
    }
}

int EventContainersModel::rowCount(const QModelIndex &parent) const
{
    return containers.size();
}

QVariant EventContainersModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return containers.at(index.row()).getName();
    }
    return QVariant();
}
