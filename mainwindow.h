#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "storing.h"

#include "newrumdialog.h"
#include "newwhiskydialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionProgramm_beenden_triggered();

    void on_WhiskyTabelle_cellClicked(int row, int column);

    void on_RumTabelle_cellDoubleClicked(int row, int column);

    void on_actionNeuen_Rum_triggered();

    void on_actionNeuen_Whisky_triggered();

private:
    Ui::MainWindow *ui;
    Storing* storing;
    //NewLiquorDialog* newLiquorDialog;
    NewRumDialog* newRumDialog;
    NewWhiskyDialog* newWhiskyDialog;
};

#endif // MAINWINDOW_H
