#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include "event_container.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_create_object_triggered()
{

}

void MainWindow::on_action_exit_triggered()
{

}

void MainWindow::on_create_container_triggered()
{

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
