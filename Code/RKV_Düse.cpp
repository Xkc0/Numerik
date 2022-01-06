#include <iostream>
#include <cmath>
#include "Functions.h"
using namespace std;

double Oel(double daten[], double dyn_daten[], double Temp1, double Temp2);

double Luft(double daten[], double dyn_daten[], double Temp1, double Temp2);

void RKV(double daten[], double dyn_daten[],  double **Temp, int n, double h);

double Interpolation(double x0, double y0, double x1, double y1, double xp){
    return y0 + ((y1-y0)/(x1-x0)) * (xp - x0);
}


int main(){

//Initialisierung
    int StoffdatenAnzahl = 126;
    int m = 3;
    int n, Schritte;
    double h;
    double z = 0;
    double e = 0.0003;
    bool check = 1;
    


    double daten[StoffdatenAnzahl];
    double dyn_daten[10];

    //Test
    dyn_daten[0] = 0.3;
    dyn_daten[1] = 0.8;
    dyn_daten[2] = 0.1;
    //Test Ende

//Beginn
    datenEinlesen(daten);
    //datenAusgeben(daten, 1);
    Schritte = 100;
    h = daten[7] / Schritte;
    cout << h << endl;
    do {
        n = 0;
        double **Temp = new double *[m];
        for (int i = 0; i < m; i++){
            Temp[i] = new double [Schritte];
        }
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < Schritte; j++){
                Temp[i][j] = 0;
                
            }
        }
        Temp[1][0] = daten[8];
        Temp[2][0] = daten[9];


        for (int j = 0; j < Schritte; j++){
            Temp[0][j+1] = Temp[0][j] + h;
        }

        for (double z = 0; z < Schritte; z++){
            RKV(daten, dyn_daten, Temp, n, h);
            n++;
            }

        for (int j = 0; j <= Schritte; j++){
            for (int i = 0; i < m; i++){
                cout << Temp[i][j];
                cout << "   ";
            }
            cout << endl;
        }


/*
        for (int i = 0; i < m; i++){
            for (int j = 0; j < Schritte; j++){
                cout << Temp[i][j];                
            }
            cout << endl;
        }
*/
        for (int i = 0; i < m; i++){
            delete[] Temp[i];
        }
        delete[] Temp;
    } while(check == 0);
        
    
    
    



//Speicher freigeben
    
}

//Pseudo Programm:
/*

Matix au0erhalb erstellen (sonst kommen wir an die werte nach der Schleife nicht mehr ran)

do {

    Speicher für Matrix reservieren also das ganze inizialisations zeug mit new double etc.

    RKV ausführen und Matrix füllen (Anzahl der schritte in n speichern)

    if(Matrix[1][n] - Alt < 0.001){
        Alt = Matrix[1][n];
        Matix löschen 
        Längen Variable m verdoppeln oder so KA 
    }
    else{
        check = 1;
    }

} while (check == 0);

*/

//Fuktionen

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

double Oel(double daten[], double dyn_daten[], double Temp1, double Temp2){
    return ((2. * M_PI) / (daten [12] * daten[13])) * ((Temp2 - Temp1)  / (1 / (dyn_daten[0] * daten[0]) + (log(daten[1] / daten[0])) / daten[118] + (1 / (dyn_daten[1] * daten[1]))));
}

double Luft(double daten[], double dyn_daten[], double Temp1, double Temp2){
    return ((2. * M_PI) / (daten[11] * daten[33])) * (((973.15 - Temp2)  / (1 / (dyn_daten[1] * daten[2]) + (log(daten[3] / daten[2])) / daten[118] + (1 / (dyn_daten[2] * daten[3])))) - ((Temp2 - Temp1)  / (1 / (dyn_daten[0] * daten[0]) + (log(daten[1] / daten[0])) / daten[118] + (1 / (dyn_daten[1] * daten[1])))));

}

void RKV(double daten[], double dyn_daten[],  double **Temp, int n, double h){
    double F1, F2, F3, F4, G1, G2, G3, G4;
    //  [Oel]   F = index 1
    //  [Luft]  G = index 2
        
        F1 = Oel(daten, dyn_daten,      Temp[1][n],                 Temp[2][n]);
        G1 = Luft(daten, dyn_daten,     Temp[1][n],                 Temp[2][n]);
        F2 = Oel(daten, dyn_daten,      Temp[1][n] + F1 * (h / 2.), Temp[2][n] + G1 * (h / 2.));
        G2 = Luft(daten, dyn_daten,     Temp[1][n] + F1 * (h / 2.), Temp[2][n] + G1 * (h / 2.));
        F3 = Oel(daten, dyn_daten,      Temp[1][n] + F2 * (h / 2.), Temp[2][n] + G2 * (h / 2.));
        G3 = Luft(daten, dyn_daten,     Temp[1][n] + F2 * (h / 2.), Temp[2][n] + G2 * (h / 2.));
        F1 = Oel(daten, dyn_daten,      Temp[1][n] + F3 * h,        Temp[2][n] + G3 * h);
        G1 = Luft(daten, dyn_daten,     Temp[1][n] + F3 * h,        Temp[2][n] + G3 * h);

        Temp[1][n+1] = Temp[1][n] + (h / 6.) * (F1 + 2 * F2 + 2 * F3 + F4);
        Temp[2][n+1] = Temp[2][n] + (h / 6.) * (G1 + 2 * G2 + 2 * G3 + G4);  

}
