#include "random_num.h"


void random_gen::setStore() {
    if(bools.Is_low) {
        store += low_alp;
    }
    if(bools.Is_up) {
        store += upper_alp;
    }
    if(bools.Is_Spec) {
        store += special;
    }
    if(bools.Is_brac) {
        store += bracket;
    }
}

std::string random_gen::password(int key, int length) {    /* the meaning of universe: 42 */
    int store_length = store.length();
    int user_length = self_require.length();
    int val_hold;
    srand(time(NULL) + key);
    std::string new_str;
    for(int i = 0; i < length; i++) {
        val_hold = rand() % store_length + 1;
        if(val_hold < store_length) {
            new_str = new_str + store[val_hold];
        } else if (bools.self_set) {
            new_str = new_str + self_require;
            i += user_length;
                // I want it appear only once:
            bools.self_set = false;
        }
    }
    return new_str;
}

bool random_gen::char_input() {
    char store_char = 'a';
    while(true) {
        if(std::cin >> store_char && (store_char == 'Y' || store_char == 'N')) {
            return store_char == 'Y';
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl << "Please enter character 'Y' and 'N' only" << std::endl;
    }
}

std::string random_gen::output_display() {
    std::string result_str;
    int length = 0;
    std::cout << "_________Program is intended to generate Random Password_________"<< std::endl;
    while(true) {
        std::cout << "Enter the length of password from 1 to 100: ";
        if(std::cin >> length) {
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl << "Please input valid integer" << std::endl;

        }
        std::cout << "Your Password length is: " << length << std::endl;
        std::cout << "Now for decide if following option is desire: " << std::endl;
        std::cout << std::setw(45) << std::left << "lowercase alphabet (abcd...) (Y/N)" << std::endl;
        bools.Is_low = char_input();
        std::cout << std::setw(45) << std::left << "Uppercase alphabet (ABCD...) (Y/N)" << std::endl;
        bools.Is_up = char_input();
        std::cout << std::setw(45) << std::left << "Special case (@#$%^&...) (Y/N)" << std::endl;
        bools.Is_Spec = char_input();
        std::cout << std::setw(45) << std::left << "Bracket (()<>[]...) (Y/N)" << std::endl;
        bools.Is_brac = char_input();
        std::cout << std::setw(45) << std::left << "Want to input your own customize substring? (Y/N)" << std::endl;
        bools.self_set = char_input();
        if(bools.self_set) {
            std::cin.ignore();
            std::cout << "User Input substring of password: " << std::endl;
            std::getline(std::cin, this->self_require);
        }
        setStore();
        std::cout << "Enter a key: " << std::endl;
        int key;
        while(true) {
            if(std::cin >> key) {
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Require valid Int input" << std::endl;
        }
        result_str = password(key, length);
        return result_str;
        }






