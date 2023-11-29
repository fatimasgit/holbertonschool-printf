#include<stdio.h>
#include<unistd.h>
#include<stdarg.h>
#include<stdlib.h>
#include<math.h>
#include"main.h"

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
int j = 0;
if (str == NULL)
{
write(1, "(null)", 6);
(*length) += 6;
return;
}
for (; str[j]; j++)
{
write(1, &str[j], 1);
(*length)++;
}
}
/**
 * print_int - print integer
 * @list: list of args
 * @length: length of text
 */
void print_int(va_list list, int *length)
{
int len_of_int = -1;
int a;
int temp = va_arg(list, int);
int copy_of_temp = temp;
if (temp < 0)
{
temp = copy_of_temp *= -1;
write(1, "-", 1);
(*length)++;
}
while (copy_of_temp != 0)
{
len_of_int++;
copy_of_temp /= 10;
}
(*length) += len_of_int + 1;
while (len_of_int != 0)
{
a = (temp / (int)(custom_pow(10, len_of_int))) + 48;
write(1, &a, 1);
temp %= (int)(custom_pow(10, len_of_int));
len_of_int--;
}
a = temp + 48;
write(1, &a, 1);
}
/**
 * find_type - check is char or string
 * @list: list of args
 * @format: format for checking
 * @length: total length of str
 */
void find_type(va_list list, char format, int *length)
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
case 'd':
case 'i':
print_int(list, length);
break;
default:
write(1, "%", 1);
write(1, &format, 1);
(*length) += 2;
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
int i = 0;
if (format == NULL)
{
exit(98);
}
va_start(list, format);
for (; format[i] != '\0'; i++)
{
if (format[i] == '%' && format[i + 1] == '\0')
{
return (-1);
}
else if (format[i] == '%')
{
find_type(list, format[++i], &length);
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
