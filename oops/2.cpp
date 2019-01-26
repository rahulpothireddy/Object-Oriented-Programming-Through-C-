
#include <iostream>
#include<iomanip>
#include<cstring>
using namespace std;
void divisors(int n){
cout<<setw(4)<<to_string(n)<<" = ";
int count=0;
int i=1,sum=0;
while(i<n){
if(n%i==0){
sum=sum+i;
if (count!=0){
cout<<" + "<<to_string(i);
             
}
           
else{
cout<<to_string(i);
count=1;
}
}
i++; 
}
cout<<endl;
}
bool isPerfect(int n){
int i=1,sum=0;
while(i<n){
if(n%i==0){
sum=sum+i;
}
i++; 
}
if(sum==n){

divisors(i); 
return true;
}
return false;
}
    

int main()
{
for(int i=1;i<9999;i++){
isPerfect(i);
}
}
