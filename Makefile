.PHONY: all test clean

all: build run
build:
	g++ --std=c++17 -I. main.cpp -o ./bin/a.out
run: build
	./bin/a.out

build_test:
	g++ --std=c++17 -I. test.cpp -o ./bin/test.out
test: build_test
	./bin/test.out

clean:
	rm ./bin/*
