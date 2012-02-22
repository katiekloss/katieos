#ifndef __MM_H
#define __MM_H

#include <stddef.h>

typedef struct mm_chunk
{
    void *start;
    char flags;
} mm_chunk_t;

void init_mm(unsigned long upper_mem_size);
void * kmalloc(size_t bytes);
void kfree(void *ptr);
#endif
