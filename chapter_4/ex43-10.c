#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include <math.h>

#define MAXOP 100

typedef enum {
	/* basic types */
	NUMBER,
	RESULT,
	UNKNOWN,

	/* basic operations */
	ADDITION,
	SUBSTRACTION,
	MULTIPLICATION,
	DIVISION,
	MODULO,

	/* math.h */
	SIN,
	COS,
	TAN,

	EXP,
	LOG,

	POW,
	SQRT,

	/* utility */
	QUIT
} Optype;

/* -> Basic calculator from exercise extended with enum type for operations.
 * -> Support for negative numbers and for modulus operand
 */


/* input handling */
Optype getOp(char []);
Optype translateOp(char);
Optype translateSOp(char s[]);

/* buffer management */
int getch(void);
void ungetch(int);

/* stack functions */
void push(double);
double pop(void);
void pstack(void);
double stacktop(void);
void topdup(void);
void swap(void);

int
main()
{
	Optype type;
	double op2;
	char s[MAXOP];

	while ((type = getOp(s)) != EOF) {

		switch (type) {

		case NUMBER:
			push(atof(s));
			break;

		case ADDITION:
			push(pop() + pop());
			break;

		case MULTIPLICATION:
			push(pop() * pop());
			break;

		case SUBSTRACTION:
			op2 = pop();
			push(pop() - op2);
			break;

		case DIVISION:
			op2 = pop();
			if (!op2)
				push(pop() / op2);
			else {
				printf("ERROR: Division by zero\n");
				return -1;
			}
			break;

		case MODULO:
			op2 = pop();
			if (!op2)
				push((int) pop() % (int) op2);
			else
				printf("ERROR: Division by zero\n");
			break;

		case SIN:
			push(sin(pop()));
			break;

		case COS:
			push(cos(pop()));
			break;

		case TAN:
			push(tan(pop()));
			break;

		case EXP:
			push(exp(pop()));
			break;

		case LOG:
			op2 = pop();
			if (op2 < 0 || op2 == 1)
				printf("ERROR: Bad logarithm\n");
			else
				push(log(op2));
			break;

		case POW:
			op2 = pop();
			push(pow(pop(), op2));
			break;

		case SQRT:
			op2 = pop();
			if (op2 < 0)
				printf("ERROR: Square root of negative number\n");
			else
				push(sqrt(op2));
			break;

		case RESULT:
			printf("\t%.8g\n", pop());
			break;

		case QUIT:
			return 0;

		case UNKNOWN:
			printf("ERROR: Unkown operation: %s\n", type);

		}
	}
	return 0;
}

Optype
translateOp(char c)
{
	switch (c) {
	/* base */
	case '+':
		return ADDITION;
	case '-':
		return SUBSTRACTION;
	case '/':
		return DIVISION;
	case '*':
		return MULTIPLICATION;
	case '\n': case '=':
		return RESULT;
	case '%':
		return MODULO;

	/* utility */
	case 'q':
		return QUIT;
	default:
		return UNKNOWN;
	}
}

Optype
translateSOp(char s[])
{
	if 		(!strcmp(s, "sin") || !strcmp(s, "SIN"))
		return SIN;
	else if (!strcmp(s, "cos") || !strcmp(s, "COS"))
		return COS;
	else if (!strcmp(s, "tan") || !strcmp(s, "TAN"))
		return TAN;
	else if (!strcmp(s, "exp") || !strcmp(s, "EXP"))
		return EXP;
	else if (!strcmp(s, "log") || !strcmp(s, "LOG"))
		return LOG;
	else if (!strcmp(s, "pow") || !strcmp(s, "POW"))
		return POW;
	else if (!strcmp(s, "sqrt") || !strcmp(s, "SQRT"))
		return SQRT;
	else
		return UNKNOWN;
}

Optype
getOp(char s[])
{
	int i, c, tmp;
	/* escape all the whitespaces */
	i = 0;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;


	s[1] = '\0';

	/* return operand if not number or letter */
	if (!isdigit(c) && !isalpha(c) && c != '-' && c != '.')
		return translateOp(c);

	/* handle negative numbers */
	else if (c == '-') {
		if (isdigit(c = getch())) {
			s[++i] = c;
		}
		else {
			ungetch(c);
			return translateOp('-');
		}
	}

	/* handle math.h operations */
	else if (isalpha(c)) {
		while (isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		return translateSOp(s);
	}
	
	
	/* integer part */
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;

	/* fraction part */
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;


	s[i] = '\0';
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}


#define MAXVAL 100
int sp = 0;
double stack[MAXVAL];

void
push(double v)
{
	if (sp < MAXVAL)
		stack[sp++] = v;
	else
		printf("ERROR: Stack full can't push %g\n", v);
}

double
pop(void)
{
	if (sp)
		/* (--sp) because sp is at next free position */
		return stack[--sp];
	printf("ERROR: Stack empty\n");
	return 0.0;
}

void
pstack(void)
{
	printf("STACK(%d):\n", sp);
	for (int i = 0; i < sp; ++i) {
		printf("%f, ", stack[i]);
	}
	printf("\n");
}

double
stacktop(void)
{
	if (sp)
		return stack[sp-1];
	else
		printf("ERROR: Stack empty\n");
}

void stackdup(void)
{
	int i, tmp;
	if (sp < 99) {
		for (i = sp-1; i > 0; i--)
			stack[i] =  stack[i+1];
		sp++;
		stack[1] = stack[0];
	}
	else
		printf("ERROR: Stack full can't duplicate top\n");
}

void swap(void)
{
	int tmp;
	tmp = stack[0]; stack[0] = stack[1]; stack[1] = tmp;
}



#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

/* Check if there is a char in the buffer. If so return it instead of stdin. */
int
getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* Push char in the buffer */
void
ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ERROR: ungetch -  too many characters\n");
	else
		buf[bufp++] = c;
}
