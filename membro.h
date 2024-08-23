#ifndef MEMBRO_H__
#define MEMBRO_H__

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Membro {
private:
    int ID;
    string nome;
    vector<string> LivrosEmprestados;  // Armazena apenas o ISBN dos livros emprestados

public:
    // Construtor padrão
    Membro() = default;

    // Construtor com parâmetros
    Membro(const int& ID, const string& nome);

    // Getters
    int getID() const;
    string getNome() const;
    vector<string> getLivrosISBN() const;

    // Métodos
    void exibirDados() const;
    void adicionarLivroEmprestado(const string& ISBN);  // Aceita o ISBN diretamente
    void removerLivroEmprestado(const string& ISBN);
};

#endif // MEMBRO_H__
