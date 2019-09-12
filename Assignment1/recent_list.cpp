#include <stdlib.h>
#include <string>
#include <stack>
#include <iostream>
#include <array>
#include "document.h"
#include "recent_list.h"

recent_list::recent_list(){
    document * temp;

    // fill the list with random documents
    for(int i = 0; i < LIST_SIZE; ++i){
        
        temp = new document;
        // std::cout << i <<". recent_list document initialized " <<std::endl;
        recentList[i] = temp;
    }
}

recent_list::~recent_list(){
    //free(list);
}
/**
 * Description: push the document pointer to the back of the list
 */ 
void recent_list::push(document * doc){
    int i = 0;
    while(recentList[i] != 0 && i < LIST_SIZE){
        ++i;
    }
    recentList[i] = doc;
}

/**
 * Description: Pop out the front of the list
 * @return void
 */ 
void recent_list::pop(){
    // pull all the pointers to the front
    for(int i = 0; i < LIST_SIZE - 1; ++i)
        recentList[i] = recentList[i+1];
    // Last pointer is set to null
    recentList[LIST_SIZE -1] = NULL;
}

/**
 * Description: pull pointer forward if there are any NULL ptrs inside
 */
void recent_list::pullForward(){
    int head = 0;
    int tail = 1;
    while(tail < LIST_SIZE){
        if(recentList[head] == NULL){

            // nothing here pull something to here
            if(recentList[tail] != NULL){
                               // there is something in tail
                // move it to the head
                recentList[head] = recentList[tail];
                recentList[tail] = NULL;
                ++head;
            }

            // check next pointer
            ++tail;
        } else {
            // there is a pointer here already 
            ++head;

            // change the tail pointer if it is lower than head.
            if(head > tail) tail = head + 1;
        }
    }
}
/**
 * Description: Print the content of the list at the index
 * @param index: index of where to check
 * @return void
 */ 
void recent_list::peekContent(int index){
    std::cout << "recent_list index = " << index << std::endl;
    (*recentList[index]).printContent();
}
/**
 * Description: Print the pointer of the list at the index
 * @param index: index of where to check
 * @return void
 */ 
void recent_list::peekPointer(int index){
    std::cout << "recent_list index = " << index << std::endl;
    std::cout << recentList[index] << std::endl;
}

/**
 * Description: Find the word from the recent list
 * @param word: word to look for
 * @return: index of the list that includes the word
 */
int recent_list::findWord(string word){
    int found = -1;
    int wordLength = word.length();

    // change string to c_str
    char char_array[wordLength];
    for(int i = 0; i <sizeof(char_array); ++i){
        char_array[i] = word[i];
    }

    
    for(int i = 0; i < LIST_SIZE; ++i){
        // found is set to index when the word is found in the document
        //std::cout << "looking at document : " << i << std::endl;
        //std::cout << "-------------------------------------------" <<std::endl;
        // found the document with the word
        if((*recentList[i]).find(char_array, wordLength)){
            found = i;
            i = LIST_SIZE + 9999;
        }
    }
    
    return found;
}


/**
 * Description: finds all the documents that does not have the word inputted
 * @param word: string input of the word to find
 * @return: an array of pointers that includes the index of all the documents that do not have inputted word in it
 */ 
int * recent_list::findAll(string word){
    static int found[LIST_SIZE];
    int wordLength = word.length();
    int found_index = 0;

    // change string to c_str
    char char_array[wordLength];


    // std::cout << "looking for word: " << word << " length of: " << wordLength << std::endl;
    for(int i = 0; i <sizeof(char_array); ++i){
        char_array[i] = word[i];
    }

    
    for(int i = 0; i < LIST_SIZE; ++i){

        // // found the document with the word
        // if((*list[i]).find(char_array, wordLength)){
        //     std::cout << "list number: " << i <<std::endl;
        //     found[found_index] = i;
        //     // update counter
        //     found_index++;
            
        // }

        // find if the word does not exist
        if(!(*recentList[i]).find(char_array,wordLength)){
            std::cout << word <<" is not found at list number " << i <<std::endl;
            found[found_index] = i;
            found_index++;
        }
    }
    
    // std::cout << "b4 found" << std::endl;
    found[found_index] = -1;
    // std::cout << "after found" << std::endl;
    return found;
}

/**
 * Description removes the indexes that are passed in
 * @param remove: array of index to remove from the recent list
 * @ return doc_ptr is the array that is getting removed
 */
document * recent_list::removeIndexes(int * remove){
    document * doc_ptr;
    int index = 0;
    while(*remove != -1 && index < LIST_SIZE){
        doc_ptr = recentList[*remove];
        std::cout << "removed ptr: " << remove << std::endl;
         //std::cout << doc_ptr << std::endl;
        //std::cout << list[*remove] << std::endl;
        recentList[*remove] = NULL;
        doc_ptr++;
        remove++;
        index++;
    }

    return doc_ptr;
}

/**
 * Description:  get the number of missing/empty pointers 
 * @return count of missing pointers
 */ 
int recent_list::getMissingCount(){
    int count = 0;
    for(int i = 0; i < LIST_SIZE; ++i){
        if(recentList[i] == NULL){
            ++count;
        }
    }
    return count;
}