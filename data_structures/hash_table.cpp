#include <iostream>
#include <string>
using namespace std;

int y;

struct fruit_t{

    string color;
    double price;

} ;


void modify_y(){

    y = 10;

    return;
}

void change_color(fruit_t *fruit){


    fruit->color = "red";

    cout << (*fruit).color << (*fruit).price << endl;

    return;
}


class Node {

    double x, y;

    public:
        void set_x(double xx){x = xx;};
        double get_x(){return x;};


};

int main(){

    Node node;

    node.set_x(10.);

    cout << node.get_x() << endl; 


    return 0;

    enum color_t {black, red, colour_bizarre};


    cout << colour_bizarre << endl;

    return 0;

    fruit_t orange;

    orange.color = "orange";
    orange.price = 10.0;

    change_color(&orange);

    cout << orange.color << orange.price << endl;


    return 0;

    cout << "Enter alloc size" << endl;
  


    long N;

    cin >> N;

    char * a = new char [N];

    for (long i =0; i < N; i++){
        a[i] = 'a';
    }

    cout << a[N-1] << endl;

    cin >> N;


    return 0;

}


