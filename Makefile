CC=g++

all:
	$(CC) src/*.cpp src/layers/*.cpp main.cpp -o main

run:
	./main

clean:
	rm main
