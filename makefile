CC = g++
H = UandF.h Node.h
C = asn2.cpp UandF.cpp Node.cpp
EXEC = asn2
INF = infile

build: ${C} ${H}
	${CC} ${C} -o ${EXEC}

clean:
	@echo "Cleaning up..."
	rm -v -f ${EXEC} *.o

test:
	./${EXEC} ${INF}

run:
	make clean
	make
	make test
