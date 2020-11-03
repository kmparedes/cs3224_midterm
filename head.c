#include "types.h"
#include "user.h"
#include "stat.h"

char buf[512];

void head(int file, char *name){
  int i, j, n;
  int lineNum = 0;
  int currPos = 0;

  while ((n = read(file, buf, sizeof(buf)))>0){
    for (i = 0; i <= n; i++){
      if (buf[i] == '\n'){
        lineNum++;
        if (lineNum > 10){
          exit();
        }
        else{
          for(j = currPos; j < i; j++){
            printf(1, "%c", buf[j]);
            currPos = i;
          }
        }
      }
    }
  }
  printf(1, "\n");
  exit();

}
int main(int argc, char *argv[]) {
  int fileDirect;
  char *fileName;

  fileDirect = 0;
  fileName = "";

  if (argc <= 1) {
    head(fileDirect, fileName);
    exit();
  }

  else{
    if ((fileDirect = open(argv[1], 0)) < 0){
      printf(1, "head cannot open %s\n", argv[1]);
      exit();
    }
    head(fileDirect, argv[1]);
    close(fileDirect);

  }
  exit();
}
