#ifndef EVENTSMODEL_H
#define EVENTSMODEL_H

#include <QAbstractListModel>

class EventsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit EventsModel(QObject *parent = 0);

signals:

public slots:

};

#endif // EVENTSMODEL_H
