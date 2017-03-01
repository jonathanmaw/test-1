#include<stdio.h>
int main(int argc, char *argv[])
{
    int a, sum = 0;

    FILE *filein;
    filein = fopen(argv[1], "r"); /* opens and reads file */
      if(argc != 2)
    {
        perror("Error: Please enter valid file name: \n"); /* prints error if not a valid file */
    }
    
    while(fscanf(filein, "%d", &a) == 1)
    {
        sum += a;      /* adds sum of numbers */
    }

    fclose(filein);
   
    printf("Number total from file: %d\n", sum);
    return 0; 
}
