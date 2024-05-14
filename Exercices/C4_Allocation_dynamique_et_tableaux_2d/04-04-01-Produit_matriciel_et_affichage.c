#include <stdio.h>
#include <stdarg.h>

typedef double vec3[3];
typedef double mat3x3[3][3];

void mat_vec_mult(const mat3x3 m, const vec3 v, vec3 w) {
    for (int i = 0; i < 3; i++) {
        w[i] = 0;
        for (int j = 0; j < 3; j++) {
            w[i] += m[i][j] * v[j];
        }
    }
}

void display_vec(const vec3 v) {
    printf("[");
    for (int i = 0; i < 3; ++i) {
        if (i) printf(", ");
        printf("%g", v[i]);
    }
    printf("]");
}

void display_mat(const mat3x3 m) {
    printf("[");
    for (int i = 0; i < 3; ++i) {
        if (i) printf(", ");
        display_vec(m[i]);
    }
    printf("]");
}

int print_mat(const char *fmt, ...) {
    int n = 0;
    va_list ap;
    va_start(ap, fmt);

    for (const char *p = fmt; *p != '\0'; ++p) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        ++n;
        switch (*++p) {
        case 'm':
            display_mat((double(*)[3]) va_arg(ap, double(*)[3]));
            break;
        case 'v':
            display_vec((double *)va_arg(ap, double *));
        default:
            return -1;
        }
    }
    va_end(ap);
    return n;
}

int main() {
    mat3x3 m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vec3 v = { 1, 2, 3 };
    vec3 w = {};

    mat_vec_mult(m, v, w);

}
