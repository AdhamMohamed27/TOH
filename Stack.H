//
//  Stack.H
//  Assignment1, Adham Salem<900222465>
//
//  Created by Adham Mohamed  on 12/09/2023.
//

#ifndef Stack_h
#define Stack_h

class Stack{
public:
    
    Stack();
    Stack(int n);
    ~Stack();
    void push(int n);
    int pop();
    void name(char n);
    char Name;
    bool isempty();
    bool isfull();
    void Stack::display();
    
private:
    int * pointer;
    int top,Maxsize;
};

#endif /* Stack_h */

