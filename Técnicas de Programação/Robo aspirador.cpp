#include <iostream>
#include <cstring>

using namespace std;

struct Estado {
    int x, y, movimentos, bateria;
};

const int MAX_H = 100;
const int MAX_W = 100;

char sala[MAX_H][MAX_W];

int main() {
    int N, M, W, H;

    while (cin >> N >> M) {
        cin >> W >> H;

        Estado fila[H * W];
        int front = 0, rear = 0;

        Estado inicial;

        // Leitura da sala e posição inicial
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> sala[i][j];

                if (sala[i][j] == 'R') {
                    inicial.x = j;
                    inicial.y = i;
                    inicial.movimentos = 0;
                    inicial.bateria = M;
                }
            }
        }

        // Movimentos possíveis: cima, baixo, esquerda, direita
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        int maxGraos = 0;

        fila[rear++] = inicial;

        while (front < rear) {
            Estado atual = fila[front++];

            // Chegou à estação de recarga
            if (sala[atual.y][atual.x] == 'S') {
                maxGraos = max(maxGraos, N - atual.bateria);
                continue;
            }

            // Movimentos possíveis
            for (int i = 0; i < 4; ++i) {
                int nx = atual.x + dx[i];
                int ny = atual.y + dy[i];

                // Verifica se é uma posição válida
                if (nx >= 0 && nx < W && ny >= 0 && ny < H && sala[ny][nx] != '#' && atual.movimentos + 1 <= M) {
                    Estado novo;
                    novo.x = nx;
                    novo.y = ny;
                    novo.movimentos = atual.movimentos + 1;
                    novo.bateria = atual.bateria - 1;

                    // Coleta grão de sujeira
                    if (sala[ny][nx] == '*') {
                        sala[ny][nx] = '.'; // Marca como visitado
                        novo.bateria = M;    // Recarrega a bateria ao coletar um grão
                    }

                    fila[rear++] = novo;
                }
            }
        }

        if (maxGraos == 0) {
            cout << -1 << endl;
        } else {
            cout << maxGraos << endl;
        }
    }

    return 0;
}
