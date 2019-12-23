#ifndef SPIRITUOSE_H
#define SPIRITUOSE_H

#include <QDate>

#include <iostream>
using namespace std;

class Spirituose {
public:

    //========== Constructors ==========
    Spirituose() {

    }

    /*
    //Konstruktor mit Initialisierungsliste
    Spirituose(std::string brennerei, std::string herkunft, unsigned int alter, float alkoholgehalt, QDate destillationsDatum,
               QDate bottleDatum, std::string fassTyp, std::string region, int bewertung, unsigned int fuellStand) :
        brennerei{brennerei}, herkunft{herkunft}, alter{alter}, alkoholgehalt{alkoholgehalt}, destillationsDatum{destillationsDatum},
        bottleDatum{bottleDatum}, fassTyp{fassTyp}, region{region}, bewertung{bewertung}, fuellStand{fuellStand}
    {

    }
    */

    //Konstruktor mit allen optionalen
    Spirituose(QString brennerei, QString herkunft, int alter, float alkoholgehalt, QString destillationsDatum,
               QString bottleDatum, QString fassTyp, QString region, int bewertung,
               int fuellStand, QString geschmacksrichtung, QString beschreibung, QString flaschennummer) :
        brennerei{brennerei}, herkunft{herkunft}, alter{alter}, alkoholgehalt{alkoholgehalt}, destillationsDatum{destillationsDatum},
        bottleDatum{bottleDatum}, fassTyp{fassTyp}, region{region}, bewertung{bewertung}, fuellStand{fuellStand},
         geschmacksrichtung {geschmacksrichtung}, beschreibung{beschreibung}, flaschennummer{flaschennummer}
    {

    }





    virtual ~Spirituose() {

    }

    //virtual
    virtual char getType() = 0;

    //========== Getter & Setter ==========


    //PflichtFelder
    QString getBrennerei() const {return brennerei;}
    void setBrennerei(QString brennerei) {this->brennerei = brennerei;}

    QString getHerkunft() const {return herkunft;}
    void setHerkunft(QString herkunft) {this->herkunft = herkunft;}



    float getAlkoholgehalt() const {return alkoholgehalt;}
    void setAlkoholgehalt(float alkoholgehalt) {this->alkoholgehalt = alkoholgehalt;}



    QString getFassTyp() const {return fassTyp;}
    void setFassTyp(QString fassTyp) {this->fassTyp = fassTyp;}

    QString getRegion() const {return region;}
    void setRegion(QString region) {this->region = region;}

    int getBewertung() const {return bewertung;}
    void setBewertung(int bewertung) {this->bewertung = bewertung;}

   int getFuellStand() const {return fuellStand;}
    void setFuellStand(int fuellStand) {this->fuellStand = fuellStand;}

    //optionale Felder

    QString getGeschmacksrichtung() const {return geschmacksrichtung;}
    void setGeschmacksrichtung(QString geschmacksrichtung) {this->geschmacksrichtung = geschmacksrichtung;}

    QString getBeschreibung() const {return beschreibung;}
    void setBeschreibung(QString beschreibung) {this->beschreibung = beschreibung;}

    QString getFlaschennummer() const {return flaschennummer;}
    void setFlaschennummer(QString flaschennummer) {this->flaschennummer = flaschennummer;}


    //Für Rum Optional
    int getAlter() const {return alter;}
    void setAlter(int alter) {this->alter = alter;}

    QString getDestillationsDatum() const {return  destillationsDatum;}
    void setDestillationsDatum (QString destillationsDatum) {this->destillationsDatum = destillationsDatum;}

    QString getBottleDatum() const {return bottleDatum;}
    void setBottleDatum(QString bottleDatum) {this->bottleDatum = bottleDatum;}



protected:
    char type;


    QString brennerei;
    QString herkunft;
    int alter;
    float alkoholgehalt;
    QString destillationsDatum;   //jjjjmmdd  whisky
    QString bottleDatum;  //whisky
    QString fassTyp;

    QString region;
    int bewertung;
    int fuellStand;

    //std::string name;   //whisky hat doch kein Name

    //optional

    QString geschmacksrichtung;
    QString beschreibung;
    QString flaschennummer; //zb: 10/203

};

#endif // SPIRITUOSE_H

