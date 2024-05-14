#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

//===========================
//        Exercice 1
//===========================


// bool is_palindrome(const char *mot) {
//     bool palindrome = true;

//     size_t i = 0, j = strlen(mot) - 1;
//     while (i <= j) {
//         if (mot[i] != mot[j]) palindrome = false;
//         ++i;
//         --j;
//     }

//     return palindrome;
// }

// int main() {

//     printf("Saisir un mot (que des lettres dans [a-z,A-Z]): ");

//     char mot[20];
//     scanf("%19s", mot);

//     for (size_t i = 0; i < 19; ++i) mot[i] = toupper(mot[i]);

//     if (is_palindrome(mot)) {
//         printf("%s est un palindrome\n", mot);
//     } else {
//         printf("%s n'est pas un palindrome\n", mot);
//     }

//     return 0;
// }

//===========================
//        Exercice 2
//===========================

// bool lire_ligne(char *chaine, size_t max) {

//     size_t i;
//     for (i = 0; i < max - 1; ++i) {
//         char c;

//         if (scanf("%c", &c) != 1) return false;
//         else if (c == '\n')break;

//         chaine[i] = c;
//     }

//     chaine[i] = '\0';
//     return true;
// }

// int main() {
//     printf("[?] Saisissez une ligne de mots et parenthèses: ");
//     char chaine[255];

//     if (!lire_ligne(chaine, sizeof(chaine))) {
//         printf("[i] Il manque des parenthèses :(\n");
//     }

//     int n = 0;
//     for (char *t = chaine; *t != '\0'; ++t) {
//         if (*t == '(') ++n;
//         if (*t == ')') --n;

//         if (n < 0) break;
//     }

//     if (n == 0) printf("[i] Le compte est bon :)\n");
//     else printf("[i] Il manque des parenthèses :(\n");

//     return 0;
// }

//===========================
//        Exercice 3
//===========================

int main(void) {
    char line[255], sline[255];
    int ll = 0, pos = -1, len = 0;

    printf("[?] Saisissez une ligne de mots: ");

    fgets(line, sizeof(line), stdin);
    while (!(line[ll] == '\n' || line[ll] == '\0')) ++ll;
    line[ll] = '\0';

    if (ll == 0) {
        printf("[i] Ligne vide.\n");
        return -1;
    }

    printf("[i] La ligne contient %d caractères\n", ll);

    printf("[?] Extraire APRES combien de caractères ? ");
    if (scanf("%d", &pos) == 0 || pos < 0 || pos >= ll) {
        printf("[!] Erreur: position impossible !\n");
    }

    printf("[?] Extraire combien de caractères ? ");
    if (scanf("%d", &len) == 0 || len <= 0 || len >= (ll - pos)) {
        printf("[!] Erreur: longueur impossible !\n");
        return -1;
    }

    size_t i = 0;
    for (i = 0; i < len; ++i) {
        sline[i] = line[pos + i];
    }
    sline[i] = '\0';

    printf("[i] La sous-chaîne extraite de la chaîne est : \\%s\\ \n\n", sline);

    return 0;




}
