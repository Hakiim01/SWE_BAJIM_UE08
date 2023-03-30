#include <iostream>
#include "content/text_coder_t.h"

int main() {

    std::cout << "test1: \nInput: aaaacccggt \noutput: ";
    coder::text_coder_t t1;
    t1.encode("../files/test1.txt");
    t1.decode("../files/test1.enc");

    std::cout << "\n\ntest2: \nInput: hello world \noutput: ";
    coder::text_coder_t t2;
    t2.encode("../files/test2.txt");
    t2.decode("../files/test2.enc");

    std::cout
            << "\n\ntest3: \nInput: AACCCNNDDDAACCCCCRRAACCCCNNNADDDDDCCCAAACCNAAAAACCDDDDRRAAAANCCCRRAAAAARRRCCCCAARRAAAAAAACCCRRRRNCCC \noutput: ";
    coder::text_coder_t t3;
    t3.encode("../files/test3.txt");
    t3.decode("../files/test3.enc");


    std::cout << "\n\ntest4: \nInput: \noutput: ";
    coder::text_coder_t t4;
    t4.encode("../files/test4.txt");
    t4.decode("../files/test4.enc");

    std::cout << "\n\ntest5: \nInput: a\noutput: ";
    coder::text_coder_t t5;
    t5.encode("../files/test5.txt");
    t5.decode("../files/test5.enc");

    
    std::cout << "\n\ntest6: \nInput: 1234\noutput: ";
    coder::text_coder_t t6;
    t6.encode("../files/test6.txt");
    t6.decode("../files/test6.enc");

    std::cout << "\n\ntest7: \nInput: -,,.-%&)=(/!§\noutput: ";
    coder::text_coder_t t7;
    t7.encode("../files/test6.txt");
    t7.decode("../files/test6.enc");


    return 0;
}
