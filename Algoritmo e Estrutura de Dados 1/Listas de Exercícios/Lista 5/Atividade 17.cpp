#include <iostream>
#include <clocale>
using namespace std;

int cL,cC;
double matA[4][4];

void pElementDiagSec(){

    cout << "\n\nElementos da diagonal secund�ria:\n";

    for(int i=0;i<4;i++){
        cout << matA[i][3-i] << "   ";
    }
}

//Calcula e mostra a m�dia dos elementos da diagonal principal
double fMedElementDiagPrin(){

    float media=0;

    cout << "\n\nM�dia dos elementos da diagonal principal: ";

    for(cL=0;cL<4;cL++){
        for(cC=0;cC<4;cC++){
            if(cL==cC){
                media = media + matA[cL][cC];
            }
        }
    }

    media = media/4;

    cout << media;

    pElementDiagSec();
}

//Mostra os elementos da diagonal principal
void pElementDiagPrin(){

    cout << "\nElementos da diagonal principal:\n";

    for(cL=0;cL<4;cL++){
        for(cC=0;cC<4;cC++){
            if(cL==cC){
                cout << matA[cL][cC] << "   ";
            }
        }
    }
    fMedElementDiagPrin();
}

//Faz uma representa��o gr�fica
void pGrafica(){

    cout << "\nRepresenta��o gr�fica da Matriz A:\n\n";

    for(cL=0;cL<4;cL++){
        for(cC=0;cC<4;cC++){
            cout << matA[cL][cC] << "    ";
        }
        cout << endl;
    }
    pElementDiagPrin();
}

//L� os elementos da matriz
void pPreenchimento(){
    for(cL=0;cL<4;cL++){
        for(cC=0;cC<4;cC++){
            cout << "Informe o n�mero da " << cL+1 << "� linha da " << cC+1 << "� coluna: ";
            cin >> matA[cL][cC];
        }
    }
    pGrafica();
}

int main(){

	setlocale(LC_ALL,"Portuguese");

    pPreenchimento();

	return 0;
}
