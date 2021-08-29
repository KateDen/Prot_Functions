#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

/*! functions !*/
int prot_puts (char* str);
void TEST_prot_puts ();

int prot_strchr (char* str, int* ch);
void TEST_prot_strchr ();

int prot_strlen (char* str);
void TEST_prot_strlen ();

char* prot_strcpy (char* str_inp, char* str_cpy);
void TEST_prot_strcpy ();

char* prot_strncpy (char* str_inp, char* str_cpy, int* n);
void TEST_prot_strncpy ();

char* prot_strcat (char* str1, char* str2);
void TEST_prot_strcat ();

char* prot_strncat (char* str1, char* str2, int* n);
void TEST_prot_strncat ();

char* prot_fgets (char* str_inp, int* n, char* str_out);
void TEST_prot_fgets ();

char* prot_strdup (char* str);
void TEST_prot_strdup ();

char* prot_getline (char* str, int* str_size, char* str_read);
void TEST_prot_getline ();

int prot_strcmp (char* str1, char* str2);
void TEST_prot_strcmp ();


/*! main !*/
int main ()
{
    TEST_prot_puts ();
    TEST_prot_strchr ();
    TEST_prot_strlen ();
    TEST_prot_strcpy ();
    TEST_prot_strncpy ();
    TEST_prot_strcat ();
    TEST_prot_strncat ();
    TEST_prot_fgets ();
    TEST_prot_strdup ();
    TEST_prot_getline ();
    TEST_prot_strcmp ();

    return 0;
}


/*!PUTS!*/
int prot_puts (char* str)
{
    int k = 0;

    for (; str[k] != '\0'; k++)
    {
        putchar (str[k]);
    }

    str[k] = '\n';
    return 0;
}

void TEST_prot_puts ()
{
    char str[] = {"Hello World!\n"};
    prot_puts (str);
}


/*!STRCHR!*/
int prot_strchr (char* str, int* ch)
{
    int i = 0;
    for (; str[i] != *ch; i++) {};

    return i+1;
}

void TEST_prot_strchr ()
{
    char str [] = "Find me if you can";
    int ch = 'y';

    printf ("\nSymbol 'y' in line str has number %d\n", prot_strchr (str, &ch));
}


/*!STRLEN!*/
int prot_strlen (char* str)
{
    int nc = 0;

    while (str[nc] != '\0')
        ++nc;

    return nc;
}

void TEST_prot_strlen ()
{
    char str [] = {"This line has 24 symbols"};

    printf ("\nsymbols in the line: %d\n", prot_strlen(str));
}


/*!STRCPY!*/
char* prot_strcpy (char* str_inp, char* str_cpy)
{
    int i = 0;
    for (; str_inp[i] != '\0'; i++)
    {
        str_cpy[i] = str_inp[i];
    }

    return str_cpy;
}

void TEST_prot_strcpy ()
{
    char str_inp [] = {"Line one\0 line two"};
    char str_cpy [100] = {};

    prot_strcpy (str_inp, str_cpy);

    printf ("\nstrcpy line: %s\n", str_cpy);
}


/*!STRNCPY!*/
char* prot_strncpy (char* str_inp, char* str_cpy, int* n)
{
    int i = 0;
    for (; i <= *n; i++)
    {
        str_cpy[i] = str_inp[i];
    }

    return str_cpy;
}

void TEST_prot_strncpy ()
{
    char str_inp [] = {"Line one\0 line two"};
    char str_cpy [100] = {};
    int n = 6;

    prot_strncpy (str_inp, str_cpy, &n);

    printf ("\nstrcpy line: %s\n", str_cpy);
}


/*!STRCAT!*/
char* prot_strcat (char* str1, char* str2)
{
    int nLine = prot_strlen(str1);
    int k = 0;

    for (; str2[k] != '\0'; k++)
    {
        str1[k + nLine] = str2[k];
    }

    str1[k + nLine] = '\0';
    return str1;
}

void TEST_prot_strcat ()
{
    char line [MAX] = "The line";
    char add [MAX] = " and add";

    prot_strcat(line, add);

    printf ("\nline: %s\n", line);
}


/*!STRNCAT!*/
char* prot_strncat (char* str1, char* str2, int* n)
{
    int nLine = prot_strlen(str1);
    int k = 0;

    for (; k <= *n; k++)
    {
        str1[k + nLine] = str2[k];
    }

    str1[k + nLine] = '\0';
    return str1;
}

void TEST_prot_strncat ()
{
    char line [MAX] = "The line";
    char add [MAX] = " and add";
    int n = 6;

    prot_strncat(line, add, &n);

    printf ("\nline: %s\n", line);
}


/*!FGETS!*/
char* prot_fgets (char* str_inp, int* n, char* str_out)
{
    int i = 0;

    for (; str_inp[i] != '\0' && str_inp[i] != '\n' && str_inp[i] != EOF &&  i != (*n-1) ; i++)
    {
        str_out[i] = str_inp[i];
    }

    if (str_out[i] == EOF) return NULL;

    str_out[i] = '\0';
    return str_out;
}

void TEST_prot_fgets ()
{
    char str_inp [] = {"This line contains 29 symbols"};
    char str_out [50] = {};

    int n = sizeof(str_out);

    printf ("\nWas read: %s\n", prot_fgets(str_inp, &n, str_out));
}


/*!STRDUP!*/
char* prot_strdup (char* str)
{
    char* addr = (char*) malloc(sizeof(str) + 2);

    //printf ("%d\n", sizeof(str));                        !!!

    if (addr == NULL) return NULL;

    int i = 0;

    for (; str[i] != '\0'; i++)
    {
        addr[i] = str[i];
    }

    addr[i] = '\0';
    return addr;
}

void TEST_prot_strdup ()
{
    char str [] = {"Hello"};

    printf ("\nCopy: %s\n", prot_strdup (str));

    free(prot_strdup (str));
}


/*!GETLINE!*/
char* prot_getline (char* str, int* str_size, char* str_read)
{
    int i = 0;

    for (; str[i] != '\0' && i != (*str_size - 1); i++)
    {
        str_read[i] = str[i];
    }

    str_read[i] = '\0';

    return str_read;
}

void TEST_prot_getline ()
{
    char str [] = {"Hello!"};
    char str_read [100] = {};

    int str_size = 100;

    printf ("\nGot: %s\n", prot_getline(str, &str_size, str_read));
}


/*!STRCMP!*/
int prot_strcmp (char* str1, char* str2)
{
    int i = 0;
    int s1 = 0;
    int s2 = 0;

    for (; (str1[i] = str2[i] && str1[i] != '\0' && str2[i] != '\0'); i++)
    {
        s1 = str1[i];
        s2 = str2[i];
    }

    if (s1 > s2)  return  1;
    if (s1 < s2)  return -1;
    if (s1 == '\0' || s2 == '\0') return  0;
}

void TEST_prot_strcmp ()
{
    char str1 [] = {"Hello World!"};
    char str2 [] = {"Hello World!"};

    //printf ("%d\n", 'o');
    //printf ("%d\n", 'e');


    switch (prot_strcmp (str1, str2))
    {
        case 0:
            printf ("\nThe lines are identical.\n");
            break;

        case 1:
            printf ("\nThe lines are not identical l1 > l2 (%d).\n", prot_strcmp (str1, str2));
            break;

        case -1:
            printf ("\nThe lines are not identical l1 < l2 (%d).\n", prot_strcmp (str1, str2));
            break;

        default:
            printf ("\nError\n");
    }
}
