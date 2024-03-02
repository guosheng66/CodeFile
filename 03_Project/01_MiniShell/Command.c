#include "Command.h"

/********************************************
 * 函数名:MyCd
 * 功能:切换当前工作目录 
 * 参数:
 * 		ppCmdArray：指向解析后的指令数组的指针
 *      CurCnt：解析后的命令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int MyCd(char **ppCmdArray, int CurCnt)
{   
    /* 判断用户输入命令模式是否正确 */
    if (2 != CurCnt)
	{
		fprintf(stderr, "Usage:cd mode filename\n");
		return -1;
	}

	/* 切换工作目录 */
    if (ppCmdArray[1] != NULL)
    {
        chdir(ppCmdArray[1]);
    }
    
    return 0;
}

/********************************************
 * 函数名:MyChmod
 * 功能:切换当前工作目录 
 * 参数:
 * 		ppCmdArray：指向解析后的指令数组的指针
 *      CurCnt：解析后的命令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int MyChmod(char **ppCmdArray, int CurCnt)
{
    mode_t mode;
    char *p = NULL;

    /* 判断用户输入命令模式是否正确 */
    if (3 != CurCnt)
	{
		fprintf(stderr, "Usage:chmod mode filename\n");
		return -1;
	}
	
	
    p = ppCmdArray[1];
	while (*p != '\0')
	{
		mode = mode * 8 + *p - '0';	//将转换为8进制数字
		p++;
	}

    chmod(ppCmdArray[2], mode);		//修改文件权限


	return 0;
}

/********************************************
 * 函数名:MyLn
 * 功能:为某一个文件在另外一个位置建立一个同步的链接
 * 参数:
 * 		ppCmdArray：指向解析后的指令数组的指针
 *      CurCnt：解析后的命令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int MyLn(char **ppCmdArray, int CurCnt)
{
	if (CurCnt < 3)
	{
		fprintf(stderr, "Usage:ln [-s] src.txt link.txt\n");
		return -1;
	}

	if (3 == CurCnt)
	{
		link(ppCmdArray[1], ppCmdArray[2]);
	}
	else if (4 == CurCnt && !strcmp(ppCmdArray[1], "-s"))
	{
		symlink(ppCmdArray[2], ppCmdArray[3]);
	}

	return 0;
}

/********************************************
 * 函数名:MyMv
 * 功能:命令用来为文件或目录改名,
 * 	   或将文件或目录移入其它位置
 * 参数:
 * 		ppCmdArray：指向解析后的指令数组的指针
 *      CurCnt：解析后的命令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int MyMv(char **ppCmdArray, int CurCnt)
{
	int ret = 0;
	struct stat buf;
	char newpath[1024] = {0};

	/* 判断用户输入命令模式是否正确 */
	if (CurCnt != 3)
	{
		fprintf(stderr, "Usage:mv srcfile dstpath\n");
		return -1;
	}

	ret = stat(ppCmdArray[2], &buf);
	if (0 == ret && S_ISDIR(buf.st_mode))
	{
		sprintf(newpath, "%s/%s", ppCmdArray[2], ppCmdArray[1]);
	}
	else
	{
		sprintf(newpath, "%s", ppCmdArray[2]);
	}

	ret = rename(ppCmdArray[1], newpath);
	if (-1 == ret)
	{
		perror("fail to rename");
		return -1;
	}
	
	return 0;
}

