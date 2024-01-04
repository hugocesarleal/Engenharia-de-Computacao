#include <iostream>
#include "biblio1.h"

void iniciarEnt(TEntidade &e){

    e.chave=1;
    e.nome="teste";
    cout << "Chave: " << e.chave << endl;
    cout << "Nome: " << e.nome << endl;
}

