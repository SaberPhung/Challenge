#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A){
    if(A.size() == 1){
        return 1;
    }
    int start = 0, finish = 0, res = 0;
    for(int i = 0; i < A.size(); ++i){
        // find the different in height and assign to finish
        if(i + 1 < A.size() && A[i] != A[i + 1])
        {
            finish = i;
            if(start > 0)
            {
                if((A[start] > A[start - 1] && A[finish] > A[finish + 1])
                   || (A[start] < A[start - 1] && A[finish] < A[finish + 1]))
                {
                    res++;
                }
            }
            else{
                res++;
            }
            start = i + 1;
        }
    }
    if(A.size() - start == 1 || A[A.size() - 2] == A[A.size() - 1]){
        if((start > 0 && A[start] != A[start - 1]) || start == 0){
            res++;
        }
    }
    return res;
}

int main(){
    vector<int> A{2, 2, 3, 4, 3, 3, 2, 2, 1, 1, 2, 5};
    cout << solution(A);
    return 0;
}