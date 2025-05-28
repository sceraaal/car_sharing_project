CC = gcc
CFLAGS = -Wall -Wextra -g

# Sorgenti principali
MAIN_SRC = main.c veicoli.c prenotazioni.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)
MAIN_EXE = carsharing

# Sorgenti test
TEST_SRC = test.c veicoli_test.c prenotazioni_test.c veicoli.c prenotazioni.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_EXE = testcarsharing

# Target di default
all: $(MAIN_EXE) $(TEST_EXE)

# Compilazione programma principale
$(MAIN_EXE): $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ)

# Compilazione test
$(TEST_EXE): $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJ)

# Regole di compilazione generiche per .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia file compilati
clean:
	rm -f *.o $(MAIN_EXE) $(TEST_EXE)

.PHONY: all clean