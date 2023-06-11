OUT_NAME = app-linux.out

all: ${OUT_NAME}
	./${OUT_NAME}

${OUT_NAME}: main.cpp
	g++ main.cpp -o ${OUT_NAME} -Wall -lpthread -lsfml-graphics -lsfml-window -lsfml-system