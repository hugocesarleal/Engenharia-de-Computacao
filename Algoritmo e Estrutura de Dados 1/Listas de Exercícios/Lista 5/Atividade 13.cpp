#include <iostream>
#include <clocale>
using namespace std;

double fConceito(double media){
    if(media>=0 && media<=4.9){
        cout << "Média: " << media << "\nConceito: D";
    }
    else{
            if(media>=5 && media<=6.9){
            cout << "Média: " << media << "\nConceito: C";
        }
        else{
                if(media>=7 && media<=8.9){
                cout << "Média: " << media << "\nConceito: B";
            }
            else{
                cout << "Média: " << media << "\nConceito: A";
            }
        }
    }
}

int main(){

    double media;

	setlocale(LC_ALL,"Portuguese");

	cout << "Informe a média final do aluo: ";
	cin >> media;

	fConceito(media);

	return 0;
}
