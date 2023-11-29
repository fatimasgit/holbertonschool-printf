#include <stdio.h>
#include "main.h"
/**
 * custom_pow - find power of int
 * @base: is always 10
 * @power: power
 * Return: the base of the power
 */
int custom_pow(int base, int power)
{
	if (power == 0)
		return (1);
	return (base * custom_pow(base, power - 1));
}
