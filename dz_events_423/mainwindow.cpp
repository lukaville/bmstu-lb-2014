#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include "simpleevent.h"
#include "event_container.h"
#include "eventeditordialog.h"
#include <QDebug>
#include <QDir>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    containers_model = new EventContainersModel(0);
    ui->ContainersListView->setModel(containers_model);

    connect(ui->ContainersListView->selectionModel(),
          SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
          this, SLOT(container_selection_changed(QItemSelection)));

    EventList list1("list1");
    list1.add(new SimpleEvent("0", "test", QDate::currentDate(), 0));
    list1.add(new SimpleEvent("1", "test", QDate::currentDate(), 0));
    list1.add(new SimpleEvent("2", "test", QDate::currentDate(), 0));
    list1.add(new SimpleEvent("3", "test", QDate::currentDate(), 0));

    EventList list2("list2");
    list2.add(new SimpleEvent("0b", "test", QDate::currentDate(), 0));
    list2.add(new SimpleEvent("1b", "test", QDate::currentDate(), 0));
    list2.add(new SimpleEvent("2b", "test", QDate::currentDate(), 0));
    list2.add(new SimpleEvent("3b", "test", QDate::currentDate(), 0));

    EventList list3("list3");
    list3.add(new SimpleEvent("=0b", "test", QDate::currentDate(), 0));
    list3.add(new SimpleEvent("=1b", "test", QDate::currentDate(), 0));
    list3.add(new SimpleEvent("=2b", "test", QDate::currentDate(), 0));
    list3.add(new SimpleEvent("=3b", "test", QDate::currentDate(), 0));

    EventList list("list");
    list = list1 + list2;
    qDebug() << list;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::container_selection_changed(QItemSelection s)
{
    if (s.indexes().size() == 1) {
        int row = s.indexes().at(0).row();
        ui->ObjectsListView->setModel(containers_model->get(row));
    }
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
                                                   "Безымянный набор событий", &ok);

    if (ok && !container_name.isEmpty()) {
        containers_model->add(new EventList(container_name));
    }
}

void MainWindow::on_delete_container_triggered()
{
    containers_model->remove(ui->ContainersListView->selectionModel()->selectedIndexes());
    ui->ContainersListView->selectionModel()->clearSelection();
}

void MainWindow::on_clear_container_triggered()
{
    containers_model->clear(ui->ContainersListView->selectionModel()->selectedIndexes());
}

void MainWindow::on_merge_containers_triggered()
{
    containers_model->merge(ui->ContainersListView->selectionModel()->selectedIndexes());
    ui->ContainersListView->selectionModel()->clearSelection();
}

void MainWindow::on_create_object_triggered()
{
    if (ui->ObjectsListView->model() != NULL) {
        EventEditorDialog dialog;
        dialog.exec();
        ((EventList*) ui->ObjectsListView->model())->add(
                    new SimpleEvent("The event", "test", QDate::currentDate(), 0));
    } else {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка","Вы не выбрали набор событий");
    }
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
