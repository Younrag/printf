#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array
 * @flags: Calculates flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', p_char}, {'s', p_string}, {'%', p_percent},
		{'i', p_int}, {'d', p_int}, {'b', p_binary},
		{'u', p_unsigned}, {'o', p_octal}, {'x', p_hexadecimal},
		{'X', p_UpperHexa}, {'p', p_pointer}, {'S', p_NOprintable},
		{'r', p_reverse}, {'R', p_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
