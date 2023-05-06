#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

using namespace std;

//This file is of book class of libary for function of student which haveing two singly Linked List 
//This file contacts the File Handling, typedef also this file haveing queue
//one is for book List
//secound of student List

//Concepts of singly Linked List
//Start Structure of singly Linked List
struct book{
    char name[30];
    char author[30];
    int id;
    struct book *next;
};

//Start Structure of singly Linked List to store the data for student who ssue the book
struct student{
    char name[30];
    char email[20];
    char book[20];
    char a[30];
    int id;
    struct student *next;
};

//All function decleration 
struct book *start_lib=NULL;
struct student *start=NULL;
struct book *initialize_lib(struct book *);
struct student *book_issue(struct student *);
struct student *book_return(struct student *);
struct book *diplay_lib(struct book *);
struct book *delete_book(int);
struct book *add_book(char [],char [],int);
void display(struct student *);
void greetings();
void main_menu();

//Main menu of this class that haveing the functions of libary class 
void main_menu(){
    int choice;
    do{
        cout<<"\n\n";
        cout<<"\n\t\t\t*************************************************\n";
        cout<<"\n\t\t\t\t      MAIN MENU: ";
        cout<<"\n\t\t\t\t     1.ISSUE OF BOOKS ";
        cout<<"\n\t\t\t\t     2.RETURN OF BOOKS ";
        cout<<"\n\t\t\t\t     3.DISPLAY STUDENT DETAILS ";
        cout<<"\n\t\t\t\t     4.EXIT\n ";
        cout<<"\n\t\t\t*************************************************\n";
        cout<<"\n\t\t\t\t      Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                start=book_issue(start);
                break;
            }
            case 2:{
            	system("cls");
                start=book_return(start);
                break;
            }
            case 3:{
            	system("cls");
                display(start);
                break;
            }
            case 4:{
                exit(1);
            }
            default:{
                cout<<"\n\t\t\t\t      ...Invalid Option!...\n";
                cout<<"\n\t\t\t\t      Press any key to try again: ";
                getch();
            }
        }
    }while(choice!=4);
}


struct book *initialize_lib(struct book *start){
	
    struct book *ptr,*new_book1,*new_book2,*new_book3,*new_book4,*new_book5;
    new_book1=(struct book *)malloc(sizeof(struct book));
    new_book1->next=NULL;
    start_lib=new_book1;
    strcpy(new_book1->name,"C++ All-in-One ");
    strcpy(new_book1->author,"Khaled Dummies");
    new_book1->id=101;
    ptr=new_book1;

    new_book2=(struct book*)malloc(sizeof(struct book));
    new_book2->next=NULL;
    strcpy(new_book2->name,"Let Us C");
    strcpy(new_book2->author,"Harper Lee");
    new_book2->id=102;
    ptr->next=new_book2;
    ptr=new_book2;

    new_book3=(struct book*)malloc(sizeof(struct book));
    new_book3->next=NULL;
    strcpy(new_book3->name,"Let Us C++");
    strcpy(new_book3->author,"Paulo Coelho");
    new_book3->id=103;
    ptr->next=new_book3;
    ptr=new_book3;

    new_book4=(struct book*)malloc(sizeof(struct book));
    new_book4->next=NULL;
    strcpy(new_book4->name,"Python And Prejudice");
    strcpy(new_book4->author,"Jane Austen");
    new_book4->id=104;
    ptr->next=new_book4;
    ptr=new_book4;

    new_book5=(struct book*)malloc(sizeof(struct book));
    new_book5->next=NULL;
    strcpy(new_book5->name,"A Tale Of Two Cities");
    strcpy(new_book5->author,"Charles Dickens");
    new_book5->id=105;
    ptr->next=new_book5;

    return start_lib;
}

struct student *book_issue(struct student *start){
    struct book *ptr;
    struct student *ptr2,*new_student;
    int i=1,id,flag=0;
    if(start_lib==NULL){
        cout<<"\n\t\t\t\t No books left in the library to issue!\n\t\t\t\t Sorry for the inconvenience!\n";
    }else{
        system("cls");
        ptr=start_lib;
        cout<<"\n\t*************** Books Available: ****************\n";
        while(ptr!=NULL){
            cout<<"\n\t_________________________________________________\n";
            cout<<"\n\t Book : "<<i;
            cout<<"\n\t Book Title: "<<ptr->name;
            cout<<"\n\t Name of Author: "<<ptr->author;
            cout<<"\n\t Book ID: "<<ptr->id;
            cout<<"\n\t_________________________________________________\n";
            ptr=ptr->next;
            i++;
        }
        cout<<"\n\n\t Enter the Book ID: ";
        cin>>id;
        ptr=start_lib;
        while(ptr!=NULL){
            if(ptr->id==id){
                flag=1;
                break;
            }
            ptr=ptr->next;
        }
        if(flag==1){
            ptr=start_lib;
            while(ptr->id!=id){
                ptr=ptr->next;
            }
            new_student=(struct student *)malloc(sizeof(struct student));
            cout<<"\n\t Enter Student Details \n ";
            cout<<"\n\t Enter your Name : ";
            cin>>new_student->name;
            cout<<"\n\t Enter your Email : ";
            cin>>new_student->email;
            strcpy(new_student->book,ptr->name);
            strcpy(new_student->a,ptr->author);
            new_student->id=ptr->id;
            new_student->next=NULL;
            cout<<"\n\t Issue of Book done successfully! ID : "<<new_student->id<<endl;
            cout<<"\n\n\t*************************************************\n";
            if(start==NULL){
                start=new_student;
            }else{
                ptr2=start;
                while(ptr2->next!=NULL){
                    ptr2=ptr2->next;
                }
                ptr2->next=new_student;
            }
            start_lib=delete_book(new_student->id);
            cout<<"\n\n\t Press any key to go to the main menu: ";
            getch();
            system("cls");
        }else{
            cout<<"\n\t\t      ...Invalid Option!...\n";
            cout<<"\n\t\t      Press any key to try again: ";
            getch();
            system("cls");
        }
    }
    return start;
}

