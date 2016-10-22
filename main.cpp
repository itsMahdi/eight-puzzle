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
///////////	
	state_table(state_table *state)
	{  // tabeye sazandeye copy
		int i,j;

		for (i = 0; i < 3; ++i)
			for (j = 0; j < 3 ; ++j)
				table[i][j]=state->table[i][j];
	}
///////////
	void show_table()
	{
		int i,j;
		for (i = 0; i < 3 ; ++i)
		{
			cout<<endl;
			for (j = 0; j < 3 ; ++j)
				cout<</*"i , j = "<<i<<" , "<<j<<" = "<<*/table[i][j]<<"  ";
		}
	cout<<endl;
	}
	
};
class table_search //making a tree and seaching in that to reach the goal state
{
public:
	state_table *start_state;
	state_table *goal_state;
	std::vector<state_table *> table_list_vector;
	



	bool check_goal (state_table *current_state)
	{
		int i,j,c=0;
		for (i = 0; i < 3 ; ++i)
			for (j = 0; j < 3 ; ++j)
			{
				if(current_state->table[i][j] != c) return false;
				c++;
			}

		return true;
	}

	state_table* actions()
	{
		int void_row, void_col;
		int i=0,j=0;

		table_list_vector.push_back(start_state);
		
		state_table *temp,*current_state;


		while(1)
		{
		current_state = table_list_vector.front();
		cout<<"size: "<<table_list_vector.size()<<"\n";
		cout<<"current_state\n";
		current_state->show_table();
		//cout<<"goal \n";
		//goal_state->show_table();
		char x;
		cin>>x;
			if(check_goal(current_state) == true)
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
		static int temp_row=void_row,
		temp_col=void_col;
		

		if (void_col > 0)
		{
		temp =  new state_table(*current_state);
		void_col = temp_col;
		void_row = temp_row;
		switch_state (temp->table[void_row][void_col],temp->table[void_row][void_col -1]);
			cout<<"***\n temp:1 \n";
		temp->show_table();
		table_list_vector.push_back(temp);
	
		}
		
		if (void_col < 2)
		{
		temp =  new state_table(*current_state);
		void_col = temp_col;
		void_row = temp_row;
		switch_state (temp->table[void_row][void_col],temp->table[void_row][void_col +1]);
		table_list_vector.push_back(temp);
					cout<<"***\n temp:2 \n";
		temp->show_table();
		}
		
		if (void_row > 0)
		{
		temp =  new state_table(*current_state);
		void_col = temp_col;
		void_row = temp_row;
		switch_state (temp->table[void_row][void_col],temp->table[void_row-1][void_col]);
		table_list_vector.push_back(temp);
					cout<<"***\n temp:3 \n";
		temp->show_table();
		}
		
		if (void_row < 2)
		{
		temp =  new state_table(*current_state);
 		void_col = temp_col;
		void_row = temp_row;
		switch_state (temp->table[void_row][void_col],temp->table[void_row+1][void_col]);
		table_list_vector.push_back(temp);
					cout<<"***\n temp:4 \n";
		temp->show_table();
		}

		table_list_vector.erase(table_list_vector.begin());
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
		int i,j,c=0;
		cout<< "enter start state:\n";
		for (i = 0; i < 3; ++i)
			for (j = 0; j < 3 ; ++j)
			{
				cout<<"table["<<i<<"]["<<j<<"] :";
				cin>>start_state->table[i][j];
				goal_state->table[i][j]=c;
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