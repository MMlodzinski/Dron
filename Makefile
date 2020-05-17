TRGDIR=./
OBJ=./obj
FLAGS = -Wall -pedantic -std=c++14 -iquote inc

${TRGDIR}/dron.out: ${OBJ} ${OBJ}/main.o ${OBJ}/Macierz.o ${OBJ}/Wektor3D.o\
		${OBJ}/Obiekty.o ${OBJ}/Dron.o ${OBJ}/Dr3D_gnuplot_api.o -lpthread
	g++ -o ${TRGDIR}zad3.out ${OBJ}/main.o ${OBJ}/Macierz.o ${OBJ}/Wektor3D.o\
		${OBJ}/Obiekty.o ${OBJ}/Dron.o ${OBJ}/Dr3D_gnuplot_api.o -lpthread

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Macierz.o: src/Macierz.cpp inc/Macierz.hh
	g++ -c ${FLAGS} -o ${OBJ}/Macierz.o src/Macierz.cpp

${OBJ}/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh
	g++ -c ${FLAGS} -o ${OBJ}/Wektor3D.o src/Wektor3D.cpp

${OBJ}/Obiekty.o: src/Obiekty.cpp inc/Obiekty.hh
	g++ -c ${FLAGS} -o ${OBJ}/Obiekty.o src/Obiekty.cpp

${OBJ}/Dron.o: src/Dron.cpp inc/Dron.hh
	g++ -c ${FLAGS} -o ${OBJ}/Dron.o src/Dron.cpp

${OBJ}/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh\
		inc/Draw3D_api_interface.hh
	g++ -c ${FLAGS} -o ${OBJ}/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp


clear:
	rm -f ${TRGDIR}/dron ${OBJ}/*


run: ${TRGDIR}dron.out
	${TRGDIR}dron.out
