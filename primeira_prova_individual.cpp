#include <iostream>
#include <vector>

using namespace std;

class DataNascimento {
    int dia;
    int mes;
    int ano;

    public:
        
        DataNascimento() : dia(0), mes(0), ano(0) {
        }

        ~DataNascimento(){}

        void validaDtNasc(){
            cout << "Informe a sua data de nascimento: " << endl;
            cout << "Dia: ";
            cin >> dia;
            if(dia < 1 || dia > 31){
                do{
                    cout << "O dia que você informou não é válido, por favor digite um dia válido: " << endl;
                    cout << "Dia: ";
                    cin >> dia;
                } while (dia < 1 || dia > 31);
            }
            cout << "Mês: ";
            cin >> mes;
            if(mes < 1 || mes > 12){
                do{
                    cout << "O mês que você informou não é válido, por favor digite um mês válido: " << endl;
                    cout << "Mês: ";
                    cin >> mes;
                } while (mes < 1 || mes > 12);
            }
            cout << "Ano: ";
            cin >> ano;
            if(ano < 1920 || ano > 2023){
                do{
                    cout << "O ano que você informou não é válido, por favor digite um ano válido (Ex: 2010): " << endl;
                    cout << "Ano: ";
                    cin >> ano;
                } while (ano < 1920 || ano > 2023);
            }
            
        }

        void retornaDtNasc(){
            cout << dia << "/" << mes << "/" << ano << endl;
        }
};


class Paciente {
    string cpf;
    string nome;
    DataNascimento dtNasc;
    

    public:
        Paciente() {
            cpf = "";
            nome = "";
            
        }

        void setCpf(string _cpf){
            this -> cpf = _cpf;
        }

        string getCpf(){
            return cpf;
        }

        void setNome(string _nome){            
            this -> nome = _nome;
        }

        string getNome(){
            return nome;
        }

        void setDtNasc(){
            dtNasc.validaDtNasc();
        }

        void getDtNasc(){
            dtNasc.retornaDtNasc();
        }

};

class Medico {
    string crm;
    string nome;
    string esp;

};

int main (){
    Paciente *paciente_ = new Paciente();
    vector <Paciente*> paciente;
    paciente.push_back(paciente_);
    // DataNascimento dataNasc;
    // dataNasc.validaDtNasc(); 
    paciente_->getDtNasc();
    paciente_->getDtNasc();
    int op;

    cout << "|=======================================|" << endl;
    cout << "|==========GESTÃO DE PACIENTES==========|" << endl;
    cout << "|========CLÍNICA SEM DODÓI LTDA.========|" << endl;
    cout << "|=======================================|" << endl;

    cout << "\nEscolha uma opção: \n" << endl;

    cout << "1. Incluir" << endl;
    // *paciente_ = new Paciente();
    // paciente.push_back(paciente_);
    cout << "2. Excluir" << endl;
    cout << "3. Alterar (apenas por CPF)" << endl;
    cout << "4. Listar" << endl;
    cout << "5. Localizar (por CPF)" << endl;
    cout << "0. Sair" << endl;

    cout << "\nOpção: ";
    cin >> op;

    return 0;
}