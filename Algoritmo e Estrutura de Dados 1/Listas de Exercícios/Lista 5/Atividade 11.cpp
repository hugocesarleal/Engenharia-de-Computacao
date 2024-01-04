#include <iostream>
#include <clocale>
using namespace std;

double fTempo(int tempo){

    int segundos,minutos,horas;

    segundos=tempo%60;
    minutos=(tempo-segundos)/60;
    horas=minutos/60;
    minutos=minutos%60;

    cout << tempo << " segundos são: \n" << horas << " horas \n" << minutos << " minutos \n" << segundos << " segundos";

}

int main(){

    int tempo;

	setlocale(LC_ALL,"Portuguese");

	cout << "Informe o tempo em segundos: ";
    cin >> tempo;

	fTempo(tempo);

	return 0;
}
