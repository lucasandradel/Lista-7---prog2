#include "Biblioteca.h"  // Inclui o cabeçalho da classe Biblioteca, onde estão as declarações dos métodos e membros
#include <fstream>       // Inclui a biblioteca para manipulação de arquivos
#include <sstream>       // Inclui a biblioteca para manipulação de strings como fluxos de entrada/saída
#include <iostream>

// Métodos para carregar dados

/**
 * Carrega os dados dos livros a partir de um arquivo e armazena no mapa de livros.
 * @param nomeArquivo Nome do arquivo contendo os dados dos livros.
 * @param livros Mapa onde os livros serão armazenados.
 */
void Biblioteca::carregarLivros(const string& nomeArquivo, map<string, Livro>& livros) {
    ifstream file(nomeArquivo);  // Abre o arquivo para leitura com o nome fornecido
    string isbn, titulo, status; // Declara variáveis para armazenar dados lidos do arquivo

    if (!file) {  // Verifica se o arquivo foi aberto com sucesso
        cerr << "Não foi possível abrir o arquivo de livros.\n"; // Exibe mensagem de erro se não conseguir abrir o arquivo
        return; // Sai da função se o arquivo não puder ser aberto
    }

    while (getline(file, isbn)) { // Lê o ISBN do livro da linha do arquivo
        getline(file, titulo);    // Lê o título do livro da linha do arquivo
        getline(file, status);    // Lê o status do livro (disponível ou emprestado) da linha do arquivo

        livros[isbn] = Livro(isbn, titulo, status); // Adiciona o livro ao mapa com o ISBN como chave
    }
}
