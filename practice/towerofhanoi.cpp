#include<iostream>
using namespace std;

void towerofhanoi(int n, char s, char a, char d){
    if (n==0){
        return;
    }

    towerofhanoi(n-1, s,d,a);
    cout<< "Moved disk " << n << " from "<< s << " to "<<d<<endl;

    towerofhanoi(n-1, a,s,d);
}

int main(){
    towerofhanoi(3,'A','B','C');
}