#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <event.h>
#include <QMainWindow>
#include <QItemSelection>
#include "event_container.h"
#include "eventcontainersmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_create_object_triggered();

    void on_action_exit_triggered();

    void on_create_container_triggered();

    void on_delete_container_triggered();

    void on_merge_containers_triggered();

    void on_delete_object_triggered();

    void on_search_object_by_name_triggered();

    void on_search_object_by_time_triggered();

    void on_action_help_triggered();

    void on_clear_container_triggered();

    void container_selection_changed(QItemSelection);

private:
    Ui::MainWindow *ui;

    EventContainersModel *containers_model = NULL;
};

#endif // MAINWINDOW_H
