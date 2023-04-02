#include <stdio.h>
#include <stdlib.h>

struct Flower
{
    int flowerId;
    char name[100];
    char category[100];
};


void main()
{
    struct Flower* ptr;
    int size = 20;

    ptr = (struct Flower*) malloc(size * sizeof(struct Flower));

    return;
}