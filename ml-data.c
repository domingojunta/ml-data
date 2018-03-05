#include <stdio.h>
#include "ninstances-c/ninstances.h"

int main(void)
{
int x, flag;
flag=1;

while(flag==1)
{
printf("Menu:\n");
printf("0.- EXIT\n");
printf("1.- Number of instances, features and labels archivo yeast (Juan A. Romero)\n");
printf("2.- Number of instances, features and labels archivo scene (Juan A. Romero)\n");
scanf("%d", &x);
fflush(stdin);
printf("\n\n");
switch(x){
    case 0:
        flag=0;
        break;
    case 1:
        printf("Ejecutando la función ninstances(yeast) de Juan A. Romero:\n");
        ninstances("yeast.complete");
        break;
    case 2:
        printf("Ejecutando la función ninstances(scene) de Juan A. Romero:\n");
        ninstances("scene.complete");
        break;
/* add here more functionality */
    }
}

}
