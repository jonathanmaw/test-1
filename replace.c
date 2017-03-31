#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int c, d;
  FILE *filein;
  char replace [100], *start, *end, temp;


    filein = fopen(argv[1], "r");

    if(filein == NULL)
    {
        printf("Error reading file");
        exit(1);
    }


    fgets(replace, 100, filein);

  fclose(filein);
  start = replace;
  end = start + strlen(replace) - 1;


    while(end > start)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        ++start;
        --end;
    }



  filein = fopen("reversefile.txt", "wt");
  fprintf(filein, "%s", replace);
  fclose(filein);
  printf("%s\n", replace);

  return 0;

}
