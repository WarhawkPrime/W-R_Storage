#include "whisky.h"

char Whisky::getType() {
    return 'W';
}

void Whisky::convertToJsonValues(QJsonObject &json) const {
    //Nummer
    json["ID"] = this->getWReihenfolge();

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

    //Pflicht und Whisky
    json["Abfueller"] = this->getAbfueller();
    json["Torfig"] = this->getTorfig();
    json["Fruchtig"] = this->getFruchtig();
    json["Leicht"] = this->getLeicht();
    json["Gehaltvoll"] = this->getGehaltvoll();
    json["Weich"] = this->getWeich();

    //Optional und Whisky
    json["SMWS Code"] = this->getSmwsCode();
    json["Art"] = this->getArt();
}

void Whisky::convertToJsonObject(QJsonObject &json) const {
    QJsonObject whiskyJ;
    this->convertToJsonValues(whiskyJ);
    QString id = QString::number(this->getWReihenfolge());
    json[id] = whiskyJ;
}


//============================== read from file ==============================

//wird aus dem unteresten Object gemacht
void Whisky::convertFromJsonValues(const QJsonObject &json) {

    //Nummer
    if(json.contains("ID") && json["ID"].isDouble() ) {
        this->setWReihenfolge(json["ID"].toInt());
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


    //Pflicht und Whisky
    if(json.contains("Abfueller") && json["Abfueller"].isString()) {
        this->setAbfueller(json["Abfueller"].toString());
    }
    if(json.contains("Torfig") && json["Torfig"].isDouble() ) {
        this->setTorfig(json["Torfig"].toInt());
    }
    if(json.contains("Fruchtig") && json["Fruchtig"].isDouble() ) {
        this->setFruchtig(json["Fruchtig"].toInt());
    }
    if(json.contains("Leicht") && json["Leicht"].isDouble() ) {
        this->setLeicht(json["Leicht"].toInt());
    }
    if(json.contains("Gehaltvoll") && json["Gehaltvoll"].isDouble() ) {
        this->setGehaltvoll(json["Gehaltvoll"].toInt());
    }
    if(json.contains("Weich") && json["Weich"].isDouble() ) {
        this->setWeich(json["Weich"].toInt());
    }

    //Optional und Whisky
    if(json.contains("SMWS Code") && json["SMWS Code"].isString()) {
        this->setSmwsCode(json["SMWS Code"].toString());
    }
    if(json.contains("Art") && json["Art"].isString()) {
        this->setArt(json["Art"].toString());
    }


}

//aus den objekten des arrays
void Whisky::convertFromJsonObject(const QJsonObject &json) {

    QString id = QString::number(this->getWReihenfolge());
    if(json.contains(id) && json[id].isObject() ) {
        convertFromJsonValues(json[id].toObject());
    }

}
