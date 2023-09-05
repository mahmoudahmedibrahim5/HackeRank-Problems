#include <bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box
{
  private:
    long long l,b,h;
  public:
    Box(long long L, long long B, long long H){
        l = L;
        b = B;
        h = H;
    }  
    Box(){
        l = 0;
        b = 0;
        h = 0;
    }
    Box(Box& t){
        l = t.getLength();
        b = t.getBreadth();
        h = t.getHeight();
    }
    long long getLength(){
        return l;
    }
    long  long getBreadth(){
        return b;
    }
    long long getHeight(){
        return h;
    }
    unsigned long long CalculateVolume(){
        return (l*b*h);
    }
};
ostream& operator<<(ostream& COUT, Box& tmp)
{
    COUT << tmp.getLength() << " " << tmp.getBreadth() << " " << tmp.getHeight();
    return COUT;
}
int operator < (Box& A, Box& B)
{
    if( (A.getLength() < B.getLength()) )
        return 1;
    else if( (A.getLength()==B.getLength()) && (A.getBreadth()<B.getBreadth()) )
        return 1;
    else if ( ( (A.getLength()==B.getLength()) && (A.getBreadth()<B.getBreadth()) && (A.getHeight()<B.getHeight()) ) )
        return 1;
    else
        return 0;
}
void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}