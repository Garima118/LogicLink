// #include <iostream>
// #include <string>
// #include <cctype>
// #include <fstream>
// // #include "encryption.h"

// using namespace std;

// string performCeaserCipher(string& content){
//     for (int i=0;i<content.length();i++){
//         content[i]=(content[i]*6/1*18/8*1/14)%127;
// 		if (content[i]==44)
// 			content[i]++;
//     }
//     return content;
// }

// string decrypt(string& str){
// 	for (int i=0;i<str.length();i++){
//         // str[i]=str[i]/6%18*8%14;
// 		int x;
// 		for (x = 0; x <= 1000; x++) {
// 			if ((x*6/1*18/8*1/14)%127== str[i]) {
// 				if (x==44)
// 				    x--;
// 				str[i]=x;
// 				break; // Exit the loop once we find a solution
// 			}
//     	}
//     }
// 	return str;
// }

// int main(){
// 	cout<<"code starts here.\n";
// 	string str="My name is Mohammad Farhan.";
// 	cout<<"String before encryption:- "<<str<<endl<<endl;
// 	performCeaserCipher(str);
// 	cout<<"String after encryption:- "<<str<<endl<<endl;
// 	cout<<(95 * 6 / 1 * 18 / 8 * 1 / 14)%127;
// 	cout<<char(44)<<endl;
// 	decrypt(str);
// 	cout<<"String after decryption:- "<<str<<endl;
// 	return 0;
// }

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std; //needed for cout and etc

int main()
{
START:
system("cls");
cout<<"\nEnter Password : ";
char pass[32];//to store password.
int i = 0;
char a;//a Temp char
for(i=0;;)//infinite loop
{
a=getch();//stores char typed in a
if(a>=33&&a<=126)
//check if a is numeric or alphabet
{
pass[i]=a;//stores a in pass
++i;
cout<<"*";
}
if(a=='\b'&&i>=1)//if user typed backspace
//i should be greater than 1.
{
cout<<"\b \b";//rub the character behind the cursor.
--i;
}
if(a=='\r')//if enter is pressed
{
pass[i]='\0';//null means end of string.
break;//break the loop
}
}
cout<<"\nYou entered : "<<pass;
//here we can even check for minimum digits needed
if(i<=5)
{
cout<<"\nMinimum 6 digits needed.\nEnter Again";
getch();//It was not pausing :p
goto START;
}
return 0;
}


