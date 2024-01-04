#include <iostream>
#include <cstring>

using namespace std;

class Cavaleiro {
public:
    int l, c, mov;

    Cavaleiro() : l(0), c(0), mov(0) {}

    Cavaleiro(int linha, int coluna, int movimentos) : l(linha), c(coluna), mov(movimentos) {}
};

bool ehValido(int l, int c) {
    return l >= 0 && l < 8 && c >= 0 && c < 8;
}

int movCavaleiro(const string &inicio, const string &fim) {
    int linInicio = inicio[1] - '1';
    int colInicio = inicio[0] - 'a';
    int linFim = fim[1] - '1';
    int colFim = fim[0] - 'a';

    const int dl[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    const int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

    bool visitado[8][8];
    memset(visitado, false, sizeof(visitado));

    Cavaleiro filaCav[64];
    int frente = 0, tras = 0;

    filaCav[tras++] = Cavaleiro(linInicio, colInicio, 0);
    visitado[linInicio][colInicio] = true;

    while (frente != tras) {
        Cavaleiro atual = filaCav[frente++];

        if (atual.l == linFim && atual.c == colFim) {
            return atual.mov;
        }

        for (int direcao : {0, 1, 2, 3, 4, 5, 6, 7}) {
            int nL = atual.l + dl[direcao];
            int nC = atual.c + dc[direcao];

            if (ehValido(nL, nC) && !visitado[nL][nC]) {
                filaCav[tras++] = Cavaleiro(nL, nC, atual.mov + 1);
                visitado[nL][nC] = true;
            }
        }
    }

    return -1;
}

int main() {
    string inicio, fim;

    while (cin >> inicio && cin >> fim) {
        int movimentos = movCavaleiro(inicio, fim);
        cout << "To get from " << inicio << " to " << fim << " takes " << movimentos << " knight moves." << endl;
    }

    return 0;
}
