#include <iostream>
#include <clocale>

using namespace std;

struct TListaA
{
    int vetItens[5];
    int primeiro;
    int ultimo;
};

struct TLista3A
{
    int vetItens[10];
    int primeiro;
    int ultimo;
};

void criarLista_A(TListaA &lA)
{
    lA.primeiro = 0;
    lA.ultimo = lA.primeiro;
}

void criarLista_3A(TLista3A &lA)
{
    lA.primeiro = 0;
    lA.ultimo = lA.primeiro;
}

bool estaVazia(TListaA lA)
{
    return lA.primeiro == lA.ultimo;
}

bool estaVazia3A(TLista3A lA)
{
    return lA.primeiro == lA.ultimo;
}

bool estaCheia(TListaA lA)
{
    return lA.ultimo >= 5;
}

bool estaCheia3A(TLista3A lA)
{
    return lA.ultimo >= 10;
}

void inserirItem(TListaA &lA, int x)
{
    if (estaCheia(lA))
    {
        cout << "Lista cheia. Não posso inserir!" << endl;
    }
    else
    {
        lA.vetItens[lA.ultimo] = x;
        lA.ultimo++;
    }
}

void inserirItem3A(TLista3A &lA, int x)
{
    if (estaCheia3A(lA))
    {
        cout << "Lista cheia. Não posso inserir!" << endl;
    }
    else
    {
        lA.vetItens[lA.ultimo] = x;
        lA.ultimo++;
    }
}

void mostrarLista(TListaA lA)
{
    cout << "=== Mostrando itens da lista ===" << endl;
    for (int i=lA.primeiro; i<lA.ultimo; i++)
    {
        cout << "Número : " << lA.vetItens[i] << endl;
    }
}

void mostrarLista3A(TLista3A lA)
{
    cout << "=== Mostrando itens da lista ===" << endl;
    for (int i=lA.primeiro; i<lA.ultimo; i++)
    {
        cout << "Número : " << lA.vetItens[i] << endl;
    }
}

void retirar(TListaA &lA,int p)
{

    int excluido;

    if(estaVazia(lA))
    {
        cout << "A lista está vazia!";
    }
    else
    {
        lA.ultimo--;
        excluido=lA.vetItens[p];

        for(int i=p; i<lA.ultimo; i++)
        {
            lA.vetItens[i]=lA.vetItens[i+1];
        }
    }
}

int fBusca(TListaA lA,int b)
{

    for(int i=0; i<5; i++)
    {

        if(lA.vetItens[i]==b)
        {
            return i;
        }
    }

    return -1;
}

int retornaItem(TListaA lA, int p){

    return lA.vetItens[p];
}

void concatenar(TListaA l1A, TListaA l2A, TLista3A &l3A){

    int x;

    for(int i=0;i<5;i++){
        x = retornaItem(l1A,i);

        inserirItem3A(l3A,x);
    }

    for(int i=0;i<5;i++){
        x = retornaItem(l2A,i);

        inserirItem3A(l3A,x);
    }
}

void intercalar(TListaA l1A, TListaA l2A, TLista3A &l4A){

    int x;

    for(int i=0;i<5;i++){
        x = retornaItem(l1A,i);

        inserirItem3A(l4A,x);

        x = retornaItem(l2A,i);

        inserirItem3A(l4A,x);
    }
}

int main()
{

    setlocale(LC_ALL,"Portuguese");

    TListaA lista1A, lista2A;
    TLista3A lista3A,lista4A;
    int item,pos,swi;

    criarLista_A(lista1A);
    criarLista_A(lista2A);
    criarLista_3A(lista3A);
    criarLista_3A(lista4A);

    for(int i=0;i<5;i++){

        int busca;

        cout << "Informe o " << i+1 << "º número: " << endl;
        cin >> item;

        busca=fBusca(lista1A,item);

        if(busca!=-1){
            cout << "O número informado já está na lista na posição " << busca << endl;
            i--;
        }
        else{
            inserirItem(lista1A,item);
        }
    }

    cout << "Deseja remover um número?\n1 - Sim\n2 - Não\n";
    cin >> swi;

    if(swi==1){
    cout << "Qual elemento deseja remover? ";
    cin >> item;

    pos=fBusca(lista1A,item);

    retirar(lista1A,pos);

    cout << "Número retirado!" << endl;

    }

    mostrarLista(lista1A);

    for(int i=0;i<5;i++){

        item = retornaItem(lista1A,i);

        inserirItem(lista2A,item);
    }

    cout << "Lista copiada:" <<endl;

    mostrarLista(lista2A);

    concatenar(lista1A,lista2A,lista3A);

    cout << "Lista concatenada:" <<endl;

    mostrarLista3A(lista3A);

    intercalar(lista1A,lista2A,lista4A);

    cout << "Lista intercalada:" <<endl;

    mostrarLista3A(lista4A);

    return 0;
}
