void init_console(void)
{
    unsigned char *vram = (unsigned char *) 0xB8000;
    int i;
    for(i = 0; i < (80 * 25); i++)
    {
        *vram = ' ';
        vram++;
        *vram = 0x0;
        vram++;
    }
}
