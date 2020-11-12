# Variables
TIME =$(LOGPATH)$(shell date)
# Variable objetos
OBJECTS = main.o PRF.o
# Flags de compilacion
CFLAGS = -c -std=c++17

FPR: $(OBJECTS)
	g++  $(OBJECTS) -o FPR
	mv *.o ../objects
	mv FPR ../bin

main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

PRF.o: ../src/PRF.cpp ../include/PRF.hpp
	g++ $(CFLAGS) ../src/PRF.cpp



.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*


run:
	../bin/FPR



git:
	git add ../.
	git commit -m "Upload $(TIME)"
	git push
