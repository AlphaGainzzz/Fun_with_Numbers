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
    char option;
    do
    {
        printf("\tFUN WITH NUMBERS\n\n");
        printf("1) Find prime number in location x.\n");
        printf("2) Find sum of all primes before location x.\n");
        printf("3) Find if number is prime.\n");
        printf("4) Find factors of number.\n");
        printf("5) Prime factorization of number.\n");
        printf("PRESS 'q' or 'Q' to exit.\n");
        printf("\n");
        printf("Choose one of the options above: ");
        scanf("%c", &option);
        if(option=='Q' || option=='q')
        {
            printf("Exited.\n");
            return 1;
        }
    } while (option < '1' || option > '5');

    if (option == '1')
    {
        printf("Enter x location: ");
        scanf("%i", &prime);
        unsigned long primeNumber = find_prime(prime);
        if(primeNumber == 0)
            if(prime==1)
                printf("Found: 2\n");
            else
                printf("Number not found.\n");
        else
            printf("Found: %lu\n", primeNumber);
        unload();
        return 0;
    }

    if (option == '2')
    {
        printf("Enter x location: ");
        scanf("%i", &prime);
        long answer = find_prime_sum(find_prime(prime));
        printf(answer == 0 ? "Number couldn't be found." : "The summation is: %li\n", answer);
        unload();
        return 0;
    }

    if (option == '3')
    {
        printf("Enter number: ");
        scanf("%li", &primenum);
        int result = prime_number(primenum);
        if(result)
            printf("Number %li is prime.\n", primenum);
        else
            printf("Number %li is not prime.\n", primenum);
        unload();
        return 0;
    }

    if (option == '4')
    {
        printf("Enter number: ");
        scanf("%i", &prime);
        int result = prime_number((long)prime);
        if (result == 1)
            printf("Number %i is prime.\n", prime);
        else
            factors(prime);
        unload();
        return 0;
    }

    if( option == '5')
    {
        printf("Enter number: ");
        scanf("%li", &primenum);
        if(prime_number(primenum))
        {
            printf("The number %li is prime.\n", primenum);
        }
        else
        {
            for(int i=2; i<=primenum;){
            if(primenum%i==0){
                printf("%d ", i);
                primenum/=i;
                i=2;
            }
            else
                i++;
            }
        }
        printf("\n");

    }
}

// option 1: find prime number in location x
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


// option 2: find sum of all primes below given location of prime
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

// option 3: find if number is prime
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

// option 4: find all the factors of a number
void factors(int number)
{

    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            printf("%i", i);
            if (i != number)
                printf(", ");
        }
        if (i == number)
            printf(".\n");
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
