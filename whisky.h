#ifndef WHISKY_H
#define WHISKY_H

#include <QJsonObject>

#include "spirituose.h"

class Whisky : public Spirituose {
public:

    //========== Constructors ==========
    Whisky() {

        type = 'W';

    }

    Whisky(QString abfueller, int torfig, int fruchtig, int leicht, int gehaltvoll, int weich, QString smwsCode,
           QString brennerei, QString herkunft, int alter, float alkoholgehalt, QString destillationsDatum,
           QString bottleDatum, QString fassTyp, QString region, int bewertung,
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

    int getTorfig() const {return torfig;}
    void setTorfig(int torfig) {this->torfig = torfig;}

    int getFruchtig() const {return fruchtig;}
    void setFruchtig(int fruchtig) {this->fruchtig = fruchtig;}

    int getLeicht() const {return leicht;}
    void setLeicht(int leicht) {this->leicht = leicht;}

    int getGehaltvoll() const {return gehaltvoll;}
    void setGehaltvoll(int gehaltvoll) {this->gehaltvoll = gehaltvoll;}

    int getWeich() const {return weich;}
    void setWeich(int weich) {this->weich = weich;}

    QString getSmwsCode() const {return smwsCode;}
    void setSmwsCode(QString smwsCode) {this->smwsCode = smwsCode;}

    QString getArt() const {return art;}
    void setArt(QString art) {this->art = art;}

    //Reihenfolge
    int getWReihenfolge() const {return wReihenfolge;}
    void setWReihenfolge(int wReihenfolge) {this->wReihenfolge = wReihenfolge;}




    //========== QJson ==========
    //Hier das schreiben und lesen von json einfügen ( read and write )
    void convertFromJsonValues (const QJsonObject &json);
    void convertFromJsonObject (const QJsonObject &json);

    void convertToJsonValues (QJsonObject &json) const;
    void convertToJsonObject (QJsonObject &json) const;


private:


    QString abfueller;

    int torfig;
    int fruchtig;
    int leicht;
    int gehaltvoll;
    int weich;

    //optional
    QString smwsCode;

    QString art;


    //für die Reihenfolge des
    int wReihenfolge;

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
