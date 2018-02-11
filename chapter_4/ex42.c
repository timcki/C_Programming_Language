#include <stdio.h>
#include <math.h>

double atof(char []);
int trimbeg(char []);
int isspace(char);


int
main()
{
	double num;
	num = atof("12.2e-3");
	printf("%f\n", num);
	return 0;
}


double
atof(char s[])
{
	double val; /* value before f point */
	double after_point; /* value after f point */
	int i; /* string index */
	int sign, sign_exp; /* choose sign for value and exponent */
	int power; /* value of the exponent after E */

	val = 0;
	power = 0;
	after_point = 1;
	i = trimbeg(s); /* trim whitespaces from the beginning, return index for first sign of the number */

	/* decide about sign */
	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '-' || s[i]  == '+')
		i++;

	/* read value of integer */
	while (s[i] != '\0' && s[i] != '.' && s[i] != ',') {
		val *= 10.0;
		val += s[i++] - '0';
	}

	if (s[i] != '.' || s[i] != ',')
		i++;

	/* handle numbers after floating point */
	while (s[i] != '\0') {

		/* scientific notation handler, hijacks the entire while loop so no need
		 * for an else statemnt in the normal handler part
		 */
		if (s[i] == 'e' || s[i] == 'E') {
			i++;
			sign_exp = (s[i] == '-') ? -1 : 1;
			if (s[i] == '-' || s[i]  == '+')
				i++;
			/* read power after E or e */
			while(s[i] != '\0') {
				power *= 10;
				power += (s[i++] - '0');
			}
			val *= pow(10, (sign_exp * power));
			break;

		}

		after_point *= 0.1;
		val += ((s[i++] - '0') * after_point);
	}
	return sign * val;
}


int
isspace(char c)
{
	return (c == ' ') ? 1 : 0;
}


int
trimbeg(char s[])
{
	int i;
	i = 0;
	while (isspace(s[i]))
		i++ ;
	return i;
}
