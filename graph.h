// this part is for making the graph of puzzle states
// and searching algourithms for them

/*
this code first make a linked list of states and then turn it to graph of states
you can use state in both of
linked list and graph with RLink and LLink for linked list
and LEFT RIGHT UP DOWN for graph
*/
#include <iostream>
#include "puzzle_struct.h"
#include <vector>
using namespace std;

class Graph 
{
private:
	state_node *first;
	state_node *last;
    vector <state_node *> v_list;


public:
	//constructor and destructor part:

	Graph(){first = NULL; last = NULL;}
	//constructor function


	//link list part:

	void make_list();
	//create a Link list of puzzle states
	void add_to_last_fringe(int number[]);
	// add element to the last of link list
	void show_link_list();
	// showin link list of states

	//graph part:
	void make_graph();
	int go_find(state_node *,int [],int );

	//search algouritms:
	state_node* BFS_search(){

		std::vector<state_node *> v;
		int A[9];
		for (int i = 0; i < 9; ++i)
			cin>>A[i];

		state_node *temp=first,*current_state;
		while(temp)
		{
			if (temp->tile[0]== A[0] && temp->tile[1]== A[1] && temp->tile[2]== A[2] && 
				temp->tile[3]== A[3] && temp->tile[4]== A[4] && temp->tile[5]== A[5] && 
				temp->tile[6]== A[6] && temp->tile[7]== A[7] && temp->tile[8]== A[8] )
			{
				current_state=temp;
				temp=NULL;
				cout<<"founded";
			}

			temp=temp->RLink;
		}


		v.push_back(current_state);

		while (v.size() == 0)
		{
			current_state = v.front();
			current_state->check=1;
			v.erase(v.begin());
			int flag=0;
			for (int i = 0; i < 9; ++i)
				if (current_state->tile[i] == i)
					{
						flag++;
					}

			if(flag == 9)
			{
						cout<<"goal founded";
					return current_state;
				}
			flag=0;
			if(current_state->up != NULL && current_state->check==0)
			v.push_back(current_state->up);

			if(current_state->down != NULL && current_state->check==0)
			v.push_back(current_state->down);

			if(current_state->right != NULL && current_state->check==0)
			v.push_back(current_state->right);

			if(current_state->left != NULL && current_state->check==0)
			v.push_back(current_state->left);


		}

	}



	// others needed functions:
	void swap_number(int &a,int &b){
		int temp = a;
		a = b;
		b = temp;
	}
	void swap_number (int A[],int x,int y){
		int temp = A[x];
		A[x] = A[y];
		A[y] = temp;
	}
};


void Graph::make_list() {
	int i[8];

	for (i[0]=0;i[0]<9;i[0]++)
	
		for (i[1]=0;i[1]<9;i[1]++)
			if(i[1] != i[0])
			
				for (i[2]=0;i[2]<9;i[2]++)
					if(i[2] != i[0] && i[2] != i[1])
					
						for (i[3]=0;i[3]<9;i[3]++)
							if(i[3] != i[0] && i[3] != i[1] && i[3] != i[2])
							
								for (i[4]=0;i[4]<9;i[4]++)
									if(i[4] != i[0] && i[4] != i[1] && i[4] != i[2] && i[4] != i[3])
									
										for (i[5]=0;i[5]<9;i[5]++)
											if(i[5] != i[0] && i[5] != i[1] && i[5] != i[2] && i[5] != i[3] && i[5] != i[4])
											
												for (i[6]=0;i[6]<9;i[6]++)
													if(i[6] != i[0] && i[6] != i[1] && i[6] != i[2] && i[6] != i[3] && i[6] != i[4] && i[6] != i[5])
													
														for (i[7]=0;i[7]<9;i[7]++)
															if(i[7] != i[0] && i[7] != i[1] && i[7] != i[2] && i[7] != i[3] && i[7] != i[4] && i[7] != i[5] && i[7] != i[6])
															
																for (i[8]=0;i[8]<9;i[8]++)
																	if(i[8] != i[0] && i[8] != i[1] && i[8] != i[2] && i[8] != i[3] && i[8] != i[4] && i[8] != i[5] && i[8] != i[6] && i[8] != i[7])
                                                                    {
																		add_to_last_fringe(i);
                                                                        v_list.push_back(last);
                                                                    }
}

