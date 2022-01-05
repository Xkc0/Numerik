#include <iostream>
#include <math.h>
using namespace std;

void test(double *P) {
    *P = 2;
}


int main(){
cout << "Hallo" << endl;
double i = 0;
double *P = &i;
cout << "test ";
cout << *P;
test(P);
cout << "test ";
cout << *P;

}
