#ifndef EVENTEDITORDIALOG_H
#define EVENTEDITORDIALOG_H

#include <QDialog>
#include "event.h"

namespace Ui {
class EventEditorDialog;
}

class EventEditorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EventEditorDialog(QWidget *parent = 0);
    void openEditor(Event* e);
    ~EventEditorDialog();

private:
    Ui::EventEditorDialog *ui;
};

#endif // EVENTEDITORDIALOG_H
