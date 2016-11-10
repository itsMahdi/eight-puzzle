#include <iostream>
#include "graph.h"

using namespace std;

int main() {

    Graph test;

    test.make_list();
    cout<<"make graph";
    //test.show_link_list();
    cout<<"start";
    test.make_graph();
    cout<<"payan";
    //int a;
    //cin>>a;

   // test.mahdimahdi();
    test.BFS_search();
    cout<<"bye bye";
    return 0;
}
