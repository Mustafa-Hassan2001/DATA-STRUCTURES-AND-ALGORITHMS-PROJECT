//Assalamoalikum For Log-in 	
//Username : Mustafa
//password : 1234 

//===================== Start of Header Files ================

#include <iostream>
#include <string>
#include<iomanip> // It defines the manipulator functions setbase() , setfill() and setw()
#include<time.h>  // time() function in C++ returns the current calendar time as an object of type time_t
#include<stdlib.h> // It includes functions involving memory allocation, process control, conversions
#include<ctype.h>  //declares a set of functions to classify (and transform) individual characters. For example, isupper()
#include<process.h>
#include <conio.h>
#include<windows.h>
#include <malloc.h>
#include "Libary Student.h"
#include "libary Admin.h"
#include "Employ.h"
#include "Contact_book.h"
#include "Canteen.h"
#include "Booking.h"

//===================== Start of Header Files ================

using namespace std;

//Concept of enum	
enum week{Sunday , Monday, Tuesday, Wednesday, Thursday,Friday, Saturday};	  
enum month{January, Febuary, March, April, May, June, July, August, September, October, November, December};


//To Display Date on Screen
void date(){
  time_t T= time(NULL);
  struct  tm tm = *localtime(&T); //it can use by time.h header file inn which struct is tm is by default to show date
  cout<<endl<<endl<<endl;
  printf("\t\t\t\t\t   Date :: %02d/%02d/%04d\n\t",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
  
}

//To give delay to load Login System
void delay(unsigned int mseconds){		//it calculate the 24 hours by secound and update the date in display every day
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//If Invalid Attempts will exceed the 3 then 
void callExit(){
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t");
    fflush(stdin);
    printf("You are out of the System.");
    printf("\n\n");
    printf("\t\t\t\t");
    printf("   Press Enter to Continue Exit Program...");
    getchar();
    exit(0);
}


void mainpage(){
  int process=0;
  system("cls");
  system("color 0B");		//D E
  date();
  cout<<endl;
  printf("\t\t\t\t  ------------------------------------\n");
  printf("\t\t\t\t      || HOSTEL MANAGEMENT SYSTEM ||\n");
  printf("\t\t\t\t  ------------------------------------\n");
  cout<<endl<<endl<<endl;
  printf("\t\t\t\t");
  printf("Prepared By    :");
  printf("  Syed Mustafa Hassan");
  printf("\n\n");
  printf("\t\t\t\t");
  printf("Mini Project   :");
  printf("  Hostel Management System");
  printf("\n\n");
  printf("\t\t\t\t");
  printf("\n\n");
  printf("\t\t\t\t    Press Enter to continue......");
  printf("\n\n");
  getchar();
  printf("\t\t\t\tLoading");

  for(process=0;process<25;process++){
    delay(150);
    printf(".");
  }
}

void  logscreen(){	
  char username[30];
  char password[30];
  int chances = 0;
  int flag = 1;
  
  do{  	
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t");
    printf("Username: ");
    scanf("%s",username);
    printf("\t\t\t\t\t");
    printf("\n");
    printf("\t\t\t\t\t");
    printf("Password: ");
    scanf("%s",password);
    if(strcmp(username,"Mustafa")==0 && strcmp(password,"1234")==0)
      {
        printf("\n\n");
        printf("\t\t\t\t");
        printf("You are accessed to the system!\n\n");
        printf("\t\t\t\t   Press Enter to continue...");
        fflush(stdin);
        getchar();

        system("cls");
        getchar();
        flag =0;
      }
      else
      {
        system("cls");
        chances = chances+1;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t");
        printf("No. of attempts remain: %d",3-chances);
        fflush(stdin);
        getchar();
        if(chances>=3)
        {

          printf("\t\t\t\t\t\t");
          printf("\n");
          printf("\t\t\t\t");
          printf("   No permission to enter the system!" );
          getchar();
          callExit();
          getchar();
      
      }
  } //END OF ELSE
 }
 while(true==1);
}



void adminlogin(){
	int opt;
	menu:
	cout<<"\n\t\t\t\t\t\tWELCOME ADMIN"<<endl;	
	cout<<"\n\t\t\t\t\t\t1-> Check Rooms"<<endl;
	cout<<"\n\t\t\t\t\t\t2-> Check Libary"<<endl;
	cout<<"\n\t\t\t\t\t\t3-> Check Employees"<<endl;
	cout<<"\n\t\t\t\t\t\t4-> Check Contact Book"<<endl;
	cout<<"\n\t\t\t\t\t\t5-> Check Canteen"<<endl;
	cout<<"\n\t\t\t\t\t\tEnter Your Option : ";
	cin>>opt;
	switch(opt){
		case 1:{
			system("cls");
			Booking bookings;
			bookings.BookingMenu();
			goto menu;
			break;
		}
		case 2:{
			system("cls");
			AdminLibarymenu();
			break;
		}
		case 3:{
			system("cls");
			employ e;
			e.Employmain();
			break;
		}
		case 4:{
			system("cls");
			ContactBook c1;
			c1.contactBookmenu();
			break;
		}
		case 5:{
			system("cls");
			Canteen c2;
			c2.admin();
			break;
		}
        default:
            cout << "Invalid choice.  Enter again.\n\n";
            break;			
	}
}

void paybill(){
			int Taxis = 550;
			int days, nights, total,cardno,code,opt,recivedamount,balance;
			string name;
			cout<<"Enter Your Name : ";
			cin>>name;
			cout<<"\n\t\t\t\t\t\tEnter how many day's you Stay : ";
			cin>>days;
			cout<<"\n\t\t\t\t\t\tEnter how many nights's you Stay : ";
			cin>>nights;
			total = (days+nights)*3000+Taxis;
			cout<<"\n\t\t\t\t\t\tYou Total Payment : "<<total;
			cout<<"How do you want to pay Card(1) or Cash(2) : ";
			cout<<opt;
			if(opt==1){
				cout<<"Enter Card Number : ";
				cin>>cardno;
				cout<<"Enter code : ";
				cin>>code;
				cout<<"Thank For "<<name<<" your Time your dues are clear now you can take you card !! Have a Nice Day..."<<endl; 
			}  
			else if(opt==2){
				pay:
				cout<<"Enter the amount : ";
				cin>>recivedamount;
				if(recivedamount < total){
					cout<<"Please Enter the complete amount !!"<<endl;
					goto pay;
				}
				else if(recivedamount >= total){
				balance = total - recivedamount;
				if(balance < 0 ){
					balance = -1 * (balance);
					cout<<"Thank For "<<name<<" your Time your dues are clear please take you balance  "<<balance<<"  !! Have a Nice Day..."<<endl; 
					}
				else{
					cout<<"Thank For "<<name<<" your Time your dues are clear please take you balance  "<<balance<<"  !! Have a Nice Day..."<<endl;
				}	
		}
				
	}
}

void Receptionistlogin(){
	int opt;
	cout<<"\n\t\t\t\t\t\tWELCOME RECEPTIONIST"<<endl;
	cout<<"\n\t\t\t\t\t\t1-> Check Room Booking"<<endl;
	cout<<"\n\t\t\t\t\t\t2-> Goto Canteen"<<endl;
	cout<<"\n\t\t\t\t\t\t3-> Goto Libary"<<endl;
	cout<<"\n\t\t\t\t\t\t4-> Check Contact Book"<<endl;
	cout<<"\n\t\t\t\t\t\t5-> Recive Payment"<<endl;
	cout<<"\n\t\t\t\t\t\tEnter Your Option : ";
	cin>>opt;
	switch(opt){
		case 1:{
			system("cls");
			Booking bookings;
			bookings.BookingMenu();
			break;
		}
		case 2:{
			system("cls");
			Canteen c2;
			c2.customer();
			break;
		}
		case 3:{
			system("cls");
			main_menu();
			break;
		}
		case 4:{
			system("cls");
			ContactBook c1;
			c1.contactBookmenu();
			break;
		}
		case 5:{
			system("cls");
			paybill();
			break;
		}
        default:
            cout << "Invalid choice.  Enter again.\n\n";
            break;	
	}
}


void studentlogin(){
	int opt;
	
	cout<<"\n\t\t\t\t\t\tWELCOME STUDENT"<<endl;
	cout<<"\n\t\t\t\t\t\t1-> Goto Canteen"<<endl;
	cout<<"\n\t\t\t\t\t\t2-> Goto Libary"<<endl;
	cout<<"\n\t\t\t\t\t\t3-> Check Contact Book"<<endl;
	cout<<"\n\t\t\t\t\t\t4-> Recive Payment"<<endl;
	cout<<"\n\t\t\t\t\t\tEnter Your Option : ";
	cin>>opt;
	switch(opt){
		case 1:{
			system("cls");
			Canteen c2;
			c2.customer();
			break;
		}
		case 2:{
			system("cls");
			main_menu();
			break;
		}
		case 3:{
			system("cls");
			ContactBook c1;
			c1.contactBookmenu();
			break;
		}
		case 4:{
			system("cls");
			paybill();
			break;
		}
        default:
            cout << "Invalid choice.  Enter again.\n\n";
            break;		
	}
}



void Mainmenu(){
	int opt;
	cout<<"\n\t\t\t\t\t\t1-> Admin "<<endl;
	cout<<"\n\t\t\t\t\t\t2-> Receptionist"<<endl;
	cout<<"\n\t\t\t\t\t\t3-> Student"<<endl;
	cout<<"\n\t\t\t\t\t\tEnter your Option : ";
	cin>>opt;
	switch(opt){
		case 1:{
			system("cls");
			adminlogin();
			break;
		}
		case 2:{
			system("cls");
			Receptionistlogin();
			break;
		}
		case 3:{
			system("cls");
			studentlogin();
			break;
		}
        default:
            cout << "Invalid choice.  Enter again.\n\n";
            break;			
	}
}

int main() {
	start_lib=initialize_lib(start_lib);
	mainpage();
	system("cls");
	Mainmenu();

 return 0;
}
