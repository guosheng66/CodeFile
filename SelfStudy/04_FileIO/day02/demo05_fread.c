#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 定义学生类型结构体 */
struct student
{
    char name[16];
    int age;
    char sex[8];
};

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;
    size_t ret = 0;
    struct student stu1;

    fp = fopen("student.bin", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }

    ret = fread(&stu1, sizeof(stu1), 1, fp);
    if (ret == -1)
    {
        perror("fopen");
        goto end;
    }

    printf("name: %s, age: %d, sex:%s\n", stu1.name, stu1.age, stu1.sex);

end:
    fclose(fp);

    return 0;
}
