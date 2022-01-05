#include <iostream>
#include <cmath>
#include "Functions.h"
using namespace std;



int main(){

//Initialisierung
    int StoffdatenAnzahl = 126;
    int m = 2;
    int n = 100;
    double z = 1;


    double daten[StoffdatenAnzahl];
    double dyn_daten[10];
    double **Temp = new double *[m];
    for (int i = 0; i < m; i++){
        Temp[i] = new double [n];
    }

    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            Temp[i][j] = 1;
        }
    }


//Funktionen
    datenEinlesen(daten);
    cout << "HAllo";
    datenAusgeben(daten, StoffdatenAnzahl);

    /*
    Oel(daten, dyn_daten, Temp, z);
    Luft(daten, dyn_daten, Temp, z);
    */

/*
    for(int i = 0; i <= StoffdatenAnzahl; i++){
        cout << eingaben[i] << endl;
    }
*/


}




