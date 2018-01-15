#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define PAT_SIZE 50
int main(int argc, char* argv[]) {

    /*
     * Calculation for first three coefficients (row = 5)
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
    int coefs[10];
    int len, r;

    /* Main loop */
    for(;;) {
        printf("Enter a Coefficient between from 1 - 10 ('q' quits): ");

        /*
         * Get user stdin and place the value into pat using fgets().
         * Strip the new line character from the input, and then get
         * the length of the input stored in pat.
         */
        if (fgets(pat, 50, stdin) != NULL) {
            pat[strcspn(pat, "\n")] = 0;
            len = strlen(pat);

            /* Convert user input into an integer. */
            r = atoi(pat);

            /* If the user enters 'q' then quit the program. */
            if (strcmp(pat, "q") == 0)
                break;
            /*
             * If the user enters nothing or enters a negative number
             * give them a message.
             */
            if (len < 1) {
                puts("Please enter an integer that is greater than or equal to 0.");
                printf("\tYou entered: %d\n", r);
            /*
             * If the user enters a value that is greater than 10
             * give them a message.
             */
            } else if (r > 10) {
                puts("Please enter an integer that is greater than 0 and less than 11");
                printf("\tYou entered: %d\n", r);
            } else {

                /*
                 * If the user enters a positive integer that meets the
                 * than generate the criteria, generate the pyramid.
                 */
                int spc, c = 1;

                for (int i = 0; i < r; ++i) {
                    for (spc = 1; spc <= r - i; ++spc)
                        printf("  ");

                    for (int j = 0; j <= i; j++) {
                        if (j == 0 || i == 0) {
                            c = 1;
                            /*
                             * Also store the appropriate values in the
                             * coefficient array.
                             */
                            coefs[j] = 1;
                            coefs[i] = 1;
                        } else {
                            c = c * (i - j + 1) / j;
                            /* Store appropriate values in the coefficient array */
                            coefs[j] = c;
                        }
                        printf("%4d", c);
                    }
                    printf("\n");
                }
                for (int k = 0; k < r ; ++k) {
                    printf("%d\n",coefs[k]);
                }
            }
        }
    }

    return 0;
}
