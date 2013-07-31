ifeq ($(SHELL), sh.exe)
	CMD_DEL = del /F /Q
else
	CMD_DEL = rm -f
endif
all: bin/mult
	@echo Done
bin/mult: bin/ obj/release/ obj/release/mult.o
	@echo Compilation de bin/mult
	/usr/bin/g++ -fopenmp -s -Wl,--gc-sections -Wl,-O1 -o bin/mult obj/release/mult.o -lm
bin:
	@echo Création du dossier: bin/
	@mkdir bin
obj/release:
	@echo Création du dossier: obj/release/
	@mkdir obj
	@mkdir obj/release
obj/release/mult.o: src/mult.cpp src/mult.hpp
	@echo Compilation de src/mult.cpp
	/usr/bin/g++   -std=c++11 -std=gnu++11 -fopenmp -W -Wall -Wextra -Wdeprecated -Wuninitialized -Wunused-variable -Wvariadic-macros -Wredundant-decls -Wunused-macros -Wundef -Wfloat-equal -Wwrite-strings -Wredundant-decls -Winit-self -Wpointer-arith -Wcast-align -Os -fdata-sections -ffunction-sections -c -pipe src/mult.cpp -o obj/release/mult.o
clean:
	@echo Suppression des fichiers temporaires
	$(CMD_DEL) obj/release/mult.o
exec: bin/mult
	cd bin/ && ./mult
