#include <iostream>
#include <clocale>

using namespace std;

struct TPessoa{
    string nome,sexo;
    int idade;
};

struct TCelula{
    TPessoa pessoa;
    TCelula *proximo;
};

struct TListaP{
    TCelula *primeiro;
    TCelula *ultimo;
};

void criarListaPVazia(TListaP &lp){
    lp.primeiro = new TCelula;
    lp.ultimo = lp.primeiro;
    lp.primeiro->proximo = NULL;
}

void inserir(TListaP &lp, TPessoa x){
    lp.ultimo->proximo = new TCelula;
    lp.ultimo = lp.ultimo->proximo;
    lp.ultimo->pessoa = x;
    lp.ultimo->proximo = NULL;
}

void mostrar(TListaP lp){
    TCelula *celAux;
    celAux = lp.primeiro;

    cout << "=== MOSTRANDO A LISTA === "<< endl;
    while (celAux->proximo != NULL){

        celAux = celAux->proximo;
    }
}

TCelula *pegaAnterior(TListaP lp, TPessoa chave){
    TCelula *celAux;
    bool achou = false;

    celAux = lp.primeiro;

    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
    while (celAux->proximo != NULL){
        if (celAux->proximo->pessoa.idade == chave.idade){
            achou = true;
            return celAux;
        }
        celAux = celAux->proximo;
    }
    if (achou == false){
        return NULL;
    }
}

void retirarPorChave(TListaP &lp, TPessoa chave){
    TCelula *p = pegaAnterior(lp,chave);
    TCelula *q;

    q = p->proximo;
    p->proximo = q->proximo;
    delete(q);
}

bool verificarOrdem(TListaP lP){
    TCelula *celAux=lP.primeiro;
    bool ordem=false;
    int cont=0;

    while(celAux->proximo != NULL){
        if(celAux->proximo->pessoa.idade<celAux->proximo->proximo->pessoa.idade){
            cont++;
        }
        celAux=celAux->proximo;
    }

    if(cont==10){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    setlocale(LC_ALL,"Portuguese");

    TListaP lista;
    TPessoa x;

    criarListaPVazia(lista);

    for(int i=0;i<10;i++){
        cout << "Informe o nome da pessoa: " << endl;
        cin >> x.nome;

        cout << "Informe a idade: " << endl;
        cin >> x.idade;

        cout << "Informe o sexo (M ou F) " << endl;
        cin >> x.sexo;
    }

    //Eu entendi que para ornedar a lista dentro dela mesma seria só ir adicionando as pessoas em ordem na mesma lista e depois apagar as pessoas anteriores que
    //estavam desorganizadas, porém não consegui uma maneira de determinar qual a ordem certa

    return 0;
}
