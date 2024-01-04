    #include <iostream>
    #include <clocale>
    using namespace std;

    float result;

    float fFuncao(float x){

        result = (2*x)+4;

        return result;
    }

    void pControle(){

        float i;
        float resultado;

        for(i=0;i<21;i++){

            fFuncao(i);

            resultado = result;

            cout << "f(" << i << ")= " << resultado << endl;
        }

    }

    int main(){

	setlocale(LC_ALL,"Portuguese");

	pControle();

	return 0;
}
