#include "newliquordialog.h"
#include "ui_newliquordialog.h"

NewLiquorDialog::NewLiquorDialog(QWidget *parent, Storing* storing) :
    QDialog(parent),
    ui(new Ui::NewLiquorDialog)
{
    ui->setupUi(this);
    this->storing = storing;



    ui->VarLabel1_7->setVisible(true);
    ui->VarLineEdit1_7->setVisible(true);
    ui->comboBox_6->setVisible(true);

    ui->VarLabel1->setVisible(false);
    ui->VarLineEdit1->setVisible(false);

    ui->VarLabel1_8->setVisible(false);
    ui->VarLabel1_9->setVisible(false);

    ui->comboBox_2->setVisible(false);
    ui->comboBox_3->setVisible(false);
    ui->comboBox_4->setVisible(false);

    ui->VarLabel1->setText("Abfüllung *");
    ui->VarLabel1_2->setText("SMWS Code");
    ui->VarLabel1_3->setText("Torfig *");
    ui->VarLabel1_4->setText("Fruchtig *");
    ui->VarLabel1_5->setText("Leicht *");
    ui->VarLabel1_6->setText("Gehaltvoll *");
    ui->VarLabel1_7->setText("Weich *");

}



NewLiquorDialog::~NewLiquorDialog()
{
    delete ui;
}

void NewLiquorDialog::on_bestaetigen_clicked()
{

    QString choice = ui->comboBox->currentText();

    std::string fileChoice = ui->comboBox_4->currentText().toStdString();   //fileName als String

    //Umwandlung für Rum und Whisky
    //pflichtfeld
    QString brennereiP = ui->lineEdit->text();

    QString herkunftP = ui->lineEdit_3->text();
    unsigned int alkoholgehaltP = ui->lineEdit_5->text().toUInt();
    QString regionP = ui->lineEdit_9->text();
    unsigned int fuellstandP = ui->lineEdit_10->text().toUInt();

    //Optionales Feld
    unsigned int alterO = ui->lineEdit_4->text().toUInt();
    QString destillationsDatumO = ui->lineEdit_6->text();
    QString bottleDatumO = ui->lineEdit_7->text();
    QString geschmacksrichtungO = ui->lineEdit_11->text();
    QString fasstypO = ui->lineEdit_8->text();
    QString flaschennummerO = ui->lineEdit_12->text();
    QString beschreibungO = ui->textEdit->toPlainText();
    unsigned int bewertungP = ui->lineEdit_13->text().toUInt();


    //Datei auswahl
    std::string fileName;
    bool tested = false;

    if(ui->comboBox_5->currentText() == "Im Bestand") {
        tested = false;
    }
    else {
        tested = true;
    }

    //Whisky oder Rum
    if(choice == "Whisky") {

        QString abfuellerP = ui->lineEdit_2->text();
        QString smwsCodeO = ui->VarLineEdit1_2->text();
        QString art;

        //Blume var3, var4, var5, var6, var7
        unsigned int torfigP = ui->VarLineEdit1_3->text().toUInt();
        unsigned int fruchtigP = ui->VarLineEdit1_4->text().toUInt();
        unsigned int leichtP = ui->VarLineEdit1_5->text().toUInt();
        unsigned int gehaltvollP = ui->VarLineEdit1_6->text().toUInt();
        unsigned int weichP = ui->VarLineEdit1_7->text().toUInt();

        if(ui->comboBox_6->currentText() == "Single Malt" ) {
            art = "Single Malt";
        }
        else if(ui->comboBox_6->currentText() == "Malt Whisky") {
            art = "Malt Whisky";
        }
        else if(ui->comboBox_6->currentText() == "Single Barrel") {
            art = "Single Barrel";
        }
        else if(ui->comboBox_6->currentText() == "Grain") {
            art = "Grain";
        }
        else if(ui->comboBox_6->currentText() == "Scotch") {
            art = "Scotch";
        }
        else if(ui->comboBox_6->currentText() == "Burbon") {
            art = "Burbon";
        }

        //In jeweilige Datei einspeichern und entsprechende txt datei auswählen

        if(tested == false) {
            storing->createNewOwnedWhisky(brennereiP, herkunftP, alterO, alkoholgehaltP, destillationsDatumO,
                                          bottleDatumO, fasstypO, regionP, bewertungP, fuellstandP,
                                          geschmacksrichtungO, beschreibungO, flaschennummerO, abfuellerP,
                                          torfigP, fruchtigP, leichtP, gehaltvollP, weichP, smwsCodeO, art);
        }
        else {
            storing->createNewTestedWhisky(brennereiP, herkunftP, alterO, alkoholgehaltP, destillationsDatumO,
                                           bottleDatumO, fasstypO, regionP, bewertungP, fuellstandP,
                                           geschmacksrichtungO, beschreibungO, flaschennummerO, abfuellerP,
                                           torfigP, fruchtigP, leichtP, gehaltvollP, weichP, smwsCodeO, art);
        }
        //storing->storeWhiskyInFile( newWhisky , fileName);






    }
    else if (choice == "Rum") {

        QString nameP = ui->lineEdit_2->text();
        QString abfuellungP = ui->VarLineEdit1->text();
        unsigned int preisLeistung = ui->VarLineEdit1_2->text().toUInt();

        bool melasseP;
        bool zuckerrohrP;
        bool singleBarrelP;
        bool farbstoffP;

        //Melasse oder zuckerrohr
        if(ui->comboBox_2->currentText() == "Melasse") {
            melasseP = true;
            zuckerrohrP = false;
        }
        else {
            melasseP = false;
            zuckerrohrP = true;
        }

        //singlebarrel ja nein
        if(ui->comboBox_3->currentText() == "Ja") {
            singleBarrelP = true;
        }
        else {
            singleBarrelP = false;
        }

        //Farbstoff ja nein
        if(ui->comboBox_4->currentText() == "Ja") {
            farbstoffP = true;
        }
        else {
            farbstoffP = false;
        }

        unsigned int rauchigP = ui->VarLineEdit1_3->text().toUInt();
        unsigned int suesseP = ui->VarLineEdit1_4->text().toUInt();
        unsigned int wuerzeP = ui->VarLineEdit1_5->text().toUInt();
        unsigned int fruchtigP = ui->VarLineEdit1_6->text().toUInt();

        if(tested == false) {
            storing->createNewOwnedRum(brennereiP, herkunftP, alterO, alkoholgehaltP, destillationsDatumO, bottleDatumO,
                                       fasstypO, regionP, bewertungP, fuellstandP, nameP, geschmacksrichtungO, beschreibungO,
                                       flaschennummerO, abfuellungP, melasseP, zuckerrohrP, farbstoffP, singleBarrelP,
                                       preisLeistung, rauchigP, suesseP, wuerzeP, fruchtigP);
        }
        else {
            storing->createNewTestedRum(brennereiP, herkunftP, alterO, alkoholgehaltP, destillationsDatumO, bottleDatumO,
                                        fasstypO, regionP, bewertungP, fuellstandP, nameP, geschmacksrichtungO, beschreibungO,
                                        flaschennummerO, abfuellungP, melasseP, zuckerrohrP, farbstoffP, singleBarrelP,
                                        preisLeistung, rauchigP, suesseP, wuerzeP, fruchtigP);
        }
    }

    this->close();
}

