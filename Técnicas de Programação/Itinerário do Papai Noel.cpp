#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

class Grafo {
public:
    int V; // número de vértices
    vector<vector<int>> matrizAdj; // matriz de adjacência

    Grafo(int V) : V(V), matrizAdj(V, vector<int>(V, INF)) {}

    void adicionarAresta(int u, int v, int peso) {
        matrizAdj[u][v] = peso;
        matrizAdj[v][u] = peso;
    }

    int prim() {
        int custoTotal = 0;
        vector<bool> visitado(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // min-heap

        // Começar do vértice 0
        pq.push({0, 0});

        while (!pq.empty()) {
            int u = pq.top().second;
            int peso = pq.top().first;
            pq.pop();

            // Se o vértice ainda não foi visitado, marcá-lo como visitado e adicionar ao custo total
            if (!visitado[u]) {
                visitado[u] = true;
                custoTotal += peso;

                // Percorrer todos os vértices adjacentes de u
                for (int v = 0; v < V; ++v) {
                    if (!visitado[v] && matrizAdj[u][v] != INF) {
                        pq.push({matrizAdj[u][v], v});
                    }
                }
            }
        }

        return custoTotal;
    }
};

int main() {
    int M, N;

    while (true) {
        cin >> M >> N;

        if (M == 0 && N == 0) {
            break;  // Fim da entrada
        }

        Grafo grafo(M);

        for (int i = 0; i < N; ++i) {
            int X, Y, Z;
            cin >> X >> Y >> Z;
            grafo.adicionarAresta(X, Y, Z);
        }

        int resultado = grafo.prim();
        cout << resultado << endl;
    }

    return 0;
}
