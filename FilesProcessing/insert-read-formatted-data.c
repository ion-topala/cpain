#include <stdio.h>

void main()
{
    FILE *fptr;

    int id;
    char name[30];
    float salary;

    fptr = fopen("format.txt", "w+"); /*  open for writing */

    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }

    printf("Enter the id\n");
    scanf("%d", &id);
    fprintf(fptr, "Id= %d\n", id);

    printf("Enter the name \n");
    scanf("%s", name);
    fprintf(fptr, "Name= %s\n", name);

    printf("Enter the salary\n");
    scanf("%f", &salary);
    fprintf(fptr, "Salary= %.2f\n", salary);

    fclose(fptr);

    int idV2;
    char nameV2[30];
    float salaryV2;

    fptr = fopen("format.txt", "r");
    rewind(fptr);

    fscanf(fptr, "Id= %d\n", &idV2);
    fscanf(fptr, "Name= %s\n", nameV2);
    fscanf(fptr, "Salary= %f", &salaryV2);

    printf("Id= %d\n", idV2);
    printf("Name= %s\n", nameV2);
    printf("Salary= %f\n", salaryV2);

    fclose(fptr);

    return;
}