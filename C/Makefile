all:test

CC=gcc
CPPFLAGS=-Wall -ggdb
LDFLAGS=-lm

test:main.o zq_cv.o study_cv.o -lm
	$(CC) $(LDFLAGS) -o $@ $^
zq_cv.o:zq_cv.c
	$(CC) $(CPPFLAGS) -o $@ -c $^
study_cv.o:study_cv.c
	$(CC) $(CPPFLAGS) -o $@ -c $^

main.o:main.c
	$(CC) $(CPPFLAGS) -o $@ -c $^
.PHONY:
	clean

clean:
	rm *.o test *.bmp