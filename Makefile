MODULES = global       \
          application  \
          window       \
          voxel        \
          main
OBJECTS = $(foreach MODULE, ${MODULES}, build/${MODULE}.o)
LIBS    = gl glfw3
CFLAGS  = -O2 -Wall -Wno-unused-result `pkg-config --cflags ${LIBS}` -g
LDFLAGS = `pkg-config --libs ${LIBS}` -lm
EXEC    = voxel

${EXEC}: ${OBJECTS}
	gcc $^ -o $@ ${LDFLAGS}

format:
	astyle -rnNCS *.{c,h}

build/:
	mkdir -p build

build/%.o: src/%.c | build/
	gcc -c $< -o $@ ${CFLAGS}

clean:
	rm -rf build
	rm ${EXEC}