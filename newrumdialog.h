#ifndef NEWRUMDIALOG_H
#define NEWRUMDIALOG_H

#include <QDialog>

#include "storing.h"

namespace Ui {
class NewRumDialog;
}

class NewRumDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewRumDialog(QWidget *parent = nullptr, Storing* storing = nullptr);
    ~NewRumDialog();

private slots:
    void on_abbrechen_clicked();

private:
    Ui::NewRumDialog *ui;
    Storing* storing;
};

#endif // NEWRUMDIALOG_H
