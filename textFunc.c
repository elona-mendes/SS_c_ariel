#include <stdio.h>
#include <string.h>

//int lenstrW(char word[]);
void init(int arr[], char word[]);

int gematria(char word[], char txt[]){
    int sumG = 0;
    int flag = 0;
    //calculate the gimatria of "word"
    for (int i = 0; (*(word +i) != ' ')&&(*(word +i) != '\t')&&(*(word +i) != '\n'); i++)
    {
        if (*(word +i) <='Z' && *(word +i) >= 'A')
        {
            sumG = sumG + *(word +i) - 'A' + 1;
        }
        else if (*(word +i) <='z' && *(word +i) >= 'a')
        {
            sumG = sumG + *(word +i) - 'a' + 1;
        }  
    }

    int sumOfTxt = 0;
    int j = 0;
    for (int i = 0; txt[i] != '~'; i++)
    {
        //Skips insignificant char at the beginning of the word
        while ((txt[i] != '~') && ((txt[i] >'Z' || txt[i] < 'A') && (txt[i] >'z' || txt[i] < 'a')))
        {
            i++;
        }
        if(txt[i] == '~'){
            return 0;
        }
        j=i;
        //find letter/word that have the same gematria than "word"
        while ((sumOfTxt<sumG) && (txt[j] != '~'))
        {  
            if (*(txt+j) <='Z' && *(txt+j) >= 'A')
            {
                sumOfTxt = sumOfTxt + *(txt+j) - 'A' +1;
            }
            else if (*(txt+j) <='z' && *(txt+j) >= 'a')
            {
                sumOfTxt = sumOfTxt + *(txt+j) - 'a' +1;
            }
            j++; 
        }
        
        if(sumOfTxt == sumG){
            j=j-1;
            //delete insignificant char at the end of the word
            while((j>=i) && !((txt[j] <='Z' && txt[j] >= 'A') || (txt[j] <='z' && txt[j] >= 'a'))){
                j--;
            }
            //print word that there gematria are the same than "word"
            if(flag == 1){
                printf("~");
                for(int k = i; k<=j; k++){
                    printf("%c", txt[k]);
                }      
            }
            else{
                flag=1;
                for(int k = i; k<=j; k++){
                    printf("%c", txt[k]);
                }
            }
        }
        sumOfTxt = 0;
    }
    return 0;
}


int atbash(char* word, char* txt){  
    int len = strlen(word)-1;  
    char invers[len];
    char invers2[len];   

    //make atbash word
    for (int i = 0;i<len; i++)
    {
        if (word[i] <='z' && word[i] >= 'a'){
            invers[i] = 'a' - word[i] + 'z';
            invers2[len-1-i] = 'a' - word[i] + 'z';
        }
        else if (word[i] <='Z' && word[i] >= 'A'){
            invers[i] = 'A' - word[i] + 'Z';
            invers2[len-1-i] = 'A' - word[i] + 'Z';
        }
        else{
            invers[i] = word[i];
            invers2[len-1-i] = word[i];
        }
    }
    
    int j = 0;
    int txtC=0;
    int flag = 0;
    //find sequence of letter in txt that equals of "sumG"
    for (int i = 0 ; *(txt+i) != '~'; i++){

        //Skips insignificant char at the beginning of the word
        while (!((*(txt+i) <='Z' && *(txt+i) >= 'A') || (*(txt+i) <='z' && *(txt+i) >= 'a')) && *(txt+i) != '~')
        {
            i++;
        }
        if(*(txt+i) == '~') {
            return 0;
        }
        txtC = i;
        if(*(txt+i) == *(invers+j)){
            while ((j<len) && (*(txt+txtC) == *(invers+j)))
            {
                txtC++;
                j++;
            }
            if(j == len){
                if(flag == 1){
                    printf("~%s", invers);
                }
                else{
                    flag=1;
                    printf("%s", invers);
                }
            }
        }
        else if(*(txt+i) == *(invers2+j)){
            while ((j<len) && (*(txt+txtC) == *(invers2+j)))
            {
                txtC++;
                j++;
            }
            if(j==len){ 
                 if(flag == 1){
                    printf("~%s", invers2);
                }
                else{
                    flag=1;
                    printf("%s", invers2);
                }
            }
        }
        j=0; 
    }
    return 0; 
}

int anagram(char* word, char* txt){
    int letters[94] ={0}; //put in every case for each symbole how mach of it are exist in "word"
    
    int flag = 0;
    char str[1024];
    int j =0;
    int k= 0;
    int g = 0;

    for(int i=0; *(txt+i) != '~'; i++){
        while (!((*(txt+i) <='Z' && *(txt+i) >= 'A') || (*(txt+i) <='z' && *(txt+i) >= 'a')) && (txt[i] != '~'))
        {
            i++;
        }
        if(txt[i] == '~'){
            return 0;
        }
        init(letters, word); //Initializes the array "letters" by: word
        j=i;
        k=0;
        while(((letters[txt[j] - '!'] !=0) || (txt[j] == ' '))&&(*(txt+j) != '~')){
            if(txt[j] != ' ') {
                letters[txt[j] - '!']--;
            }
            *(str+k) = *(txt+j);
            j++; 
            k++; 
        }
        //check if all letters was find
        for (g = 0; (g < 94) && !(letters[g] > 0); g++);
        if(g==94){
            for (int l = k-1; (!((*(str+l) <='Z' && *(str+l) >= 'A') || (*(str+l) <='z' && *(str+l)>='a'))) &&(l >= 0); l--)
            {
                str[l]= '\0';    
            }
            if (flag==1){
                printf("~%s", str);
            }
            else{
                flag = 1;
                printf("%s", str);
            }
        }
        //init str
        for (int l = 0; l < k; l++)
        {
            str[l]= '\0';
        }
    }
    return 0;
}

void init(int* arr, char* word){
    for(int i =0;(*(word +i) != ' ')&&(*(word +i) != '\t')&&(*(word +i) != '\n'); i++){
        if((word[i] - '!') >= 0){
            arr[word[i] - '!'] = 0;
        }
    }
    for(int i =0;(*(word +i) != ' ')&&(*(word +i) != '\t')&&(*(word +i) != '\n'); i++){
        if((word[i] - '!') >= 0){
            arr[word[i] - '!'] ++;
        }
    }
}