#include <iostream>
#include <vector>

class Cidade {
private:
    int N;
    std::vector<std::vector<bool>> conexoes;

public:
    Cidade(int n) : N(n), conexoes(n, std::vector<bool>(n, false)) {}

    void add(int a, int b) {
        conexoes[a - 1][b - 1] = conexoes[b - 1][a - 1] = true;
    }

    void floyd() {
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    conexoes[i][j] = conexoes[i][j] || (conexoes[i][k] && conexoes[k][j]);
                }
            }
        }
    }

    bool check(int k, int l) {
        return conexoes[k - 1][l - 1] || conexoes[l - 1][k - 1];
    }
};

int main() {
    int N, M, P;
    std::cin >> N >> M >> P;

    Cidade c(N);

    for (int i = 0; i < M; ++i) {
        int A, B;
        std::cin >> A >> B;
        c.add(A, B);
    }

    c.floyd();

    for (int i = 0; i < P; ++i) {
        int K, L;
        std::cin >> K >> L;

        if (c.check(K, L)) {
            std::cout << "Lets que lets\n";
        } else {
            std::cout << "Deu ruim\n";
        }
    }

    return 0;
}
