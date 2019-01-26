
// Program to recognise the cents in a given source file and delete them. 

#include "prog4.h" 

int main() //calling main function
{
  ifstream is; 
  ofstream os; 
  open_files(is, os); 
  process_data(is, os); 
  close_files(is, os); 
 return 0;
}


void open_files(ifstream& is,ofstream& os) // To open the files for computation of data.
{
  is.open(INf); //opening input file path
  if(is.fail())
  {
	  cout<<"Error";
	  exit(EXIT_FAILURE);     //returns error
  }
  os.open(OUTf); //output file path
  if(os.fail())
  {
	  cout<<"Error";       //return error
	  exit(EXIT_FAILURE);
  }
}

void process_data(ifstream& is,ofstream& os) // PURPOSE : To check, detect and delete the cents from the input files.
{
    string str; // Declaring the string for storing the data for computation.
       unsigned int c,c1,c2; // Variables for detecting the cents.
       unsigned int pos; // Variable for finding the location of the pointer.
       int n=0;

    while(getline(is,str)) // Loop for transversing the data in the input file and storing into the string.
        {
                string temp;
                pos = str.length(); // Saving the length of teh string into position.
                c1 = 0;
                c2 = 0;

        for(unsigned int i = 0; i<pos; i++) // Loop for detecting the cents using the format of cents.
                {
                       
                        if(str[i] == '/' && str[i+1] == '*' && c1 == 0 && c2 == 0) // Line starting with '/*' is checked for.
                        {
                                c = 1;
                                i=i+2;
                        }
                        if(str[i] == '*' && str[i+1] == '/' && c1 == 0 && c2 == 0) // Line ending with '*/' is checked.
                        {
                                c = 0;
                                i=i+2;
                
                                if(str[i] == '/' && str[i+1] == '*')
                                {
                                        c = 1;
                                }
                        }

                        if(str[i] == '/' && str[i+1] == '/' && c2 == 0 && c == 0) // Line starting with '//' is checked for.
                        {
                                c1 = 1;
                                pos = i;
                        }
                         if(str[i] == '"' && c == 0 && c1 == 0 && n == 0) // Line starting with ' " ' is checked for.
                        {
                                                c2 = 1;

                                                n = 1;
                                                temp  = temp + '"';
                                                i++;
                        }

                   if(str[i] == '"' && c == 0 && c1 == 0 && n == 1) // Loop to check if the string position reached to the end.
                      {
                        c2 = 0;
                        n = 0;
                        temp= temp + '"';
                        i++;
                      }

                 if(c == 0) // Loop for check of cent is checked.
                  {
                     if(i < pos) // Loop to verify the values by comparing it to position of the variable.
                       {
                         temp = tempp + str[i];
                       }
                  }
             }

            os<<temp<<endl; // Displaying the computed output.
        }
 }

void close_files(ifstream& is,ofstream& os) //closing the file
{
  is.close(); 
  os.close(); 
}



