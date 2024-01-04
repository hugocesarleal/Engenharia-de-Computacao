#include <iostream>
#include <clocale>
using namespace std;


double fFatorial(int a){

    double fatorial=a;

    for(int i=a-1;i>0;i=i-1){

        fatorial = fatorial*i;
    }
    cout << fatorial;
}

int main(){

	setlocale(LC_ALL,"Portuguese");

	int a;

	cout << "Informe um valor para saber seu fatorial: ";
	cin >> a;

	fFatorial(a);

	return 0;
}
