// this is a small program solution for food line programing challenge

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINES 100

//finds shortest line for new people
int shortest_line_index(int lines[], int n) {
	int j, shortest = 0;
	for (j = 1;j < n; j++)
		if (lines[j] < lines[shortest])
			shortest = j;
	return shortest;
}

void solve(int lines[], int n, int m) {
	int i, shortest;
	for (i = 0;i < m; i++) {
		shortest = shortest_line_index(lines, n);
		printf("in line %d : no of people %d\n", shortest + 1, lines[shortest]);
		lines[shortest]++;
	}
}

int main(void) {
	int lines[MAX_LINES];
	int n, m, i;
	printf("enter number of \"lines\" \"new people\" : ");
	scanf("%d%d", &n, &m);
	for (i = 0;i < n; i++)
		scanf("%d", &lines[i]);
	solve(lines, n, m);
	return 0;
}