/********************************************
 * 函数名:MyLs
 * 功能:打印出当前目录的列表
 * 参数:
 * 		ppCmdArray：指向解析后的指令数组的指针
 *      CurCnt：解析后的命令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int MyLs(char **ppCmdArray, int CurCnt)
{
	char tmpbuff[4096] = {0};	//存放当前目录路径
	DIR *dp = NULL;				//定义DIR结构体的指针dp
	struct dirent *pp = NULL;	//pp指向结构dirent

	/* 判断用户输入命令模式是否正确 */
	if (CurCnt >= 3)
	{
		fprintf(stderr, "Usage:ls mode filename\n");
		return -1;
	}
	/* 执行ls */
	else if (CurCnt == 1)
	{
		getcwd(tmpbuff, sizeof(tmpbuff));	//获取当前目录路径存放到tmpbuff数组

		dp = opendir(tmpbuff);				//打开tmpbuff指向的目录，并返回*DIR结构的目录流
    	/* 如果打开制定的目录失败则打印出错信息 */
		if (NULL == dp)
    	{
			perror("fail to opendir");
			return -1;
		}

		/* 遍历当前目录下的文件并打印 */
		while ((pp = readdir(dp)) != NULL)
		{
			if ('.' == pp->d_name[0])
			{
				continue;
			}	

			printf("%s  ", pp->d_name);
		}

		printf("\n");	
		closedir(dp);
	}
	/* 执行ls -a */
	else if(CurCnt == 2 && !(strcmp(ppCmdArray[1], "-a")))
	{
		getcwd(tmpbuff, sizeof(tmpbuff));	//获取当前目录路径存放到tmpbuff数组

		dp = opendir(tmpbuff);				//打开tmpbuff指向的目录，并返回*DIR结构的目录流
    	/* 如果打开制定的目录失败则打印出错信息 */
		if (NULL == dp)
    	{
			perror("fail to opendir");
			return -1;
		}

		/* 遍历当前目录下的文件并打印 */
		while ((pp = readdir(dp)) != NULL)
		{
			printf("%s  ", pp->d_name);
		}

		printf("\n");	
		closedir(dp);
	}
	/* 执行ls -l */
	else if(CurCnt == 2 && !(strcmp(ppCmdArray[1], "-l")))
	{
		dp = opendir(".");	//打开当前目录
		if (NULL == dp)
		{
			perror("fail to open");
			return -1;
		}

		/* 获取当前目录下的文件并将其名称存放在数组中 */
		while (NULL != (pp = readdir(dp)))
		{
			if ('.' == pp->d_name[0])
			{
				continue;
			}
			sprintf(tmpbuff, "%s", pp->d_name);
			StatFile(tmpbuff);

			close(dp);
		}
	}

	return 0;
}

/********************************************
 * 函数名:StatFile
 * 功能:获取文件信息
 * 参数:
 * 		pfilename：指向存储文件名称的数组
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
void StatFile(char *pfilename)
{         
	struct stat finformation;	//存放文件的信息
	int ret = 0;				//接收返回值

	ret = lstat(pfilename,&finformation);	//获取信息给finformation
	if(-1 == ret)							//判断是否获取成功
	{
		perror("fail to lstat");
	}

	switch(finformation.st_mode & __S_IFMT) //文件类型
	{
			case __S_IFBLK: putchar('b'); break;
			case __S_IFCHR: putchar('c'); break;
			case __S_IFDIR: putchar('d'); break;
			case __S_IFREG: putchar('-'); break;
			case __S_IFLNK: putchar('l'); break;
			case __S_IFSOCK: putchar('s');break;
			case __S_IFIFO: putchar('p'); break;
	}

	finformation.st_mode & S_IRUSR ? putchar('r') : putchar('-');	//创建者权限
	finformation.st_mode & S_IWUSR ? putchar('w') : putchar('-');
	finformation.st_mode & S_IXUSR ? putchar('x') : putchar('-');

	finformation.st_mode & S_IRGRP ? putchar('r') : putchar('-');	//同组人员权限
	finformation.st_mode & S_IWGRP ? putchar('w') : putchar('-');
	finformation.st_mode & S_IXGRP ? putchar('x') : putchar('-');

	finformation.st_mode & S_IROTH ? putchar('r') : putchar('-');	//其余人权限
	finformation.st_mode & S_IWOTH ? putchar('w') : putchar('-');
	finformation.st_mode & S_IXOTH ? putchar('x') : putchar('-');

	printf(" %ld",finformation.st_nlink);	//硬链接个数

	struct passwd *puid = NULL;				//uid名
	puid = getpwuid(finformation.st_uid);
	printf(" %s",puid->pw_name);

	struct group *pgid = NULL;				//gid名
	pgid = getgrgid(finformation.st_gid);
	printf(" %s",pgid->gr_name);

	printf(" %5ld",finformation.st_size);	//文件大小

	struct tm *ptime = NULL;				//最近编辑时间
	char *mon[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	ptime = localtime(&finformation.st_ctime);
	printf(" %s%d  %d:%d %s\n",mon[ptime->tm_mon],ptime->tm_mday,ptime->tm_hour
													,ptime->tm_min,pfilename);
 
         
}

/********************************************
 * 函数名:MyCat
 * 功能:将文件内容打印在终端
 * 参数:
 * 		ppCmdArray：指向解析后的指令数组的指针
 *      CurCnt：解析后的命令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int MyCat(char **ppCmdArray, int CurCnt)
{
	int fd = 0;				//定义一个文件描述符
	char cont[10240] = {0};	//定义一个字符型数组存放读取到的文件内容

	/* 判断用户输入命令模式是否正确 */
	if (CurCnt != 2)
	{
		fprintf(stderr, "Usage:cat mode filename\n");
		return -1;
	}

	/* 打开文件并返回文件描述符 */
	fd = open(ppCmdArray[1], O_RDONLY);
	if (-1 == fd)
	{
		perror("fail to open(cat)");
		return -1;
	}

	read(fd, cont, sizeof(cont));	//读取文件内容存储到数组中
	printf("%s", cont);				//打印读取到的文件内容

	close(fd);						//关闭文件描述符

	return 0;
}

