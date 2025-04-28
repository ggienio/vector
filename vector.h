#ifndef VECTOR_H
#define VECTOR_H

/* VECTOR_TYPE
 * the type stored in the vectors
 */
#ifndef VECTOR_TYPE
#define VECTOR_TYPE int 
#endif

/* REALLOC_STEP
 * how much elements to expand the vector by when it runs out of space
 */
#ifndef REALLOC_STEP
#define REALLOC_STEP 4 
#endif

/* vector
 * @param len number of elements in the vector
 * @param allocated number of elements that may currently be stored
 * @param elements pointer to the array of elements
 */
typedef struct {
    int len;
    int allocated;
    VECTOR_TYPE *elements;
} vector;

/* vec_new creates a new vector of the specified length
 * @param len lenght of the vector
 * @return a pointer to the vector if successfull, NULL otherwise
*/
vector *vec_new(int len);

/* vec_append appends to the end of the vector
 * @param vec vector to append to
 * @param element int to append
 * @return 0 if successful, -1 otherwise
 */
int vec_append(vector *vec, VECTOR_TYPE element);

/* vec_get retrieves the element at the specified index
 * @param vec vector to in question
 * @param index the index of the element 
 * @param result pointer to store the retrieved value in
 * @return 0 if successful, NULL otherwise
 */
int vec_get(vector *vec, int index, VECTOR_TYPE *result);

/* vec_set sets the element at the specified index to the specified value
 * @param vec the vector
 * @param index the index of the element 
 * @param value the value to set
 * @return 0 if successful, -1 otherwise
 */
int vec_set(vector *vec, int index, VECTOR_TYPE value);

/* vec_insert shifts all elements starting from the specified index by 1 and sets the element at the specified index to the specified value
 * @param vec the vector
 * @param index the index of the element 
 * @param value the value to set
 * @return 0 if successful, -1 otherwise
 */
int vec_insert(vector *vec, int index, VECTOR_TYPE value);

/* vec_insert shifts all elements starting from the specified index by -1 (essentially removing the element at the specified index)
 * @param vec the vector
 * @param index the index of the element to remove
 * @return 0 if successful, -1 otherwise
 */
int vec_pop(vector *vec, int index);

/* vec_reverse reverses the order of the elements in the vector
 * @param vec the vector
 */
int vec_reverse(vector *vec);

/* vec_print prints out all the elements of the vector
 * @param vec the vector
 * @return 0 if successful, -1 otherwise
 */
int vec_print(vector *vec);

/* vec_shrink shrinks the allocated memory to match the current length of the vector
 * @param vec the vector
 * @return 0 if successful, -1 otherwise
 */
int vec_shrink(vector *vec);

/* vec_free frees the memory
 * @param vec the vector
 */
void vec_free(vector *vec);

#endif