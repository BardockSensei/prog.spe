CC = g++
OPTIONS = -g -Wall # Option -g pour avoir les infos de débogage
EXECUTABLE = out/tp2

# Obtient la liste des fichiers source .cpp dans le répertoire /src
SOURCES = $(wildcard src/*.cpp)

# Obtient la liste des fichiers objet correspondant dans le répertoire /out
OBJECTS = $(patsubst src/%.cpp, out/%.o, $(SOURCES))

# Règle par défaut pour construire l'exécutable dans le répertoire /out (s'il existe)
$(EXECUTABLE): | out $(OBJECTS)
	$(CC) $(OPTIONS) -o $(EXECUTABLE) $(OBJECTS)

# Règle pour créer le répertoire /out s'il n'existe pas
out:
	mkdir -p out

# Règle générique pour construire les fichiers objets dans le répertoire /out
out/%.o: src/%.cpp
	$(CC) $(OPTIONS) -c $< -o $@

# Nettoyage des fichiers .o, .exe
clean :
	rm -f $(EXECUTABLE)
	rm -f out/*.o
