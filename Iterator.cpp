//
// Created by feng on 2020/11/20.
//
#include "Iterator.h"
void testIterator(){
    ArrayList<int> arr;
    for(int i = 0;i < 1000;++i){
        arr.add(i);
    }
    Iterator<int>& it =  arr.getIterator();
    while (it.hasNext()){
        int x = it.next();
        std::cout << x << std::endl;
    }
}