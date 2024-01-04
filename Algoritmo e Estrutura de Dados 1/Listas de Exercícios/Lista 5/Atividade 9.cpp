#include <iostream>
#include <clocale>
using namespace std;

bool fParimpar(int a){

    if(a%2==0){
        return true;
    }
    else{
        return false;
    }
}

void pControle(){

    int numero=1;

    while(numero != 0){
        cout << "Informe um número: ";
        cin>> numero;

        if(fParimpar(numero)==true){
            cout << numero << " é par." << endl;
        }
        else{
            cout << numero << " é ímpar." << endl;
        }
	}
}

int main(){

	setlocale(LC_ALL,"Portuguese");

	pControle();

	return 0;
}
