#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    int A[8]={1,2,90,34,67,45,24,78};
    int n=8;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                int b;
                b=A[j];
                A[j]=A[j+1];
                A[j+1]=b;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        cout<<A[i]<<",";
    }

    return 0;
}