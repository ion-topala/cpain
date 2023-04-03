#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
} drug, c[100];

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

int getNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

void Sortare_bubble(struct Drug *c, int n, struct Drug drug)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (c[j].price > c[j + 1].price)
            {
                drug = c[j];
                c[j] = c[j + 1];
                c[j + 1] = drug;
            }
        }
    }
}

void CombSort(struct Drug *c, int n, struct Drug drug)
{
    bool swapped = true;
    int gap = n;

    while (gap != 1 || swapped == true)
    {
        gap = getNextGap(gap);
        swapped = false;

        for (int i = 0; i < n - gap; i++)
        {
            if (c[i].price > c[i + gap].price)
            {
                drug = c[i];
                c[i] = c[i + gap];
                c[i + gap] = drug;

                swapped = true;
            }
        }
    }
}

void InsertionSort(struct Drug *c, int n, struct Drug drug)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        drug = c[i];
        j = i - 1;

        while (j >= 0 && c[j].price > drug.price)
        {
            c[j + 1] = c[j];
            j--;
        }

        c[j + 1] = drug;
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
    InsertionSort(ptr, size, drug);
    readInserted(ptr, size);

    return;
}