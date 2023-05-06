#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

//This file is of booking class that book a room for admin, customer, employees of hostel 
//which haveing Circular Doubly Linked List & also haveing try throw & catch functions 
// this class haveing 3 floors & 9 rooms in each floor  (48 rooms).

//Concepts of Circular Doubly Linked List
//Start Structure of Circular Doubly Linked List
struct NodE{
    int NUMBER = 1;
    int fill = 0;
    char CUS_NAMES[3][10];
    NodE *NXT;
    NodE *PREVIOUS;
};

//Start of booking class
class Booking{
   public:      
    NodE *TITLE[3];
    NodE *WORDS;
	//constructor of booking class
    Booking(){
        for (int x = 0; x < 3; x++)
            TITLE[x] = NULL;
    }
    // create function of duobly linked list & booking of rooms in hostel that
	// haveing 3 floors & 9 rooms in each floor (48 rooms)
    void create(){
        for (int x = 0; x < 3; x++){
            for (int y = 0; y < 9; y++){
                NodE *B = new NodE;
                B->NXT = NULL;
                B->PREVIOUS = NULL;
                if (TITLE[x] == NULL){
                    TITLE[x] = B;
                    B->NUMBER = 1;
                }
                else{
                   NodE *WORDS = TITLE[x];
                    while (WORDS->NXT != NULL){
                        WORDS = WORDS->NXT;
                    }
                    if (y == 3 || y == 5 || y == 7 || y == 8){
                        WORDS->NUMBER = 3;
                    }
                    if (y == 2 || y == 4 || y == 6){
                        WORDS->NUMBER = 2;
                    }
                    WORDS->NXT = B;
                    B->PREVIOUS = WORDS;
                }
            }
        }
    }
    //this function display the list in matrix (table) from with room status  
    void display(){
        int y = 0, z = 0, w = 0;
        for (int x = 0; x < 48; x++){
            cout << "~~";
        }
        cout << "\n ";
        for (int x = 1; x < 4; x++){
            cout << "| Floor number : "<< x << " \t\t";
        }
        cout << "|\n" ;
        for (int x = 0; x < 48; x++){
            cout << "~~";
        }
        WORDS = TITLE[y];
        NodE *s = TITLE[y + 1];
        NodE *t = TITLE[y + 2];
        cout << "\n ";
        while (WORDS != NULL){
            if (WORDS->fill != WORDS->NUMBER && WORDS->NUMBER != 0){
                y++;
                cout << "| Room no : "<< y;
                cout << "->Vacant cots->"<< WORDS->NUMBER;
            }
            else{
                y++;
                cout << "| Room no : "<< y;
                cout << "->Not Vacant";
            }
            if (s->fill != s->NUMBER && s->NUMBER != 0){
                z++;
                cout << "\t | Room no : "<< y;
                cout << "->Vacant cots->"<< s->NUMBER;
            }
            else{
                z++;
                cout << " \t | Room no : "<< y;
                cout << "->Present ";
            }
            if (t->fill != t->NUMBER && t->NUMBER != 0){
                w++;
                cout << "\t | Room no : "<< y;
                cout << "->Vacant cots->"<< t->NUMBER << "| ";
            }
            else{
                w++;
                cout << "\t | Room no : "<< y;
                cout << "->Not Vacant "<< " | ";
            }
            cout << " \n ";
            for (int x = 0; x < 48; x++){
                cout << "--" ;
            }
            cout << "\n ";
            WORDS = WORDS->NXT;
            s = s->NXT;
            t = t->NXT;
        }
    }
    //This function that book a room fro admin, student, employees
    void booking(int people){
        int fl, rom;
        cout << "\n Enter the floor number : ";
        cin >> fl;
        
        try{	
            if (fl < 0 || fl > 4){
                throw(fl);
            }
            WORDS = TITLE[fl - 1];
            cout << "\n Enter the room number : ";
            cin >> rom;
            try{
                if (rom < 0 || rom > 10){
                    throw(rom);
                }
                else{
                    int x = 1;
                    while (x < rom){
                        WORDS = WORDS->NXT;
                        x++;
                    }
                    if (WORDS->NUMBER >= people){
                        cout << "\n Room is vacant you can apply for this Room "<<endl;
                        int count = 0;
                        while (WORDS->fill - 1 <= WORDS->NUMBER){
                            cout << "\n Enter name "<< WORDS -> fill + 1 << " : ";
                            cin >> WORDS->CUS_NAMES[WORDS->fill];
                            count++;
                            WORDS->fill++;
                            if (count >= people){
                                break;
                            }
                        }
                        WORDS->NUMBER = WORDS->NUMBER - people;
                    }

                    else{
                        cout << "\n Room is not vacant... SORRY !!!";
                    }
                }
            }
            catch (int r){
                cout << "\n Invalid Room number : "<< r;
            }
        }
        
      catch (int r){
            cout << " \n Invalid Floor number : " << r;
        }
    }
	//This function will cancelled the booked room of any person
    void cancelled(int check){
        char checking_namess[10];
        int fg = 0;
        int rms, x = 1;
        try{
            if (check < 0 || check > 4){
                throw(check);
            }
            else{
                cout << " Enter the room no : ";
                cin >> rms;
                try{
                    if (rms < 0 || rms > 10){
                        throw(rms);
                    }
                    else{
                        cout << " Enter the name to be delete :";
                        cin >> checking_namess;
                        WORDS = TITLE[check - 1];
                        while (x < rms){
                            WORDS = WORDS->NXT;
                            x++;
                        }
                        x = 0;
                        while (x < 3){
                            if (!strcmp(checking_namess, WORDS -> CUS_NAMES[x])){
                                fg = 1;
                                break;
                                x = 0;
                            }
                            else
                                x++;
                        }
                        if (fg == 1 && WORDS->fill != 0){
                            cout << "\n Record deleted : "<< WORDS -> CUS_NAMES[x];
                            WORDS->CUS_NAMES[x][0] ='A';
                            WORDS->CUS_NAMES[x][1] ='\0';
                            WORDS->fill--;
                            WORDS->NUMBER++;
                        }
                        else{
                            cout << "\n Record not present ";
                        }
                    }
                }
                
                catch (int r){
                    cout << "\n Invalid room number : " << r;
                }
            }
        }
        catch (int r){
            cout << " \n Floor dosn't exist : " << r;
        }
    }
    //This function will modyfy the data & can change the room & floor of any booked room  
    void modify(int check){
        char checking_namess[10];
        int rms, x = 1;
        try{
            if (check < 0 || check > 4){
                throw(check);
            }
            else{
                cout << " Enter the Room number : ";
                cin >> rms;
                try{
                    if (rms < 0 || rms > 10){
                        throw(rms);
                    }
                    else{
                        cout << " Enter the name to be updated :";
                        cin >> checking_namess;
                        WORDS = TITLE[check - 1];
                        while (x < rms){
                            WORDS = WORDS->NXT;
                            x++;
                        }
                        x = 0;
                        while (x < 3){
                            if (!strcmp(checking_namess, WORDS -> CUS_NAMES[x])){
                                cout << "\n Enter updated name : " ;
                                cin >> WORDS->CUS_NAMES[x];
                                break;
                            }
                            else
                                x++;
                        }
                        if (x >= 3)
                            cout << "Record not found "<<endl;
                        else{
                            cout << "\n Record updated \n Previous name : "<< checking_namess << "\n Updated name : "<< WORDS->CUS_NAMES[x];
                        }
                    }
                }
                catch (int r){
                    cout << "\n Invalid room number : "<< r<<endl;
                }
            }
        }
        catch (int r){
            cout << "\n Floor dosn't exist : "<< r<<endl;
        }
    }
    
