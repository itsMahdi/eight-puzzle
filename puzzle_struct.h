// puzzle structure

#include <iostream>
using namespace std;

class state_node
{
friend class Graph;
private:
	
	int tile[9];
	
	state_node *LLink,*RLink; //for link list
	
	state_node  *left,
				*right,
				*up,
				*down;

public:

	void swap(int x,int y); // for going left right and.. in the puzzle (with void tile)
	void put_to_RLink(state_node *in) {RLink = in;}
	void put_to_LLink(state_node *in) {LLink = in;}
	//return the location of void tile
	int void_location(){
		for (int i = 0; i < 9; ++i)
		if(tile[i] == 0)
			return i;

		cout<<"\nERORR IN TILES!!!\n";
		return 999;
	}
	void show() {
		for (int i = 0; i < 9; ++i)
			cout<<tile[i]<<" ";
		cout<<endl;
	}

	//constructor functions:
	state_node(); //with no input
	state_node(state_node *); // copy constructopr function
	state_node(int A[]);	// :)

	//destructor function
	~state_node(){
		//delete[] tile;      we should search about it!!
		delete LLink;
		delete RLink;
	    delete left;
		delete right;
		delete up;
		delete down;
		cout<<"deleted!!";
	}
};

//swap function
void state_node::swap(int x,int y)
{
	int temp=tile[x];
	tile[x] = tile[y];
	tile[y] = temp;


}

/// constructor functions ///
state_node::state_node()
{
	for (int i = 0; i < 9; ++i)
	{
		tile[i]=0;
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
		tile[i]=A->tile[i];
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
		tile[i]=A[i];
	}
	LLink=NULL;
	RLink=NULL;
	
    left=NULL;
	right=NULL;
	up=NULL;
	down=NULL;
}
/// ******************** ///
