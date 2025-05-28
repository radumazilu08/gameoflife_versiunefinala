#include "proiect.h"

void push(Elem **Generatie, NODE *newcel, int gen) // adaug gen in stiva
{
    Elem *noua_gen = (Elem *)malloc(sizeof(Elem));
    noua_gen->k = gen;
    noua_gen->top = newcel;
    noua_gen->next = *Generatie;
    *Generatie = noua_gen;
}

void introducere_nod_in(NODE **head, int l, int c) // insereaza nod la inceputul listei
{
    NODE *newcel = (NODE *)malloc(sizeof(NODE));
    newcel->l = l;
    newcel->c = c;
    newcel->next = *head;
    *head = newcel;
}

void introducere_nod_sf(NODE **head, int l, int c) // insereaza nod la sf listei
{
    if (*head == NULL)
        introducere_nod_in(head, l, c);
    else
    {
        NODE *aux = *head;
        while (aux->next != NULL)
            aux = aux->next;
        NODE *newcel = (NODE *)malloc(sizeof(NODE));
        newcel->l = l;
        newcel->c = c;
        aux->next = newcel;
        newcel->next = NULL;
    }
}

void print(FILE *fis2, Elem *Generatie)
{
    while (Generatie != NULL)
    {
        NODE *aux = Generatie->top;
        fprintf(fis2, "%d", Generatie->k);
        while (aux != NULL)
        {
            fprintf(fis2, " %d %d", aux->l, aux->c);
            aux = aux->next;
        }
        fprintf(fis2, "\n");
        Generatie = Generatie->next;
    }
}

Elem *pop(Elem **top) // elimin din stiva
{
    if (*top == NULL)
        return NULL;
    Elem *temp = *top;
    *top = (*top)->next;
    return temp;
}

void free_celule(NODE *Cel) // memorie lista
{
    while (Cel != NULL)
    {
        NODE *aux = Cel;
        Cel = Cel->next;
        free(aux);
    }
}

void free_generatii(Elem *Gen) // memorie generatii
{
    while (Gen != NULL)
    {
        Elem *aux = Gen;
        free_celule(Gen->top);
        Gen = Gen->next;
        free(aux);
    }
}

void push2(Elem **Generatie, NODE *newcel) // adaug in stiva fara k
{
    Elem *noua_gen = (Elem *)malloc(sizeof(Elem));
    noua_gen->top = newcel;
    noua_gen->next = *Generatie;
    *Generatie = noua_gen;
}

void citirematrice(char **matrice, int n, int m, FILE *fis1)
{
    int i, j;
    char c;
    for (i = 0; i < n; i++)
    {
        j = 0;
        while (j < m)
        {
            fscanf(fis1, "%c", &c);
            if (c == '\n' || c == '\r')
                continue;
            matrice[i][j] = c;
            j++;
        }
    }
}

