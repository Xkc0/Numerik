#include <iostream>
#include <math.h>
using namespace std;

void test(double *P) {
    *P = 2;
}

void test1(double A){
    cout << A << endl;
}


int main(){
cout << "Hallo" << endl;
int z = 0;
double i = 0;
double *P = &i;
double A[2][3];
for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            A[i][j] = z;
            z++;
        }
    }

cout << P << "  " << *P <<endl;

//cout << *P;
test(P);
test1(A[0][0]);
//cout << *P;
}
