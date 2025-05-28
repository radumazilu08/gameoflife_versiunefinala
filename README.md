# gameoflife_versiunefinala
--DESCRIEREA PROIECTULUI--

Game of Life este un 'joc' care demonstreaza cum, printr-un set de reguli simple, se pot genera comportamente complexe. Nu este propriu-zis un joc, ci un automat celular, adica un model matematic ce descrie functionarea sistemelor de calcul (hardware sau software).

--REGULI--

Game of Life se desfasoara pe o grila de celule patrate, in care fiecare celula poate avea doua stari: vie sau moarta. Celulele interactioneaza, de la un moment de timp la altul (denumite generatii), cu cele 8 celule vecine, dupa urmatoarele reguli:

1. Orice celula vie cu mai putin de doi vecini in viata moare (subpopulare).
2. Orice celula vie cu doi sau trei vecini vii traieste in continuare.
3. Orice celula vie cu mai mult de trei vecini vii moare (suprapopulare).
4. Orice celula moarta cu exact trei vecini devine o celula vie (reproducere).

---------------------------------------------------------------------------------------------------------------------------

--TASK 1  SIMULAREA JOCULUI--

Se porneste de la o configuratie initiala a grilei.
Se aplica regulile clasice K generatii.
Fiecare generatie este afisata sub forma de matrice.

Scop: Sa vedem cum evolueaza configuratia in timp.

---------------------------------------------------------------------------------------------------------------------------

--TASK 2  MEMORAREA DIFERENTELOR--

In loc sa stocam intreaga grila la fiecare pas, memoram doar celulele care isi schimba starea intre generatii.
Se foloseste o stiva de liste:
	-fiecare element din stiva corespunde unei generatii.
	-fiecare lista contine coordonatele celulelor care s-au modificat.

Avantaj: Economie de memorie si evidentierea clara a modificarilor.

---------------------------------------------------------------------------------------------------------------------------

--TASK 3  ARBORI BINARI DE GENERATII--

Se construieste un arbore binar de generatii:
	-fiul stang: aplica o regula alternativa (Regula B): orice celula moarta cu exact 2 vecini devine vie.
	-fiul drept: aplica regulile clasice.
Se construieste arborele pentru K niveluri.
Se afiseaza matricea fiecarui nod al arborelui in parcurgere preordine.

Scop: Sa comparam evolutia cu reguli diferite si sa observam diferentele.

---------------------------------------------------------------------------------------------------------------------------

--TASK 4  CAUTAREA LANTURILOR HAMILTONIENE--

Fiecare configuratie (nod din arbore) este interpretata ca un graf:
	-noduri: celule vii
	-muchii: existenta de vecini intre celule
Se cauta cel mai lung lant Hamiltonian in fiecare componenta conexa:
	-lant in care fiecare celula vie apare o singura data
	-cel mai lung posibil
Outputul: lungimea lantului + coordonatele celulelor parcurse

Scop: Sa determinam daca o configuratie poate fi "desenata" fara a trece de doua ori prin aceeasi celula.
