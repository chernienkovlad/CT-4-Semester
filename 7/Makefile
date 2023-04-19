CC=g++
INT=python3
CFLAGS=-std=c++20 -O3
FILENAME1=speed_cmp.cpp
FILENAME2=plot.py

all: compile run plot

compile: $(FILENAME1)
	$(CC) $(CFLAGS) $(FILENAME1)

run:
	./a.out

plot: $(FILENAME2)
	$(INT) $(FILENAME2)

clean:
	rm a.out