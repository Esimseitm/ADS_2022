#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool prime_number(int num) {  
    if (num < 2)
    {
        return false;
    }                     
    for(int i=2; i<num; ++i)
    {           
        if(num % i == 0) 
        {
            return false;
        }   
    }                              
    return true;                     
}
int prime_check(int mn) {
    int j = 2;
    set <int> stac;
    while (mn > 1) {
        if (mn % j == 0) {
            mn /= j;
            stac.insert(j);
        }
        else {
            j++;
        }
    }
}


long long sums(vector <long long> arr_sum){
    long long sum=0;
    for(long long i=0;i<arr_sum.size();i++){
        sum+=arr_sum[i];
    }
    return sum;
}
void Merge(vector <vector <long long> > & arr , long long l1,long long r1,long long l2,long long r2){
    long long n1 = r1-l1+1;
    vector <vector <long long> > L;
    for(long long i=0;i<n1;i++){
        L.push_back(arr[i+l1]);
    }
    long long n2 = r2-l2+1;
    vector <vector <long long> > R;
    for(long long i=0;i<n2;i++){
        R.push_back(arr[i+l2]);
    }
    long long i = l1;
    long long i1 = 0;
    long long i2 = 0;
    while (i1<n1 && i2<n2)
    {
        if(sums(L[i1])<sums(R[i2])){
            arr[i] = L[i1];
            i1++;
        }
        else if(sums(L[i1])==sums(R[i2])){
            for(long long x = 0 ; x<L[i1].size();x++){
                if(L[i1][x]>R[i2][x]){
                    arr[i] = L[i1];
                    i1++;
                    break;
                }
                else{
                    arr[i] = R[i2];
                    i2++;
                    break;
                }
            }
        }
        else{
            arr[i] = R[i2];
            i2++;
        }
        i++;
    }
    


    while (i1<n1)
    {
        arr[i] = L[i1];
        i++;
        i1++;
    }
    while (i2<n2)
    {   
        arr[i] = R[i2];
        i2++;
        i++;
    }
}


void MergeSort(vector <vector <long long> > & arr,long long left,long long righ){
    if(left<righ){
        long long mid = (left+righ)/2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,righ);
        Merge(arr,left,mid,mid+1,righ);
    }
}


int main(){
    vector <vector <long long> > arr;
    long long n;cin>>n;
    long long m;cin>>m;
    for(long long i=0;i<n;i+=1){
        vector <long long> sub_arr;
        for(long long j=0;j<m;j++){
            long long z;cin>>z;
            sub_arr.push_back(z);
        }
        arr.push_back(sub_arr);
    }
    MergeSort(arr,0,n-1);
    for(long long i=n-1;i>=0;i-=1){
        for(long long j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}