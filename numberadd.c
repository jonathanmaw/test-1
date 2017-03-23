#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int read_numb (const char*  file_name)
{
  FILE* filein;
  filein = fopen(file_name, "r"); /* opens file */
  int i = 0;
  int sum = 0;
  if(filein == NULL)
    {
      perror("Error: \n");
      exit(1);
    }

   while(fscanf(filein, "%d", &i) == 1)
    {
      sum += i; /* adds sum of numbers */
    }

  fclose (filein);
  return sum;
}
int main(int argc, char *argv[])
 {
  int sum = read_numb(argv[1]);
  printf("Number total from file: %d\n", sum);
  return 0;
}
