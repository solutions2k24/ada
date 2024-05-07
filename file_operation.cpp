#include<iostream>
#include<fstream>
#include<iomanip>// for proper alignment
using namespace std;

void addstudent()
{
    //output stream name is f , open in append mode so ios::ap
    ofstream f("db.txt",ios::app);// for output opration
    string rn,name,div,add;
    cout<<"Enter student rollno: ";
    cin>>rn;
    cout<<"Enter student name: ";
    cin>>name;
    cout<<"Enter student division: ";
    cin>>div;
    cout<<"Enter student address: ";
    cin>>add;
    //the left is done for left alignment 
    f<<left<<setw(20)<<rn<<setw(20)<<name<<setw(20)<<div<<setw(20)<<add<<endl;// for output
    cout<<"Student added sucessfully"<<endl;
    f.close();
}
void deletestudent()
{
    ifstream f("db.txt");
    string line;

    string rn;
    cout<<"Enter the rollno to delete:";
    cin>>rn;
    bool found=false;
    string filedata;
    while(getline(f,line)){
        if(line.find(rn)==string::npos){/// npos is non position
            filedata+=line;// add the data not to be deleted
            filedata+="\n";
        }
        ofstream f1("db.txt",ios::out);// outputting the rest of the data
        f1<<filedata<<endl;
        f1.close();
    }   
    if(!found){
        cout<<"student doesn't exit"<<endl;
    }
    f.close();
}
void searchstudent()
{
    ifstream f("db.txt");
    string line;

    string rn;
    cout<<"Enter the rollno:";
    cin>>rn;
    bool found=false;
    while(getline(f,line)){
        // checking if rn is in that line or not
        if(line.find(rn)!=string::npos){/// npos is non position i.e not in the line
            cout<<"student details:"<<endl;
            cout<<line<<endl;
            found=true;
            break;
        }
    }   
    if(!found){
        cout<<"student doesn't exit"<<endl;
    }
    f.close();
}
void printdata()
{
    ifstream f("db.txt");// we are taking input from file
    string line;
    cout<<"Printing file data......"<<endl;
    while(getline(f,line))  {
        cout<<line<<endl;
    } 
    cout<<"Printing complete!"<<endl;
    f.close();
}
int main(){
    int ch=10;
    ofstream f("db.txt",ios::out);//clearing the data
    f<<left<<setw(20)<<"Roll.no"<<setw(20)<<"Name"<<setw(20)<<"Division"<<setw(20)<<"Address"<<endl;// for the heading
    f.close();

    while(ch!=0){
        cout<<"Enter 1 for add"<<endl;
        cout<<"Enter 2 for delete"<<endl;
        cout<<"Enter 3 for search"<<endl;
        cout<<"Enter 4 for print"<<endl;
        cout<<"Enter 0 for exit"<<endl;
        cout<<"Enter your choice: ";
        int ch;
        cin>>ch;
        if(ch==1){
            addstudent();
        }
        else if(ch==2){
            deletestudent();
        }
        else if(ch==3){
            searchstudent();
        }
        else if(ch==4){
            printdata();
        }
        else{
            break;
        }
    }
}
