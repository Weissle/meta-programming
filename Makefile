all: build run

build:
	g++ --std=c++17 -I. main.cpp -o ./build/a.out
run: build
	./build/a.out

build_test:
	g++ --std=c++17 -I. test.cpp -o ./build/test.out
test: build_test
	./build/test.out
