//
// Created by feng on 2020/11/19.
//

#ifndef DESIGNPATTERN_COMMAND_H
#define DESIGNPATTERN_COMMAND_H

//命令统一接口
#include <mutex>
#include <atomic>
#include <cassert>
#include <thread>
#include <chrono>
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};
class Light{
    volatile bool _state = false;
    std::atomic_bool _buf {false};
    std::mutex lock;
public:
    explicit Light(bool state) : _state(state) {
        show();
    }
    void update();
    bool set(bool state);
    bool getState();

private:
    void show();
};


class LightOff : public Command{
    Light* _receive = nullptr;
    std::atomic_int _time = {0};
    std::thread _thread;
public:
    explicit LightOff(Light *receive) : _receive(receive) {
        assert(receive != nullptr);
    }
    void execute() override;
    void undo() override;
};

class LightOn : public Command{
    Light* _receive = nullptr;
    std::atomic_int _time = {0};
    std::thread _thread;
public:
    explicit LightOn(Light *receive) : _receive(receive) {
        assert(receive != nullptr);
    }
    void execute() override;
    void undo() override;
};
void testCommand();
#endif //DESIGNPATTERN_COMMAND_H
