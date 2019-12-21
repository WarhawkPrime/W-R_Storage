#ifndef RUM_H
#define RUM_H

#include <QJsonObject>

#include "spirituose.h"

class Rum : public Spirituose
{
public:

    Rum () {

    }

    Rum(QString abfuellung, QString name, bool melasse, bool zuckerrohr, bool farbstoff, bool singleBarel, unsigned int preisLeistung,
        unsigned int rauchig, unsigned int suesse, unsigned int wuerze, unsigned int fruchtig,
        QString brennerei, QString herkunft, unsigned int alter, float alkoholgehalt, QString destillationsDatum,
                       QString bottleDatum, QString fassTyp, QString region, unsigned int bewertung,
                       unsigned int fuellStand, QString geschmacksrichtung, QString beschreibung, QString flaschennummer) :
        Spirituose (brennerei, herkunft, alter, alkoholgehalt, destillationsDatum, bottleDatum, fassTyp, region, bewertung, fuellStand,
                    geschmacksrichtung, beschreibung, flaschennummer),
        abfuellung{abfuellung}, name{name}, melasse{melasse}, zuckerrohr{zuckerrohr}, farbstoff{farbstoff}, singleBarrel{singleBarel}, preisLeistung{preisLeistung},
        rauchig{rauchig}, suesse{suesse}, wuerze{wuerze}, fruchtig{fruchtig}
    {

        type = 'R';

    }

    ~Rum(){

    }

    char getType();



    //Getter & Setter
    QString getAbfuellung() const {return abfuellung;}
    void setAbfuellung(QString abfuellung) {this->abfuellung = abfuellung;}

    bool getMelasse() const {return melasse;}
    void setMelasse(bool melasse) {this->melasse = melasse;}

    bool getZuckerrohr() const {return zuckerrohr;}
    void setZuckerrohr(bool zuckerrohr) {this->zuckerrohr = zuckerrohr;}

    bool getFarbstoff() const {return farbstoff;}
    void setFarbstoff(bool farbstoff) {this->farbstoff = farbstoff;}

    bool getSingleBarrel() const {return singleBarrel;}
    void setSingleBarrel(bool singleBarrel) {this->singleBarrel = singleBarrel;}

    unsigned int getPreisLeistung() const {return preisLeistung;}
    void setPreisLeistung(unsigned int preisLeistung) {this->preisLeistung = preisLeistung;}

    QString getName() const {return name;}
    void setName(QString name) {this->name = name;}

    //Blume
    unsigned int getRauchig() const {return rauchig;}
    void setRauchig(unsigned int rauchig) {this->rauchig = rauchig;}

    unsigned int getSuesse() const {return suesse;}
    void setSuesse(unsigned int suesse) {this->suesse = suesse;}

    unsigned int getWuerze() const {return wuerze;}
    void setWuerze(unsigned int wuerze) {this->wuerze = wuerze;}

    unsigned int getFruchtig() const {return fruchtig;}
    void setFruchtig(unsigned int fruchtig) {this->fruchtig = fruchtig;}

    //Reihenfolge
    unsigned int getRReihenfolge() const {return rReihenfolge;}
    void setRReihenfolge(unsigned int rReihenfolge) {this->rReihenfolge = rReihenfolge;}

    //========== QJson ==========
    //Hier das schreiben und lesen von json einfügen ( read and write )
    void readJ(const QJsonObject &json);
    void writeJ (QJsonObject &json) const;


private:

    QString abfuellung;

    QString name;

    bool melasse;
    bool zuckerrohr;
    bool farbstoff;
    bool singleBarrel;
    unsigned int preisLeistung;

    unsigned int rauchig;
    unsigned int suesse;
    unsigned int wuerze;
    unsigned int fruchtig;

    unsigned int rReihenfolge;
};

#endif // RUM_H
