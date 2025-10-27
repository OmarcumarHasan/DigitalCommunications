all: 01 02 03

01: sample.c
	gcc -o ../bin/sample.exe sample.c

02: main.c input.c rle.c analysis.c
	gcc -o ../bin/main.exe main.c input.c rle.c analysis.c

03: rle_main.c rle.c
	gcc -o ../bin/rle.exe rle_main.c rle.c
clean:
	rm -f ../bin/*.exe