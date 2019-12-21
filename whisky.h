#ifndef WHISKY_H
#define WHISKY_H

#include <QJsonObject>

#include "spirituose.h"

class Whisky : public Spirituose {
public:

    //========== Constructors ==========
    Whisky() {

    }

    Whisky(QString abfueller, unsigned int torfig, unsigned int fruchtig, unsigned int leicht, unsigned int gehaltvoll, unsigned int weich, QString smwsCode,
           QString brennerei, QString herkunft, unsigned int alter, float alkoholgehalt, QString destillationsDatum,
           QString bottleDatum, QString fassTyp, QString region, unsigned int bewertung,
           unsigned int fuellStand, QString geschmacksrichtung, QString beschreibung, QString flaschennummer, QString art) :
        Spirituose (brennerei, herkunft, alter, alkoholgehalt, destillationsDatum, bottleDatum, fassTyp, region, bewertung, fuellStand,
                    geschmacksrichtung, beschreibung, flaschennummer),
        abfueller{abfueller}, torfig{torfig}, fruchtig{fruchtig}, leicht{leicht}, gehaltvoll{gehaltvoll}, weich{weich}, smwsCode{smwsCode}, art{art}
    {
        type = 'W';

    }

    ~Whisky() {

    }

    //virtual
    char getType();

    //========== Getter && Setter ==========
    QString getAbfueller() const {return abfueller;}
    void setAbfueller(QString abfueller) {this->abfueller = abfueller;}

    unsigned int getTorfig() const {return torfig;}
    void setTorfig(unsigned int torfig) {this->torfig = torfig;}

    unsigned int getFruchtig() const {return fruchtig;}
    void setFruchtig(unsigned int fruchtig) {this->fruchtig = fruchtig;}

    unsigned int getLeicht() const {return leicht;}
    void setLeicht(unsigned int leicht) {this->leicht = leicht;}

    unsigned int getGehaltvoll() const {return gehaltvoll;}
    void setGehaltvoll(unsigned int gehaltvoll) {this->gehaltvoll = gehaltvoll;}

    unsigned int getWeich() const {return weich;}
    void setWeich(unsigned int weich) {this->weich = weich;}

    QString getSmwsCode() const {return smwsCode;}
    void setSmwsCode(QString smwsCode) {this->smwsCode = smwsCode;}

    QString getArt() const {return art;}
    void setArt(QString art) {this->art = art;}

    //Reihenfolge
    unsigned int getWReihenfolge() const {return wReihenfolge;}
    void setWReihenfolge(unsigned int wReihenfolge) {this->wReihenfolge = wReihenfolge;}




    //========== QJson ==========
    //Hier das schreiben und lesen von json einfügen ( read and write )
    void readJ(const QJsonObject &json);
    void writeJ (QJsonObject &json) const;


private:


    QString abfueller;

    unsigned int torfig;
    unsigned int fruchtig;
    unsigned int leicht;
    unsigned int gehaltvoll;
    unsigned int weich;

    //optional
    QString smwsCode;

    QString art;


    //für die Reihenfolge des
    unsigned int wReihenfolge;

};

#endif // WHISKY_H

/*
    char type;

    std::string name;
    unsigned int alter;
    float alkoholgehalt;
    std::string herkunft;
    std::string brennerei; !    s
    std::string geschmacksrichtung;     o
    int bewertung;  s
    std::string beschreibung;       o

    unsigned int flaschennummer;        o
    unsigned int gesamtFlaschen;        o

    unsigned int fuellStand;            in prozent      s


    std::string abfueller;
    std::string destillationsDatum;
    std::string bottleDatum;
    std::string fassTyp;
    std::string region;
    std::string smwsCode;       o

    S
    unsigned int torfig;
    unsigned int fruchtig;
    unsigned int leicht;
    unsigned int gehaltvoll;
    unsigned int weich;


*/
