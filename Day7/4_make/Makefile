CXX = g++
NAME = fancy
all: main.o liba.a  b.o
	$(CXX) main.o liba.a b.o -o $(NAME)

main.o: main.cpp liba.a  b.o
	$(CXX) -c main.cpp 
liba.a: a.cpp a.h
	$(CXX) -c a.cpp -o a.o
	ar -rv liba.a a.o

b.o: a.cpp a.h
	$(CXX) -c b.cpp -o b.o

