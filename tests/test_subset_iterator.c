#include <assert.h>
#include <string.h>
#include "../src/subset_iterator.h"

// Тест инициализации итератора
void test_iterator_init() {
    iterator_t it;
    iterator_init(&it, 3);
    
    assert(it.n == 3);
    assert(it.mask == 0);
    assert(it.total == 8); // 2^3 = 8
    assert(it.value.elements != NULL);
    assert(it.value.size == 0);
    
    iterator_destroy(&it);
    printf("✓ test_iterator_init passed\n");
}

// Тест перебора всех подмножеств
void test_iterator_all_subsets() {
    iterator_t it;
    iterator_init(&it, 2);
    
    int expected_counts[] = {0, 1, 1, 2}; // размеры подмножеств для n=2
    int expected_elements[4][2] = {
        {}, {0}, {1}, {0, 1}
    };
    
    int count = 0;
    while (iterator_has_next(&it)) {
        iterator_next(&it);
        const set_t *s = iterator_value(&it);
        
        assert(s->size == expected_counts[count]);
        for (int i = 0; i < s->size; i++) {
            assert(s->elements[i] == expected_elements[count][i]);
        }
        count++;
    }
    
    assert(count == 4); // 2^2 = 4 подмножества
    iterator_destroy(&it);
    printf("✓ test_iterator_all_subsets passed\n");
}

// Тест пустого множества
void test_iterator_empty_set() {
    iterator_t it;
    iterator_init(&it, 0);
    
    assert(iterator_has_next(&it));
    iterator_next(&it);
    const set_t *s = iterator_value(&it);
    assert(s->size == 0); // только пустое подмножество
    
    assert(!iterator_has_next(&it)); // только одно подмножество
    
    iterator_destroy(&it);
    printf("✓ test_iterator_empty_set passed\n");
}

// Тест has_next
void test_iterator_has_next() {
    iterator_t it;
    iterator_init(&it, 1);
    
    assert(iterator_has_next(&it));
    iterator_next(&it); // пустое множество
    assert(iterator_has_next(&it));
    iterator_next(&it); // {0}
    assert(!iterator_has_next(&it));
    
    iterator_destroy(&it);
    printf("✓ test_iterator_has_next passed\n");
}

// Тест корректности количества подмножеств
void test_iterator_count() {
    iterator_t it;
    iterator_init(&it, 4);
    
    int count = 0;
    while (iterator_has_next(&it)) {
        iterator_next(&it);
        count++;
    }
    
    assert(count == 16); // 2^4 = 16
    iterator_destroy(&it);
    printf("✓ test_iterator_count passed\n");
}
