#ifndef EVENTEDITORDIALOG_H
#define EVENTEDITORDIALOG_H

#include <QDialog>

namespace Ui {
class EventEditorDialog;
}

class EventEditorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EventEditorDialog(QWidget *parent = 0);
    ~EventEditorDialog();

private:
    Ui::EventEditorDialog *ui;
};

#endif // EVENTEDITORDIALOG_H
