#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(){
    DIR *dirY = opendir("/var/Y");
    printf("hello Y\n");
    DIR *dirX = opendir("/var/X");
    printf("hello X\n");
}
