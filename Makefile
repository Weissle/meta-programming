all: build run

mkbin:
	mkdir -p bin

build: mkbin
	g++ --std=c++17 -Iinclude src/main.cpp -o ./bin/main.out
run: build
	./bin/main.out

build_test: mkbin
	g++ --std=c++17 -Iinclude test/test.cpp -o ./bin/test.out
test: build_test
	./bin/test.out

clean:
	rm ./bin/*
