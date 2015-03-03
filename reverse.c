/** Program to demonstrate string reversal
 */

#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>
/** Print usage message
 */
void usage ()
{
    printf("usage: reversestring \"string with characters to reverse\"\n");
    printf("   OR: reversewords \"string with words to reverse\"\n");
}

/** Reverses all the characters in a string, in place.
 * For example, "hello world" becomes "dlrow olleh"
 * @param s String to reverse.
 */

void reversestring(char* s)
{
    size_t len = strlen(s);
    size_t i;
    for (i = 0; i < len / 2; i++)
    {
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}

/** Reverses all the words in a string, in place.
 * For example, "hello world" becomes "world hello"
 * @param s String with words to reverse.
 */
void reversewords(char* s)
{
    reversestring(s);
    char *t, *u;
    char b[200];
    int i = 0;
    t = s;
    while(*t)
    {
        while(*t != ' ' && *t != '\0')
        {
            b[i] = *t;
            t++;
            i++;
        }
        b[i] = '\0';
        i = 0;

        reversestring(b);

        u = b;

        while(*u)
        {
            *s = *u;
            u++;
            s++;
        }
        
        while(*s == ' ')
            s++;
        t = s;
    }
}

/** Must take exactly one argument.
 */
int main(int argc, char* argv[])
{

    char* command; // duplicate of command name
    char* basec;    // basename of command
    char* s;       // String to reverse;

    if (argc != 2)   // Check that it was called with exactly one argument
    {
        usage();
        return 1;
    }

    s = strdup(argv[1]); // Sring to reverse

    // See how the command was invoked

    // First strip down to just the basename, no directory prefix
    command = strdup(argv[0]);
    basec = basename(command);

    if (strcmp(basec, "reversestring") == 0)
    {
        printf("Original string: %s\n", argv[1]);
        reversestring(s);
        printf("Reversed string: %s\n", s);
        return 0;
    }
    else if (strcmp(basec, "reversewords") == 0)
    {
        printf("Original string: %s\n", argv[1]);
        reversewords(s);
        printf("Reversed string: %s\n", s);
        return 0;
    }
    else     // Those are the only two valid choices
    {
        usage();
        return 1;
    }
}
