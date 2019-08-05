#include <inttypes.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int getBattery(){
  const char * batteryStatePath = "/sys/class/power_supply/BAT0/capacity";
  FILE * batteryStateFile = fopen(batteryStatePath, "rb");
  // char buf[MAXLINE];
  char * line;
  size_t n = 0;
  ssize_t read;
  int battery = -1;
   
  if (batteryStateFile == NULL){
    fprintf(stderr, "can't open battery status file: %s\n", strerror(errno));
    return -1;
  }

  if (read = getline( &line, &n, batteryStateFile) != -1) {
    //printf("Retrieved line of length %zu:\n", read);
    battery = strtoimax(line, NULL, 10);
    if (ERANGE == errno) {
      fprintf(stderr, "Battery status file didn't contain a number: %s\n", strerror(errno));
      return -1;
    }
  } else {
    fprintf(stderr, "File read failed: %s\n", strerror(errno));
    return -1;
  }

  fclose(batteryStateFile);
  if (line)
    free(line);
  return battery;
}

