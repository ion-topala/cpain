#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file;
    char data[50];

    file = fopen("test.txt", "w");
    if (file == NULL)
    {
        printf("file not found");
        return 1;
    }

    printf("Enter some text:\n");
    fgets(data, 50, stdin);

    fputs(data, file);
    fputs("\n", file);

    fclose(file);

    return 0;
}