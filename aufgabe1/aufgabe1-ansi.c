#include <stdio.h>
#include <string.h>

int main(void)
{
    int izahl1 = 123;
    short int izahl2 = 123;
    long int izahl3 = 123;
    unsigned int uzahl1 = 123;
    unsigned short int uzahl2 = 123;
    unsigned long int uzahl3 = 123;
    float fzahl1 = 1.123F;
    double fzahl2 = 1.123;
    long double fzahl3 = 1.123123L;
    char zeichen = 'y';
    signed char schar = -100;
    unsigned char byte = 0xff;
    const char *str = "Hallo";

    printf("%p %lu int izahl1 = %d\n", (void *)&izahl1, (unsigned long)sizeof(izahl1), izahl1);
    printf("%p %lu short int izahl2 = %hd\n", (void *)&izahl2, (unsigned long)sizeof(izahl2), izahl2);
    printf("%p %lu long int izahl3 = %ld\n", (void *)&izahl3, (unsigned long)sizeof(izahl3), izahl3);
    printf("%p %lu unsigned int uzahl1 = %u\n", (void *)&uzahl1, (unsigned long)sizeof(uzahl1), uzahl1);
    printf("%p %lu unsigned short int uzahl2 = %hu\n", (void *)&uzahl2, (unsigned long)sizeof(uzahl2), uzahl2);
    printf("%p %lu unsgined long int uzahl3 = %lu\n", (void *)&uzahl3, (unsigned long)sizeof(uzahl3), uzahl3);
    printf("%p %lu float fzahl1 = %f\n", (void *)&fzahl1, (unsigned long)sizeof(fzahl1), fzahl1);
    printf("%p %lu double fzahl2 = %f\n", (void *)&fzahl2, (unsigned long)sizeof(fzahl2), fzahl2);
    printf("%p %lu long double fzahl3 = %Lf\n", (void *)&fzahl3, (unsigned long)sizeof(fzahl3), fzahl3);
    printf("%p %lu char zeichen = %c\n", (void *)&zeichen, (unsigned long)sizeof(zeichen), zeichen);
    printf("%p %lu signed char schar = %d\n", (void *)&schar, (unsigned long)sizeof(schar), schar);
    printf("%p %lu unsigned char byte = %u\n", (void *)&byte, (unsigned long)sizeof(byte), byte);
    printf("%p %lu const char *str = \"%s\"\n", (void *)str, (unsigned long)sizeof str, str);

    if (sizeof(int) == 4 && sizeof(long int) == 4 && sizeof(char *) == 4)
    {
        printf("ILP32\n");
    }
    else if (sizeof(int) == 4 && sizeof(long int) == 8 && sizeof(char *) == 8)
    {
        printf("LP64\n");
    }
    else if (sizeof(int) == 4 && sizeof(long int) == 4 && /*sizeof(long long int) == 8 &&*/ sizeof(char *) == 8)
    {
        printf("LLP64\n");
    }

    return 0;
}
