#include <stdio.h>

// Объявления тестовых функций
void test_iterator_init();
void test_iterator_all_subsets();
void test_iterator_empty_set();
void test_iterator_has_next();
void test_iterator_count();

int main() {
    printf("Running subset iterator tests\n");
    
    test_iterator_init();
    test_iterator_all_subsets();
    test_iterator_empty_set();
    test_iterator_has_next();
    test_iterator_count();
    
    printf("\nAll tests passed\n");
    return 0;
}