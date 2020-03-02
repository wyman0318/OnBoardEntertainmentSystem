#ifndef VOL_H
#define VOL_H

#ifdef __cplusplus
extern "C"{
#endif

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/soundcard.h>

bool init_mixer(char *device_name, int *fd);
void contrl_vol(int *fd,int increment);

#ifdef __cplusplus
}
#endif

#endif // VOL_H
