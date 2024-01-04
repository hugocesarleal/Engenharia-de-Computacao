#include <iostream>
#include <chrono>
#include <clocale>

using namespace std;

void fbi(int n)
{
    if (n <= 0){

    }
    int a = 0;
    int b = 1;
    int temp = 0;

    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
        cout << b << endl;
    }


}

double fbr(int n)
{
    int resultado;
    if (n <= 2){
        return 1;
    }
    resultado = fbr(n - 1) + fbr(n - 2);

    cout << resultado << endl;

    return resultado;
}

int main()
{

    setlocale(LC_ALL,"Portuguese");

    long double vetTemposI[30], vetTemposR[30];
    long double num1,num2;

    for(int i=0; i<30; i++)
    {

        auto start = std::chrono::high_resolution_clock::now();

        num1 = fbr(20);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<long double> duration = end - start;
        long double executionTime = duration.count();

        vetTemposR[i] = executionTime;
    }

    for(int i=0; i<30; i++)
    {

        auto start = std::chrono::high_resolution_clock::now();

        fbi(20);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<long double> duration = end - start;
        long double executionTime = duration.count();

        vetTemposI[i] = executionTime;

    }

    cout << "Tempos Fibonacci Recursivo   Tempos Fibonacci Iterativo" << endl;

    for(int i=0; i<30; i++)
    {
        cout << vetTemposR[i] << "                                  " << vetTemposI[i] << endl;
    }


    return 0;
}
