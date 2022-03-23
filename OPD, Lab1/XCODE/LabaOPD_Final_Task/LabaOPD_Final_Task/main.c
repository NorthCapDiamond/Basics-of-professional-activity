
//  main.c
//  LabaOPD_Final_Task
//
//  Created by Dmitry Drobysh on 20.10.2021.
//

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <regex.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
int mkdir(const char *pathname, mode_t mode);

int main(int argc, const char * argv[]) {
    
    DIR *dir;
    struct dirent *ent;
    mkdir("/Users/dmitrydrobysh/Desktop/jpegFiles", 0777);
    mkdir("/Users/dmitrydrobysh/Desktop/pngFiles", 0777);
    mkdir("/Users/dmitrydrobysh/Desktop/gifFiles", 0777);
    if ((dir = opendir ("/Users/dmitrydrobysh/Desktop/Laba001")) != NULL) {
      /* print all the files and directories within directory */
      while ((ent = readdir(dir)) != NULL) {
          char *file = ent->d_name;
          char *p;
          char *none = "NULL";
          p = strstr(file,".png");
          if (p!=none){
              char whatToDo[512];
              sprintf(whatToDo,"cp /Users/dmitrydrobysh/Desktop/Laba001/%s /Users/dmitrydrobysh/Desktop/pngFiles/",file);
              system(whatToDo);
              remove(file);
          }
          p = strstr(file,".jpeg");
          if (p!=none){
              char whatToDo[512];
              sprintf(whatToDo,"cp /Users/dmitrydrobysh/Desktop/Laba001/%s /Users/dmitrydrobysh/Desktop/jpegFiles/",file);
              system(whatToDo);
              remove(file);
          }
          p = strstr(file,".gif");
          if (p!=none){
              char whatToDo[512];
              sprintf(whatToDo,"cp  /Users/dmitrydrobysh/Desktop/Laba001/%s /Users/dmitrydrobysh/Desktop/gifFiles/",file);
              system(whatToDo);
              remove(file);
          }
      }
      closedir (dir);
    } else {
      /* could not open directory */
      perror ("");
      return EXIT_FAILURE;
    }
}

