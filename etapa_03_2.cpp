#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void bubbleSort(vector<string>& nomes, vector<float>& notas1, vector<float>& notas2) {
    int N = nomes.size();
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (nomes[j] > nomes[j + 1]) {
                // Trocar nomes
                swap(nomes[j], nomes[j + 1]);
                // Trocar notas correspondentes
                swap(notas1[j], notas1[j + 1]);
                swap(notas2[j], notas2[j + 1]);
            }
        }
    }
}

int main() {
    int N;
    cout << "Informe o limite de alunos (N): ";
    cin >> N;

    vector<string> nomes;
    vector<float> notas1;
    vector<float> notas2;

    char continuar;
    do {
        string nome;
        float nota1, nota2;

        cout << "Informe o nome do aluno: ";
        cin >> nome;

        if (nomes.size() >= N) {
            cout << "Limite de alunos atingido. Não é possível incluir mais alunos." << endl;
        } else {
            cout << "Informe a primeira nota do aluno: ";
            cin >> nota1;
            cout << "Informe a segunda nota do aluno: ";
            cin >> nota2;

            nomes.push_back(nome);
            notas1.push_back(nota1);
            notas2.push_back(nota2);

            bubbleSort(nomes, notas1, notas2);

            cout << "Aluno adicionado com sucesso." << endl;
            cout << " " << endl;
        }

        cout << "Deseja incluir mais alunos (s/n)? ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    char alterarNota;
    do {
        cout << "\nLista de Alunos:\n";
        cout << " " << endl;
        for (size_t i = 0; i < nomes.size(); i++) {
            cout << i + 1 << ". Nome: " << nomes[i] << ", Nota 1: " << notas1[i] << ", Nota 2: " << notas2[i] << endl;
        }

        cout << "Deseja alterar alguma nota (s/n)? ";
        cin >> alterarNota;
        cout << " " << endl;

        if (alterarNota == 's' || alterarNota == 'S') {
            string nomeAluno;
            cout << "Informe o nome do aluno cuja nota será alterada: ";
            cin >> nomeAluno;

            auto it = find(nomes.begin(), nomes.end(), nomeAluno);
            if (it != nomes.end()) {
                int index = distance(nomes.begin(), it);
                cout << "Notas atuais do aluno " << nomeAluno << ": Nota 1 = " << notas1[index] << ", Nota 2 = " << notas2[index] << endl;
                int opcao;
                do {
                    cout << "Alterar a primeira nota (1), a segunda nota (2) ou nenhuma (0)? ";
                    cin >> opcao;
                    if (opcao == 1) {
                        cout << "Informe a nova primeira nota: ";
                        cin >> notas1[index];
                    } else if (opcao == 2) {
                        cout << "Informe a nova segunda nota: ";
                        cin >> notas2[index];
                    }
                } while (opcao != 0);
            } else {
                cout << "Aluno não encontrado." << endl;
            }
        }
    } while (alterarNota == 's' || alterarNota == 'S');

    return 0;
}