/********************************************
 * 函数名:MyCp
 * 功能:拷贝文件
 * 参数:
 * 		ppCmdArray：指向解析后的指令数组的指针
 *      CurCnt：解析后的命令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int MyCp(char **ppCmdArray, int CurCnt)
{
	int fsrc = 0;
	int fdst = 0;
	int len = 0;			//定义读取到的内容长度
	char str[4096] = {0};	//定义字符型数组来存储文件内容

	/* 打开源文件 */
	fsrc = open(ppCmdArray[1], O_RDONLY);
	if (-1 == fsrc)
	{
		perror("fail to open(cp)");
		return -1;
	}

	/* 打开目的文件 */
	fdst = open(ppCmdArray[2], O_WRONLY | O_TRUNC |O_CREAT, 0664);	//110 110 100
	if (-1 == fdst)
	{
		perror("fail to open(cp)");
		return -1;
	}

    while(( len = read(fsrc, str, sizeof(str)) ) > 0 ) 
	{
        write(fdst, str, len);	//将读取到的文件内容写入到目标文件中
    }

	close(fsrc);
	close(fdst);

	return 0;
}

/********************************************
 * 函数名:MyMv
 * 功能:建立一个新的文件
 * 参数:
 * 		ppCmdArray：指向解析后的指令数组的指针
 *      CurCnt：解析后的命令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int MyTouch(char **ppCmdArray, int CurCnt)
{
	char filename[1024] = {0};	//文件名称
	char filepath[1024] = {0};	//当前文件路径
	FILE *fp = NULL;

	getcwd(filepath, sizeof(filepath));	//获取当前目录的路径并存储到数组中
	
	sprintf(filename, "%s/%s", filepath, ppCmdArray[1]);
	
	fp = fopen(filename, "a");
	if (NULL == fp)
	{
		perror("fail to fopen(touch)");
		return -1;
	}

	fclose(fp);
	
	return 0;
}

/********************************************
 * 函数名:MyRm
 * 功能:删除文件
 * 参数:
 * 		ppCmdArray：指向解析后的指令数组的指针
 *      CurCnt：解析后的命令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int MyRm(char **ppCmdArray, int CurCnt)
{
	/* 判断用户输入命令模式是否正确 */
	if (CurCnt != 2)
	{
		fprintf(stderr, "Usage:rm mode filename\n");
		return -1;
	}

	remove(ppCmdArray[1]);	//删除指定文件

	return 0;
}

/********************************************
 * 函数名:MyRmDir
 * 功能:删除文件夹
 * 参数:
 * 		ppCmdArray：指向解析后的指令数组的指针
 *      CurCnt：解析后的命令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int MyRmDir(char **ppCmdArray, int CurCnt)
{
	/* 判断用户输入命令模式是否正确 */
	if (CurCnt != 2)
	{
		fprintf(stderr, "Usage:rmdir mode filename\n");
		return -1;
	}

	rmdir(ppCmdArray[1]);	//删除指定文件夹

	return 0;
}
/********************************************
 * 函数名:MyMkdir
 * 功能:创建文件夹
 * 参数:
 * 		ppCmdArray：指向解析后的指令数组的指针
 *      CurCnt：解析后的命令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int MyMkdir(char **ppCmdArray, int CurCnt)
{
	/* 判断用户输入命令模式是否正确 */
	if (CurCnt != 2)
	{
		fprintf(stderr, "Usage:mkdir mode filename\n");
		return -1;
	}

	mkdir(ppCmdArray[1], 0777);	//创建指定文件夹

	return 0;
}

/********************************************
 * 函数名:MyPwd
 * 功能:显示工作目录
 * 参数:
 * 		ppCmdArray：指向解析后的指令数组的指针
 *      CurCnt：解析后的命令个数
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
int MyPwd(char **ppCmdArray, int CurCnt)
{
	char filepath[1024] = {0};
	
	getcwd(filepath, sizeof(filepath));
	puts(filepath);

	return 0;
}

/********************************************
 * 函数名:MyExit
 * 功能:退出minishell
 * 参数:
 * 		缺省
 * 返回值:
 * 		成功返回0 
 * 		失败返回-1 
 * 注意事项:
 * 		无
 *******************************************/
void MyExit(void)
{
	exit(0);
}