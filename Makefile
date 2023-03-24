OBJ = main.o terminal.o game.o level.o title_screen.o gamestate.o snake_state.o snake.o
HEADERS = terminal.h game.h level.h title_screen.h gamestate.h snake_state.h snake.h
CFLAGS = -O2 -fexceptions

%.o: %.cpp ${HEADERS}
	g++ ${CFLAGS} -c $< -o $@

build: ${OBJ}
	g++ ${CFLAGS} -o main.exe ${OBJ}

run: build
	./main.exe