#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

/*! functions !*/
int prot_puts (char* str);
void TEST_prot_puts ();

char* prot_strchr (char* str, int s);
void TEST_prot_strchr ();

int prot_strlen (char* str);
void TEST_prot_strlen ();

char* prot_strcpy (char* str_inp, char* str_cpy);
void TEST_prot_strcpy ();

char* prot_strncpy (char* str_inp, char* str_cpy, int n);
void TEST_prot_strncpy ();

char* prot_strcat (char* str1, char* str2);
void TEST_prot_strcat ();

char* prot_strncat (char* str1, char* str2, int n);
void TEST_prot_strncat ();

char* prot_fgets (FILE* str_inp, int n, char* str_out);
void TEST_prot_fgets ();

char* prot_strdup (char* str);
void TEST_prot_strdup ();

char* prot_getline (char* str, int str_size, char* str_read);
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
    int i = 0;

    for (; str[i] != '\0'; i++)
    {
        putchar (str[i]);
    }

    str[i] = '\n';
    return 0;
}

void TEST_prot_puts ()
{
    char str[] = "Hello World!\n";
    prot_puts (str);
}


/*!STRCHR!*/
char* prot_strchr (char* str, int ch)
{
    int i = 0;
    for (; str[i] != ch ; i++)
    {
        if (str[i] == '\0') return NULL;
    }

    return str + i;
}

void TEST_prot_strchr ()
{
    char str [] = "Find me if you cat";
    int ch = 'y';

    printf ("\n" "Symbol 'y' in line str has number %d\n", prot_strchr (str, ch) - str);
}


/*!STRLEN!*/
int prot_strlen (char* str)
{
    int len = 0;

    while (str[len] != '\0')
        ++len;

    return len;
}

void TEST_prot_strlen ()
{
    char str [] = "This line has 24 symbols";

    printf ("\n" "symbols in the line: %d\n", prot_strlen(str));
}


/*!STRCPY!*/
char* prot_strcpy (char* str_inp, char* str_cpy)
{
    int i = 0;

    for (; str_inp[i] != '\0'; i++)
    {
        str_cpy[i] = str_inp[i];
    }

    str_cpy[i] = '\0';
    return str_cpy;
}

void TEST_prot_strcpy ()
{
    char str_inp [] = "Line one\0 line two";
    char str_cpy [100] = {};

    prot_strcpy (str_inp, str_cpy);

    printf ("\n" "strcpy line: %s\n", str_cpy);
}


/*!STRNCPY!*/
char* prot_strncpy (char* str_inp, char* str_cpy, int n)
{
    int i = 0;
    for (; str_inp[i] != '\0' && i != n; i++)
    {
        str_cpy[i] = str_inp[i];
    }

    if (i <= n) str_inp[i] = '\0';
    return str_cpy;
}

void TEST_prot_strncpy ()
{
    char str_inp [] = "Line one\0 line two";
    char str_cpy [100] = {};
    int n = 6;

    prot_strncpy (str_inp, str_cpy, n);

    printf ("\n" "strcpy line: %s\n", str_cpy);
}


/*!STRCAT!*/
char* prot_strcat (char* str1, char* str2)
{
    int nLine = prot_strlen(str1);
    int i = 0;

    for (; str2[i] != '\0'; i++)
    {
        str1[i + nLine] = str2[i];
    }

    str1[i + nLine] = '\0';
    return str1;
}

void TEST_prot_strcat ()
{
    char line [MAX] = "The line";
    char add [MAX] = " and add";

    prot_strcat (line, add);

    printf ("\n" "line: %s\n", line);
}


/*!STRNCAT!*/
char* prot_strncat (char* str1, char* str2, int n)
{
    int nLine = prot_strlen(str1);
    int k = 0;

    for (; str2[k] != '\0' && k <= n - 1; k++)
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

    prot_strncat(line, add, n);

    printf ("\n" "line: %s\n", line);
}


/*!FGETS!*/
char* prot_fgets (FILE* str_inp, int n, char* str_out)
{
    int i = 0;
    int ch = 0;

    for (; i != (n-1); i++)
    {
        ch = getc (str_inp);

        if (ch == '\n')
        {
            str_out[i] = '\n';
            str_out[i+1] = '\0';
            break;
        }

        if (ch == EOF)
        {
            str_out[i] = '\0';
            break;
        }

        str_out[i] = ch;
    }

    str_out[i] = '\0';
    return str_out;
}

void TEST_prot_fgets ()
{
    char str_out [50] = {};

    int n = prot_strlen (str_out);

    printf ("\n" "Was read: %s\n", prot_fgets(stdin, n, str_out));
}


/*!STRDUP!*/
char* prot_strdup (char* str)
{
    char* addr = (char*) calloc (prot_strlen (str) + 1, sizeof (char));

    if (addr == NULL) return NULL;

    return prot_strcpy (str, addr);
}

void TEST_prot_strdup ()
{
    char str [] = "Hello!";

    printf ("\n" "Copy: %s\n", prot_strdup (str));

    free (prot_strdup (str));
}


/*!GETLINE!*/
char* prot_getline (char* str, int str_size, char* str_read)
{
    int i = 0;

    for (; str[i] != '\0' && i != (str_size - 1); i++)
    {
        str_read[i] = str[i];
    }

    str_read[i] = '\0';

    return str_read;
}

void TEST_prot_getline ()
{
    char str [] = "Hello!";
    char str_read [100] = {};

    int str_size = 100;

    printf ("\n" "Got: %s\n", prot_getline(str, str_size, str_read));
}


/*!STRCMP!*/
int prot_strcmp (char* str1, char* str2)
{
    int i = 0;

    for (; (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0'); i++) {;}

    return (str1[i] - str2[i]);
}

void TEST_prot_strcmp ()
{
    char str1 [] = "Hello World!";
    char str2 [] = "Hello Werld!";

    int returned = prot_strcmp (str1, str2);

    if (returned < 0) printf ("\n" "The lines are not identical l1 < l2 (%d).\n", returned);

    else if (returned > 0) printf ("\n" "The lines are not identical l1 > l2 (%d).\n", returned);

    else if (returned == 0) printf ("\n" "The lines are identical.\n");
}
