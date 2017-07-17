CXX=g++-5
CXXFLAGS=-std=c++14 -Wall -Werror=vla -MMD
OBJECTS=main.o exception.o ppmArray.o image.o basic.o decorator.o flip.o rotate.o sepia.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=a4q3


${EXEC}:${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm *.o a4q3
.PHONY: clean
