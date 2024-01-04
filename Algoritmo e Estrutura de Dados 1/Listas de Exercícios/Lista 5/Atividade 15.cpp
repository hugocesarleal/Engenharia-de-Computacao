#include <iostream>
#include <clocale>
using namespace std;

float vetNum[3];

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

    cout << "Vetor original: " << vetNum[0] << "   " << vetNum[1] << "   " << vetNum[2];
    cout << "\nVetor em ordem crescente: " << menor << "   " << meio << "   " << maior;
}

int main(){

    int a,b,c;

	setlocale(LC_ALL,"Portuguese");

    for(int i=0;i<3;i++){
	cout << "Informe o " << i+1 << "º número: ";
	cin >> vetNum[i];
    }

	pOrdem(vetNum[0],vetNum[1],vetNum[2]);

	return 0;
}
