#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer;

int divide(const int lhs, const int rhs) {
    if (rhs == 0) {
        longjmp(buffer, 1);
    }

    return lhs / rhs;
}

int main() {
    int lhs = 4;
    int rhs = 0;

    if ((setjmp(buffer)) == 0) {
        printf("%d / %d = %d\n", lhs, rhs, divide(lhs, rhs));
    } else {
        printf("Can't divide by zero\n");
    }
}
