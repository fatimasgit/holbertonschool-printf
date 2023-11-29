#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
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
