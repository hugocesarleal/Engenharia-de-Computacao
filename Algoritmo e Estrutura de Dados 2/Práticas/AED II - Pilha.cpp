#include <iostream>
#include <clocale>
using namespace std;

const int maxTam = 5;

// ESTRUTURA
struct TItem{
    // campos desejados!
    int chave; // valor único de cada elemento (diferencia)
};

struct TPilhaA{
    TItem vetItens[maxTam];
    int topo; // campo de controle
    int fundo;
};

// OPERAÇÕES BÁSICAS
void criaPilhaVazia(TPilhaA &p){
    p.fundo = -1;
    p.topo = p.fundo; // fora do limite do vetor!
}

bool estaVazia(TPilhaA p){
    return p.topo == p.fundo;
}

bool estaCheia(TPilhaA p){
    return p.topo >= maxTam-1;
}

void empilhar(TPilhaA &p, TItem x){
    cout << "=== EMPILHANDO ===" << endl;
    if (estaCheia(p)){
        cout << "Não posso empilhar. Pilha Cheia!" << endl;
    }
    else{
        p.topo++; // incrementar o topo;
        p.vetItens[p.topo] = x;
        cout << "Topo: " << p.topo << endl;
    }
}

void desempilhar(TPilhaA &p){
    cout << "=== DESEMPILHANDO ===" << endl;
    if (estaVazia(p)){
        cout << "Nenhum elemento para desempilhar. Pilha Vazia!" << endl;
    }
    else{
        p.topo--; // decrementa o controle!
    }
}

void mostrar(TPilhaA p){
    cout << "=== MOSTRANDO A PILHA ===" << endl;
    if (estaVazia(p)){
        cout << "Nenhum elemento para mostrar. Pilha Vazia!" << endl;
    }
    else{
        // fazer um for de topo para fundo
        int aux;
        for (aux=p.topo;aux>=0;aux--){
            cout << "Posição " << aux << ": " << p.vetItens[aux].chave << endl;
        }
    }

}



int main(){

    setlocale(LC_ALL,"Portuguese");//para acentuação e caracteres especiais

    // instanciando uma Pilha
    TPilhaA pilha;
    // criando uma pilha
    criaPilhaVazia(pilha);

    // NÃOOOOOOO faça
    cout << "Valor do topo: " << pilha.topo << endl;

    // preparando um item auxiliar para manipular a pilha
    TItem iAux;

    iAux.chave = 5;

    // empilhando
    empilhar(pilha,iAux);

    // NÃOOOOOOO faça
    cout << "Valor do topo: " << pilha.topo << endl;

    iAux.chave = 7;
    empilhar(pilha,iAux);
    iAux.chave = 8;
    empilhar(pilha,iAux);
    iAux.chave = 4;
    empilhar(pilha,iAux);
    iAux.chave = 2;
    empilhar(pilha,iAux);
    iAux.chave = 3;
    empilhar(pilha,iAux);

    // NÃOOOOOOO faça
    cout << "Valor do topo: " << pilha.topo << endl;

    mostrar(pilha);

    desempilhar(pilha);

    mostrar(pilha);
    cout << "Valor do topo: " << pilha.topo << endl;

    desempilhar(pilha);
    desempilhar(pilha);
    desempilhar(pilha);
    desempilhar(pilha);
    desempilhar(pilha);
    cout << "Valor do topo: " << pilha.topo << endl;
    desempilhar(pilha);
    mostrar(pilha);

    return 0;
}
