/*
 * 循环左移
 */

#include <time.h>
#include "../vector.h"
#define RANDOM_RANGE 10
#define LEFT 3


void reverse ()
{



}


void converse ()
{



}



void move_left(Vector *vec, int p) 
{




}



int main(void) 
{
    
    /* genreate basic vector */ 
    srand(time(0));
    Vector *vec  = init_vector(10);
    for (int i = 0; i < 10; ++i) {
        insert(vec, i, rand() % RANDOM_RANGE);
    }
    get_vec_status(vec);

    
    /* move 3 to left */ 
    move_left(vec, LEFT);
    get_vec_status(vec);

    return 0;
}
