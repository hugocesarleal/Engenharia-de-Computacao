/*
    Algoritmos e Estruturas de Dados
    TAD: Lista por PONTEIROS Simplesmente Encadeada
    Versão: v2 - completa
    Autor: Gabriel da Silva
*/

#include <iostream>
#include <clocale>
using namespace std;

// ESTRUTURAS

struct TItem
{
    int chave;
    string valor;
    //... demais campos necessários
};

struct TCelula
{
    TItem item;
    TCelula *proximo;
};

struct TListaP
{
    TCelula *primeiro;
    TCelula *ultimo;
    int cont;
};


// OPERAÇÕES BÁSICAS

void criarLPVazia(TListaP &lp)
{
    lp.primeiro = new TCelula;      // criei uma NOVA célula e chamei-a de PRIMEIRO
    lp.ultimo = lp.primeiro;        // atribuí o mesmo endereço de primeiro para ULTIMO
    lp.ultimo->proximo = lp.primeiro;
    lp.cont=0;
}

void inserirLP(TListaP &lp, TItem x)
{

    if(lp.cont==0)
    {
        lp.ultimo->item=x;
        lp.cont++;
        cout << "IF";
    }
    else
    {
        cout << "ELSE";
        lp.ultimo->proximo = new TCelula;
        lp.ultimo = lp.ultimo->proximo;
        lp.ultimo->item = x;
        lp.ultimo->proximo = lp.primeiro;
    }
}

bool estaVaziaLP(TListaP lp)
{
    return lp.primeiro == lp.ultimo;
}

void mostrar(TListaP lp)
{

    //celAux = lp.primeiro; // começa como ponto de acesso, logo, não tem item válido

    TCelula *celAux;
    celAux = lp.primeiro; // começa como a primeira célula válida, ie, que tem item válido

    cout << "=== MOSTRANDO A LISTA === "<< endl;

    if (estaVaziaLP(lp))
    {
        cout << "Nenhum item a ser mostrado. Lista vazia!" << endl;
        cout << "-------------------------------------------" << endl;

    }
    else
    {
        do
        {
            cout << "End.Mem.Celula: " << celAux << endl;
            cout << "   Chave:   " << celAux->item.chave << endl;
            cout << "   Valor:   " << celAux->item.valor << endl;
            cout << "   Proximo: " << celAux->proximo << endl;
            celAux = celAux->proximo;
            cout << "End.Mem. lp.ultimo: " << lp.ultimo << endl;
            cout << "-------------------------------------------" << endl;
        }
        while (celAux != lp.ultimo->proximo);
    }
}


// QUALQUER OPERAÇÃO SOBRE UMA CÉLULA (NEW OU DELETE) DEVE SER FEITA A PARTIR
// DA CÉLULA ANTERIOR. POR ISSO, A IMPORTÂNCIA DE UMA FUNÇÃO DE RETORNA O ENDEREÇO
// DESTA CÉLULA ANTERIOR AO CRITÉRIO ESTABELECIDO NA BUSCA PELA CHAVE OU OUTRO CAMPO.