int vecini(char **matrice, int i, int j, int n, int m) // determina numarul de vecini
{
    int ct = 0;
    if (i == 0 && j == 0)
    {
        if (matrice[i + 1][j] == 'X')
            ct++;
        if (matrice[i][j + 1] == 'X')
            ct++;
        if (matrice[i + 1][j + 1] == 'X')
            ct++;
        return ct;
    }
    else if (i == n - 1 && j == 0)
    {
        if (matrice[i - 1][j] == 'X')
            ct++;
        if (matrice[i][j + 1] == 'X')
            ct++;
        if (matrice[i - 1][j + 1] == 'X')
            ct++;
        return ct;
    }
    else if (i == n - 1 && j == m - 1)
    {
        if (matrice[i][j - 1] == 'X')
            ct++;
        if (matrice[i - 1][j - 1] == 'X')
            ct++;
        if (matrice[i - 1][j] == 'X')
            ct++;
        return ct;
    }
    else if (i == 0 && j == m - 1)
    {
        if (matrice[i][j - 1] == 'X')
            ct++;
        if (matrice[i + 1][j] == 'X')
            ct++;
        if (matrice[i + 1][j - 1] == 'X')
            ct++;
        return ct;
    }
    else if (i == 0)
    {
        if (matrice[i][j + 1] == 'X')
            ct++;
        if (matrice[i][j - 1] == 'X')
            ct++;
        if (matrice[i + 1][j - 1] == 'X')
            ct++;
        if (matrice[i + 1][j + 1] == 'X')
            ct++;
        if (matrice[i + 1][j] == 'X')
            ct++;
        return ct;
    }
    else if (i == n - 1)
    {
        if (matrice[i][j + 1] == 'X')
            ct++;
        if (matrice[i][j - 1] == 'X')
            ct++;
        if (matrice[i - 1][j - 1] == 'X')
            ct++;
        if (matrice[i - 1][j + 1] == 'X')
            ct++;
        if (matrice[i - 1][j] == 'X')
            ct++;
        return ct;
    }
    else if (j == 0)
    {
        if (matrice[i - 1][j] == 'X')
            ct++;
        if (matrice[i + 1][j] == 'X')
            ct++;
        if (matrice[i][j + 1] == 'X')
            ct++;
        if (matrice[i + 1][j + 1] == 'X')
            ct++;
        if (matrice[i - 1][j + 1] == 'X')
            ct++;
        return ct;
    }
    else if (j == m - 1)
    {
        if (matrice[i - 1][j] == 'X')
            ct++;
        if (matrice[i + 1][j] == 'X')
            ct++;
        if (matrice[i][j - 1] == 'X')
            ct++;
        if (matrice[i + 1][j - 1] == 'X')
            ct++;
        if (matrice[i - 1][j - 1] == 'X')
            ct++;
        return ct;
    }
    else
    {
        if (matrice[i - 1][j - 1] == 'X')
            ct++;
        if (matrice[i - 1][j] == 'X')
            ct++;
        if (matrice[i - 1][j + 1] == 'X')
            ct++;
        if (matrice[i][j + 1] == 'X')
            ct++;
        if (matrice[i][j - 1] == 'X')
            ct++;
        if (matrice[i + 1][j - 1] == 'X')
            ct++;
        if (matrice[i + 1][j] == 'X')
            ct++;
        if (matrice[i + 1][j + 1] == 'X')
            ct++;
        return ct;
    }
}

void urmatoarea_matrice(char **matrice, int n, int m) // transforma matricea in noua generatie
{
    int nrvecini, i, j;
    char **copie = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
        copie[i] = (char *)malloc((m + 1) * sizeof(char));

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            copie[i][j] = matrice[i][j];

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            nrvecini = vecini(matrice, i, j, n, m);
            if (matrice[i][j] == 'X' && (nrvecini < 2 || nrvecini > 3))
                copie[i][j] = '+';
            else if (matrice[i][j] == '+' && nrvecini == 3)
                copie[i][j] = 'X';
        }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            matrice[i][j] = copie[i][j];

    for (i = 0; i < n; i++)
        free(copie[i]);
    free(copie);
}

NODE *regulaB(char **matrice, int n, int m)
{
    int i, j, nr_vecini;
    char **copie = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        copie[i] = (char *)malloc((m + 1) * sizeof(char));
        for (j = 0; j < m; j++)
        {
            copie[i][j] = matrice[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            nr_vecini = vecini(matrice, i, j, n, m);
            if (nr_vecini == 2 && matrice[i][j] == '+')
            {
                copie[i][j] = 'X';
            }
        }
    }
    NODE *celule_modificate = NULL;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (matrice[i][j] != copie[i][j])
            {
                introducere_nod_sf(&celule_modificate, i, j);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            matrice[i][j] = copie[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        free(copie[i]);
    }
    free(copie);
    return celule_modificate;
}

NODE *determinare_celule_modificate(char **matrice_veche, char **matrice_noua, int n, int m)
{
    NODE *celule_modificate = NULL;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrice_veche[i][j] != matrice_noua[i][j])
            {
                introducere_nod_sf(&celule_modificate, i, j);
            }
        }
    }
    return celule_modificate;
}

