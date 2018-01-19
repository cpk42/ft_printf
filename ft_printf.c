#include "ft_printf.h"

/*
** argument prototype: %[flags][width/margin][.precision][hh|h|l|ll|j|z]type
**
** flags:			'+' || '-' || ' ' || '#' || '0';
**
** width/margin:	min amount of displayed digits, does not cut digits if less,
**					fill with spaces on the left side;
**					if '*' added it's necessary to pass one more parameter with
**					a number of spaces before the actual parameter;
**
** .precision:		for diouxX min amount of digits, fill with 0 is necessary;
**					for eEf amount of digits after dot;
**					for gG amount of all digits, if bigger displays number;
**					for sS max amount of characters;
**					if '*' added is necessary to pass one more parameter with a
**					number of spaces before the actual parameter;
**
** hh|h|l|ll|j|z|q:	default values' modification:
**						hh:	for idouxX - char;
**						h:	for idouxX - short int;
**						l:	for idouxX - long int, for feE - double;
**						ll:	for idouxX - long long int;
**						j:	for idouxX - intmax_t;
**						z:	for idouxX - size_t;
**						q:	for CS - prints Unicode
*/
void convert_char(t_tools tools, char *str, va_list ap)
{
  char *temp;
  int i;
  int j;

  if (TYPE == 's')
    temp = va_arg(ap, char *);
//  else if (TYPE == 'c')
//    (*(str[ft_strlen(str)])) = va_arg(ap, int);
  ft_putstr(temp);
  while (temp[i])
  {
    j = ft_strlen(str);
    str[j] = temp[i];
    i++;
  }
}

void find_flag(t_tools tools, char *str, va_list ap)
{
    if (TYPE == 's' || TYPE == 'c')
      convert_char(tools, str, ap);
}

int parse_flag(char *format, char *str, t_tools tools, va_list ap, int *i)
{
  while (!CONV(format[*i]))
    (*i)++;
  // ft_putchar(format[*i]);
  TYPE = format[*i];
  find_flag(tools, str, ap);
  return (*i);
}

int parse_format(char *format, char *str, t_tools tools, va_list ap)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (format[i])
  {
    // ft_putnbr(j);
    if (format[i] != '%' && format[i])
      {
        str[j] = format[i];
        i++;
	j++;
      }
    else
      {
	i = parse_flag(format, str, tools, ap, &i);
	j = ft_strlen(str);
      }
  }
  return (i);
}

int	ft_printf(const char *format, ...)
{
  t_tools tools;
  char str[1024];
  va_list ap;

  va_start(ap, format);
  ft_bzero(str, 1024);
  parse_format((char *)format, str, tools, ap);
//  ft_putstr(str);
  va_end(ap);
  return (1);
}

int main()
{
    ft_printf("asdasd%sasdsad%asdass%s", "string", "new", "str");
    return 1;
}


/*
  char1 byte-128 to 127 or 0 to 255
  unsigned char1 byte0 to 255
  signed char1 byte-128 to 127
  int2 or 4 bytes-32,768 to 32,767 or -2,147,483,648 to 2,147,483,647
  unsigned int2 or 4 bytes0 to 65,535 or 0 to 4,294,967,295
  short2 bytes-32,768 to 32,767
  unsigned short2 bytes0 to 65,535
  long4 bytes-2,147,483,648 to 2,147,483,647
  unsigned long4 bytes0 to 4,294,967,295
  float4 byte1.2E-38 to 3.4E+386 decimal places
  double8 byte2.3E-308 to 1.7E+30815 decimal places
  long double10 byte3.4E-4932 to 1.1E+493219 decimal places
unsigned long long 18,446,744,073,709,551,615.
\aaudible alert
\bbackspace
\fform feed
\nnewline, or linefeed
\rcarriage return
\ttab
\vvertical tab
\						\backslash


%d %i     Decimal signed integer.
%o      Octal integer.
%x %X     Hex integer.
%u      Unsigned integer.
%c      Character.
%s      String. See below.
%f      double
%e %E     double.
%g %G     double.
%p        pointer.
%n      Number of characters written by this printf.
No argument expected.
% %%. No argument expected.
*/
