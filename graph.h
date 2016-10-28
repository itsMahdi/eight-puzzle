// this part is for making the graph of puzzle states
// and searching algouritjms for them

/*
this code first make a linked list of states and then turn it to graph of states
you can use state in both of
linked list and graph with RLink and LLink for linked list
and LEFT RIGHT UP DOWN for graph
*/
#include <iostream>
#include "puzzle_struct.h"
using namespace std;

class Graph 
{
private:
	state_node *first;
	state_node *last;


public:
	//constructor function
	Graph(){first = NULL; last = NULL;}
	void make_list();
	//create a Link list of puzzle states
	void add_to_last_fringe(int number[]);



};
void Graph::make_list() {
	int i[8];

	for (i[0]=0;i[0]<9;i[0]++)
	{
		for (i[1]=0;i[1]<9;i[1]++)
			if(i[1] != i[0])
			{
				for (i[2]=0;i[2]<9;i[2]++)
					if(i[2] != i[0] && i[2] != i[1])
					{
						for (i[3]=0;i[3]<9;i[3]++)
							if(i[3] != i[0] && i[3] != i[1] && i[3] != i[2])
							{
								for (i[4]=0;i[4]<9;i[4]++)
									if(i[4] != i[0] && i[4] != i[1] && i[4] != i[2] && i[4] != i[3])
									{
										for (i[5]=0;i[5]<9;i[5]++)
											if(i[5] != i[0] && i[5] != i[1] && i[5] != i[2] && i[5] != i[3] && i[5] != i[4])
											{
												for (i[6]=0;i[6]<9;i[6]++)
													if(i[6] != i[0] && i[6] != i[1] && i[6] != i[2] && i[6] != i[3] && i[6] != i[4] && i[6] != i[5])
													{
														for (i[7]=0;i[7]<9;i[7]++)
															if(i[7] != i[0] && i[7] != i[1] && i[7] != i[2] && i[7] != i[3] && i[7] != i[4] && i[7] != i[5] && i[7] != i[6])
															{
																for (i[8]=0;i[8]<9;i[8]++)
																	if(i[8] != i[0] && i[8] != i[1] && i[8] != i[2] && i[8] != i[3] && i[8] != i[4] && i[8] != i[5] && i[8] != i[6] && i[8] != i[7])
																	{
																		add_to_last_fringe(i);
																	}
															}
													}
											}
									}
							}
					}
			}
	}
}

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

int main()
{
	return 0;
}