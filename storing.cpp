#include "storing.h"

void Storing::readAllFiles() {  //wird mit json gemacht



}



Spirituose* Storing::getSpirituoseByIndex(int index) {
    return allOwnedSpirituosen.at(index);
}

Whisky* Storing::getWhiskyByIndex(int index) {
    return allOwnedWhisky.at(index);
}

Rum* Storing::getRumByIndex(int index) {
    return allOwnedRum.at(index);
}






Whisky* Storing::createNewOwnedWhisky(QString brennerei, QString herkunft, unsigned int alter,
                                 float alkoholgehalt, QString destillationsDatum, QString bottleDatum,
                                 QString fassTyp, QString region, unsigned int bewertung, unsigned int fuellStand,
                                 QString geschmacksrichtung, QString beschreibung,
                                 QString flaschennummer, QString abfueller,
                                 unsigned int torfig, unsigned int fruchtig, unsigned int leicht, unsigned int gehaltvoll,
                                 unsigned int weich, QString smwsCode, QString art) {

    Whisky* whisky = new Whisky(abfueller, torfig, fruchtig, leicht, gehaltvoll, weich, smwsCode, brennerei, herkunft, alter,
                                alkoholgehalt, destillationsDatum, bottleDatum, fassTyp, region, bewertung, fuellStand,
                                geschmacksrichtung, beschreibung, flaschennummer, art);

    whisky->setWReihenfolge(whiskyCounter);
    allOwnedWhisky.push_back(whisky);
    whiskyCounter++;

    return whisky;
}


Rum* Storing::createNewOwnedRum(QString brennerei, QString herkunft, unsigned int alter, float alkoholgehalt,
                           QString destillationsDatum, QString bottleDatum, QString fassTyp, QString region, unsigned int bewertung,
                           unsigned int fuellStand, QString name, QString geschmacksrichtung, QString beschreibung,
                           QString flaschennummer, QString abfuellung, bool melasse, bool zuckerrohr, bool farbstoff,
                           bool singleBarel, unsigned int preisLeistung, unsigned int rauchig, unsigned int suesse, unsigned int wuerze,
                           unsigned int fruchtig) {


    Rum* rum = new Rum(abfuellung, name, melasse, zuckerrohr, farbstoff, singleBarel, preisLeistung, rauchig, suesse, wuerze, fruchtig, brennerei,
                       herkunft, alter, alkoholgehalt, destillationsDatum, bottleDatum, fassTyp, region, bewertung, fuellStand,
                       geschmacksrichtung, beschreibung, flaschennummer);

    rum->setRReihenfolge(rumCounter);
    allOwnedRum.push_back(rum);
    rumCounter++;

    return rum;
}

Whisky* Storing::createNewTestedWhisky(QString brennerei, QString herkunft, unsigned int alter,
                                 float alkoholgehalt, QString destillationsDatum, QString bottleDatum,
                                 QString fassTyp, QString region, unsigned int bewertung, unsigned int fuellStand,
                                 QString geschmacksrichtung, QString beschreibung,
                                 QString flaschennummer, QString abfueller,
                                 unsigned int torfig, unsigned int fruchtig, unsigned int leicht, unsigned int gehaltvoll,
                                 unsigned int weich, QString smwsCode, QString art) {

    Whisky* whisky = new Whisky(abfueller, torfig, fruchtig, leicht, gehaltvoll, weich, smwsCode, brennerei, herkunft, alter,
                                alkoholgehalt, destillationsDatum, bottleDatum, fassTyp, region, bewertung, fuellStand,
                                geschmacksrichtung, beschreibung, flaschennummer, art);

    whisky->setWReihenfolge(whiskyCounter);
    allTestedWhisky.push_back(whisky);
    whiskyCounter++;

    return whisky;
}


Rum* Storing::createNewTestedRum(QString brennerei, QString herkunft, unsigned int alter, float alkoholgehalt,
                           QString destillationsDatum, QString bottleDatum, QString fassTyp, QString region, unsigned int bewertung,
                           unsigned int fuellStand, QString name, QString geschmacksrichtung, QString beschreibung,
                           QString flaschennummer, QString abfuellung, bool melasse, bool zuckerrohr, bool farbstoff,
                           bool singleBarel, unsigned int preisLeistung, unsigned int rauchig, unsigned int suesse, unsigned int wuerze,
                           unsigned int fruchtig) {


    Rum* rum = new Rum(abfuellung, name, melasse, zuckerrohr, farbstoff, singleBarel, preisLeistung, rauchig, suesse, wuerze, fruchtig, brennerei,
                       herkunft, alter, alkoholgehalt, destillationsDatum, bottleDatum, fassTyp, region, bewertung, fuellStand,
                       geschmacksrichtung, beschreibung, flaschennummer);

    rum->setRReihenfolge(rumCounter);
    allTestedRum.push_back(rum);
    rumCounter++;

    return rum;
}
