
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const char *compare = "subcmd";

bool is_in_substr(const char *str) {
    if (strstr(str, compare) != NULL) {
        return true;
    }
    return false;
}


int main(int argc, char *argv[]) {
    const char *tabstr[] = {
        "commande1 subcmd",
        "autre commande",
        "encore subcmd ici",
        "dernière chaîne"
    };


}
