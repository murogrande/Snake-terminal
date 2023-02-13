OBJ = main.o terminal.o game.o
HEADERS = terminal.h game.h
CFLAGS = -O2 -fexceptions

%.o: %.c ${HEADERS}
	g++ ${CFLAGS} -c $< -o $@

build: ${OBJ}
	g++ -o main.exe ${OBJ}

run: build
	./main.exe