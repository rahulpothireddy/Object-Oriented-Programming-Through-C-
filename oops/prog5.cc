/* NAME : MRUDULA SUNDRU
   ZID : Z1808014
   COURSE : CSCI 689
   DUE DATE : 09/30/2016
   SECTION : 1 */
#include "prog5.h"; // Link to the header file of the program.

void buildMineField(vector<vector<bool> >& mines, const double& mineProb) // PURPOSE : Subroutine to determine the location of mines in the table.
{
int i,j,s; double rnd;
s=sqrt(mines.size());
i=0;
while(i<s) // Loop to add the elements into the table.
    {
        mines.push_back(vector<bool>(s));
        for(j=0;j<s;j++) // Loop that sets values for the location.
        {	 mines[i].push_back(1);
            rnd=rand()/(double(RAND_MAX)+1);
          if(rnd<mineProb) // Returns true if it sets the value for location.
            mines[i][j]=true;
          else // Returns false if it doesnot set the value for location.
            mines[i][j]=false;
        }
        i++;
    }
        srand(1);
}

void fixCounts(const vector <vector <bool> >& mines, vector <vector <unsigned> >& counts) // PURPOSE : Subroutine to check the boolean value for each location and set value for location in mine table.
{
int i,j,s;
s=sqrt(mines.size());
counts.resize(s*s);
i=0;
while(i<s) // Loop to add the elements into the vector.
    {
        for(j=0;j<s;j++)
        {
			counts[i].push_back(0);
	  }
	  i++;
    }
  i=0;
  while(i<s) // Loop to change the values in the mine table. 
    {
        for(j=0;j<s;j++)
        {

            if(mines[i][j]==1) // Sets the value of the location to the value in the next location.
                {
                  counts[i][j]=counts[i][j]+1;
                }
            if((i-1>=0)&&(j-1>=0)) 
            {
                if(mines[i-1][j-1]==1)
                {
                  counts[i][j]=counts[i][j]+1;
                }
            }
            if(j-1>=0)
            {
                if(mines[i][j-1]==1)
                {
                 counts[i][j]=counts[i][j]+1;
                }
            }
            if(((i+1)<s)&&((j-1)>=0))
            {
                if(mines[i+1][j-1]==1)
                {
                 counts[i][j]=counts[i][j]+1;
                }
            }
            if(i+1<s)
            {
                if(mines[i+1][j]==1)
                {
                 counts[i][j]=counts[i][j]+1;
                }
            }
            if((i+1<s)&&(j+1<s))
            {
                if(mines[i+1][j+1]==1)
                {
                 counts[i][j]=counts[i][j]+1;
                }
            }
            if(j+1<s)
            {
                if(mines[i][j+1]==1)
                {
                 counts[i][j]=counts[i][j]+1;
                }
            }
            if((i-1>=0)&&(j+1<s))
            {
                if(mines[i-1][j+1]==1)
                {
                 counts[i][j]=counts[i][j]+1;
                }
            }
            if(i-1>=0)
            {
                if(mines[i-1][j]==1)
                {
                 counts[i][j]=counts[i][j]+1;
                }
            }
        }
        i++;
   }
}

void displayMineLocations(const vector <vector <bool> >& mines) // PURPOSE : Subroutine to display the tavle for the mine field on output console by printing the character X for each mine.
{
int i,j,k,s;
s=sqrt(mines.size());
string str=" ----- "; 
for(i=0;i<s;i++) // Loop to call string to seperate each location.
cout<<str;
cout<<endl;
i=0;
while(i<s) // Loop to display the mines in the mine table.
    {
	for(k=0;k<s;k++)
  	 cout<<"|     |";
	 cout<<endl;
       for(j=0;j<s;j++)
        {
	 cout<<"|  ";
	  if(mines[i][j])
 	   cout<<'X';
	  else
	   cout<<' ';
	  cout<<"  |";
        }
	 cout<<endl;
	for(k=0;k<s;k++)
	 cout<<"|     |";
	cout<<endl;
	for(k=0;k<s;k++)
	 cout<<str;
	cout<<endl;
	i++;
     }	
cout<<endl;
}
 

void displayMineCounts(const vector < vector <unsigned> >& counts) // PURPOSE : Subroutine to display the table for the mine counts on output console for each mine location in counts.
{
int i,j,k,s;
s=sqrt(counts.size());
string str=" ----- ";
   for(k=0;k<s;k++) // Loop to display contents in a string to seperate the location of the table.
     cout<<str;
  cout<<endl;
  i=0;
   while(i<s) // Loop to display the contents in the mine table.
    {
      for(k=0;k<s;k++)
        cout<<"|     |";
      cout<<endl;
      for(j=0;j<s;j++)
        {
	 cout<<"|  "<<counts[i][j]<<"  |";
        }
	cout<<endl;
	 for(k=0;k<s;k++)
	    cout<<"|     |";
	cout<<endl;
	 for(k=0;k<s;k++)
	    cout<<str;
	cout<<endl;
	i++;
    }	
 cout<<endl;
}


int main() /* The main function is responsible for invoking the defined functions .
The return type of main function is int and hence, we are returning the 0 value at the end .
*/

{
    int s; double mineProb; // Declarations of variables for the further computation of program.
       vector <vector <bool> > mines;
       vector <vector <unsigned> > counts;   
          while((cin>>s)&&(cin>>mineProb)) //Loop to call the functions for the computation of values in a mine table.
	    {
              mines.resize(s*s);	
	        buildMineField(mines,mineProb);
		fixCounts(mines,counts);
			cout<<"Mine Locations:size="<<s<<"x"<<s<<", prob of mine="<<mineProb<<endl;
		displayMineLocations(mines);
			cout<<"Mine Counts:"<<endl;
		displayMineCounts(counts);
		mines.resize(0);
		counts.resize(0);
	    }
 return 0;
}

