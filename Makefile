SRC = $(wildcard *.cpp)
BUILD_DIR = build
OBJ = $(addprefix ${BUILD_DIR}/, ${SRC:.cpp=.o})
CFLAGS = -O2 -fexceptions

-include ${OBJ:.o=.d}

${BUILD_DIR}/%.o: %.cpp
	mkdir -p $(@D)
	g++ ${CFLAGS} -c $< -o $@
	g++ ${CFLAGS} -MM $< > ${BUILD_DIR}/$*.d
	sed -i '1s;^;${BUILD_DIR}/;' ${BUILD_DIR}/$*.d

build: ${OBJ}
	g++ ${CFLAGS} -o build/snake ${OBJ}

run: build
	./build/snake

clean:
	rm -r build