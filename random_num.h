#ifndef C___RANDOM_NUM_H
#define C___RANDOM_NUM_H

#include <string>
#include <random>
#include <iostream>
#include <time.h>
#include <iomanip>

class random_gen{
    const std::string low_alp = "abcdefghijklmnopqrstuvwxyz";
    const std::string upper_alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string special = "!@#$%^&*+-";
    const std::string bracket = "()[]<>{}";
    std::string store;
    std::string self_require;

    struct Bools{
        bool Is_low = false;
        bool Is_up = false;
        bool Is_Spec = false;
        bool Is_brac = false;
        bool self_set = false;
    };
    Bools bools;
    void setStore();
    // password(key, length) Return the string of random generated password to user, where key is optional input.
    std::string password(int key = 42, int length = 3);
    bool char_input();

    public:
        // output_display() is the actually the interaction with user, will can just let user use this as a black box.
    std::string output_display();
};

#endif //C___RANDOM_NUM_H
