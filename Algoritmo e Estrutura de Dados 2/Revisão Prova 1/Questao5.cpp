#include <iostream>
#include <clocale>
using namespace std;

// SESSÃO DE DECLARAÇÕES
const int maxTam = 100;

struct TConta
{
    int numero,saldo;
    string tipo;
};

struct TCliente
{
    int cpf, idade;
    string nome;
    TConta conta;
};

struct TLista_A
{
    TCliente vetItens[maxTam];
    int primeiro;
    int ultimo;
};

void criarLista_A(TLista_A &lA)
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
    return lA.ultimo >= maxTam;
}

void inserirItem(TLista_A &lA, TCliente x)
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

    }
}

void pRetirarPos(TLista_A &lA, int p)
{
    int aux;

    if((estaVazia(lA)) || (p>=lA.ultimo) || (p<lA.primeiro))
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

void pCadastro(TLista_A &lA){
    int res=1;
    TCliente cliente;
    while(res !=2 && lA.ultimo<100){
        cout << "Cadastro do " << lA.ultimo+1 << "º cliente:" << endl;
        cout << "Informe o nome completo: " << endl;
        cin >> cliente.nome;
        cout << "Informe o CPF: " << endl;
        cin >> cliente.cpf;
        cout << "Informe a idade: " << endl;
        cin >> cliente.idade;
        cout << "Informe o número da conta: " << endl;
        cin >> cliente.conta.numero;
        cout << "Informe o saldo da conta: " << endl;
        cin >> cliente.conta.saldo;
        cout << "Informe o tipo da conta:\n1 - Poupança\n2 - Corrente\n" << endl;
        cin >> res;

        if(res=1){
            cliente.conta.tipo="Poupança";
        }
        else{
            cliente.conta.tipo="Corrente";
        }

        inserirItem(lA,cliente);

        cout << "Cliente cadastrado!" << endl;
        cout << "Deseja cadastrar outro cliente?\n1 - Sim\n2 - Não" << endl;
        cin >> res;
    }
}

void mostrarCadastrados(TLista_A lA){
    for(int i=0;i<lA.ultimo;i++){
        cout << "\nCadastro do " << lA.ultimo+1 << "º cliente:" << endl;
        cout << "Nome completo: " << lA.vetItens[i].nome << endl;
        cout << "CPF: " << lA.vetItens[i].cpf << endl;
        cout << "Idade: " << lA.vetItens[i].idade << endl;
        cout << "Número da conta: " << lA.vetItens[i].conta.numero << endl;
        cout << "Saldo da conta: " << lA.vetItens[i].conta.saldo << endl;
        cout << "Tipo da conta: " << lA.vetItens[i].conta.tipo;
    }
}

void saldoBanco(TLista_A lA){
    int cont=0;
    for(int i=0;i<lA.ultimo;i++){
        cont=cont+lA.vetItens[i].conta.saldo;
    }

    cout << "\n\nSaldo total do banco: " << cont << endl;
}

int main()
{

    setlocale(LC_ALL,"Portuguese");

    TLista_A listaClientes;

    criarLista_A(listaClientes);

    pCadastro(listaClientes);

    mostrarCadastrados(listaClientes);

    saldoBanco(listaClientes);

    //Não consegui entender a parte do TAD Lista em diante

    return 0;
}
