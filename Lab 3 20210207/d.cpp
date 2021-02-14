#include <stdio.h>

#define MAXC 100

int main(void) {

    int c = 0;
    size_t n = 0;

    printf ("\n Enter a sentence.\n\n input: ");

    /* read up to 100 characters from stdin, print each word on a line */
    while ((c = getchar ()) != EOF && c != '\n')
    {
        if (c == ' ')
            printf ("\n");
        else
            printf ("%c", c);
        n++;
    }
    printf ("\n");



    return 0;

}