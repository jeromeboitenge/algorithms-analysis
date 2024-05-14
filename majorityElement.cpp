#include <iostream>
using namespace std;

int main() {
     char c[30]={};
    int n;
  
    int count=0;
     cout<<"enter the brackets please\n";
    cin>>c;
    for( int i=0; i<sizeof(c);i++){
   
    if (c[i]=='('){
        count ++;
    }
    else if(c[i]==')'){
        count --;
    }
     cout<<c[i]<<endl;   
    }
    
    cout<<count;
    if(count==0){
        cout<<"brackets well closed";}
        else{
            cout<<"brackets not competed";
        }
    

    return 0;
}