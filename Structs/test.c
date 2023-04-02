#include <stdlib.h>
#include <string.h>

struct data
{
    int ziua;
    int luna;
    int an;
};
struct nume
{
    char nume[20];
    char prenume[20];
};
struct numar
{
    char part_st[10];
    int part_nd;
};

struct Evidenta_auto
{
    char marca[20];
    char culoare[15];
    struct numar numar_inmat;
    int an_inmatriculare;
    char tip_cas[20];
    struct data data_inspectie;
    struct nume proprietar;

} temp, c[20];

void finish_line()
{
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        printf("-");
    }
    printf("\n");
}

void citirea(struct Evidenta_auto *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Marca masinii %i: ", i + 1);
        scanf("%s", (ptr + i)->marca);
        printf("Culoarea masinii %i: ", i + 1);
        scanf("%s", (ptr + i)->culoare);
        printf("Numar de inmatriculare a masinii %i\n", i + 1);
        printf("       Partea formata din litere: ");
        scanf("%s", (ptr + i)->numar_inmat.part_st);
        printf("       Partea numerica: ");
        scanf("%i", &(ptr + i)->numar_inmat.part_nd);
        printf("Anul de inmatriculare a masinii %i: ", i + 1);
        scanf("%i", &(ptr + i)->an_inmatriculare);
        printf("Tipul caroseriei(sedan, universala, etc.) masinii %i: ", i + 1);
        scanf("%s", (ptr + i)->tip_cas);
        printf("Data ultimei inspectii a masinii %i\n", i + 1);
        printf("       Ziua: ");
        scanf("%i", &(ptr + i)->data_inspectie.ziua);
        printf("       Luna: ");
        scanf("%i", &(ptr + i)->data_inspectie.luna);
        printf("       Anul: ");
        scanf("%i", &(ptr + i)->data_inspectie.an);
        printf("Proprietarul masinii %i\n", i + 1);
        printf("       Numele: ");
        scanf("%s", (ptr + i)->proprietar.nume);
        printf("       Prenumele: ");
        scanf("%s", (ptr + i)->proprietar.prenume);
        finish_line();
    }
}

void Afisarea(struct Evidenta_auto *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nMarca masinii %i: %s", i + 1, (ptr + i)->marca);
        printf("\nCuloarea masinii %i: %s", i + 1, (ptr + i)->culoare);
        printf("\nNumar de inmatriculare a masinii %i: %s %i", i + 1, (ptr + i)->numar_inmat.part_st, (ptr + i)->numar_inmat.part_nd);
        printf("\nAnul de inmatriculare a masinii %i: %i", i + 1, (ptr + i)->an_inmatriculare);
        printf("\nTipul caroseriei(sedan, universala, etc.) masinii %i: %s", i + 1, (ptr + i)->tip_cas);
        printf("\nData ultimei inspectii a masinii %i: %i/%i/%i", i + 1, (ptr + i)->data_inspectie.ziua, (ptr + i)->data_inspectie.luna, (ptr + i)->data_inspectie.an);
        printf("\nProprietarul masinii %i: %s %s", i + 1, (ptr + i)->proprietar.prenume, (ptr + i)->proprietar.nume);
        finish_line();
    }
}

void Sortare_bubble(struct Evidenta_auto *c, int n, struct Evidenta_auto temp)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(c[j].proprietar.nume, c[j + 1].proprietar.nume) < 0)
            {
                temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n%s\t%s\t%s", c[i].proprietar.nume, c[i].proprietar.prenume, c[i].marca);
    }
}

