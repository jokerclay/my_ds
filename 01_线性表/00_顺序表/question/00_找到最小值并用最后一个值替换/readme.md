# Code
```c
/*
 * 从顺序表中删除最小的元素（假设唯一）并由函数返回被删除元素的值，空出的位置由
 * 最后一个元素填补，若顺序表为空，则显示出错误信息并退出运行
 *
 */

#include <time.h>
#include <stdbool.h>
#include "../vector.h"

int answer(Vector *vec, int value) {

    if (vec ==NULL)  {
        printf("Vector doesn't exist !");
        exit(0);
    }

    if (vec->length == 0 ){
        printf("Vector is empty!");
        exit(0);
    }

    int index = 0;
    value = vec->data[0];

    for (int i = 1; i < vec->length; i++) {

        if (vec->data[i] < value) {
            value = vec->data[i];
            index  =  i;
        }
    }

    vec->data[index] = vec->data[vec->length - 1];
    vec->length--;
    return value;
}


int main(void) 
{
    
    Vector *vec  = init_vector(10);

    srand(time(0));

    for (int i = 0; i < 10; ++i) {
        insert(vec, i, rand() % 100);
    }

    get_vec_status(vec);

    int value = 0;
    int ans = answer(vec,value);


    get_vec_status(vec);
    printf("====> [MIN VALUE]: %d\n", ans);

    return 0;
}

```





# Result
```txt

====> [VECTOR STATUS]: 
Vector's current length = 10
Vector's capacity = 10
Vector(10) = [ 81  35  93  1  6  88  83  34  80  42 ]

====> [VECTOR STATUS]: 
Vector's current length = 9
Vector's capacity = 10
Vector(9) = [ 81  35  93  42  6  88  83  34  80 ]

====> [MIN VALUE]: 1


```


