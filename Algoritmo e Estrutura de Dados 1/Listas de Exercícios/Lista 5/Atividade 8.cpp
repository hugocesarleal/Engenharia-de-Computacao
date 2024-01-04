#include <iostream>
#include <clocale>
using namespace std;

double vetNumero[20];

int fMaior(){

    double controleMaior=-999999;

    for(int i=0;i<20;i++){

        if(vetNumero[i]>controleMaior){
            controleMaior=vetNumero[i];
        }
    }
    return controleMaior;
}

void pVetor(){

    double maior;

    for(int i=0;i<20;i++){

        cout << "Informe o " << i+1 << "º número: ";
        cin >> vetNumero[i];

        maior = fMaior();
    }
    cout << "O maior número informado é " << maior;
}

int main(){

	setlocale(LC_ALL,"Portuguese");

	pVetor();

	return 0;
}
