#ifndef STORING_H
#define STORING_H

#include "spirituose.h"
#include "whisky.h"
#include "rum.h"

#include <QFile>
#include <QTextStream>
#include <sstream>
#include <fstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <istream>
#include <array>
#include <iostream>
#include <vector>

#include <QVector>

//Json Include
#include <QJsonObject>
#include <QJsonDocument>

using namespace std;

class Storing
{
public:
    Storing() {
        rumCounter = 0;
        whiskyCounter = 0;
    }

    ~Storing()
    {
        for (int i {0}; i < allOwnedSpirituosen.size(); i++) {
            delete allOwnedSpirituosen.at(i);
        }
        allOwnedSpirituosen.clear();

    }
    //========== Methodes ==========
    void readAllFiles();
    Spirituose* getSpirituoseByIndex(int index);
    Whisky* getWhiskyByIndex(int index);
    Rum* getRumByIndex(int index);

    void storeWhiskyInFile(Whisky* whisky, std::string fileName, bool owned);
    void storeRumInFile(Rum* rum, std::string fileName, bool owned);


    Whisky* createNewOwnedWhisky(QString brennerei, QString herkunft, unsigned int alter, float alkoholgehalt, QString destillationsDatum,
                         QString bottleDatum, QString fassTyp, QString region, unsigned int bewertung,
                         unsigned int fuellStand, QString geschmacksrichtung, QString beschreibung,
                         QString flaschennummer,
                         QString abfueller, unsigned int torfig, unsigned int fruchtig, unsigned int leicht, unsigned int gehaltvoll,
                         unsigned int weich, QString smwsCode, QString art);

    Rum* createNewOwnedRum(QString brennerei, QString herkunft, unsigned int alter, float alkoholgehalt, QString destillationsDatum,
                       QString bottleDatum, QString fassTyp, QString region, unsigned int bewertung,
                       unsigned int fuellStand, QString name, QString geschmacksrichtung, QString beschreibung,
                       QString flaschennummer,
                       QString abfuellung, bool melasse, bool zuckerrohr, bool farbstoff, bool singleBarel, unsigned int preisLeistung,
                               unsigned int rauchig, unsigned int suesse, unsigned int wuerze, unsigned int fruchtig
                       );

    Whisky* createNewTestedWhisky(QString brennerei, QString herkunft, unsigned int alter, float alkoholgehalt, QString destillationsDatum,
                         QString bottleDatum, QString fassTyp, QString region, unsigned int bewertung,
                         unsigned int fuellStand, QString geschmacksrichtung, QString beschreibung,
                         QString flaschennummer,
                         QString abfueller, unsigned int torfig, unsigned int fruchtig, unsigned int leicht, unsigned int gehaltvoll,
                         unsigned int weich, QString smwsCode, QString art);

    Rum* createNewTestedRum(QString brennerei, QString herkunft, unsigned int alter, float alkoholgehalt, QString destillationsDatum,
                       QString bottleDatum, QString fassTyp, QString region, unsigned int bewertung,
                       unsigned int fuellStand, QString name, QString geschmacksrichtung, QString beschreibung,
                       QString flaschennummer,
                       QString abfuellung, bool melasse, bool zuckerrohr, bool farbstoff, bool singleBarel, unsigned int preisLeistung,
                               unsigned int rauchig, unsigned int suesse, unsigned int wuerze, unsigned int fruchtig
                       );

    //========== Getter && Setter ==========
    int getAllOwnedSpirituoseSize() const {return allOwnedSpirituosen.size();}
    int getAllOwnedWhiskySize() const {return allOwnedWhisky.size();}
    int getAllOwnedRumSize() const {return allOwnedRum.size();}

private:
   QVector<Spirituose*> allOwnedSpirituosen;

   QVector<Whisky*> allOwnedWhisky;
   QVector<Rum*> allOwnedRum;

   QVector<Rum*> allTestedRum;
   QVector<Whisky*> allTestedWhisky;

   unsigned int rumCounter;
   unsigned int whiskyCounter;
};

#endif // STORING_H
