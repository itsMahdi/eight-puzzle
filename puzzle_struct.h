// puzzle structure

#include <iostream>
using namespace std;

class state_node
{
private:
	
	int inedx[9];
	
	state_node *LLink,*RLink; //for link list
	
	state_node  *left,
				*right,
				*up,
				*down;

public:

	//constructor functions:
	state_node(); //with no input
	state_node(state_node *); // copy constructopr function
	state_node(int A[]);	// :)

	//destructor function
	~state_node(){
		//delete[] inedx;      we should search about it!!
		delete LLink;
		delete RLink;
	    delete left;
		delete right;
		delete up;
		delete down;
		cout<<"deleted!!";
	}
};

/// constructor functions ///
state_node::state_node()
{
	for (int i = 0; i < 9; ++i)
	{
		inedx[i]=0;
	}
	LLink=NULL;
	RLink=NULL;
	
	    left=NULL;
		right=NULL;
		up=NULL;
		down=NULL;
}
state_node::state_node(state_node *A)//copy constructor function
{
	for (int i = 0; i < 9; ++i)
	{
		inedx[i]=A->inedx[i];
	}
	LLink=NULL;
	RLink=NULL;
	
	    left=NULL;
		right=NULL;
		up=NULL;
		down=NULL;
}
state_node::state_node(int A[])
{
	for (int i = 0; i < 9; ++i)
	{
		inedx[i]=A[i];
	}
	LLink=NULL;
	RLink=NULL;
	
	    left=NULL;
		right=NULL;
		up=NULL;
		down=NULL;
}
/// ******************** ///



int main()
{
	return 0;
}