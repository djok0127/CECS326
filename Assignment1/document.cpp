
#include <stdlib.h>
#include <time.h>
#include <array>
#include "document.h"

const int ALAPHABET_SIZE = 26;
char alphabet [ALAPHABET_SIZE] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

document::document(){

    // srand called here will give same output within the 1 second frame
    // srand(time(NULL));
    documentSize = (rand()%(1024*1024) + 2*1024*1024);
    size_t i = 0;

    // Allocate space for document ptr
    documentPtr = (char*)malloc(documentSize*sizeof(char));

    for(i = 0; i < documentSize; ++i){
        documentPtr[i] = alphabet[rand()%ALAPHABET_SIZE];
    }
    // for(i = 0; i < BufSize; ++i){
    //     std::cout << BufPtr[i];
    // }
}

/**
 * Description: deep copy of the document
 */ 
document::document(const document &doc2){
    std::cout << "copy";
    this->documentSize = doc2.documentSize;
    this->documentPtr = doc2.documentPtr;
    this->documentPtr = (char*)malloc(doc2.documentSize*sizeof(char));

    for(size_t i = 0; i < documentSize; ++i){
        this-> documentPtr[i] = doc2.documentPtr[i] ;
    }
}


document::~document(){
    // std::cout << " \n --- freed the memory --- \n";
    //free(documentPtr);
}

size_t document::getSizeInBytes(){
    return documentSize;
}

/**
 * Description: display the output of the document
 */ 
void document::printContent(){
    for(size_t i = 0; i < documentSize; ++i){
        std::cout << documentPtr[i];
    }
}

/**
 * Description: Find the word that is passed in
 * @param word: char array of word
 * @param size: size of the array
 * @return if found return true
 */
bool document::find(char * word, int size){
    int count = 0;
    // std::cout << "looking for word: " << word[0] << word[1] << word[2] << " length of: " << size << std::endl;
    for(size_t i = 0; i < documentSize; ++i){

        
        // check if the first letter is the same
        if(word[0] == documentPtr[i]){
            for(int j = 0; j < size ; ++j){
                //std::cout << documentPtr[i+j];
                if(word[j] == documentPtr[i+j]) ++count;
                else{
                    count = 0;
                    j = 99;
                }
            }
            
            if(count >= size) {
                // std::cout << "found at : " << i <<std::endl;
                // std::cout << "count: " << count <<std::endl;
                // std::cout << "size: " << size << std::endl;
                return true;
            } //else std::cout << "\n --- failed at " << i << " --- \n";
        }
    }
    return false;
}

