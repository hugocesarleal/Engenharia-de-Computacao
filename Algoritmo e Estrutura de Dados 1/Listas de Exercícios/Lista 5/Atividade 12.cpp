#include <iostream>
#include <clocale>
using namespace std;

string vetNomes[10], vetSexo[10];
int vetIdade[10],controlM=0,controlF=0;

//Calcula a media das idades
double mediaIdades(){

    double media=0;

    for(int i=0;i<10;i++){

        media=media+vetIdade[i];
    }

    media=media/10;

    return media;
}

//Conta quantos s�o homens e quantas s�o mulheres
double controlMF(){

    for(int i=0;i<10;i++){
        if(vetSexo[i]=="M" || vetSexo[i]=="m"){
            controlM=controlM+1;
        }
        else{
            controlF=controlF+1;
        }
    }

    cout << "\n\nForam cadastrados " << controlM << " homens e " << controlF << " mulheres.";
}

//Busca e mostra as informa��es da pessoa desejada
double fBusca(){

    string nome;

    cout << "\nInforme o nome da pessoa que deseja buscar: ";
    cin >> nome;

    for(int i=0;i<10;i++){
        if(vetNomes[i]==nome){
            cout << "Nome: " << vetNomes[i] << "\nSexo: " << vetSexo[i] << "\nIdade: " << vetIdade[i] << "\nPosi��o de cadastro: " << i+1 << "�\n";
        }
    }
}

double nomeM(){

    int existenciaM=0;

    for(int i=0;i<10;i++){
        if(vetSexo[i]=="M" || vetSexo[i]=="m"){
            existenciaM=1;
        }
    }

    if(existenciaM==0){
        cout << "Nenhum homem foi cadastrado";
    }
    else{
        cout << "Nomes dos homens cadastrados:\n";

        for(int i=0;i<10;i++){

        if(vetSexo[i]=="M" || vetSexo[i]=="m"){
            cout << vetNomes[i] << endl;
            }
        }
    }
}

double maisIdosa(){

    int controleIdosa=0,controleIdosapos=0;

    for(int i=0;i<10;i++){
        if(vetIdade[i]>controleIdosa){
            controleIdosa=vetIdade[i];
            controleIdosapos=i;
        }
    }

    cout << "Dados da pessoa mais idosa:\n" << "Nome: " << vetNomes[controleIdosapos] << "\nSexo: " << vetSexo[controleIdosapos] << "\nIdade: " << vetIdade[controleIdosapos] << "\nPosi��o de cadastro: " << controleIdosapos+1 << "�\n";
}

double maisJovem(){

    int controleJovem=0,controleJovempos=0;

    for(int i=0;i<10;i++){
        if(vetIdade[i]<controleJovem){
            controleJovem=vetIdade[i];
            controleJovempos=i;
        }
    }

    cout << "Dados da pessoa mais idosa:\n" << "Nome: " << vetNomes[controleJovempos] << "\nSexo: " << vetSexo[controleJovempos] << "\nIdade: " << vetIdade[controleJovempos] << "\nPosi��o de cadastro: " << controleJovempos+1 << "�\n";
}


//Cadastra as pessoas e chama as fun��es
void pCadastro(){

    for(int i=0;i<10;i++){

        cout << "Informe o nome da " << i+1 << "� pessoa: ";
        cin >> vetNomes[i];

        cout << "Informe o sexo de " << vetNomes[i] << " (Utilize M ou F): ";
        cin >> vetSexo[i];

        while(vetSexo[i] !="M" && vetSexo[i] !="m" && vetSexo[i] !="F" && vetSexo[i] !="f"){
            cout << "Voc� digitou uma letra inv�lida! Informe o sexo da pessoa apenas com 'M' ou 'F': ";
            cin >> vetSexo[i];
        }

        cout << "Informe a idade de " << vetNomes[i] << ": ";
        cin >> vetIdade[i];
    }

    for(int i=0;i<10;i++){

        cout << endl << endl << "Nome: " << vetNomes[i] << "\nSexo: " << vetSexo[i] << "\nIdade: " << vetIdade[i];
    }

    cout << "\n\nA m�dia das idades �: " << mediaIdades();

    controlMF();

    fBusca();

    nomeM();

    maisIdosa();

    maisJovem();
}

int main(){

	setlocale(LC_ALL,"Portuguese");

	pCadastro();

	return 0;
}
