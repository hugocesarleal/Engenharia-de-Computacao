#include <iostream>
#include <clocale>
using namespace std;

// SESS�O DE DECLARA��ES
const int maxTam = 5; // CRIEI UMA CONSTANTE PARA DEFINIR A QUANT DE ITENS E PODER REALIZAR A MUDAN�A NO C�DIGO DE
// MODO MAIS EFICIENTE, BASTANTO ALTERAR AQUI E PROPAGAR EM TODOS LUGARES ONDE A QUANT DE ITENS � USADA

// ESTRUTURAS DE ARMAZENAMENTO E CONTROLE DOS DADOS
struct TItem // Tipo de cada elemento do meu vetor. Varia de acordo com sua necessidade de contexto
{
    int chave;
    string nome;
};

struct TLista_A  // a lista por arranjo, composta pelo vetor suporte de itens e as vari�veis de controle
{
    //TItem vetItens[5];
    TItem vetItens[maxTam]; //usando a CONSTANTE criada
    int primeiro;
    int ultimo;
};


// OPERA��ES B�SICAS

void criarLista_A(TLista_A &lA) // passo a lista por refer�ncia pois MODIFICAREI valores dela
{
    lA.primeiro = 0;
    lA.ultimo = lA.primeiro;
    cout << "Lista criada e pronta para uso!" << endl;
}

bool estaVazia(TLista_A lA)
{
    return lA.primeiro == lA.ultimo;
}

bool estaCheia(TLista_A lA)
{
    //return lA.ultimo >= 5;
    return lA.ultimo >= maxTam; //usando a CONSTANTE criada
}
//onde?         o que?
void inserirItem(TLista_A &lA, TItem x)
{
    if (estaCheia(lA))
    {
        cout << "Lista cheia. N�o posso inserir!" << endl;
    }
    else
    {
        lA.vetItens[lA.ultimo] = x;
        lA.ultimo++;
        cout << "Item inserido com sucesso!" << endl;
    }
}

void mostrarLista(TLista_A lA)
{
    cout << "=== Mostrando itens da lista ===" << endl;
    for (int i=lA.primeiro; i<lA.ultimo; i++)
    {
        cout << "Posi��o: " << i << endl;
        cout << "  Chave: " << lA.vetItens[i].chave << endl;
        cout << "  Nome:  " << lA.vetItens[i].nome << endl;
    }
}

/*
    PARA CASA:

    crie uma fun��o que:
    1. permita fazer a busca na lista por valor de um dos campos do item, informado pelo usu�rio
    2. retorne a posi��o do item, se o tiver encontrado, ou -1, como uma "flag" que significa que n�o encontrou.

    demonstre a utiliza��o desta fun��o combinada com o RETIRAR, tanto o procedimento, quanto a fun��o.
*/


void pRetirarPos(TLista_A &lA, int p)  // IMPLEMENTADO COMO PROCEDIMENTO: SEM RETORNO E SEM C�PIA EM VARI�VEL POR REFER�NCIA
{
    /* PARA CASA! RESOLVIDO!
        Com base na explica��o em aula e no livro do Ziviani,
        implemente este procedimento e demonstre sua utiliza��o na main.
    */

    int aux; // USADA PARA CONTROLAR AS REPETI��ES DO FOR (QUE S�O OS MOVIMENTOS DE REALOCA��O!)

    if((estaVazia(lA)) || (p>=lA.ultimo) || (p<lA.primeiro))  // VERIFICO, AL�M DE ESTAR VAZIA, SE A POSI��O PASSADA EST� NO INTERVALO V�LIDO DE �NDICES DO VETITENS
    {
        cout << "N�o posso retirar! Lista vazia ou posi��o fora do limite" << endl;
    }
    else
    {
        lA.ultimo--;
        for(aux=p; aux<lA.ultimo; aux++)
        {
            lA.vetItens[aux] = lA.vetItens[aux+1];
        }
    }
}

TItem fRetirarPos(TLista_A &lA, int p)  // IMPLEMENTANDO COMO FUN��O QUE RETORNA O ITEM RETIRADO
{
    // ADAPTADO NA NOSSA AULA!
    TItem itemAux; // vou usar para retornar o item que for retirado
    int aux; // USADA PARA CONTROLAR AS REPETI��ES DO FOR (QUE S�O OS MOVIMENTOS DE REALOCA��O!)

    if((estaVazia(lA)) || (p>=lA.ultimo) || (p<lA.primeiro))  // VERIFICO, AL�M DE ESTAR VAZIA, SE A POSI��O PASSADA EST� NO INTERVALO V�LIDO DE �NDICES DO VETITENS
    {
        cout << "N�o posso retirar! Lista vazia ou posi��o fora do limite" << endl;
    }
    else
    {
        itemAux = lA.vetItens[p]; // faz uma c�pia do item que est� na posi��o P e que ser� retirado
        lA.ultimo--;
        for(aux=p; aux<lA.ultimo; aux++)
        {
            lA.vetItens[aux] = lA.vetItens[aux+1];
        }
        return itemAux;
    }
}

