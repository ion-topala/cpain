#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Company
{
    char name[100];
};

struct Drug
{
    int id;
    char name[30];
    struct Company company;
    float price;
} drug;

void insert(struct Drug *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nDrug nr.%d\n", i + 1);

        printf("Insert id ");
        scanf("%d", &(ptr + i)->id);

        printf("Insert name ");
        scanf("%s", (ptr + i)->name);

        printf("Insert company name ");
        scanf("%s", (ptr + i)->company.name);

        printf("Insert price ");
        scanf("%f", &(ptr + i)->price);
    }
}

void readInserted(struct Drug *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nDrug nr.%d\n", i + 1);

        printf("Id: %d\n", (ptr + i)->id);
        printf("Name: %s\n", (ptr + i)->name);
        printf("Company name: %s\n", (ptr + i)->company.name);
        printf("Price: %f\n", (ptr + i)->price);
    }
}

void main()
{
    struct Drug *ptr;

    int size;
    printf("Insert size=");
    scanf("%d", &size);

    ptr = (struct Drug *)malloc(size * (sizeof(struct Drug)));

    insert(ptr, size);
    readInserted(ptr, size);

    return;
}