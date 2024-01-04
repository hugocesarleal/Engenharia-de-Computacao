#include <iostream>
#include <clocale>
using namespace std;

// SESSÃO DE DECLARAÇÕES
const int maxTam = 5; // CRIEI UMA CONSTANTE PARA DEFINIR A QUANT DE ITENS E PODER REALIZAR A MUDANÇA NO CÓDIGO DE
// MODO MAIS EFICIENTE, BASTANTO ALTERAR AQUI E PROPAGAR EM TODOS LUGARES ONDE A QUANT DE ITENS É USADA

// ESTRUTURAS DE ARMAZENAMENTO E CONTROLE DOS DADOS
struct TItem // Tipo de cada elemento do meu vetor. Varia de acordo com sua necessidade de contexto
{
    int chave;
    string nome;
};

struct TLista_A  // a lista por arranjo, composta pelo vetor suporte de itens e as variáveis de controle
{
    //TItem vetItens[5];
    TItem vetItens[maxTam]; //usando a CONSTANTE criada
    int primeiro;
    int ultimo;
};


// OPERAÇÕES BÁSICAS

void criarLista_A(TLista_A &lA) // passo a lista por referência pois MODIFICAREI valores dela
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
        cout << "Lista cheia. Não posso inserir!" << endl;
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
        cout << "Posição: " << i << endl;
        cout << "  Chave: " << lA.vetItens[i].chave << endl;
        cout << "  Nome:  " << lA.vetItens[i].nome << endl;
    }
}

/*
    PARA CASA:

    crie uma função que:
    1. permita fazer a busca na lista por valor de um dos campos do item, informado pelo usuário
    2. retorne a posição do item, se o tiver encontrado, ou -1, como uma "flag" que significa que não encontrou.

    demonstre a utilização desta função combinada com o RETIRAR, tanto o procedimento, quanto a função.
*/


void pRetirarPos(TLista_A &lA, int p)  // IMPLEMENTADO COMO PROCEDIMENTO: SEM RETORNO E SEM CÓPIA EM VARIÁVEL POR REFERÊNCIA
{
    /* PARA CASA! RESOLVIDO!
        Com base na explicação em aula e no livro do Ziviani,
        implemente este procedimento e demonstre sua utilização na main.
    */

    int aux; // USADA PARA CONTROLAR AS REPETIÇÕES DO FOR (QUE SÃO OS MOVIMENTOS DE REALOCAÇÃO!)

    if((estaVazia(lA)) || (p>=lA.ultimo) || (p<lA.primeiro))  // VERIFICO, ALÉM DE ESTAR VAZIA, SE A POSIÇÃO PASSADA ESTÁ NO INTERVALO VÁLIDO DE ÍNDICES DO VETITENS
    {
        cout << "Não posso retirar! Lista vazia ou posição fora do limite" << endl;
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

TItem fRetirarPos(TLista_A &lA, int p)  // IMPLEMENTANDO COMO FUNÇÃO QUE RETORNA O ITEM RETIRADO
{
    // ADAPTADO NA NOSSA AULA!
    TItem itemAux; // vou usar para retornar o item que for retirado
    int aux; // USADA PARA CONTROLAR AS REPETIÇÕES DO FOR (QUE SÃO OS MOVIMENTOS DE REALOCAÇÃO!)

    if((estaVazia(lA)) || (p>=lA.ultimo) || (p<lA.primeiro))  // VERIFICO, ALÉM DE ESTAR VAZIA, SE A POSIÇÃO PASSADA ESTÁ NO INTERVALO VÁLIDO DE ÍNDICES DO VETITENS
    {
        cout << "Não posso retirar! Lista vazia ou posição fora do limite" << endl;
    }
    else
    {
        itemAux = lA.vetItens[p]; // faz uma cópia do item que está na posição P e que será retirado
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

    setlocale(LC_ALL,"Portuguese");//para acentuação e caracteres especiais

    TLista_A minhaLista; // instância de uma lista por arranjo
    TItem item;

    // apesar de funcionar o comando a seguir, NUNCA deve ser feito algo parecido!!!
    // apenas as operações dos TAD podem e DEVEM manipular seus dados e controles
    //minhaLista.primeiro = 1;
    cout << "Primeiro: " << minhaLista.primeiro << endl;
    cout << "Ultimo:   " << minhaLista.ultimo << endl;

    // COMO FAÇO ENTÃO??? Eu peço a quem sabe e pode fazer: operações do TAD!
    // isto é, faço uma chamada ao procedimento ou função desejados.

    // USANDO A OPERAÇÃO CRIAR
    criarLista_A(minhaLista);
    cout << "Primeiro: " << minhaLista.primeiro << endl;
    cout << "Ultimo:   " << minhaLista.ultimo << endl;

    // TESTANDO SE ESTÁ VAZIA
    if (estaVazia(minhaLista))  // a chamada da função é feita dentro da condicional
    {
        cout << "Lista vazia!" << endl;
    }
    else
    {
        cout << "Lista possui itens!" << endl;
    }
    // USANDO A OPERAÇÃO INSERIR
    // Preparando um item!!! ATRIBUIÇÃO
    item.chave = 21;
    item.nome = "Doido";

    // chamando a operação inserir
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

    cout << "Você sabe a posição do item que deseja retirar?\n1 - Sim\n2 - Não\n";
    cin >> valor;

    switch(valor)
    {
    case 1:

        cout << "Qual a posição? ";
        cin >> pos;

        pRetirarPos(minhaLista,pos);

        break;

    case 2:

        cout << "Qual o nome que deseja? ";
        cin>> busca;

        pos=fBusca(minhaLista,busca);

        if(pos==-1)
        {
            cout << "Nome não encontrado!\n";
        }
        else
        {
            cout << "O nome buscado está na " << pos+1 << "ª posição.\n";

            TItem ret=fRetirarPos(minhaLista,pos);

            cout << "O item com nome " << ret.nome << " e chave " << ret.chave << " foi excluído\n";
        }
        break;

    }

    mostrarLista(minhaLista);

    return 0;
}
