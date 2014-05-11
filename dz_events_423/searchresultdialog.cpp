#include "searchresultdialog.h"
#include "ui_searchresultdialog.h"

SearchResultDialog::SearchResultDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchResultDialog)
{
    ui->setupUi(this);
}

SearchResultDialog::~SearchResultDialog()
{
    delete ui;
}

void SearchResultDialog::openDialog(EventList* search_results)
{
    ui->listView->setModel(search_results);
    this->exec();
}
