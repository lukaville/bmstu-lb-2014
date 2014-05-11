#ifndef SEARCHRESULTDIALOG_H
#define SEARCHRESULTDIALOG_H

#include <QDialog>
#include "eventcontainer.h"

namespace Ui {
class SearchResultDialog;
}

class SearchResultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchResultDialog(QWidget *parent = 0);
    ~SearchResultDialog();
    void openDialog(EventList* search_results);

private:
    Ui::SearchResultDialog *ui;
};

#endif // SEARCHRESULTDIALOG_H
