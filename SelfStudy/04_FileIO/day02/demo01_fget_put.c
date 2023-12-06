#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL; //创建文件流指针
    int rec = 0;     //接收从文件中读取到的字符
    int  wrc = 'w';  //存储要往文件中写入的字符
    
    fp = fopen("file.txt", "a+"); //以追加读写方式打开file.txtx文件
    /* 文件打开失败打印提示信息并退出 */
    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }
#if 0
    rec = fgetc(fp);               //从文件流指针fp指向的文件中去除一个字符赋值给rec
    /* 字符获取失败打印提示信息并退出 */
    if (rec == -1)
    {
        perror("fgetc");
        fclose(fp);                 //关闭文件流指针
        return 0;
    }
    printf("Get char = %c\n", rec); //打印接收的字符

    rec = getchar();
    printf("Get STD input = %c\n", rec);
    
    fclose(fp);
#endif

#if 0
    fp = fopen("file.txt", "r"); //以只读方式打开file.txt文件
    /* 文件打开失败打印提示信息并退出 */
    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }

    /* fgetc获取文件中的字符后会将文件的位置标识符号向后移动一位 */
    /* 获取文件file.txt中的第一个字符并打印 */
    rec = fgetc(fp);
    printf("Get Char = %c\n", rec);

    /* 获取文件file.txt中的第二个字符并打印 */
    rec = fgetc(fp);
    printf("Get char = %c\n", rec);

    /* 获取文件file.txt中的第三个字符并打印 */
    rec = fgetc(fp);
    printf("Get char = %c\n", rec);

    fclose(fp);
#endif

    rec = fputc(wrc, fp); //向文件中写入wrc内存储的字符，并用rec接收返回值
    /* 写urshibai打印提示信息并退出 */
    if (rec == -1)
    {
        perror("fpuc");
        fclose(fp);
        return 0;
    }

    /* 打印成功写入的字符 */
    putchar(wrc);
    puts("");

    fclose(fp); //关闭文件流指针

    return 0;
}
