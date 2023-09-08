# This file runs the below two commands.
# $ gcc -O2 -Wall -c main.c blowfish.c rwfile.c keys.c  wrapbf.c wrapzl.c endian.c
# $ gcc -O2 -Wall -o bcrypt main.o blowfish.o rwfile.o keys.o wrapbf.o endian.o wrapzl.o -L/usr/local/lib -lz
# Say keys.o checks if keys.c and Makefile, includes.h and other h's are newer newer. If yes, it will run `gcc -O2 -Wall -c keys.c`
# Since bcrypt or any tag that is first, it will anyway run if only make is given, and of course its deps after it. It is the only one which will run!
# Say if bcrypt already exists, it will say it is upto date.
# If the pre-requisite after : if changed say like main.o, then the command is run
# target : pre-requisite
# 	commands

DEFAULTS = Makefile includes.h blowfish.h functions.h config.h
CC = gcc
CFLAGS = -O2 -Wall 
COMPILE = ${CC} ${CFLAGS}
OBJS = main.o blowfish.o rwfile.o keys.o wrapbf.o endian.o wrapzl.o
LDFLAGS = -L/usr/local/lib -lz 
PREFIX = /usr/local

#clean_hello:
#	echo "hello"

#clean:
#	echo "hi"

bcrypt:	${OBJS} Makefile
	${COMPILE} -o bcrypt ${OBJS} ${LDFLAGS}

install:	bcrypt Makefile
	mkdir -p ${PREFIX}/bin;\
	mkdir -p ${PREFIX}/man/man1;\
	cp bcrypt ${PREFIX}/bin;\
	cp bcrypt.1 ${PREFIX}/man/man1;\
	chmod 755 ${PREFIX}/bin/bcrypt;\
	chmod 644 ${PREFIX}/man/man1/bcrypt.1

main.o:	main.c ${DEFAULTS}
	${COMPILE} -c main.c

blowfish.o:	blowfish.c ${DEFAULTS}
	${COMPILE} -c blowfish.c

rwfile.o:	rwfile.c ${DEFAULTS}
	${COMPILE} -c rwfile.c

keys.o:	keys.c ${DEFAULTS}
	${COMPILE} -c keys.c

wrapbf.o:	wrapbf.c ${DEFAULTS}
	${COMPILE} -c wrapbf.c

wrapzl.o:	wrapzl.c ${DEFAULTS}
	${COMPILE} -c wrapzl.c

endian.o:	endian.c ${DEFAULTS}
	${COMPILE} -c endian.c

clean.o:
	rm -rf *.o bcrypt bcrypt.core core bcrypt.tgz 

