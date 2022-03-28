#include<conio.h>
#include<cstdio>
#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
static int p=0;
class a
{
	char busn[5],driver[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
	public:
		void install();
		void allotment();
		void empty();
		void show();
		void avail();
		void position(int i);
}
bus[10];
void vline(char ch)
{
	for(int i=80;i>0;i--)
	cout<<ch;
}
void a::install()
{
	cout<<"\nEnter bus no:";
	cin>>bus[p].busn;
	cout<<"\nEnter Driver's name:";
	cin>>bus[p].driver;
	cout<<"\nArrival time:";
	cin>>bus[p].arrival;
	cout<<"\nDeparture:";
	cin>>bus[p].depart;
	cout<<"\nFrom: \t\t\t";
	cin>>bus[p].from;
	cout<<"\nTo: \t\t\t";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
}

void a::allotment()
{
	int seat;
	char number[5];
	top:
		cout<<"\n bus no: ";
	cin>>number;
	int n;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n<=p)
	{
		cout<<"\nSeat Number: ";
		cin>>seat;
		if(seat>32)
		{
			cout<<"\nThere are only 32 seats available in this bus.";
		}
		else
		{
			if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
			{
				cout<<"\nEnter passanger Name: ";
				cin>>bus[n].seat[seat/4][(seat%4)-1];
				break;
			}
			else
			
			 cout<<"The seat number is already reserved.\n";
		}
	}
	if(n>p){
		cout<<"\nEnter correct bus no.\n";
		goto top;
	}
}

void a::empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j],"Empty");
		}
	}
}

void a::show()
{
	int n;
	char number[5];
	cout<<"\nEnter bus no: ";
	cin>>number;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n<=p){
		vline('*');
		cout<<"\n Bus no: \t"<<bus[n].busn<<"\n Driver: \t"<<bus[n].driver
		<<"\n Arrival Time: \t"<<bus[n].arrival<<"\n Departure Time: \t"<<bus[n].depart
		<<"\n From: \t"<<bus[n].from<<"\nTo: \t"<<bus[n].to<<"\n";
		vline('*');
		bus[0].position(n);
		int a=1;
		for(int i=0;i<8;i++){
			for(int j=0;j<4;j++)
			{
				a++;
				if(strcmp(bus[n].seat[i][j],"Empty")!=0)
				cout<<"\nThe seat no "<<(a-1)<<"is reserved for "<<bus[n].seat[i][j]<<".";
			}
		}
		break;
	}
	if(n>p)
	cout<<"Enter correct bus no: ";
}

void a::position( int l)
{
	int s=0,p=0;
	for(int i=0;i<8;i++)
	{
		cout<<"\n";
		for(int j=0;j<4;j++)
		{
		
		s++;
		if(strcmp(bus[l].seat[i][j],"Empty")==0){
			cout.width(5);
			cout.fill(' ');
			cout<<s<<".";
			cout.width(10);
			cout.fill(' ');
			cout<<bus[l].seat[i][j];
			p++;
		}
		else
		{
			cout.width(5);
			cout.fill(' ');
			cout<<s<<".";
			cout.width(10);
			cout.fill(' ');
			cout<<bus[l].seat[i][j];
		}
	}
	
	}
	cout<<"\n\nThere are "<<p<<" seats empty in Bus no: "<<bus[l].busn;
}
 void a::avail()
 {
 	for (int n=0;n<p;n++)
 	{
 		vline('*');
		cout<<"\n Bus no: \t"<<bus[n].busn<<"\n Driver: \t"<<bus[n].driver
		<<"\n Arrival Time: \t"<<bus[n].arrival<<"\n Departure Time: \t"<<bus[n].depart
		<<"\n From: \t"<<bus[n].from<<"\nTo: \t"<<bus[n].to<<"\n";
		vline('*');
		vline('_');
		}
	}

int main()
{
	int w;
	while(1){
		cout<<"\n\n\n\n";
		cout<<"\t\t1.Install\n\t\t"
		<<"2.Reservation\n\t\t"
		<<"3.Show\n\t\t"
		<<"4.Bus Available\n\t\t"
		<<"5.Exit";
		cout<<"\n\t\tEnter your choice: ";
		cin>>w;
		switch(w){
			case 1: bus[p].install();
				break;
			case 2: bus[p].allotment();
				break;
			case 3: bus[p].show();
				break;
			case 4: bus[p].avail();
				break;
			case 5: exit(0);				
				
		}
	}
	return 0;
}
