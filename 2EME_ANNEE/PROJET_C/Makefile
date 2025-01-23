CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
EXEC = fourmiliere

SOURCES	= $(SRC_DIR)/main.c $(SRC_DIR)/role_fourmis.c $(SRC_DIR)/Chasse.c $(SRC_DIR)/Cycle_reine.c $(SRC_DIR)/Consommation.c $(SRC_DIR)/initialisation.c $(SRC_DIR)/Simulation.c $(SRC_DIR)/Supprime.c $(SRC_DIR)/arbre_tache.c $(SRC_DIR)/Champs.c
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(EXEC)

$(EXEC): $(OBJECTS)
		$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		-mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR) $(EXEC)

.PHONY: all clean