#compile and link the application
all: main

#run the application
run: main
	./main

#link everything to lab1
main: main.o student.o DomesticStudent.o internationalStudent.o toeflScore.o nodeClass.o linkFunction.o
	g++ -g -o main main.o student.o DomesticStudent.o internationalStudent.o toeflScore.o nodeClass.o linkFunction.o

#compile main.cpp
main.o: main.cpp
	g++ -g -c main.cpp

#compile student.hpp, student.cpp
student.o: student.cpp
	g++ -g -c student.cpp
	
#compile DomesticStudent.hpp DomesticStudent.cpp
DomesticStudent.o: DomesticStudent.cpp
	g++ -g -c DomesticStudent.cpp

#compile internationalStudent.hpp internationalStudent.cpp
internationalStudent.o: internationalStudent.cpp
	g++ -g -c internationalStudent.cpp
	
#compile toeflScore.hpp toeflScore.hpp
toeflScore.o: toeflScore.cpp
	g++ -g -c toeflScore.cpp
	
#compile nodeClass.hpp nodeClass.cpp
nodeClass.o: nodeClass.cpp
	g++ -g -c nodeClass.cpp

#compile linkFunction.hpp linkFunction.cpp
linkFunction.o: linkFunction.cpp
	g++ -g -c linkFunction.cpp
	
#clean regular files
clean:
	rm -rf main main.o student.o DomesticStudent.o internationalStudent.o toeflScore.o nodeClass.o linkFunction.o

#clean debug mode files
debugclean:
	rm -rf debug TestMain.o student.o internationalStudent.o DomesticStudent.o toeflScore.o nodeClass.o linkFunction.o unittests.o

#run debug version
rundebug: debug
	./debug

#links unittests an main
debug: TestMain.o unittests.o student.o internationalStudent.o toeflScore.o DomesticStudent.o nodeClass.o linkFunction.o
	g++ -g -lm -o debug TestMain.o unittests.o student.o internationalStudent.o toeflScore.o DomesticStudent.o nodeClass.o linkFunction.o

#compile unittests
unittests.o: unittests.cpp
	g++ -g -c unittests.cpp

#compiles debug main
TestMain.o: TestMain.cpp
	g++ -g -c TestMain.cpp
