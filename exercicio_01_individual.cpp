#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
   
    cout << "Informe o limite de alunos (N): ";
    cin >> N;

    vector<string> nomes;
    vector<float> notas1;
    vector<float> notas2;

    for (int i = 0; i < N; ++i) {
        string nome;
        float nota1, nota2;

        cout << "Informe o nome do aluno " << i + 1 << ": ";
        cin >> nome;

        cout << "Informe a primeira nota do aluno " << nome << ": ";
        cin >> nota1;

        cout << "Informe a segunda nota do aluno " << nome << ": ";
        cin >> nota2;

        nomes.push_back(nome);
        notas1.push_back(nota1);
        notas2.push_back(nota2);
    }

    cout << "\nLista de alunos e suas médias:" << endl;

    cout << " " << endl;

    for (int i = 0; i < N; ++i) {
        float media = (notas1[i] + notas2[i]) / 2.0;
        cout << nomes[i] << ": Nota 1 = " << notas1[i] << ", Nota 2 = " << notas2[i] << ", Média = " << media << endl;
    }

    cout << " " << endl;
    
    return 0;
}