    #include <iostream>
    #include <clocale>
    using namespace std;

    double c;

    double converter(double c){

    double f;

    f = c*1.8+32;

    cout << c << "�C s�o " << f << "�F.";

    }

    int main(){

	setlocale(LC_ALL,"Portuguese");

	cout << "Informe uma temperatura em �C: ";
    cin >> c;

    converter(c);

	return 0;
}
