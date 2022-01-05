#include<iostream>
#include<fstream>

using namespace std;
/*
Variablenpositionen im Array:
        0-6:        Radien r1-r7
        7:          Länge des Zerstäuberstabs
        8:          Eintrittstemperatur Öl
        9:          Eintrittstemperatur Luft
        10:         Konstante Temperatur
        11:         Massenstrom Luft
        12:         Massenstrom Öl
        13:         cp Heizöl
        14:         Lambda Heizöl
        15:         Eta Heizöl         
        16-32:      Rho Luft
        33-49:      cp Luft
        50-66:      lambda Luft
        67-83:      eta Luft        
        84-100:     ny Luft
        101-117:    Pr Luft
        118-126:    lambda X6Cr17
*/



void datenEinlesen(double *daten){
    ifstream datei;
    datei.open("Stoffdaten.txt");
    int cnt = 0;
    while(!datei.eof()){
        datei >> daten[cnt];
        cnt++;
    }
    datei.close();

}



int main(){
    int StoffdatenAnzahl = 126;

    double eingaben[StoffdatenAnzahl];
    datenEinlesen(eingaben);
    for(int i = 0; i <= StoffdatenAnzahl; i++){
        cout << eingaben[i] << endl;
    }
}