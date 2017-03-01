#include<stdio.h>
main(int argc, char *argv[])
{
    int a, sum = 0;

    FILE *filein;
    filein = fopen(argv[1], "r"); /* opens and reads file */ 
   
    while(fscanf(filein, "%d", &a) == 1) 
    {
        sum += a;      /* adds sum of numbers */
    }

    fclose(filein);
   
    printf("Number total from file: %d\n", sum);
    return 0; 
}
