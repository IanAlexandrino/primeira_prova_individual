#include <iostream>
#include <vector>
#include <string>

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

        ~Paciente(){}

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

        void insereDadosPaciente(){
            string nomeP;
            string cpfP;

            cout << "Digite o nome do paciente: ";
            getline(cin >> ws, nomeP);
            setNome(nomeP);

            cout << "Digite o CPF do paciente: ";
            getline(cin >> ws, cpfP);
            setCpf(cpfP);

            dtNasc.validaDtNasc();
        }

        void listaPaciente(){
            cout << "Aqui está o paciente que você está procurando: \n" << endl;
            cout << "Nome: " << getNome() << endl;
            cout << "CPF: " << getCpf() << endl;
            getDtNasc();
        }

        void alterandoPaciente (){
            string auxNome;
            string auxCpf;

            cout << "Aqui está o paciente que você quer alterar: \n" << endl;
            cout << "Novo nome: ";
            getline(cin >> ws, auxNome);
            setNome(auxNome);
            cout << "Novo cpf: ";
            getline(cin >> ws, auxCpf);
            setCpf(auxCpf);
            cout << "Nova data de nascimento: ";
            setDtNasc();
            
        }
};

class Medico {
    string crm;
    string nome;
    string esp;

    public:
        Medico() {
            crm = "";
            nome = "";
            esp = "";
            
        }

        ~Medico(){}

        void setCrm(string _crm){
            this -> crm = _crm;
        }

        string getCrm(){
            return crm;
        }

        void setNome(string _nome){            
            this -> nome = _nome;
        }

        string getNome(){
            return nome;
        }

        void setEsp(string _esp){
            this -> esp = _esp;
        }

        string getEsp(){
            return esp;
        }

        void insereDadosMedico(){
            string nomeM;
            string crmM;
            string espM;

            cout << "Digite o nome do médico: ";
            getline(cin >> ws, nomeM);
            setNome(nomeM);

            cout << "Digite o CRM do médico: ";
            getline(cin >> ws, crmM);
            setCrm(crmM);

            cout << "Digite a especialidade do médico: ";
            getline(cin >> ws, espM);
            setEsp(espM);
        }

        void listaMedico(){
            cout << "Aqui está o médico que você está procurando: \n" << endl;
            cout << "Nome: " << getNome() << endl;
            cout << "CRM: " << getCrm() << endl;
            cout << "Especialidade: " << getEsp() << endl;
        }

        void alterandoMedico (){
            string auxNome;
            string auxCrm;
            string auxEsp;

            cout << "Aqui está o médico que você quer alterar: \n" << endl;
            cout << "Novo nome: ";
            getline(cin >> ws, auxNome);
            setNome(auxNome);
            cout << "Novo CRM: ";
            getline(cin >> ws, auxCrm);
            setCrm(auxCrm);
            cout << "Nova especialidade: ";
            getline(cin >> ws, auxEsp);
            setEsp(auxEsp);
            
        }
};

