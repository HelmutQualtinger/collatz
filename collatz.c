#include <stdio.h>
#include <time.h>
struct collatz_struct
{
    int number;
    int cycle_length;
    int max;
} collatz(int number)
{

    int max = number;
    int init_number = number;
    int cycle_length = 0;
    struct collatz_struct result;
    result.number = number;
    while (number > 1)
    {
        if ((number & 1) == 0) // even
        {
            number = number >> 1;
        }
        else // odd
        {
            number = (number << 1) + number + 1;
        }
        cycle_length += 1;
        if (number > max)
        {
            max = number;
        }
    }

    result.cycle_length = cycle_length;
    result.max = max;

    return result;
}

#define MAX 10000000
int numbers[MAX];
int maxima[MAX];
int cycles[MAX];

int main()
{

    int i;
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();

    // ... existing code ...

    for (i = 3; i < MAX; i += 2)
    {
        struct collatz_struct r = collatz(i);
        numbers[i] = r.number;
        cycles[i] = r.cycle_length;
        maxima[i] = r.max;
        if (i % 10000000 == 0)
        {
            printf("%d\n", i);
        }
        //  printf("%d %d %d\n", numbers[i], cycles[i], maxima[i]);
    }
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}