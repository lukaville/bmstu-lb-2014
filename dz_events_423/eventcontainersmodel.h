#ifndef EVENTCONTAINERSMODEL_H
#define EVENTCONTAINERSMODEL_H

#include <QAbstractListModel>
#include <QVector>
#include "event_container.h"

class EventContainersModel : public QAbstractListModel
{
    Q_OBJECT
private:
    QList<EventList*> containers;
public:
    explicit EventContainersModel(QObject *parent = 0);
    void add(EventList* el);
    void remove(QModelIndexList index);
    void merge(QModelIndexList indexes);
    void clear();
    void clear(QModelIndexList indexes);
    EventList* get(int index);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
signals:

public slots:

};

#endif // EVENTCONTAINERSMODEL_H
