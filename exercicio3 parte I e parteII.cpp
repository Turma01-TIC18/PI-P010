#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void bubbleSort(vector<string>& nomes) {
    
    int n = nomes.size();
    bool trocou;

    do {
        trocou = false;

        for (int i = 1; i < n; i++) {
            
            if (nomes[i - 1] > nomes[i]) {
                swap(nomes[i - 1], nomes[i]);
                trocou = true;
            }
        }
    } while (trocou);
}

void excluirAluno(vector<string>& nomes, vector<float>& nota1, vector<float>& nota2) {
    string nome;
    int i = 0;
    
    cout << "Favor o nome do aluno: ";
    cin >> nome;
    cin.ignore();

    for(auto it=nomes.begin(); it!=nomes.end(); it++, i++) {
        if(*it == nome) {
            nomes.at(i).erase();
            nota1.at(i) = 0;
            nota2.at(i) = 0;
        }
    }
    
}

void imprimir(vector<string>& nomes) {
    int i = 1;
    for(auto it=nomes.begin(); it!=nomes.end(); it++, i++) {
        
        if(!nomes.empty()){

            cout << "Aluno " << i << " - " <<  *it << endl;
        }else {
            cout << "Dados não encontrados em Nomes" << endl;
        }
    }
    cout << "-------------------------------------\n";

}

void incluirNotas(vector<float>& nota1, vector<float>& nota2) {
    float n1, n2;
    int indice = 0;

    cout << "Informe o número do aluno: ";
    cin >> indice;  

    indice -= 1;    
       
    cout << "Favor informar a nota1: ";
    cin >> n1;
    nota1.insert(nota1.begin()+indice,n1);

    cout << "Favor informar a nota2: ";
    cin >> n2;
    nota2.insert(nota2.begin()+indice,n2);                      
    
}

void alterarNotas(vector<string>& nomes, vector<float>& nota1, vector<float>& nota2) {
    string nome;
    int i = 0, opcao;
    float novaNota1, novaNota2;

    cout << "Favor o nome do aluno: ";
    getline(cin >> ws, nome);

    for(auto it=nomes.begin(); it!=nomes.end(); it++, i++) {
        if(*it == nome) {
            cout << "Qual a nota que deseja alterar(1 | 2 | 0 - Nenhuma)? ";
            cin >> opcao;           
        }else {
            cout << "Nome não encontrado" << endl;
            break;
        }
         switch (opcao)
            {
            case 1:
                cout << "Digite o novo valor da Nota1: ";
                cin >> novaNota1;
                nota1[i] = novaNota1;
                break;
            case 2:
                cout << "Digite o novo valor da Nota2: ";
                cin >> novaNota2;
                nota2[i] = novaNota2;
                break;
            case 0:
                break;
            default:
                break;
            }

    }


}




void incluirAluno(vector<string>& nomes, vector<float>& nota1, vector<float>& nota2) {
    int numAlunos;
    string nome; 
    char opcao;
        

    cout << "Favor digitar o n. de alunos: ";
    cin >> numAlunos;
    
      
         
    for(int i = 1 ; i <= numAlunos ; i++) {
        cout << "Informe o nome do " << i << " aluno" << endl;
        getline(cin >> ws, nome);
        nomes.push_back(nome);    
        
    }
    
    bubbleSort(nomes);

    cout << "Deseja incluir Notas(s/n) ?";
    cin >> opcao;
    if(opcao == 's' || opcao == 'S') {
        imprimir(nomes);
        incluirNotas(nota1, nota2);
    }

    
}



void imprimirNotas(vector<float>& nota1, vector<float> nota2) {
    int i = 1;
    int j = 1;
    for(auto it=nota1.begin(); it!=nota1.end(); it++, i++) {
        
        if(!nota1.empty() || !nota2.empty()){

            cout << "Nota1 - Aluno " << i << ": " << fixed << setprecision(2) << *it << endl;
        }else {
            cout << "Dados não encontrados em Nota" << endl;
        }
    }
    cout << "-------------------------------------\n";
    for(auto it=nota2.begin(); it!=nota2.end(); it++, j++) {
        if(!nota1.empty() || !nota2.empty()){

            cout << "Nota2 - Aluno  " << j <<  ": " << fixed << setprecision(2) << *it << endl;
            
        }else {
            cout << "Dados não encontrados em Nota" << endl;
        }
    }  

    
}


int main() {
    string troca;
    float notas;
    bool prosseguir = true;
    int opcao;
    int n;

    vector<string> nomes;
    vector<float> nota1;
    vector<float> nota2;

    n=nomes.size();

    

while(prosseguir) {
    
    cout << "1 - Deseja INCLUIR alunos? \n";
    cout << "2 - Deseja EXCLUIR alunos? \n";
    cout << "3 - Incluir NOTAS? \n";
    cout << "4 - Alterar NOTAS? \n";
    cout << "5 - Imprimir \n";
    cout << "0 - Sair \n";
    cin >> opcao;
    

    switch (opcao)
    {
    case 1:
        incluirAluno(nomes, nota1, nota2);
        break;
    case 2:
        excluirAluno(nomes, nota1, nota2);
        break;
    case 3:
        imprimir(nomes);
        incluirNotas(nota1,nota2);
        break;
    case 4:
        alterarNotas(nomes, nota1, nota2);
        break;
    case 5:
        imprimir(nomes);
        imprimirNotas(nota1, nota2);
        break;
    case 0:
        prosseguir = opcao == 0? false : true;
    default:
        break;
    }

}



   

    /*for(auto it = nomes.begin(); it!= nomes.end(); it++ ) {
        cout << *it << "\t" << endl;
    }
    cout << endl;*/
    
    /*for(auto it = nota1.begin(); it!= nota1.end(); it++ ) {
        cout << *it << "\t" << endl ;
    }
    cout << endl;

    for(auto it = nota2.begin(); it!= nota2.end(); it++ ) {
        cout << *it << "\t" << endl;
    }*/

}