#include "storing.h"

void Storing::readAllFiles() {  //wird mit json gemacht



}


/*
Spirituose* Storing::getSpirituoseByIndex(int index) {
    return allOwnedSpirituosen.at(index);
}
*/

Whisky* Storing::getOWhiskyByIndex(int index) {
    return allOwnedWhisky.at(index);
}

Rum* Storing::getORumByIndex(int index) {
    return allOwnedRum.at(index);
}

Whisky* Storing::getTWhiskyByIndex(int index) {
    return allTestedWhisky.at(index);
}

Rum* Storing::getTRumByIndex(int index) {
    return allTestedRum.at(index);
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

    whisky->setWReihenfolge(this->getAllOwnedWhiskySize());
    allOwnedWhisky.push_back(whisky);

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

    rum->setRReihenfolge(this->getAllOwnedRumSize());
    allOwnedRum.push_back(rum);

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

    whisky->setWReihenfolge(this->getAllTestedWhiskySize());
    allTestedWhisky.push_back(whisky);

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

    rum->setRReihenfolge(this->getAllTestedRumSize());
    allTestedRum.push_back(rum);

    return rum;
}



//============================== write to file ownWhisky ==============================
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



//============================== write to file testedWhisky ==============================
void Storing::storeAllTestedWhiskyInArray(QJsonObject &json) const {
    QJsonArray testedWArray;

    for(Whisky* whisky : allTestedWhisky) {
        QJsonObject allTW;
        whisky->convertToJsonObject(allTW);
        testedWArray.append(allTW);
    }

    json["AllTestedWhiskyArray"] = testedWArray;

}

void Storing::saveTestedWhiskyToFile(QString filename) {

    QFile saveFileJ(filename);

    if(!saveFileJ.open(QIODevice::WriteOnly)) {
        qWarning("Task failed succesfully");
    }

    QJsonObject allTW;
    this->storeAllTestedWhiskyInArray(allTW);

    QJsonDocument allOWDoc(allTW);
    saveFileJ.write(allOWDoc.toJson());
}



//============================== read from file ownWhisky ==============================
void Storing::getAllOwnedWhiskyFromArray(const QJsonObject &json) {


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
            whisky->setWReihenfolge(this->getAllOwnedWhiskySize());
            //jedem level wird jezt der Inhalt des objects übergeben
            whisky->convertFromJsonObject(whiskyObject);
            //die einzelnen levels werden zu dem vector hinzugefügt
            allOwnedWhisky.push_back(whisky);
        }
    }
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



//============================== read from file testedWhisky ==============================
void Storing::getAllTestedWhiskyFromArray(const QJsonObject &json) {


    if (json.contains("AllTestedWhiskyArray") && json["AllTestedWhiskyArray"].isArray()) {
        //neues array erstellen und darin den inhalt aus dem json arary kopieren
        QJsonArray levelArray = json["AllTestedWhiskyArray"].toArray();
        //vector clearen
        this->getAllTestedWhisky().clear();
        //größe des vectors reservieren
        this->getAllTestedWhisky().reserve(levelArray.size());
        //inhalt des temp arrays wird pro index einem object übergeben
        for (int levelIndex = 0; levelIndex < levelArray.size(); ++levelIndex) {
            //und zwar hier
            QJsonObject whiskyObject = levelArray[levelIndex].toObject();
            //level ertellen
            Whisky* whisky = new Whisky();
            whisky->setWReihenfolge(this->getAllTestedWhiskySize());
            //jedem level wird jezt der Inhalt des objects übergeben
            whisky->convertFromJsonObject(whiskyObject);
            //die einzelnen levels werden zu dem vector hinzugefügt
            allTestedWhisky.push_back(whisky);
        }
    }
}

