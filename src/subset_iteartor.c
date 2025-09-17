код программы:
#include <stdio.h>
#include <stdlib.h>

// Структура подмножества
typedef struct Set {
    int *elements;   // Элементы подмножества
    int size;        // Количество элементов
} set_t;

// Структура итератора
typedef struct SetIterator {
    set_t value;     // Текущее подмножество
    unsigned n;      // Размер множества {0, ..., n-1}
    unsigned mask;   // Текущее состояние (битовая маска)
    unsigned total;  // Всего подмножеств = 2^n
} iterator_t;

// Инициализация итератора
void iterator_init(iterator_t *i, unsigned n) {
    i->n = n;
    i->mask = 0;
    i->total = 1U << n;
    i->value.elements = (int *)malloc(n * sizeof(int));
    i->value.size = 0;
}

// Получение текущего значения
const set_t *iterator_value(const iterator_t *i) {
    return &i->value;
}

// Есть ли ещё подмножества
int iterator_has_next(const iterator_t *i) {
    return i->mask < i->total;
}

// Переход к следующему подмножеству
void iterator_next(iterator_t *i) {
    i->value.size = 0;
    for (unsigned bit = 0; bit < i->n; ++bit) {
        if (i->mask & (1U << bit)) {
            i->value.elements[i->value.size++] = bit;
        }
    }
    i->mask++;
}

// Освобождение ресурсов
void iterator_destroy(iterator_t *i) {
    free(i->value.elements);
}

// Пример использования
int main() {
    unsigned n;
    printf("Введите n: ");
    scanf("%u", &n);

    iterator_t it;
    iterator_init(&it, n);

    while (iterator_has_next(&it)) {
        iterator_next(&it);
        const set_t *s = iterator_value(&it);
        printf("{ ");
        for (int j = 0; j < s->size; ++j) {
            printf("%d ", s->elements[j]);
        }
        printf("}\n");
    }

    iterator_destroy(&it);
    return 0;
}
