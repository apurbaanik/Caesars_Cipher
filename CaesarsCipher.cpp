/*
Title: Homework 4.1 Caesar's Cipher
Author: Anik Barua
Version: 1.0
Date: 05-04-2021

Description: This C++ program takes a cipher text and returns a plain text. Since it doesn't have the shift
number it uses "brute force" to get all the plain text possible and the one contains "Yanks" is the correct 
shift key. Then it uses the shift key to get the plain text for each cipher text.
*/

#include <iostream>
#include <string>
using namespace std;

/*
The findShiftNum() takes the cipher text and returns the shift number of the correct plain text 
that matches with the substring "Yanks".
*/
int findShiftNumber(string cipherText){
    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int len = alphabet.length();

    //Rotation through 52 alphabets (both upper and lower case) in the alphabet string
    for(int shiftNum = 1; shiftNum <= len; shiftNum++){
        string result = ""; //Blank string for new shifted line
        for(int i = 0; i < cipherText.length(); i++){ //Going through each character
            char c = cipherText[i]; 
            //Finding the character position in the alphabet string
            int position;
            for(int j = 0; j < len; j++){
                if(alphabet[j] == c){
                    position = j; //Found the index
                }
            }
            int finalPosition = (shiftNum + position - 1)%len; //Position of the character after shifted
            //If the final position is greater than string alphabet length, subtract length
            if(finalPosition > len){
                finalPosition -= len;
            }
            c = alphabet[finalPosition - 1]; //Shifted character
            result += c;  //Add it to the string
        }
        //If string contains "Yanks", return the shift number. 
        if (result.find("Yanks") != string::npos) {
            return shiftNum;
        }
    }
    return 0;
}

/*
The decipher() takes a cipher text and the shift number, and returns the plain text.
*/
void decipher(string cipherText, int shiftNum){
    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int len = alphabet.length();
    string result = ""; //Blank string for new shifted line

    for(int i = 0; i < cipherText.length(); i++){ //Going through each character
        char c = cipherText[i];
        //Finding the character position in the alphabet string
        int position;
        for(int j = 0; j < len; j++){
            if(alphabet[j] == c){
                position = j; //Found the index
            }
        }
        int finalPosition = (shiftNum + position - 1)%len; //Position of the character after shifted
        //If the final position is greater than string alphabet length, subtract length
        if(finalPosition > len){
                finalPosition -= len;
        }
        c = alphabet[finalPosition - 1]; //Shifted character
        result += c; //Add it to the string
    }
    cout << "Plain text: " << result << endl;
}

int main(){
    //Cipher text strings
    string cipherText1 = "uIFzBOLTbSFbMTPlOPXObTuIFcSPOYcPNCFST";
    string cipherText2 ="dBFTBSdJQIFSfYFSDJTFxJUIdqMVTqMVT";
    
    int shiftNumber = findShiftNumber(cipherText1); // Gets the shift number
    cout << "The shift number is: " << shiftNumber << endl;
    
    decipher(cipherText1, shiftNumber); //Prints the plain text for cipher text 1
    decipher(cipherText2, shiftNumber); //Prints the plain text for cipher text 2
    return 0;
}