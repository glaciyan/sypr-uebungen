#include <stdio.h>

int main(void)
{
    {
        int zahl1 = 123;
        printf("int: %d\n", zahl1);

        short int zahl2 = 123;
        printf("short int: %hd\n", zahl2);

        long int zahl3 = 123;
        printf("long int: %ld\n", zahl3);

        long long int zahl4 = 123;
        printf("long long int: %lld\n", zahl4);
    }

    {
        unsigned int zahl1 = 123;
        printf("unsigned int: %u\n", zahl1);

        unsigned short int zahl2 = 123;
        printf("short int: %hu\n", zahl2);

        unsigned long int zahl3 = 123;
        printf("long int: %lu\n", zahl3);

        unsigned long long int zahl4 = 123;
        printf("long long int: %llu\n", zahl4);
    }

    {
        float zahl1 = 1.123F;
        printf("float: %f\n", zahl1);

        double zahl2 = 1.123;
        printf("double: %f\n", zahl2);

        long double zahl3 = 1.123123L;
        printf("long double: %Lf\n", zahl3);
    }

    {
        char zeichen = 'y';
        printf("char: %c\n", zeichen);

        signed char zahl = -100;
        printf("signed char: %d\n", zahl);

        unsigned char byte = 0xff;
        printf("unsigned char: %u\n", byte);
    }

    {
        const char *str = "Hallo";
        printf("string: %s\n", str);
    }
}
