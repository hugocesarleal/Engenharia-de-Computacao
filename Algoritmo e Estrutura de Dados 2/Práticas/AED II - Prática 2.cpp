#include <iostream>
#include <clocale>

using namespace std;

struct Tconta
{
    int numero;
    string tipo;
    double saldo=0;
};

struct Tcliente
{
    int matricula;
    string nome;
    int idade;
    Tconta conta;
};

Tcliente cliente[10];

void pLinhaD()
{

    cout << "=====================================================\n";
}

int fVelho()
{

    int valor,pos,controleVelho=-1;

    for(int i=0; i<10; i++)
    {
        if(cliente[i].idade>controleVelho)
        {
            controleVelho=cliente[i].idade;
            pos=i;
        }
    }

    cout << "Dados da conta do cliente mais velho: ";
    cout << "\n\nNome: " << cliente[pos].nome << "\nMatr�cula: " << cliente[pos].matricula << "\nIdade: " << cliente[pos].idade << endl;
    cout << "\nConta: " << cliente[pos].conta.numero << "\nTipo: " << cliente[pos].conta.tipo << "\nSaldo: R$" << cliente[pos].conta.saldo << endl;

    cout << "\n\nDeseja voltar para o menu?\n1 - Sim\n2 - N�o\n";
    cin >> valor;

    system("cls");

    return valor;
}

int fMostrar()
{
    int valor;

    system("cls");

    for(int i=0; i<10; i++)
    {
        if(cliente[i].idade!=0)
        {
            pLinhaD();
            cout << "\n*Dados do Cliente*\n\nNome: " << cliente[i].nome << "\nMatr�cula: " << cliente[i].matricula << endl;
            cout << "\n*Dados da Conta*\n\nConta: " << cliente[i].conta.numero << "\nTipo: " << cliente[i].conta.tipo << "\nSaldo: R$" << cliente[i].conta.saldo << endl;
        }
    }

    pLinhaD();

    cout << "\n\nDeseja voltar para o menu?\n1 - Sim\n2 - N�o\n";
    cin >> valor;

    system("cls");

    return valor;
}

int fSaldo()
{

    int mat,valor;

    cout << "Informe o n�mero de matr�cula do qual deseja saber o saldo: ";
    cin >> mat;

    for(int i=0; i<10; i++)
    {
        if(mat==cliente[i].matricula)
        {
            system("cls");

            cout << "Dados da conta:\n\nNome: " << cliente[i].nome << "\nMatr�cula: " << cliente[i].matricula << "\nTipo: " << cliente[i].conta.tipo;
            cout << "\n\nSaldo: R$" << cliente[i].conta.saldo;

            cout << "\n\nDeseja voltar para o menu?\n1 - Sim\n2 - N�o\n";
            cin >> valor;

            system("cls");

            return valor;
        }
    }
}

int fDeposito()
{

    int valor,conta;
    double quant;

    cout << "Informe o n�mero da conta que ser� depositado: ";
    cin >> conta;

    system("cls");

    for(int i=0; i<10; i++)
    {
        if(conta==cliente[i].conta.numero)
        {

            cout << "Dados da conta:\n\nNome: " << cliente[i].nome << "\nMatr�cula: " << cliente[i].matricula << "\nTipo: " << cliente[i].conta.tipo;
            cout << "\n\nQuanto deseja depositar? ";
            cin >> quant;

            system("cls");

            cliente[i].conta.saldo=cliente[i].conta.saldo+quant;

            cout << "Dep�sito realizado com sucesso! O saldo atual da conta � de R$" << cliente[i].conta.saldo;
            cout << "\n\nDeseja voltar para o menu?\n1 - Sim\n2 - N�o\n";
            cin >> valor;

            system("cls");

            return valor;
        }
    }
}

void pInfo()
{
    cout << "Cadastro de Cliente\n" << endl;
}

int nCad;

int fCadastro()
{
    for(int i=0; i<10; i++)
    {
        pInfo();

        cout << "Informe o nome do " << i+1 << "� cliente: ";
        cin >> cliente[i].nome;
        system("cls");

        pInfo();

        cout << "Informe o n�mero da matr�cula de " << cliente[i].nome << ": ";
        cin >> cliente[i].matricula;
        system("cls");

        pInfo();

        cout << "Qual a idade de " << cliente[i].nome << "? ";
        cin >> cliente[i].idade;
        system("cls");

        pInfo();

        cout << "Informe o n�mero da conta: ";
        cin >> cliente[i].conta.numero;
        system("cls");

        pInfo();

        int valor;

        cout << "Qual o tipo da conta?" << endl << "1 - Poupan�a" << endl << "2 - Corrente\n";
        cin >> valor;

        switch(valor)
        {

        case 1:
            cliente[i].conta.tipo = "Poupan�a";
            break;

        case 2:
            cliente[i].conta.tipo = "Corrente";
            break;

        default:
            cout << "N�mero inv�lido.";
        }

        system("cls");

        pInfo();

        cout << "Voc� deseja continuar cadastrando mais pessoas?\n1 - Sim\n2 - N�o\n";
        cin >> valor;

        if(valor==2)
        {
            system("cls");
            break;
        }

        nCad=i;

        system("cls");
    }

    int valor=0;

    cout << "Voc� cadastrou " << nCad+2 << " clientes com sucesso!\n\nDeseja voltar ao menu?\n1 - Sim\n2 - N�o\n";
    cin >> valor;

    system("cls");

    return valor;
}

int fMenu()
{

    int valor;

    pLinhaD();
    cout << "                  Banco Algoritmo                    \n";
    pLinhaD();
    cout << "\nEsse � o menu de funcionamento do sistema.\nDigite o n�mero correspondente a op��o que deseja:\n\n";
    cout << "1 - Fazer o cadastramento de at� 10 clientes\n";
    cout << "2 - Fazer um dep�sito em uma conta\n";
    cout << "3 - Mostrar o saldo de um determinado cliente\n";
    cout << "4 - Mostrar um relat�rio completo de todos os clientes\n";
    cout << "5 - Exibir os dados do cliente mais velho\n\n";
    pLinhaD();
    cin >> valor;

    return valor;
}

int main()
{
    setlocale (LC_ALL,"Portuguese");

    int opcao,cad;

volta:

    opcao = fMenu();

    switch(opcao)
    {
    case 1:
        system("cls");
        cad = fCadastro();
        if(cad==1)
        {
            system("cls");
            goto volta;
        }
        break;

    case 2:
        system("cls");
        cad = fDeposito();
        if(cad==1)
        {
            system("cls");
            goto volta;
        }
        break;

    case 3:
        system("cls");
        cad = fSaldo();
        if(cad==1)
        {
            system("cls");
            goto volta;
        }
        break;

    case 4:
        system("cls");
        cad = fMostrar();
        if(cad==1)
        {
            system("cls");
            goto volta;
        }
        break;

    case 5:
        system("cls");
        cad = fVelho();
        if(cad==1)
        {
            system("cls");
            goto volta;
        }
        break;

    default:
        system("cls");
        goto volta;
    }

    return 0;
}
