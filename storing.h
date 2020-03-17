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
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

using namespace std;

class Storing
{
public:
    Storing() {

    }

    ~Storing()
    {
        for (int i {0}; i < allOwnedSpirituosen.size(); i++) {
            delete allOwnedSpirituosen.at(i);
        }
        allOwnedSpirituosen.clear();

        for (int i {0}; i < allOwnedRum.size(); i++) {
            delete allOwnedRum.at(i);
        }
        allOwnedRum.clear();

        for (int i {0}; i < allOwnedWhisky.size(); i++) {
            delete allOwnedWhisky.at(i);
        }
        allOwnedWhisky.clear();

        for (int i {0}; i < allTestedWhisky.size(); i++) {
            delete allTestedWhisky.at(i);
        }
        allTestedWhisky.clear();

        for (int i {0}; i < allTestedRum.size(); i++) {
            delete allTestedRum.at(i);
        }
        allTestedRum.clear();
    }



    //========== Methodes ==========
    void readAllFiles();
    //Spirituose* getSpirituoseByIndex(int index);

    Whisky* getOWhiskyByIndex(int index);
    Rum* getORumByIndex(int index);

    Whisky* getTWhiskyByIndex(int index);
    Rum* getTRumByIndex(int index);


    Whisky* createNewOwnedWhisky(QString brennerei, QString herkunft, int alter, float alkoholgehalt, QString destillationsDatum,
                         QString bottleDatum, QString fassTyp, QString region, int bewertung,
                         int fuellStand, QString geschmacksrichtung, QString beschreibung,
                         QString flaschennummer,
                         QString abfueller, int torfig, int fruchtig, int leicht, int gehaltvoll,
                         int weich, QString smwsCode, QString art
                         );

    Rum* createNewOwnedRum(QString brennerei, QString herkunft, int alter, float alkoholgehalt, QString destillationsDatum,
                       QString bottleDatum, QString fassTyp, QString region, int bewertung,
                       int fuellStand, QString name, QString geschmacksrichtung, QString beschreibung,
                       QString flaschennummer,
                       QString abfuellung, bool melasse, bool zuckerrohr, bool farbstoff, bool singleBarel, int preisLeistung,
                               int rauchig, int suesse, int wuerze, int fruchtig
                       );

    Whisky* createNewTestedWhisky(QString brennerei, QString herkunft, int alter, float alkoholgehalt, QString destillationsDatum,
                         QString bottleDatum, QString fassTyp, QString region, int bewertung,
                         int fuellStand, QString geschmacksrichtung, QString beschreibung,
                         QString flaschennummer,
                         QString abfueller, int torfig, int fruchtig, int leicht, int gehaltvoll,
                         int weich, QString smwsCode, QString art
                         );

    Rum* createNewTestedRum(QString brennerei, QString herkunft, int alter, float alkoholgehalt, QString destillationsDatum,
                       QString bottleDatum, QString fassTyp, QString region, int bewertung,
                       int fuellStand, QString name, QString geschmacksrichtung, QString beschreibung,
                       QString flaschennummer,
                       QString abfuellung, bool melasse, bool zuckerrohr, bool farbstoff, bool singleBarel, int preisLeistung,
                               int rauchig, int suesse, int wuerze, int fruchtig
                       );

    //========== ========== JSON ========== ==========

    //ownedW
    void storeAllOwnedWhiskyInArray(QJsonObject &json) const;
    void saveOwnedWhiskyToFile(QString filename);

    void getAllOwnedWhiskyFromArray(const QJsonObject &json);
    void readOwnedWhiskyFromFile(QString filename);

    //ownedR
    void storeAllOwnedRumInArray(QJsonObject &json) const;
    void saveOwnedRumToFile(QString filename);

    void getAllOwnedRumFromArray(const QJsonObject &json);
    void readOwnedRumFromFile(QString filename);



    //testedW
    void storeAllTestedWhiskyInArray(QJsonObject &json) const;
    void saveTestedWhiskyToFile(QString filename);

    void getAllTestedWhiskyFromArray(const QJsonObject &json);
    void readTestedWhiskyFromFile(QString filename);

    //testedR
    void storeAllTestedRumInArray(QJsonObject &json) const;
    void saveTestedRumToFile(QString filename);

    void getAllTestedRumFromArray(const QJsonObject &json);
    void readTestedRumFromFile(QString filename);



    //========== Getter && Setter ==========
    //int getAllOwnedSpirituoseSize() const {return allOwnedSpirituosen.size();}
    int getAllOwnedWhiskySize() const {return allOwnedWhisky.size();}
    int getAllOwnedRumSize() const {return allOwnedRum.size();}
    int getAllTestedRumSize() const {return allTestedRum.size();}
    int getAllTestedWhiskySize() const {return allTestedWhisky.size();}

    QVector<Whisky*> getAllOwnedWhisky() const {return allOwnedWhisky;}
    QVector<Rum*> getAllOwnedRum() const {return allOwnedRum;}

    QVector<Whisky*> getAllTestedWhisky() const {return allTestedWhisky;}
    QVector<Rum*> getAllTestedRum() const {return allTestedRum;}

private:
   QVector<Spirituose*> allOwnedSpirituosen;

   QVector<Whisky*> allOwnedWhisky;
   QVector<Rum*> allOwnedRum;

   QVector<Rum*> allTestedRum;
   QVector<Whisky*> allTestedWhisky;
};

#endif // STORING_H
