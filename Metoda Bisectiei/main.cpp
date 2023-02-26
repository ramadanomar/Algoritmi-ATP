#include <iostream>
#include <cmath>
#include <iomanip>

#define PRECIZIE 10

using namespace std;

double f(double x) {
    return (x*x-7*x+12);
}

void bisectie(double x1, double x2, double eps, int n, double(*f)(double), int &er, double &sol) {
    double f1 = f(x1);
    double f2 = f(x2);

    if (f1*f2 > 0) {
//        cerr << "Nu exista radacini intre " << x1 << " & " << x2 << " sau exista un numar par de radacini";
        er = 0;
        return;
    }

    double mij, temp;

    for(int i=1; i<=n;i++) {
        mij = (x1+x2)/2;
        // Verificare daca rezolva equatia
        temp = f(mij); // Folosim variabila ca sa nu mai apelam functia pt urmatoarele verificari.
        //verificam daca er este mai mica decat eps
        if (temp == 0) {
            // Este radacina exacta
            sol = mij;
            er = 1;
            return;
        }
        if(fabs(x1-x2) < eps) {
            er = 2; // solutie aproximata
            sol = mij;
            return;
        }
        // Adica aici
        if (f1*temp<0) {
            x2 = mij;
        }
        else {
            x1 = mij;
        }
    }
    // sol aproximata
    er = 2;
    sol = mij;
}

int main() {
    cout<<setprecision(PRECIZIE)<<fixed;

    double x1 = 3.1;
    double x2 = 5;
    double eps = ::pow(10,-PRECIZIE);
    int n = 100;
    int er;
    double sol;

    bisectie(x1, x2, eps, n, f, er, sol);

    if (er == 0) {
        cerr << "Nu exista radacini intre " << x1 << " & " << x2 << " sau exista un numar par de radacini";
    } else if (er == 1) {
        cout << "Solutie exacta gasita: x = " << sol << endl;
    } else {
        cout << "Solutia x = " << sol << " este adevarata pentru o precizie de "<< eps << "." << endl;
    }

    return 0;
}
