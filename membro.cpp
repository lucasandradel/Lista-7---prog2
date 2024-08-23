#include "Membro.h"

// Construtor com parâmetros
Membro::Membro(const int& ID, const string& nome) : ID(ID), nome(nome) {}

// Getters
int Membro::getID() const {
    return ID;
}

string Membro::getNome() const {
    return nome;
}

vector<string> Membro::getLivrosISBN() const {
    return LivrosEmprestados;
}

void Membro::exibirDados() const {
    cout << "ID: " << ID << "\n";
    cout << "Nome: " << nome << "\n";
    cout << "Livros Emprestados: " << LivrosEmprestados.size() << "\n";
    for (const auto& isbn : LivrosEmprestados) {
        cout << "ISBN: " << isbn << "\n";  // Apenas mostra o ISBN
    }
}

// Métodos para adicionar e remover livros
void Membro::adicionarLivroEmprestado(const string& ISBN) {
    LivrosEmprestados.push_back(ISBN);
}

void Membro::removerLivroEmprestado(const string& ISBN) {
    auto it = remove(LivrosEmprestados.begin(), LivrosEmprestados.end(), ISBN);
    if (it != LivrosEmprestados.end()) {
        LivrosEmprestados.erase(it, LivrosEmprestados.end());
    }
}