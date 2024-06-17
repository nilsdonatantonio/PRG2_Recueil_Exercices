#include <stdio.h>
#include <stdbool.h>

#define filename "test.txt"
// *** TODO: counting functions
int countc(FILE *stream) {
    int out = 0;

    while (fgetc(stream) != EOF) {
        out++;
    }
    return out - 1; //Omit return char at the end
}

int countm(FILE *stream) {
    char c;
    bool curw = false;
    int out = 0;
    while ((c = fgetc(stream)) != EOF) {
        if (c == ' ' || c == '\n') {
            curw = false;
        } else if (!curw) {
            curw = true;
            out++;
        }
    }
    return out;
}

int countl(FILE *stream) {
    char c;
    int out = 0;
#if 0
    while ((c = fgetc(stream)) != EOF) {
        if (c == '\n') {
            out++;
        }
    }
#endif /* 0 */
    char s[50];
    while (fgets(s, 50, stream) != NULL) {
        out++;
    }
    return out;
}

int main(int argc, char **argv) {

    FILE *fin;

    // *** TODO: open file
    fin = fopen(filename, "r");
    if (!fin) {
        printf("Can't open %s\n", filename);
        return -1;
    }

    // count characters in file

    printf("%s contains %d characters\n", filename, countc(fin));

    fin = freopen(filename, "r", fin);
    printf("%s contains %d words\n", filename, countm(fin));

    fin = freopen(filename, "r", fin);
    printf("%s contains %d lines\n", filename, countl(fin));

    fclose(fin);
    return 0;
}
