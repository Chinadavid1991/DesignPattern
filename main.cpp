#include "Strategy.h"
#include <iostream>
using namespace std;
int main() {
    People people[] = {People("jack",178,25),
                       People("rose",165,23),
                       People("xxx",170,30),
                       People("aaa",180,20),
                       People("bbb",170,28)};

    BubbleSort(people,NameComporator());
    for(People& p : people){
        cout << p << endl;
    }
}