void selectionSort(struct Evidenta_auto *c, int n, struct Evidenta_auto temp)
{
    for (int i = 0; i < n - 1; i++)
    {
        int position = i;
        for (int j = i + 1; j < n; j++)
        {
            if (c[position].data_inspectie.an > c[j].data_inspectie.an)
            {
                position = j;
            }
            else if (c[position].data_inspectie.an == c[j].data_inspectie.an)
            {
                if (c[position].data_inspectie.luna > c[j].data_inspectie.luna)
                {
                    position = j;
                }
                else if (c[position].data_inspectie.luna == c[j].data_inspectie.luna)
                {
                    if (c[position].data_inspectie.ziua > c[j].data_inspectie.ziua)
                    {
                        position = j;
                    }
                }
            }
        }
        if (position != i)
        {
            temp = c[i];
            c[i] = c[position];
            c[position] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n%s\t%d.%d.%d\t%s", c[i].proprietar.nume, c[i].data_inspectie.ziua, c[i].data_inspectie.luna, c[i].data_inspectie.an, c[i].marca);
    }
}
void change(struct Evidenta_auto *ptr, int n)
{

    printf("Modificarea elementelor din structura\n");
    int m, k = 0;
    printf("\nAlege din meniul de mai ce doresti sa reintroduci(se va alege numarul corespondent optiunii)\n");
    printf("\n1. Marca masinii\n");
    printf("2. Culoarea\n");
    printf("3. Numar de inmatriculare\n");
    printf("4. An de inmatriculare\n");
    printf("5. Tipul caroseriei\n");
    printf("6. Data ultimei inspectii\n");
    printf("7. Numele propietarului\n");
    printf("9. Exit");
    finish_line();
    while (k != 9)
    {
        printf("\nAlegeti ce tip de schimbare doti sa faceti, sau tastati 9 pentru a finisa: ");
        scanf("%i", &k);
        switch (k)
        { // (ptr + i)->marca
        case 1:
            printf("\nAti ales sa modificati marca unei masini, in baza de date sunt %i masini\nIntroduceti numarul masinii care ati dori sa-i schimbati marca\n", n);
            int t;
            char p[20];
            scanf("%i", &t);
            printf("Introduceti marca noua a masinii %i\n", t);
            scanf("%s", p);
            strcpy((ptr + t - 1)->marca, p);
            // printf("Marca masinii deja introduse %s\n",c[t-1].marca);
            break;
        case 2:
            printf("\nAti ales sa modificati culoarea unei masini, in baza de date sunt %i masini\nIntroduceti numarul masinii care ati dori sa-i schimbati culoarea\n", n);
            scanf("%i", &t);
            printf("Introduceti culoarea noua a masinii %i\n", t);
            scanf("%s", p);
            strcpy((ptr + t - 1)->culoare, p);
            // printf("Culoarea masinii deja introduse %s\n",c[t-1].culoare);
            break;
        case 3:
            printf("\nAti ales sa modificati numarul de inmatriculare unei masini, in baza de date sunt %i masini\nIntroduceti numarul masinii care ati dori sa-i schimbati numarul de inmatriculare\n", n);
            scanf("%i", &t);
            printf("Introduceti partea formata din litere a numarului masinii %i\n", t);
            scanf("%s", p);
            strcpy((ptr + t - 1)->numar_inmat.part_st, p);
            printf("Introduceti partea formata din cifre a numarului masinii %i\n", t);
            scanf("%d", &(ptr + t - 1)->numar_inmat.part_nd);
            // printf("Marca masinii deja introduse %s %d\n",c[t-1].numar_inmat.part_st,c[t-1].numar_inmat.part_nd);
            break;
        case 4:
            printf("\nAti ales sa modificati anul de inmatriculare unei masini, in baza de date sunt %i masini\nIntroduceti numarul masinii care ati dori sa-i schimbati anul de inmatriculare\n", n);
            scanf("%i", &t);
            printf("Introduceti anul de inmatriculare a masinii %i\n", t);
            scanf("%d", &(ptr + t - 1)->an_inmatriculare);
            // printf("Anul de inmatriculare deja introdus: %d",c[t-1].an_inmatriculare);
            break;
        case 5:
            printf("\nAti ales sa modificati tipul caroseriei unei masini, in baza de date sunt %i masini\nIntroduceti numarul masinii care ati dori sa-i schimbati tipul de caroserie\n", n);
            scanf("%i", &t);
            printf("Introduceti tipul caroseriei a masinii %i\n", t);
            scanf("%s", p);
            strcpy((ptr + t - 1)->tip_cas, p);
            // printf("Tipul caroseriei deja introduse %s\n",c[t-1].tip_cas);
            break;
        case 6:
            printf("\nAti ales sa modificati data ultimei inspectii, in baza de date sunt %i masini\nIntroduceti numarul masinii care ati dori sa-i schimbati data ultimei inspectii\n", n);
            scanf("%i", &t);
            printf("       Ziua: ");
            scanf("%i", &(ptr + t - 1)->data_inspectie.ziua);
            printf("       Luna: ");
            scanf("%i", &(ptr + t - 1)->data_inspectie.luna);
            printf("       Anul: ");
            scanf("%i", &(ptr + t - 1)->data_inspectie.an);
            // printf("Data deja introdusa:%d.%d.%d",c[t-1].data_inspectie.ziua,c[t-1].data_inspectie.luna,c[t-1].data_inspectie.an);
            break;
        case 7:
            printf("\nAti ales sa modificati proprietarul masinii, in baza de date sunt %i masini\nIntroduceti numarul masinii care ati dori sa-i schimbati proprietarul\n", n);
            scanf("%i", &t);
            printf("Introduceti numele:");
            scanf("%s", p);
            strcpy((ptr + t - 1)->proprietar.nume, p);
            printf("Introduceti prenumele:");
            scanf("%s", p);
            strcpy((ptr + t - 1)->proprietar.prenume, p);
            // printf("\nProprietarul masinii: %s %s",c[t-1].proprietar.prenume,c[t-1].proprietar.nume);
            break;
        default:
            break;
        }
    }
}

int main()
{
    struct Evidenta_auto *ptr;
    int n;
    printf("n=");
    scanf("%i", &n);

    ptr = (struct Evidenta_auto *)malloc(n * sizeof(struct Evidenta_auto));

    citirea(ptr, n);
    finish_line();
    Afisarea(ptr, n);
    printf("Sortarea Bubble descrescatoare dupa numele Proprietarolui\n");
    Sortare_bubble(ptr, n, temp);
    finish_line();
    printf("Sortarea Selection crescatoare dupa data ultimei inspectii a masinii\n");
    selectionSort(ptr, n, temp);
    finish_line();
    change(ptr, n);
    Afisarea(ptr, n);

    return 0;
}