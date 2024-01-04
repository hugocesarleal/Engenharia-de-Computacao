    #include <iostream>
    #include <clocale>
    using namespace std;

    double c;

    double converter(double c){

    double f;

    f = c*1.8+32;

    cout << c << "ºC são " << f << "ºF.";

    }

    int main(){

	setlocale(LC_ALL,"Portuguese");

	cout << "Informe uma temperatura em ºC: ";
    cin >> c;

    converter(c);

	return 0;
}
