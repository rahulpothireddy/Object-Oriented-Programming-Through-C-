void process_infile ( const int& shift, const string& key ) // Subroutine to display the output of the give ndetails by the user.
{
 cout<<"Shift = "<<shift<<"\n";
 cout<<"Key = "<<key<<"\n";
 
  string input_file_line; // Declarations of variables required for displaying the output in a format.
  string new_input_file_line;
  ifstream input_file;
  input_file.open(input_file_path);
    if(input_file.is_open()) // Loop used to call the subroutine for input of data.
     {
      while(getline(input_file,input_file_line))
       {
         cout<<encodeCaesarCipher(input_file_line,shift,key)<<endl;
       }
      input_file.close();
     }
    else
     {
       cerr<<"File does not exist in the given path"; // Error message.
       exit(EXIT_FAILURE);
     }
}


string encodeCaesarCipher( string str, const int& shift, const string& key )// Subroutine to take the input data fro the user.
{
 string new_input_file_line=""; // Declarations for the subroutine.
 string each_character="";
  for(int index_of_chars=0;index_of_chars<int(input_file_line.length());index_of_chars++) // Loop for the alignment of the input file.
   {
     each_character=new_position(input_file_line[index_of_chars],shift,key);
     new_input_file_line=new_input_file_line.append(each_character);
   }  
  return new_input_file_line;
}


int new_position( const char& c, const int& shift, const string& key )

        string alphacheck = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int finalvaluetoreturn = 0;
		int totalShift = 0;
        cout<<endl<<shift<<" is the shift"<<endl;
        cout<<key<<" is the key"<<endl;
		int Value_ASCII = 0 ; // Declarations.

int i=0;
while(i<alphacheck.length()){

			if(isalpha(c)){
                if(toupper(c) == alphacheck[i])
                {
                char findme=key[i];

                int j=0;
                while(!(key[i]==alphacheck[j]))
                {
                j++;

                }
				totalShift = i - j;
                cout<<totalShift<<" is the needed value asdasdasdadasdasd";
                }
                i++;
                }
			}
	
		totalShift = totalShift + shift;
	if(isalpha(c)){
		if(isupper(c)){
			Value_ASCII = totalShift + 65;
		}else{
			Value_ASCII = totalShift + 97;
		}
    }
  int j=0;
  if(isalpha(ch)) // Loop to check the values are alphabets.
   {
    if(totalShift>=1) // Loop to check and shift the position.
     {
      if(isupper(ch)) // Loop to check the case of the value.
       {
        if(Value_ASCII+totalShift>90) // Loop if value is in ascii range.
         {
          Value_ASCII=64+(Value_ASCII+totalShift-90)%26;
         } 
        else if(Value_ASCII+totalShift<90) // Loop if value is in ascii range.
         {
          j=1;
         }
       }
      else
      {
       if(Value_ASCII+totalShift>122) // Loop if value is upper case alphabet.
       {
        Value_ASCII=96+(Value_ASCII+totalShift-122)%26;
         if(Value_ASCII<97)
          {
	   Value_ASCII=122;
          }
       }
      else if(Value_ASCII+totalShift<122) // Loop if value is lower case alphabet.
      {
       j=1;
      }
     }
    }   
   else if(totalShift<0)
   {
    if(isupper(ch))
     {
      if(Value_ASCII+totalShift<65)
       {
        Value_ASCII=91+(Value_ASCII+totalShift-65)%26;
       }
      else if(Value_ASCII+totalShift>65)
      {
       j=1;
      }
     }
    else // Loop to shift the value.
    {
      if(Value_ASCII+totalShift<97)
       {
         Value_ASCII=123+(Value_ASCII+totalShift-97)%26;
       }
      else if (Value_ASCII+totalShift>97)
       {
         j=1;
       }
    }
   }
  }
 if(j==1){
   Value_ASCII=Value_ASCII+totalShift;
  }
   
  return Value_ASCII; 		
}
int main() 
{
  int shift=0; 
  int i=0;
   while(i<5) 
   {
      cin>>shift;
	  cin>>key;
     process_infile(shift,key);
     cout<<endl;
     i++;
   }
return 0;
}
