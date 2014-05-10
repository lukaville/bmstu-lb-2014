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
    bool openEditor(Event* e);
    ~EventEditorDialog();

private slots:
    void on_nameLineEdit_textChanged(const QString &arg1);

    void on_typeComboBox_currentIndexChanged(int index);

    void on_cityComboBox_currentIndexChanged(const QString &arg1);

    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

private:
    Ui::EventEditorDialog *ui;
    Event* event;
    void loadEvent(Event* e);
};

#endif // EVENTEDITORDIALOG_H
