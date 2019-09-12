#pragma once

#include "document.h"
const int LIST_SIZE = 128;
class recent_list{
    private:
        document * recentList [LIST_SIZE];
    public:
        recent_list();
        ~recent_list();

        int getMissingCount();
        void pullForward();
        document * removeIndexes(int * remove);
        int * findAll(string word);
        int findWord(string word);
        void peekPointer(int index);
        void peekContent(int index);
        void pop();
        void push(document * doc);
};
