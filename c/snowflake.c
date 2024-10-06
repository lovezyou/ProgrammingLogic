//this program i for to find identical pair of snowflak in given input max of 100000


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100000

//this function check tow flaks are identical from the starting position to the right
int identical_right (int flak1[], int flak2[], int start)
{
	int offset;
	for (offset = 0; offset < 6; offset++)
	{
		if (flak1[offset] != flak2[(start + offset) % 6])
			return 0;
	}
	return 1;
}

//checks flaks are identical from start to left
int identical_left (int flak1[], int flak2[], int start)
{
	int offset;
	for (offset = 0; offset < 6; offset++)
	{
		if ((start - offset) < 0)
			if (flak1[offset] != flak2[(start - offset) + 6])
				return 0;
		if (flak1[offset] != flak2[(start - offset) + 6])
			return 0;
		
	}
	return 1;
}

//returns true if flaks identical in start to left or right else false
int isIdentical (int flak1[], int flak2[])
{
	int start;
	for (start = 0; start < 6; start++)
	{
		if (identical_right(flak1, flak2, start))
			return 1;
		if (identical_left(flak1, flak2, start))
			return 1;
	}
	return 0;
}

//taks array of snowflakes and checks for identiacl
int identify_identical(int snowflaks[][6], int n)
{
	int i, j;
	for	( i=0; i<n; i++)
	{
		for (j=i+1; j<n; j++)
		{
			if (isIdentical(snowflaks[i], snowflaks[j]))
			{
				printf("\nfound identical!\n");
				return 1;
			}
		}
	}
	printf("\nno identical found!\n");
	return 0;
}

int main()
{
	int n, i, j;
	static int snowflaks[MAXSIZE][6];
	printf("Enter number of flaks: ");
	scanf("%d", &n);
	for ( i=0; i<n; i++)
	{
		printf("Enter flake patern values: ");
		for ( j=0; j<6; j++)
		{
			scanf("%d", &snowflaks[i][j]);
		}
	}
	identify_identical(snowflaks, n);
	return 0;
}
