button.o : button.cpp button.h
	g++ -Wall -g -c button.cpp

main.o : main.cpp main.h
	g++ -Wall -g -c main.cpp

element.o : element.cpp element.h
	g++ -Wall -g -c element.cpp

jaguti : button.o main.o
	g++ -g button.o main.o -o jaguti -lSDL -lSDL_image -lSDL_mixer
	rm main.o button.o

clean :
	rm jaguti
