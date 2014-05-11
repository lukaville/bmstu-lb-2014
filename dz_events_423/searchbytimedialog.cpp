#include "searchbytimedialog.h"
#include "ui_searchbytimedialog.h"

SearchByTimeDialog::SearchByTimeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchByTimeDialog)
{
    ui->setupUi(this);
}

SearchByTimeDialog::~SearchByTimeDialog()
{
    delete ui;
}

EventList *SearchByTimeDialog::getResults(EventList* el)
{
    EventList* result = el->search(ui->startDateTimeEdit->dateTime(), ui->endDateTimeEdit->dateTime());
    return result;
}
