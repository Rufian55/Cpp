/*****************************************************************************
* binomialCoef returns the binomial coefficient of a combination, that is,
* C(n,k) means how many combinations of n can be made with k choices.  Both a
* recursive and iterative Dynamic Programming solution are given below.
* Compile with gcc binomialCoef.c -o binCoef -g -Wall
* Adapted from matierials presented by J. Shufert, Oregon State Univ., W17
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// Prototypes.
int min(int a, int b);
int binomialCoeff_Iter(int n, int k);
int binomialCoeff_Rec(int n, int k);

int main(int argc, char **argv) {
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);

	if (argc != 3 || n < k) {
		printf("Usage: \"binCoef n k\" where n = total objects, k = how many to choose.\n");
		exit(1);
	}

	printf("Value of C(%d, %d) is %d\n", n, k, binomialCoeff_Iter(n, k));
	return 0;
}


/* Return value of Binomial Coefficient C(n, k) iteratively. O(n^2)
	Running time Θ(nk), space utilization Θ(nk). */
int binomialCoeff_Iter(int n, int k) {
	int i, j;
	int C[n + 1][k + 1]; // Memoized storage table.

	// Calculate value of Binomial Coefficient bottom up.
	for (i = 0; i <= n; i++)	{
		for (j = 0; j <= min(i, k); j++) {
			// Base Case.
			if (j == 0 || j == i) {
				C[i][j] = 1;
			}
			else { // Calculate value using previosly stored values.
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
	}
	return C[n][k];
}

// Return minimum of two ints.
int min(int a, int b) {
	return (a<b) ? a : b;
}

/* Return value of Binomial Coefficient C(n, k) recursively.
	Runs 2^n so NOT USED - FYI only. */
int binomialCoeff_Rec(int n, int k) {
	// Base Cases.
	if (k == 0 || k == n)
		return 1;
	// Recursion.
	return binomialCoeff_Rec(n - 1, k - 1) + binomialCoeff_Rec(n - 1, k);
}
