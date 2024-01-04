#include <iostream>
#include <vector>
#include <set>

class G {
public:
    G(int n) : N(n), LA(n, std::set<int>()) {}

    void aA(int u, int v) {
        LA[u - 1].insert(v - 1);
    }

    std::string tC() {
        std::vector<bool> V(N, false);
        std::set<int> visited;

        for (int i = 0; i < N; ++i) {
            if (!V[i] && tCDFS(i, V, visited))
                return "Bolada";
        }

        return "Nao Bolada";
    }

    bool tCDFS(int n, std::vector<bool>& V, std::set<int>& visited) {
        if (!V[n]) {
            V[n] = true;
            visited.insert(n);

            for (int v : LA[n]) {
                if (!V[v] && tCDFS(v, V, visited))
                    return true;
                else if (visited.find(v) != visited.end())
                    return true;
            }
        }

        visited.erase(n);
        return false;
    }

private:
    int N;
    std::vector<std::set<int>> LA;
};

int main() {
    int N, M;
    std::cin >> N >> M;

    G Gf(N);

    for (int i = 0; i < M; ++i) {
        int U, V;
        std::cin >> U >> V;
        Gf.aA(U, V);
    }

    std::cout << Gf.tC() << std::endl;

    return 0;
}
