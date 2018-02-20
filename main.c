#include "ft_printf.h"
#include <locale.h>

int main(void)
{
  setlocale(LC_ALL, "");
  printf(" C = [%C]\n", '@');
  ft_printf(" C = [%C]\n\n", '@');
  printf(" C = [%C]\n", '@');
  ft_printf(" C = [%wC]\n\n", '@');
  printf(" S = [%S]\n", L"@@");
  ft_printf(" S = [%wS]\n\n", "@@");
  printf("%5.d\n", 123);
  ft_printf("%5.d\n\n", 123);
  printf("%5.d\n", 123);
  ft_printf("%5.d\n\n", 123);
  printf("%5.c\n", 'c');
  ft_printf("%5.c\n\n", 'c');
  printf("%5.C\n", 'c');
  ft_printf("%5.C\n\n", 'c');
  while (1)
     ;
}
