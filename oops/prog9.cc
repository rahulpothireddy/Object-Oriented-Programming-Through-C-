/*********************************************************
Name            : Thummala Rahul Reddy
Zid             : z1795447
Assignment      : 10
Due Date        : 11/15/2016
Description     : Source file to make the calculator
*********************************************************/

#include "prog10.h" /*include header file that has function prototypes and necessary header files for the programs*/

int main()
{
	string str;
	stack<double> S; /*stack is declared*/
	while(getline(cin, str)) /*reads the input line by line*/
	{
		istringstream isstr(str);
	 	string token; /*token is declared*/
	 	while(getline(isstr, token, ' '))/* it takes input as tokens by using space as a delimiter*/
	 	{
	 		process_token(token, S); /*process_token() function is called*/
	 	}
	}
	return 0;
}



/*This routine inspects each character in the token in sequence and takes the proper action according to the inspected character in the token. */

void process_token(const string &token, stack <double > &S )
{
	bool flag1,flag2,flag3; /*'flag1' is used for checking an unary operator,'flag3' is used for binary operator and 'flag2' for floating point number*/
	flag3=false;
	char una,bin;
	double num,res,a,b;
	for(unsigned i=0;i<token.length();i++) /*iteration through the loop*/
	{
		if(i!=(token.length()-1)) /*checks if a character is the last character or not*/
	 	{
	  		flag1=unarySign(token[i],token,i); /*calls unarySign() and value is stored in flag1*/
	  		if(flag1)
	  		una=token[i]; /* stores the unary operator*/
	  		if(token[i]=='.') /*checks if character is a decimal point*/
	  		{
	   			flag2=floatPoint(token[i],token,i); /*calls floatPoint() and value is stored in flag2*/
	   			if(flag2) /*if the character is a decimal point*/
	    				i++;
	  		}
	 	}
		if(isdigit(token[i])) /*checks if a character is a digit*/
        	{
        		num=getNumber(token,i,flag2);
          		if(una=='-')
          		{
           			num=(num)*(-1);
           			S.push(num);
          		}
          	else
          		S.push(num);
         	}
	 	if(!flag1)
 		{
	  		flag3=isValidOperator(token[i]);
	  		if(flag3)
	  			bin=token[i]; /*stores a binary operator*/
	 	}
	 	if(flag3)
	 	{
	  		a=popStack(S); /*pops second operand*/
	 		b=popStack(S); /*pops first operand*/
	  		res=operation(bin,a,b); /*calls operation() and stores result in 'res'*/
	  		S.push(res); /*pushes result into stack*/
	 	}
	 	if(token[i]=='=')
	 		printResult(S);
		if((!isdigit(token[i])) && (!flag1) && (tolower(token[i]!='c')) && (!flag3) && (token[i]!='='))
			cerr<<"error: character '"<<token[i]<<"' is invalid"<<endl; /*prints error message if input is incorrect*/
		if(tolower(token[i])=='c')
         		emptyStack(S);
	}
}



/*This routine checks whether a character is a unary operator or not. */

bool unarySign(const char &c,const string &token, const unsigned &i) /*checks whether a character is a unary operator or not.*/
{
	if((c=='+'||c=='-')&&(isdigit(token[i+1])||token[i+1]=='.'))
		return true;
	else
		return false;
}

/*This routine checks whether a character is a decimal point or not. */

bool floatPoint(const char &c,const string &token, const unsigned &i)
{
	if((c=='.')&&(isdigit(token[i+1])))
		return true;
	else
		return false;
}


/*This routine checks if a floating point number is valid or not and if it is valid it returns the number. */

double getNumber(const string &token, unsigned &i, const bool &floatPointFlag)
{
	double num;
	int start=i,n=0,count=0,p=0;
	n++;
	i++;
	while((i<=token.length()-1)&&(isdigit(token[i])|| token[i]=='.'))
	{
	 	n++;
	 	i++;
	}
	i--;
	while(p<n)
	{
		if(token[p]=='.')
			count++;
		p++;
	}
	if(count>1)/*checks if a floating point number is valid or not*/
	{
	 	cerr<<"error: number '"<<token.substr(start,n)<<"' is invalid"<<endl; /*error message is printed*/
	 	exit(EXIT_FAILURE); /*exits*/
	}
	else
	num=stringToDouble(token.substr(start,n)); /*string is converted to double*/
	if(floatPointFlag) /*if it is a floating point value*/
	{
		num/=pow(10,n); /*to get a floating point number*/
	}
	return num; /*returns floating point number*/
}


/*This routine checks if a character is a valid binary operator or not.*/

bool isValidOperator(const char &c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/') /*checks if a character is a valid binary operator or not.*/
		return true;
	else
		return false;
}

/*This routine performs the desired operation and returns the result. */

double operation(const char &c, const double &x, const double &y)
{
	double res;
	switch(c)
	{
		case '+': 	res=x+y;
				break;
		case '-': 	res=y-x;
				break;
		case '*': 	res=x*y;
				break;
		case '/': 	res=y/x;
				break;
	}
	return res;
}


/*This routine pops the top element in the stack and returns it. */

double popStack(stack <double > &S )
{
	double t;
	if(S.empty()) /*checks if stack is empty or not*/
		cerr<<"error: stack is empty "<<endl; /*displays error message*/
	else
	{
	 	t=S.top(); /*top of the stack */
	 	S.pop(); /*pops the top element*/
	}
	return t;/*returns the top element*/
}


/*This routine empties the stack. */

void emptyStack(stack<double> &S)
{
	while(!S.empty())/*checks if stack is empty or not*/
	{
	 	S.top(); /*gets the top of the stack*/
	 	S.pop(); /*pops elements*/
	}
}


/*This routine prints the top element in the stack. */

void printResult(const stack<double>& S)
{
        if(S.empty())          /*checks if stack is empty or not*/
        {
         	cerr<<"error : The stack is empty"<<endl;      /*displays error message*/
         	exit(EXIT_FAILURE);
        }
        else
        {
         	S.top();  /*gets the top of the stack*/
         	cout<<fixed<<showpoint<<setprecision(2)<<setw(8)<<S.top()<<endl; /* prints the top element in the stack.*/
        }
}


/*This routine converts string to double. */

double stringToDouble(string str)
{
        double x; /*floating point number is declared*/
        x=atof(str.c_str()); /* converts string to float*/
        return x; /*returns floating point number*/
}
