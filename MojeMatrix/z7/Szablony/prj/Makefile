#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: uklad_rownan
	./uklad_rownan
uklad_rownan: obj/main.o  obj/LZespolona.o obj/parametry.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/LZespolona.o obj/parametry.o

obj/main.o: src/main.cpp inc/UkladRownanLiniowych.hh inc/Macierz.hh inc/Wektor.hh\
        inc/parametry.hh inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/parametry.o: src/parametry.cpp inc/parametry.hh
	g++ ${CPPFLAGS} -o obj/parametry.o src/parametry.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

clean:
	rm -f obj/*.o uklad_rownan
