OBJ = main.o terminal.o game.o level.o title_screen.o snake_game.o gamestate.o
HEADERS = terminal.h game.h level.h title_screen.h snake_game.h gamestate.h signals.h
CFLAGS = -O2 -fexceptions

%.o: %.cpp ${HEADERS}
	g++ ${CFLAGS} -c $< -o $@

build: ${OBJ}
	g++ ${CFLAGS} -o main.exe ${OBJ}

run: build
	./main.exe