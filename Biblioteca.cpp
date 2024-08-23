#include "Biblioteca.h"  
#include <fstream>       
#include <sstream>       
#include <iostream>

void Biblioteca::carregarLivros(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {// Verifica se o arquivo foi aberto com sucesso
        cerr << "\nErro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }else{
        cout << "\nArquivo carregado com sucesso: " << nomeArquivo << endl;
    }

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
    if (!arquivo.is_open()) {
        cerr << "\nErro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    } else {
        cout << "\nArquivo carregado com sucesso: " << nomeArquivo <<  endl;
    }

    string linha;

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        int id;
        string nome;
        string isbn;

        ss >> id >> nome;

        Membro membro(id, nome);


        // Lê os ISBNs dos livros emprestados
        while (ss >> isbn) {
            membro.adicionarLivroEmprestado(isbn);
        }

        membros[id] = membro;

        cout << "\n" << "Membro carregado: ID = " << id << ", Nome = " << nome << endl;
    }

    arquivo.close();
}

void Biblioteca::registrarLivro(const Livro& livro) {

    // Adiciona o livro ao mapa 'livros' com o ISBN como chave
    livros[livro.getISBN()] = livro;
}

void Biblioteca::registrarMembro(const Membro& membro) {
    membros[membro.getID()] = membro;
    cout << "Membro registrado: ID = " << membro.getID() << ", Nome = " << membro.getNome() << endl;
}

void Biblioteca::gravarLivros(const string& nomeArquivo) const {
    ofstream file(nomeArquivo);  // Abre o arquivo para escrita

    if (!file) {
        // Se não foi possível abrir o arquivo, exibe uma mensagem de erro e retorna
        cerr << "Não foi possível abrir o arquivo para gravação de livros.\n";
        return;
    }

    // Itera sobre o mapa de livros
    for (const auto& [isbn, livro] : livros) {
        // Escreve o ISBN, o título e o status do livro no arquivo, separados por espaços
        file << livro.getISBN() << " " << livro.getTitulo() << " " << livro.getStatus() << "\n";
    }

    file.close();  // Fecha o arquivo após a gravação
    cout << "\nArquivo " << nomeArquivo << " gravado com sucesso"  "\n";

}

void Biblioteca::gravarMembros(const string& nomeArquivo) const {
    ofstream file(nomeArquivo);

    if (!file) {
        cerr << "Não foi possível abrir o arquivo para gravação de membros.\n";
        return;
    }

    cout << "\nGravando membros no arquivo " << nomeArquivo << "...\n";
    for (const auto& [id, membro] : membros) {
        file << membro.getID() << " " << membro.getNome();
        
        auto livrosEmprestados = membro.getLivrosISBN();
        for (const auto& isbn : livrosEmprestados) {
            file << " " << isbn;
        }
        
        file << "\n";
        cout << "\nMembro gravado: ID = " << id << ", Nome = " << membro.getNome() << "\n";

    }

    file.close();
    cout << "\nArquivo " << nomeArquivo << " gravado com sucesso\n";
}

void Biblioteca::listarLivros() const {
    for (const auto& [isbn, livro] : livros) {
        livro.exibirDados();
        cout << "-------------------\n";
    }
}

void Biblioteca::listarMembros() const {
    for (const auto& [id, membro] : membros) {
        membro.exibirDados();
        cout << "-------------------\n";
    }
}

void Biblioteca::emprestarLivro(const string& isbn, const int idMembro) {
    if (livros.count(isbn) && livros[isbn].isDisponivel()) {
        if (membros.count(idMembro)) {
            livros[isbn].emprestar();
            membros[idMembro].adicionarLivroEmprestado(isbn);  // Passa o ISBN como string
        } else {
            cerr << "Membro com ID " << idMembro << " não encontrado.\n";
        }
    } else {
        cerr << "Livro com ISBN " << isbn << " não disponível ou não encontrado.\n";
    }
}

void Biblioteca::devolverLivro(const string& isbn, const int idMembro) {
    // Verifica se o membro existe
    if (membros.count(idMembro)) {
        // Verifica se o livro está emprestado ao membro
        auto& membro = membros[idMembro];
        auto livrosEmprestados = membro.getLivrosISBN();
        if (find(livrosEmprestados.begin(), livrosEmprestados.end(), isbn) != livrosEmprestados.end()) {
            // Devolve o livro e remove da lista de livros do membro
            livros[isbn].devolver();
            membro.removerLivroEmprestado(isbn);

            // Atualiza o arquivo de livros após devolver
            gravarLivros("livros.txt");
        } else {
            cerr << "O membro não tem o livro com ISBN " << isbn << " emprestado.\n";
        }
    } else {
        cerr << "Membro com ID " << idMembro << " não encontrado.\n";
    }
}

