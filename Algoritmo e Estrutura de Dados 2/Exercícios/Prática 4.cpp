#include <iostream>
#include <clocale>
using namespace std;

// ESTRUTURAS
struct TItem{
    int chave;
    // ...
};

struct TCelula{
    TCelula *anterior;
    TItem item;
    TCelula *proximo;
};

struct TListaDP{
    TCelula *primeiro;
    TCelula *ultimo;
    int cont;
};


// OPERA��ES B�SICAS

void criarListaPVazia(TListaDP &lp){
    lp.primeiro = new TCelula;
    lp.ultimo = lp.primeiro;
    lp.primeiro->anterior = lp.ultimo; //adicionado para duplamente encadeada
    lp.ultimo->proximo = lp.primeiro;
    lp.cont=0;
}

void inserir(TListaDP &lp, TItem x){

    if(lp.cont==0){
        cout << "VERDADEIRO";
        lp.ultimo->item = x;
        lp.cont++;
    }
    else{
        cout << "FALSO";

        lp.ultimo->proximo = new TCelula;
        lp.ultimo->proximo->anterior = lp.ultimo;
        lp.ultimo = lp.ultimo->proximo;
        lp.ultimo->item = x;
        lp.ultimo->proximo = lp.primeiro;
        lp.primeiro->anterior=lp.ultimo;
    }

    // "debugando" na unha
    cout << "-------------------------------" << endl;
    cout << "Novo Ultimo:  " << lp.ultimo << endl;
    cout << "Ant de Ult:   " << lp.ultimo->anterior << endl;
    cout << "Prox Ultimo:  " << lp.ultimo->proximo << endl;
}
//
void mostrarED(TListaDP lp){
    TCelula *celAux;
    celAux = lp.primeiro; // come�a como a primeira c�lula v�lida, ie, que tem item v�lido

    cout << "=== MOSTRANDO A LISTA DA ESQ->DIR === "<< endl;
    do{
        cout << "E.M.Cel: " << celAux << "   -   Valor: " << celAux->item.chave << endl;
        celAux = celAux->proximo;
    }while (celAux != lp.ultimo->proximo);
}

void mostrarDE(TListaDP lp){
    TCelula *celAux;
    celAux = lp.ultimo; // com�a pela c�lula ULTIMO, pois j� tem item v�lido

    cout << "=== MOSTRANDO A LISTA DA DIR->ESQ === "<< endl;
    do{
        cout << "E.M.Cel: " << celAux << "   -   Valor: " << celAux->item.chave << endl;
        celAux = celAux->anterior;
    }while (celAux != lp.primeiro->anterior);
}
//
//TCelula *pegaAnterior(TListaP lp, int chave){
//    TCelula *celAux;
//    bool achou = false;
//
//    celAux = lp.primeiro;   //n�o come�amos pela c�lula v�lida, e sim
//                            // pela cabe�a
//
//    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
//    while (celAux->proximo != NULL){
//        if (celAux->proximo->item == chave){
//            achou = true;
//            return celAux;
//        }
//        celAux = celAux->proximo;
//    }
//    if (achou == false){
//        return NULL;
//    }
//}
//
//void retirarPorChave(TListaP &lp, int chave){
//    TCelula *p = pegaAnterior(lp,chave); //anterior
//    TCelula *q; //alvo
//
//    q = p->proximo;
//    p->proximo = q->proximo;
//    cout << "EM Exclu�do: " << q << endl;
//    delete(q);
//}



int main(){

    setlocale(LC_ALL,"Portuguese");

    TListaDP lista; // instancia��o

    //preparando a lista para uso!
    criarListaPVazia(lista);



    cout << "EM cel Prim:  " << lista.primeiro << endl;
    cout << "EM cel Ulti:  " << lista.ultimo << endl;
    cout << "Ant de Prim:  " << lista.primeiro->anterior << endl;
    cout << "Prox de Prim: " << lista.primeiro->proximo << endl;
    cout << "Ant de Ult:   " << lista.ultimo->anterior << endl;
    cout << "Prox Ultimo:  " << lista.ultimo->proximo << endl;

    TItem iAux;
    iAux.chave = 5;
    inserir(lista,iAux);



    iAux.chave = 8;
    inserir(lista,iAux);

    iAux.chave = 14;
    inserir(lista,iAux);

    mostrarED(lista);

    mostrarDE(lista);


    return 0;
}
