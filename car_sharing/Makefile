# Nome dell'eseguibile
TARGET = car_sharing

# Compilatore
CC = gcc

# Flag di compilazione
CFLAGS = -Wall

# File oggetto
OBJS = main.o veicoli.o prenotazioni.o

# Regola principale
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regole per i singoli file .c
main.o: main.c veicoli.h prenotazioni.h
	$(CC) $(CFLAGS) -c main.c

veicoli.o: veicoli.c veicoli.h
	$(CC) $(CFLAGS) -c veicoli.c

prenotazioni.o: prenotazioni.c prenotazioni.h
	$(CC) $(CFLAGS) -c prenotazioni.c

# Pulizia dei file oggetto e dell'eseguibile
clean:
	rm -f *.o $(TARGET)

# Compilazione con flag di debug
debug: CFLAGS += -g
debug: $(TARGET)

.PHONY: clean debug
