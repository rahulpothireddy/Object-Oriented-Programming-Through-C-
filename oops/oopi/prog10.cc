//satyanarayana kotha
//z1805662
//Assignment10
//nov 15th

#include "prog10.h"
void process_token ( const string& token, stack < double >& d )
{
    
    bool f = false;
    char a;
    unsigned int i=0;
    while(i < token.size())
        
    {
        a = token[i];
        f = floatPoint(a, token, i);
        
        if(unarySign(a, token, i))
        {
            f = floatPoint(token[i+1], token, i+1);   //check for predicate unarysign()
            d.push(getNumber(a,token, i,f));
        }
        else if(isdigit(a))
        {
            d.push(getNumber(a,token,i,f));  //checking if digit
        }
        
        else if(isValidOperator(a))   //checking whether a valid operator
        {
            double result = operation(a, popStack(d), popStack(d));
            d.push(result);
        }
        
        else if(f)
        {
            d.push(getNumber(a,token,i,f));   //floatpoint checking
        }
        
        else if(a == '=')       //if character is equal to then call printResult() function
        {
            printResult(d);
        }
        else if(a == 'c')
        {
            emptyStack(d);    //if character is c then it calls emptystack() routine
        }
        else if(a != ' ')
        {
            
            cerr<<"error:character "<<"'"<<a<<"'"<<" is invalid"<<endl;   //error will be printed if not one of the valid operator
        }
        i++;
    }
}
bool unarySign(const char& c, const string& token, const unsigned& i)
{
    if(((token[i+1] == '.') || (isdigit(token[i+1])) ) && ((c == '-') || (c == '+')))
    {
        return true;
    }
    else                                          //checks if it is a valid unary sign -,+
    {
        return false;
    }
}
bool floatPoint(const char& c, const string& token, const unsigned& i)
{
    if(!(isdigit(token[i+1]) && (c == '.')))
    {
        return false;          //checking if given position is a valid decimal point
    }
    else
    {
        return true;
    }
}
double stringToDouble(string& str)
{
    double a = stod(str);
    return a;
}



double getNumber(const char& c,const string& token, unsigned& i, const bool& f)
{
    int d = 0;
    unsigned b = 0;
    if( f || c == '.'){}
    {
        b=i+1;
    }
    while(b<token.length())          //getnumber function builds a double-precision floating number
    {
        if(token[b] == '.')
        {
            if(!floatPoint('.',token,b))
            {
                d = 8;
                break;
            }
            d++;
        }
        else if(!isdigit(token[b]))
            break;
        b++;
    }
    if(!(d >= 2))           //checking for number of decima points if dcimal point greater than 1 then return error
    {
        string str = token.substr(i, (b-i));
        i = b-1;
        return(stringToDouble(str));
        
    }
    else
    {
        cout<<"error:number"<<"'"<<token<<"'"<<"is invalid"<<endl;              //print the error message
        return(0.0);
        
    }
}
bool isValidOperator(const char& c)
{
    if((c == '/') || (c == '*') || (c == '+') || (c == '-'))
    {
        return true;          //check if it a valid  operator /,*,+,-
    }
    else
    {
        return false;
    }
}
double operation(const char& c, const double& a, const double& b)
{
    
    double d = 0.0;
    
    if(c == '+')
    {
        d = a+b;
    }
    else if(c == '-')
    {
        d = a-b;
    }
    else if(c == '*')        //performing the basic operations +,-,*,/
    {
        d = a*b;
    }
    else if(c == '/')
    {
        d = a/b;
    }
    
    return d;
    
}
double popStack(stack<double>& d)
{
    double a = 0.0;
    if(!(d.empty()))
    {
        a = d.top();
        d.pop();     //if stack is not empty then top of the stack is popped
    }
    else
    {
        cout<<"error: Stack is empty"<<endl;   //if stack empty then print error msg
    }
    return a;
}
void printResult(const stack<double>& d)
{
    if(!(d.empty()))
    {
        cout<<fixed<<setprecision(2)<<d.top()<<endl;     //prints exactly two digits after the decimal point for the value in top of stack
    }
    else
    {
        cout<<"stack is empty"<<endl;
    }
}
void emptyStack(stack <double>& d)
{
    while(!d.empty())
    {
        d.top();
        d.pop();          //all the elements will be popped till stack is empty
    }
}
int main()
{
    stack<double> d;
    string token;            //declaring string token for further use
    while(getline(cin, token))
    {
        process_token(token, d);      //calling process token function
    }
    return 0;
}










