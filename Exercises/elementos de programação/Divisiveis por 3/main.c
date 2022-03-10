#include <stdio.h>


int main()
{
    int x,y,matriztrasponta[5][5],matriz[5][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

    for(x=0;x<5;x++){
        for(y=0;y<5;y++){
            printf("[%i][%i]=%i",x,y,matriz[x][y]);
            matriztrasponta[y][x]= matriz[x][y];
        }
        printf("\n\n");
    }
        printf("\n\n");

    for(x=0;x<5;x++){
        for(y=0;y<5;y++){
            printf("[%i][%i]=%i",x,y,matriztransposta[x][y]);
        }
        printf("\n\n");
    }

    return 0;
}