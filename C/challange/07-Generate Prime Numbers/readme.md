# 07-GeneratePrime Numbers

## Requirements

In this challenge, you are going to create a program that will find all the prime numbers from 3-100. There will be no input to the program. The output will be each prime number separated by a space on a single line.

You will need to create an array that will store each prime number as it is generated. You can hard-code the first two prime numbers (2 and 3) in the primes array.

You should utilize loops to only find prime numbers up to 100 and a loop to print out the primes array.

## Hints

The criteria that can be used to identify a prime number is that a number is considered prime if it is not evenly divisible by any other previous prime numbers.

Can use the following as an exit condition in the innermost loop

```c
p / primes[i] >= primes[i]
```

a test to ensure that the value of p does not exceed the square root of primes[i]

Your program can be more efficient by skipping any checks for even numbers (as they cannot be prime).

## Jason's Codes

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int p;
    int i;

    int primes[50] = {0};
    int primeIndex = 2;

    bool isPrime;

    // hardcode prime numbers
    primes[0] = 2;
    primes[1] = 3;

    for(p = 5; p <= 100; p = p + 2)
    {
        isPrime = true;

        for (i = 1; isPrime && p / primes[i] >= primes[i]; ++i)
            if (p % primes[i] == 0)
                isPrime = false;

        if (isPrime == true)
        {
            primes[primeIndex] = p;
            ++primeIndex;
        }
    }

    for ( i = 0;  i < primeIndex;  ++i )
         printf ("%i  ", primes[i]);

    printf("\n");
    return 0;
}
```
