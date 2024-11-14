#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cctype>
#include <math.h>
#include <conio.h>

//#include "encryption.h"

using namespace std;

string hide_password(){
	string password;
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
	password=pass;
	return password;
}

bool isDigitPresent(string& str){
    for (int i=0;i<str.length();i++){
    	char c = str[i];
        if(isdigit(c)){
            return true;
        }
    }
    return false;
}

bool onlyDigitPresent(string& str){
    for (int i=0;i<str.length();i++){
    	char c = str[i];
        if(!isdigit(c)){
            return true;
        }
    }
    return false;
}

string splitString()
{	
	ifstream inFile("UserRecord.txt");  // Open the file in read mode

    if (!inFile) {  // Check if the file is open
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
	char delimiter=' ';
	string arr[7];
	int index=0;
    // Creating an input string stream from the input string

    // Temporary string to store each token
    string token;

	string line;

	while(getline(inFile,line)){
		istringstream stream(line);
		while (getline(stream, token, delimiter)) {
			// Add the token to the array
			arr[index++] = token;
		}
	}

}

string toUpperString(string& str){
    for (int i=0;i<str.length();i++){
        str[i]=toupper(str[i]);
    }
    return str;
}

string performCeaserCipher(string& content){
    for (int i=0;i<content.length();i++){
        content[i]=(content[i]*6/1*18/8*1/14)%127;
    }
    return content;
}

string decrypt(string& str){
	for (int i=0;i<str.length();i++){
        // str[i]=str[i]/6%18*8%14;
		int x;
		for (x = 0; x <= 1000; x++) {
			if ((x*6/1*18/8*1/14)%127== str[i]) {
				str[i]=x;
				break; // Exit the loop once we find a solution
			}
    	}
    }
	return str;
}

void lapse(int tm){
    time_t now = time(0);
    while (true){
        time_t n = time(0);
        if (n-now >= tm){
            break;
        }
    }
    return;
}

int stoi(string& str){
	int num=0;
	int len=str.length();
	for(int i=len-1;i>=0;i--){
		num+=(str[i]-48)*(pow(10,len-i-1));
	}
	return num;
}

bool checkAt(string& str){
	for (int i=0;i<str.length();i++){
        if (str[i]=='@'){
        	return true;
		}
	}
	return false;
}

void registerr(string name, string age, string gender, string course, string username, string email, string phone, string password){
	string filename="UserRecord.txt";
	ofstream file;
	file.open(filename,std::ios::app);
	if (!file) {
        std::cerr << "Error opening file!" << std::endl;
		return;
    }
    file << performCeaserCipher(name) <<" "
    << performCeaserCipher(age) <<" "
    << performCeaserCipher(gender) <<" "
    << performCeaserCipher(course) <<" "
    << performCeaserCipher(username) <<" "
    << performCeaserCipher(email) <<" "
    << performCeaserCipher(phone) <<" "
    << performCeaserCipher(password) <<"\n";

	file.close();
}

class Quiz {

	// quiz file objects.

	bool encryption();
    bool decryption();
    bool permission();
};

class Admin {
	string username;
    string email;
    string password;


	void login();
    string notify();
    void updateQuizFiles();
	public:
		void accessUserDetails();
		void seeUserPerformance();
		void accessQuizFiles();
		void seeFeedback();
		void removeUser();
		void addNewAdmin();
		void removeAdmin();
};

class User {
	string name;
    int age;
    string gender;
    string course;
    string username;
    string email;
    string phn;
    string password;

	void registration();

    void login();

    void giveTest();
    string giveFeedback();
    void seePerformance();
    void practice();
    void review();
    void logout();
    void seeNotification();
public:
    User(int user_choice){
        if (user_choice==1){
            login();
        }
        else if (user_choice==2){
            registration();
        }
    }

};


void Admin::accessUserDetails(){
	cout<<"Code to acces User Details\n\n";

	ifstream inFile("UserRecord.txt");  // Open the file in read mode

    if (!inFile) {  // Check if the file is open
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

	string col[7]={"Name                 :         ","Age                  :         ","Gender               :         ","Course               :         "
				,"Username             :         ","Email                :         ","Phone Number         :         "};
	string line;
	while(getline(inFile,line)){
		string str="";
		int i=0;
		for (int a=0; a<line.length();a++){
			if (line[a]!=' ')
				str+=line[a];
			else{
				cout<<col[i]<<decrypt(str)<<endl;
				i++;
				str=" ";
			}
		}
		
	}
	
}

void User::registration(){
		system("cls");
        string cnfpass;
        string ages;
        cout<<"Code to Register.\n\n";
        int chances=0;
        //name
	    while(chances<=6){
	    	chances++;
	    	if (chances==6){
	    		cout<<"You have entered wrong input 5 times. Program is exiting. Please restart the program to Register..\n\n";
	    		chances=0;
	    		return;
			}
	        cout<<"Name                 :         "; getline(cin>>ws,name);cout<<"\n";
	        if (isDigitPresent(name)){
	            cout<<"Name cannot contain any digit.\nPlease enter the name again..\n\n";
	            continue;
	        }
	        else if (name.length() < 3 || name.length() > 50 ){
	            cout<<"Name Length should be at least 3 and not more than 50.\nPlease enter the name again..\n\n";
	            continue;
	        }
	        else{
	        	chances=0;
	        	break;
			}
		}
        
        //age
        while (chances<=6){
        	chances++;
	    	if (chances==6){
	    		cout<<"You have entered wrong input 5 times. Program is exiting. Please restart the program to Register..\n\n";
	    		chances=0;
	    		return;
			}
        	cout<<"Age                  :         "; cin>>ages;cout<<"\n";
        	age=stoi(ages);
	        if (onlyDigitPresent(ages)){
	            cout<<"Age should be in  numbers.\nPlease enter the age again..\n\n";
	            continue;
	        }
	        else if (age<1 || age>125){
	            cout<<"Age should not be less than 1 and not more than 125.\nPlease enter the age again..\n\n";
	            continue;
	        }
	        else{
	        	chances=0;
		        age=stoi(ages);
		        break;
	    	}
		}
        
        //gender
        while (chances<=6){
        	chances++;
	    	if (chances==6){
	    		cout<<"You have entered wrong input 5 times. Program is exiting. Please restart the program to Register..\n\n";
	    		chances=0;
	    		return;
			}
        	cout<<"Gender (M/F/O)       :         "; cin>>gender;cout<<"\n";
	        if (toUpperString(gender)=="MALE" || toUpperString(gender)=="FEMALE" || toUpperString(gender)=="OTHER" || toUpperString(gender)=="M" || toUpperString(gender)=="F" || toUpperString(gender)=="O"){
	        	chances=0;
	            break;
	        } else{
	        	cout<<"Gender could be male or female or other only.\nPlease enter the gender again..\n\n";
	            continue;
			}
		}
		
		//course
		while (chances<=6){
			chances++;
	    	if (chances==6){
	    		cout<<"You have entered wrong input 5 times. Program is exiting. Please restart the program to Register..\n\n";
	    		chances=0;
	    		return;
			}
	        cout<<"Course               :         "; cin>>course;cout<<"\n";
	        if (course.length() < 2 || course.length() > 30 ){
	            cout<<"Course Length should be at least 3 and not more than 30.\nPlease enter the course again..\n\n";
	            continue;
	        }
	        else{
	        	chances=0;
	        	break;
			}
    	}
    	
        //username
        while (chances<=6){
        	chances++;
	    	if (chances==6){
	    		cout<<"You have entered wrong input 5 times. Program is exiting. Please restart the program to Register..\n\n";
	    		chances=0;
	    		return;
			}
			cout<<"Username             :         "; cin>>username;cout<<"\n";
			if (!isDigitPresent(username)){
				cout<<"Username should be Alphanumeric. Please enter the username again..\n\n";
				continue;
			}
			
			else if (onlyDigitPresent(username)==false){
				cout<<"Username should be Alphanumeric. Please enter the username again..\n\n";
				continue;
			}
			else{
				chances=0;
				break;
			}
    	}
        //email
        while (chances<=6){
        	chances++;
	    	if (chances==6){
	    		cout<<"You have entered wrong input 5 times. Program is exiting. Please restart the program to Register..\n\n";
	    		chances=0;
	    		return;
			}
        	cout<<"Email                :         "; cin>>email;cout<<"\n";
        	if (!checkAt){
        		cout<<"Email format is invalid. Please enter correct email..\n\n";
        		continue;
			}
			else{
				chances=0;
				break;
			}
		}
        
        //phone number
        while (chances<=6){
        	chances++;
	    	if (chances==6){
	    		cout<<"You have entered wrong input 5 times. Program is exiting. Please restart the program to Register..\n\n";
	    		chances=0;
	    		return;
			}
	        cout<<"Phone Number         :         "; cin>>phn;cout<<"\n";
	        if (phn.length()!=10){
	            cout<<"Phone number should be of 10 digits only. Enter the correct Phone number..\n\n";
	            continue;
	        }
	        else if (phn[0] < 54){
	            cout<<"Phone number can start only with 6, 7, 8 or 9. Enter the correct Phone number..\n\n";
	            continue;
	        }
	        else if (onlyDigitPresent(phn)){
	            cout<<"Phone number can only contain digits. Enter the correct Phone number..\n\n";
	            continue;
	        }
	        else{
	        	chances=0;
	        	break;
			}
    	}
        
        //password
        while (chances<=6){
        	chances++;
	    	if (chances==6){
	    		cout<<"You have entered wrong input 5 times. Program is exiting. Please restart the program to Register..\n\n";
	    		chances=0;
	    		return;
			}
	        cout<<"Password             :         "; password=hide_password();cout<<"\n";
			if (password.length()<8){
				cout<<"Password lenght cannot be less than 8. Please enter the password again..\n\n";
				continue;
			}
			
			else if (!isDigitPresent(password)){
				cout<<"Password should be Alphanumeric. Please enter the password again..\n\n";
				continue;
			}
			
			else if (onlyDigitPresent(password)==false){
				cout<<"Password should be Alphanumeric. Please enter the password again..\n\n";
				continue;
			}
			else{
				//confirm password	
		        cout<<"Confirm Password     :         "; cnfpass=hide_password();cout<<"\n";
		        if (password!=cnfpass){
		            cout<<"Error: Password does not match. Enter password again..\n\n";
		            continue;
		
		        }
		        else{
		        	chances=0;
		        	break;
				}
			}
		}

		system("cls");
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<gender<<endl;
        cout<<course<<endl;
        cout<<username<<endl;
        cout<<email<<endl;
        cout<<phn<<endl;
        cout<<password<<endl;
		
		registerr(name, ages, gender, course, username, email, phn, password);

    }

void User::login(){
        cout<<"Code to login.\n\n";
        cout<<"Username/Email:         "; cin>>username;cout<<"\n";
        cout<<"Password      :         "; cin>>password;cout<<"\n";
        cout<<"YouR Entered Username/Email is: "<<username<<endl;
        cout<<"YOUR Entered Password is: "<<password<<endl;
    }

int main(){
	/*
    Welcome message of app
    ### User interface ###
    login:
    	check credentials
    	Welcome back message
        see notification
        ### user menu ###
        Give test
        See performance
        Give feedback (should be limited that unnecessary feedback can be restricted.)
        MultiUser test
        Practice
        Review
        logout

    register:
    	check credentials through OTP.
    	Thank you message.
        ### user menu ###
        Give test
        See performance
        Give feedback (should be limited that unnecessary feedback can be restricted.)
        MultiUser test
        Practice
        Review
        logout

    exit

    ### Admin interface ###
    login:
    	check credentials
    	Welcome Admin message
        ### Admin menu ###
        see user feedbacks.
        Update Test
        access user details
        See performances of user
        Give recommendations or notification to user.
        acces quiz files
        addNewAdmin  (can only be done by admin 1 that is group leader.)
        removeAdmin  (can only be done by admin 1 that is group leader.)
        removeUser   (can be done by any admin.)
        logout

    exit

    */
    int chooseLRE=-1;
    int no_Of_WO=0;

    while (chooseLRE!=0 || no_Of_WO > 5){
        system("cls");
        cout << "          ************** Welcome to Logic Link ***************\n"<<endl;
        cout << "We are here to make your preparation better for the concerned Exams.🙂🙂\n\n";
        cout << "Press 1 to Login.\nPress 2 to Register.\nPress 0 to Exit.\n";
        cout <<"Choose your desired option: "; cin >> chooseLRE; cout<<"\n";

        if (chooseLRE==0 || chooseLRE==1 || chooseLRE==2){
            User *obj = new User(chooseLRE);
            break;
        }

        else {
            cout<<"Sorry wrong input. Please select the correct option number !!";
            no_Of_WO++;
        }
    }
    lapse(5);
    // system("cls");
	Admin *objj = new Admin();
	objj->accessUserDetails();
	cout << "Thank you for visiting our Application.\nApplication Exited Successfully." << endl;
	return 0;
}
