OUT_NAME = app-linux.out

all: ${OUT_NAME}
	./${OUT_NAME}

${OUT_NAME}: main.o camera.o grid.o
	g++ main.o camera.o grid.o -o ${OUT_NAME} -Wall -lpthread -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

camera.o: camera.cpp camera.h
	g++ -c camera.cpp

grid.o: grid.cpp grid.h
	g++ -c grid.cpp