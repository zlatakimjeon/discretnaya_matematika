#ifndef SUBSET_ITERATOR_H
#define SUBSET_ITERATOR_H

typedef struct set set_t;

typedef struct {
    int n;
    int mask;
    int total;
    set_t value;
} iterator_t;

void iterator_init(iterator_t *it, int n);
void iterator_destroy(iterator_t *it);
int iterator_has_next(const iterator_t *it);
void iterator_next(iterator_t *it);
const set_t *iterator_value(const iterator_t *it);

#endif