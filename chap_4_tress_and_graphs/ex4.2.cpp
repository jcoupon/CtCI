/*
Done well:
    - right approach but first solution did not record leaves
To improve:
    - reduce code complexity

*/


#include <iostream>

using namespace std;

class Node{
    public:
        int i;
        int left;
        int right;
};

int find_pivot(int first, int last){
    int n = last - first + 1;
    // odd, the pivot is in the middle
    if (n%2 != 0){
        return first + (n-1)/2;
    }
    // even the pivot on the right
    else{
        return first + n/2;
    }

}

int build_BST(Node *node, int first, int last){

    int n = last - first + 1;
    if (n==0){
        return -1;
    }

    // pivot
    int i = find_pivot(first, last);
    node->i = i;

    std::cout << first << ' ' << i << ' ' << last << endl;

    // left
    Node *left = new Node();
    node->left = build_BST(left, first, i-1);
    
    // right
    Node *right = new Node();
    node->right = build_BST(right, i+1, last);
    
    return i;
}

int main(){

    int arr [] = {2,4,5,10,12,13,14,15,20};

    Node *root = new Node();
    build_BST(root, 0, 8);

    return 0;
}



