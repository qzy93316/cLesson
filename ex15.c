#include <stdio.h>

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // first way using indexing
    for(i = 0; i < count ; i++) {
        printf("%s has %d years alive.\n",
            names[i], ages[i]);
    }

    printf("---\n");

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    // second way using pointers
    for(i = 0; i < count; i++) {
        printf("%s is %d years old.\n",
                *(cur_name+i),*(cur_age+i));
        printf("ages address: %p and names address: %p\n",
                &*(cur_age+i), &*(cur_name+i));
    }

    printf("---\n");

    // third way, pointers are just arrays
    for(i = 0; i < count; i++) {
        printf("%s is %d years old again.\n",
                cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // fourth way with pointers in a stupid complex way
    for(cur_name = names,cur_age = ages;
        (cur_age - ages) < count;
        cur_name++, cur_age++)
    {
        printf("%s lived %d years so far.\n",
                *cur_name, *cur_age);
    }



}
/*
    type *ptr 指向type类型的指针，名为ptr
    *ptr 所指向位置的值
    *(ptr + i) (ptr所指向位置加上i)的值
    译者注：以字节为单位的话，应该是ptr所指向的位置再加上sizeof(type) * i。
    &thing
    thing的地址
    type *ptr = &thing
    名为ptr, type类型的指针，值设置为thing的地址
    ptr++
    自增ptr指向的位置
*/
