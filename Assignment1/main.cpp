#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include <time.h>
#include "document.h"
#include "recent_list.h"
#include "library.h"

const int DICT_SIZE = 16;

int main() {

    // seed the random
    srand(time(NULL));

    string dictionary [DICT_SIZE] = {"FIRST", "CPP", "REVIEW", "PROGRAM", "ASSIGNMENT", "CECS", "BEACH", "ECS", "FALL", "SPRING", "OS", "MAC", "LINUX", "WINDOWS", "LAB", "EXIT"};
    
    recent_list recentList;
    std::cout << "initialized recentlist" << std::endl;

    library lib;
    std::cout << "initialized library" << std::endl;

    string wordInput;


    std::cout << "Enter a word from the dictionary: \n" << std::endl;

    bool equal = false;
    bool EXIT = true;

    do{ // run the program until the user Exits

        do { //  get the correct input
            // what does he mean by the software maintains dictionary of wordsd
            std::cout << "FIRST, CPP, REVIEW, PROGRAM, ASSIGNMENT, CECS, BEACH, ECS, FALL, SPRING, OS, MAC, LINUX, WINDOWS, LAB: \n" << std::endl;
            std::cout << "Enter EXIT to exit the program" << std::endl;
            std::cin >> wordInput;

            for(int i = 0; i < DICT_SIZE; ++i){
                if(equal) i = 99;
                else equal = wordInput== dictionary[i];
            }

            if(!equal) std::cout << "the word that you entered does not match anything in the dictionary" << std::endl;

        // run while until there is same word from the dictionary
        }while(!equal);

        // reset equal 
        equal = false;

        if(wordInput == "EXIT"){
            EXIT = false;
        } else {
            int * ptr;
            document * removed;
            ptr = recentList.findAll(wordInput);
            removed = recentList.removeIndexes(ptr);

            // show the removed pointers
            std::cout << "removed:" << std::endl;
            for(int i = 0; i < LIST_SIZE; ++i){
                recentList.peekPointer(i);
            }

            // replaced the empty indices with library documents
            std::cout << "pull forward" << std::endl;

            // pull the list forward
            recentList.pullForward();
            

            // show the pulled forward pointers
            for(int i = 0; i < LIST_SIZE; ++i){
                recentList.peekPointer(i);
            }
            
            // fill the empty locations from library documents
            int missing = recentList.getMissingCount();


            //fill the empty locations
            for(int i = 0; i < missing; i++ ){
                // replace the missing ones
                recentList.push(lib.pop());
                removed = new document;
                lib.push(removed);
                removed++;
            }


            // show the pointer after the recent list is filled with library documents
            std::cout << "after filled : " <<std::endl;

            for(int i = 0; i < LIST_SIZE; ++i){
                recentList.peekPointer(i);
            }
            
        }
    }while(EXIT); // exit the program when the Exit input is inputted

    return 0;
} // end of main