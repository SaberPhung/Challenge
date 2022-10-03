#include <iostream>
#include <climits>
#include <string>
using namespace std;

int solution(int N){
    string s = to_string(N);
    // Max is the smallest number of type int
    int Max = INT_MIN;
    for(int i = 0; i < s.length(); ++i){
        // search the number 5 in string
        if(s[i] == '5'){ //5859
            // create a sub string to store the rest of the string after remove digit 5
            string s2 = s.substr(0, i) + s.substr(i + 1);
            // revert string to integer to compare with Max
            int val = stoi(s2);
            Max = max(Max, val);
        }
    }
    return Max;
}

int main(){
    cout << solution(5859);
    return 0;
}
// ANOTHER WAY TO SOLVE THIS PROBLEM THAT YOU MAY SEE IF N > 0 (5759) we jus need to run for loop with i = 0 and
// remove the first number 5 in string. And with N<0 run for loop with i = s.length() and remove the first number 5 in string
// BUT THIS WAY take longer line of code than using the first one but it will run shorter cycle of loop
// #include <iostream>
// #include <climits>
// #include <string>
// using namespace std;

// int solution(int N){
//     int val;
//     string s = to_string(N);
//     if (N>0)
//     {
//         for(int i = 0; i < s.length(); ++i){
//         // search the number 5 in string
//             if(s[i] == '5'){
//             // create a sub string to store the rest of the string after remove digit 5
//                 string s2 = s.substr(0, i) + s.substr(i + 1);
//                 val = stoi(s2);
//                 break;
//             }
//         }
//     }
//     else
//     {
//         for(int i = s.length(); i >0; --i){     
//         // search the number 5 in string
//         if(s[i] == '5'){
//             // create a sub string to store the rest of the string after remove digit 5
//             string s2 = s.substr(0, i) + s.substr(i + 1);
//             val = stoi(s2);
//             break;
//             }
//         }
//     }
//     return val;
// }

// int main(){
//     cout << solution(-5000);
//     return 0;
// }