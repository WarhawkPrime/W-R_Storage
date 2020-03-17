#ifndef NEWWHISKYDIALOG_H
#define NEWWHISKYDIALOG_H

#include <QDialog>

#include "storing.h"

namespace Ui {
class NewWhiskyDialog;
}

class NewWhiskyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewWhiskyDialog(QWidget *parent = nullptr, Storing* storing = nullptr);
    ~NewWhiskyDialog();

private slots:

    void on_abbrechen_clicked();

    void on_bestaetigen_clicked();

private:
    Ui::NewWhiskyDialog *ui;
    Storing* storing;
};

#endif // NEWWHISKYDIALOG_H