struct student *book_return(struct student *start){
    struct student *ptr,*preptr;
    char bookname[30],authorname[30];
    int flag=0,id,identity,c=0,d=1;
    cout<<"\n\n\t*************** Books Submission: ****************\n";
    cout<<"\n\n\t Enter your Book ID : ";
    cin>>identity;
    ptr=start;
    while(ptr!=NULL){
        if(ptr->id==identity){
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==1){
        ptr=start;
        while(ptr!=NULL){
            c++;
            ptr=ptr->next;
        }
        ptr=start;
        while(ptr->id!=identity){
                d++;
            ptr=ptr->next;
        }
        ptr=start;
        if( d==1 ){
            cout<<"\n\t_________________________________________________\n";
            cout<<"\n\t Student Name: "<<start->name;
            cout<<"\n\t Student Email: "<<start->email;
            cout<<"\n\t Name of Book Issued: "<<start->book;
            cout<<"\n\t_________________________________________________\n";
            cout<<"\n\n\t Return of Book ID done successfully!\n",identity;
            cout<<"\n\n\t*************************************************\n";
            strcpy(bookname,start->book);
            strcpy(authorname,start->a);
            id=start->id;
            start=start->next;
            free(ptr);
            add_book(bookname,authorname,id);
        }else{
            ptr=start;
            while(ptr->id!=identity){
                preptr=ptr;
                ptr=ptr->next;
            }
            cout<<"\n\t_________________________________________________\n";
            cout<<"\n\t Student Name: "<<ptr->name;
            cout<<"\n\t Student Email: "<<ptr->email;
            cout<<"\n\t Name of Book Issued: "<<ptr->book;
            cout<<"\n\t Book ID: "<<ptr->id;
            cout<<"\n\t_________________________________________________\n";
            strcpy(bookname,ptr->book);
            strcpy(authorname,ptr->a);
            id=ptr->id;
            preptr->next=ptr->next;
            free(ptr);
            add_book(bookname,authorname,id);
        }
        cout<<"\n\t Thank you! ";
        cout<<"\n\n\t Press any key to go to the main menu: ";
        getch();
        system("cls");
    }else{
        cout<<"\n\tSorry the book doesn't exist! Please Recheck the entered ID";
        cout<<"\n\t\t\t\t      Press any key to try again: ";
        getch();
        system("cls");
    }
    return start;
}

//concept of  Merge Sort
//Start Merge Sort
void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    int i, j, k;
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    
	while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}
//End Merge Sort

void display(struct student *start){
    struct student *ptr;
    ptr=start;
    while(ptr!=NULL){
        cout<<"\n\t************* Details of Students: **************\n";
        cout<<"\n\t_________________________________________________\n";
        cout<<"\n\t\t Student Name: %s",ptr->name;
        cout<<"\n\t\t Student Email: %s",ptr->email;
        cout<<"\n\t\t Name of Book Issued: %s",ptr->book;
        cout<<"\n\t\t Book ID: %d",ptr->id;
        cout<<"\n\t_________________________________________________\n";
        cout<<"\n\n\t*************************************************\n";
        ptr=ptr->next;
    }
    cout<<"\n\n\t Press any key to go to the main menu: ";
    getch();
    system("cls");
}

struct book *delete_book(int id){
    struct book *ptr,*preptr;
    int c=0;
    ptr=start_lib;
    while(ptr!=NULL){
        c++;
        ptr=ptr->next;
    }
    if(c==1){
        ptr=start_lib;
        start_lib=NULL;
        free(ptr);
    }else if(start_lib->id==id){
        ptr=start_lib;
        start_lib=start_lib->next;
        free(ptr);
    }else{
        ptr=start_lib;
        while(ptr->id!=id){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
    return start_lib;
}

struct book *add_book(char bookname[30],char authorname[30],int id){
    struct book *ptr,*new_book;
    new_book=(struct book *)malloc(sizeof(struct book));
    strcpy(new_book->name,bookname);
    strcpy(new_book->author,authorname);
    new_book->id=id;
    new_book->next=NULL;
    if(start_lib==NULL){
        start_lib=new_book;
    }else{
        ptr=start_lib;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=new_book;
    }
    return start_lib;
}
