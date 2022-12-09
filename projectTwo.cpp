#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct node{

    int info;
    node *next;
};


class Stack{

private:
    node *Top;
public:
    Stack()
    {Top=NULL;}

    bool isEmpty(){

        if(Top==NULL)
            return true;
        else
            return false;
    }

    void push(int item){

        node *p= new node;
        p->info=item;
        p->next=Top;
        Top=p;
    }

    int pop(){

        if(isEmpty()){
            cout<< "Underflow\n";
            return 0;
    }

        else{
            node *t=Top;
            int x=t->info;
            Top=Top->next;
            delete t;
            return x;
        }
    }

    int peak(){

        if(isEmpty()){
            cout<< "The stack is empty\n";
            return 0;
        }
        else
            return Top->info;
    }


    int evalPostfix(string e){

        int i=0;
        while(e[i] != '\0'){
            char symb = e[i];
            if(symb >= '0' && symb <= '9'){
                push(symb - '0');
            }

        else{

        int opnd2 = pop();
        int opnd1 = pop();

            if (symb =='+'){
                push(opnd1 + opnd2);
            }
            else if(symb =='-'){
                push(opnd1 - opnd2);
            }
            else if (symb =='*'){
                push(opnd1 * opnd2);
            }
            else if (symb =='/'){
                push(opnd1 / opnd2);
            }
            else if (symb =='%'){
                push(opnd1 % opnd2);
            }
            else if (symb =='^'){
                push(pow(opnd1 , opnd2));
            }
        }
            i++;
        }
        return (pop());
    }
};


int main()
{
    Stack s;
    string exp;

    cout <<"Enter the POSTFIX expression:\n";
    cin>>exp;
    cout<<"\n-------------------------------------\n";
    cout<< "\nEvaluating a POSTFIX expression is: \n";
    cout <<s.evalPostfix(exp);
    cout<<"\n\n\n";

    return 0;
}
