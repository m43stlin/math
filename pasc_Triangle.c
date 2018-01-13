#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define PAT_SIZE 50
int main(int argc, char* argv[]) {

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
    char pat[PAT_SIZE];
    int len, c;

    for(;;) {
        printf("Coefficient: ");
        fflush(stdout);

        if (fgets(pat, 50, stdin) != NULL)
        {
            pat[strcspn(pat, "\n")] = 0;
            len = strlen(pat);

            c = atoi(pat);

            if (strcmp(pat, "q") == 0)
                break;

            if (len < 1)
            {
                puts("Please enter a positive integer.");
            }

            printf("%d\n", c);
        }

    }
//
//     int r, spc, c = 1;
//
//        for (int i = 0; i < r; ++i) {
//            for (spc = 1; spc <= r - i; ++spc)
//                printf("  ");
//
//            for (int j = 0; j <= i; j++) {
//                if (j == 0 || i == 0)
//                    c = 1;
//                else
//                    c = c * (i - j + 1) / j;
//
//                printf("%4d", c);
//            }
//            printf("\n");
    //    }
    //}
    return 0;
}
