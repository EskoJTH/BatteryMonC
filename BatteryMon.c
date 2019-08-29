#include <inttypes.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "OpenGLDemo.c"
#include "ReadBattery.c"
//#include "batterydata.h"
#include "ConfigReaderGlib.c"



int main(int argc, char **argv){
  setlinebuf(stdout);
  struct batterydata batdat;
  readConf(&batdat, "/home/esko/OmatProjektit/BatteryMon/batterymon.ini");
  //readConf(&batdat, "batterymon.ini");
  int warn = batdat . low;

  const char * openGl = "OpenGLDemoPlain";
  const char * arg = "";
  //printf("Battery status: %i\n", battery);
  //sleep(30);
  while(1){
    int battery = getBattery(batdat . path); //ReadBattery.c
    if (battery <= warn){
      printf("executing drawing\n");
      //execl(openGl, arg, NULL);
      drawWarn(argc, argv);//OpenGLDemo.c
      //printf("drawing executed\n");
      
    }
    printf("loopping");
    sleep(20);
  }
    return 0;
}

