//
// Created by feng on 2020/11/23.
//

#ifndef DESIGNPATTERN_OBSERVER_H
#define DESIGNPATTERN_OBSERVER_H
#include <string>
#include <iostream>
#include <vector>
class Child;
class Event;

class Observer {
public:
    virtual void actionOnEvent(Event& event) = 0;
};
class Event{
    const Child& resource;
    const std::string name;
public:
    Event(const Child& resource, const std::string &name) : resource(resource), name(name) {}

    const Child &getResource() const {
        return resource;
    }
    const std::string &getName() const {
        return name;
    }

};

class Child{
    bool _cry = false;
    std::vector<Observer*> _observers;
public:
    bool isCry() const{
        return _cry;
    }
    void onWake(){
        _cry = true;
        Event event(*this,std::string("child cry"));
        for(Observer* o : _observers){
            o->actionOnEvent(event);
        }

    }
    void addObserver(Observer* observer){
        _observers.push_back(observer);
    }
};


class Dad : public Observer{
public:
    void actionOnEvent(Event& event) override {
        if(event.getResource().isCry()){
            feed();
        }
    }
    void feed(){
        std::cout << "do feed" << std::endl;
    }
};

class Mum : public Observer{
public:
    void actionOnEvent(Event &event) override {
        if(event.getResource().isCry()){
            hug();
        }
    }
    void hug(){
        std::cout << "do hug" << std::endl;
    }
};

class Dog : public Observer{
public:
    void actionOnEvent(Event &event) override {
        if(event.getResource().isCry()){
            bark();
        }
    }
    void bark(){
        std::cout << "do bark" << std::endl;
    }
};

void testObserver();

#endif //DESIGNPATTERN_OBSERVER_H
