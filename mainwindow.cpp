#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    storing = new Storing;  //delete im Destruktor vorhanden

    ui->WhiskyTabelle->setRowCount(storing->getAllOwnedSpirituoseSize());
    ui->WhiskyTabelle->setColumnCount(2);
    ui->WhiskyTabelle->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->WhiskyTabelle->setWindowOpacity(400);

    ui->RumTabelle->setRowCount(storing->getAllOwnedSpirituoseSize());
    ui->RumTabelle->setColumnCount(2);
    ui->RumTabelle->setEditTriggers(QAbstractItemView::NoEditTriggers);



    //geht bisher nur wenn alle Felder ausfefüllt sind
    storing->readAllFiles();

    //updated der Tabellen
    for(int i {0}; i < storing->getAllOwnedWhiskySize();  i++ ) {
        ui->WhiskyTabelle->setItem(i, 0, new QTableWidgetItem((storing->getWhiskyByIndex(i)->getAbfueller())));

        ui->WhiskyTabelle->setItem(i, 1, new QTableWidgetItem((storing->getWhiskyByIndex(i)->getBeschreibung())));
    }
    for (int i {0}; i < storing->getAllOwnedRumSize(); i ++) {
        ui->RumTabelle->setItem(i, 0, new QTableWidgetItem((storing->getRumByIndex(i)->getName())));

        ui->RumTabelle->setItem(i, 1, new QTableWidgetItem((storing->getRumByIndex(i)->getBeschreibung())));
    }

}

void MainWindow::updateTable() {
    std::cout << "signal bekommen" << std::endl;
    QMessageBox::information(this, "mainwindow", "signal bekommen",  QMessageBox::Ok);
    QMessageBox::information(this, "mainwindow", QString::number(storing->getAllOwnedWhiskySize()),  QMessageBox::Ok);

    //updated der Tabellen
    for(int i {0}; i < storing->getAllOwnedWhiskySize();  i++ ) {
        ui->WhiskyTabelle->setItem(i, 0, new QTableWidgetItem((storing->getWhiskyByIndex(i)->getAbfueller())));

        ui->WhiskyTabelle->setItem(i, 1, new QTableWidgetItem((storing->getWhiskyByIndex(i)->getBeschreibung())));
    }
    for (int i {0}; i < storing->getAllOwnedRumSize(); i ++) {
        ui->RumTabelle->setItem(i, 0, new QTableWidgetItem((storing->getRumByIndex(i)->getName())));

        ui->RumTabelle->setItem(i, 1, new QTableWidgetItem((storing->getRumByIndex(i)->getBeschreibung())));
    }

    ui->WhiskyTabelle->update();
    ui->WhiskyTabelle->repaint();
    repaint();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete storing;
}

void MainWindow::on_actionProgramm_beenden_triggered()
{
    exit(0);
}

void MainWindow::on_WhiskyTabelle_cellClicked(int row, int column)
{


    //angeklickte row bestimmen
    //int bookingIndex = ui->tableData->currentRow();

    //buchung nach bookingIndex auswählen und den String des Datums rausholen
    //std::string datumN = travelagency->getBooking(bookingIndex)->getBookingFromDate();

    int index = ui->WhiskyTabelle->currentRow();

    QMessageBox::information(this, "mainwindow", storing->getWhiskyByIndex(index)->getAbfueller()  ,  QMessageBox::Ok);

    //sortieren: brennerei!!!, alter, whisky art,
    //sortieren: art, hersteller/brennerei/hersteller, melasse,zuckerrohr
    //sortieren (nach starken geschmacksrichtungen)


}

void MainWindow::on_actionNeuen_Whisky_hinzuf_gen_triggered()
{
    NewLiquorDialog* newLiquorDialog = new NewLiquorDialog(this, storing);

    //QObject::connect(newLiquorDialog, SIGNAL(tableChangedTest()), this, SLOT(updateTable()) );

    newLiquorDialog->exec();

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
        ui->WhiskyTabelle->setItem(i, 0, new QTableWidgetItem((storing->getWhiskyByIndex(i)->getAbfueller())));

        ui->WhiskyTabelle->setItem(i, 1, new QTableWidgetItem((storing->getWhiskyByIndex(i)->getBeschreibung())));
    }
    for (int i {0}; i < storing->getAllOwnedRumSize(); i ++) {
        ui->RumTabelle->setItem(i, 0, new QTableWidgetItem((storing->getRumByIndex(i)->getName())));

        ui->RumTabelle->setItem(i, 1, new QTableWidgetItem((storing->getRumByIndex(i)->getBeschreibung())));
    }

}
