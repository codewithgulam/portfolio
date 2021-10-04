
#include <iostream>

using namespace std;


class node
{
  public:

  char data;
  node *next;
};



class stack1
{
  public:

  node *top;

  stack1()
  {
    top=NULL;
  }

  void push(char data);
  char pop();
  char gettop();
  int empty1();

};


int stack1::empty1()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}


char stack1::gettop()
{
    if(top==NULL)
        return -1;
    else
        return top->data;
}



void stack1::push(char d)
{
    node *temp=new node;

    if(temp==NULL)
    {
        cout<<"\nStack is overflow";
    }
    else
    {
        temp->data=d;
        temp->next=top;
        top=temp;
    }
}


char stack1::pop()
{
    if(top==NULL)
	{
		return -1;
	}
	else
	{
		node *temp=new node;
		char c;
		c=top->data;
		temp=top;
		top=top->next;
		temp->next=NULL;
		return c;
	}
}




class conversion
{

  public:

  int infix_to_postfix(char infix[],char postfix[]);
  int infix_to_prefix(char infix[],char prefix[]);
  int precedence(char ch);
  int evaluate_prefix(char prefix[]);
  int evaluate_postfix(char postfix[]);
  int evaluate(char x,int op1,int op2);
  int validations(char exp[]);

};



int conversion::validations(char exp[])
{
    int i,opening=0,closing=0,operands=0,operators=0;

    for(i=0;exp[i]!='\0';i++)
    {

        if(exp[i]=='(')
            opening++;
        else
            if(exp[i]==')')
            closing++;

        else
          if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z') || (exp[i]>='0' && exp[i]<='9'))
            operands++;

        else
            operators++;

    }

    if(opening!=closing || operators>=operands || operators==0)
        return -1;
    else
        return 1;
}


int conversion::precedence(char c)
{

   if(c=='*' || c=='/' || c=='%')
    return 2;

    else
     if(c=='+' || c=='-')
    return 1;

    else
        return -1;

}


int conversion::infix_to_postfix(char infix[],char postfix[])
{
    stack1 s;

    char ch,sc;

    int i,j=0;

    for(i=0;infix[i]!='\0';i++)
    {
        ch=infix[i];

        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            postfix[j]=ch;
            j++;
        }

        else
            if(ch=='(')
        {
            s.push(ch);
        }

        else
            if(ch==')')
        {
            while(s.gettop()!='(' && !s.empty1())
            {
                sc=s.pop();
                postfix[j]=sc;
                j++;
            }

            if(s.gettop()=='(')
                sc=s.pop();

        }

        else
        {
            while(precedence(ch)<=precedence(s.gettop()) && !s.empty1())
            {
                sc=s.pop();
                postfix[j]=sc;
                j++;
            }
            s.push(ch);
        }
    }


    while(!s.empty1())
    {
        sc=s.pop();
        postfix[j]=sc;
        j++;
    }

    postfix[j]='\0';

    return 0;

}




int conversion::infix_to_prefix(char infix[],char prefix[])
{
     int i,length=0,j,re;

     char infix1[100],temp[100];

     while(infix[length]!='\0')
        length++;

     for(i=length-1,j=0;i>=0;i--,j++)
     {
        if(infix[i]=='(')
                infix1[j]='(';

        else
            if(infix[i]==')')
               infix1[j]=')';

        else
            infix1[j]=infix[i];
     }


     infix1[j]='\0';

     re=infix_to_postfix(infix1,temp);

     if(re==-1)
        return -1;

     else
     {
         length=0;

         while(temp[length]!='\0')
            length++;

         for(i=length-1,j=0;i>=0;i--,j++)
         {
             prefix[j]=temp[i];
         }

         prefix[j]='\0';
         return 1;

     }

}




int conversion::evaluate_prefix(char prefix[])
{
    stack1 s;
    char x;
    int op1,op2,value,i,len=0;

    while(prefix[len]!='\0')           /*calculates length of expression*/
        len++;

    for(i=len-1;i>=0;i--)
    {
        x=prefix[i];

        if(isalpha(x))                               /*checks if x is character*/
        {
            cout<<"\nEnter value of "<<x<<" ";
            cin>>value;
            s.push(value);

        }

        else
        {
            op1=s.pop();
            op2=s.pop();
            value=evaluate(x,op1,op2);
            s.push(value);
        }
    }

    value=s.pop();

    return value;
}




int conversion::evaluate_postfix(char postfix[])
{
    stack1 s;
    char x;
    int op1,op2,value,i;


    for(i=0;i<postfix[i]!='\0';i++)
    {
        x=postfix[i];

        if(isalpha(x))                               /*checks if x is character*/
        {
            cout<<"\nEnter value of "<<x<<" ";
            cin>>value;
            s.push(value);

        }

        else
        {
            op1=s.pop();
            op2=s.pop();
            value=evaluate(x,op1,op2);
            s.push(value);
        }
    }

    value=s.pop();

    return value;
}


int conversion::evaluate(char x,int op1,int op2)
{

    if(x=='+')
        return (op1+op2);
    else
     if(x=='-')
       return (op2-op1);
    else
     if(x=='*')
       return (op1*op2);
    else
     if(x=='/')
       return (op1/op2);
    else
     if(x=='%')
       return (op1%op2);
    else
     return -1;
}




int main()
{
   conversion ex;
   int ch,result,f;
   char j[100],infix[100],prefix[100],postfix[100];



  do
  {
    cout<<"\n1.Infix to prefix conversion";
    cout<<"\n2.Infix to postfix conversion";
    cout<<"\n3.Prefix evaluation";
    cout<<"\n4.Postfix evaluation";
    cout<<"\nEnter choice:";
    cin>>ch;

    switch(ch)
    {

     case 1:

     cout<<"\nEnter infix expression:";
     cin>>infix;

     if(ex.validations(infix)==-1)
        cout<<"\nExpression is  invalid!!!";
     else

        {
            result=ex.infix_to_prefix(infix,prefix);
            cout<<"\nPrefix expression is:"<<prefix;
        }

     break;


     case 2:

     cout<<"\nEnter infix expression:";
     cin>>infix;

     if(ex.validations(infix)==-1)
        cout<<"\nExpression is  invalid!!!";
     else

         {
             result=ex.infix_to_postfix(infix,postfix);
            cout<<"\nPostfix expression is:"<<postfix;
         }

     break;


     case 3:

     cout<<"\nEnter prefix expression:";
     cin>>j;

     if(ex.validations(j)==-1)
        cout<<"\nExpression is  invalid!!!";
     else
     {
        result=ex.evaluate_prefix(j);
        cout<<"\nValue is:"<<result;
     }

     break;



     case 4:

     cout<<"\nEnter postfix expression:";
     cin>>j;

     if(ex.validations(j)==-1)
        cout<<"\nExpression is  invalid!!!";
     else
     {
        result=ex.evaluate_postfix(j);
        cout<<"\nValue is:"<<result;
     }

     break;


    }

    cout<<"\nDo u want to choose another option?(0/1):";
    cin>>f;

  }

  while(f==1);

  return 0;

}



