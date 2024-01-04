#include <iostream>
#include <clocale>
using namespace std;

double fNota(int nota1,int nota2,int nota3,string letra){

    double media;

    if(letra == "A" || letra == "a"){
        media = (nota1+nota2+nota3)/3;
        cout << "A média aritmética do aluno é: " << media;
    }
    else{
        if(letra == "P" || letra == "p"){
        media = ((nota1*5)+(nota2*3)+(nota3*2))/10;
        cout << "A média ponderada do aluno é: " << media;
    }
        else{
        cout << "Letra informada inválida!";
        }
    }
}

int main(){

    int nota1,nota2,nota3;
    string letra;

	setlocale(LC_ALL,"Portuguese");

	cout << "Informe a primeira nota: ";
    cin >> nota1;

    cout << "Informe a segunda nota: ";
    cin >> nota2;

    cout << "Informe a terceira nota: ";
    cin >> nota3;

    cout << "Informe a letra (A ou P): ";
    cin >> letra;

	fNota(nota1,nota2,nota3,letra);

	return 0;
}