int main (){
    Paciente *pacienteNovo = nullptr;
    vector <Paciente*> pacienteVec;
    vector <Paciente*> :: iterator it;

    Medico *medicoNovo = nullptr;
    vector <Medico*> medicoVec;
    vector <Medico*> :: iterator at;
    
    string cpf;
    string crm;
    int opPacienteMedico;
    int opPaciente;
    int opMedico;
    do{
        
        cout << "|=======================================|" << endl;
        cout << "|========CLÍNICA SEM DODÓI LTDA.========|" << endl;
        cout << "|=======================================|" << endl;

        cout << "\nEscolha uma opção: \n" << endl;

        cout << "1. Área dos Médicos" << endl;
        cout << "2. Área dos Pacientes" << endl;
        cout << "0. Sair" << endl;

        cout << "\nOpção: ";
        cin >> opPacienteMedico;

        if(opPacienteMedico == 1){

            cout << "|=======================================|" << endl;
            cout << "|===========GESTÃO DE MEDICOS===========|" << endl;
            cout << "|========CLÍNICA SEM DODÓI LTDA.========|" << endl;
            cout << "|=======================================|" << endl;

            cout << "\nEscolha uma opção: \n" << endl;

            cout << "1. Incluir" << endl;
            cout << "2. Excluir" << endl;
            cout << "3. Alterar (apenas por CRM)" << endl;
            cout << "4. Listar" << endl;
            cout << "5. Localizar (por CRM)" << endl;
            cout << "0. Sair" << endl;

            cout << "\nOpção: ";
            cin >> opMedico;
            
            switch(opMedico){           
                case 1:
                    medicoNovo = new Medico();
                    medicoNovo->insereDadosMedico();            
                    medicoVec.push_back(medicoNovo);
                    break;

                case 2:
                    at = medicoVec.begin();
                    

                    cout << "Digite o CRM do médico que você quer deletar";
                    cin >> crm;

                    medicoNovo=*at;

                    while (at != medicoVec.end() && medicoNovo -> getCrm() != crm){
                        at++;
                        medicoNovo=*at;
                    }

                    if(at != medicoVec.end()) medicoVec.erase(at);

                break;

                case 3:
                    at = medicoVec.begin();
                    

                    cout << "Digite o CRM do médico que você quer alterar: ";
                    cin >> crm;

                    medicoNovo=*at;

                    while (at != medicoVec.end() && medicoNovo -> getCrm() != crm){
                        at++;
                        medicoNovo=*at;
                    }

                    if(at != medicoVec.end()) medicoNovo -> alterandoMedico();
                break;

                case 4:
                    for (auto medico : medicoVec) {
                        medico->listaMedico();
                    }
                break;

                case 5:
                    at = medicoVec.begin();
                

                    cout << "Digite o CRM do médico que você quer localizar: ";
                    cin >> crm;

                    medicoNovo=*at;

                    while (at != medicoVec.end() && medicoNovo -> getCrm() != crm){
                        at++;
                        medicoNovo=*at;
                    }

                    if(at != medicoVec.end()) medicoNovo -> listaMedico();
                break;

                case 0:            
                break;

                default:
                cout << "Opção Inválida, por favor escolha uma opção válida!!!" << endl;
            }

        }else if (opPacienteMedico == 2){ 

            cout << "|=======================================|" << endl;
            cout << "|==========GESTÃO DE PACIENTES==========|" << endl;
            cout << "|========CLÍNICA SEM DODÓI LTDA.========|" << endl;
            cout << "|=======================================|" << endl;

            cout << "\nEscolha uma opção: \n" << endl;

            cout << "1. Incluir" << endl;
            cout << "2. Excluir" << endl;
            cout << "3. Alterar (apenas por CPF)" << endl;
            cout << "4. Listar" << endl;
            cout << "5. Localizar (por CPF)" << endl;
            cout << "0. Sair" << endl;

            
            cout << "\nOpção: ";
            cin >> opPaciente;
            
            switch(opPaciente){           
                case 1:
                    pacienteNovo = new Paciente();
                    pacienteNovo->insereDadosPaciente();            
                    pacienteVec.push_back(pacienteNovo);
                    break;

                case 2:
                    it = pacienteVec.begin();
                    

                    cout << "Digite o cpf do paciente que você quer deletar";
                    cin >> cpf;

                    pacienteNovo=*it;

                    while (it != pacienteVec.end() && pacienteNovo -> getCpf() != cpf){
                        it++;
                        pacienteNovo=*it;
                    }

                    if(it != pacienteVec.end()) pacienteVec.erase(it);

                break;

                case 3:
                    it = pacienteVec.begin();
                    

                    cout << "Digite o cpf do paciente que você quer alterar: ";
                    cin >> cpf;

                    pacienteNovo=*it;

                    while (it != pacienteVec.end() && pacienteNovo -> getCpf() != cpf){
                        it++;
                        pacienteNovo=*it;
                    }

                    if(it != pacienteVec.end()) pacienteNovo -> alterandoPaciente();
                break;

                case 4:
                    for (auto paciente : pacienteVec) {
                        paciente->listaPaciente();
                    }
                break;

                case 5:
                    it = pacienteVec.begin();
                

                    cout << "Digite o cpf do paciente que você quer localizar: ";
                    cin >> cpf;

                    pacienteNovo=*it;

                    while (it != pacienteVec.end() && pacienteNovo -> getCpf() != cpf){
                        it++;
                        pacienteNovo=*it;
                    }

                    if(it != pacienteVec.end()) pacienteNovo -> listaPaciente();
                break;

                case 0:            
                break;

                default:
                cout << "Opção Inválida, por favor escolha uma opção válida!!!" << endl;
            }
        }    

    } while (opPacienteMedico != 0);

    for (auto paciente : pacienteVec) {
        delete paciente;
    }

    for (auto medico : medicoVec) {
        delete medico;
    }

    return 0;
}