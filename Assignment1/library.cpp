#include <stdlib.h>
#include <string>
#include <stack>
#include <iostream>
#include <array>
#include "document.h"
#include "library.h"

library::library(){
    document * temp;
    for(int i = 0; i < LIB_SIZE; ++i){
        
        temp = new document;
        // std::cout <<i <<". library document initialized " <<std::endl;
        doc_list[i] = temp;
    }
}

library::~library(){
    //free(list);
}
/**
 * Description: add the pointer to the library
 */ 
void library::push(document * doc){
    int i = 0;
    while(doc_list[i] != 0 && i < LIB_SIZE){
        ++i;
    }
    doc_list[i] = doc;
}


/**
 * Description: Pop out the front of the list
 * @return popped out ptr
 */ 
document * library::pop(){
    document * temp;
    temp = doc_list[0];
    // pull all the pointers to the front
    for(int i = 0; i < LIB_SIZE - 1; ++i)
        doc_list[i] = doc_list[i+1];
    // Last pointer is set to null
    doc_list[LIB_SIZE -1] = NULL;
    
    return temp;
}
