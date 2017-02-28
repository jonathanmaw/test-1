#include<stdio.h>
main()
{
    int a, sum = 0;

    FILE *filein;
    filein= fopen("numbers.txt", "r"); /* opens and reads file */ 
   
    while(fscanf(filein, "%d", &a) == 1) {
        sum += a;      /* adds sum of numbers */
    }

    fclose(filein);
   
    printf("Number total from file: %d", sum);
    return 0; 
}
