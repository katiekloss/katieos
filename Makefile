build:
	nasm -f elf -o loader.o loader.s
	gcc -o kernel.o -c kernel.c -Wall -Wextra -nostdlib -fno-builtin -nostartfiles -nodefaultlibs
	ld -T linker.ld -o kernel.bin loader.o kernel.o

run: build
	qemu -nographic -curses -monitor stdio -kernel kernel.bin

clean:
	rm -f *.o kernel.bin
