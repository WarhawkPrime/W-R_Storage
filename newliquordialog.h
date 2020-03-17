#ifndef NEWLIQUORDIALOG_H
#define NEWLIQUORDIALOG_H

#include "storing.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <QMessageBox>

#include <QDialog>

namespace Ui {
class NewLiquorDialog;
}

class NewLiquorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewLiquorDialog(QWidget *parent = nullptr, Storing* storing = nullptr);
    ~NewLiquorDialog();

private slots:
    void on_bestaetigen_clicked();

    void on_abbrechen_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::NewLiquorDialog *ui;
    Storing* storing;
};

#endif // NEWLIQUORDIALOG_H
