#include <bits/stdc++.h>

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
    return stac.size();
}
struct GpA{
    string name;
    string soname;
    int cnt;
    double TotalGpa;

    GpA(string name,string soname,double cnt){
        this->name = name;
        this->soname = soname;
        this->cnt = cnt;
        this->TotalGpa=0;
        double cntFor=0;
        for(int i=0;i<cnt;i++){
            string txt;cin>>txt;
            int num;cin>>num;
            cntFor+=num;
            this->TotalGpa+=(getGpaA(txt)*num);
        }
        this->TotalGpa/=cntFor;
    }
    double getGpaA(string txt){
        if(txt=="A+"){
            return 4.00;
        }
        if(txt=="A"){
            return 3.75;
        }
        if(txt=="B+"){
            return 3.50;
        }
        if(txt=="B"){
            return 3.00;
        }
        if(txt=="C+"){
            return 2.50;
        }
        if(txt=="C"){
            return 2.00;
        }
        if(txt=="D+"){
            return 1.50;
        }
        if(txt=="D"){
            return 1.00;
        }
        if(txt=="F"){
            return 0.0;
        }
    }    
};

void Merge(vector <GpA> & arr,int l1,int r1,int l2,int r2){
    int n1 = r1-l1+1;
    vector <GpA> L;
    for(int i=0;i<n1;i++){
        L.push_back(arr[i+l1]);
    }
    int n2 = r2-l2+1;
    vector <GpA> R;
    for(int i=0;i<n2;i++){
        R.push_back(arr[i+l2]);
    }
    
    int i = l1;
    int i1 = 0;
    int i2 = 0;
    while (i1<n1 && i2<n2)
    {
        if(L[i1].TotalGpa<R[i2].TotalGpa){
            arr[i] = L[i1];
            i1++;
        }
        else if(L[i1].TotalGpa==R[i2].TotalGpa){
            if(L[i1].soname<R[i2].soname){
                arr[i] = L[i1];
                i1++;
            }
            else if(L[i1].soname==R[i2].soname){
                if(L[i1].name<R[i2].name){
                    arr[i] = L[i1];
                    i1++;
                }
                else{   
                    arr[i] = R[i2];
                    i2++;
                }
            }
            else{
                arr[i] = R[i2];
                i2++;
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
        arr[i]=L[i1];
        i++;
        i1++;
    }
    while (i2<n2)
    {
        arr[i]=R[i2];
        i++;
        i2++;
    }
}



void MergeSort(vector <GpA> & arr,int left,int righ){
    if(left<righ){
        int mid = (left+righ)/2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,righ);
        Merge(arr,left,mid,mid+1,righ);
    }
}

int main(){
    int n;cin>>n;
    int fdsfsdf;
    int sdfsdfsd;
    vector <GpA> arr;
    for(int i=0;i<n;i++){
        string soname;cin>>soname;
        string name;cin>>name;
        int cnt;cin>>cnt;
        GpA newMan(name,soname,cnt);
        arr.push_back(newMan);
    }
    MergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i].soname<<" "<<arr[i].name<<" ";
        cout << fixed << setprecision(3) << arr[i].TotalGpa << "\n";
    }
}