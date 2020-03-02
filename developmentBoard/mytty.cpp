#include "mytty.h"
#include "tty.h"
#include <QDebug>
#include <QFile>
#include <QByteArray>

mytty::mytty(int fd) : fd2(fd)
{

}

void mytty::run()
{
    char buf[256]={0};
    while(1)
    {
        bzero(buf,sizeof(buf));
        read(fd2,buf,sizeof(buf));
        if(strstr(buf,"start"))
        {
            emit blue_msg(1);
        }
        else if(strstr(buf,"stop"))
        {
            emit blue_msg(2);
        }
        else if(strstr(buf,"next"))
        {
            emit blue_msg(3);
        }
        else if(strstr(buf,"prev"))
        {
            emit blue_msg(4);
        }
        else if(strstr(buf,"ss"))
        {
            emit blue_msg(5);
        }
#if 1
        else if(strstr(buf,"file"))
        {
            int  flag=1;
            char tmp[256]={0};
            char data[128]={0};
            int  file_len;
            qint64  file_rec=0;
            char file_name[100]={0};
            char *p;
            char *q;
            char *info;
            int len;
            QByteArray array;
            QByteArray temp;
            QFile file;
            while(1)
            {
                if(flag)
                {
                    bzero(data,sizeof(data));
                    len=read(fd2,data,sizeof(data));//一次只能发２０字节
                    if(len>0)
                        strcat(tmp,data);
                    else continue;
                    qDebug() << data;
                }
                else
                {
                    len=0;
                    bzero(data,sizeof(data));
                    len=read(fd2,data,sizeof(data));
                    if(len==0) continue;
//                    temp=data;
                    temp = QByteArray(data,len);
                }

                if(flag!=0)
                {
                    info=strdup(tmp);
                    p=strtok(info,"#"); //先是路径

                    strcpy(file_name,p);

                    if(!(p=strtok(NULL,"#")))//如果后面没有了，说明自定义包还没发完
                    {
                        free(info); //释放临时申请内存的指针
                        continue;
                    }

                    //此时说明出现了第二个#了，后面则是文件包大小
                    if(q=strtok(NULL,"#"))//如果没有第三个#则是不完全的数字
                    {
                        file_len=atoi(p);
                        bzero(tmp,sizeof(tmp));
//                        strcpy(tmp,q+1); //读到第三个#号，后面的就可能是数据包
                        qDebug() << "message"<< file_name << file_len <<" more:" << q;
                        flag=0;

//                        file_fd = open(file_name, O_RDWR | O_CREAT, 0777);
//                        if(file_fd<0)
//                        {
//                            qDebug() << "file error";
//                            close(file_fd);
//                            break;
//                        }

                        file.setFileName(file_name);
                        if(!file.open(QIODevice::WriteOnly))
                        {
                            qDebug()<<"open fail";
                        }
                    }

                    free(info);
                    continue;
                }
                else
                {
//                    if(strlen(tmp)!=0)
//                    {
//                        QByteArray temparray=tmp;
//                        file_rec+=file.write(temparray);
//                        bzero(tmp,sizeof(tmp));
//                    }

//                    file_rec += write(file_fd,data,strlen(data));

                    array.clear();
                    array.append(temp,temp.length());
                    file_rec+=file.write(array);
                    qDebug() << file_rec;

                    if(file_rec>=file_len)
                    {
                        qDebug() << "finish";
                        file.close();
                        emit blue_msg(6);
                        break;
                    }
                }
            }
        }
#endif
//        else if(strstr(buf,"file"))
//        {
//            //需要马上处理
//            int  len;
//            char temp[256] = {0};
//            char file_name[100] = {0};
//            int  file_fd = 0;//接收到数据文件描述符
//            int  file_all_len = 0;//文件的总大小有对方发来拆解得到
//            int  file_recv_len = 0;//每次获取的文件数据大小
//            bool flag = true;//文件标志位，true是第一次要做处理
//            while(1)
//            {

//                len = read(fd2, buf, sizeof(buf));

//                if(flag)
//                {
//                    strcat(temp, buf);
//                    u8 *p = find_data(file_name, (unsigned int *)&file_all_len,(u8 *)temp);

//                    if(p == NULL)
//                    {
//                            //printf("recv data continue \n");
//                            if(172 < strlen(temp))//一直没有找到文件名字和大小，数据也装一半，那就是错误了
//                            {
//                                emit blue_msg(10);
//                                break;
//                            }
//                            continue;
//                    }
//                    file_fd = open(file_name, O_RDWR | O_CREAT, 0777);
//                    if(file_fd<0)
//                    {
//                        emit blue_msg(11);
//                        break;
//                    }
//                    file_recv_len += write(file_fd, p, strlen((const char*)p));
//                    if(file_recv_len == file_all_len)//如果相等就直接退出
//                    {
//                            emit blue_msg(12);
//                            close(file_fd);
//                            break;
//                    }
//                    flag=false;
//                }
//                else
//                {
//                    file_recv_len += len;//读到多少就写入多少
//                    write(file_fd, buf, len);
//                }
//                if(file_recv_len == file_all_len)//文件总大小于文件的数据读取的大小相等
//                {
//                    emit blue_msg(12);
//                    close(file_fd);
//                    flag = true;
//                    break;
//                }
//            }
//        }
        qDebug()<<QString(buf);

    }
}
