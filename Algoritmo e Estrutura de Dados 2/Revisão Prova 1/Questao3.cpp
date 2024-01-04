#include <iostream>
#include <clocale>
#include <Windows.h>
#include <random>

using namespace std;

struct TMusica
{
    string titulo, artista;
    int duracao;
};

struct TCelula
{
    TMusica music;
    TCelula *proximo;
};

struct TListaP
{
    TCelula *primeiro;
    TCelula *ultimo;
    int quant;
};

struct TFilaP
{
    TCelula *frente;
    TCelula *tras;
};

struct TPilhaP
{
    TCelula *fundo;
    TCelula *topo;
};

void criarLPVazia(TListaP &lp)
{
    lp.primeiro = new TCelula;
    lp.ultimo = lp.primeiro;
    lp.primeiro->proximo = NULL;
    lp.quant = 0;
}

void inserirLP(TListaP &lp, TMusica x)
{
    lp.ultimo->proximo = new TCelula;
    lp.ultimo = lp.ultimo->proximo;
    lp.ultimo->music = x;
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
        cout << "Nenhuma música a ser mostrada." << endl;
        cout << "-------------------------------------------" << endl;

    }
    else
    {
        while (celAux != NULL)
        {
            cout << "Título: " << celAux->music.titulo << endl;
            cout << "Artista: " << celAux->music.artista << endl;
            cout << "Duração: " << celAux->music.duracao << endl;

            celAux = celAux->proximo;

            cout << "-------------------------------------------" << endl;
        }
    }
}

