#include<iostream>
#include<sstream>
#include<fstream>
#include<string>

using namespace std;
int main(){
    int i = 0, a;
    string name, password0, password1, password2, age, user, pass, text, word, word1, old;
    string cred[2], cp[2];
    cout<<"security System"<<endl<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"|     1.Register          |"<<endl;
    cout<<"|     2.Log In            |"<<endl;
    cout<<"|     3.Change Password   |"<<endl;
    cout<<"|_____4.End program_______|"<<endl;

    do{
        cout<<endl<<endl;
        cout<<"Enter Your Choice:- ";
        cin>>a;
        switch(a){
            case 1:{
                cout<<" ___________________"<<endl;
                cout<<"|    Register Here  |"<<endl;
                cout<<"|___________________|"<<endl;
                cout<<"Enter username : ";
                cin>>name;
                cout<<endl<<"Enter your age : ";
                cin>>age;
                cout<<endl<<"Enter password : ";
                cin>>password0;
                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
                    of1<<name<<"\n";
                    of1<<password0<<"\n";
                    of1<<age;
                    cout<<endl<<endl<<"Registration Successful"<<endl;
                }
                  break;
            }
            case 2:{
                cout<<" ___________________"<<endl;
                cout<<"|       Log In      |"<<endl;
                cout<<"|___________________|"<<endl;
                i = 0;
                ifstream of2;
                of2.open("file.txt");
                cout<<"Please enter your username: ";
                cin>>user;
                cout<<endl<<"Enter your password : ";
                cin>>pass;
                if(of2.is_open()){
                    while(!of2.eof()){
                        while(getline(of2,text)){
                            istringstream iss(text);
                            iss>>word;
                            cred[i] = word;
                            i++;
                        }
                    }
                    if(user==cred[0] && pass == cred[1]){
                        cout<<"            Loged In successfully            "<<endl<<endl;
                        cout<<"         Details:         "<<endl;
                        cout<<"Username :"<<name<<endl;
                        cout<<"Password : "<<pass<<endl;
                        cout<<"age "<< age<<endl;
                    }
                    else{
                        cout<<endl<<endl;
                        cout<<"    Incorrect Credentials           "<<endl;
                        cout<<"    1.press 2 to log in             "<<endl;
                        cout<<"    2.press 3 to change password    "<< endl;
                    }
                }
                break;
            }
            case 3:{
                i = 0;
                cout<<"                Change Password          "<<endl<<endl;
                ifstream of0;
                of0.open("file.txt");
                cout<<" Enter your old password: "<<endl;
                cin>>old;
                if(of0.is_open()){
                    while(of0.eof()){
                    while(getline(of0, text)){
                        istringstream iss(text);
                        iss>>word1;
                        cp[i] = word1;
                        i++;
                    }
                    if(old == cp[1]){
                        of0.close();
                        ofstream of1;
                        if(of1.is_open())
                        { 
                            cout<<"Enter New Password: ";
                            cin>>password1;
                            cout<<endl<<"Enter New Password again: ";
                            cin>>password2;
                        if(password1==password2){
                            of1<<cp[0]<<"\n";
                            of1<<password1;
                            cout<<"Password changed successfully "; 
                        }               
                        else{
                            of1<<cp[0]<<"\n";
                            of1<<old;
                            cout<<"Password do not match"<<endl;
                        }
                    }
                    }
                    else{ 
                        cout<<"Please enter valid password "<<endl;
                        break;
                    }
                    }
                }
                break;
            }
            case 4:{
                cout<<"__________Thank You____________"<<endl;
                break;
            }
            default:{
                cout<<"Enter a valid choice "<<endl;
            }
        }
    }while(a!=4);
    return 0;
}