#include "newrumdialog.h"
#include "ui_newrumdialog.h"

NewRumDialog::NewRumDialog(QWidget *parent, Storing* storing) :
    QDialog(parent),
    ui(new Ui::NewRumDialog)
{
    ui->setupUi(this);
    this->storing = storing;
}

NewRumDialog::~NewRumDialog()
{
    delete ui;
}

void NewRumDialog::on_abbrechen_clicked()
{
    this->close();
}
