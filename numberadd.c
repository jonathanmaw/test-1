
#include<stdio.h>
int main(int argc, char *argv[])
{
  int a, sum = 0;
  
  if(argc != 2) /* if argc doesnt have atlest 2 arguments not a file */
    {
      perror("Error: Please enter valid file name \n"); 
      return 1;
    }

  FILE *filein;
  filein = fopen(argv[1], "r"); /* opens and reads file */
  
  if(filein == NULL)
    {
      perror("Error: \n");
      return 1;
    }
  while(fscanf(filein, "%d", &a) == 1)
    {
      sum += a;      /* adds sum of numbers */
    }

  fclose(filein);
   
  printf("Number total from file: %d\n", sum);
  return 0; 
}
