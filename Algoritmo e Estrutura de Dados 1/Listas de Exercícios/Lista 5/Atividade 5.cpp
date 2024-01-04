#include <iostream>
#include <clocale>
using namespace std;

int n;

double fCalculo(int n){

    int cont;

    for(cont=1;cont<11;cont++){

        cout << n << "+" << cont << "= " << n+cont << "     " << n << "-" << cont << "= " << n-cont << "     " << n << "x" << cont << "= " << n*cont << "     " << n*cont << "/" << n << "= " << cont << endl;
    }

}

void pTabuada(){

    while(n>=0){
        cout << "Informe o número que deseja saber a tabuada: ";
        cin >> n;

        if(n>=0){
        fCalculo(n);
        }
    }
}

int main(){

	setlocale(LC_ALL,"Portuguese");

	pTabuada();

	return 0;
}
