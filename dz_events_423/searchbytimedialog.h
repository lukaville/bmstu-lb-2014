#ifndef SEARCHBYTIMEDIALOG_H
#define SEARCHBYTIMEDIALOG_H

#include "eventcontainer.h"

#include <QDialog>

namespace Ui {
class SearchByTimeDialog;
}

class SearchByTimeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchByTimeDialog(QWidget *parent = 0);
    ~SearchByTimeDialog();
    EventList* getResults(EventList* el);

private:
    Ui::SearchByTimeDialog *ui;
};

#endif // SEARCHBYTIMEDIALOG_H
