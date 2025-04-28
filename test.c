#include <stdio.h>
#include "vector.h"

int main(void) {
    vector *my_vector = vec_new(2);
    
    vec_append(my_vector, 1);
    vec_append(my_vector, 1322);

    vec_print(my_vector);
    printf("len: %d, allocated: %d\n", my_vector->len, my_vector->allocated);

    vec_append(my_vector, -12);
    vec_append(my_vector, 2);
    vec_append(my_vector, -1);

    vec_print(my_vector);
    printf("len: %d, allocated: %d\n", my_vector->len, my_vector->allocated);

    vec_append(my_vector, 1);
    vec_append(my_vector, 3);
    vec_append(my_vector, 5);
    vec_append(my_vector, 7);
    vec_append(my_vector, 9);

    vec_print(my_vector);
    printf("len: %d, allocated: %d\n", my_vector->len, my_vector->allocated);

    vec_pop(my_vector, 5);
    vec_pop(my_vector, 0);

    vec_print(my_vector);
    printf("len: %d, allocated: %d\n", my_vector->len, my_vector->allocated);

    vec_shrink(my_vector);

    vec_print(my_vector);
    printf("len: %d, allocated: %d\n", my_vector->len, my_vector->allocated);

    vec_free(my_vector);
}
