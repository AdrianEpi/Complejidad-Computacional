# Variables
TIME =$(LOGPATH)$(shell date)
# Variable objetos
OBJECTS = main.o alphabet.o stack.o
# Flags de compilacion
CFLAGS = -c -std=c++17

AP: $(OBJECTS)
	g++  $(OBJECTS) -o AP
	mv *.o ../objects
	mv AP ../bin

main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

alphabet.o: ../src/alphabet.cpp ../include/alphabet.hpp
	g++ $(CFLAGS) ../src/alphabet.cpp

stack.o: ../src/stack.cpp ../include/stack.hpp
	g++ $(CFLAGS) ../src/stack.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*


run:
	../bin/AP



git:
	git add ../.
	git commit -m "Upload $(TIME)"
	git push
