#include <iostream>
#include <clocale>

using namespace std;

int buscaBinaria (int x, int n, int v[])
{
    int e = -1, d = n;
    while (e < d-1)
    {
        int m = (e + d)/2;
        if (v[m] < x) e = m;
        else d = m;
    }
    return d;
}

int main ()
{
    setlocale(LC_ALL, "Portuguese");

    int vetA[100000], k, escolha, busca, enc;

    for(int i=0; i<100000; i++)
    {
        vetA[i] = i+1;

    }

    cout << "Qual a chave? " << endl;
    cin >> k;

volta:

    cout << "Qual algoritmo deseja usar?\n1 - Para\n2 - Busca Binária" << endl;
    cin >> escolha;

    switch(escolha)
    {
    case 1:
        for(int i=0; i<100000; i++)
        {
            for(int j=0; j<100000; j++)
            {
                if(vetA[i]+vetA[j] == k)
                {
                    cout << "Posição 1: " << i << endl;
                    cout << "Posição 2: " << j << endl << endl;
                }
            }
        }
        break;
    case 2:

        for(int i=0; i<100000; i++)
        {
            busca = k - vetA[i];

            if(busca<0){
                busca = busca*(-1);
            }

            enc = buscaBinaria(busca,100000,vetA);

            if(vetA[enc]+vetA[i]==k)
            {
                cout << "Posição 1: " << i << endl;
                cout << "Posição 2: " << enc << endl << endl;
            }
        }
        break;
    default:
        goto volta;
        break;
    }
    return 0;
}


