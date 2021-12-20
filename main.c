#include <stdio.h>
#include <string.h>
#include "textFunc.h"

// #define TXT 1024;
// #define WORD 30;

char word[30];
char txt[1024];

int main(){
    for(int i = 0; i < 30; i++){
        scanf("%c", &word[i]);
        if((word[i] == ' ') || (word[i] == '\t') || (word[i] == '\n')){
            (word[i+1] = '\0');
           i=29;
        }
    }
    for(int j = 0; j< 1024; j++){
        scanf("%c", &txt[j]);
        if(txt[j] == '~'){
            j=1023;
        }
    }
    printf("Gematria Sequences: ");
    gematria(word, txt);
    printf("\nAtbash Sequences: ");
    atbash(word, txt);
    printf("\nAnagram Sequences: ");
    anagram(word, txt);
    printf("\n");
    return 0;
}


