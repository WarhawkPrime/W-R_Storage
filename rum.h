#ifndef RUM_H
#define RUM_H

#include <QJsonObject>

#include "spirituose.h"

class Rum : public Spirituose
{
public:

    Rum () {

        type = 'R';

    }

    Rum(QString abfuellung, QString name, bool melasse, bool zuckerrohr, bool farbstoff, bool singleBarel, int preisLeistung,
        int rauchig, int suesse, int wuerze, int fruchtig,
        QString brennerei, QString herkunft, int alter, float alkoholgehalt, QString destillationsDatum,
                       QString bottleDatum, QString fassTyp, QString region, int bewertung,
                       int fuellStand, QString geschmacksrichtung, QString beschreibung, QString flaschennummer) :
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

    int getPreisLeistung() const {return preisLeistung;}
    void setPreisLeistung(int preisLeistung) {this->preisLeistung = preisLeistung;}

    QString getName() const {return name;}
    void setName(QString name) {this->name = name;}

    //Blume
    int getRauchig() const {return rauchig;}
    void setRauchig(int rauchig) {this->rauchig = rauchig;}

    int getSuesse() const {return suesse;}
    void setSuesse(int suesse) {this->suesse = suesse;}

    int getWuerze() const {return wuerze;}
    void setWuerze(int wuerze) {this->wuerze = wuerze;}

    int getFruchtig() const {return fruchtig;}
    void setFruchtig(int fruchtig) {this->fruchtig = fruchtig;}

    //Reihenfolge
    int getRReihenfolge() const {return rReihenfolge;}
    void setRReihenfolge(int rReihenfolge) {this->rReihenfolge = rReihenfolge;}




    //========== QJson ==========
    //Hier das schreiben und lesen von json einfügen ( read and write )
    void convertFromJsonValues (const QJsonObject &json);
    void convertFromJsonObject (const QJsonObject &json);

    void convertToJsonValues (QJsonObject &json) const;
    void convertToJsonObject (QJsonObject &json) const;



private:

    QString abfuellung;

    QString name;

    bool melasse;
    bool zuckerrohr;
    bool farbstoff;
    bool singleBarrel;
    int preisLeistung;

    int rauchig;
    int suesse;
    int wuerze;
    int fruchtig;

    int rReihenfolge;
};

#endif // RUM_H
