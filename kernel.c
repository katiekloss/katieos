/*
 * Copyright (c) 2012 Katie Kloss <kloss.katherine@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <console.h>

void kinit(void *multiboot_info, unsigned int magic)
{
    if (magic != 0x2BADB002)
    {
        // Boot was not performed correctly
    }

    init_console();

    /* VRAM starts at 0xB8000 and consists of pairs of bytes:
     * vram[0] = character;
     * vram[1] = attribute_for_character;
     * For the section below, attribute 0x07 is 'gray on black'
     */
    
    const char *string = "Hello, world!";
    unsigned char *vram = (unsigned char *) 0xB8000;
    int i;

    for(i = 0; i < 13; i++)
    {
        *vram = string[i];
        vram++;
        *vram = 0x07;
        vram++;
    }
}
