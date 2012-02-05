About KatieOS
============
KatieOS is a personal project to write an operating system.

Isn't that complicated?
-----------------------
Yep.

Why would you do that?
----------------------
Mostly because we don't do anything remotely similar in my undergrad operating systems courses, and I think it's pretty cool.

How it works
============
At the moment, KatieOS has two major components:

The loader
----------
The loader (implemented in loader.s) sets up a <a href="http://www.gnu.org/software/grub/manual/multiboot/">Multiboot</a>-compliant environment and then immediately passes control to the main kernel code. This allows us to avoid dealing with setting up protected mode (and pretty much any aspect of the bootloading process, which I think is pretty spiffy).

The kernel
----------
The kernel first comes to life in the kmain() function in kernel.c. It doesn't do much yet, other than initializing the console and saying hi.
