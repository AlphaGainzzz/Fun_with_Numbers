//work in progress

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

unsigned long find_prime(int num);
int prime_number(long user);
long find_prime_sum(int findprime);
void factors(int number);
void unload();

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    int prime;
    long primenum;
    int option;
    do
    {
        printf("what would you like to do?\n");
        printf("1) Find prime number in location x\n");
        printf("2) Find sum of all primes before location x (use option 1 to find x)\n");
        printf("3) Find if number is prime\n");
        printf("4) Find factors of number\n");
        printf("\n");
        printf("enter number (Q to quit): ");
        scanf("%i", &option);
    } while (option < 1 || option > 4);

    if (option == 1)
    {
        printf("enter x location: ");
        scanf("%i", &prime);
        unsigned long primeNumber = find_prime(prime);
        printf(primeNumber == 0 ? "number not found\n" : "found: %lu\n", primeNumber);
        unload();
        return 0;
    }

    if (option == 2)
    {
        printf("enter x location: ");
        scanf("%i", &prime);
        long answer = find_prime_sum(find_prime(prime));
        printf(answer == 0 ? "number cannot be found" : "the summation is: %li\n", answer);
        unload();
        return 0;
    }

    if (option == 3)
    {
        printf("enter number: ");
        scanf("%li", &primenum);
        int result = prime_number(primenum);
        printf(result == 1 ? "number is prime\n" : "number is not prime\n");
        unload();
        return 0;
    }

    if (option == 4)
    {
        printf("enter number: ");
        scanf("%i", &prime);
        int result = prime_number((long)prime);
        if (result == 1)
            printf("number is prime: 1, %i", prime);
        else
            factors(prime);
        unload();
        return 0;
    }
}

// option 1, find prime number in location x
node *root_primes;
node *traverse;
node *prime_numbers;
unsigned long find_prime(int num)
{
    int count = 1;
    int current_number = 2;

    root_primes = malloc(sizeof(node));
    traverse = malloc(sizeof(node));
    if (root_primes == NULL || traverse == NULL)
        return 0;

    root_primes->number = 2;
    root_primes->next = NULL;
    while (count <= num)
    {
        current_number++;
        traverse = root_primes;
        while (traverse != NULL)
        {
            int temp = traverse->number;
            if (current_number % temp == 0)
                break;

            else if (traverse->next == NULL && current_number % temp != 0)
            {
                count++;
                if (count == num)
                    return current_number;

                prime_numbers = malloc(sizeof(node));
                if (prime_numbers == NULL)
                    return 0;

                printf("%i\n", count);

                prime_numbers->number = current_number;
                prime_numbers->next = NULL;
                if (root_primes->next == NULL)
                    root_primes->next = prime_numbers;

                else
                {
                    prime_numbers->next = root_primes->next;
                    root_primes->next = prime_numbers;
                }
            }
            traverse = traverse->next;
        }
    }
    return 0;
}

// option 2, find if number is prime
int prime_number(long user)
{
    unsigned int square_root = (int)round(sqrt(user));
    int current_number = 2; // number we are using to find prime

    while (current_number <= square_root)
    {
        if (user % current_number == 0)
            return 0;
        current_number++;
    }
    return 1;
}

// option 3, find sum of all primes below given location of prime
long find_prime_sum(int findprime)
{
    // findprime returns the result of find_prime
    // line 80 for traverse
    traverse = root_primes;
    long sum = 0;
    while (traverse != NULL)
    {
        int temp = traverse->number;
        sum = sum + temp;
        traverse = traverse->next;
        if (traverse == NULL)
            return sum;
    }
    return 0;
}

// option 4, find all the factors of a number
void factors(int number)
{

    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
            printf("%i, ", i);
        if (i == number)
            printf("\n");
    }
}

void unload()
{
    if (root_primes != NULL)
        free(root_primes);
    if (traverse != NULL)
        free(traverse);
    if (prime_numbers != NULL)
        free(prime_numbers);
}
