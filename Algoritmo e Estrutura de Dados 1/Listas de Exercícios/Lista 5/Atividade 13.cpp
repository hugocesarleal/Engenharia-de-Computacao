#include <iostream>
#include <clocale>
using namespace std;

double fConceito(double media){
    if(media>=0 && media<=4.9){
        cout << "M�dia: " << media << "\nConceito: D";
    }
    else{
            if(media>=5 && media<=6.9){
            cout << "M�dia: " << media << "\nConceito: C";
        }
        else{
                if(media>=7 && media<=8.9){
                cout << "M�dia: " << media << "\nConceito: B";
            }
            else{
                cout << "M�dia: " << media << "\nConceito: A";
            }
        }
    }
}

int main(){

    double media;

	setlocale(LC_ALL,"Portuguese");

	cout << "Informe a m�dia final do aluo: ";
	cin >> media;

	fConceito(media);

	return 0;
}
