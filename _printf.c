#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	const char *c;
	char spec, *string, chr;
	int count = 0, i;

	va_list ap;
	if (format == NULL)
                return (-1);

	va_start(ap, format);
	for (c = format; *c && c != 0; c++)
	{
		if (*c == '%')
		{
			c++;
			spec = *c;
			switch (spec) {
				case 'c':
					chr = va_arg(ap, int);
					putchar(chr);
					count++;
					continue;
				case 's':
					string = va_arg(ap, char*);
					for (i = 0; *string != '\0'; i++)
					{
						putchar(*string);
						string++;
					}
					count = count + i;
					continue;
				case '%':
					putchar('%');
					count++;
					continue;
			}
		}
		putchar(*c);
		count++;
	}
	putchar('\0');
	return (count);
}
