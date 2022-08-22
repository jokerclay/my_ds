/*
 * 循环左移
 */

#include <time.h>
#include "../vector.h"
#define LEFT 2
#define RANDOM_RANGE 10
#define INIT_VEC_SIZE 5


#if 1
void reverse (Vector *vec, int from, int to)
{

    int i, temp;

    for (int i = 0; i < (to - from + 1)/2; i++) {

//         printf("i => %d\n",i);

        temp = vec->data[from + i];

        vec->data[from + i] = vec->data[to - i - 1];

        vec->data[to - i - 1] = temp;
    }

}

#endif

#if 1
void converse (Vector *vec, int n, int p)
{
                                //     (A    B  )           // abc edfgh
                               
    reverse(vec, 0, p - 1);     //     (A-1  B  )           // cba edfgh

//    reverse(vec, p, n - 1);     //     (A-1  B-1)           // cba ghfed

//    reverse(vec, 0, n - 1);     //     (A-1  B-1)-1 = ba    // defgh abc

}
#endif


int main(void) 
{
    
    /* genreate basic vector */ 
    srand(time(0));
    Vector *vec  = init_vector(INIT_VEC_SIZE);

#if 0
    for (int i = 0; i < INIT_VEC_SIZE; ++i) {
        insert(vec, i, rand() % RANDOM_RANGE);
    }
#endif

#if 1
    for (int i = 0; i < INIT_VEC_SIZE; ++i) {
        insert(vec, i, i);
    }
#endif



    get_vec_status(vec);

    /* move 3 to left */ 
    // 逆转
    reverse(vec, 0, INIT_VEC_SIZE);

    // 交换
    int n = vec->length;

    converse(vec, n, LEFT);

    get_vec_status(vec);

    return 0;
}
