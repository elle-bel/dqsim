CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror=vla -MMD -g
EXEC = dqsim
OBJECTS = enemies.o heroes.o luminary.o weapon.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	del ${OBJECTS} ${EXEC}.exe ${DEPENDS}