void Storing::readTestedWhiskyFromFile(QString filename) {
    QFile loadFile(filename);

    if(!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Task failed succesfuly");
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDocJ(QJsonDocument::fromJson(saveData));

    this->getAllTestedWhiskyFromArray(loadDocJ.object());
}



//============================== write to file ownRum ==============================
void Storing::storeAllOwnedRumInArray(QJsonObject &json) const {
    QJsonArray ownedRArray;

    for(Rum* rum : allOwnedRum) {
        QJsonObject allOR;
        rum->convertToJsonObject(allOR);
        ownedRArray.append(allOR);
    }

    json["AllOwnedRumArray"] = ownedRArray;

}

void Storing::saveOwnedRumToFile(QString filename) {

    QFile saveFileJ(filename);

    if(!saveFileJ.open(QIODevice::WriteOnly)) {
        qWarning("Task failed succesfully");
    }

    QJsonObject allOR;
    this->storeAllTestedRumInArray(allOR);

    QJsonDocument allORDoc(allOR);
    saveFileJ.write(allORDoc.toJson());
}



//============================== write to file testedRum ==============================
void Storing::storeAllTestedRumInArray(QJsonObject &json) const {
    QJsonArray testedRArray;

    for(Rum* rum : allTestedRum) {
        QJsonObject allTR;
        rum->convertToJsonObject(allTR);
        testedRArray.append(allTR);
    }

    json["AllTestedRumArray"] = testedRArray;

}

void Storing::saveTestedRumToFile(QString filename) {

    QFile saveFileJ(filename);

    if(!saveFileJ.open(QIODevice::WriteOnly)) {
        qWarning("Task failed succesfully");
    }

    QJsonObject allOR;
    this->storeAllTestedRumInArray(allOR);

    QJsonDocument allORDoc(allOR);
    saveFileJ.write(allORDoc.toJson());
}



//============================== read from file ownedRum ==============================
void Storing::getAllOwnedRumFromArray(const QJsonObject &json) {

    if (json.contains("AllOwnedRumArray") && json["AllOwnedRumArray"].isArray()) {
        //neues array erstellen und darin den inhalt aus dem json arary kopieren
        QJsonArray levelArray = json["AllOwnedRumArray"].toArray();
        //vector clearen
        this->getAllOwnedRum().clear();
        //größe des vectors reservieren
        this->getAllOwnedRum().reserve(levelArray.size());
        //inhalt des temp arrays wird pro index einem object übergeben
        for (int levelIndex = 0; levelIndex < levelArray.size(); ++levelIndex) {
            //und zwar hier
            QJsonObject rumObject = levelArray[levelIndex].toObject();
            //level ertellen
            Rum* rum = new Rum();
            rum->setRReihenfolge(this->getAllOwnedRumSize());
            //jedem level wird jezt der Inhalt des objects übergeben
            rum->convertFromJsonObject(rumObject);
            //die einzelnen levels werden zu dem vector hinzugefügt
            allOwnedRum.push_back(rum);
        }
    }
}
void Storing::readOwnedRumFromFile(QString filename) {
    QFile loadFile(filename);

    if(!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Task failed succesfuly");
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDocJ(QJsonDocument::fromJson(saveData));

    this->getAllOwnedRumFromArray(loadDocJ.object());
}



//============================== read from file testedRum ==============================
void Storing::getAllTestedRumFromArray(const QJsonObject &json) {

    if (json.contains("AllTestedRumArray") && json["AllTestedRumArray"].isArray()) {
        //neues array erstellen und darin den inhalt aus dem json arary kopieren
        QJsonArray levelArray = json["AllTestedRumArray"].toArray();
        //vector clearen
        this->getAllTestedRum().clear();
        //größe des vectors reservieren
        this->getAllTestedRum().reserve(levelArray.size());
        //inhalt des temp arrays wird pro index einem object übergeben
        for (int levelIndex = 0; levelIndex < levelArray.size(); ++levelIndex) {
            //und zwar hier
            QJsonObject rumObject = levelArray[levelIndex].toObject();
            //level ertellen
            Rum* rum = new Rum();
            rum->setRReihenfolge(this->getAllTestedRumSize());
            //jedem level wird jezt der Inhalt des objects übergeben
            rum->convertFromJsonObject(rumObject);
            //die einzelnen levels werden zu dem vector hinzugefügt
            allOwnedRum.push_back(rum);
        }
    }
}
void Storing::readTestedRumFromFile(QString filename) {
    QFile loadFile(filename);

    if(!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Task failed succesfuly");
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDocJ(QJsonDocument::fromJson(saveData));

    this->getAllTestedRumFromArray(loadDocJ.object());
}






