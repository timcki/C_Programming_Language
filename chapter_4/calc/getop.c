#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "calc.h"

Optype
translateOp(char c)
{

	/* variables */
	if (c >= 'a' && c <= 'z')
		return VARIABLE;

	switch (c) {
	case '+':
		return ADDITION;
	case '-':
		return SUBSTRACTION;
	case '/':
		return DIVISION;
	case '*':
		return MULTIPLICATION;
	case '\n':
		return RESULT;
	case '=':
		return VARIABLE_WRITE;
	case '%':
		return MODULO;
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
		/* if just one char it's a variable and then use translateOp insted of entire
		 * string comparison
		 */
		if (!isalpha(tmp = getch()))
			return translateOp(c);
		ungetch(tmp);

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
