#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int limites;
   
    cout << "Digite o limite de alunos: ";
    cin >> limites;

    vector<string> nomes;
    vector<float> notas1;
    vector<float> notas2;

    for (int i = 0; i < limites; ++i) {
        string nome;
        float nota1, nota2;

        cout << "Digite o nome do aluno " << i + 1 << ": ";
        getline(cin >> ws, nome);

        cout << "Digite a primeira nota do aluno " << nome << ": ";
        cin >> nota1;

        cout << "Digite a segunda nota do aluno " << nome << ": ";
        cin >> nota2;

        nomes.push_back(nome);
        notas1.push_back(nota1);
        notas2.push_back(nota2);
    }

    cout << "\nLista de alunos e suas medias:" << endl;

    cout << " " << endl;

    for (int i = 0; i < limites; ++i) {
        float media = (notas1[i] + notas2[i]) / 2.0;
        cout << nomes[i] << ": Nota 1 = " << notas1[i] << ", Nota 2 = " << notas2[i] << ", Media = " << media << endl;
    }

    cout << " " << endl;
    

    cout << "\nResultados dos alunos:\n";
    for (int i = 0; i < limites; i++) {
        float media = (notas1[i] + notas2[i]) / 2.0;
        cout << "Aluno: " << nomes[i] << endl;
        cout << "Nota 1: " << notas1[i] << endl;
        cout << "Nota 2: " << notas2[i] << endl;
        cout << "Media: " << media << endl;
        if (media >= 7.0) {
            cout << "Situacao: Aprovado\n";
        } else {
            cout << "Situacao: Reprovado\n";
        }
        cout << "-----------------------------------\n";
    }

    return 0;
}