void afisarematrice(char **matrice, int n, int m, FILE *fis2) // afiseaza in fisierul2
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            fprintf(fis2, "%c", matrice[i][j]);
        fprintf(fis2, "\n");
    }
}

void parcurgerePreordine(Node *radacina, FILE *fis2, char **matrice, int n, int m)
{
    if (radacina == NULL)
        return;
    NODE *aux = radacina->celule_modificate;
    while (aux != NULL)
    {
        matrice[aux->l][aux->c] = (matrice[aux->l][aux->c] == 'X') ? '+' : 'X';
        aux = aux->next;
    } // aplic moficarile matricei initiale
    afisarematrice(matrice, n, m, fis2);
    fprintf(fis2, "\n");
    char **copie = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        copie[i] = (char *)malloc((m + 1) * sizeof(char));
        for (int j = 0; j < m; j++)
            copie[i][j] = matrice[i][j];
    }
    parcurgerePreordine(radacina->RegulaB, fis2, matrice, n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrice[i][j] = copie[i][j];
    parcurgerePreordine(radacina->Standard, fis2, matrice, n, m);
    for (int i = 0; i < n; i++)
        free(copie[i]);
    free(copie);
    aux = radacina->celule_modificate;
    while (aux != NULL)
    {
        matrice[aux->l][aux->c] = (matrice[aux->l][aux->c] == 'X') ? '+' : 'X';
        aux = aux->next;
    }
}

void freeTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_celule(root->celule_modificate);
    freeTree(root->RegulaB);
    freeTree(root->Standard);
    free(root);
}

Node *buildTree(char **matrice, int n, int m, int niveluri)
{
    Node *nod = (Node *)malloc(sizeof(Node));
    nod->celule_modificate = NULL;
    nod->Standard = NULL;
    nod->RegulaB = NULL;
    if (niveluri == 0)
        return nod;
    char **copie_initiala = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        copie_initiala[i] = (char *)malloc((m + 1) * sizeof(char));
        for (int j = 0; j < m; j++)
            copie_initiala[i][j] = matrice[i][j];
    }
    urmatoarea_matrice(matrice, n, m);
    NODE *modificari_standard = determinare_celule_modificate(copie_initiala, matrice, n, m);
    nod->Standard = buildTree(matrice, n, m, niveluri - 1);
    if (nod->Standard != NULL)
        nod->Standard->celule_modificate = modificari_standard;
    else
        free_celule(modificari_standard);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrice[i][j] = copie_initiala[i][j];
    NODE *modificari_regulaB = regulaB(matrice, n, m);
    nod->RegulaB = buildTree(matrice, n, m, niveluri - 1);
    if (nod->RegulaB != NULL)
        nod->RegulaB->celule_modificate = modificari_regulaB;
    else
        free_celule(modificari_regulaB);
    for (int i = 0; i < n; i++)
        free(copie_initiala[i]);
    free(copie_initiala);
    return nod;
}

