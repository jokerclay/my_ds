# 顺序表的 C 语言实现
/*
 * 关于线性表的基本操作
 *
 */


```C
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Vector {
    int *data;      // An array of data elements(`int` in this case)
    int length;     // Number of current elements
    int capacity;   // Length of array in sequence table/total capacity of data
} Vector;

Vector *init_vector(int n)
{
    // Dynamically allocate memory blocks
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = (int *)malloc(sizeof(int) * n);
    vec->capacity = n;
    vec->length = 0;
    return vec;
}

void clear_vector(Vector *vec)
{
    if (vec == NULL) {
        printf("ERROR: Vector can not be cleared !");
        exit(0);
    }
    free(vec->data);
    free(vec);
    return ;
}


int insert(Vector *vec, int pos, int value)
{
    if (vec == NULL) {
        printf("ERROR: Vector don't exist !");
        exit(0);
    }
    if (vec->length == vec->capacity) {
        printf("ERROR: Vector is full ! could not insert any value");
        exit(0);
    }
    if (pos < 0 || pos > vec->capacity) {
        printf("ERROR: insert value's postion is out of boundary !");
        exit(0);
    }

    for (int i = vec->capacity - 1; i > pos; --i) {
        vec->data[i] = vec->data[i-1];
    }

    vec->data[pos] = value;

    vec->length += 1;

    return 1;
}

int erase(Vector *vec, int pos)
{
    if (vec == NULL) {
        printf("ERROR: Vector doesn't exist!") ;
        exit(0);
    }

    if (pos < 0 || pos > vec->length) {
        printf("ERROR: postion is out of vectory's length");
        exit(0);
    }

    // erase
    for (int i = pos; i < vec->length; i++) {
        vec->data[i] = vec->data[i+1];
    }

    // reduce the length
    vec->length -= 1;

    return 1;
}


int locate_value(Vector *vec, int value)
{
    if (vec == NULL) {
        printf("ERROR: Vector doesn't exist!") ;
        exit(0);
    }

    for (int i = 0; i < vec->length; i++) {
        if (vec->data[i] == value ) return i;
    }

    return 0;
}


void print_out(Vector *vec)
{
    printf("Vector(%d) = [", vec->length);
    for (int i = 0; i < vec->length; ++i) {
        printf(" %d ", vec->data[i]);
    }

    printf("]\n");
}

void print_vectoy_details(Vector *vec) {
    printf("[---- VECTOR STATUS]: \n");
    printf("Vector's current length = %d\n", vec->length);
    printf("Vector's capacity = %d\n", vec->capacity);
}

void get_vec_status(Vector *vec) {
    print_vectoy_details(vec);
    print_out(vec);
    printf("\n");
}



int main (void)
{
    // initialization of a Vector
    Vector *vec  = init_vector(MAX_SIZE);
    get_vec_status(vec);

    // insert 5 value into the Vector
    for (int i = 0; i < 5; i++) {
        insert(vec, i, i);
    }
    get_vec_status(vec);

    insert(vec, 0, 69);
    get_vec_status(vec);

    insert(vec, 4, 6699);
    get_vec_status(vec);

    erase(vec, 0);
    get_vec_status(vec);

    erase(vec, 2);
    get_vec_status(vec);


    int location_of_the_value =  locate_value(vec, 6699);
    printf("the location of 6699 is %d\n", location_of_the_value);
    
    clear_vector(vec);
    return 0;
}
```
