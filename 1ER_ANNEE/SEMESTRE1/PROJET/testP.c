#include <stdio.h>
#include <stdlib.h>

void remplir_plateau(int t[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
}

int verif_vsx(int t[], int n, int v) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == 1) {
            count++;
        }
    }
    if (count != v) {
        printf("FIN DE PARTIE : PAS ASSEZ DE VAISSEAUX SPATIAUX");
        exit(-1);
    }
    return 0;
}

int compter_coups(int c[]) {
    int count = 0;
    for (int i = 0; c[i] != -1; i++) {
        scanf("%d", &c[i]);

    }

    while (c[count] != -1){
        count++;
    }
    return count;
}

void verif_liste_coups(int n_coups, int n, int c[]) {
    for (int i = 0; i < n_coups; i++) {
        if (c[i] > n) {
            printf("COUP INTERDIT : PARTIE FINIE\n");
            exit(-1);
        }
    }
    if (n_coups % 2 != 0) {
        printf("COUP MANQUANT : PARTIE INCOMPLETE\n");
        exit(-1);
    }
}

void combat(int c[], int ta[], int tb[], int n_coups, char prems, int pa, int pb, int v, int n) {
    pa = 0;
    pb = 0;

    for (int i = 0; i < n_coups; i += 2) {
        pa += ta[c[i]]; 
        pb += tb[c[i + 1]];
    }

    if (pa > pb) {
        printf("PARTIE FINIE : GAGNANT ALICE : %d a %d\n", pa, pb);
    } else if (pb > pa) {
        printf("PARTIE FINIE : GAGNANT BERNARD : %d a %d\n", pb, pa);
    } else {
        printf("PARTIE FINIE A EGALITE : %d a %d\n", pa, pb);
    }
}

int main() {
    int n, v;
    char espace, A, B;
    int t[1000], c[1000];
    char prems, pa = 0, pb = 0;

    scanf("%d %d", &n, &v);
    scanf(" %c", &espace);
    scanf(" %c", &A);

    int ta[n], tb[n];

    remplir_plateau(ta, n);

    scanf(" %c", &espace);
    scanf(" %c", &B);

    remplir_plateau(tb, n);

    verif_vsx(ta, n, v);
    verif_vsx(tb, n, v);

    scanf(" %c", &espace);
    scanf(" %c", &prems);
    scanf(" %c", &espace);

    int n_coups = compter_coups(c);

    verif_liste_coups(n_coups, n, c);

    printf("TAILLE DU TABLEAU : %d\n", n);
    printf("NOMBRE DE VAISSEAUX SPATIAUX: %d\n", v);
    printf("NOMBRE DE COUPS : %d\n", n_coups);

    combat(c, ta, tb, n_coups, prems, pa, pb, v, n);

    printf("PARTIE TERMINEE : FIN DU JEU\n");
}
