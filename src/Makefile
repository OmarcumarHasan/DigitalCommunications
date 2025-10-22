all: 01 02

01: sample.c
	gcc -o ../bin/sample.exe sample.c

run: 01
	../bin/sample.exe

02: main.c
	gcc -o ../bin/main.exe main.c

run: 02
	../bin/main.exe

clean:
	rm -f ../bin/*.exe