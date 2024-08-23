#include "Biblioteca.h"  
#include <fstream>       
#include <sstream>       
#include <iostream>

void Biblioteca::carregarLivros(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    string linha;

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string isbn, titulo, status;
        
        getline(ss, isbn, ' ');
        getline(ss, titulo, ' ');
        getline(ss, status, ' ');

        Livro livro(isbn, titulo, status);
        livros[isbn] = livro;
    }
    arquivo.close();
}

void Biblioteca::carregarMembros(const string& nomeArquivo) {
    
}

void Biblioteca::registrarLivro(const Livro& livro) {
    livros[livro.getISBN()] = livro;
}

void Biblioteca::registrarMembro(const Membro& membro) {
    membros[membro.getID()] = membro;
}

/*void Biblioteca::gravarLivros(const string& nomeArquivo) const {
    
}

/*void Biblioteca::gravarMembros(const string& nomeArquivo) const {
    
}*/

void Biblioteca::listarLivros() const {
    
}

void Biblioteca::listarMembros() const {
    
}

void Biblioteca::emprestarLivro(const string& isbn, const int idMembro) {
    
}

void Biblioteca::devolverLivro(const string& isbn, const int idMembro) {
    
}