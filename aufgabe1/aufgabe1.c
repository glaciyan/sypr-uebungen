#include <stdio.h>
#include <string.h>

int main(void)
{
    {
        int zahl1 = 123;
        printf("%p %zu int zahl1 = %d\n", (void*) &zahl1, sizeof(zahl1), zahl1);

        short int zahl2 = 123;
        printf("%p %zu short int zahl2 = %hd\n", (void*) &zahl2, sizeof(zahl2), zahl2);

        long int zahl3 = 123;
        printf("%p %zu long int zahl3 = %ld\n", (void*) &zahl3, sizeof(zahl3), zahl3);

        long long int zahl4 = 123;
        printf("%p %zu long long int zahl4 = %lld\n", (void*) &zahl4, sizeof(zahl4), zahl4);
    }

    {
        unsigned int zahl1 = 123;
        printf("%p %zu unsigned int zahl1 = %u\n", (void*) &zahl1, sizeof(zahl1), zahl1);

        unsigned short int zahl2 = 123;
        printf("%p %zu unsigned short int zahl2 = %hu\n", (void*) &zahl2, sizeof(zahl2), zahl2);

        unsigned long int zahl3 = 123;
        printf("%p %zu unsgined long int zahl3 = %lu\n", (void*) &zahl3, sizeof(zahl3), zahl3);

        unsigned long long int zahl4 = 123;
        printf("%p %zu unsigned long long int zahl4 = %llu\n", (void*) &zahl4, sizeof(zahl4), zahl4);
    }

    {
        float zahl1 = 1.123F;
        printf("%p %zu float zahl1 = %f\n", (void*) &zahl1, sizeof(zahl1), zahl1);

        double zahl2 = 1.123;
        printf("%p %zu double zahl2 = %f\n", (void*) &zahl2, sizeof(zahl2), zahl2);

        long double zahl3 = 1.123123L;
        printf("%p %zu long double zahl3 = %Lf\n", (void*) &zahl3, sizeof(zahl3), zahl3);
    }

    {
        char zeichen = 'y';
        printf("%p %zu char zeichen = %c\n", (void*) &zeichen, sizeof(zeichen), zeichen);

        signed char zahl = -100;
        printf("%p %zu signed char zahl = %d\n", (void*) &zahl, sizeof(zahl), zahl);

        unsigned char byte = 0xff;
        printf("%p %zu unsigned char byte = %u\n", (void*) &byte, sizeof(byte), byte);
    }

    {
        const char *str = "Hallo";
        printf("%p %zu const char *str = \"%s\"\n", (void*) str, sizeof str, str);
    }

    if (sizeof(int) == 4 && sizeof(long int) == 4 && sizeof(char*) == 4)
    {
        printf("ILP32\n");
    }
    else if (sizeof(int) == 4 && sizeof(long int) == 8 && sizeof(char*) == 8)
    {
        printf("LP64\n");
    }
    else if (sizeof(int) == 4 && sizeof(long int) == 4 && sizeof(long long int) == 8 && sizeof(char*) == 8)
    {
        printf("LLP64\n");
    }
}
