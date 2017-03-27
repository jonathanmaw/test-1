#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int read_numb(const char *file_name, const int alternate)
{
	FILE *filein;
	filein = fopen(file_name, "r"); /* opens file */
	int i = 0;
	int sum = 0;

	if (filein == NULL)
	{
		perror("Error reading file");
		exit(1);
	}


	while (fscanf(filein, "%d", &i) == 1)
	{
		sum += i; /* adds sum of numbers */

		if (fscanf(filein, "%d", &i) != 1)
		break;

		if (alternate)
		{
			sum -= i;
		}

		else
		{
			sum += i;
		}

	}

	fclose(filein);
	return sum;

}

int main(int argc, char *argv[])
{
	int alternate = 0;
	int sum = 0;
	int opt;

	while ((opt = getopt (argc, argv, "a")) != -1)
	{
		if (opt == 'a')
		{
			alternate = 1;
		}

		else
		{
			fprintf(stderr, "Usage: %s [-a] file\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	sum = read_numb(argv[optind], alternate);
	printf("Number total from file: %d\n", sum);
	return 0;
}
