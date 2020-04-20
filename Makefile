CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = chess
OBJECTS = main.o pieces/Piece.o pieces/Pawn.o pieces/Bishop.o pieces/Knight.o pieces/Rook.o pieces/King.o pieces/Queen.o Board.o Boardstatus.o Computer.o Game.o Human.o Player.o Scoreboard.o Side.o conversion.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
		${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