// functia care rezolva task 4
void task4(Node *radacina, char **matrice, int nr_linii, int nr_coloane, FILE *fisier_out)
{
    if (radacina == NULL)
        return;

    char **matrice_copie = (char **)malloc(nr_linii * sizeof(char *));
    for (int i = 0; i < nr_linii; i++)
    {
        matrice_copie[i] = (char *)malloc((nr_coloane + 1) * sizeof(char));
        for (int j = 0; j < nr_coloane; j++)
        {
            matrice_copie[i][j] = matrice[i][j];
        }
    }

    Punct *lant_maxim = NULL;
    int lungime_maxima = 0;

    while (verifica_matrice_goala(matrice_copie, nr_linii, nr_coloane) == 0)
    {
        // Găsim componenta conexă curentă
        bool **vizitat = (bool **)malloc(nr_linii * sizeof(bool *));
        for (int i = 0; i < nr_linii; i++)
        {
            vizitat[i] = (bool *)malloc(nr_coloane * sizeof(bool));
            memset(vizitat[i], false, nr_coloane * sizeof(bool));
        }

        Punct *componenta = (Punct *)malloc(nr_linii * nr_coloane * sizeof(Punct));
        int dimensiune_componenta = 0;

        // Găsim prima componentă conexă nevizitată
        for (int i = 0; i < nr_linii && dimensiune_componenta == 0; i++)
        {
            for (int j = 0; j < nr_coloane && dimensiune_componenta == 0; j++)
            {
                if (matrice_copie[i][j] == 'X' && !vizitat[i][j])
                {
                    Punct start = {i, j};
                    gasestePrimaComponenta(matrice_copie, nr_linii, nr_coloane, vizitat, start, componenta, &dimensiune_componenta);
                }
            }
        }

        // Optimizare 1: Dacă componenta are mai puțin de 2 noduri, nu poate fi lanț hamiltonian
        if (dimensiune_componenta == 1)
        {
            // Lanț trivial: un singur nod
            if (lungime_maxima == 0)
            {
                lungime_maxima = 1;
                if (lant_maxim)
                    free(lant_maxim);
                lant_maxim = (Punct *)malloc(sizeof(Punct));
                lant_maxim[0] = componenta[0];
            }

            matrice_copie[componenta[0].x][componenta[0].y] = '+';
            free(componenta);
            for (int i = 0; i < nr_linii; i++)
                free(vizitat[i]);
            free(vizitat);
            continue;
        }

        // Optimizare 2: Verificăm dacă există noduri cu un singur vecin
        int noduri_cu_un_vecin = 0;
        for (int i = 0; i < dimensiune_componenta; i++)
        {
            int vecini = 0;
            Punct p = componenta[i];
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    if (dx == 0 && dy == 0)
                        continue;
                    int x = p.x + dx;
                    int y = p.y + dy;
                    if (x >= 0 && x < nr_linii && y >= 0 && y < nr_coloane && matrice_copie[x][y] == 'X')
                    {
                        vecini++;
                    }
                }
            }
            if (vecini == 1)
                noduri_cu_un_vecin++;
        }

        // Dacă sunt cel puțin 3 noduri cu un singur vecin, nu poate exista lanț hamiltonian
        if (noduri_cu_un_vecin >= 3)
        {
            for (int i = 0; i < dimensiune_componenta; i++)
            {
                matrice_copie[componenta[i].x][componenta[i].y] = '+';
            }
            free(componenta);
            for (int i = 0; i < nr_linii; i++)
                free(vizitat[i]);
            free(vizitat);
            continue;
        }

        // Căutăm lanț hamiltonian doar dacă avem șanse reale să existe
        Punct *lant_curent = (Punct *)malloc(dimensiune_componenta * sizeof(Punct));

        bool **vizitatLant = (bool **)malloc(nr_linii * sizeof(bool *));
        for (int i = 0; i < nr_linii; i++)
        {
            vizitatLant[i] = (bool *)malloc(nr_coloane * sizeof(bool));
            memset(vizitatLant[i], false, nr_coloane * sizeof(bool));
        }

        int indice_lant = 0;
        bool gasit = gasesteLantHamiltonian(matrice_copie, nr_linii, nr_coloane, componenta, dimensiune_componenta,
                                            lant_curent, &indice_lant, vizitatLant);

        if (gasit && indice_lant > lungime_maxima)
        {
            lungime_maxima = indice_lant;
            free(lant_maxim);
            lant_maxim = (Punct *)malloc(indice_lant * sizeof(Punct));
            memcpy(lant_maxim, lant_curent, indice_lant * sizeof(Punct));
        }

        // Marcăm componenta conexă ca moartă
        for (int i = 0; i < dimensiune_componenta; i++)
        {
            matrice_copie[componenta[i].x][componenta[i].y] = '+';
        }

        free(lant_curent);
        free(componenta);
        for (int i = 0; i < nr_linii; i++)
        {
            free(vizitat[i]);
            free(vizitatLant[i]);
        }
        free(vizitat);
        free(vizitatLant);
    }

    // Afișăm rezultatul
    if (lant_maxim != NULL)
    {
        fprintf(fisier_out, "%d\n", lungime_maxima - 1);
        for (int i = 0; i < lungime_maxima; i++)
        {
            if (i == lungime_maxima - 1)
                fprintf(fisier_out, "(%d,%d)", lant_maxim[i].x, lant_maxim[i].y);
            else
                fprintf(fisier_out, "(%d,%d) ", lant_maxim[i].x, lant_maxim[i].y);
        }
        fprintf(fisier_out, "\n");
        free(lant_maxim);
    }
    else
    {
        fprintf(fisier_out, "-1\n");
    }

    // Eliberăm memoria
    for (int i = 0; i < nr_linii; i++)
    {
        free(matrice_copie[i]);
    }
    free(matrice_copie);

    // Continuăm cu subarborii
    if (radacina->Standard != NULL || radacina->RegulaB != NULL)
    {
        char **matrice_standard = (char **)malloc(nr_linii * sizeof(char *));
        char **matrice_regulaB = (char **)malloc(nr_linii * sizeof(char *));

        for (int i = 0; i < nr_linii; i++)
        {
            matrice_standard[i] = (char *)malloc((nr_coloane + 1) * sizeof(char));
            matrice_regulaB[i] = (char *)malloc((nr_coloane + 1) * sizeof(char));
            for (int j = 0; j < nr_coloane; j++)
            {
                matrice_standard[i][j] = matrice[i][j];
                matrice_regulaB[i][j] = matrice[i][j];
            }
        }

        urmatoarea_matrice(matrice_standard, nr_linii, nr_coloane);
        aplicare_regulaB(matrice_regulaB, nr_linii, nr_coloane);

        task4(radacina->RegulaB, matrice_regulaB, nr_linii, nr_coloane, fisier_out);
        task4(radacina->Standard, matrice_standard, nr_linii, nr_coloane, fisier_out);

        for (int i = 0; i < nr_linii; i++)
        {
            free(matrice_standard[i]);
            free(matrice_regulaB[i]);
        }
        free(matrice_standard);
        free(matrice_regulaB);
    }
}

