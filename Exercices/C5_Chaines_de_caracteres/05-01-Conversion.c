#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

bool isInteger(char *arg1) {
    if (*arg1 == '-' || *arg1 == '+') {
        arg1++;
    }

    if (*arg1 == '\0') {
        return false;
    }

    while (isdigit((unsigned char)*arg1)) {
        ++arg1;
    }

    return *arg1 == '\0';
}

int main(int argc, char *argv[]) {

    if (argc != 3 || !(isInteger(argv[1]) && isInteger(argv[2]))) {
        printf("[!] Usage : ./main <INT1> <INT2>");
        return -1;
    }


    errno = 0;
    long long lhs, rhs, result;

    lhs = strtoll(argv[1], NULL, 10);
    if(errno == ERANGE){
        printf("[e] %s is too long!\n", argv[1]);
        return EXIT_FAILURE;
    }

    rhs = strtoll(argv[2], NULL, 10);
    if(errno == ERANGE){
        printf("[e] %s is too long!\n", argv[2]);
        return EXIT_FAILURE;
    }

    result = lhs * rhs;

    if (lhs != 0 && result / lhs != rhs) {
        print("[e] %s * %s is too long!\n", argv[1], argv[2]);
        return EXIT_FAILURE;
    }  
    
     

}
