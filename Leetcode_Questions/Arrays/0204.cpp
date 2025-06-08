// 204. Count Primes

// Given an integer n, return the number of prime numbers that are strictly less than n.

 

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0


class Solution {
public:
    int countPrimes(int n) {
        int primes=0;
        if (n<1){
            return 0;
        }
        bool arr[n];
        for(int i=2;i<n;i++){
            arr[i]= true;
        }
        for(int i=2;i<n;i++){
            if (arr[i]==false){
                continue;
            }
            else{
                primes++;
                for(int k=2*i; k<n ; k+=i){
                    arr[k]=false;
                }
            }
        }
        return primes;
    }
};