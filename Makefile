all: build run
build:
	g++ --std=c++17 main.cpp -o a.out
run: build
	./a.out
