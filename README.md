# learn_cee
Repository to learn C.


# Compilation

```
gcc -Wall cus.c cus.h mem.c -o mem_.o -g
gdb -q --args myprogram 1 2 3 4
```


# generate exuberant ctags
```
ctags --recurse=yes --exclude=.git --exclude=BUILD --exclude=.svn --exclude=vendor/* --exclude=node_modules/* --exclude=db/* --exclude=log/
```

# for PeachOS

Install nasm and qemu to load the binary in bios. Check cmd logs.

# hello.asm assembly program

To generate object file

```
nasm -f elf hello.asm
```

To link the obj file and generate the executable

```
ld -m elf_i386 -s -o hello hello.o
```

Run program

```
./hello
```
```
make -C ~/repos_/linux/ M=/home/scion/repos/learn_cee/dri modules
```

# Lex analyzer and yacc

```
cc lex.yy.c -o first
lex samp.l
```
