main.o : main.cpp main.h
	g++ -Wall -g -c main.cpp

button.o : button.cpp button.h
	g++ -Wall -g -c button.cpp

jaguti : main.o button.o
	g++ -g main.o button.o -o jaguti -lSDL -lSDL_image -lSDL_mixer
	rm main.o button.o

clean :
	rm jaguti
