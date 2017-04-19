
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int c, d;
  FILE *filein, *filew;
  char replace [100], *start, *end, temp;


    filein = fopen(argv[1], "r");

    if(filein == NULL)
      {
        printf("Error reading file");
        exit(1);
      }
    filew = fopen(argv[2], "w");

    if(filew == NULL)
      {
	printf("error opening file");
	exit(1);

      }

    while(fgets(replace, 100, filein) != NULL)
      {
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

	fprintf(filew, "%s", replace);
      }
    

    fclose(filew);
    fclose(filein);
    printf("%s\n", replace);

    return 0;

}
