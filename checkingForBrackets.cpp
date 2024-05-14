#include <iostream>
using namespace std;

int main() {
   int arr[13]={10,20,30,1,2,3,4,6,7,8,8,9,0};
   int element;
   cout<<"please enter element to search"<<endl;
   cin>>element;
   for(int i=0;i<sizeof(arr);i++){
       if(element==arr[i]){
       
    cout<<"the number is on index  "<<i<<endl;
    break;
       }
       
   }

    return 0;
}