#include <iostream>
#include <clocale>
using namespace std;

void pOrdem(int a,int b,int c){

    int maior,menor,meio;

    //Determina o maior
    if(a>b && a>c){
        maior=a;
    }
    if(b>a && b>c){
        maior=b;
    }
    if(c>a && c>b){
        maior=c;
    }

    //Determina o menor
    if(a<b && a<c){
        menor=a;
    }
    if(b<a && b<c){
        menor=b;
    }
    if(c<a && c<b){
        menor=c;
    }

    //Determina o do meio
    if(a>menor && a<maior){
        meio=a;
    }
    if(b>menor && b<maior){
        meio=b;
    }
    if(c>menor && c<maior){
        meio=c;
    }

    cout << "Ordem crescente: " << menor << "   " << meio << "   " << maior;
}

int main(){

    int a,b,c;

	setlocale(LC_ALL,"Portuguese");

	cout << "Informe o primeiro número: ";
	cin >> a;

	cout << "Informe o segundo número: ";
	cin >> b;

	cout << "Informe o terceiro número: ";
	cin >> c;

	pOrdem(a,b,c);

	return 0;
}
