#include <iostream>
#include <clocale>
using namespace std;

// ESTA VERSÃO SE BASEIA NA IMPLEMENTAÇAO CIRCULAR PROPOSTA POR ZIVIANI.
// O PROBLEMA DE "NÃO CABER" APESAR DE TER POSIÇÃO LIVRE É RESOLVIDO.

// SESSÃO DE DECLARAÇÕES

const int maxTam = 5;

// ESTRUTURA

struct TFilaACircular{
    int vetItens[maxTam];
    int frente;
    int tras;
    int contItens; //criado por nós para ser usado nas operações
                    // estaVazia e estaCheia, resolvendo o problema
                    // que ocorre após 1 CICLO completo
};

// OPERAÇÕES BÁSICAS
void criarFilaVazia(TFilaACircular &f){
    f.frente = 0;
    f.tras = f.frente;
    f.contItens = 0; // quantidade
}

bool estaVazia(TFilaACircular f){
    //return f.frente == f.tras;
        // APÓS 1 CICLO ENF->DESENF, ELA SE CONFUNDE SOBRE VAZIA/CHEIA
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
        cout << "Não posso enfileirar. Fila Cheia!" << endl;
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
        cout << "Não posso desenfileirar. Fila Vazia!" << endl;
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
            cout << "Frente: " << f.frente << "   Trás: " << f.tras << "   Aux: " << aux << endl;
            cout << "Pos: " << aux << ": " << f.vetItens[aux] << endl;
            aux=(aux+1)%maxTam;

        }

        cout << "\n\nVetItens Completo: " << "\nPosição 0: " << f.vetItens[0] << "\nPosição 1: " << f.vetItens[1] << "\nPosição 2: " << f.vetItens[2] << "\nPosição 3: " << f.vetItens[3] << "\nPosição 4: " << f.vetItens[4];
    }
}

int main(){

    setlocale(LC_ALL,"Portuguese");//para acentuação e caracteres especiais

    TFilaACircular fila; //instanciação

    criarFilaVazia(fila); // prepara para o uso
    // não pode, lembra!!!

    int val,num;

    escolha:

    cout << "O que vai fazer?\n1 - Enfileirar\n2 - Desenfileirar\n3 - Mostrar\n";
    cout << "Frente: " << fila.frente << "   Trás: " << fila.tras << endl;
    cin >> val;

    system("cls");

    switch(val){
    case 1:

        cout << "Qual número será enfileirado? ";
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
        cout << "Inválido\n";
        system("pause");
        system("cls");
        goto escolha;
    }

    return 0;
}
