#include <iostream>
#include <stdio.h>
using namespace std;

class Livro{
private:
    int isbn;
    char titulo[20];
    char autor[30];
    char edicao[15];
    int ano;
    char editora[20];
public:
    void registrarDados();
    void mostrarDados();
    int getIsbn();
};
void Livro::registrarDados(){
    cout << "isbn: ";
    cin >> isbn;

    cout << "titulo: ";
    fflush(stdin);
    gets(titulo);

    cout << "autor: ";
    fflush(stdin);
    gets(autor);

    cout << "edicao: ";
    fflush(stdin);
    gets(edicao);

    cout << "ano: ";
    cin >> ano;

    cout << "editora: ";
    fflush(stdin);
    gets(editora);
}
void Livro::mostrarDados(){
    cout << "isbn: " <<isbn << endl;
    cout << "titulo: " <<titulo << endl;
    cout << "autor: " <<autor << endl;
    cout << "edicao: " <<edicao << endl;
    cout << "ano: " <<ano << endl;
    cout << "editora: " <<editora << endl;
}
int Livro::getIsbn(){
    return isbn;
}

class livroFisico:Livro{
private:
    char tpcapa[10];
    float precolivro;
    float precofrete;
    int diasparaentrega;
public:
    void registrarDados();
    float calcularPreco();
    void mostrarDados();
    int getIsbn();
};
void livroFisico::registrarDados(){
    Livro::registrarDados();

    cout << "tipo da capa: ";
    fflush(stdin);
    gets(tpcapa);

    cout << "preco do livro: ";
    cin >> precolivro;

    cout << "preco do frete: ";
    cin >> precofrete;

    cout << "dias para entrega: ";
    cin >> diasparaentrega;
}
float livroFisico::calcularPreco(){
    return precolivro + precofrete;
}
void livroFisico::mostrarDados(){
    Livro::mostrarDados();
    cout << "tipo de capa: " <<tpcapa <<endl;
    cout << "preco do livro: R$" <<precolivro <<endl;
    cout << "preco do frete: R$" <<precofrete <<endl;
    cout << "dias para entrega: " <<diasparaentrega <<endl;
    cout << "preco total: R$"<<livroFisico::calcularPreco();
}
int livroFisico::getIsbn(){
    return Livro::getIsbn();
}

class livroDigital:Livro{
private:
    float precoassinatura;
    int tempoassinaturameses;
public:
    void registrarDados();
    float calcularPreco();
    void mostrarDados();
    int getIsbn();
};
void livroDigital::registrarDados(){
    Livro::registrarDados();
    cout << "preco da assinatura: ";
    cin >> precoassinatura;

    cout << "tempo da assinatura em meses: ";
    cin >> tempoassinaturameses;
}
float livroDigital::calcularPreco(){
    return precoassinatura * tempoassinaturameses;
}
void livroDigital::mostrarDados(){
    Livro::mostrarDados();
    cout << "preco da assinatura: " <<precoassinatura <<endl;
    cout << "meses assinando: " <<tempoassinaturameses <<endl;
    cout << "preco total: R$" <<livroDigital::calcularPreco() <<endl;
}
int livroDigital::getIsbn(){
    return Livro::getIsbn();
}
main(){
    //declarando variaveis
    livroFisico LF[50];
    livroDigital LD[50];
    int i, nf, nd, op, isbnop;

    //cadastrando livros fisicos
    do{
        cout << "quantos livros fisicos deseja cadastrar? ";
        cin >> nf;
        if(nf < 0 | nf > 50)
            cout << "vc deve digitar um numero positivo menor q 50! "<< endl;
    }while(nf < 0 | nf > 50);

    for(i=0;i<nf;i++){
        LF[i].registrarDados();
    }

    //cadastrando livros digitais
    do{
        cout << "quantos livros digitais deseja cadastrar? ";
        cin >> nd;
        if(nd < 0 | nd > 50)
            cout << "vc deve digitar um numero positivo menor q 50! "<< endl;
    }while(nd < 0 | nd > 50);

    for(i=0;i<nd;i++){
        LD[i].registrarDados();
    }

    //MENU
    do{
        cout << "[1] consultar livros fisicos. " << endl;
        cout << "[2] consultar livros digitais. " << endl;
        cout << "[3] sair." << endl;
        cin >> op;

        //caso o usuario escolha livros fisicos
        if(op == 1){
            cout << "digite o ISBN do livro fisico: ";
            cin >> isbnop;//isbn do livro q deseja consultar

            //verificando o isbn digitado com os cadastrados
            for(i=0;i<nf;i++){
                if(isbnop == LF[i].getIsbn())
                    LF[i].mostrarDados();
                    cout << endl;
            }
        }
        //caso o usuario escolha livros digitais
        if(op == 2){
            cout << "digite o ISBN do livro digital: ";
            cin >> isbnop;//isbn do livro q deseja consultar
            for(i=0;i<nd;i++){
                //verificando o isbn digitado com os cadastrados
                if(isbnop == LD[i].getIsbn())
                    LD[i].mostrarDados();
                    cout << endl;
                }
            }

    }while(op != 3);
    return 0;
}

