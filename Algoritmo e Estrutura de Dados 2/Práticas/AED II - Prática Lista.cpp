#include <iostream>
#include <clocale>
using namespace std;

// SESS�O DE DECLARA��ES

// ESTRUTURAS DE ARMAZENAMENTO E CONTROLE DOS DADOS
struct TItem{// Tipo de cada elemento do meu vetor. Varia de acordo com sua necessidade de contexto
    int chave;
    string nome;
};

struct TLista_A{ // a lista por arranjo, composta pelo vetor suporte de itens e as vari�veis de controle
    TItem vetItens[5];
    int primeiro;
    int ultimo;
};




// OPERA��ES B�SICAS

void criarLista_A(TLista_A &lA){// passo a lista por refer�ncia pois MODIFICAREI valores dela
    lA.primeiro = 0;
    lA.ultimo = lA.primeiro;
    cout << "Lista criada e pronta para uso!" << endl;
}

bool estaVazia(TLista_A lA){
    return lA.primeiro == lA.ultimo;
}

bool estaCheia(TLista_A lA){
    return lA.ultimo >= 5;
}
                //onde?         o que?
void inserirItem(TLista_A &lA, TItem x){
    if (estaCheia(lA)){
        cout << "Lista cheia. N�o posso inserir!" << endl;
    }
    else{
        lA.vetItens[lA.ultimo] = x;
        lA.ultimo++;
        cout << "Item inserido com sucesso!" << endl;
    }
}

void mostrarLista(TLista_A lA){
    cout << "=== Mostrando itens da lista ===" << endl;
    for (int i=lA.primeiro;i<lA.ultimo;i++){
        cout << "Posi��o: " << i << endl;
        cout << "  Chave: " << lA.vetItens[i].chave << endl;
        cout << "  Nome:  " << lA.vetItens[i].nome << endl;
    }
}

void retirar(TLista_A &lA,int p){

    TItem excluido;

    if(estaVazia(lA)){
        cout << "A lista est� vazia!";
    }
    else{
        lA.ultimo--;
        excluido=lA.vetItens[p];

        for(int i=p;i<lA.ultimo;i++){
            lA.vetItens[i]=lA.vetItens[i+1];
        }

        cout << "O item com nome " << excluido.nome << " e chave " << excluido.chave << " foi exclu�do";
    }
}

int fBusca(TLista_A lA,string b){

    for(int i=0;i<5;i++){

            if(lA.vetItens[i].nome==b){
                return i;
            }
        }
}

int main(){

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
    if (estaVazia(minhaLista)){ // a chamada da fun��o � feita dentro da condicional
        cout << "Lista vazia!" << endl;
    }
    else{
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

    switch(valor){
    case 1:

        cout << "Qual a posi��o? ";
        cin >> pos;

        retirar(minhaLista,pos);

        break;

    case 2:

        cout << "Qual o nome que deseja? ";
        cin>> busca;

        pos=fBusca(minhaLista,busca);

        cout << "O nome buscado est� na " << pos+1 << "� posi��o.";

        retirar(minhaLista,pos);

        break;
    default:
        cout << "Invalido";
    }

    mostrarLista(minhaLista);

    return 0;
}
