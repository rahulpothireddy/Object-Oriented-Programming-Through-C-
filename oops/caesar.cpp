

#include <iostream>  
#include <string>
//#include <fstream>
using namespace std;
//#define input_file_path="/home/cs689/progs/16f/p3/prog3.d2"
 
//void process_infile(const int,const string&key); 
 



/*void process_infile(const int shift, const string&key) 
{
 cout<<"Shift = "<<shift<<"\n";
  string input_file_line; 
  string new_input_file_line;
  ifstream input_file;
  input_file.open(input_file_path);
    if(input_file.is_open()) 
     {
      while(getline(input_file,input_file_line))
       {
         cout<<encodeCaesarCipher(input_file_line,shift)<<endl;
       }
      input_file.close();
     }
    else
     {
       cerr<<"File does not exist in the given path"; 
       exit;
     }
}

*/
string encodeCaesarCipher ( string str, const int& shift, const string& key )
{
	string check=str;
	int n=str.length();
	
	for(int i=0;i<n;i++)
	{
		if(isalpha(check[i]))
		{
			if(check[i]>'A'&& check[i]<'Z')
			{
			
			char x = (check[i] + shift - 'A' + 26); 
         	check[i]=((x % 26)+'A');
         }
        }

        else if (check[i] > 'a' && check[i] <'z')

        {

            char y = (check[i] + shift - 'a' + 26);
            check[i]=((y%26)+'a');

        }
  
    }
           return check;
}

		

















int main() 
{
  int shift=3; 
   string key = "QWERTYUIOPASDFGHJKLZXCVBNM";
   string str ="harini496";
  
  string ABC;
  ABC= encodeCaesarCipher(str,shift,key );
  cout<<ABC;
  

}





























