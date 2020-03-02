
#include "tty.h"


static struct timeval timeout;


/* 设置窗口参数:115200速率 */
void init_tty(int fd)
{    
	//声明设置串口的结构体
	struct termios termios_new;
	//先清空该结构体
	bzero( &termios_new, sizeof(termios_new));
	//	cfmakeraw()设置终端属性，就是设置termios结构中的各个参数。
	cfmakeraw(&termios_new);
	//设置波特率
    cfsetispeed(&termios_new, B9600);
    cfsetospeed(&termios_new, B9600);
	//CLOCAL和CREAD分别用于本地连接和接受使能，因此，首先要通过位掩码的方式激活这两个选项。    
	termios_new.c_cflag |= CLOCAL | CREAD;
	//通过掩码设置数据位为8位
	termios_new.c_cflag &= ~CSIZE;
	termios_new.c_cflag |= CS8; 
	//设置无奇偶校验
	termios_new.c_cflag &= ~PARENB;
	//一位停止位
	termios_new.c_cflag &= ~CSTOPB;
	tcflush(fd,TCIFLUSH);
	// 可设置接收字符和等待时间，无特殊要求可以将其设置为0
	termios_new.c_cc[VTIME] = 10;
	termios_new.c_cc[VMIN] = 1;
	// 用于清空输入/输出缓冲区
	tcflush (fd, TCIFLUSH);
	//完成配置后，可以使用以下函数激活串口设置
	if(tcsetattr(fd,TCSANOW,&termios_new) )
		printf("Setting the serial1 failed!\n");

}

int tty_starts()
{
//	int ret, i;
    int fd2;

//	fd1 = open(DEV_PATH1, O_RDWR | O_NOCTTY);
//	if (fd1 < 0)
//	{
//		fprintf(stderr, "Open ttySAC1 fail!\n");
//		return -1;
//	}
	
    fd2 = open(DEV_PATH3, O_RDWR | O_NOCTTY );
	if (fd2 < 0)
	{
		fprintf(stderr, "Open ttySAC2 fail!\n");
		return -1;
	}
	//初始化串口
//	init_tty(fd1);
	init_tty(fd2);
	
//	char buf[20];
//	while(1){
		
//		bzero(buf,20);
//		fgets(buf,20,stdin);
//		write(fd1,buf,strlen(buf));
		
//		bzero(buf,20);
//		read(fd2,buf,20);
//		printf("tty2:%s\n",buf);
		
//		if(strcmp(buf,"over\n")==0)break;
		
//	}
	
	
//	close(fd1);
//	close(fd2);
    return fd2;
}

//查找文件 用文件传输的设置file_name：文件名  size：文件大小 data：整个的数据
u8* find_data(char *file_name, unsigned int *size, u8 *data)
{
    u8 *p = data;
    int len = 0;
    if((file_name == NULL) || (size == NULL))//为空就退出
        return NULL;
    while(*p++)//计算有多少个#如果小于2也就是不够3个#就退出
    {
        if(*p == '#')
            len++;
    }
    if(len != 2)
        return NULL;
    len = 0;
    p = strtok(data, "#");
    while(p != NULL)
    {
        //printf("--find_data-- %s\n", p);
        if(len == 0 )
            strcpy(file_name, p);
        else if(len == 1)
        {
            *size = atoi(p);
            p = strtok(NULL, "#");
            break;
        }
        p = strtok(NULL, "#");
        len++;
    }

    return p;
}

//void file_rev(int fd)
//{
//    int len;
//    char buff[256]={0};
//    char file_name[100] = {0};//文件名
//    char temp[256] = {0};
//    int file_fd = 0;//接收到数据文件描述符
//    int file_all_len = 0;//文件的总大小有对方发来拆解得到
//    int file_recv_len = 0;//每次获取的文件数据大小
//    bool flag = true;//文件标志位，true是第一次要做处理

//    while(1)
//    {
//            //文件接收部分
//            do
//            {
//                len = read(fd, buff, sizeof(buff));
//            }
//            while(len>0);
//            printf("read_file-- %s\n", buff);
//            if(flag == true)//第一次进入要拆解文件，获取#文件名字#文件内容#
//            {
//                    //字符串拼接
//                    strcat(temp, buff);
//                    printf("--bufffile-- %s\n", temp);
//                    u8 *p = find_data(file_name, &file_all_len, temp);//就用数据将文件的名字,文件的大小查找函数
//                    //拆解失败 为NULL 重新接收continue 继续拼接新的数据，拆解字符串 直到temp>172字符就基本上没有希望了
//                    if(p == NULL)
//                    {
//                            //printf("recv data continue \n");
//                            if(172 < strlen(temp))//一直没有找到文件名字和大小，数据也装一半，那就是错误了
//                                    break;
//                            continue;
//                    }
//                    printf("filename %s , filesize %d\n", file_name, file_all_len);
//                    file_fd = open(file_name, O_RDWR | O_CREAT, 0777); //创建并写入文件
//                    if(file_fd < 0)//打开失败就退出循环
//                    {
//                            perror("file_fd file error");
//                            break;
//                    }
//                    file_recv_len += write(file_fd, p, strlen(p));
//                    if(file_recv_len == file_all_len)//如果相等就直接退出
//                    {
//                            printf("false recv done name %s,size %d\n", file_name, file_all_len);
//                            close(file_fd);
//                            break;
//                    }
//                    flag = false;
//                    printf("file_recv_len true %d p-> %s buff -->%s\n", file_recv_len, p, buff);
//            }
//            else//文件已经创建好了，直接安装
//            {
//                    file_recv_len += len;//读到多少就写入多少
//                    write(file_fd, buff, len);
//            }
//            if(file_recv_len == file_all_len)//文件总大小于文件的数据读取的大小相等
//            {
//                    printf("true recv done name %s,size %d\n", file_name, file_all_len);
//                    close(file_fd);
//                    flag = true;
//                    break;
//            }
//    }
//}
