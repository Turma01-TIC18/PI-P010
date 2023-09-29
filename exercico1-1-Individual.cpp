#include <iostream>
#include <vector>
#include <string>


using namespace std;


void incluirNotas(vector<float>& nota1, vector<float>& nota2) {
    float notas;
            
    cout << "Favor informar a nota1 ";
    cin >> notas;
    nota1.push_back(notas);

    cout << "Favor informar a nota2 ";
    cin >> notas;
    nota2.push_back(notas);
    
}


void incluirAluno(vector<string>& nomes, vector<float>& nota1, vector<float>& nota2) {
    int numAlunos;
    string nome; 
            
    cout << "Favor digitar o n. de alunos: ";
    cin >> numAlunos;
             
    for(int i = 1 ; i <= numAlunos ; i++) {
        cout << "Informe o nome do " << i << " aluno" << endl;
        getline(cin >> ws, nome);
        nomes.push_back(nome);    
        incluirNotas(nota1, nota2);
    }
        
}


int main() {
    string troca;
    bool prosseguir = true;
    int opcao;
    
    vector<string> nomes;
    vector<float> nota1;
    vector<float> nota2;

    

    

    while(prosseguir) {
        
        cout << "1 - Deseja INCLUIR alunos? \n";
        cout << "0 - Sair \n";
        cin >> opcao;
        

        switch (opcao)
        {
        case 1:
            incluirAluno(nomes, nota1, nota2);
            break;
        case 0:
            prosseguir = opcao == 0? false : true;
        default:
            break;
        }

    }

    return 0;

}