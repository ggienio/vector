#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "vector.h"

vector *vec_new(int len) {
    vector *vec = malloc(sizeof(vector));
    
    if (vec == NULL) {
        return NULL;
    }

    if (len < 1) {
        return NULL;
    }

    vec->elements = malloc(len * sizeof(VECTOR_TYPE));

    if (vec->elements == NULL) {
        free(vec);
        return NULL;
    }

    vec->len = 0;
    vec->allocated = len;

    return vec;
}

bool vec_out_of_bounds(vector *vec, int index) {
    return index >= vec->len || index < 0;
}

int vec_append(vector *vec, VECTOR_TYPE element) {
    if (vec == NULL) {
        return -1;
    }

    if (vec->allocated <= vec->len) {
        VECTOR_TYPE *new_elements = realloc(vec->elements, (vec->allocated + REALLOC_STEP) * sizeof(VECTOR_TYPE));
        if (vec->elements == NULL) {
            return -1;
        }
        vec->elements = new_elements;
        vec->allocated += REALLOC_STEP;
    }

    vec->elements[vec->len] = element;
    vec->len++;
    return 0;
}

int vec_get(vector *vec, int index, VECTOR_TYPE *result) {
    if (vec == NULL || vec_out_of_bounds(vec, index)) {
        return -1;
    }

    *result = vec->elements[index];
    return 0;
}

int vec_set(vector *vec, int index, VECTOR_TYPE value) {
    if (vec == NULL || vec_out_of_bounds(vec, index)) {
        return -1;
    }

    vec->elements[index] = value;
    return 0;
}

int vec_insert(vector *vec, int index, VECTOR_TYPE value) {
    if (vec == NULL || vec_out_of_bounds(vec, index)) {
        return -1;
    }

    int append_result = vec_append(vec, 0); // in case we need to reallocate memory
    
    if (append_result != 0) {
        return -1;
    }

    for (int i = vec->len - 2; i >= index; i--) {
        VECTOR_TYPE temp;
        int get_result = vec_get(vec, i, &temp);
        int set_result = vec_set(vec, i + 1, temp);
        if (get_result + set_result != 0) {
            return -1;
        }
    }

    int insert_result = vec_set(vec, index, value);
    
    if (insert_result != 0) {
        return -1;
    }
    return 0;
}

int vec_pop(vector *vec, int index) {
    if (vec == NULL || vec_out_of_bounds(vec, index)) {
        return -1;
    }

    for (int i = index + 1; i < vec->len; i++) {
        VECTOR_TYPE temp;
        int get_result = vec_get(vec, i, &temp);
        int set_result = vec_set(vec, i - 1, temp);
        if (get_result + set_result != 0) {
            return -1;
        }
    }

    // shrink the allocated space if needed
    vec->len--;

    if (vec->allocated - vec->len >= REALLOC_STEP) {
        VECTOR_TYPE *new_elements = realloc(vec->elements, (vec->allocated - REALLOC_STEP) * sizeof(VECTOR_TYPE));
        if (new_elements == NULL) {
            return -1;
        }
        vec->elements = new_elements;
        vec->allocated -= REALLOC_STEP;
    }

    return 0;
}

int vec_reverse(vector *vec) {
    if (vec == NULL) {
        return -1;
    }

    for (int i = 0; i < vec->len / 2; i++) {
        VECTOR_TYPE r_temp;
        VECTOR_TYPE l_temp;
        int get_result1 = vec_get(vec, vec->len - 1 - i, &r_temp);
        int get_result2 = vec_get(vec, i, &l_temp);
        int set_result1 = vec_set(vec, vec->len - 1 - i, l_temp);
        int set_result2 = vec_set(vec, i, r_temp);
        if (get_result1 + get_result2 + set_result1 + set_result2 != 0) {
           return -1;
        }
    }

    return 0;
}

int vec_print(vector *vec) {
    if (vec == NULL) {
        return -1;
    }

    printf("[");

    for (int i = 0; i < vec->len; i++) {
        VECTOR_TYPE value;
        VECTOR_TYPE result = vec_get(vec, i, &value);
        if (result == -1) {
            return -1;
        }

        #if VECTOR_TYPE==int
            printf("%d", value);
        #elif VECTOR_TYPE==double || VECTOR_TYPE==float
            printf("%f", value);
        #elif VECTOR_TYPE==char
            printf("%c", value);
        #endif

        if (i < vec->len - 1) {
            printf(", ");
        }
    }

    printf("]\n");

    return 0;
}

int vec_shrink(vector *vec) {
    if (vec == NULL) {
        return -1;
    }
    
    if (vec->len == vec->allocated) {
        return 0;
    }
    
    VECTOR_TYPE *new_elements = realloc(vec->elements, (vec->len) * sizeof(VECTOR_TYPE));
    
    if (new_elements == NULL) {
        return -1;
    }

    vec->elements = new_elements;
    vec->allocated = vec->len;

    return 0;
}

void vec_free(vector *vec) {
    if (vec) {
        free(vec->elements);
        free(vec);
    }
}