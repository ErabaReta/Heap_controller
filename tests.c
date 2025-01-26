# include "heap_controller.h"
#include  "string.h"
#include "stdio.h"
int	main(int ac, char **argv)
{
	int matrix_size  = (ac > 1  ? atoi(argv[1]) : 10);
	if (matrix_size <= 0)
		matrix_size = 1;

	// allocating
	int **matrix = (int **)mallocate(sizeof(int *) * matrix_size);

	for(int i = 0; i < matrix_size; ++i)
	{
		matrix[i] = (int *)mallocate(sizeof(int ) * matrix_size);
	}

	// writing to allocated memory
	for(int i = 0; i < matrix_size; ++i)
	{
		for (int j = 0; j < matrix_size; ++j)
		{
			matrix[i][j] = i + j;
		}
	}

	//	reading allocated memory
	for(int i = 0; i < matrix_size; ++i)
	{
		for (int j = 0; j < matrix_size; ++j)
		{
			printf("matrix[%d][%d] == %d ", i, j, matrix[i][j]);
		}
		printf("\n");
	}

	//free all memory
	free_all_heap();
	// exiter(0);

	return 0;
}