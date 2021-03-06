#Makefile for "Análise empírica de dados" C++ aplication
#Created by Ygor Bastos, Luís Eduardo Silva, Airton Correia e Dionísio Carvalho

# Comandos do sistema operacional
# Linux: rm -rf
# Windows: cmd //C del
RM = rm -rf

# Compilador
CC = g++

# Variaveis para os subdiretorios
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./build
BIN_DIR = ./bin

# Outras variaveis

# Opcoes de compilacao
CFLAGS = -Wall -ansi -std=c++11 -I. -I$(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: clean lab01
debug: CFLAGS += -g -O0
debug: clean lab01

# Alvo (target) para a construcao do executavel lab01
# Define os arquivos lab01.o como dependencias
lab01: $(OBJ_DIR)/lab01.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel lab01 criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto lab01.o
# Define o arquivo lab01.cpp e search_sort.h como dependencias.
$(OBJ_DIR)/lab01.o: $(SRC_DIR)/lab01.cpp $(INC_DIR)/search_sort.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
