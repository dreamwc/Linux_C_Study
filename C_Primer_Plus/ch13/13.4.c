#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int i = 0;
    FILE * fp;
    int ch;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s [filename1] [filename2] ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (i = 1; i < argc; i++)
    {
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Can't open file %s.\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        while ((ch = fgetc(fp)) != EOF)
        {
            fputc(ch, stdout);
        }
        fclose(fp);
    }

    return 0;
}
