#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    char ch;
    
    
    file = fopen("lorem-ipsum.txt", "r");

    if (file == NULL)
    {
        printf("File not found");
        return 1;
    }

    do
    {
        ch = fgetc(file);
        printf("%c", ch);

    } while (ch != EOF);
    
    fclose(file);

    return 0;
}