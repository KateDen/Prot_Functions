#include <stdio.h>
#define MAX 5

int prot_puts ();

int main ()
{
    (prot_puts ());
    return 0;
}

int prot_puts ()
{
    int cat;
    cat = getchar();

    while (cat != EOF)
    {
    if (cat == '\t')
        return 0;

    putchar (cat);
    cat = getchar();
    }
}


