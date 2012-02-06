CFLAGS = -Wall -Wextra -nostdlib -fno-builtin -nostartfiles -nodefaultlibs
CFLAGS += -Iinclude/
OBJECTS = kernel.o console.o libc.o

build: $(OBJECTS)
	nasm -f elf -o loader.o loader.s
	ld -T linker.ld -o kernel.bin loader.o $(OBJECTS) 

run: build
	qemu -nographic -curses -monitor stdio -kernel kernel.bin

clean:
	rm -f *.o kernel.bin
