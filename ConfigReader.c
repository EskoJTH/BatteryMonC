#include <inttypes.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

struct configs {
  int battery;
};

struct configs initConfigs(){
  struct configs conffit;
  conffit.battery = -1;
  return conffit;
}


struct configs readConfig (char * confpath){
  FILE * batteryStateFile = fopen(confpath, "rb");
  // char buf[MAXLINE];
  char * line;
  size_t n = 0;
  ssize_t read;
  int battery = -1;
  char delimiter = '=';
  char * targetAttribute = NULL;
  stuct configs conffit = initConfigs();

  if (batteryStateFile == NULL){
    char * errormsg = "cant open config file at " + confpath +  " : %s\n";
    fprintf(stderr, errormsg, strerror(errno));
    return -1;
  }

  while (read = getdelim( &line, &n, delimiter, confpath) != -1) {
    //printf("Retrieved line of length %zu:\n", read);

   switch()

    if
    battery = strtoimax(line, NULL, 10);
    if (ERANGE == errno) {
      fprintf(stderr, "Battery status file didn't contain a number: %s\n", strerror(errno));
      return -1;
    }
  }


  fclose(batteryStateFile);
  if (line)
    free(line);
  return battery;
}
