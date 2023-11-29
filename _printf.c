#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * print_char - print char
 * @list: list of args
 * @length: total length of str
 */
void print_char(va_list list, int *length)
{
	int a = va_arg(list, int);

	write(1, &a, 1);
	(*length)++;
}
/**
 * print_str - print string
 * @list: list of args
 * @length: total length of str
 */
void print_str(va_list list, int *length)
{
	char *str = va_arg(list, char *);

	if (str == NULL)
	{
		write(1, "(null)", 6);
		length += 5;
		return;
	}

	for (int j = 0; str[j]; j++)
	{
		write(1, &str[j], 1);
		(*length)++;
	}
}

/**
 * checkIsCharOrStr - check is char or string
 * @list: list of args
 * @format: format for checking
 * @length: total length of str
 */
void checkIsCharOrStr(va_list list, char format, int *length)
{
	switch (format)
	{
	case 'c':
		print_char(list, length);
		break;
	case 's':
		print_str(list, length);
		break;
	case '%':
		write(1, "%", 1);
		(*length)++;
		break;
	default:
		break;
	}
}
/**
 * _printf - copy of printf
 * @format: format
 * @...: args
 * Return: the length of text
*/
int _printf(const char *format, ...)
{
	int length = 0;
	va_list list;

	va_start(list, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			checkIsCharOrStr(list, format[++i], &length);
		}
		else
		{
			write(1, &format[i], 1);
			length++;
		}
	}

	va_end(list);
	return (length);
}
