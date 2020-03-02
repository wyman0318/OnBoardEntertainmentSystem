#include "vol.h"


bool init_mixer(char *device_name, int *fd)
{
    if ((*fd = open(device_name, O_WRONLY)) < 0){
     return false;
    }
    return true;
}

void contrl_vol(int *fd, int increment)
{
    int vol;
    ioctl(*fd,MIXER_READ(SOUND_MIXER_VOLUME),&vol);
    vol += increment;
    ioctl(*fd,MIXER_WRITE(SOUND_MIXER_VOLUME),&vol);
}
