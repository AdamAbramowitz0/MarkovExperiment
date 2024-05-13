#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <time.h>
int main(int argc, char *argv[]){

        FILE * file = fopen(argv[1],"rb");
        double (*arr)[256][256] = (double (*)[256][256]) malloc(256*256*sizeof(double));
        int x = fgetc(file);
        int y = fgetc(file);
        
        while(y != -1){
                ((*arr)[x][y]) = ((*arr)[x][y]) + 1.0;
                x = y;
                y = fgetc(file);
                
        }

        
        for(int i = 0; i < 256; i++){
                double sum = 0;
                for(int j = 0; j < 256; j++){
                        sum+= (*arr)[i][j];
                }
                if(sum != 0){
                        (*arr)[i][0] = (*arr)[i][0]/sum;
                        // for(int j = 1; j < 256; j++){
                        //         (*arr)[i][j] = (*arr)[i][j]/sum + (*arr)[i][j-1];
                        // }
                }
        }
        // fprintf(stderr,"HERE");
        // for(int i = 65; i < 90; i++){
        //         for(int j = 65; j < 90; j++){
        //                 printf("|%f|", (*arr)[i][j]);
        //         }
        //         printf("\n\n\n");
        // }
        char start;

        scanf("%c",&start);
        char curr; 
        double peak;
        for(int i = 0; i < 100; i++){
                peak = 0;
                for(int j = 0; j < 256; j++){

                        if((*arr)[start][j] >= peak){
                                peak = (*arr)[start][j];
                                curr = j;
                        }
                }
                printf("%c",curr);
                start = curr;
        }


}  


// if((*arr)[start][j] >= 1.0/((time(NULL) %7)+1)){
                        //         printf("%c",j);
                        //         start = j;
                        //         break;
                        // }
