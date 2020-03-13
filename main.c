#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int countletters(string phrase);
int countsentences(string phrase);
int countwords(string phrase);

int main(void){
    string phrase = get_string("Text: ");
    int words = countwords(phrase);
    int sentences = countsentences(phrase);
    float L = ((float)countletters(phrase) / (float)words) *100;
    float S = ((float)sentences / (float)words)*100;
    float index = round((0.0588 * L) - (0.296 * S) - 15.8);
    printf("Letters: %i\nWords: %i\nSentences: %i\nL: %f\nS: %f\nIndex: %.1f",(int)countletters(phrase),words,sentences,L,S,index);
return 0;
}

int countletters(string phrase){
    int counter = 0;
    for(int i=0;i<strlen(phrase);i++){
        if((int)phrase[i] >=65 && (int)phrase[i] <= 90){
            counter++;
        }else if((int)phrase[i] >= 97 && (int)phrase[i] <= 122){
            counter++;
        }
    }
    return counter;
}

int countwords(string phrase){
     int counter = 0;
    for(int i = 0; i <= strlen(phrase); i ++) {
       // printf("%c [%i] ",phrase[i],phrase[i]);
       if((int)phrase[i] == 32 || phrase[i] == '\0'){
           counter++;
       }
    }
    return counter;
}

int countsentences(string phrase){
    int counter = 0;
    for(int i = 0; i < strlen(phrase); i ++) {
        // printf("%c[%i]",phrase[i],phrase[i]);
       if(phrase[i] == '.' || phrase[i] == '?' || phrase[i] == '!' || phrase[i] == '\n'){
           counter++;
       }
    }
    return counter;
}
