#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Função de ordenação Bubble Sort para strings
void bubbleSort(vector<string>& nomes) {
    int n = nomes.size();
    
   
for (int i = 0; i < n - 1; ++i) {

        for (int j = 0; j < n - i - 1; ++j) {

            if (nomes[j] > nomes[j + 1]) {
                // Trocar os elementos se estiverem fora de ordem
                swap(nomes[j], nomes[j + 1]);

            }
        }
    }
};


int main() {
    
    int n;
    float nota1, nota2;

    cout << "Digite o numero de alunos: ";
    cin >> n;

    // Vetores para armazenar nomes e notas dos alunos
    vector<string> nomes;
    vector<float> notas1, notas2;
    
    for (int i = 0; i < n; ++i) {
        
        string nome;
        cout << "Digite o nome do aluno " << i + 1 << ": ";
        cin >> nome;

        cout << "Digite a primera nota de " << nome << ": ";
        cin >> nota1; 
        cout << "Digite a degunda nota de " << nome << ": ";
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

return 0;
}