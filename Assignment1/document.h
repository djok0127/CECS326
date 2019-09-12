#pragma once
#include <stdlib.h>
#include <string>
#include <stack>
#include <iostream>
#include <array>

using namespace std;
class document {
    private:
        size_t documentSize;
        char * documentPtr;

    public:
        document();

        //copy constructor
        document(const document &doc2);

        ~document();


        void pop();
        size_t getSizeInBytes();
        void printContent();
        bool find(char * word, int size);
};