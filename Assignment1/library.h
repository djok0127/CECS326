#pragma once

#include "document.h"
const int LIB_SIZE = 1024;
class library{
    private:
        document * doc_list [LIB_SIZE];
    public:
        library();
        ~library();

        document * pop();
        void push(document * doc);
};