/// ******************** ///
void Graph::add_to_last_fringe(int number[])
{
	state_node *new_state = new state_node(number);

	if (last == NULL && first == NULL ) {
		first = new_state;
		last = new_state;
	}
	else {
		last->put_to_RLink(new_state);
		new_state->put_to_LLink(last);
		last = new_state;
	}

}
/// ******************** ///
void Graph::show_link_list() {
	state_node *temp = first;
	while (temp)
	{
		temp->show();
		temp = temp->RLink;
	}
}

/// ******************** ///
void Graph::make_graph() {
	int void_loc;//void tile location of state node
	int A[9],B[9];
	state_node *temp = first;

	while (temp)
	{
		//cout<<"temp : ";
		//temp->show();
	//	cout<<endl;
		void_loc = temp->void_location();

		if (void_loc == 0)
		for (int i = 0; i < 9; ++i)
			A[i] = B [i] = temp->tile[i];

		switch (void_loc)
		{
			case 0:
			//for (int i = 0; i < 9; ++i)
			//	cout<<B[i]<<" ";
			//cout<<endl;
				swap_number(A[0],A[1]); //move void tile to right
				swap_number(B[0],B[3]); //move voide tile to down
		//		for (int j = 0; j < 9; j++)
		//	cout<<B[j]<<" ";
		//cout<<endl<<"ssssssssssss\n";
				go_find(temp,A,0);
				go_find(temp,B,1);
				break;
			case 1:
				swap_number(A[1],A[2]);
				swap_number(B[1],B[4]);
				go_find(temp,A,0);
				go_find(temp,B,1);
				break;
			case 2:
				swap_number(A[2],A[5]);
				go_find(temp,A,1);
				break;
			case 3:
				swap_number(A[3],A[4]);
				swap_number(B[3],B[6]);
				go_find(temp,A,0);
				go_find(temp,B,1);
				break;
			case 4:
				swap_number(A[4],A[5]);
				swap_number(B[4],B[7]);
				go_find(temp,A,0);
				go_find(temp,B,1);
				break;
			case 5:
                swap_number(A[5],A[7]);
				go_find(temp,A,1);
				break;
			case 6:
				swap_number(A[6],A[7]);
				go_find(temp,A,0);
				break;
			case 7:
				swap_number(A[7],A[8]);
				go_find(temp,A,0);
				break;
			case 8:
			//do nothing!!
				break;
			default:
		cout<<"error in void tile of puzzle.\n check your code again!";
		}

		temp = temp -> RLink;
	}



}

/// ******************** ///
int Graph::go_find(state_node *current,int A[],int x){
	state_node *temp = current;
    int rear,front,mid;
    front = v_list.size()-1;
    rear = 0;
    while (front = rear) {
        temp = v_list.at((front+rear)/ 2);
        mid = (front + rear) / 2;
        if(A[0]==temp->tile[0] && A[1]==temp->tile[1] && A[2]==temp->tile[2]
            && A[3]==temp->tile[3] && A[4]==temp->tile[4] && A[5]==temp->tile[5]
            && A[6]==temp->tile[6] && A[7]==temp->tile[7] && A[8]==temp->tile[8] )
        {
                if(x==0) //this means void tile goes right
                {
                    current->right = temp;
                    temp->left = current;
                }
                else
                {
                    current->down = temp;
                    temp->up = current;
                }
        return 1;
        }


        int flag;
        flag=0;
        for (int i=0;i<9 && flag==0 ;i++)
        {
            if(A[i]!=temp->tile[i])
            {
                if(A[i] < temp->tile[i])
                    front = mid;
                else
                    rear = mid;
                flag =1;
            }
        }

    }


    cout<<"ERRROOORRRRR\n";



/*    while (temp)
	{


		if(A[0]==temp->tile[0] && A[1]==temp->tile[1] && A[2]==temp->tile[2] 
			&& A[3]==temp->tile[3] && A[4]==temp->tile[4] && A[5]==temp->tile[5] 
			&& A[6]==temp->tile[6] && A[7]==temp->tile[7] && A[8]==temp->tile[8] ) 
		{
				if(x==0) //this means void tile goes right
				{
					current->right = temp;
					temp->left = current;
				}
				else
				{
					current->down = temp;
					temp->up = current;
				}
		return 1;
		}
		temp = temp -> RLink;
			// we can do binary search in here to
			// bring down complexity


	}

    */
	return 0;
}



