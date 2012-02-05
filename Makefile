CFLAGS = -Wall -Wextra -nostdlib -fno-builtin -nostartfiles -nodefaultlibs
CFLAGS += -Iinclude/

build: kernel.o console.o
	nasm -f elf -o loader.o loader.s
	ld -T linker.ld -o kernel.bin loader.o kernel.o console.o 

run: build
	qemu -nographic -curses -monitor stdio -kernel kernel.bin

clean:
	rm -f *.o kernel.bin
