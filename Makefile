# Jaguti's Makefile

button.o : button.cpp button.h
	g++ -Wall -g -c button.cpp -std=c++11 -pthread

main.o : main.cpp main.h
	$(shell) ./SOILpatch.sh
	g++ -Wall -g -c main.cpp -std=c++11 -pthread

element.o : element.cpp element.h
	g++ -Wall -g -c element.cpp -std=c++11 -pthread 

render.o : render.cpp
	g++ -Wall -g -c render.cpp -std=c++11 -pthread

oldjaguti : main.o button.o element.o render.o
	g++ -g button.o main.o element.o -o jaguti -lSDL -lSDL_image -lSDL_mixer -lGL -lSOIL 
	rm main.o button.o element.o

jaguti : main.o render.o
	g++ -Wall -g main.o render.o -o jaguti -lSDL -lSDL_image -lGL -lSOIL
	rm main.o render.o


clean :
	rm jaguti
