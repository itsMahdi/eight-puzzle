/*
an AI for solving 8 puzzle 
written by Its Mahdi
visit me on 
https://github.com/itsMahdi/
Be happy :)
*/
#include <iostream>
#include <vector>
using namespace std;

class state_table //this class will show every state and situations
{
public:
	int table[3][3];
	state_table(){
		int i,j,c=0;
		for (i = 0; i < 3; ++i)
			for (j = 0; j < 3 ; ++j)
			{
				table[i][j]=c;
				c++;
			}
	}


};
class table_search //making a tree and seaching in that to reach the goal state
{
public:
	state_table *start_state;
	state_table *goal_state;
	std::vector<state_table *> table_list_vector;
	





	state_table* actions()
	{
		int void_row, void_col;
		int i,j;

		table_list_vector.push_back(start_state);
		
		state_table *temp = new state_table,*current_state;


		while(1)
		{
		current_state = table_list_vector.front();
		table_list_vector.erase(table_list_vector.begin());

			if(current_state = goal_state)
			{
				cout<<"founded\n\n\n";
				return goal_state;
			}



		for (i = 0; i < 3; ++i)
			for (j = 0; j < 3 ; ++j)
				if (current_state->table[i][j] == 0)
				{
					void_row = i;
					void_col = j;
					i=2;j=2;
				}


		temp = current_state;
		if (void_col > 0)
		{
		switch (temp->table[i][void_col],temp->table[i][void_col -1]);
		table_list_vector.push_back(temp);
		}
		temp = current_state;
		if (void_col < 2)
		{
		switch (temp->table[i][void_col],temp->table[i][void_col +1]);
		table_list_vector.push_back(temp);
		}
		temp = current_state;
		if (void_row > 0)
		{
		switch (temp->table[i][void_row],temp->table[i][void_row -1]);
		table_list_vector.push_back(temp);
		}
		temp = current_state;
		if (void_row < 2)
		{
		switch (temp->table[i][void_row],temp->table[i][void_row +1]);
		table_list_vector.push_back(temp);
		}

		}

	}


	void switch_state (int &a,int &b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}

	table_search()
	{
		goal_state = new state_table;
		start_state = new state_table;
		int i,j,c;
		cout<< "enter start state:\n";
		for (i = 0; i < 3; ++i)
			for (j = 0; j < 3 ; ++j)
			{
				cout<<"table["<<i<<"]["<<j<<"] :";
				cin>>start_state->table[i][j];
				start_state->table[i][j]=c;
				c++;
			}
	}
};

int main() {
	table_search puzzle_8;

	puzzle_8.actions();


	cout << "sashcaisclka";

return 0;
}