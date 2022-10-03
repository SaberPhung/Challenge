#include <stdio.h>

void sortArray(int A[], int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j]) {
                // Nếu arr[i] > arr[j] thì hoán đổi giá trị của arr[i] và arr[j]
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }   

}

int solution(int A[], int N){

    sortArray(A, N);
    int i;
    for (i = 0; i < N; i++) 
    {
        //printf("%d ", A[i]);
        if(A[N-1] <1 || A[0] >1)
        {
            return 1;
        }
        
        if(A[i]<=0 && A[i+1]<=0)
        {
            continue;
        }
        
        if(A[i+1]!=A[i]+1 && A[i+1] != A[i])
        {
            return A[i]+1;
        }
    }
    return A[i]+1
}


int main()
{
    int A[]= {-1,2,3,6,7,-2};
    int N = sizeof(A)/ sizeof(A[0]);
    int ret = solution (A,N);
    printf("%d", ret);
    return 0;
}