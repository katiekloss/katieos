KERN_CFLAGS = -Wall -Wextra -nostdlib -fno-builtin -nostartfiles -nodefaultlibs

build: kernel.o console.o
	nasm -f elf -o loader.o loader.s
	ld -T linker.ld -o kernel.bin loader.o kernel.o console.o 

run: build
	qemu -nographic -curses -monitor stdio -kernel kernel.bin

kernel.o: kernel.c
	gcc $(KERN_CFLAGS) -o kernel.o -c kernel.c

console.o: console.c
	gcc $(KERN_CFLAGS) -o console.o -c console.c

clean:
	rm -f *.o kernel.bin
