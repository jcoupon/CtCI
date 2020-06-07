/*
Done well:
    - did tests properly

To improve:
    - don't forget semi-colons at the end of classes and do-while
    - find solution faster for such simple problems
*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;

class Node {
    public:
        Node(int);
        int data;
        std::vector<Node *> children;
        bool marked;
};

Node::Node(int d){

    marked = false;
    data = d;
}

std::map<std::string, Node*> build_graph(){

    // directed graph
    std::map<std::string, Node*> graph;

    // Initiate nodes
    graph["one"] = new Node(1);
    graph["two"] = new Node(2);
    graph["three"] = new Node(3);
    graph["four"] = new Node(4);
    graph["five"] = new Node(5);

    // build routes
    graph["one"]->children.push_back(graph["three"]);
    graph["one"]->children.push_back(graph["five"]);
    graph["one"]->children.push_back(graph["two"]);

    graph["two"]->children.push_back(graph["four"]);
    graph["four"]->children.push_back(graph["one"]);
    graph["five"]->children.push_back(graph["four"]);

    return graph;
}

//function to print the queue
void printQueue(queue<Node *> q)
{
	//printing content of queue 
	while (!q.empty()){
		cout<<" "<<q.front()->data;
		q.pop();
	}
	cout<<endl;
}


bool isRoute(Node *a, Node *b){

    std::queue<Node *> q;

    Node *n = a;

    q.push(n);
    n->marked = true;

    do{
        printQueue(q);
        n = q.front();
        for (Node * c:n->children){
            if (c==b) return true;
            if (!c->marked){
                c->marked = true;
                q.push(c);
            }
        }
        q.pop();
    }while(!q.empty());


    return false;
}





int main(){

    auto graph = build_graph(); 
    bool res;

    // true
    res = isRoute(graph["one"], graph["four"]);
    std::cout << res << endl;

    // false
    res = isRoute(graph["three"], graph["five"]);
    std::cout << res << endl;

    return 0;
}

