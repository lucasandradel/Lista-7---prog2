# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -std=c++11 -Wall -g

# Nome do executável
TARGET = main

# Arquivos fonte
SRCS = main.cpp Biblioteca.cpp Livro.cpp Membro.cpp

# Arquivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regra para compilar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Regra para compilar arquivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar arquivos objeto e executáveis
clean:
	rm -f $(OBJS) $(TARGET)
