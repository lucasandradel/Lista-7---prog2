#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <map>
#include <string>
#include "Livro.h"
#include "Membro.h"

class Biblioteca {
public:
    // Métodos para carregar dados
    void carregarLivros(const string& nomeArquivo);
    void carregarMembros(const string& nomeArquivo);

    // Métodos para registrar
    void registrarLivro(const Livro& livro);
    void registrarMembro(const Membro& membro);

    // Métodos para gravar dados
    void gravarLivros(const string& nomeArquivo) const;
    void gravarMembros(const string& nomeArquivo) const;

    // Métodos para listar
    void listarLivros() const;
    void listarMembros() const;

    // Métodos de empréstimo e devolução
    void emprestarLivro(const string& isbn, const int idMembro);
    void devolverLivro(const string& isbn, const int idMembro);

private:
    map<string, Livro> livros; // Mapa de livros, com ISBN como chave
    map<int, Membro> membros;       // Mapa de membros, com ID como chave
};

#endif // BIBLIOTECA_H
