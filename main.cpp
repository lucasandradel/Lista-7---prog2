#include <iostream>
#include "Biblioteca.h"

using namespace std;

int main() {
    Biblioteca biblioteca;

    // Carregar dados iniciais
    biblioteca.carregarLivros("data/livros.txt");
    biblioteca.carregarMembros("data/membros.txt");

    int opcao;
    do {
        cout << "Menu:\n";
        cout << "1. Registrar livro\n";
        cout << "2. Registrar membro\n";
        cout << "3. Listar livros\n";
        cout << "4. Listar membros\n";
        cout << "5. Emprestar livro\n";
        cout << "6. Devolver livro\n";
        cout << "7. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                string isbn, titulo;
                cout << "ISBN: ";
                cin >> isbn;
                cout << "Titulo: ";
                cin >> titulo;
                Livro livro(isbn, titulo, "Disponível");
                biblioteca.registrarLivro(livro);
                break;
            }
            
                
        }

    } while (opcao != 7);

    return 0;
}
