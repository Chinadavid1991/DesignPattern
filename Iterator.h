//
// Created by feng on 2020/11/20.
//

#ifndef DESIGNPATTERN_ITERATOR_H
#define DESIGNPATTERN_ITERATOR_H
#include <iostream>
#include <memory.h>
template <typename E>
class Collection{
public:
    virtual void add(const E& element) = 0;
    virtual int size() = 0;
};
template <typename E>
class Iterator{
public:
    virtual bool hasNext() = 0;
    virtual E& next() = 0;
};

template <typename E>
class ArrayList:public Collection<E>,public Iterator<E>{

public:
    std::size_t _capacity = 1;
    ArrayList():_data(new E[_capacity]),_len(0){}
    void add(const E &element) override {
        if(_len >= _capacity){
            E* data = new E[_capacity*2];
            memcpy(data,_data, _capacity*sizeof(E));
            delete _data;
            _data = data;
            _capacity = _capacity*2;
        }
        _data[_len] = element;
        ++_len;
    }
    int size() override {
        return _len;
    }
    bool hasNext() override {
        return _index < _len;
    }
    E &next() override {
        return _data[_index++];
    }
    Iterator<E>& getIterator(){
        _index = 0;
        return *this;
    }
private:
    E* _data = nullptr;
    size_t _len = 0;
    std::size_t _index = 0;


};
void testIterator();

#endif //DESIGNPATTERN_ITERATOR_H
