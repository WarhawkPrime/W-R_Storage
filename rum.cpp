#include "rum.h"

char Rum::getType() {
    return 'R';
}

void Rum::convertToJsonValues(QJsonObject &json) const {
    //Nummer
    json["ID"] = this->getRReihenfolge();

    //Pflicht und allgemein
    json["Brennerei"] = this->getBrennerei();
    json["Herkunft"] = this->getHerkunft();
    json["Alter"] = this->getAlter();
    json["Alkoholgehalt"] = this->getAlkoholgehalt();
    json["Destillationsdatum"] = this->getDestillationsDatum();
    json["Bottledatum"] = this->getBottleDatum();
    json["Fasstyp"] = this->getFassTyp();
    json["Region"] = this->getRegion();
    json["Bewertung"] = this->getBewertung();
    json["Fuelllstand"] = this->getFuellStand();

    //Optional und allgemein
    json["Geschmacksrichtung"] = this->getGeschmacksrichtung();
    json["Beschreibung"] = this->getBeschreibung();
    json["Flaschennummer"] = this->getFlaschennummer();

    //Pflich und Rum
    json["Abfuellung"] = this->getAbfuellung();
    json["Name"] = this->getName();
    json["Melasse"] = this->getMelasse();
    json["Zuckerrohr"] = this->getZuckerrohr();
    json["Farbstoff"] = this->getFarbstoff();
    json["Singlebarrel"] = this->getSingleBarrel();
    json["Preis/Leistumg"] = this->getPreisLeistung();
    json["Rauchig"] = this->getRauchig();
    json["Suesse"] = this->getSuesse();
    json["Wuerze"] = this->getWuerze();
    json["Fruchtig"] = this->getFruchtig();
}


void Rum::convertToJsonObject(QJsonObject &json) const {
    QJsonObject rumJ;
    this->convertToJsonValues(rumJ);
    QString id = QString::number(this->getRReihenfolge());
    json[id] = rumJ;
}



//============================== read from file ==============================

//wird aus dem unteresten Object gemacht
void Rum::convertFromJsonValues(const QJsonObject &json) {

    //Nummer
    if(json.contains("ID") && json["ID"].isDouble() ) {
        this->setRReihenfolge(json["ID"].toInt());
    }

    //Pflicht und allgemein
    if(json.contains("Brennerei") && json["Brennerei"].isString()) {
        this->setBrennerei(json["Brennerei"].toString());
    }
    if(json.contains("Herkunft") && json["Herkunft"].isString()) {
        this->setHerkunft(json["Herkunft"].toString());
    }
    if(json.contains("Alter") && json["Alter"].isDouble() ) {
        this->setAlter(json["Alter"].toInt());
    }
    if(json.contains("Alkoholgehalt") && json["Alkoholgehalt"].isDouble() ) {
        this->setAlkoholgehalt(json["Alkoholgehalt"].toDouble());
    }
    if(json.contains("Herkunft") && json["Herkunft"].isString()) {
        this->setHerkunft(json["Herkunft"].toString());
    }
    if(json.contains("Destillationsdatum") && json["Destillationsdatum"].isString()) {
        this->setDestillationsDatum(json["Destillationsdatum"].toString());
    }
    if(json.contains("Bottledatum") && json["Bottledatum"].isString()) {
        this->setBottleDatum(json["Bottledatum"].toString());
    }
    if(json.contains("Region") && json["Region"].isString()) {
        this->setRegion(json["Region"].toString());
    }
    if(json.contains("Bewertung") && json["Bewertung"].isDouble() ) {
        this->setBewertung(json["Bewertung"].toInt());
    }
    if(json.contains("Fuelllstand") && json["Fuelllstand"].isDouble() ) {
        this->setFuellStand(json["Fuelllstand"].toDouble());
    }


    //Optional und allgemein
    if(json.contains("Geschmacksrichtung") && json["Geschmacksrichtung"].isString()) {
        this->setGeschmacksrichtung(json["Geschmacksrichtung"].toString());
    }
    if(json.contains("Beschreibung") && json["Beschreibung"].isString()) {
        this->setBeschreibung(json["Beschreibung"].toString());
    }
    if(json.contains("Flaschennummer") && json["Flaschennummer"].isString()) {
        this->setFlaschennummer(json["Flaschennummer"].toString());
    }

    //Pflicht und Rum
    if(json.contains("Abfuellung") && json["Abfuellung"].isString()) {
        this->setAbfuellung(json["Abfuellung"].toString());
    }
    if(json.contains("Name") && json["Name"].isString()) {
        this->setName(json["Name"].toString());
    }



    if(json.contains("Melasse") && json["Melasse"].isString()) {
        this->setMelasse(json["Melasse"].toBool());
    }
    if(json.contains("Zuckerrohr") && json["Zuckerrohr"].isString()) {
        this->setZuckerrohr(json["Zuckerrohr"].toBool());
    }
    if(json.contains("Farbstoff") && json["Farbstoff"].isString()) {
        this->setFarbstoff(json["Farbstoff"].toBool());
    }
    if(json.contains("Singlebarrel") && json["Singlebarrel"].isString()) {
        this->setSingleBarrel(json["Singlebarrel"].toBool());
    }



    if(json.contains("Preis/Leistumg") && json["Preis/Leistumg"].isDouble()) {
        this->setPreisLeistung(json["Preis/Leistumg"].toInt());
    }
    if(json.contains("Rauchig") && json["Rauchig"].isDouble()) {
        this->setRauchig(json["Rauchig"].toInt());
    }
    if(json.contains("Suesse") && json["Suesse"].isDouble()) {
        this->setSuesse(json["Suesse"].toInt());
    }
    if(json.contains("Wuerze") && json["Wuerze"].isDouble()) {
        this->setWuerze(json["Wuerze"].toInt());
    }
    if(json.contains("Fruchtig") && json["Fruchtig"].isDouble()) {
        this->setWuerze(json["Fruchtig"].toInt());
    }
 }


//aus den objekten des arrays
void Rum::convertFromJsonObject(const QJsonObject &json) {
    QString id = QString::number(this->getRReihenfolge());
    if(json.contains(id) && json[id].isObject() ) {
        convertFromJsonValues(json[id].toObject());
    }
}
