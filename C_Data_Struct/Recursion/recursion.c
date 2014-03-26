#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUMBER_TEST      100000
#define NUMBER_LOOP         500

//function(x):
//1 + 1/2 + 1/3 + 1/4 + ... + 1/n
double commonLoop(int x)
{
    int i;
    double res = 0;

    if (x <= 0) {
        return -1;
    }

    for (i = 1; i <= x; i++) {
        res += 1 / (double)i;
    }

    return res;
}

//stack frame limit count about 330000
double recursion(int x)
{
    if (x <= 0) {
        return -1;
    } else if (x == 1) {
        return 1;
    } else {
        return 1 / (double)x + recursion(x - 1);
    }
}

//tail recursion reduces stack frame space cost,
//but maybe less efficient in time
double tailRecursion(int x, double a)
{
    if (x <= 0) {
        return -1;
    } else if (x == 1) {
        return (a + 1);
    } else {
        return tailRecursion(x - 1, a + 1 / (double)x);
    }
}

int main()
{
    int i = NUMBER_LOOP;
    double result;
    double start;
    double a = 0;

    start = clock();
    while (i > 0) {
        result = commonLoop(NUMBER_TEST);
        i--;
    }
    printf("CommonLoop:\tresult:%f, time_cost:%f.\n", result, clock() - start);

    start = clock();
    i = NUMBER_LOOP;
    while (i > 0) {
        result = recursion(NUMBER_TEST);
        i--;
    }
    printf("Recursion:\tresult:%f, time_cost:%f.\n", result, clock() - start);

    start = clock();
    i = NUMBER_LOOP;
    while (i > 0) {
        result = tailRecursion(NUMBER_TEST, a);
        i--;
    }
    printf("TailRecursion:\tresult:%f, time_cost:%f.\n", result, clock() - start);

    return 0;
}
