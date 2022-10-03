#include <stdio.h>
#include <inttypes.h>
#include <limits.h>
/*
* -- Protocol Problems -- 
*
* Part 1
*
* Consider a communication protocol that transmits a series of integers. According to the specifications, 
* the protocol transmits a preample of 25 numbers and then each subsequent number must be the sum of any 
* two of the 25 immediately previous numbers. These two numbers are always different, and there might be 
* more than one such pair.
*
* For example, consider a preamble that consists of the numbers 1 through 25 in a random order. To be 
* valid, the next number must be the sum of two of those numbers:
*
*     26 would be a valid next number, as it could be 1 plus 25 (or many other pairs, like 2 and 24).
*     49 would be a valid next number, as it is the sum of 24 and 25.
*     100 would not be valid, as no two of the previous 25 numbers sum to 100.
*     50 would also not be valid, as even although 25 appears in the previous 25 numbers, the two numbers 
*     in the pair must be different.
*
* Suppose the 26th number is 45, and the first number (no longer an option, as it is more than 25 numbers 
* ago) was 20. Now, for the next number to be valid, there needs to be some pair of numbers among 1-19, 
* 21-25, or 45 that add up to it:
*
*     26 would still be a valid next number, as 1 and 25 are still within the previous 25 numbers.
*     65 would not be valid, as no two of the available numbers sum to it.
*     64 and 66 would both be valid, as they are the result of 19+45 and 21+45 respectively.
*
* The data in your problem input has been corrupted. Do the following:
* 1) Print the first 25 numbers in the input (i.e., the preamble)
* 2) Print the first number that follows the preamble in the input 
26th

* 3) Print the number pairs in the preamble
acctual pairs output ( 1 19).....

* 4) Find the first invalid number in the input

* ---
*
* Part 2
*
* In order to find the source of the corruption, it's necessary to find a contiguous set of at least two 
* numbers in the problem input which sum to the first invalid number from Part 1.
*
* What is the sum of the smallest and largest number in this contiguous range?



/* 
print array
*/
void output(uint64_t input [], int N )
{
    for(int i = 0; i < N; i++)
    {
        printf("%lu ", input[i]);
    }
}
/* 
print array position 26
*/
void output_26(uint64_t input [], int N )
{
    for(int i = 25; i < N; i++)
    {
        printf("%lu ", input[i]);
    }
}
/* 
This function will store all sum value of previous 25 numbers
*/

void storeSum( uint64_t input[], int N, uint64_t b[], int *k)
{
    uint64_t sum = 0;
    *k = 0;
    for(int i = N-25; i < N-1; i++)
    {
        for(int j = i+1 ; j < N; j++)
        {
            if(input[i] != input[j])
            {
                sum = input[i] + input [j];
                b[(*k)++] =  sum;
            }
           
        }
    }
}
/* 
return the first invalid number in the input if there is, or 0 if not
*/
long long int checkPreamble_2(uint64_t input[], int N, uint64_t b[], int *k, int *pos)
{
    storeSum(input, N, b, k);
   
    for(int i = N ; i < N+25 ; i++ ) 
    {
        int check = 0;
        for(int j = 0; j < *k ; j++) 
        {
            if(input[i] == b[j]) // if elements in array input exist in the array of sum pairs, break update i+1
            {
                check = 1;
                break;
            }
            /* Lam cach nay thi code hoi yeu nha */
            /* else // if not equal, compare with sum array contiuous 
            {
                if(j == *k-1) // reach the end of sum array
                {
                    *pos = i;
                    return input[i]; // return the number not exist in sum array
                }
            } */
        }
        if(check == 0)
        {
            *pos = i;
            return input[i];
        }
    }
    return 0;
}
    
 /* 
print actual pair of 25 number
*/
void acctualPair(uint64_t input[], int N)
{
    //  a b c d 
    //  ab ac ad bc bd
    int count = 0;
    uint64_t sum = 0;
    for(int i = N-25; i < N -1 ; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if(input[i] != input[j])
            {
                count++;
                sum = input[i] + input[j];
                printf("\npair %d: input: %lu and %lu and sum is %lu", count, input[i], input[j], sum);
            }
            
        }
    }
}
/* 
find Min
*/
long long int findMin(long long int A, long long int B)
{
    return A < B ? A : B;
}
/* 
find max
*/
long long int findMax(long int A, long int B)
{
    return A > B ? A : B;
}
/* 
find the smallest and largest number of contiguous range
*/
void SmallestAndLargestOfCorruption (uint64_t input[], int pos, long long int invalidNum, long long int *min, long long int *max)
{
     *min = invalidNum;
     *max = LLONG_MIN;
    for(int i = 0; i < pos-1; i++)
    {
        for( int j = i+1; j < pos; j++)
        {
            if(input [i] + input [j] == invalidNum )
            {
            //   printf("%d + %d = %d", input[i], input[j], invalidNum);
               long long int retMin  = findMin(input[i], input[j]);
               long long int retMax = findMax(input[i], input[j]);
               if(*min > retMin)
               {
                   *min = retMin; 
               }
               if(*max < retMax)
               {
                   *max = retMax; 
               }
            }
        }
    }
}

int main()
{
    FILE *fd = fopen("input.txt", "r");
    uint64_t input[1000];
    for(int i = 0; i < 1000; i++) {
        fscanf(fd, "%lu", &input[i]);
    }
    uint64_t b[1000];
    int k;
    
    // A out put of first 25 numbers
    output(input, 25);
    
    // B out put of number 26
    // output_26(input, 26);
    printf("\n%ld",input[25]);
    // acctual pair combine from first 25 numbers
    acctualPair(input, 25);
    
   
    for(int i = 0; i < 1000 ; i+=25)
    {
        int pos;
        long long int min, max;
        long long int invalidNum = (checkPreamble_2(input, i+25, b, &k, &pos));
        // if exist invalidNum find the smallest and largest number of contiguous range
        if(invalidNum)
        {
            printf("\nFirst invalid Number in range from %d to %d is: %lld", i+25, i+50, invalidNum);
            printf("\nFirst invalid Number in range from %d to %d at position: %d ",i+25, i+50, pos+1);
            SmallestAndLargestOfCorruption (input, pos, invalidNum, &min, &max);
            printf("\nThe smallest number in range from %d to %d in contiguous range %lld",i+25,i+50, min);
            printf("\nThe largest number in range from %d to %d contiguous range %lld",i+25,i+50, max);
            
        }
    }
    // Write your implementation here
    
    return 0;
}
