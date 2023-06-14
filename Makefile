OUT_NAME = app-linux.out

all: ${OUT_NAME}
	./${OUT_NAME}

${OUT_NAME}: main.o camera.o grid.o debugText.o rectangle.o scene.o flower.o
	g++ main.o camera.o grid.o debugText.o rectangle.o scene.o flower.o -o ${OUT_NAME} -Wall -lpthread -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp camera.hpp grid.hpp debugText.hpp scene.hpp rectangle.hpp flower.hpp
	g++ -c main.cpp

camera.o: camera.cpp camera.hpp
	g++ -c camera.cpp

grid.o: grid.cpp grid.hpp
	g++ -c grid.cpp

debugText.o: debugText.cpp debugText.hpp
	g++ -c debugText.cpp

scene.o: scene.cpp scene.hpp object.hpp
	g++ -c scene.cpp

rectangle.o: rectangle.cpp rectangle.hpp object.hpp
	g++ -c rectangle.cpp

flower.o: flower.cpp flower.hpp object.hpp
	g++ -c flower.cpp
