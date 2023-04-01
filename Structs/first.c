#include <stdio.h>
#include <string.h>

struct Drug
{
    int drugId;
    char name[100];
    char strenght[20];
};

int main()
{
    struct Drug instance;

    instance.drugId = 1;
    strcpy(instance.name, "Nurofen");
    strcpy(instance.strenght, "100 MG");

    printf("Id %d\n", instance.drugId);
    printf("Name %s\n", instance.name);
    printf("Strenght %s\n", instance.strenght);

    return 0;
}