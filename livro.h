#ifndef LIVRO_H__
#define LIVRO_H__

#include <string>
#include <iostream>

using namespace std;

class Livro {
private:
    string ISBN;
    string Titulo;
    bool disponivel;

public:
    // Construtor padrão
    Livro() = default;

    // Construtor com parâmetros
    Livro(const string& ISBN, const string& Titulo, const string& status);

    // Getters
    string getISBN() const;
    string getTitulo() const;
    string getStatus() const;  // retornar o status como string
    bool isDisponivel() const;

    // Métodos
    void emprestar();
    void devolver();
    void exibirDados() const;  
};

#endif // LIVRO_H__