    //Menu of the Booking Class 
void BookingMenu(){
    Booking bookings;
    int opt;
    char channels;
    int checking_floors;
    bookings.create();
    
   do{
        cout << "\n 1-> Book a room for Student \n 2-> Book a room for Admin \n 3-> Book a room for Staff \n 4-> Display the Current Status of Rooms \n 5-> Cancel a Booking\n 6-> Modify"<< endl;
        cout << " Enter your choice : "   ;
        cin >> opt;
        cout<<endl;
        switch (opt){
        case 1:
      {
         system ("CLS");
         cout<<"------------------------"<<endl;
         cout<<" Booking For Student"<<endl;
         cout<<"------------------------"<<endl;
            bookings.booking(1);
            break;
        }
        case 2:
        {
           system ("CLS");
           cout<<"------------------------"<<endl;
           cout<<" Booking For Admin"<<endl;
           cout<<"------------------------"<<endl;
            bookings.booking(2);
            break;
        }
        case 3:
        {
           system ("CLS");
           cout<<"------------------------"<<endl;
           cout<<" Booking For Staff"<<endl;
           cout<<"------------------------"<<endl;
            bookings.booking(3);
            break;
        }
        case 4:
        {
           system ("CLS");
            bookings.display();
            break;
        }
        case 5:
        { 
           system ("CLS");   
            cout << " Enter Floor number : ";
            cin >> checking_floors;
            bookings.cancelled(checking_floors);
            break;
        }
        case 6:
        {
           system ("CLS");
            cout << " Enter Floor number : ";
            cin >> checking_floors;
            bookings.modify(checking_floors);
            break;
        }

        default:
            cout << "\n Invalid choice "; 
        }
        cout << "\n Do you want to continue(Y / N) ";
        cin >> channels;
        system ("CLS");
    } while (channels =='Y'|| channels =='y');
}
};
//End of booking class
