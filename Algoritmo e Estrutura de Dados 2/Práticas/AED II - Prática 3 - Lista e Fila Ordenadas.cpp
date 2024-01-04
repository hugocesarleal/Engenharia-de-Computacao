#include <iostream>
#include <clocale>

using namespace std;

const int maxTam = 5;

struct TAluno
{
    int ra;
    string nome;
    double nota;
};

TAluno vetOrdemNome[maxTam],vetOrdemNota[maxTam];


struct TLista_A
{
    TAluno vetAluno[maxTam];
    int primeiro;
    int ultimo;
};

struct TFilaACircular
{
    TAluno vetAluno[maxTam];
    int frente;
    int tras;
    int contItens;
};

void ordenarNome(TAluno x)
{
    for(int iA=0; iA<maxTam; iA++)
    {
        if(x.nome>vetOrdemNome[iA].nome)
        {
            for(int iB=4; iB>iA; iB--)
            {
                vetOrdemNome[iB]=vetOrdemNome[iB-1];
            }

            vetOrdemNome[iA]=x;

            break;
        }
    }
}

void ordenarNota(TAluno x)
{
    for(int iA=0; iA<maxTam; iA++)
    {
        if(x.nota>vetOrdemNota[iA].nota)
        {
            for(int iB=4; iB>iA; iB-- & iA++)
            {
                vetOrdemNota[iB]=vetOrdemNota[iB-1];
            }

            vetOrdemNota[iA]=x;

            break;
        }
    }
}

void criarLista_A(TLista_A &lA)
{
    lA.primeiro = 0;
    lA.ultimo = lA.primeiro;
    cout << "Lista criada e pronta para uso!" << endl;
}

bool estaVaziaL(TLista_A lA)
{
    return lA.primeiro == lA.ultimo;
}

bool estaCheiaL(TLista_A lA)
{
    return lA.ultimo >= maxTam;
}

void inserirItem(TLista_A &lA)
{
    if (estaCheiaL(lA))
    {
        cout << "Lista cheia. Não posso inserir!" << endl;
    }
    else
    {
        for(int i=0; i<maxTam; i++)
        {

            cout << "Qual o RA do " << i+1 << "º aluno? ";
            cin >> lA.vetAluno[i].ra;

            cout << "Qual o nome do " << i+1 << "º aluno? ";
            cin >> lA.vetAluno[i].nome;

            cout << "Qual a nota do " << i+1 << "º aluno? ";
            cin >> lA.vetAluno[i].nota;

            ordenarNome(lA.vetAluno[i]);
            ordenarNota(lA.vetAluno[i]);

            lA.ultimo++;
            system("cls");
        }
    }
}

void mostrarLista(TLista_A lA)
{
    cout << "=== Mostrando itens da lista ===" << endl;

    for (int i=lA.primeiro; i<lA.ultimo; i++)
    {
        cout << "RA: " << lA.vetAluno[i].ra << endl;
        cout << "Nome: " << lA.vetAluno[i].nome << endl;
        cout << "Nota:  " << lA.vetAluno[i].nota << endl;
        cout << "--------------------------------" << endl;
    }
}

void ordenarLista(TLista_A &lA)
{

    int a=4;

    for(int i=0; i<maxTam; i++)
    {
        lA.vetAluno[i].nome=vetOrdemNome[a].nome;
        lA.vetAluno[i].ra=vetOrdemNome[a].ra;
        lA.vetAluno[i].nota=vetOrdemNome[a].nota;
        a=a-1;
    }
}

void criarFilaVazia(TFilaACircular &f)
{
    f.frente = 0;
    f.tras = f.frente;
    f.contItens = 0;
}

bool estaVaziaF(TFilaACircular f)
{

    return f.contItens == 0;
}

bool estaCheiaF(TFilaACircular f)
{

    return f.contItens == maxTam;
}

void enfileirar(TFilaACircular &f, TAluno x)
{

    if (estaCheiaF(f))
    {
        cout << "Não posso enfileirar. Fila Cheia!" << endl;
    }
    else
    {

        f.vetAluno[f.tras] = x;

        f.tras = (f.tras+1) % maxTam;
        f.contItens++;

    }
}

void mostrarFila(TFilaACircular f)
{
    int aux;

    cout << "=== MOSTRANDO A FILA ===" << endl;
    if (estaVaziaF(f))
    {
        cout << "Nada para mostrar. Fila Vazia!" << endl;
    }
    else
    {
        aux=f.frente;
        for(int i=0; i<f.contItens; i++)
        {
            cout << "RA: " << f.vetAluno[aux].ra << endl;
            cout << "Nome: " << f.vetAluno[aux].nome << endl;
            cout << "Nota:  " << f.vetAluno[aux].nota << endl;
            cout << "------------------------" << endl;
            aux=(aux+1)%maxTam;

        }
    }
}


int main()
{

    setlocale(LC_ALL,"Portuguese");

    TLista_A lista;
    TFilaACircular fila;

    criarLista_A(lista);

    inserirItem(lista);

    ordenarLista(lista);

    cout << "== ALUNOS EM ORDEM ALFABÉTICA ==" << endl;

    mostrarLista(lista);

    criarFilaVazia(fila);

    for(int i=0; i<maxTam; i++)
    {
        enfileirar(fila,vetOrdemNota[i]);
    }

    cout << "=== ALUNOS EM ORDEM DE NOTA ===" << endl;

    mostrarFila(fila);

    return 0;
}
