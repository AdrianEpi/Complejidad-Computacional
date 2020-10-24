# Variables
TIME =$(LOGPATH)$(shell date)
# Variable objetos
OBJECTS = main.o alphabet.o tape.o transition.o state.o turingMachine.o
# Flags de compilacion
CFLAGS = -c -std=c++17

TM: $(OBJECTS)
	g++  $(OBJECTS) -o TM
	mv *.o ../objects
	mv TM ../bin

main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

alphabet.o: ../src/alphabet.cpp ../include/alphabet.hpp
	g++ $(CFLAGS) ../src/alphabet.cpp

tape.o: ../src/tape.cpp ../include/tape.hpp
	g++ $(CFLAGS) ../src/tape.cpp

transition.o: ../src/transition.cpp ../include/transition.hpp
	g++ $(CFLAGS) ../src/transition.cpp

state.o: ../src/state.cpp ../include/state.hpp
	g++ $(CFLAGS) ../src/state.cpp

turingMachine.o: ../src/turingMachine.cpp ../include/turingMachine.hpp
	g++ $(CFLAGS) ../src/turingMachine.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*


run:
	../bin/TM



git:
	git add ../.
	git commit -m "Upload $(TIME)"
	git push
