#include <iostream>
#include <clocale>
#include "biblio2.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    TEntidade ent; //instancia

    iniciarEnt(ent);

    alterarNome(ent);
    cout << ent.nome << endl;
    cout << ent.chave << endl;

    return 0;
}
