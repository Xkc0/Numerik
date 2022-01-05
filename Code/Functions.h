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
        84-100:     ny Luft
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

/*
double Oel(double daten[], double dyn_daten[], double **Temp, double z){
    return ((2 * M_PI) / (daten [12] * daten[13])) * ((Temp[1][1] - Temp[0][1])  / (1 / (dyn_daten[0] * daten[0]) + (log(daten[1] / daten[0])) / daten[118] + (1 / (dyn_daten[1] * daten[1]))));
}

double Luft(double daten[], double dyn_daten[], double **Temp, double z){
    return ((2 * M_PI) / (daten[11] * daten[33])) * (((700. - Temp[1][1])  / (1 / (dyn_daten[1] * daten[2]) + (log(daten[3] / daten[2])) / daten[118] + (1 / (dyn_daten[2] * daten[3])))) - ((Temp[1][1] - Temp[0][1])  / (1 / (dyn_daten[0] * daten[0]) + (log(daten[1] / daten[0])) / daten[118] + (1 / (dyn_daten[1] * daten[1])))));

}

*/

void datenAusgeben(double daten[], int StoffdatenAnzahl){
    for(int i = 0; i <= StoffdatenAnzahl; i++){
        cout << daten[i] << endl;
    }
}

void datenEinlesen(double *daten[]){
    ifstream datei;
    datei.open("Stoffdaten.txt");
    int cnt = 0;
    while(!datei.eof()){
        datei >> daten[cnt];
        cnt++;
    }
    datei.close();
}