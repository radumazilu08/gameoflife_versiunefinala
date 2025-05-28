#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXN 100 

typedef struct N
{
    int l, c;
    struct N *next;
} NODE;

typedef struct Elem
{
    int k;
    NODE *top;
    struct Elem *next;
} Elem;

//arborele pt task 3
typedef struct Node
{
    NODE *celule_modificate; // Lista de coordonate ale celulelor care și-au schimbat starea
    struct Node *RegulaB, *Standard;
} Node;

typedef struct {
    int x, y;
} Punct;

// task 1
void citirematrice(char **matrice, int n, int m, FILE *fis1);
int vecini(char **matrice, int i, int j, int n, int m);
void urmatoarea_matrice(char **matrice, int n, int m);
void afisarematrice(char **matrice, int n, int m, FILE *fis2);


// task 2
void push(Elem **Generatie, NODE *newcel, int gen);
void introducere_nod_in(NODE **head, int l, int c);
void introducere_nod_sf(NODE **head, int l, int c);
void print(FILE *Output_file, Elem *Generatie);
Elem *pop(Elem **top);
void free_celule(NODE *Cel);
void free_generatii(Elem *Gen);
void push2(Elem **Generatie, NODE *newcel);


// task 3
NODE *regulaB(char **matrice, int n, int m);
NODE *determinare_celule_modificate(char **matrice_veche, char **matrice_noua, int n, int m);
void parcurgerePreordine(Node *radacina, FILE *fis2, char **matrice, int n, int m);
void freeTree(Node *root);
Node* buildTree(char **matrice, int n, int m, int niveluri);

// task 4
void task4(Node *radacina, char **matrice, int n, int m, FILE *fis2);
void aplicare_regulaB(char **matrice, int n, int m);
int verifica_matrice_goala(char **matrice, int n, int m);
bool esteInInterior(Punct p, int nr_linii, int nr_coloane);
void gasestePrimaComponenta(char **matrice, int nr_linii, int nr_coloane, bool **vizitat, Punct start, Punct *componenta, int *dimensiune_componenta);
bool gasesteLantHamiltonian(char **matrice, int nr_linii, int nr_coloane, Punct *componenta, int dimensiune_componenta, Punct *lant, int *indice_lant, bool **vizitatLant);
void gasesteLantHamiltonianSimplu(char **matrice, int nr_linii, int nr_coloane, Punct *lant, int *nr_elemente);

// bonus
void bonus(Elem *Generatie_invers, char **matrice, int n, int m);
void initializare_generatii(Elem **Generatie);