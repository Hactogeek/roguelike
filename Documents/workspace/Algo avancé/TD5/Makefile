CC=gcc
OBJ=maxi.o maxi_test.o
CFLAG= -Wall 
EXEC=maxi_test

maxi_test: ${OBJ}
	${CC} -o ${EXEC} ${OBJ} ${CFLAGS} -lcunit
	
maxi.o: maxi.c maxi.h
	${CC} -c maxi.c ${CFLAGS}
	
maxi_test.o: maxi_test.c maxi.h
	${CC} -c maxi_test.c ${CFLAGS}
	
clean:
	rm -i *.o
	
