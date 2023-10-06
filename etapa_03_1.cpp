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
            cout << " " << endl;
            
            cout << "Aluno adicionado com sucesso." << endl;
        }
        cout << " " << endl;

        cout << "Deseja incluir mais alunos (s/n)? ";
        cin >> continuar;
        cout << " " << endl;

    } while (continuar == 's' || continuar == 'S');

    do {
        cout << "\nLista de Alunos:\n";
        for (size_t i = 0; i < nomes.size(); i++) {
            cout << i + 1 << ". Nome: " << nomes[i] << ", Nota 1: " << notas1[i] << ", Nota 2: " << notas2[i] << endl;
        }

        

        cout << "Deseja excluir algum aluno (s/n)? ";
        cin >> continuar;
        cout << " " << endl;

        if (continuar == 's' || continuar == 'S') {
            int indice;
            cout << "Informe o número do aluno a ser excluído: ";
            cin >> indice;

            cout << " " << endl;

            if (indice >= 1 && indice <= static_cast<int>(nomes.size())) {
                nomes.erase(nomes.begin() + (indice - 1));
                notas1.erase(notas1.begin() + (indice - 1));
                notas2.erase(notas2.begin() + (indice - 1));
                cout << "Aluno excluído com sucesso." << endl;
            } else {
                cout << "Número de aluno inválido." << endl;
            }
        }
    } while (continuar == 's' || continuar == 'S');

    return 0;
}