int fBusca(TLista_A lA,string b)
{

    for(int i=0; i<5; i++)
    {
        if(lA.vetItens[i].nome==b)
        {
            return i;
        }
    }

    return -1;
}


int main()
{

    setlocale(LC_ALL,"Portuguese");//para acentua��o e caracteres especiais

    TLista_A minhaLista; // inst�ncia de uma lista por arranjo
    TItem item;

    // apesar de funcionar o comando a seguir, NUNCA deve ser feito algo parecido!!!
    // apenas as opera��es dos TAD podem e DEVEM manipular seus dados e controles
    //minhaLista.primeiro = 1;
    cout << "Primeiro: " << minhaLista.primeiro << endl;
    cout << "Ultimo:   " << minhaLista.ultimo << endl;

    // COMO FA�O ENT�O??? Eu pe�o a quem sabe e pode fazer: opera��es do TAD!
    // isto �, fa�o uma chamada ao procedimento ou fun��o desejados.

    // USANDO A OPERA��O CRIAR
    criarLista_A(minhaLista);
    cout << "Primeiro: " << minhaLista.primeiro << endl;
    cout << "Ultimo:   " << minhaLista.ultimo << endl;

    // TESTANDO SE EST� VAZIA
    if (estaVazia(minhaLista))  // a chamada da fun��o � feita dentro da condicional
    {
        cout << "Lista vazia!" << endl;
    }
    else
    {
        cout << "Lista possui itens!" << endl;
    }
    // USANDO A OPERA��O INSERIR
    // Preparando um item!!! ATRIBUI��O
    item.chave = 21;
    item.nome = "Doido";

    // chamando a opera��o inserir
    inserirItem(minhaLista,item);
    // tirando a prova se deu certo!!!
    cout << "Primeiro: " << minhaLista.primeiro << endl;
    cout << "Ultimo:   " << minhaLista.ultimo << endl;

    // Preparando OUTRO item!!! LEITURA
    cout << "Digite uma chave: ";
    cin >> item.chave;
    cout << "Digite um nome: ";
    cin >> item.nome;

    inserirItem(minhaLista, item);
    cout << "Primeiro: " << minhaLista.primeiro << endl;
    cout << "Ultimo:   " << minhaLista.ultimo << endl;

    mostrarLista(minhaLista);

    item.chave = 1;
    item.nome = "Lola";
    inserirItem(minhaLista,item);

    item.chave = 17;
    item.nome = "Rex";
    inserirItem(minhaLista,item);

    item.chave = 5;
    item.nome = "Tux";
    inserirItem(minhaLista,item);

    cout << "Primeiro: " << minhaLista.primeiro << endl;
    cout << "Ultimo:   " << minhaLista.ultimo << endl;

    mostrarLista(minhaLista);

    item.chave = 171;
    item.nome = "Rolando";
    inserirItem(minhaLista,item);

    cout << "Primeiro: " << minhaLista.primeiro << endl;
    cout << "Ultimo:   " << minhaLista.ultimo << endl;

    mostrarLista(minhaLista);

    int valor,pos;
    string busca;

    cout << "Voc� sabe a posi��o do item que deseja retirar?\n1 - Sim\n2 - N�o\n";
    cin >> valor;

    switch(valor)
    {
    case 1:

        cout << "Qual a posi��o? ";
        cin >> pos;

        pRetirarPos(minhaLista,pos);

        break;

    case 2:

        cout << "Qual o nome que deseja? ";
        cin>> busca;

        pos=fBusca(minhaLista,busca);

        if(pos==-1)
        {
            cout << "Nome n�o encontrado!\n";
        }
        else
        {
            cout << "O nome buscado est� na " << pos+1 << "� posi��o.\n";

            TItem ret=fRetirarPos(minhaLista,pos);

            cout << "O item com nome " << ret.nome << " e chave " << ret.chave << " foi exclu�do\n";
        }
        break;

    }

    mostrarLista(minhaLista);

    return 0;
}
