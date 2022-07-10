
/**
 * steps to include.
 * you ar allowed to copy this file as make changes to any section including this comment section.
 * im legit just brainstorming
 *
 *
 * the printk funtion prints arguments to output
 *      it prints in stages
 *          stage one: its returns elements to output
 *          stage two: if thers % its activates func.c file
 *                      func.c file would contain state() function and spec() function
 *          state() function would check if theres state mentioned the execute action
 *                  else ( just execute spec() function)
 *
 *          spec() and state() functions may include other functions in them or
 *              have to call the functions.
 *
 * essentially the main functions include
 *      main()
 *          {
 *              calls printk()
 *          }
 * 
 *
 * printk()
 *          {
 *              if (% = true)
 *              calls spec() &&
 *                    state()
 *          }
 * state()
 *          {
 *              calls all the state function()
 *          }
 * spec()
 *          {
 *              calls all specifier functions()
 *          }
 *
 * 
 * int printk(const char *format, ...)
 * {
 *  enter any length of characters into array[n]
 * 
 *  count len of characters = len
 * 
 *  for (i =0, i < len +1)
 *      print characters as putchar(array[n])
 *      
 *      if i == %
 *      call func( array[n], len)
 *      
 *      n++, i++
 *  
 * }
 */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...);
/**
  *_printf - prints formatted output.
  *input.
  *
  *Return: number of chars printed or -1.
  */
 int main(void)
{
    _printf("%d  ");
    return (0);
}

int _printf(const char *format, ...)
{
	va_list args;
    va_start(args, format);
    int (*get_func)(va_list, int);


	int i, len;

	if (!(format))
		return (-1);
	i = 0;
	len = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				len += putchar(format[i]);
				i++;
				continue;
			}
			if (format[i] == '\0')
				return (-1);

            callspec = get_func(format[i])
             
        }
        else
          {
            len = len + putchar(format[i]);
            i++;
          }
    }
	va_end(args);
	return (len);
}