TCelula *pegaAnterior(TListaP lp, TMusica chaveBusca)
{

    TCelula *celAux;
    bool achou = false;

    celAux = lp.primeiro;

    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
    while (celAux->proximo != NULL)
    {
        if (celAux->proximo->music.artista == chaveBusca.artista)
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

void retirarPorArtista(TListaP &lp, TMusica chaveBusca)
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

void criarFilaPVazia(TFilaP &f)
{
    f.frente = new TCelula;
    f.tras = f.frente;
    f.frente->proximo = NULL;
}

bool estaVaziaFilaP(TFilaP f)
{
    return f.frente == f.tras;
}

void enfileirar(TFilaP &f, TMusica x)
{
    f.tras->proximo = new TCelula;
    f.tras = f.tras->proximo;
    f.tras->music = x;
    f.tras->proximo = NULL;
}

void mostrarFila(TFilaP f)
{
    TCelula *celAux;
    celAux = f.frente->proximo;

    if (estaVaziaFilaP(f))
    {
        cout << "Fila vazia! Nenhum elemento para mostrar!" << endl;
        cout << "-------------------------------------------" << endl;
    }
    else
    {
        cout << "Mostrando fila:" << endl;
        while (celAux->proximo != NULL)
        {
            cout << "\nTítulo: " << celAux->proximo->music.titulo << endl;
            cout << "Artista: " << celAux->proximo->music.artista << endl;
            cout << "Duração: " << celAux->proximo->music.duracao << endl;

            celAux = celAux->proximo;

            cout << "-------------------------------------------" << endl;
        }
    }
}

void desenfileirar(TFilaP &f)
{
    if (estaVaziaFilaP(f))
    {
        cout << "Fila Vazia! Nenhum elemento para desenfileirar..." << endl;
        cout << "-------------------------------------------" << endl;
    }
    else
    {
        TCelula *aux = f.frente;
        f.frente = f.frente->proximo;
        delete(aux);
    }
}

void criarPilhaPVazia(TPilhaP &p)
{
    p.topo = new TCelula;
    p.fundo = p.topo;
    p.fundo->proximo = NULL;
}

bool estaVaziaPilhaP(TPilhaP p)
{
    return p.topo->proximo == NULL;
}

void empilhar(TPilhaP &p, TMusica x)
{
    TCelula *aux = new TCelula;
    p.topo->music = x;
    aux->proximo = p.topo;
    p.topo = aux;
}


void mostrarPilha(TPilhaP p)
{
    TCelula *celAux;
    celAux = p.topo->proximo;


    cout << "=== MOSTRANDO A PILHA === "<< endl;
    if (estaVaziaPilhaP(p))
    {
        cout << "Pilha vazia! Nenhum elemento para mostrar!" << endl;
    }
    else
    {
        while (celAux->proximo != NULL)
        {

            cout << "Título: " << celAux->proximo->music.titulo << endl;
            cout << "Artista: " << celAux->proximo->music.artista << endl;
            cout << "Duração: " << celAux->proximo->music.duracao << endl;

            celAux = celAux->proximo;
            cout << "-------------------------------------------" << endl;
        }
    }
}

void desempilhar(TPilhaP &p)
{
    if (estaVaziaPilhaP(p))
    {
        cout << "Nenhum elemento para desempilhar. Pilha Vazia!" << endl;
    }
    else
    {
        TCelula *aux = p.topo;
        p.topo = p.topo->proximo;
        delete(aux);
    }
}

void buscar(TListaP lP, string n)
{

    TCelula *celAux=lP.primeiro;
    bool achou=true;

    while(celAux->proximo != NULL)
    {


        if(celAux->proximo->music.titulo == n)
        {

            cout << "Música encontrada: " << endl;
            cout << "Título: " << celAux->proximo->music.titulo << endl;
            cout << "Artista: " << celAux->proximo->music.artista << endl;
            cout << "Duração: " << celAux->proximo->music.duracao << endl;

            achou=false;
        }
        celAux=celAux->proximo;
    }
    if(achou)
    {
        cout << "Música não encontrada!\n" << endl;
    }
}

void mostrarArtista(TListaP lP, string n)
{

    TCelula *celAux=lP.primeiro;
    bool achou=true;

    while(celAux->proximo != NULL)
    {

        if(celAux->proximo->music.artista == n)
        {

            cout << "\nTítulo: " << celAux->proximo->music.titulo << endl;
            cout << "Artista: " << celAux->proximo->music.artista << endl;
            cout << "Duração: " << celAux->proximo->music.duracao << endl;
            cout << "-----------------------------------------------------" << endl;

            achou=false;
        }
        celAux=celAux->proximo;
    }
    if(achou)
    {
        cout << "Não existe nenhuma música desse artista!" << endl;
    }
}

void executarOrdem(TListaP lP, TFilaP &fP)
{

    TCelula *celAux=lP.primeiro;
    TMusica item=lP.primeiro->proximo->music;

    while(celAux->proximo!=NULL)
    {

        enfileirar(fP,item);

        celAux=celAux->proximo;

        item=celAux->music;
    }
    enfileirar(fP,item);
}

void executarAleatorio(TListaP lP, TFilaP &fP)
{

    TCelula *celAux=lP.primeiro;
    TMusica item,a,b,c,d,e;
    int x;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,5);

    a=celAux->proximo->music;
    b=celAux->proximo->proximo->music;
    c=celAux->proximo->proximo->proximo->music;
    d=celAux->proximo->proximo->proximo->proximo->music;
    e=celAux->proximo->proximo->proximo->proximo->proximo->music;

    for(int i=0; i<6; i++)
    {
        x=dist(gen);
        switch(x)
        {
        case 1:
            enfileirar(fP,a);
            break;
        case 2:
            enfileirar(fP,b);
            break;
        case 3:
            enfileirar(fP,c);
            break;
        case 4:
            enfileirar(fP,d);
            break;
        case 5:
            enfileirar(fP,e);
            break;
        }
    }
}

void reproduzir(TFilaP &f, TPilhaP &p)
{
    TCelula *celAux;
    celAux = f.frente->proximo;

    if (estaVaziaFilaP(f))
    {
        cout << "Fila vazia! Nenhum elemento para executar!" << endl;
        cout << "-------------------------------------------" << endl;
    }
    else
    {
        while (celAux->proximo != NULL)
        {
            cout << "\nTítulo: " << celAux->proximo->music.titulo << endl;
            cout << "Artista: " << celAux->proximo->music.artista << endl;
            cout << "Duração: " << celAux->proximo->music.duracao << endl;

            Sleep(5000);

            empilhar(p,celAux->proximo->music);
            desenfileirar(f);

            celAux = celAux->proximo;

            cout << "-------------------------------------------" << endl;
        }
    }
}

void duracao(TPilhaP p)
{
    TMusica maior,menor;
    TCelula *celAux=p.topo->proximo;
    maior.duracao=0;
    menor.duracao=999;

    while(celAux->proximo != NULL)
    {
        if(celAux->music.duracao>maior.duracao)
        {
            maior=celAux->music;
        }
        if(celAux->music.duracao<menor.duracao)
        {
            menor=celAux->music;
        }
        celAux = celAux->proximo;
    }

    if(celAux->music.duracao>maior.duracao)
    {
        maior=celAux->music;
    }
    if(celAux->music.duracao<menor.duracao)
    {
        menor=celAux->music;
    }

    cout << "Musica com maior duração: " << endl;
    cout << "Título: " << maior.titulo << endl;
    cout << "Artista: " << maior.artista << endl;
    cout << "Duração: " << maior.duracao << endl;

    cout << "\nMusica com menor duração: " << endl;
    cout << "Título: " << menor.titulo << endl;
    cout << "Artista: " << menor.artista << endl;
    cout << "Duração: " << menor.duracao << endl;


}


int main()
{

    setlocale(LC_ALL,"Portuguese");

    TListaP listaMusicas;
    TFilaP filaExecutar;
    TPilhaP pilhaTocadas;
    TMusica m;
    int res;

    criarLPVazia(listaMusicas);
    criarFilaPVazia(filaExecutar);
    criarPilhaPVazia(pilhaTocadas);

    while(res != 2)
    {

        cout << "Qual o nome do artista? ";
        cin >> m.artista;

        cout << "Qual o título da música? ";
        cin >> m.titulo;

        cout << "Qual a duração? ";
        cin >> m.duracao;

        inserirLP(listaMusicas,m);

        cout << "Deseja adicionar outra música?\n1 - Sim\n2 - Não\n";
        cin >> res;
    }
    mostrar(listaMusicas);

    string nome;

    cout << "Qual nome da música que está buscando? ";
    cin >> nome;

    buscar(listaMusicas,nome);


    cout << "\nQuer mostrar todas as músicas de qual artista? ";
    cin >> nome;

    mostrarArtista(listaMusicas,nome);

    cout << "Deseja tocar as músicas em ordem ou aleatóriamente?\n1 - Ordem\n2 - Aleatório\n";
    cin >> res;

    system("cls");

    switch(res)
    {
    case 1:
        executarOrdem(listaMusicas,filaExecutar);
        cout << "Executando músicas em ordem:" << endl;
        reproduzir(filaExecutar,pilhaTocadas);
        mostrarFila(filaExecutar);
        mostrarPilha(pilhaTocadas);

        break;
    case 2:
        executarAleatorio(listaMusicas,filaExecutar);
        cout << "Executando músicas aleatórias:" << endl;
        reproduzir(filaExecutar,pilhaTocadas);
        mostrarFila(filaExecutar);
        mostrarPilha(pilhaTocadas);

        break;
    }

    duracao(pilhaTocadas);

    return 0;
}
