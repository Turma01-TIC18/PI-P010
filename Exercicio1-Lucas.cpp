#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int limiteAlunos;
    cout << "Informe o limite de alunos: ";
    cin >> limiteAlunos;

    vector<string> nomes;
    vector<float> notas1;
    vector<float> notas2;

    for (int i = 0; i < limiteAlunos; ++i) {
        string nome;
        float nota1, nota2;

        cout << "Informe o nome do aluno " << i + 1 << ": ";
        cin.ignore(); 
        getline(cin, nome);

        cout << "Informe a primeira nota do aluno " << i + 1 << ": ";
        cin >> nota1;

        cout << "Informe a segunda nota do aluno " << i + 1 << ": ";
        cin >> nota2;

        nomes.push_back(nome);
        notas1.push_back(nota1);
        notas2.push_back(nota2);

        if (i == limiteAlunos - 1) {
            cout << "Limite de alunos atingido." << endl;
            break;
        }

        char continuar;
        cout << "Deseja inserir outro aluno? (S/N): ";
        cin >> continuar;
        if (continuar != 'S' && continuar != 's') {
            break;
        }
    }

    cout << "Lista de alunos e suas notas:" << endl;
    for (int i = 0; i < nomes.size(); ++i) {
        cout << "Aluno " << i + 1 << ": " << nomes[i] << " - Nota 1: " << notas1[i] << " - Nota 2: " << notas2[i] << endl;
    }

    return 0;
}
