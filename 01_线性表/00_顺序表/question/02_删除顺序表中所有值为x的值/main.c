/*
 * 对长度为 n 的顺序表,编写一个时间复杂度为 O(n) 空间复杂度为 O(1) 的算法
 * 该算法删除所有值为 X 的算法
 * 
 */

#include <time.h>
#include "../vector.h"
#define RANDOM_RANGE 2

void delete_a_x(Vector *vec, int sheep)
{
    int k = 0, i;   // use k to store the value isn't the value

    for (int i = 0; i < vec->length; ++i) {
         printf("sheep %d <=> vec->data[i]  %d\n", sheep, vec->data[i]);

         if (vec->data[i] != sheep) {
             vec->data[k] = vec->data[i];
             k++;
         }
    }

    vec->length = k;
}




void delete_a_x_2(Vector *vec, int sheep)
{
    int k = 0, i  = 0;   // use k to store the value is the value

    while (i < vec->length) {

         if (vec->data[i] == sheep) {
             k++;
         }
         else {
             vec->data[i - k] = vec->data[i];
         }

         i++;
    }

    vec->length = vec->length  - k;
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

    /* delete a certain value */
    // genreate a value TO delete
    int sheep = rand() % RANDOM_RANGE; // Why sheep ? sheep are waiting to be KILL! 8)
    printf("====> [SHEEP] %d\n", sheep);


    // 解法一
    printf("====> [解法一] <==== \n");
    delete_a_x(vec, sheep);
    get_vec_status(vec);

    // 解法二
    printf("====> [解法二] <==== \n");
    delete_a_x_2(vec, sheep);
    get_vec_status(vec);
    return 0;
}