void NewLiquorDialog::on_abbrechen_clicked()
{
    this->close();
}

/**
 * @brief NewLiquorDialog::on_comboBox_activated
 * @param arg1
 */
void NewLiquorDialog::on_comboBox_activated(const QString &arg1)
{

    QString text = ui->comboBox->currentText();

    if(arg1 == "Whisky") {

        ui->VarLabel1_7->setVisible(true);
        ui->VarLineEdit1_7->setVisible(true);
        ui->comboBox_6->setVisible(true);

        ui->VarLabel1->setVisible(false);
        ui->VarLineEdit1->setVisible(false);

        ui->VarLabel1_8->setVisible(false);
        ui->VarLabel1_9->setVisible(false);

        ui->comboBox_2->setVisible(false);
        ui->comboBox_3->setVisible(false);
        ui->comboBox_4->setVisible(false);

        ui->label_2->setText("Abfüller *");

        ui->VarLabel1_2->setText("SMWS Code");
        ui->VarLabel1_3->setText("Torfig *");
        ui->VarLabel1_4->setText("Fruchtig *");
        ui->VarLabel1_5->setText("Leicht *");
        ui->VarLabel1_6->setText("Gehaltvoll *");
        ui->VarLabel1_7->setText("Weich *");
    }
    else if(arg1 == "Rum" ) {

        ui->VarLabel1_7->setVisible(false);
        ui->VarLineEdit1_7->setVisible(false);
        ui->comboBox_6->setVisible(false);

        ui->VarLabel1->setVisible(true);
        ui->VarLineEdit1->setVisible(true);

        ui->VarLabel1_8->setVisible(true);
        ui->VarLabel1_9->setVisible(true);

        ui->comboBox_2->setVisible(true);
        ui->comboBox_3->setVisible(true);
        ui->comboBox_4->setVisible(true);

        ui->label_2->setText("Name *");

        ui->VarLabel1->setText("Abfüllung *");
        ui->VarLabel1_2->setText("Preis/Leistung");
        ui->VarLabel1_3->setText("Rauchig *");
        ui->VarLabel1_4->setText("Süße *");
        ui->VarLabel1_5->setText("Würze *");
        ui->VarLabel1_6->setText("Fruchtig *");
    }
}
