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






Whisky* Storing::createNewOwnedWhisky(QString brennerei, QString herkunft, int alter,
                                 float alkoholgehalt, QString destillationsDatum, QString bottleDatum,
                                 QString fassTyp, QString region, int bewertung, int fuellStand,
                                 QString geschmacksrichtung, QString beschreibung,
                                 QString flaschennummer, QString abfueller,
                                 int torfig, int fruchtig, int leicht, int gehaltvoll,
                                 int weich, QString smwsCode, QString art) {

    Whisky* whisky = new Whisky(abfueller, torfig, fruchtig, leicht, gehaltvoll, weich, smwsCode, brennerei, herkunft, alter,
                                alkoholgehalt, destillationsDatum, bottleDatum, fassTyp, region, bewertung, fuellStand,
                                geschmacksrichtung, beschreibung, flaschennummer, art);

    whisky->setWReihenfolge(whiskyCounter);
    allOwnedWhisky.push_back(whisky);
    whiskyCounter++;

    return whisky;
}


Rum* Storing::createNewOwnedRum(QString brennerei, QString herkunft, int alter, float alkoholgehalt,
                           QString destillationsDatum, QString bottleDatum, QString fassTyp, QString region, int bewertung,
                           int fuellStand, QString name, QString geschmacksrichtung, QString beschreibung,
                           QString flaschennummer, QString abfuellung, bool melasse, bool zuckerrohr, bool farbstoff,
                           bool singleBarel, int preisLeistung, int rauchig, int suesse, int wuerze,
                           int fruchtig) {


    Rum* rum = new Rum(abfuellung, name, melasse, zuckerrohr, farbstoff, singleBarel, preisLeistung, rauchig, suesse, wuerze, fruchtig, brennerei,
                       herkunft, alter, alkoholgehalt, destillationsDatum, bottleDatum, fassTyp, region, bewertung, fuellStand,
                       geschmacksrichtung, beschreibung, flaschennummer);

    rum->setRReihenfolge(rumCounter);
    allOwnedRum.push_back(rum);
    rumCounter++;

    return rum;
}

Whisky* Storing::createNewTestedWhisky(QString brennerei, QString herkunft, int alter,
                                 float alkoholgehalt, QString destillationsDatum, QString bottleDatum,
                                 QString fassTyp, QString region, int bewertung, int fuellStand,
                                 QString geschmacksrichtung, QString beschreibung,
                                 QString flaschennummer, QString abfueller,
                                 int torfig, int fruchtig, int leicht, int gehaltvoll,
                                 int weich, QString smwsCode, QString art) {

    Whisky* whisky = new Whisky(abfueller, torfig, fruchtig, leicht, gehaltvoll, weich, smwsCode, brennerei, herkunft, alter,
                                alkoholgehalt, destillationsDatum, bottleDatum, fassTyp, region, bewertung, fuellStand,
                                geschmacksrichtung, beschreibung, flaschennummer, art);

    whisky->setWReihenfolge(whiskyCounter);
    allTestedWhisky.push_back(whisky);
    whiskyCounter++;

    return whisky;
}


Rum* Storing::createNewTestedRum(QString brennerei, QString herkunft, int alter, float alkoholgehalt,
                           QString destillationsDatum, QString bottleDatum, QString fassTyp, QString region, int bewertung,
                           int fuellStand, QString name, QString geschmacksrichtung, QString beschreibung,
                           QString flaschennummer, QString abfuellung, bool melasse, bool zuckerrohr, bool farbstoff,
                           bool singleBarel, int preisLeistung, int rauchig, int suesse, int wuerze,
                           int fruchtig) {


    Rum* rum = new Rum(abfuellung, name, melasse, zuckerrohr, farbstoff, singleBarel, preisLeistung, rauchig, suesse, wuerze, fruchtig, brennerei,
                       herkunft, alter, alkoholgehalt, destillationsDatum, bottleDatum, fassTyp, region, bewertung, fuellStand,
                       geschmacksrichtung, beschreibung, flaschennummer);

    rum->setRReihenfolge(rumCounter);
    allTestedRum.push_back(rum);
    rumCounter++;

    return rum;
}





//============================== write to file ==============================

void Storing::storeAllOwnedWhiskyInArray(QJsonObject &json) const {
    QJsonArray ownedWArray;

    for(Whisky* whisky : allOwnedWhisky) {
        QJsonObject allOW;
        whisky->convertToJsonObject(allOW);
        ownedWArray.append(allOW);
    }

    json["AllOwnedWhiskyArray"] = ownedWArray;

}

void Storing::saveOwnedWhiskyToFile(QString filename) {

    QFile saveFileJ(filename);

    if(!saveFileJ.open(QIODevice::WriteOnly)) {
        qWarning("Task failed succesfully");
    }

    QJsonObject allOW;
    this->storeAllOwnedWhiskyInArray(allOW);

    QJsonDocument allOWDoc(allOW);
    saveFileJ.write(allOWDoc.toJson());
}

//============================== read from file ==============================



void Storing::getAllOwnedWhiskyFromArray(const QJsonObject &json) {

    this->setWhiskyCounter(0);

    if (json.contains("AllOwnedWhiskyArray") && json["AllOwnedWhiskyArray"].isArray()) {
        //neues array erstellen und darin den inhalt aus dem json arary kopieren
        QJsonArray levelArray = json["AllOwnedWhiskyArray"].toArray();
        //vector clearen
        this->getAllOwnedWhisky().clear();
        //größe des vectors reservieren
        this->getAllOwnedWhisky().reserve(levelArray.size());
        //inhalt des temp arrays wird pro index einem object übergeben
        for (int levelIndex = 0; levelIndex < levelArray.size(); ++levelIndex) {
            //und zwar hier
            QJsonObject whiskyObject = levelArray[levelIndex].toObject();
            //level ertellen
            Whisky* whisky = new Whisky();
            whisky->setWReihenfolge(this->getWhiskyCounter());
            //jedem level wird jezt der Inhalt des objects übergeben
            whisky->convertFromJsonObject(whiskyObject);
            //die einzelnen levels werden zu dem vector hinzugefügt
            allOwnedWhisky.push_back(whisky);
            this->setWhiskyCounter(this->getWhiskyCounter() + 1);
        }
    }

    this->setWhiskyCounter(0);

}

void Storing::readOwnedWhiskyFromFile(QString filename) {
    QFile loadFile(filename);

    if(!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Task failed succesfuly");
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDocJ(QJsonDocument::fromJson(saveData));

    this->getAllOwnedWhiskyFromArray(loadDocJ.object());
}








