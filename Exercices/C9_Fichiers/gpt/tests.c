#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Console.h>

#include "09-05-Gestion_produit.h"

void test_load_data() {
    CU_ASSERT_EQUAL(load_data(), 3);
}

int main() {
    CU_pSuite suite = NULL;

    if (CU_initialize_registry() != CUE_SUCCESS) return CU_get_error();

    suite = CU_add_suite("App gestion de produit", NULL, NULL);
    if (!suite) goto out;

    if (!CU_add_test(suite, "load data", test_load_data)) goto out;

    CU_console_run_tests();



out:
    CU_cleanup_registry();
    return CU_get_error();
}
