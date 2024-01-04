#include <iostream>
#include <clocale>
using namespace std;

double n,i,s=0;

double fFuncao(int n)
{

    for(i=1; i<n+1; i++)
    {

        double fatorial;

        fatorial=i;

        for(int cont=i-1; cont>0; cont=cont-1)
        {

            fatorial = fatorial*cont;
        }

        s = s + 1/fatorial;

        if(i<n)
        {
            cout << "1/" << i << "!" << " + ";
        }
        else
        {
            cout << "1/" << i << "!" << " = " << s;
        }
    }
}

int main()
{

    setlocale(LC_ALL,"Portuguese");

    cout << "Informe um número: ";
    cin >> n;

    fFuncao(n);

    return 0;
}
