//
//  main.cpp
//  Assignment1, Adham Salem<900222465>
//
//  Created by Adham Mohamed  on 12/09/2023.
//

#include <iostream>
#include "Stack.H"
using namespace std;
void TOH(int n, Stack & Sour, Stack & Aux, Stack & Des);
int main(){
    int numofdesks;
    cout<<"Please enter the number of desks"<<endl;
    cin>>numofdesks;
    Stack T1(numofdesks);
    Stack T2(numofdesks);
    Stack T3(numofdesks);
    T1.name('S');
    T2.name('A');
    T3.name('D');
    for (int i=0; i<numofdesks; i++){
        T1.push(i+1);
    }
    TOH(numofdesks, T1, T2, T3);
    cout<<"Displaying the destination tower: "<<endl;
    for (int i=0;i<numofdesks;i++){
        int r=T3.pop();
        cout<<r<<endl;
    }
    
    return 0;
}
Stack::Stack(){
    Maxsize=128;
}
Stack::~Stack(){
    delete [] pointer;
}

Stack::Stack(int elem){
    Maxsize=elem;
    pointer= new int[Maxsize];
    top=-1;
}


void Stack::push(int n){
    pointer[++top]=n;
}

int Stack::pop(){
    int r;
    r=pointer[top--];
    return r;
}
void Stack::name(char n){
    Name=n;
}
bool Stack::isempty(){
    if (top==-1)
        return true;
    else
        return false;
}
bool Stack::isfull(){
    if (top==Maxsize)
        return true;
    else
        return false;
}
    void TOH(int n, Stack & Sour, Stack & Aux, Stack & Des)
{
    static int count=0;
    if (n == 1) {
        Des.push(Sour.pop());
        cout << "Move Disk " << n << " from "<< Sour.Name <<" to " << Des.Name << endl;
        count=count+1;
        cout<<"The number of moves is: "<<count<<endl;
        return ;
    }

     TOH(n - 1,  Sour, Des, Aux);
    Des.push(Sour.pop());
    cout << "Move Disk " << n << " from " << Sour.Name << " to " << Des.Name << endl;
    count=count+1;
     TOH(n - 1, Aux, Sour, Des);
}
