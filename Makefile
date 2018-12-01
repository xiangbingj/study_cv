all:test

CC=gcc
CPPFLAGS=-Wall -ggdb
LDFLAGS=-lm

test:zq_cv.o main.o -lm
	$(CC) $(LDFLAGS) -o $@ $^

zq_cv.o:zq_cv.c
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $@ -c $^

main.o:main.c
	$(CC) $(CPPFLAGS) -o $@ -c $^
.PHONY:
	clean

clean:
	rm *.o test *.bmp