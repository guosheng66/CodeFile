#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;     //创建文件流指针
    char *buff = {NULL}; //创建指针数组
    size_t ret = 0;      //创建size_t类型变量用来接收返回值

    fp = fopen("file.txt", "r"); //以只读方式打开file.txt文件
    /* 文件打开失败打印提示信息并退出 */
    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }
    
    /* 申请空间并将相应空间的地址赋值给buff指针数组 */
    buff = (char *)malloc(100);
    /* 地址获取失败打印提示信息并退出程序 */
    if (buff == NULL)
    {
        printf("Address acquisition failed\n");
        return 0;
    }

    /* 将fp文件流中的数据读取到buff数组中 */
    ret = fread(buff, 10, 1, fp);
    /* 数据读取失败打印提示信息并退出 */    
    if (ret == -1)
    {
        perror("fread");
        free(buff); //释放申请的空间
        fclose(fp); //关闭文件流指针
        // goto end;
        return 0;
    }

    printf("buf = %s\n", buff);

    fclose(fp); //关闭文件流指针
    free(buff); //释放申请的空间
#if 0   
end:
    free(buff); //释放申请的空间
    fclose(fp); //关闭文件流指针
#endif 
    return 0;
}
