#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100


typedef enum {
	NUMBER,
	ADDITION,
	SUBSTRACTION,
	MULTIPLICATION,
	DIVISION,
	MODULO,
	RESULT,
	UNKNOWN
} Optype;


/* input handling */
Optype getOp(char []);
Optype translateOp(char);

/* buffer management */
int getch(void);
void ungetch(int);

/* stack functions */
void push(double);
double pop(void);
void pstack(void);

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
		case RESULT:
			printf("\t%.8f\n", pop());
			break;
		case UNKNOWN:
			printf("ERROR: Unkown operation: %s\n", type);
			return -1;
		}
	}
	return 0;
}

Optype
translateOp(char c)
{
	switch (c) {
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
	default:
		return UNKNOWN;
	}
}

Optype
getOp(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	/* return value if operand and not number */
	if (!isdigit(c) && c != '.')
		return translateOp(c);
	i = 0;
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
		printf("ERROR: Stack full can't push %f\n", v);
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
		printf("%f, ", stack[sp]);
	}
	printf("\n");
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
		printf("ERROR: ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