// Esta função será usada pelo procedimento retirar!
TCelula *pegaAnterior(TListaP lp, int chaveBusca)
{

    TCelula *celAux;
    bool achou = false;

    celAux = lp.primeiro;   // não começamos pela célula válida (COM CONTEÚDO)
    // mas sim pela cabeça (PONTO DE ACESSO)

    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
    while (celAux->proximo != lp.ultimo)
    {
        if (celAux->proximo->item.chave == chaveBusca)
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
    TCelula *anterior = pegaAnterior(lp,chaveBusca); //anterior

    if (anterior == NULL)
    {
        cout << "A chave não foi encontrada. Nenhuma célula a retirar." << endl;
    }
    else
    {
        TCelula *celAlvo; //alvo

        celAlvo = anterior->proximo;
        anterior->proximo = celAlvo->proximo;
        // só para mostrar os dados da célula a ser excluída!!!

        cout << "End.Mem.Celula Anterior: " << anterior << endl;
        cout << "   Chave:   " << anterior->item.chave << endl;
        cout << "   Valor:   " << anterior->item.valor << endl;
        cout << "   Proximo: " << anterior->proximo << endl;

        cout << "End.Mem.Celula Alvo: " << celAlvo << endl;
        cout << "   Chave:   " << celAlvo->item.chave << endl;
        cout << "   Valor:   " << celAlvo->item.valor << endl;
        cout << "   Proximo: " << celAlvo->proximo << endl;
        // desalocando a memória reservada pela célula alvo
        delete(celAlvo);
    }
}

// PROGRAMA PRINCIPAL

int main()
{

    setlocale(LC_ALL,"Portuguese");

    TListaP listaP; // instanciação
    TItem itemTemp; // criando uma variável do tipo item para receber os dados do item, antes de inserir na lista
    // estes valores podem ser atribuídos ou coletados pela digitação. Farei os 2 exemplos

    //preparando a lista para uso!
    criarLPVazia(listaP);

    //os dois devem ser iguais
    cout << "End.Mem. Celula Primeiro: " << listaP.primeiro << endl;
    cout << "End.Mem. Celula Ultimo:   " << listaP.ultimo << endl;

    //os dois devem ser iguais e apontarem para NULL
    cout << "Proximo do Primeiro:      " << listaP.primeiro->proximo << endl;
    cout << "Proximo do Ultimo:        " << listaP.ultimo->proximo << endl;

    if (estaVaziaLP(listaP))
    {
        cout << "Lista está vazia!" << endl;
    }
    else
    {
        cout << "Lista possui algum item!" << endl;
    }

    mostrar(listaP);

    // inserindo um item manualmente por atribuição
    itemTemp.chave = 1;
    itemTemp.valor = "Gabriel";
    inserirLP(listaP,itemTemp);


    // inserindo um item manualmente por atribuição
    itemTemp.chave = 2;
    itemTemp.valor = "Maria";
    inserirLP(listaP,itemTemp);


    itemTemp.chave = 3;
    itemTemp.valor = "Pedro";
    inserirLP(listaP,itemTemp);
    mostrar(listaP);


    // alimentando com um laço de repetição
    // condição de parada: responder N

    char resp = 'S';

    while (resp != 'N')
    {
        cout << "Entrando dados pelo teclado: " << endl;
        cout << "   Digite a chave: ";
        cin >> itemTemp.chave;
        cout << "   Digite o valor: ";
        cin >> itemTemp.valor;
        // chamando o procedimento inserir
        inserirLP(listaP,itemTemp);
        cout << "   Deseja cadastrar outro item? (S/N): ";
        cin >> resp;
    }

    mostrar(listaP);

    // retirando um item pela sua chave

    int chaveTemp;
    TCelula *anteriorTemp;

    // DEMONSTRANDO O USO DA FUNÇÃO *PEGAANTERIOR
    cout << "=== RETIRANDO UM ITEM NA LISTA === "<< endl;

    cout << "   Digite a chave do item a retirar: ";
    cin >> chaveTemp;
    anteriorTemp = pegaAnterior(listaP,chaveTemp);
    cout << "End.Mem. Celula Anterior: " << anteriorTemp << endl;
    cout << "   Chave:   " << anteriorTemp->item.chave << endl;
    cout << "   Valor:   " << anteriorTemp->item.valor << endl;
    cout << "   Proximo: " << anteriorTemp->proximo << endl;

    // AGORA, VAMOS, DE FATO, EXCLUIR A CELULA
    // USANDO O PROCEDIMENTO RETIRARPORCHAVE
    retirarPorChave(listaP,chaveTemp);

    mostrar(listaP);

    //PARA CASA: construa e demonstre uma função que procura pelo campo VALOR
    //          - Provocação: será que precisamos criar outro retirar????

    return 0;
}
