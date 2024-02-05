# Nome do arquivo executável
TARGET = trab

# Lista de arquivos fonte
SOURCES = main.c ordenacao.c

# Lista de arquivos objeto gerados pela compilação
OBJECTS = $(SOURCES:.c=.o)

# Comando de compilação
CC = gcc

# Opções de compilação
CFLAGS = -Wall -g -I\MinGW\lib\gcc\mingw32\6.3.0\include -Wl,--stack,16777216

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS)  -finput-charset=UTF-8 -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
