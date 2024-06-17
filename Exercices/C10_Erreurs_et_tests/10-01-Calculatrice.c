#include <math.h>
#include <CUnit/CUnit.h>
#include <CUnit/Console.h>

int calculer(int nombre1, int nombre2, char operateur) {

    switch (operateur) {
    case '+':
        return nombre1 + nombre2;

    case '-':
        return nombre1 - nombre2;

    case '*':
        return nombre1 * nombre2;

    case '/':
        if (nombre2 == 0) {
            // Gérer l'erreur de division par zéro
            return -1;
        } else {
            return nombre1 / nombre2;
        }

    case '^':
        // Puissance non implémentée avec des entiers
        return (int)pow((double)nombre1, (double)nombre2);

    default:
        // Gérer l'opérateur invalide
        return -1;
    }
}
void test_add() {
    CU_ASSERT_EQUAL(calculer(2, 3, '+'), 5);
    CU_ASSERT_EQUAL(calculer(-3, 2, '+'), -1);
}

void test_sub() {
    CU_ASSERT_EQUAL(calculer(2, 3, '-'), -1);
}

void test_mult() {
    CU_ASSERT_EQUAL(calculer(2, 5, '*'), 10);
    CU_ASSERT_EQUAL(calculer(3, 4, '*'), 12);
}

void test_div() {
    CU_ASSERT_EQUAL(calculer(8, 2, '/'), 4);
    CU_ASSERT_EQUAL(calculer(-10, 5, '/'), -2);
    CU_ASSERT_EQUAL(calculer(1, 0, '/'), -1);
}

void test_pow() {
    CU_ASSERT_EQUAL(calculer(3, 2, '^'), 9);
}

int main() {

    CU_pSuite pSuite = NULL;
    if (CU_initialize_registry() != CUE_SUCCESS) return CU_get_error();

    pSuite = CU_add_suite("calc_test", NULL, NULL);
    if (!pSuite) goto out;

    if ((!CU_add_test(pSuite, "Operator +", test_add)) ||
        (!CU_add_test(pSuite, "Operator-", test_sub)) ||
        (!CU_add_test(pSuite, "Operator*", test_mult)) ||
        (!CU_add_test(pSuite, "Operator/", test_div)) ||
        (!CU_add_test(pSuite, "Operator^", test_pow))) goto out;

    CU_console_run_tests();


out:
    CU_cleanup_registry();
    return CU_get_error();
}
