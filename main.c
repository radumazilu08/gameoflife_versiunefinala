#include "proiect.h"

int main(int argc, char *argv[])
{
    int i;
    int n, m, task, k;
    FILE *fis1 = fopen(argv[1], "rt");
    FILE *fis2 = fopen(argv[2], "wt");
    if (fis1 == NULL || fis2 == NULL)
    {
        printf("Fisierul nu poate fi deschis!");
        exit(1);
    }

    fscanf(fis1, "%d", &task);
    fscanf(fis1, "%d %d", &n, &m);
    fscanf(fis1, "%d", &k);

    if (task == 1)
    {
        char **matrice = (char **)malloc(n * sizeof(char *));
        for (i = 0; i < n; i++)
            matrice[i] = (char *)malloc((m + 1) * sizeof(char));

        citirematrice(matrice, n, m, fis1);

        for (i = 0; i <= k; i++)
        {
            afisarematrice(matrice, n, m, fis2);
            urmatoarea_matrice(matrice, n, m);
            fprintf(fis2, "\n");
        }

        for (i = 0; i < n; i++)
            free(matrice[i]);
        free(matrice);
    }

    if (task == 2)
    {
        NODE *nod = NULL;
        Elem *Generatie_invers = NULL;
        Elem *Generatie = NULL;
        int j, copie_k = k;

        char **matrice = (char **)malloc(n * sizeof(char *));
        char **copie = (char **)malloc(n * sizeof(char *));
        for (i = 0; i < n; i++)
        {
            matrice[i] = (char *)malloc((m + 1) * sizeof(char));
            copie[i] = (char *)malloc((m + 1) * sizeof(char));
        }

        citirematrice(matrice, n, m, fis1);

        while (k)
        {
            for (i = 0; i < n; i++)
                for (j = 0; j < m; j++)
                    copie[i][j] = matrice[i][j];

            urmatoarea_matrice(matrice, n, m);

            nod = NULL;

            for (i = 0; i < n; i++)
                for (j = 0; j < m; j++)
                    if (matrice[i][j] != copie[i][j])
                        introducere_nod_sf(&nod, i, j);

            push2(&Generatie_invers, nod);

            k--;
        }

        while (copie_k)
        {
            Elem *aux = pop(&Generatie_invers);

            NODE *copie_lista = NULL;
            NODE *p = aux->top;
            while (p)
            {
                introducere_nod_sf(&copie_lista, p->l, p->c);
                p = p->next;
            }

            push(&Generatie, copie_lista, copie_k);
            free_celule(aux->top);
            free(aux);
            copie_k--;
        }

        print(fis2, Generatie);
        free_generatii(Generatie);

        for (i = 0; i < n; i++)
        {
            free(matrice[i]);
            free(copie[i]);
        }
        free(matrice);
        free(copie);
    }

    if (task == 3)
    {
        char **matrice = (char **)malloc(n * sizeof(char *));
        for (i = 0; i < n; i++)
            matrice[i] = (char *)malloc((m + 1) * sizeof(char));

        citirematrice(matrice, n, m, fis1);

        char **matrice_start = (char **)malloc(n * sizeof(char *));
        for (i = 0; i < n; i++)
        {
            matrice_start[i] = (char *)malloc((m + 1) * sizeof(char));
            for (int j = 0; j < m; j++)
                matrice_start[i][j] = matrice[i][j];
        }

        Node *radacina = buildTree(matrice, n, m, k); // construim arborele

        parcurgerePreordine(radacina, fis2, matrice_start, n, m); // parcurgem arborele

        freeTree(radacina);

        for (i = 0; i < n; i++)
        {
            free(matrice[i]);
            free(matrice_start[i]);
        }
        free(matrice);
        free(matrice_start);
    }

    if (task == 4)
    {
        char **matrice = (char **)malloc(n * sizeof(char *));
        for (i = 0; i < n; i++)
            matrice[i] = (char *)malloc((m + 1) * sizeof(char));

        citirematrice(matrice, n, m, fis1);

        char **matrice_start = (char **)malloc(n * sizeof(char *));
        for (i = 0; i < n; i++)
        {
            matrice_start[i] = (char *)malloc((m + 1) * sizeof(char));
            for (int j = 0; j < m; j++)
                matrice_start[i][j] = matrice[i][j];
        }

        Node *radacina = buildTree(matrice, n, m, k); // construim arborele
        task4(radacina, matrice_start, n, m, fis2);

        freeTree(radacina);
        for (i = 0; i < n; i++)
        {
            free(matrice[i]);
            free(matrice_start[i]);
        }
        free(matrice);
        free(matrice_start);
    }

    if (task == 5)   //bonus task 2
    {
        char **matrice = (char **)malloc(n * sizeof(char *));
        for (i = 0; i < n; i++)
            matrice[i] = (char *)malloc((m + 1) * sizeof(char));
        
        citirematrice(matrice, n, m, fis1);

        Elem *Generatie = NULL;
        initializare_generatii(&Generatie);
        bonus(Generatie, matrice, n, m, k);
        afisarematrice(matrice, n, m, fis2);

    }

    fclose(fis1);
    fclose(fis2);
    return 0;
}
