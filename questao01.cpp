#include <iostream>
#include <stdio.h>
using namespace std;

class Posto{
private:
    //atributos da classe
    char nome_posto[20];
    char bandeira[10];
    char endereco[25];
    float preco_gaso;
    float preco_eta;
    float preco_dies;
public:
    //prototipos dos metodos
    void registrarDados();
    float getGasolina();
    float getDiesel();
    float getEtanol();
    void imprimirDados();
};
//construiindo os metodos
void Posto::registrarDados(){
    cout << "nome: ";
    fflush(stdin);
    gets(nome_posto);

    cout << "bandeira: ";
    fflush(stdin);
    gets(bandeira);

    cout << "endereco: ";
    fflush(stdin);
    gets(endereco);

    cout << "preco litro da gasolina: ";
    cin >> preco_gaso;

    cout << "preco litro do etanol: ";
    cin >> preco_eta;

    cout << "preco litro do diesel: ";
    cin >> preco_dies;

}
float Posto::getGasolina(){
    return preco_gaso;
}
float Posto::getEtanol(){
    return preco_eta;
}
float Posto::getDiesel(){
    return preco_dies;
}
void Posto::imprimirDados(){
    cout << "mome: " << nome_posto <<endl;
    cout << "bandeira: " << bandeira <<endl;
    cout << "endereco: " << endereco <<endl;
    cout << "preco litro da gasolina: R$" << preco_gaso <<endl;
    cout << "preco litro do etanol: R$" << preco_eta <<endl;
    cout << "preco litro do diesel: R$" << preco_dies <<endl;
}

main(){
    //declarando as variaveis
    Posto P[20];
    int i, n, op;
    float m_gas=0, m_et=0, m_die=0;

    //verificando se o numero digitaw esta entre 0 e 20
    do{
        cout << "quantos postoso deseja cadastrar: ";
        cin >> n;
        if(n > 20 | n < 0)
            cout << "vc deve digitar um numero positivo menor q 20. "<< endl;
    }while(n < 0 | n > 20);

    //registrar dado
    for(i=0;i<n;i++){
        P[i].registrarDados();
        cout << endl;
    }

    //MENU
    cout << "[1] gasolina. " << endl;
    cout << "[2] etanol. " << endl;
    cout << "[3] diesel. " << endl;
    do{
        cout << "com qual combustivel deseja abastecer: ";
        cin >> op;
        if(op < 0 | op > 3)
            cout << "a opcao deve estar no menu."<<endl;
    }while(op < 0 | op > 3);

    if(op == 1){
        cout << "posto de gasolina com a gasolina a menor preco: " <<endl;

        //verificando o menor preco da gasolina
        for(i=0;i<n;i++){
            if(i==0){
                m_gas = P[i].getGasolina();
            }
            if(P[i].getGasolina() < m_gas)
                m_gas = P[i].getGasolina();
        }

        //imprimindo o posto com o menor preco de gas
        for(i=0;i<n;i++){
            if(m_gas == P[i].getGasolina())
                P[i].imprimirDados();
                cout << endl;
        }
    }
    if(op == 2){
        cout << "posto de gasolina com o etanol a menor preco: " <<endl;

        //verificando o menor preco da etanol
        for(i=0;i<n;i++){
            if(i==0){
                m_et = P[i].getEtanol();
            }
            if(P[i].getEtanol() < m_et)
                m_et = P[i].getEtanol();
        }
        //imprimindo o posto com o menor preco de etanol
        for(i=0;i<n;i++){
            if(m_et == P[i].getEtanol())
                P[i].imprimirDados();
                cout << endl;
        }
    }
    if(op == 3){
        cout << "posto de gasolina com o diesel a menor preco: " <<endl;

        //verificando o menor preco da diesel
        for(i=0;i<n;i++){
            if(i==0){
                m_die = P[i].getDiesel();
            }
            if(P[i].getDiesel() < m_die)
                m_die = P[i].getDiesel();
        }
        //imprimindo o posto com o menor preco de diesel
        for(i=0;i<n;i++){
            if(m_die == P[i].getDiesel())
                P[i].imprimirDados();
                cout << endl;
        }
    }




}
