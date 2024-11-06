#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "division_program.h" // Include the header file

// Include the header file of the division program
double divide(double numerator, double denominator);

// Test case for the divide function
void test_divide(void) {
    CU_ASSERT_DOUBLE_EQUAL(divide(10, 2), 5.0, 0.0001);
    CU_ASSERT_DOUBLE_EQUAL(divide(10, 0), 0.0, 0.0001); // Should handle division by zero
    CU_ASSERT_DOUBLE_EQUAL(divide(-10, 2), -5.0, 0.0001);
    CU_ASSERT_DOUBLE_EQUAL(divide(10, -2), -5.0, 0.0001);
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Add a suite to the registry
    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("Suite_1", 0, 0);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "test of divide()", test_divide)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

