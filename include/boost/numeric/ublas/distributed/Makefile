CFLAGS = -std=c++11 -std=gnu++0x -fopenmp -W -Wall -Wextra -Wdeprecated -Wuninitialized -Wunused-variable -Wvariadic-macros -Wredundant-decls -Wunused-macros -Wundef -Wwrite-strings -Wredundant-decls -Winit-self -Wpointer-arith -Wcast-align -ggdb3
LDFLAGS = -ggdb3
INCLUDES_DIR = -Isrc -isystem /usr/include/mpi
LIBS = -lboost_mpi -lboost_serialization -lmpi -lmpi_cxx -fopenmp
CXX = /usr/bin/g++
DEFINED =
ifeq ($(SHELL), sh.exe)
	CMD_DEL = del /F /Q
	FINAL_NAME = test
else
	CMD_DEL = rm -f
	FINAL_NAME = test
endif


all: bin/$(FINAL_NAME)
	@echo Done
bin/$(FINAL_NAME): bin obj/release obj/release/Controller.o obj/release/MaestroController.o obj/release/SlaveController.o obj/release/main.o
	@echo Compilation de bin/$(FINAL_NAME)
	$(CXX) $(CFLAGS) $(DEFINED) $(LDFLAGS) -o bin/$(FINAL_NAME) obj/release/Controller.o obj/release/MaestroController.o obj/release/SlaveController.o obj/release/main.o $(LIBS)
bin:
	@echo Création du dossier: bin/
	@mkdir bin
obj/release:
	@echo Création du dossier: obj/release/
	@mkdir obj
	@mkdir obj/release
obj/release/Controller.o: Controller.cpp Controller.hpp Pipe.hpp MaestroController.hpp debug.h
	@echo Compilation de Controller.cpp
	$(CXX) $(DEFINED) $(INCLUDES_DIR) $(CFLAGS) -c -pipe Controller.cpp -o obj/release/Controller.o
obj/release/MaestroController.o: MaestroController.cpp MaestroController.hpp SlaveController.hpp Pipe.hpp debug.h
	@echo Compilation de MaestroController.cpp
	$(CXX) $(DEFINED) $(INCLUDES_DIR) $(CFLAGS) -c -pipe MaestroController.cpp -o obj/release/MaestroController.o
obj/release/SlaveController.o: SlaveController.cpp SlaveController.hpp Pipe.hpp MaestroController.hpp debug.h
	@echo Compilation de SlaveController.cpp
	$(CXX) $(DEFINED) $(INCLUDES_DIR) $(CFLAGS) -c -pipe SlaveController.cpp -o obj/release/SlaveController.o
obj/release/main.o: main.cpp SampleDouble.hpp Controller.hpp Pipe.hpp debug.h MaestroController.hpp matrix.hpp
	@echo Compilation de main.cpp
	$(CXX) $(DEFINED) $(INCLUDES_DIR) $(CFLAGS) -c -pipe main.cpp -o obj/release/main.o
clean:
	@echo Suppression des fichiers temporaires
	$(CMD_DEL) obj/release/Controller.o obj/release/MaestroController.o obj/release/SlaveController.o obj/release/main.o
exec: bin/$(FINAL_NAME)
ifeq ($(SHELL), sh.exe)
	cd bin/ && mpirun -machinefile hostfile -np 2 $(FINAL_NAME)
else
	cd bin/ && mpirun -machinefile hostfile -np 2 ./$(FINAL_NAME)
endif
