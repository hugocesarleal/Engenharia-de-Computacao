#include <iostream>
#include <clocale>

using namespace std;

struct TCelula
{
    int item;
    TCelula *proximo;
};

struct TListaP
{
    TCelula *primeiro;
    TCelula *ultimo;
    int quant;
};

void criarLPVazia(TListaP &lp)
{
    lp.primeiro = new TCelula;
    lp.ultimo = lp.primeiro;
    lp.primeiro->proximo = NULL;
    lp.quant = 0;
}

void inserirLP(TListaP &lp, int x)
{
    lp.ultimo->proximo = new TCelula;
    lp.ultimo = lp.ultimo->proximo;
    lp.ultimo->item = x;
    lp.ultimo->proximo = NULL;
    lp.quant++;
}

bool estaVaziaLP(TListaP lp)
{
    return lp.primeiro == lp.ultimo;
}

void mostrar(TListaP lp)
{

    TCelula *celAux;
    celAux = lp.primeiro->proximo;

    cout << "=== MOSTRANDO A LISTA === "<< endl;

    if (estaVaziaLP(lp))
    {
        cout << "Nenhum item a ser mostrado. Lista vazia!" << endl;
        cout << "-------------------------------------------" << endl;

    }
    else
    {
        while (celAux != NULL)
        {
            cout << "   Valor:   " << celAux->item << endl;
            celAux = celAux->proximo;

            cout << "-------------------------------------------" << endl;
        }
    }
}

TCelula *pegaAnterior(TListaP lp, int chaveBusca)
{

    TCelula *celAux;
    bool achou = false;

    celAux = lp.primeiro;

    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
    while (celAux->proximo != NULL)
    {
        if (celAux->proximo->item == chaveBusca)
        {
            achou = true;
            return celAux;
        }
        celAux = celAux->proximo;
    }
    if (achou == false)
    {
        return NULL;
    }
}

void retirarPorChave(TListaP &lp, int chaveBusca)
{
    TCelula *anterior = pegaAnterior(lp,chaveBusca);

    if (anterior == NULL)
    {
        cout << "A chave não foi encontrada. Nenhuma célula a retirar." << endl;
    }
    else
    {
        TCelula *celAlvo;

        celAlvo = anterior->proximo;
        anterior->proximo = celAlvo->proximo;

        delete(celAlvo);
        lp.quant--;
    }
}

void concatenar2Listas(TListaP l1, TListaP l2, TListaP &l3)
{

    if (estaVaziaLP(l1) || estaVaziaLP(l2))
    {
        cout << "Não é possível concatenar!" << endl;
    }
    else
    {
        TCelula *celAux = l1.primeiro;

        while (celAux->proximo != NULL)
        {
            inserirLP(l3,celAux->proximo->item);
            celAux = celAux->proximo;
        }

        celAux = l2.primeiro;

        while (celAux->proximo != NULL)
        {
            inserirLP(l3,celAux->proximo->item);
            celAux = celAux->proximo;
        }
    }

}

void intercalar2LP(TListaP l1, TListaP l2, TListaP &l4)
{
    if (!estaVaziaLP(l1) && !estaVaziaLP(l2))
    {
        if (l1.quant == l2.quant)
        {
            TCelula *celAux1, *celAux2;
            celAux1 = l1.primeiro;
            celAux2 = l2.primeiro;

            while (celAux1->proximo != NULL)
            {
                inserirLP(l4, celAux1->proximo->item);
                inserirLP(l4, celAux2->proximo->item);

                celAux1 = celAux1->proximo;
                celAux2 = celAux2->proximo;
            }
        }
    }
}

int jaExiste(TListaP lP, int x)
{
    TCelula *celAux=lP.primeiro;

    while(celAux->proximo!= NULL)
    {
        if(celAux->proximo->item == x)
        {
            return -1;
        }
        celAux=celAux->proximo;
    }
}

void copiar(TListaP l1, TListaP &l2){

    TCelula *celAux=l1.primeiro;
    int x;

    while(celAux->proximo != NULL){
        x = celAux->proximo->item;

        inserirLP(l2,x);

        celAux=celAux->proximo;
    }

}

int main()
{

    setlocale(LC_ALL,"Portuguese");

    TListaP lista1A, lista2A, lista3A, lista4A;

    criarLPVazia(lista1A);
    criarLPVazia(lista2A);
    criarLPVazia(lista3A);
    criarLPVazia(lista4A);


    int item,res;

    while(res!=2)
    {
        cout << "Qual número deseja inserir na lista? " << endl;
        cin >> item;

        if(jaExiste(lista1A,item)==-1){

            cout << "O item informado já está na lista, então não foi adicionado!" << endl;
        }
        else{
            inserirLP(lista1A,item);
        }
        cout << "Deseja inserir outro item?\n1 - Sim\n2 - Não\n";
        cin >> res;
    }

    mostrar(lista1A);

    cout << "Deseja remover algum item?\n1 - Sim\n2 - Não" << endl;
    cin >> res;

    if(res==1){
        cout << "Qual item deseja remover? ";
        cin >> item;

        retirarPorChave(lista1A,item);
    }

    mostrar(lista1A);

    copiar(lista1A,lista2A);

    cout << "Lista copiada: " << endl;

    mostrar(lista2A);

    cout << endl;
    cout << "------------- CONCATENANDO -------------" << endl;
    concatenar2Listas(lista1A,lista2A,lista3A);

    cout << "Lista concatenada: " << endl;
    mostrar(lista3A);

    cout << endl;
    cout << "------------- INTERCALANDO -------------" << endl;
    intercalar2LP(lista1A,lista2A,lista4A);

    cout << "Lista intercalada: " << endl;
    mostrar(lista4A);

    return 0;
}
