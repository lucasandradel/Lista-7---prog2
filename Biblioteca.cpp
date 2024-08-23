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
        
        // Extrai o ISBN, o título e o status da linha, separados por espaços
        getline(ss, isbn, ' ');
        getline(ss, titulo, ' ');
        getline(ss, status, ' ');

        Livro livro(isbn, titulo, status);
        livros[isbn] = livro;
    }
    arquivo.close();
}

void Biblioteca::carregarMembros(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);  
    if (!arquivo.is_open()) {// Verifica se o arquivo foi aberto com sucesso
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return;
    }

    string linha;

    // Lê o arquivo linha por linha
    while (getline(arquivo, linha)) {
        stringstream ss(linha);  // Cria um fluxo de string para a linha lida
        int id;
        string nome;

        // Lê o ID, o nome e o sobrenome da linha, separados por espaços
        ss >> id >> nome;

        // Cria um objeto Membro com os dados extraídos
        Membro membro(id, nome);
        // Adiciona o membro ao mapa 'membros' com o ID como chave
        membros[id] = membro;

         arquivo.close();  // Fecha o arquivo após a leitura

    }
}

void Biblioteca::registrarLivro(const Livro& livro) {

    // Adiciona o livro ao mapa 'livros' com o ISBN como chave
    livros[livro.getISBN()] = livro;
}

void Biblioteca::registrarMembro(const Membro& membro) {

    // Adiciona o membro ao mapa 'membros' com o ID como chave
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