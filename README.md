# Fun_with_Numbers

## this program gives 4 options

1) find the prime number that is at a location user inputed
    ex- if the user inputs 500, it will return the 500th prime

2) find the sum of all prime numbers before the location of a given prime number
    ex- if the user inputs 500, it will return the summation of all prime numbers before the 500th prime

3) find if number is prime or not
    ex- if the user inputs 100, it returns not prime. if the user inputs 97, it returns prime

4) find all the factors of a number
    ex- if the user inputs 10, it will return 1, 2, 5, 10. if the user inputs 5, it returns 1, 5

you chose one of the options and input your number at the prompt and the program returns the answer
    the first option will print out the current location it is at

- I plan on adding more to this as time goes on. But the original, the one I used for cs50, only had these four options

### to download and compile (linux, debian based): 
	git clone https://github.com/AlphaGainzzz/Fun_with_Numbers.git
	cd Fun_with_Numbers
	clang Fun_with_Numbers.c -o Fun_with_Numbers -lm
	./Fun_with_Numbers
