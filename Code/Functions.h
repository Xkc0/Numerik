#include <iostream>
#include <fstream>
#include <cmath>
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
        84-100:     ny LuftS
        101-117:    Pr Luft
        118-126:    lambda X6Cr17
*/

/*
Dynamische Daten:

        0:          alpha1 (Öl)
        1:          alpha2 (Luft)
        2:          alpha700 (Umgebung)
        3:   

*/


void datenAusgeben(double daten[], int StoffdatenAnzahl){
    for(int i = 0; i <= StoffdatenAnzahl; i++){
        cout << daten[i] << endl;
    }
}

void datenEinlesen(double daten[]){
    ifstream datei;
    datei.open("Stoffdaten.txt");
    int cnt = 0;
    while(!datei.eof()){
        datei >> daten[cnt];
        cnt++;
    }
    datei.close();
}

double Interpolation(double x0, double y0, double x1, double y1, double xp){
    return y0 + ((y1-y0)/(x1-x0)) * (xp - x0);
}
