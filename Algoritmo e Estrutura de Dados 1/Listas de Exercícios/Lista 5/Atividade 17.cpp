#include <iostream>
#include <clocale>
using namespace std;

int cL,cC;
double matA[4][4];

void pElementDiagSec(){

    cout << "\n\nElementos da diagonal secundária:\n";

    for(int i=0;i<4;i++){
        cout << matA[i][3-i] << "   ";
    }
}

//Calcula e mostra a média dos elementos da diagonal principal
double fMedElementDiagPrin(){

    float media=0;

    cout << "\n\nMédia dos elementos da diagonal principal: ";

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

//Faz uma representação gráfica
void pGrafica(){

    cout << "\nRepresentação gráfica da Matriz A:\n\n";

    for(cL=0;cL<4;cL++){
        for(cC=0;cC<4;cC++){
            cout << matA[cL][cC] << "    ";
        }
        cout << endl;
    }
    pElementDiagPrin();
}

//Lê os elementos da matriz
void pPreenchimento(){
    for(cL=0;cL<4;cL++){
        for(cC=0;cC<4;cC++){
            cout << "Informe o número da " << cL+1 << "ª linha da " << cC+1 << "ª coluna: ";
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
