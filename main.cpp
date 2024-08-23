#include <iostream>
#include "Biblioteca.h"

using namespace std;

int main() {
    Biblioteca biblioteca;

    // Carregar dados iniciais
    biblioteca.carregarLivros("livros.txt");
    biblioteca.carregarMembros("membros.txt");

    biblioteca.gravarLivros("livros.txt");
    biblioteca.gravarMembros("membros.txt");

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
        cout<<"\n";

        switch (opcao) {
            case 1: {
                string isbn, titulo;
                cout << "ISBN: ";
                cin >> isbn;
                cout << "Titulo: ";
                cin >> titulo;
                Livro livro(isbn, titulo, "Disponível");
                biblioteca.registrarLivro(livro);
                biblioteca.gravarLivros("livros.txt");
                break;
            }
            case 2: {
                int id;
                string nome;
                cout << "ID: ";
                cin >> id;
                cout << "Nome: ";
                cin >> nome;
                Membro membro(id, nome);
                biblioteca.registrarMembro(membro);
                biblioteca.gravarMembros("membros.txt");

                break;
            }
            case 3:
                biblioteca.listarLivros();
                break;
            case 4:
                biblioteca.listarMembros();
                break;
            case 5: {
                string isbn;
                int idMembro;
                cout << "ISBN do Livro: ";
                cin >> isbn;
                cout << "ID do Membro: ";
                cin >> idMembro;
                biblioteca.emprestarLivro(isbn, idMembro);
                break;
            }
            case 6: {
                string isbn;
                int idMembro;
                cout << "ISBN do Livro: ";
                cin >> isbn;
                cout << "ID do Membro: ";
                cin >> idMembro;
                biblioteca.devolverLivro(isbn, idMembro);
                break;
            }
            case 7:
                biblioteca.gravarLivros("livros.txt");
                biblioteca.gravarMembros("membros.txt");
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }

    } while (opcao != 7);

    return 0;
}
