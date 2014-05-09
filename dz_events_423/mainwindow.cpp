#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include "simpleevent.h"
#include "event_container.h"
#include <QDebug>
#include <QDir>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    EventList list;
    list.add(new SimpleEvent("0", "test", QDate::currentDate(), 0));
    list.add(new SimpleEvent("1", "test", QDate::currentDate(), 0));
    list.add(new SimpleEvent("2", "test", QDate::currentDate(), 0));
    list.add(new SimpleEvent("3", "test", QDate::currentDate(), 0));

    EventList list2;
    list2.add(new SimpleEvent("0b", "test", QDate::currentDate(), 0));
    list2.add(new SimpleEvent("1b", "test", QDate::currentDate(), 0));
    list2.add(new SimpleEvent("2b", "test", QDate::currentDate(), 0));
    list2.add(new SimpleEvent("3b", "test", QDate::currentDate(), 0));

    list2.clear();

    qDebug() << list2;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void update_containers_view() {

}

void MainWindow::on_create_object_triggered()
{

}

void MainWindow::on_action_exit_triggered()
{
    qApp->exit();
}

void MainWindow::on_create_container_triggered()
{
    bool ok;
    QString container_name = QInputDialog::getText(this,
                                                   tr("Новый набор событий"),
                                                   tr("Введите название набора событий:"),
                                                   QLineEdit::Normal,
                                                   "Безымянное событие", &ok);

    if (ok && !container_name.isEmpty()) {
        containers.append(EventList(container_name));
        update_containers_view();
    }
}

void MainWindow::on_delete_container_triggered()
{

}

void MainWindow::on_merge_containers_triggered()
{

}

void MainWindow::on_delete_object_triggered()
{

}

void MainWindow::on_search_object_by_name_triggered()
{

}

void MainWindow::on_search_object_by_time_triggered()
{

}

void MainWindow::on_action_help_triggered()
{

}
