CC=g++

all:
	$(CC) src/*.cpp src/layers/*.cpp main.cpp -o main

run: all
	./main

clean:
	rm main
