#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* readinput(FILE *filein)
{
#define CHUNK 100
   char* input = NULL;
   char tempbuf[CHUNK];
   size_t inputlen = 0, templen = 0;
   do {
       if(fgets(tempbuf, CHUNK, filein) == NULL)
	 break;
       templen = strlen(tempbuf);
       inputlen += templen;
       input = realloc(input, inputlen+1);
       strcat(input, tempbuf);
    } while (templen==CHUNK-1 && tempbuf[CHUNK-2]!='\n');
    return input;
}


int main(int argc, char *argv[])
{
  int c, d;
  FILE *filein, *filew;
  char *replace, *start, *end, temp;


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

    while((replace = readinput(filein)) != NULL)
      {
	start = replace;
	end = start + strlen(replace) - 2;


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
    

    return 0;

}
