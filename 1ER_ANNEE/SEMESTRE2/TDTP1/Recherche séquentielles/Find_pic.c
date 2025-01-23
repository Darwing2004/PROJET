int trouverPic(int tableau[], int NTab) {
    if (NTab == 0) {
        return -1;
    }
    if (NTab == 1 || tableau[0] > tableau[1]) {
        return 0;
    }
    if (tableau[NTab - 1] > tableau[NTab - 2]) {
        return NTab - 1;
    }
    for (int i = 1; i < NTab - 1; i++) {
        if (tableau[i] > tableau[i - 1] && tableau[i] > tableau[i + 1]) {
            return i;
        }
    }
    return -1;
}