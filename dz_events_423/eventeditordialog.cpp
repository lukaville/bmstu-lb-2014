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

bool EventEditorDialog::openEditor(Event* e) {
    event = e;
    loadEvent(e);
    return this->exec();
}

EventEditorDialog::~EventEditorDialog()
{
    delete ui;
}

void EventEditorDialog::on_nameLineEdit_textChanged(const QString &name)
{
    event->setName(name);
}

void EventEditorDialog::loadEvent(Event *e)
{
    ui->nameLineEdit->setText(e->getName());

    for(int i = 0; i < ui->cityComboBox->count(); ++i) {
        if (ui->cityComboBox->itemText(i) == e->getCity()) {
            ui->cityComboBox->setCurrentIndex(i);
            break;
        };
    }

    ui->dateTimeEdit->setDateTime(e->getTimestamp());
}

void EventEditorDialog::on_typeComboBox_currentIndexChanged(int index)
{
    event->setEventType(index);
}

void EventEditorDialog::on_cityComboBox_currentIndexChanged(const QString &city)
{
    event->setCity(city);
}

void EventEditorDialog::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    event->setTimestamp(dateTime);
}
