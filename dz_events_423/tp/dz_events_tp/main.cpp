#include <QCoreApplication>
#include <QDebug>

#include "../../node.h"
#include "../../event.h"
#include "../../simpleevent.h"
#include "../../eventcontainer.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Event
    qDebug() << "*** Events *** \n\n";
    Event* e = new SimpleEvent("Test", "Test", QDateTime::currentDateTime(), EVENT_TYPE_WEBINAR);
    qDebug() << *e;

    qDebug() << e->getActive()
             << e->getCity()
             << e->getDebugData()
             << e->getEventType()
             << e->getEventTypeTitle(EVENT_TYPE_CONFERENCE)
             << e->getName()
             << e->getTimestamp().toString();

    e->setActive(true);
    e->setCity("Qwerty");
    e->setEventType(EVENT_TYPE_DISCUSSION);
    e->setName("Qwerty");
    e->setTimestamp(QDateTime::currentDateTimeUtc());

    qDebug() << *e;


    SimpleEvent* e1 = new SimpleEvent("Test", "Test", QDateTime::currentDateTime(), EVENT_TYPE_WEBINAR);
    SimpleEvent e2("Test", "Test", QDateTime::currentDateTime(), EVENT_TYPE_WEBINAR);

    qDebug() << *e1 << e2;

    delete e; delete e1;

    EventList list1("list1");
    list1.add(new SimpleEvent("0", "test", QDateTime::currentDateTime(), 0));
    list1.add(new SimpleEvent("1", "test", QDateTime::currentDateTime(), 0));
    list1.add(new SimpleEvent("2", "test", QDateTime::currentDateTime(), 0));
    list1.add(new SimpleEvent("3", "test", QDateTime::currentDateTime(), 0));

    EventList list2("list2");
    list2.add(new SimpleEvent("0b", "test", QDateTime::currentDateTime(), 0));
    list2.add(new SimpleEvent("1b", "test", QDateTime::currentDateTime(), 0));
    list2.add(new SimpleEvent("2b", "test", QDateTime::currentDateTime(), 0));
    list2.add(new SimpleEvent("3b", "test", QDateTime::currentDateTime(), 0));

    EventList list3("list3");
    list3.add(new SimpleEvent("=0b", "test", QDateTime::currentDateTime(), 0));
    list3.add(new SimpleEvent("=1b", "test", QDateTime::currentDateTime(), 0));
    list3.add(new SimpleEvent("=2b", "test", QDateTime::currentDateTime(), 0));
    list3.add(new SimpleEvent("=3b", "test", QDateTime::currentDateTime(), 0));

    qDebug() << list1;
    qDebug() << list2;
    qDebug() << list3;


    EventList list("list");
    list = list1 + list2;
    qDebug() << list;

    list = list + list3;

    qDebug() << list;

    list.remove(0);

    qDebug() << list;

    qDebug() << list.get(0);

    list.setName("Test");

    qDebug() << list.getName();

    return a.exec();
}
