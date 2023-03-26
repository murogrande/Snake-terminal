SRC = $(wildcard *.cpp)
OBJ = ${SRC:.cpp=.o}
CFLAGS = -O2 -fexceptions

%.o: %.cpp
	g++ ${CFLAGS} -c $< -o $@

build: ${OBJ}
	g++ ${CFLAGS} -o main.exe ${OBJ}

run: build
	./main.exe