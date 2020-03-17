#include "newwhiskydialog.h"
#include "ui_newwhiskydialog.h"

NewWhiskyDialog::NewWhiskyDialog(QWidget *parent, Storing* storing) :
    QDialog(parent),
    ui(new Ui::NewWhiskyDialog)
{
    ui->setupUi(this);
    this->storing = storing;
}

NewWhiskyDialog::~NewWhiskyDialog()
{
    delete ui;
}

void NewWhiskyDialog::on_abbrechen_clicked()
{
    this->close();
}

void NewWhiskyDialog::on_bestaetigen_clicked()
{
    std::string fileChoice = ui->comboBox_5->currentText().toStdString();   //fileName


}
