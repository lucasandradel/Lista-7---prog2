#ifndef MEMBRO_H__
#define MEMBRO_H__

#include <string>
#include <iostream>
#include <vector>
#include "Livro.h"

using namespace std;

class Membro {
private:
    int ID;
    string nome;
    vector<Livro> LivrosEmprestados;

public:
    // Construtor padrão
    Membro() = default;

    // Construtor com parâmetros
    Membro(const int& ID, const string& nome);

    // Getters
    int getID() const;
    string getNome() const;
    vector<Livro> getLivrosEmprestados() const;

    // Métodos
    void exibirDados() const;
    void adicionarLivroEmprestado(const Livro& livro);
    void removerLivroEmprestado(const string& ISBN);
};

#endif // MEMBRO_H__
