#define _WIN32_WINNT 0x0600 // Target Windows Vista or later
#include <windows.h>
#include <stdio.h>
#include "thread.h"
#include "sync_primitives.h"

// Global condition variable and mutex for conditional wait and signal
my_mutex cond_mutex;
CONDITION_VARIABLE cond_var;
int condition_met = 0; // Variable to track if condition is met

// Function to calculate factorial
void *factorial_function(void *arg)
{
    int num = *(int *)arg;
    int factorial = 1;
    for (int i = 1; i <= num; i++)
    {
        factorial *= i;
    }
    printf("Factorial of %d is %d\n", num, factorial);
    return NULL;
}

// Function to print prime numbers up to a given number
void *prime_function(void *arg)
{
    int num = *(int *)arg;
    printf("Prime numbers up to %d: ", num);
    for (int i = 2; i <= num; i++)
    {
        int is_prime = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                is_prime = 0;
                break;
            }
        }
        if (is_prime)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return NULL;
}

// Function demonstrating condition variables
void *waiter_function(void *arg)
{
    my_mutex_lock(&cond_mutex);
    while (!condition_met)
    {
        printf("Thread waiting for condition...\n");
        SleepConditionVariableCS(&cond_var, &cond_mutex, INFINITE);
    }
    printf("Thread resumed after condition met.\n");
    my_mutex_unlock(&cond_mutex);
    return NULL;
}

// Function to set the condition and signal waiting threads
void *signaler_function(void *arg)
{
    Sleep(2000); // Simulate some work
    my_mutex_lock(&cond_mutex);
    condition_met = 1;
    printf("Condition met! Signaling waiting threads.\n");
    WakeAllConditionVariable(&cond_var);
    my_mutex_unlock(&cond_mutex);
    return NULL;
}

int main()
{
    int num1, num2, num3;

    // Prompt user for factorial and prime number calculations
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num1);
    printf("Enter a number to find prime numbers up to that value: ");
    scanf("%d", &num2);

    printf("\nExample: Factorial and Prime Number Calculations\n");
    my_thread thread1, thread2;
    my_thread_create(&thread1, factorial_function, &num1);
    my_thread_create(&thread2, prime_function, &num2);
    my_thread_join(&thread1);
    my_thread_join(&thread2);

    // Condition Variable Example: Waiter and Signaler threads
    printf("\nExample: Condition Variable with Waiter and Signaler\n");
    my_mutex_init(&cond_mutex);
    InitializeConditionVariable(&cond_var);

    my_thread waiter, signaler;
    my_thread_create(&waiter, waiter_function, NULL);
    my_thread_create(&signaler, signaler_function, NULL);

    my_thread_join(&waiter);
    my_thread_join(&signaler);

    printf("\nAll threads completed.\n");
    return 0;
}
