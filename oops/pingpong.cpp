#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

int min_cycles=1;
int max_cycles=4;
const  int grid_size=25;
int sprung=0;


int noBallsInAir=0;
int prn_cycles=10;
int maxBallsInAir=0;
void init_sim(vector < vector < bool> >&traps,vector<unsigned>& ballCycles);
unsigned release_balls (vector < vector < bool> > traps, vector<unsigned> ballCycles);
void print_grid (  vector < vector < bool> >traps,  const unsigned& clock, const unsigned& noBallsInAir );
void print_stat ( const vector < vector < bool > >& traps, const unsigned& maxNoBallsInAir, const unsigned& clock ) ;
void update_cycles ( vector < unsigned >& ballCycles );


int main()
{
	 vector<unsigned >ballCycles;
     vector < vector < bool> > traps (grid_size,vector<bool> (grid_size));
     
   init_sim (traps, ballCycles);
   
   int clock;
   while(noBallsInAir>0)
   {
    noBallsInAir=release_balls (traps, ballCycles);
    //print_grid ( traps, clock,noBallsInAir );
    clock++;
	}
	cout<<"number of balls in air"<<endl;
   print_stat (traps,  maxBallsInAir, clock );
   
 

}





void init_sim(vector < vector < bool> >&traps,vector<unsigned>& ballCycles)

{
	for(int i=0;i<grid_size;i++)
	{
		for(int j=0;j<grid_size;j++)
		{
			traps[i][j]=true;
		}
	}
	srand(time(0));
	ballCycles.push_back(1);
	noBallsInAir=1;
}

unsigned release_balls (vector < vector < bool> > traps, vector<unsigned> ballCycles)
{    
    int repSize=ballCycles.size();
    int clock=0;
    int noBallsInAir=0;
    int high=25;int low=1;
	for(int i=0;i<repSize;i++)
	{
		if(ballCycles[i]>0)
		{
		ballCycles[i]--;
		noBallsInAir++;
		
    	}
	 
	 else
	 
	 if(ballCycles[i]==0)
	 {
	 	if(noBallsInAir>0)
	 noBallsInAir--;
	int b1row= (rand()%(grid_size));
	int b1col=(rand()%(grid_size));
//	int b2row=(rand()%(max_cycles-min_cycles+1))+min_cycles;
//	int n2col=(rand()%(max_cycles-min_cycles+1))+min_cycles;
	
		if(traps[b1row][b1col]==true)
		{
		    update_cycles(ballCycles);
		    update_cycles(ballCycles);
			traps[b1row][b1col]=false;
			noBallsInAir+=2;
		}
		
	/*	if(trap[b2row][b2col]==true)
		{
			sprung++;
			trap[b2row][b2col]=false;
		}
          */		
          		
	}
}
cout<<noBallsInAir;
return noBallsInAir;
}



void print_grid (  vector < vector < bool> >traps,  const unsigned& clock, const unsigned& noBallsInAir )
{
 if(clock%prn_cycles==0)
  {
    cout<<"clock"<<clock;
	cout<<"noBallsInAir"<<noBallsInAir;
   for(int i=0;i<traps.size();i++)
    {
	for(int j=0;j<traps[i].size();j++)
	{
		if(traps[i][j]==true)
		cout<<"X";
		else
		cout<<".";
		
	}
	cout<<endl;
	}	
	
}
}




 	
void print_stat ( const vector < vector < bool > >& traps, const unsigned& maxNoBallsInAir, const unsigned& clock ) 

	{
 	int count=0;
 	cout<<"clock"<<clock;
 	cout<<"number of balls in air is"<<noBallsInAir;
     for(int i=0;i<grid_size;i++)
	 {
	 	for(int j=0;j<grid_size;j++)
	 	{
	 		if(traps[i][j]==false)
	 		count++;
		 }
		  } 	
 	
float percentage=((count/625)*100);
cout<<"percentage of balls in air is"<<percentage;
 	
 	
 }
 
 void update_cycles ( vector < unsigned >& ballCycles )
 {
 	bool result=false;
 	for(int i=0;i<ballCycles.size();i++)
 	{
 		if(ballCycles[i]==0)
 		{
 		   int temp= rand()%(max_cycles-min_cycles+1)+min_cycles;
 			ballCycles[i]=temp;
 			result=true;
		}
 		
	 }
 	if(result==false)
 	{
 		int temp1= rand()%(max_cycles-min_cycles+1)+min_cycles;
 		ballCycles.push_back(temp1);
	 }
 }
