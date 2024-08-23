# Variáveis de compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Diretivas de arquivos
TARGET = main
OBJECTS = main.o livro.o membro.o Biblioteca.o
HEADERS = livro.h membro.h Biblioteca.h

# Regra padrão
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regras para gerar arquivos .o a partir dos .cpp
main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp

livro.o: livro.h livro.h
	$(CXX) $(CXXFLAGS) -c livro.cpp

membro.o: membro.cpp membro.h
	$(CXX) $(CXXFLAGS) -c membro.cpp

Biblioteca.o: Biblioteca.cpp Biblioteca.h
	$(CXX) $(CXXFLAGS) -c Biblioteca.cpp

# Limpeza dos arquivos temporários
clean:
	rm -f $(TARGET) $(OBJECTS)

# Limpeza total, incluindo os arquivos de backup
cleanall: clean
	rm -f *~
