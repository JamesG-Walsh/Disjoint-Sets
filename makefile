CC = g++
H = UandF.h
C = asn2.cpp UandF.cpp
EXEC = asn2
INF = infile

build: ${C} ${H}
	${CC} ${C} -o ${EXEC}

clean:
	@echo "Cleaning up..."
	rm ${EXEC} *.o -v -f

test:
	./${EXEC} < ${INF}

run:
	make clean
	make
	make test
