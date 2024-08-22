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

vector<Livro> Membro::getLivrosEmprestados() const {
    return LivrosEmprestados;
}

// Método único `exibirDados`
void Membro::exibirDados() const {
    cout << "ID: " << ID << "\n";
    cout << "Nome: " << nome << "\n";
    cout << "Livros Emprestados: " << LivrosEmprestados.size() << "\n";
    for (const auto& livro : LivrosEmprestados) {
        livro.exibirDados() ;
    }
}

void Membro::adicionarLivroEmprestado(const Livro& livro) {
    LivrosEmprestados.push_back(livro);
}

void Membro::removerLivroEmprestado(const string& ISBN) {
    for (auto it = LivrosEmprestados.begin(); it != LivrosEmprestados.end(); ++it) {
        if (it->getISBN() == ISBN) {
            LivrosEmprestados.erase(it);
            break;
        }
    }
}
