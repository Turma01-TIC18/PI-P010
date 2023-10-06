#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Função de ordenação Bubble Sort para strings
void bubbleSort(vector<string>& nomes) {
    int n = nomes.size();
    
    for (int i = 0; i < n - 1; ++i) {

        for (int j = 0; j < n - i - 1; ++j) {

            if (nomes[j] > nomes[j + 1]) {
                swap(nomes[j], nomes[j + 1]);
                
            }
        }
    }
}

int main() {

    int n;
    float nota1, nota2;
    vector<string> nomes;
    vector<float> notas1, notas2;

    cout << "Digite o numero de alunos: ";
    cin >> n;

    // Vetores para armazenar nomes e notas dos alunos    
    for (int i = 0; i < n; ++i) {

        string nome;
        cout << "Digite o nome do aluno " << i + 1 << ": ";
        cin >> nome;

        cout << "Digite a primeira nota de " << nome << ": ";
        cin >> nota1; 
        cout << "Digite a segunda nota de " << nome << ": ";
        cin >> nota2;

        nomes.push_back(nome);
        notas1.push_back(nota1);
        notas2.push_back(nota2);
    }

    bubbleSort(nomes);
    
    // Exibir os dados dos alunos
    cout << "\nDados dos Alunos:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Aluno: " << nomes[i] << ", Nota 1: " << notas1[i] 
        << ", Nota 2: " << notas2[i] << endl;
    }

    char opcao;
    do {
        cout << "\nEscolha uma opcao:\n";
        cout << "1. Incluir novo aluno\n";
        cout << "2. Excluir aluno\n";
        cout << "3. Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case '1': {
                string novoNome;
                cout << "Digite o nome do novo aluno: ";
                cin >> novoNome;

                // Verificar se o aluno já existe
                auto it = find(nomes.begin(), nomes.end(), novoNome);

                if (it != nomes.end()) {
                    cout << "Aluno ja existe. Inclusao cancelada.\n";

                } 

                else {
                    cout << "Digite a primeira nota de " << novoNome << ": ";
                    cin >> nota1;
                    cout << "Digite a segunda nota de " << novoNome << ": ";
                    cin >> nota2;

                    nomes.push_back(novoNome);
                    notas1.push_back(nota1);
                    notas2.push_back(nota2);

                    bubbleSort(nomes);

                    cout << "Novo aluno incluido com sucesso!\n";
                }

                break;
            }
            case '2': {
                string alunoExcluir;
                cout << "Digite o nome do aluno a ser excluido: ";
                cin >> alunoExcluir;

                // Verificar se o aluno existe
                auto it = find(nomes.begin(), nomes.end(), alunoExcluir);
                if (it != nomes.end()) {
                    // Encontrado, excluir o aluno
                    nomes.erase(it);
                    notas1.erase(notas1.begin() + distance(nomes.begin(), it));
                    notas2.erase(notas2.begin() + distance(nomes.begin(), it));

                    cout << "Aluno excluido com sucesso!\n";
                } 
                else {
                    cout << "Aluno nao encontrado. Exclusao cancelada.\n";

                }
                break;

            }
            case '3':
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opcao invalida... Tente novamente.\n";
        }

    } while (opcao != '3');

return 0;
}