#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>v1(1e6+1);
vector<int>v2(1e6+1);
bool sum(vector<int>v1,vector<int>v2){
    int sum1=0,sum2=0,n=v1.size();
    for(int i=0;i<n;i++){
        if(v1[i]==1 && v2[i]==1){
            sum1+=1;
            sum2+=1;
        }
        else if(v1[i]==0 && v2[i]==1)
        sum1+=3;
        else if(v1[i]==1 && v2[i]==0)
        sum2+=3;
        else if(v1[i]==0 && v2[i]==0){
            sum1+=2;
            sum2+=2;
        }
    }
    if(sum1>sum2)
    return 1;

    return 0;
}
int main(){
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    // use inputFile instead of cin and outputFile instead of cout
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=rand()%100000+1;
    cout<<"Number of Test Cases : "<<t<<endl;
    int Stay_Calm=0,Testify=0,TitforTat=0;
    while(t--){
        n=rand()%1000000+1;
        v1[0]=v2[0]=1;

        int last=1;
        for(int i=1;i<n;i++){
            v1[i]=last;
            int p=rand()%2;
            v2[i]=p;
            last=p;
        }
        if(sum(v1,v2))
        TitforTat++;

        for(int i=1;i<n;i++){
            v1[i]=1;
            int p=rand()%2;
            v2[i]=p;
        }
        if(sum(v1,v2))
        Stay_Calm++;

        for(int i=1;i<n;i++){
            v1[i]=0;
            int p=rand()%2;
            v2[i]=p;
        }
        if(sum(v1,v2))
        Testify++;
    }
    cout<<"Tit for Tat "<<TitforTat<<endl;
    cout<<"Not Stay_Calm "<<Testify<<endl;
    cout<<"Stay_Calm "<<Stay_Calm<<endl;
    return 0;
}