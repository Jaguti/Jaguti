button.o : button.cpp button.h
	g++ -Wall -g -c button.cpp

main.o : main.cpp main.h
	g++ -Wall -g -c main.cpp

element.o : element.cpp element.h
	g++ -Wall -g -c element.cpp

jaguti : button.o main.o element.o
	g++ -g button.o main.o element.o -o jaguti -lSDL -lSDL_image -lSDL_mixer -lGL -lSOIL
	rm main.o button.o element.o


clean :
	rm jaguti