void aplicare_regulaB(char **matrice, int nr_linii, int nr_coloane)
{
    char **copie = malloc(nr_linii * sizeof(char *));
    if (!copie)
        exit(1);
    for (int i = 0; i < nr_linii; i++)
    {
        copie[i] = malloc(nr_coloane * sizeof(char));
        if (!copie[i])
            exit(1);
    }

    for (int i = 0; i < nr_linii; i++)
    {
        for (int j = 0; j < nr_coloane; j++)
        {
            int cnt = 0;
            if (i > 0)
            {
                if (j > 0 && matrice[i - 1][j - 1] == 'X')
                    cnt++;
                if (matrice[i - 1][j] == 'X')
                    cnt++;
                if (j < nr_coloane - 1 && matrice[i - 1][j + 1] == 'X')
                    cnt++;
            }
            if (j > 0 && matrice[i][j - 1] == 'X')
                cnt++;
            if (j < nr_coloane - 1 && matrice[i][j + 1] == 'X')
                cnt++;
            if (i < nr_linii - 1)
            {
                if (j > 0 && matrice[i + 1][j - 1] == 'X')
                    cnt++;
                if (matrice[i + 1][j] == 'X')
                    cnt++;
                if (j < nr_coloane - 1 && matrice[i + 1][j + 1] == 'X')
                    cnt++;
            }
            if (matrice[i][j] == '+')
            {
                if (cnt == 2)
                    copie[i][j] = 'X';
                else
                    copie[i][j] = '+';
            }
            else
            {
                copie[i][j] = 'X';
            }
        }
    }
    for (int i = 0; i < nr_linii; i++)
        for (int j = 0; j < nr_coloane; j++)
            matrice[i][j] = copie[i][j];

    for (int i = 0; i < nr_linii; i++)
        free(copie[i]);
    free(copie);
}

