#include "random_num.cc"



int main(void) {
    random_gen a;
    std::string str = a.output_display();
    std::cout << "*********************Generated Key*********************" << std::endl;
    std::cout << str << std::endl;
    std::cout << "*******************************************************" << std::endl;

}
