#include <iostream>
using namespace std;
bool checkPrime(int n)
{  
    if (n < 2)
    {
        return false;
    }                     
    for(int i=2; i<n; ++i)
    {           
        if(n % i == 0) 
        {
            return false;
        }   
    }                              
    return true;                     
}      
int main(){
    int n;
    cin >> n;
    for(int i=0; i<10000; i++){
        if(checkPrime(i)){
            if(checkPrime(n - i)){
                cout << i << ' ' << n - i;
                return 0;
            }
        }
    }
}