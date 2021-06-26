#pragma warning(disable:4996)
#pragma fenv_access (on)

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <fenv.h>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main(void) {
    double f = 123.45;
    printf("Given the number %.2f or %a in hex,\n", f, f);

    double f3;
    double f2 = modf(f, &f3);
    printf("modf() makes %.0f + %.2f\n", f3, f2);

    int i;
    f2 = frexp(f, &i);
    printf("frexp() makes %f * 2^%d\n", f2, i);

    i = ilogb(f);
    printf("logb()/ilogb() make %f * %d^%d\n", f / scalbn(1.0, i), FLT_RADIX, i);

    // error handling
    feclearexcept(FE_ALL_EXCEPT);
    printf("ilogb(0) = %d\n", ilogb(0));

    if (fetestexcept(FE_INVALID)) {
        puts("    FE_INVALID raised");
    }

    _getch();
    return 0;
}