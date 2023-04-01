#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool file_exists(const char *filename);

int main()
{
    FILE *file;
    char fileName[20] = "integer.txt";

    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num;

    file = fopen(fileName, "w");

    for (int i = 0; i < 10; i++)
    {
        putw(array[i], file);
    }

    printf("Closing the file \n");
    fclose(file);

    if (!file_exists(fileName))
    {
        printf("File not found");
        return 1;
    }

    file = fopen(fileName, "r");
    while (getw(file) != EOF)
    {
        num = getw(file);
        printf("Data in test.c file is %d \n", num);
    }

    fclose(file);

    return 0;
}

bool file_exists(const char *filename)
{
    FILE *file;
    if (file = fopen(filename, "r"))
    {
        fclose(file);
        return true;
    }

    return false;
}