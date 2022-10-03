#include <stdio.h>
/// @brief  tìm số nguyên dương nhỏ nhất không xuất hiện trong một mảng
// bài này bổ sung thêm điều kiện nếu mảng bằng 0
/// @param A 
/// @param N 
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

    
    int smallest = 1;
    if(N==0)
    {
        return smallest;
    }
    sortArray(A, N);
    if(A[N-1]<1 || A[0]>1)
    {
        return 1;
    }
    
    for (int i = 0; i< N; ++i) 
    {   
           if(A[i] == smallest)
           {
               smallest++;
           }
        
    }
    return smallest;
    
}


int main()
{
    int A[]= {-1,2,4,6,7,-2};
    int N = sizeof(A)/ sizeof(A[0]);
    int ret = solution (A,N);
    printf("%d", ret);
    return 0;
}