SRC = main.cpp $(wildcard **/*.cpp)
BUILD_DIR = build
OBJ = $(addprefix ${BUILD_DIR}/, ${SRC:.cpp=.o})
CFLAGS = -O2 -fexceptions

build: ${OBJ}
	g++ ${CFLAGS} -o ${BUILD_DIR}/snake ${OBJ}

clean:
	rm -r build

run: build
	./${BUILD_DIR}/snake

-include ${OBJ:.o=.d}
${BUILD_DIR}/%.o: %.cpp
	@echo building $<
	@mkdir -p $(@D)
	@g++ ${CFLAGS} -c $< -o $@
	@g++ ${CFLAGS} -MM $< > ${BUILD_DIR}/$*.d
#prepend BUILD_DIR to the .d file
	@sed -i '1s;^;${BUILD_DIR}/;' ${BUILD_DIR}/$*.d
