#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    struct student stu2;

    /* 以只读方式打开student.bin文件 */
    fp = fopen("student.bin", "a+");
    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }

    /* stu1信息初始化（赋值） */
    strcpy(stu1.name, "guosheng");
    stu1.age = 18;
    strcpy(stu1.sex, "male");

    /* 将stu1结构体中的内容写入到fp指向的文件中 */
    ret = fwrite(&stu1, sizeof(stu1), 1, fp);
    if (ret == -1)
    {
        perror("fwrite");
        goto end;
    }
    else
    {
        printf("write struct of student success!\n");
    }

    fclose(fp); //关闭文件流指针

    /* 以只读方式打开student.bin文件 */
    fp = fopen("student.bin", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }    

    /* 将fp指向的文件中数据读取到结构体stu2中 */
    ret = fread(&stu2, sizeof(stu2), 1, fp);
    if (ret == -1)
    {
        perror("fread");
        goto end;
    }

    printf("stu2:\nname: %s, age:%d, sex:%s\n", stu2.name, stu2.age, stu2.sex);

end:
    fclose(fp);    

    return 0;
}
