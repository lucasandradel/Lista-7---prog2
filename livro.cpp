#include "Livro.h"

// Construtor com parâmetros
Livro::Livro(const string& ISBN, const string& Titulo, const string& disponivel): ISBN(ISBN), Titulo(Titulo), disponivel(disponivel == "Emprestado") {}

// Getters
string Livro::getISBN() const {
    return ISBN;
}

string Livro::getTitulo() const {
    return Titulo;
}

bool Livro::isDisponivel() const {
    return disponivel;
}

// Métodos
void Livro::emprestar() {
    if (disponivel) {
        disponivel = false;
    } else {
        cout << "Livro já está emprestado." << endl;
    }
}

void Livro::devolver() {
    disponivel = true;
}

void Livro::exibirDados() const { 
    cout << "ISBN: " << ISBN << "\n";
    cout << "Titulo: " << Titulo << "\n";
    if (disponivel) {
        cout << "Livro Disponível\n";
    } else {
        cout << "Livro Indisponível\n";
    }
}
