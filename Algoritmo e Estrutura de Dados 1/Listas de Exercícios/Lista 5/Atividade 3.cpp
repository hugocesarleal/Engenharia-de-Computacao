    #include <iostream>
    #include <clocale>
    using namespace std;

    double n;

    double fFuncao(int n){

    for(double i=1;i<n+1;i++){

        double s = s + 1/i;

        if(i<n){
            cout << "1/" << i << " + ";
        }
        else{
            cout << "1/" << i << " = " << s;
            }
        }
    }

    int main(){

	setlocale(LC_ALL,"Portuguese");

	cout << "Informe um número: ";
	cin >> n;

    fFuncao(n);

	return 0;
}