int verifica_matrice_goala(char **matrice, int nr_linii, int nr_coloane)
{
    for (int i = 0; i < nr_linii; i++)
        for (int j = 0; j < nr_coloane; j++)
            if (matrice[i][j] != '+')
                return 0;
    return 1;
}

bool esteInInterior(Punct p, int nr_linii, int nr_coloane)
{
    return p.x >= 0 && p.x < nr_linii && p.y >= 0 && p.y < nr_coloane;
}

void gasestePrimaComponenta(char **matrice, int nr_linii, int nr_coloane, bool **vizitat, Punct start, Punct *componenta, int *dimensiune_componenta)
{
    if (!esteInInterior(start, nr_linii, nr_coloane) || matrice[start.x][start.y] != 'X' || vizitat[start.x][start.y])
    {
        return;
    }
    vizitat[start.x][start.y] = true;
    componenta[*dimensiune_componenta] = start;
    (*dimensiune_componenta)++;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++)
    {
        Punct urm = {start.x + dx[i], start.y + dy[i]};
        gasestePrimaComponenta(matrice, nr_linii, nr_coloane, vizitat, urm, componenta, dimensiune_componenta);
    }
}

int comparaPuncte(const void *a, const void *b)
{
    Punct *p1 = (Punct *)a;
    Punct *p2 = (Punct *)b;
    if (p1->x != p2->x)
        return p1->x - p2->x;
    return p1->y - p2->y;
}

bool gasesteLantHamiltonian(char **matrice, int nr_linii, int nr_coloane,
                            Punct *componenta, int dimensiune_componenta,
                            Punct *lant, int *indice_lant, bool **vizitatLant)
{
    if (*indice_lant == dimensiune_componenta)
        return true;

    if (*indice_lant == 0)
    {
        qsort(componenta, dimensiune_componenta, sizeof(Punct), comparaPuncte);

        for (int startIdx = 0; startIdx < dimensiune_componenta; startIdx++)
        {
            Punct start = componenta[startIdx];
            vizitatLant[start.x][start.y] = true;
            lant[0] = start;
            *indice_lant = 1;

            if (gasesteLantHamiltonian(matrice, nr_linii, nr_coloane,
                                       componenta, dimensiune_componenta,
                                       lant, indice_lant, vizitatLant))
            {
                return true;
            }
            vizitatLant[start.x][start.y] = false;
            *indice_lant = 0;
        }
        return false;
    }

    Punct curent = lant[*indice_lant - 1];

    int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    Punct vecini[8];
    int nr_vecini = 0;

    for (int i = 0; i < 8; i++)
    {
        Punct urm = {curent.x + dx[i], curent.y + dy[i]};
        for (int j = 0; j < dimensiune_componenta; j++)
        {
            if (componenta[j].x == urm.x && componenta[j].y == urm.y &&
                !vizitatLant[urm.x][urm.y])
            {
                vecini[nr_vecini++] = urm;
                break;
            }
        }
    }

    for (int i = 0; i < nr_vecini - 1; i++)
        for (int j = i + 1; j < nr_vecini; j++)
            if (vecini[j].x < vecini[i].x ||
                (vecini[j].x == vecini[i].x && vecini[j].y < vecini[i].y))
            {
                Punct tmp = vecini[i];
                vecini[i] = vecini[j];
                vecini[j] = tmp;
            }

    for (int i = 0; i < nr_vecini; i++)
    {
        Punct urm = vecini[i];
        vizitatLant[urm.x][urm.y] = true;
        lant[*indice_lant] = urm;
        (*indice_lant)++;

        if (gasesteLantHamiltonian(matrice, nr_linii, nr_coloane,
                                   componenta, dimensiune_componenta,
                                   lant, indice_lant, vizitatLant))
        {
            return true;
        }
        (*indice_lant)--;
        vizitatLant[urm.x][urm.y] = false;
    }

    return false;
}

