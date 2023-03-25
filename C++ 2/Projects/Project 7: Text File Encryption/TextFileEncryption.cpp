#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <fstream>


// I have no idea which libraries I can get rid of...?


using namespace std;


// get line and parse for characters code is in int main()... declare as functions????


// Ceasar Cipher Functions


int MoveEnctUp(int key, int ascii) {        // uppercase encrypt (65-90)
   for(int i = 0; i < key; i++) {
       if((ascii + 1) > 90) {
           ascii = 65;
       }   else {
           ascii = ascii + 1;
       }
   }
   return ascii;
}


int MoveEnctLow(int key, int ascii) {       // lowercase encrypt (97-122)
   for(int i = 0; i < key; i++) {
       if((ascii + 1) > 122) {
           ascii = 97;
       }   else {
           ascii = ascii + 1;
       }
   }
   return ascii;
}


char Encrypt(int key, int ascii)    {  
   char c;
   if((ascii > 97) && (ascii < 122)) { // lowercase ascii values (a/97-z/122)
       ascii = MoveEnctLow(key, ascii);
   }
   if((ascii > 65) && (ascii < 90)) {  // uppercase ascii (A/65-Z/90)
       ascii = MoveEnctUp(key, ascii);
   }   // nothing happens when character is not a letter
   c = char(ascii);    // convert ascii back into a character
   return c;
}


int MoveDcyptUp(int key, int ascii) {       // uppercase decrypt (65-90)
   for(int i = 0; i < key; i++) {
       if((ascii - 1) < 65) {
           ascii = 90;
       }   else {
           ascii = ascii - 1;
       }
   }
   return ascii;
}


int MoveDcyptLow(int key, int ascii) {      // lowercase decrypt (97-122)
   for(int i = 0; i < key; i++) {
       if((ascii - 1) < 97) {
           ascii = 122;
       }   else {
           ascii = ascii - 1;
       }
   }
   return ascii;
}


char Decrypt(int key, int ascii) {
   char c;
   if((ascii > 97) && (ascii < 122)) { // lowercase ascii values (a/97-z/122)
       ascii = MoveDcyptLow(key, ascii);
   }
   if((ascii > 65) && (ascii < 90)) {  // uppercase ascii (A/65-Z/90)
       ascii = MoveDcyptUp(key, ascii);
   }   // nothing happens when character is not a letter
   c = char(ascii);    // convert ascii back into a character
   return c;
}


int main(int argc, char* argv[]) {
   int ascii;  // ascii value of char
   int key = 0;    // user declared key shift number
   string fileName = "";
   string outputName = "";
          
   bool encrypt = false;
   bool decrypt = false;


// declare function for determining if it's a encrypt/decrypt();


//  int strmp();    // takes the two strings as arguments and compares them
           // if int value is 0, the two strings are equal


  
/* 
*    -e or -d : These flags will indicate if the program is encrypting or decrypting a file
*    -k X : This flag specifies the key value, X, where X could be any integer value
*    -i <filename> : This flag specifies the input file, or source file, containing the text to be encrypted or decrypted. Substitute <filename> with your input file name.
*    -o <filename> : This flag specifies the output file, which has the results are written to.
*/
   for(int i = 1; i < argc; i++) {
       string arg = argv[i];
       if(arg == "-e") {
           encrypt = true;
       } else if (arg == "-d") {
           decrypt = true;
       } else if (arg == "-k") {
           sscanf(argv[i+1], "%d", &key);
           i++;
       } else if (arg == "-i") {
           fileName = argv[i+1];
           i++;
       } else if (arg == "-o") {
           outputName = argv[i+1];
           i++;
       }
   }
  
  
   if ((!encrypt && !decrypt) || fileName == "" || outputName == "" || key == 0) {
       cout << "Missing parameters" << endl;
       return 1;
   }


   if (encrypt && decrypt) {
       cout << "Cannot encrypt and decrypt at once" << endl;
       return 1;
   }
  
  
   // READ INPUT FILE
   fstream inputFile;
   if(fileName != "") {
       inputFile.open(fileName, ios::in);  // opens the file to be read
   }
   string fileText;    // string that will contain all data in the file
  
   if(inputFile.is_open()) {
       getline(inputFile, fileText);   // assigns all text to string
   }


   // iterate through the character array
   // each char gets passed to the functions
   // put the edited single characters from parsed line into an output character array
   string outString = "";
   for(int i = 0; i < fileText.length(); i++) {
       ascii = fileText[i];        // gets ascii value of character
       char temp;
       if (encrypt)
           temp = Encrypt(key, ascii);
       else if (decrypt)
           temp = Decrypt(key, ascii);


       outString += temp;
   }
  


   // CREATE OUTPUT FILE
   fstream outputFile;
   outputFile.open(outputName, ios::out);  // open the output file to write to
   if(outputFile.is_open() ) {
       outputFile<<outString;  // insert text in output file
       outputFile.close();
   }


   return 0;
}
