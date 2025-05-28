CC = gcc
CFLAGS = -Wall -Wextra -Isorgenti

SRC = sorgenti/main.c sorgenti/veicoli.c sorgenti/prenotazioni.c
OBJ = $(SRC:sorgenti/%.c=build/%.o)

TEST_SRC = sorgenti/test.c sorgenti/veicoli_test.c sorgenti/prenotazioni_test.c sorgenti/veicoli.c sorgenti/prenotazioni.c
TEST_OBJ = $(TEST_SRC:sorgenti/%.c=build/%.o)

EXEC = eseguibili/car_sharing.exe
TEST_EXEC = eseguibili/test_car_sharing.exe

.PHONY: all clean test dirs

all: dirs $(EXEC)

dirs:
	if not exist build mkdir build
	if not exist eseguibili mkdir eseguibili

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_EXEC): $(TEST_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

test: dirs $(TEST_EXEC)
	.\$(TEST_EXEC)

# Regola generica per compilare i .c in build/
build/%.o: sorgenti/%.c | dirs
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q build\*.o eseguibili\*.exe 2>nul
	rmdir /S /Q build 2>nul
	rmdir /S /Q eseguibili 2>nul


  