#include <iostream>
#include <string>

using namespace std;
string solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    string s;
    s.resize(N);
    for( int i = 0; i< N; ++i)
    {
        if( i % 2 != 0 )
        {
            s[i] = '-';
        }
        else
        {
            s[i] = '+';
        }
        
    }
    return s;
    
int main()
{
    cout <<solution(5);
    return 0;
}