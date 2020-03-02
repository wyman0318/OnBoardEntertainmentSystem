#ifndef __TTY_H
#define __TTY_H

#ifdef __cplusplus
extern "C"{
#endif


#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h>
#include <termios.h> 
#include <sys/types.h>
#include <sys/select.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>


#define DEV_PATH1   "/dev/ttySAC1"
#define DEV_PATH2   "/dev/ttySAC2"
#define DEV_PATH3   "/dev/ttySAC3"
typedef unsigned char u8;

void init_tty(int fd);
int tty_starts();
void file_rev(int fd);
u8* find_data(char *file_name, unsigned int *size, u8 *data);



#ifdef __cplusplus
}
#endif

#endif
