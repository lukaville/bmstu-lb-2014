#include "eventeditordialog.h"
#include "ui_eventeditordialog.h"
#include "event.h"

EventEditorDialog::EventEditorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventEditorDialog)
{
    ui->setupUi(this);

    for(int i = 0; i < EVENT_TYPES_COUNT; ++i) {
        qDebug() << Event::EVENT_TYPE_TITLES;
        //ui->typeComboBox->addItem([i]);
    }
}

EventEditorDialog::~EventEditorDialog()
{
    delete ui;
}
