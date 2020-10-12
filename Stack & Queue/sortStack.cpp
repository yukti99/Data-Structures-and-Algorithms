#include <bits/stdc++.h>
using namespace std ;

typedef stack<int> St;
// Sorting a Stack using Recursion


// In ascending Order
void sortedInsertAsc(St &s,int item){
    if (s.empty() || item > s.top())
        s.push(item);
    // item < s.top()
    else{
        int t = s.top();
        s.pop();
        sortedInsertAsc(s,item);
        s.push(t);
    }
}
// In descending Order
void sortedInsertDes(St &s,int item){

    if (s.empty() || item < s.top())
        s.push(item);
    else{
            int t = s.top();
            s.pop();
            sortedInsertDes(s,item);
            s.push(t);
    }
}

void sortStack(St &s){

    if (!s.empty()){
        int temp = s.top();
        s.pop();
        sortStack(s);
        sortedInsertAsc(s,temp);
        //sortedInsertDes(s,temp);
    }
}

// No change done on the actual stack
void show(stack<int> s){
    while(!s.empty()){
        int t = s.top();
        s.pop();
        printf("\t%d\n",t);
    }

}

int main(){

    stack<int> s;
    s.push(31);s.push(3);s.push(15);s.push(-45);s.push(2);s.push(6);s.push(-3);s.push(10);
    printf("Stack initially :\n");
    show(s);
    sortStack(s);
    printf("\nSorted Stack : \n");
    show(s);
    return 0;
}

