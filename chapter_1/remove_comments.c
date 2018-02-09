#include <stdio.h>

#define MAXLINE 1000

#define IN 1
#define OUT 0
#define TRUE 1
#define FALSE 0

/*TEST*/
int
main() {
	int state, /*testetstestsett*/c, previous_char, edge_case;

	previous_char = 0;

	edge_case = FALSE;
	state = OUT;

	while ((c = getchar()) != EOF) {

		if (c == '*' && previous_char == '/') {
    		state = IN;
    		edge_case = FALSE;
		}

    	else if (c == '/' && previous_char == '*')
        	state = OUT;

    	else if (state == OUT) {
        	if (c == '/')
            	edge_case = TRUE;
        	else if (edge_case) {
            	putchar(previous_char);
            	putchar(c);
            	edge_case = FALSE;
        	}
        	else
        		putchar(c);
    	}
		previous_char = c;
	}
	return 0;
}
