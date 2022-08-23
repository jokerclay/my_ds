# Code

```c

/*
 *      循环左移
 */

#include <time.h>
#include "../vector.h"
#define LEFT 2
#define RANDOM_RANGE 10
#define INIT_VEC_SIZE 10


#if 1
void reverse (Vector *vec, int from, int to)
{
    printf("[INFO]: Reversing from %d -> %d\n", from, to);
    int i, temp;
    for (int i = 0; i < (to - from + 1)/2; i++) {

//        printf("i => %d\n",i);
        temp = vec->data[from + i];

        vec->data[from + i] = vec->data[to - i];

        vec->data[to - i] = temp;
    }
    print_out(vec);
    printf("\n");
}

#endif

#if 1
void converse (Vector *vec, int n, int p)
{
    printf("====> 循环左移 %d 个位置 <==== \n", p);

    
                                //     (A    B  )           // abc edfgh
                               
    reverse(vec, 0, p - 1);     //     (A-1  B  )           // cba edfgh

    reverse(vec, p, n - 1);     //     (A-1  B-1)           // cba ghfed

    reverse(vec, 0, n - 1);     //     (A-1  B-1)-1 = ba    // defgh abc

}
#endif


int main(void) 
{
/* genreate basic vector with the size of INIT_VEC_SIZE */ 
    srand(time(0));
    Vector *vec  = init_vector(INIT_VEC_SIZE);




/* genreate random value from 0 to RANDOM_RANGE and fill into the vector*/
#if 0
    for (int i = 0; i < INIT_VEC_SIZE; ++i) {
        insert(vec, i, rand() % RANDOM_RANGE);
    }
#endif




/* genreate value from 0 to INIT_VEC_SIZE and fill into the vector */
#if 1
    for (int i = 0; i < INIT_VEC_SIZE; ++i) {
        insert(vec, i, i);
    }
#endif



    /* get the init STATUS */ 
    get_vec_status(vec);

    /* move 2 to left */ 
    converse(vec, vec->length, LEFT);

    /* get the result STATUS */ 
    get_vec_status(vec);

    return 0;

}

```


# Result
```txt

====> [VECTOR STATUS]: 
Vector's current length = 10
Vector's capacity = 10
Vector(10) = [ 0  1  2  3  4  5  6  7  8  9 ]

====> 循环左移 2 个位置 <==== 
[INFO]: Reversing from 0 -> 1
Vector(10) = [ 1  0  2  3  4  5  6  7  8  9 ]

[INFO]: Reversing from 2 -> 9
Vector(10) = [ 1  0  9  8  7  6  5  4  3  2 ]

[INFO]: Reversing from 0 -> 9
Vector(10) = [ 2  3  4  5  6  7  8  9  0  1 ]

====> [VECTOR STATUS]: 
Vector's current length = 10
Vector's capacity = 10
Vector(10) = [ 2  3  4  5  6  7  8  9  0  1 ]

```