void gasesteLantHamiltonianSimplu(char **matrice, int nr_linii, int nr_coloane, Punct *lant, int *nr_elemente)
{
    *nr_elemente = 0;

    if (nr_linii == 0 || nr_coloane == 0)
    {
        return;
    }

    bool **vizitat = (bool **)malloc(nr_linii * sizeof(bool *));
    for (int i = 0; i < nr_linii; i++)
    {
        vizitat[i] = (bool *)malloc(nr_coloane * sizeof(bool));
        for (int j = 0; j < nr_coloane; j++)
        {
            vizitat[i][j] = false;
        }
    }

    Punct *componenta = (Punct *)malloc(nr_linii * nr_coloane * sizeof(Punct));
    int dimensiune_componenta = 0;

    for (int i = 0; i < nr_linii && dimensiune_componenta == 0; i++)
    {
        for (int j = 0; j < nr_coloane && dimensiune_componenta == 0; j++)
        {
            if (matrice[i][j] == 'X' && !vizitat[i][j])
            {
                Punct start = {i, j};
                gasestePrimaComponenta(matrice, nr_linii, nr_coloane, vizitat, start, componenta, &dimensiune_componenta);
            }
        }
    }

    if (dimensiune_componenta == 0)
    {
        goto eliberare;
    }

    bool **vizitatLant = (bool **)malloc(nr_linii * sizeof(bool *));
    for (int i = 0; i < nr_linii; i++)
    {
        vizitatLant[i] = (bool *)malloc(nr_coloane * sizeof(bool));
        for (int j = 0; j < nr_coloane; j++)
        {
            vizitatLant[i][j] = false;
        }
    }

    Punct *lant_temp = (Punct *)malloc(dimensiune_componenta * sizeof(Punct));
    int indice_lant = 0;

    if (gasesteLantHamiltonian(matrice, nr_linii, nr_coloane, componenta, dimensiune_componenta, lant_temp, &indice_lant, vizitatLant))
    {
        for (int i = 0; i < dimensiune_componenta; i++)
        {
            lant[i] = lant_temp[i];
        }
        *nr_elemente = dimensiune_componenta;
    }
eliberare:
    for (int i = 0; i < nr_linii; i++)
    {
        free(vizitatLant[i]);
    }
    free(vizitatLant);
    free(lant_temp);

    for (int i = 0; i < nr_linii; i++)
    {
        free(vizitat[i]);
    }
    free(vizitat);
    free(componenta);
}

void bonus(Elem *Generatie, char **matrice, int n, int m, int k)
{
    // Parcurgem stiva de la ultima generatie inapoi spre 1
    while (Generatie != NULL || k != 0)
    {
        NODE *celula = Generatie->top;
        // Pentru fiecare celulă modificată în această generație, inversăm modificarea
        while (celula != NULL)
        {
            // Daca era X, devine +, altfel devine X
            matrice[celula->l][celula->c] = (matrice[celula->l][celula->c] == 'X') ? '+' : 'X';
            celula = celula->next;
        }
        k--;
        Generatie = Generatie->next;
    }
}

void initializare_generatii(Elem **Generatie)
{
    // Prima generație
    NODE *lista1 = NULL;
    introducere_nod_sf(&lista1, 0, 1);
    introducere_nod_sf(&lista1, 1, 2);
    push(Generatie, lista1, 1);

    // A doua generație
    NODE *lista2 = NULL;
    introducere_nod_sf(&lista2, 2, 2);
    introducere_nod_sf(&lista2, 3, 3);
    push(Generatie, lista2, 2);

    // A treia generație
    NODE *lista3 = NULL;
    introducere_nod_sf(&lista3, 4, 0);
    introducere_nod_sf(&lista3, 4, 1);
    introducere_nod_sf(&lista3, 4, 2);
    push(Generatie, lista3, 3);
}