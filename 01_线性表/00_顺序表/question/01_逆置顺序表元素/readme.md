# Code
```c


/*
 * 设计一个高效算法，将顺序表中的所有元素逆置，并要求算法的空间复杂度为O(1)
 *
 */

#include <time.h>
#include "../vector.h"

void reverse(Vector *vec)
{
    int temp;
    for (int i = 0; i < (vec->length)/2; i++)  {        // 选择一半
        temp = vec->data[i];                            // 前半部分移走
        vec->data[i] = vec->data[vec->length-1];        // 后半部分前移
        vec->data[vec->length - i -1] = temp;           // 后半部分从后向前移
    }
}


int main(void) 
{
    
    /* genreate basic vector */ 
    srand(time(0));
    Vector *vec  = init_vector(10);
    for (int i = 0; i < 10; ++i) {
        insert(vec, i, rand() % 100);
    }
    get_vec_status(vec);

    /* reverse the vector */
    reverse(vec);
    get_vec_status(vec);


    return 0;
}



```

# Result
```txt
====> [VECTOR STATUS]: 
Vector's current length = 10
Vector's capacity = 10
Vector(10) = [ 2  30  74  21  59  68  19  70  37  5 ]

====> [VECTOR STATUS]: 
Vector's current length = 10
Vector's capacity = 10
Vector(10) = [ 5  2  2  2  2  59  21  74  30  2 ]

```
