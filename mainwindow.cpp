#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    storing = new Storing;  //delete im Destruktor vorhanden

    ui->lineEdit->setVisible(true);

    //gespeicherte Daten einlesen
    QString filenameW = "ownedW.json";
    QString filenameR = "ownedR.json";
    QString tfilenameW = "testedW.json";
    QString tfilenameR = "testedR.json";


    storing->readOwnedWhiskyFromFile(filenameW);
    storing->readOwnedRumFromFile(filenameR);
    storing->readTestedWhiskyFromFile(tfilenameW);
    storing->readTestedRumFromFile(tfilenameR);


    ui->WhiskyTabelle->setRowCount(storing->getAllOwnedWhiskySize() );
    ui->WhiskyTabelle->setColumnCount(2);
    ui->WhiskyTabelle->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->WhiskyTabelle->setWindowOpacity(400);

    ui->RumTabelle->setRowCount(storing->getAllOwnedRumSize() );
    ui->RumTabelle->setColumnCount(2);
    ui->RumTabelle->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //updated der Tabellen
    for(int i {0}; i < storing->getAllOwnedWhiskySize();  i++ ) {
        ui->WhiskyTabelle->setItem(i, 0, new QTableWidgetItem((storing->getOWhiskyByIndex(i)->getBrennerei())));

        ui->WhiskyTabelle->setItem(i, 1, new QTableWidgetItem((storing->getOWhiskyByIndex(i)->getHerkunft())));
    }
    for (int i {0}; i < storing->getAllOwnedRumSize(); i ++) {
        ui->RumTabelle->setItem(i, 0, new QTableWidgetItem((storing->getORumByIndex(i)->getName())));

        ui->RumTabelle->setItem(i, 1, new QTableWidgetItem((storing->getORumByIndex(i)->getHerkunft())));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    delete storing;
}

/*
    std::cout << "signal bekommen" << std::endl;
    QMessageBox::information(this, "mainwindow", "signal bekommen",  QMessageBox::Ok);
    QMessageBox::information(this, "mainwindow", QString::number(storing->getAllOwnedWhiskySize()),  QMessageBox::Ok);

    //updated der Tabellen
    for(int i {0}; i < storing->getAllOwnedWhiskySize();  i++ ) {
        ui->WhiskyTabelle->setItem(i, 0, new QTableWidgetItem((storing->getWhiskyByIndex(i)->getBrennerei())));

        ui->WhiskyTabelle->setItem(i, 1, new QTableWidgetItem((storing->getWhiskyByIndex(i)->getHerkunft())));
    }
    for (int i {0}; i < storing->getAllOwnedRumSize(); i ++) {
        ui->RumTabelle->setItem(i, 0, new QTableWidgetItem((storing->getRumByIndex(i)->getName())));

        ui->RumTabelle->setItem(i, 1, new QTableWidgetItem((storing->getRumByIndex(i)->getHerkunft())));
    }

    ui->WhiskyTabelle->update();
    ui->WhiskyTabelle->repaint();
    repaint();

}
*/



void MainWindow::on_actionProgramm_beenden_triggered()
{
    QString filenameW = "ownedW.json";
    QString filenameR = "ownedR.json";
    QString tfilenameR = "testedR.json";
    QString tfilenameW = "testedW.json";

    this->storing->saveOwnedWhiskyToFile(filenameW);
    this->storing->saveOwnedRumToFile(filenameR);
    this->storing->saveTestedWhiskyToFile(tfilenameW);
    this->storing->saveTestedRumToFile(tfilenameR);
    exit(0);
}

void MainWindow::on_WhiskyTabelle_cellClicked(int row, int column)
{


    //angeklickte row bestimmen
    //int bookingIndex = ui->tableData->currentRow();

    //buchung nach bookingIndex auswählen und den String des Datums rausholen
    //std::string datumN = travelagency->getBooking(bookingIndex)->getBookingFromDate();

    int index = ui->WhiskyTabelle->currentRow();

    //*
    ui->label->setText("Brennerei");
    ui->lineEdit->setText(storing->getOWhiskyByIndex(index)->getBrennerei());
    ui->label_2->setText("Herkunft");
    ui->lineEdit_2->setText(storing->getOWhiskyByIndex(index)->getHerkunft());
    ui->label_3->setText("Region");
    ui->lineEdit_3->setText(storing->getOWhiskyByIndex(index)->getRegion());

    //sortieren: brennerei!!!, alter, whisky art,
    //sortieren: art, hersteller/brennerei/hersteller, melasse,zuckerrohr
    //sortieren (nach starken geschmacksrichtungen)
}

void MainWindow::on_RumTabelle_cellDoubleClicked(int row, int column)
{
    int index = ui->RumTabelle->currentRow();

    ui->label->setText("Name");
    ui->lineEdit->setText(storing->getORumByIndex(index)->getBrennerei());
    ui->label_2->setText("Herkunft");
    ui->lineEdit_2->setText(storing->getORumByIndex(index)->getHerkunft());
    ui->label_3->setText("Region");
    ui->lineEdit_3->setText(storing->getORumByIndex(index)->getRegion());

}

/*
    NewLiquorDialog* newLiquorDialog = new NewLiquorDialog(this, storing);

    //QObject::connect(newLiquorDialog, SIGNAL(tableChangedTest()), this, SLOT(updateTable()) );

    //newLiquorDialog->exec();
    newLiquorDialog->showFullScreen();

    ui->WhiskyTabelle->setRowCount(storing->getAllOwnedWhiskySize() );
    ui->WhiskyTabelle->setColumnCount(2);
    ui->WhiskyTabelle->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->WhiskyTabelle->setWindowOpacity(400);

    ui->RumTabelle->setRowCount(storing->getAllOwnedRumSize() );
    ui->RumTabelle->setColumnCount(2);
    ui->RumTabelle->setEditTriggers(QAbstractItemView::NoEditTriggers);

    newLiquorDialog->setTabletTracking(true);

    //updated der Tabellen
    for(int i {0}; i < storing->getAllOwnedWhiskySize();  i++ ) {
        ui->WhiskyTabelle->setItem(i, 0, new QTableWidgetItem((storing->getOWhiskyByIndex(i)->getBrennerei())));

        ui->WhiskyTabelle->setItem(i, 1, new QTableWidgetItem((storing->getOWhiskyByIndex(i)->getHerkunft())));
    }
    for (int i {0}; i < storing->getAllOwnedRumSize(); i ++) {
        ui->RumTabelle->setItem(i, 0, new QTableWidgetItem((storing->getORumByIndex(i)->getName())));

        ui->RumTabelle->setItem(i, 1, new QTableWidgetItem((storing->getORumByIndex(i)->getHerkunft())));
    }

}
*/

void MainWindow::on_actionNeuen_Rum_triggered()
{
   newRumDialog = new NewRumDialog(this, storing);
   newRumDialog->showFullScreen();
}

void MainWindow::on_actionNeuen_Whisky_triggered()
{
    newWhiskyDialog = new NewWhiskyDialog(this, storing);
    newWhiskyDialog->showFullScreen();
}
