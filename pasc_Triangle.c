#include <stdio.h>

int main() {
    int r, spc, c = 1;

    scanf("%d", &r);

    /*
     * Calculation for first three iterations (row = 5)
     * -----------------------------------------------
     * i = 0
     *
     * spc = 1; spc <= 5;
     * 		printf("  ")
     *
     * 		- Prints initial spaces to print coefficients
     *
     * j = 0; k <= 0
     * 		if j == 0 then c = 1
     *
     * 		printf("%4d", c)
     *
     * 		- Print c with a spacing of 4
     * ------------------------------------------------------------------
     * i = 1
     *
     * spc = 1; spc <= 4;
     * 		printf("  ")
     *
     * 		- Prints initial spaces to print coefficients
     *
     * j = 0; j <= 1;
     * 		if j == 0 then c = 1
     *
     * 		if j == 1 then c = 1*(1-1+1)/1 = 1(0+1)/1 = 1(1)/1 = 1
     *
     *
     * 		- Then we print a line break to move on to the next iteration
     * ------------------------------------------------------------------
     * i = 2
     *
     * spc = 1; space <= 3;
     * 		printf("  ")
     *
     * 		- Prints initial spaces to print coefficients
     *
     * j = 0; j <= 2;
     * 		if j == 0 then c = 1
     *
     * 		if j == 1 then c = 1*(2-1+1)/1 = 1(1+1)/1 = 1(2)/1 = 2
     *
     * 		if j == 2 then c = 1*(2-2+1)/2 = 1(2-2+1)/1 = 1(1)/1 = 1
     *
     *
     * 		- Then we print a line break to move on to the next iteration
     *
     * 		- After 3 iterations we have the following:
     *
     * 		          		  1
     * 		        		1   1
     * 		      		  1   2   1
     *
     * ------------------------------------------------------------------
     */

    for (int i = 0; i < r; ++i) {
        for (spc = 1; spc <= r-i; ++spc)
            printf("  ");

        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == 0)
                c = 1;
            else
                c = c*(i-j+1)/j;

            printf("%4d", c);
        }
        printf("\n");
    }

    return 0;
}
