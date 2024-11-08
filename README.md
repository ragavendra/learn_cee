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
