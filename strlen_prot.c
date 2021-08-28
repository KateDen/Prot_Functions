#include <stdio.h>

int prot_strlen();

int main ()
{
    (prot_strlen());

    return 0;
}

int prot_strlen()
{
    long nc =0;

    while (getchar() != EOF)
        ++nc;

    printf ("%ld\n", nc);
}
