#include <iostream>
#include <clocale>
using namespace std;

double fMultiplo(int a, int b){

    double result;

    if(a<b){
        result = b%a;
    }
    else{
        result = a%b;
    }
    return result;
}

void pControle(){

    int c,d,multiplo;

    cout << "Informe o primeiro valor: ";
    cin >> c;

    cout << "Informe o segundo valor: ";
    cin >> d;

    multiplo = fMultiplo(c,d);

    if(multiplo == 0){
        cout << "S�o m�ltiplos";
    }
    else{
        cout << "N�o s�o m�ltiplos";
    }
}

int main(){

	setlocale(LC_ALL,"Portuguese");

	pControle();

	return 0;
}

