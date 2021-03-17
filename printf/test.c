#include"ft_printf.h"
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
    printf("abc: %.000s, 12%10.3d, %4.6x\n", "yesmine", 1250, 205784);
    ft_printf("abc: %.000s, 12%10.3d, %4.6x\n", "yesmine", 1250, 205784);



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