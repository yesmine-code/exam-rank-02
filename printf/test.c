//#include"ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
int ft_printf(const char *format, ...);
int main()
{
  int i;
    printf("\n----------------------------\n");
    i = printf("%s|\n", "hello");
    printf("-%d-", i);
    i = printf("%.s|\n", "hello");
    printf("-%d-", i);
    i = printf("%10s|\n", "hello");
    printf("-%d-", i);
    i = printf("%.8s|\n", "hello");
    printf("-%d-", i);
    i = printf("%10.0s|\n", "hello");
    printf("-%d-", i);
    printf("\n----------------------------\n");
    i = ft_printf("%s|\n", "hello");
    ft_printf("-%d-", i);
    i = ft_printf("%.s|\n", "hello");
    ft_printf("-%d-", i);
    i = ft_printf("%10s|\n", "hello");
    ft_printf("-%d-", i);
    i = ft_printf("%.8s|\n", "hello");
    ft_printf("-%d-", i);
    i = ft_printf("%10.0s|\n", "hello");
    ft_printf("-%d-", i);

    printf("\n----------------------------\n");

    printf("%0d|\n", 12);
    printf("%.d|\n", 12);
    printf("%10d|\n", 12);
    printf("%10.4d|\n", -16);
    printf("%10.0d|\n", 12);
    ft_printf("%10.12d|\n", 12);

     ft_printf("%0d|\n", 12);
    ft_printf("%.d|\n", 12);
    ft_printf("%10d|\n", 12);
    ft_printf("%10.4d|\n", -16);
    ft_printf("%10.0d|\n", 12);
    ft_printf("%10.12d|\n", 12);


    printf("%0d|\n", -12);
    printf("%.d|\n", -12);
    printf("%10d|\n", -12);
    printf("%.4d|\n", -12);
    printf("%10.0d|\n", -12);
    printf("%10.12d|\n", -12);

    ft_printf("%0d|\n", -12);
    ft_printf("%.d|\n", -12);
    ft_printf("%10d|\n", -12);
    ft_printf("%.4d|\n", -12);
    ft_printf("%10.0d|\n", -12);
    ft_printf("%10.12d|\n", -12);

    printf("----------------------------\n");
    printf("%0x|\n", 12);
    printf("%.x|\n", 12);
    printf("%10x|\n", 12);
    printf("%.4x|\n", 12);
    printf("%10.0x|\n", 12);
    printf("%10.12x|\n", 12);


    ft_printf("%0x|\n", 12);
    ft_printf("%.x|\n", 12);
    ft_printf("%10x|\n", 12);
    ft_printf("%.4x|\n", 12);
    ft_printf("%10.0x|\n", 12);
    ft_printf("%10.12x|\n", 12);


printf("----------------------------\n");

    printf("%0x|\n", -12);
    printf("%.x|\n", -12);
    printf("%10x|\n", -12);
    printf("%.4x|\n", -12);
    printf("%10.0x|\n", -12);
    printf("%10.12x|\n", -12);


    ft_printf("%0x|\n", -12);
    ft_printf("%.x|\n", -12);
    ft_printf("%10x|\n", -12);
    ft_printf("%.4x|\n", -12);
    ft_printf("%10.0x|\n", -12);
    ft_printf("%10.12x|\n", -12);
	    char *str;
    str = NULL;
    printf("abc: %10.0s, 12%2.0d, %10.0x\n", str, -12 ,53543);
    ft_printf("abc: %10.0s, 12%2.0d, %10.0x\n", str, -12, 53543);
printf("----------------------------\n");
printf("%7s%-5s\n", "hello", "world");
ft_printf("%7s%-5s\n", "hello", "world");
printf("----------------------------\n");
printf("|%.03s|\n", NULL);

ft_printf("|%.03s|\n", NULL);
printf("|%3.1s|\n", NULL);
ft_printf("|%3.1s|\n", NULL);
printf("|%9.1s|\n", NULL);
ft_printf("|%9.1s|\n", NULL);
printf("|%.0d|\n", 0);
ft_printf("|%.0d|\n", 0);
printf("|%.d|\n", 0);
ft_printf("|%.d|\n", 0);
printf("|%5.0d|\n", 0);
ft_printf("|%5.0d|\n", 0);
printf("|%5.d|\n", 0);
ft_printf("|%5.d|\n", 0);
printf("|%d|\n", INT_MIN);
ft_printf("|%d|\n", INT_MIN);
printf("|%d|\n", INT_MAX + 1);
ft_printf("|%d|\n", INT_MAX + 1);
printf("|%3.6s|\n", NULL);
ft_printf("|%3.6s|\n", NULL);
printf("|%20.6s|\n", NULL);
ft_printf("|%20.6s|\n", NULL);
printf("|%x|\n", 4294967295u);
ft_printf("|%x|\n", 4294967295u);
printf("Il fait au moins %x\n", -8000);
ft_printf("Il fait au moins %x\n", -8000);
printf("%x\n", INT_MIN);
ft_printf("%x\n", INT_MIN);
printf("%x\n", INT_MAX + 1);
ft_printf("%x\n", INT_MAX + 1);
i = printf("|%%|\n");
printf("%d", i);
i = ft_printf("|%%|\n");
printf("%d", i);
   return 0;
}

/*
    int min_size; par defaut 0 (si vide)
    int precision; can't be negatif
    int is_precision_exist; 0 or 1
    char specifier; s, d or x

*/

/*
    la precision avec %s donne la taille max a afficher de la chaine de caractere (%.s --> %.0s)
    la precision avec %d donne la taille min a afficher poun un nombre, elle ajoute des 0 à gauche (le signe - n'est pas pris en compte)
*/

/*
    %x ne gere pas les signes. (unsigned)
*/
