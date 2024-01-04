#include <iostream>
#include <clocale>
using namespace std;

struct TProduto{
    int codigo, preco, estoque;
    string nome;
};

struct TCelula{
    TProduto item;
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

void inserir(TListaP &lp, TProduto x){
    lp.ultimo->proximo = new TCelula;
    lp.ultimo = lp.ultimo->proximo;
    lp.ultimo->item = x;
    lp.ultimo->proximo = NULL;
}

void mostrar(TListaP lp){
    TCelula *celAux;

    celAux = lp.primeiro;

    cout << "=== MOSTRANDO A LISTA === "<< endl;
    while (celAux->proximo != NULL){
        cout << "C�digo do produto: " << celAux->proximo->item.codigo << endl;
        cout << "Estoque do produto: " << celAux->proximo->item.estoque << endl;
        cout << "Nome do produto: " << celAux->proximo->item.nome << endl;
        cout << "Pre�o do produto: " << celAux->proximo->item.preco << endl;
        cout << "---------------------------------------" << endl;
        celAux = celAux->proximo;
    }
}

TCelula *pegaAnterior(TListaP lp, TProduto chave){
    TCelula *celAux;
    bool achou = false;

    celAux = lp.primeiro;
    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
    while (celAux->proximo != NULL){
        if (celAux->proximo->item.codigo == chave.codigo){
            achou = true;
            return celAux;
        }
        celAux = celAux->proximo;
    }
    if (achou == false){
        return NULL;
    }
}

void retirarPorChave(TListaP &lp, TProduto chave){
    TCelula *p = pegaAnterior(lp,chave);
    TCelula *q;

    q = p->proximo;
    p->proximo = q->proximo;
    delete(q);
}

int buscarItem(TListaP lP, int code){
    TCelula *celAux=lP.primeiro;
    int cont=1;

    while(celAux->proximo != NULL){
        if(celAux->proximo->item.codigo==code){
            return cont;
        }
        cont++;

        celAux=celAux->proximo;
    }
    return -1;
}

TProduto vizinhoEsq(TListaP lP, int x){
    TCelula *celAux=lP.primeiro;
    TProduto erro;
    bool primeiro=false;

    erro.codigo=-1;

    for(int i=1;i<x;i++){
        primeiro=true;
        celAux=celAux->proximo;
    }

    if(primeiro){
    return celAux->item;
    }
    else{
        cout << "O produto � esquerda da posi��o informada � o ponto de acesso!" << endl;
        return erro;
    }
}

void mostrarEstoqueBaixo(TListaP lP){
    TCelula *celAux=lP.primeiro;
    bool achou=true;

    while(celAux->proximo != NULL){
        if(celAux->proximo->item.estoque<5){
            achou=false;
            cout << "\nItem com estoque abaixo de 5:" << endl;
            cout << "C�digo do produto: " << celAux->proximo->item.codigo << endl;
            cout << "Estoque do produto: " << celAux->proximo->item.estoque << endl;
            cout << "Nome do produto: " << celAux->proximo->item.nome << endl;
            cout << "Pre�o do produto: " << celAux->proximo->item.preco << endl;
        }
        celAux=celAux->proximo;
    }

    if(achou){
        cout << "Nenhum produto est� abaixo do estoque 5!" << endl;
    }
}

TProduto produtoMaisCaro(TListaP lP){
    TCelula *celAux=lP.primeiro;
    TProduto caro;

    caro.preco=0;

    while(celAux->proximo != NULL){
        if(celAux->proximo->item.preco>caro.preco){
            caro=celAux->proximo->item;
        }
        celAux=celAux->proximo;
    }

    return caro;
}

TProduto produtoMaisBarato(TListaP lP){
    TCelula *celAux=lP.primeiro;
    TProduto barato;

    barato.preco=99999999;

    while(celAux->proximo != NULL){
        if(celAux->proximo->item.preco<barato.preco){
            barato=celAux->proximo->item;
        }
        celAux=celAux->proximo;
    }

    return barato;
}

int main(){

    setlocale(LC_ALL,"Portuguese");

    TListaP lista;
    TProduto x,y;
    int s,res;

    criarListaPVazia(lista);

    while (res != 2){

        cout << "Qual o c�digo do produto? ";
        cin >> x.codigo;

        cout << "Qual o estoque do produto? ";
        cin >> x.estoque;

        cout << "Qual o nome do produto? ";
        cin >> x.nome;

        cout << "Qual o pre�o do produto? ";
        cin >> x.preco;

        inserir(lista,x);

        cout << "Deseja cadastrar outro produto?\n1 - Sim\n2 - N�o\n";
        cin >> res;
    }

    mostrar(lista);

    cout << "Qual o c�digo do produto que est� buscando? ";
    cin >> res;

    s=buscarItem(lista,res);

    if(s==-1){
        cout << "C�digo n�o encontrado!" << endl;
    }
    else{
        cout << "O produto de c�digo " << res << " est� na posi��o " << s << endl;
    }

    cout << "Qual a posi��o do produto que est� a direita do desejado? ";
    cin >> res;

    y=vizinhoEsq(lista,res);

    if(y.codigo!=-1){
        cout << "C�digo do produto � esquerda: " << y.codigo << endl;
        cout << "Estoque do produto � esquerda: " << y.estoque << endl;
        cout << "Nome do produto � esquerda: " << y.nome << endl;
        cout << "Pre�o do produto � esquerda: " << y.preco << endl;
    }

    mostrarEstoqueBaixo(lista);

    y=produtoMaisCaro(lista);

    cout << "\nProduto mais caro registrado:" << endl;
    cout << "C�digo do produto: " << y.codigo << endl;
    cout << "Estoque do produto: " << y.estoque << endl;
    cout << "Nome do produto: " << y.nome << endl;
    cout << "Pre�o do produto: " << y.preco << endl;

    y=produtoMaisBarato(lista);

    cout << "\nProduto mais barato registrado:" << endl;
    cout << "C�digo do produto: " << y.codigo << endl;
    cout << "Estoque do produto: " << y.estoque << endl;
    cout << "Nome do produto: " << y.nome << endl;
    cout << "Pre�o do produto: " << y.preco << endl;

    return 0;
}
