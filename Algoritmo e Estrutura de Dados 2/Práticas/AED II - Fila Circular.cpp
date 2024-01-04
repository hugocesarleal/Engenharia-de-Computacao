#include <iostream>
#include <clocale>
using namespace std;

// ESTA VERS�O SE BASEIA NA IMPLEMENTA�AO CIRCULAR PROPOSTA POR ZIVIANI.
// O PROBLEMA DE "N�O CABER" APESAR DE TER POSI��O LIVRE � RESOLVIDO.

// SESS�O DE DECLARA��ES

const int maxTam = 5;

// ESTRUTURA

struct TFilaACircular{
    int vetItens[maxTam];
    int frente;
    int tras;
    int contItens; //criado por n�s para ser usado nas opera��es
                    // estaVazia e estaCheia, resolvendo o problema
                    // que ocorre ap�s 1 CICLO completo
};

// OPERA��ES B�SICAS
void criarFilaVazia(TFilaACircular &f){
    f.frente = 0;
    f.tras = f.frente;
    f.contItens = 0; // quantidade
}

bool estaVazia(TFilaACircular f){
    //return f.frente == f.tras;
        // AP�S 1 CICLO ENF->DESENF, ELA SE CONFUNDE SOBRE VAZIA/CHEIA
    //ou
    return f.contItens == 0;
}

bool estaCheia(TFilaACircular f){
    //return f.tras >= maxTam; PROBLEMA!!!
    return f.contItens == maxTam;
}

void enfileirar(TFilaACircular &f, int x){
    //if (estaCheia(f)){

    //if((f.tras+1) % maxTam == f.frente){ PROBLEMA
    if (estaCheia(f)){
        cout << "N�o posso enfileirar. Fila Cheia!" << endl;
    }
    else{
        f.vetItens[f.tras] = x;
        //f.tras++; // INCREMENTAR
        f.tras = (f.tras+1) % maxTam;
        f.contItens++;
    }
}

void desenfileirar(TFilaACircular &f){
    if (estaVazia(f)){
        cout << "N�o posso desenfileirar. Fila Vazia!" << endl;
    }
    else{
        //f.frente++; PROBLEMA
        f.frente = (f.frente+1) % maxTam;
        f.contItens--;
    }
}


// PARA CASA: mostrar!!!
void mostrar(TFilaACircular f){
    int aux;

    cout << "=== MOSTRANDO A FILA ===" << endl;
    if (estaVazia(f)){
        cout << "Nada para mostrar. Fila Vazia!" << endl;
    }
    else{
        aux=f.frente;
        for(int i=0;i<f.contItens;i++){
            cout << "Frente: " << f.frente << "   Tr�s: " << f.tras << "   Aux: " << aux << endl;
            cout << "Pos: " << aux << ": " << f.vetItens[aux] << endl;
            aux=(aux+1)%maxTam;

        }

        cout << "\n\nVetItens Completo: " << "\nPosi��o 0: " << f.vetItens[0] << "\nPosi��o 1: " << f.vetItens[1] << "\nPosi��o 2: " << f.vetItens[2] << "\nPosi��o 3: " << f.vetItens[3] << "\nPosi��o 4: " << f.vetItens[4];
    }
}

int main(){

    setlocale(LC_ALL,"Portuguese");//para acentua��o e caracteres especiais

    TFilaACircular fila; //instancia��o

    criarFilaVazia(fila); // prepara para o uso
    // n�o pode, lembra!!!

    int val,num;

    escolha:

    cout << "O que vai fazer?\n1 - Enfileirar\n2 - Desenfileirar\n3 - Mostrar\n";
    cout << "Frente: " << fila.frente << "   Tr�s: " << fila.tras << endl;
    cin >> val;

    system("cls");

    switch(val){
    case 1:

        cout << "Qual n�mero ser� enfileirado? ";
        cin >> num;

        enfileirar(fila,num);

        system("pause");
        system("cls");
        goto escolha;

        break;
    case 2:

        desenfileirar(fila);

        cout << "Desenfileirado com sucesso!" << endl;

        system("pause");
        system("cls");
        goto escolha;

        break;
    case 3:

        mostrar(fila);

        system("pause");
        system("cls");
        goto escolha;

        break;
    default:
        cout << "Inv�lido\n";
        system("pause");
        system("cls");
        goto escolha;
    }

    return 0;
}
