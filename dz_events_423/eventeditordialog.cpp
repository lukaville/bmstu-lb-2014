#include "eventeditordialog.h"
#include "ui_eventeditordialog.h"
#include "event.h"

EventEditorDialog::EventEditorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventEditorDialog)
{
    ui->setupUi(this);

    for(int i = 0; i < EVENT_TYPES_COUNT; ++i) {
        ui->typeComboBox->addItem(EVENT_TYPE_TITLES[i]);
    }
}

void EventEditorDialog::openEditor(Event* e) {
    ui->nameLineEdit->setText(e->getName());

    for(int i = 0; i < ui->cityComboBox->count(); ++i) {
        if (ui->cityComboBox->itemText(i) == e->getCity()) {
            ui->cityComboBox->setCurrentIndex(i);
            break;
        };
    }

    ui->dateTimeEdit->setDate(e->getTimestamp());

    this->exec();
}

EventEditorDialog::~EventEditorDialog()
{
    delete ui;
}
