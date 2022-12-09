#include <iostream>
#include <string>
using namespace std;

struct node{

    char info;
    node *next;
};

class Stack{

private:
    node *Top;
public:
    Stack(){Top=NULL;}

    bool isEmpty(){

        if(Top==NULL)
            return true;
        else
            return false;
    }

    void push(char item){
    
        node *p= new node;
        p->info=item;
        p->next=Top;
        Top=p;
    }

    char pop(){
    
        if(isEmpty()){
            cout<< "Underflow\n";
            return 0;
    }
        else{
       
            node *t=Top;
            char x =t->info;
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

    int pre(char op){
    
        if(op == '^')
            return 1;
        else if(op == '*' || op == '/'|| op == '%')
            return 2;
    
    return 3;
    }

    bool prcd(char Top, char symb){
   
        if(Top=='(' || symb=='(')
            return false;
        else if (symb == ')')
            return true;
        if (Top=='^' && symb=='^')
            return false;
        if(pre(Top) <= pre(symb))
            return true;
        
    return false;
    }

    string InfixToPostfix(string infix){
    
        string postfix;
        int i =0;
        char topsym;
        
        while(i<infix.length()){ //or while( infix!= '\0')
            char symb= infix[i];
            
            if((symb >='a' && symb <= 'z')|| (symb >= 'A' && symb <= 'Z'))
                postfix.insert(postfix.end(),symb);
            else{
                
                while(!isEmpty()&&prcd(peak(),symb)){
                    topsym = pop();
                    postfix.insert(postfix.end(),topsym);
                }
                if(isEmpty()||symb != ')')
                    push(symb);
                else
                    topsym=pop();
            }
            i++;
        }
    
        while(!isEmpty()){
    
            topsym =pop();
            postfix.insert(postfix.end(),topsym);
        }
        return postfix;
    }
};


int main()
{
    Stack s;
    string inf;
    
    cout <<"Enter the INFIX expression to convert into POSTFIX:\n";
    cin >> inf;
    cout<<"\n---------------------------------------------------------\n";
    cout<< "\nAfter converted to POSTFIX:\n";
    cout<<s.InfixToPostfix(inf);
    cout<<"\n\n\n";
    
return 0;
}
