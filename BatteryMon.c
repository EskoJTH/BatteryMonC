#include <inttypes.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "OpenGLDemo.c"
#include "ReadBattery.c"

int main(int argc, char **argv){
  int warn = 99;
  int battery = getBattery(); //ReadBattery.c
  printf("Battery status: %i\n", battery);
  while(True){
    if (battery <= warn){
      drawWarn(argc, argv); //OpenGLDemo.c
    } else {
      sleep(20);
    }
  }
}


