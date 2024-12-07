CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror=vla -MMD -g
EXEC = dqsim
OBJECTS = enemies.o luminary.o heroes.o weapon.o spelltypes.o spells.o main.o
VPATH=Entities: Entities/Heroes: BattleActions:
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	del ${OBJECTS} ${EXEC}.exe ${DEPENDS}