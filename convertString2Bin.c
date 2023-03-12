#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "Hello";
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        printf("%c: ", str[i]);

        for (int bit = 7; bit >= 0; bit--)
        {
            printf("%d", (str[i] >> bit) & 1);
        }

        printf("\n");
    }

    return 0;
}
