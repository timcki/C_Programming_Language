typedef enum {
	/* basic types */
	NUMBER,
	RESULT,
	UNKNOWN,
	VARIABLE,

	/* basic operations */
	ADDITION,
	SUBSTRACTION,
	MULTIPLICATION,
	DIVISION,
	MODULO,
	VARIABLE_WRITE,

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

/* variables */
void pvars(void);
void initvars(void);
void writevar(char, double);
double getvar(void);

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

char var;
