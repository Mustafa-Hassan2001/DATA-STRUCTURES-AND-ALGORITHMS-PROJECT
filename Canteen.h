#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

using namespace std;

//This file is of canteen class which haveing two Doubly Linked List 
//one is for Admin List
//secound of customer List

//Concepts of Doubly Linked List

//Start Structure of Doubly Linked List
struct NODE{		
    char foodname[50];
    int quantity;
    float price;
    int data;
    struct NODE *prev;
    struct NODE *next;
};
//End Structure of Doubly Linked List


//Nodes of Doubly Linked List
struct NODE *headc = NULL,*newnode,*tailc = NULL;
struct NODE *heada = NULL, *taila = NULL;
struct NODE *head_s;
//headc = head of customer
//tailc = tail of customer
//heada = head of Admin
//taila = tail of Admin

//Start of Function that create a Doubly Linked List of Admin
struct NODE* createadmin(struct NODE *head,int data, char foodname[25], float price){
    newnode = new NODE;
    newnode->data = data;
    newnode->price = price;
    newnode-> quantity = 0;
    strcpy(newnode->foodname,foodname);
    newnode->next = NULL;
    newnode->prev = NULL;

    struct NODE *temp = head;

    if(temp==NULL)			//if the list is empty then head contains the data that comes first
        heada = taila = newnode;
    else{
        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=newnode;
        newnode->prev = taila;
        taila = newnode;
    }
    return heada;
}
//End of Function that create a Doubly Linked List of Admin


//Start of Function that create a Doubly Linked List of Customer
struct NODE* createcustomer(struct NODE *head,int data,int quantity){
    newnode = new NODE;
    struct NODE *temp1 = heada;
    int flag = 0;
    while(temp1!=NULL){
        if(temp1->data==data){
            flag = 1;
            break;
        }
        temp1 = temp1->next;
    }
    if(flag==1){			//if the list is empty then head contains the data that comes first
        newnode->data = data;
        newnode->price = quantity*(temp1->price);
        newnode-> quantity = quantity;
        strcpy(newnode->foodname,temp1->foodname);
        newnode->next = NULL;
        newnode->prev = NULL;
        struct NODE *temp = head;
        if(temp==NULL)
            headc = tailc = newnode;
        else{
            while(temp->next!=NULL)
                temp=temp->next;

            temp->next=newnode;
            newnode->prev = tailc;
            tailc = newnode;
        }
    }
    else{
        cout<<"\n\t\t\t\t\t\t\t This item is not present in the menu! \n";
    }
    return headc;
}
//End of Function that create a Doubly Linked List of customer


//Start of Canteen Class 
class Canteen{
	public:

//	Menu for admin
void adminmenu(){
	cout<<endl;
    cout<<"\t\t\t\t\t\t\t1. View total sales\n";
    cout<<"\t\t\t\t\t\t\t2. Add new items in the order menu\n";
    cout<<"\t\t\t\t\t\t\t3. Delete items from the order menu\n";
    cout<<"\t\t\t\t\t\t\t4. Display order menu\n";
    cout<<"\t\t\t\t\t\t\t5. Back To Main Menu \n\n";
    cout<<"\t\t\t\t\t\t\t Enter Your Choice : ";
}

// mENU for customer
void customermenu(){
	cout<<endl;
    cout<<"\t\t\t\t\t\t\t1. Place your order\n";
    cout<<"\t\t\t\t\t\t\t2. View your ordered items\n";
    cout<<"\t\t\t\t\t\t\t3. Delete an item from order\n";
    cout<<"\t\t\t\t\t\t\t4. Display final bill\n";
    cout<<"\t\t\t\t\t\t\t5. Back To Main Menu \n\n";
    cout<<"\t\t\t\t\t\t\t   Enter Your Choice : ";
}

//Display function that can displlay data of both list (i.e: admin list , customer list)
void displayList(struct NODE *head){
    struct NODE *temp1 = head;
    if(temp1==NULL){	//if the list is empty
        cout<<"\n\t\t\t\t\t\t\t List is empty!!\n\n";
    }
    else{		//if list is not empty
        cout<<endl;
        while(temp1!=NULL){
            if(temp1->quantity==0)
                cout<<"\n\t\t\t\t\t\t\t"<<temp1->data<<" for "<<temp1->foodname<<"  "<<temp1->price<<endl;
            else{
                cout<<"\n\t\t\t\t\t\t\t"<<temp1->data<<" for "<<temp1->foodname<<"  "<<temp1->quantity<<"  "<<temp1->price;
            }
            temp1 = temp1->next;
        }
        cout<<endl;
    }
}

// Start Funtion that count the total sales of canteen that can admin see 
struct NODE* totalsales(int data,int quantity){
    newnode = new NODE;
    int flag = 0;
    struct NODE *temp1 = heada;
    while(temp1->data!=data){
        temp1 = temp1->next;
    }

    newnode->data = data;
    newnode->price = quantity*(temp1->price);
    newnode-> quantity = quantity;
    strcpy(newnode->foodname,temp1->foodname);
    newnode->next = NULL;
    newnode->prev = NULL;

    struct NODE *temp = head_s;

    if(temp==NULL)
        head_s = newnode;
    else{
        while(temp->next!=NULL){
            if(temp->data==data){
                flag = 1;
                break;
            }
            temp=temp->next;
        }

        if(flag==1){
            temp->quantity += newnode-> quantity;
            temp->price += newnode->price;
        }
        else{
            temp->next=newnode;
        }
    }
    return head_s;
}
// End Funtion that count the total sales of canteen that can admin see 

// Start Funtion that calculates the total sales of canteen that can admin see 
void calculatetotsales(){
    struct NODE *temp = headc;
    while(temp!=NULL){
        head_s = totalsales(temp->data, temp->quantity);
        temp=temp->next;
    }
}
// End Funtion that calculates the total sales of canteen that can admin see 


// Start Funtion that delete the node from any side of list  
struct NODE* Delete(int data,struct NODE *head, struct NODE* tail){
    if(head==NULL){
        cout<<"\n\t\t\t\t\t\t\t List is empty\n";
    }
    else{
        struct NODE* temp;
        if(data == head->data){
            temp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            free(temp);
        }
        else if(data==tail->data){
            temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }
        else{
            temp = head;
            while(data!=temp->data){
                temp = temp->next;
            }
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            free(temp);
        }
    }
    return head;
}
// Start Funtion that delete the node from any side of list  

//this function delete the data from admin list
int deleteadmin(){
	int num;
    
	cout<<"\n\t\t\t\t\t\t\t Enter serial no. of the food item which is to be deleted: ";
    cin>>num;

    struct NODE* temp= heada;
    
    while(temp!=NULL){
        if (temp->data == num){
            heada = Delete(num, heada, taila);
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

//this function delete the data from customer list
int deletecustomer(){
	int num;
    
	cout<<"\n\t\t\t\t\t\t\t Enter serial no. of the food item which is to be deleted: ";
    cin>>num;
    
    struct NODE* temp=headc;
    
	while(temp!=NULL){
        if (temp->data == num){
            headc = Delete(num, headc, tailc);
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

//This function show the total bill to user
void displaybill(){
//	date();
    displayList(headc);
    struct NODE *temp = headc;
    float total_price = 0;
    while (temp!=NULL){
        total_price +=temp->price;
        temp = temp->next;
    }
    cout<<"\t\t\t\t\t\t\t Total price: "<<total_price<<endl;
}

struct NODE* deleteList(struct NODE* head){
    if(head==NULL){
        return NULL;
    }
    else{
        struct NODE* temp = head;
        while(temp->next!=0){
            temp = temp->next;
            free(temp->prev);
        }
        free(temp);
        head = NULL;
    }
    return head;
}

//This function that show the menu of admin functions
void admin(){
	int opt;
    cout<<"\n\t\t\t\t\t   ----------------------------------------------\n";
    cout<<"\t\t\t\t\t\t\t    ADMIN SECTION\n";
    cout<<"\t\t\t\t\t   ----------------------------------------------\n";
    while(1){
	    adminmenu();
        
		cin>>opt;

        if(opt==5){
        	system("cls");
            break;
        }

        switch (opt){
            case 1:
            	system("cls");
                displayList(head_s);
                break;
            case 2:{
            	system("cls");
                cout<<"\n\t\t\t\t\t\t\t Enter serial no. of the food item: ";
    			int num,flag = 0;
                char name[50];
                float price;
                cin>>num;
                struct NODE *temp = heada;
                while(temp!=NULL){
                    if(temp->data==num){
                        cout<<"\t\t\t\t\t\t\t Food item with given serial number already exists!!\n\n";
                        flag = 1;
                        break;
                    }
                    temp = temp->next;
                }
                if(flag==1)
                    break;

                cout<<"\t\t\t\t\t\t\t Enter food item name: ";
                cin>>name;
                cout<<"\t\t\t\t\t\t\t Enter price: ";
                cin>>price;
                heada = createadmin(heada, num, name, price);
                cout<<"\t\t\t\t\t\t\t New food item added to the list!!\n\n";
                break;
            }
            case 3:{
            	system("cls");
                if(deleteadmin()){
                    cout<<"\t\t\t\t\t\t\t ### Updated list of food items menu ###\n";
                    displayList(heada);
                }
                else
                    cout<<"\n\t\t\t\t\t\t\t Food item with given serial number doesn't exist!\n\n";
					break;
			}            
			case 4:{
				system("cls");
                cout<<"\n\t\t\t\t\t\t\t ### Order menu ###\n";
                displayList(heada);
                break;
			}
            default:
                cout<<"\n\t\t\t\t\t\t\t Wrong Input !! PLease choose valid option\n";
                break;
        }
    }
}

//This function that show the menu of customer functions
void customer(){
    int flag=0,j=1;
    char ch;
    cout<<"\n\t\t\t\t\t   ----------------------------------------------\n";
    cout<<"\t\t\t\t\t\t\t    CUSTOMER SECTION\n";
    cout<<"\t\t\t\t\t   ----------------------------------------------\n";
    while(1){
        customermenu();
        int opt;
        cin>>opt;

        if(opt==5){
			system("cls");
            break;
			}

        switch (opt){
            case 1:
            	system("cls");
                displayList(heada);
                cout<<"\n\t\t\t\t\t\t\t Enter number corresponding to the item you want to order: ";
                int n;
                cin>>n;
                cout<<"\t\t\t\t\t\t\t Enter quantity: ";
                int quantity;
                cin>>quantity;
                headc = createcustomer(headc, n, quantity);
                break;
            case 2:
            	system("cls");
                cout<<"\n   ### List of ordered items ###\n";
                displayList(headc);
                break;
            case 3:
            	system("cls");
                if(deletecustomer()){
                    cout<<"\n\t\t\t\t\t\t\t ### Updated list of your ordered food items ###\n";
                    displayList(headc);
                }
                else
                    cout<<"\n\t\t\t\t\t\t\t Food item with given serial number doesn't exist!!\n";
                break;
            case 4:
            	system("cls");
                calculatetotsales();
                cout<<"\n\t\t\t\t\t\t\t ### Final Bill ###\n";
                displaybill();
                headc = deleteList(headc);
                cout<<"\n\t\t\t\t\t\t\t  Press any key to return to main menu: \n";
                fflush(stdin);
                ch=fgetc(stdin);
                flag=1;
                break;

            default:
                cout<<"\n\t\t\t\t\t\t\t Wrong Input !! PLease choose valid option\n";
                break;
        }
        if(flag==1)
            break;
    }
}
//Main Function 
void mainnenu(){
    cout<<"\n                                 **************************************************************************\n";
    cout<<"                                                     WELCOME TO MAJU HOSTEL CANTEEN\n";
    cout<<"                                 **************************************************************************\n\n\n";
    cout<<"\t\t\t\t\t\t\t1. ADMIN SECTION \n";
    cout<<"\t\t\t\t\t\t\t2. CUSTOMER SECTION \n";
    cout<<"\t\t\t\t\t\t\t3. Exit \n\n";
    cout<<"\t\t\t\t\t\t\tEnter Your Choice : ";
}

//This function is the Menu of canteen items
void CanteenMenu(){
	Canteen c;
    heada = createadmin(heada,1,"Hot and Sour Soup",100);
    heada = createadmin(heada,2,"Manchow Soup",200);
    heada = createadmin(heada,3,"Manchurian Noodles",150);
    heada = createadmin(heada,4,"Fried Rice",180);
    heada = createadmin(heada,5,"Hakka Noodles",80);

    while(1){
        c.mainnenu();
        int choice;
        cin>>choice;

        switch (choice){
            case 1:
            	system("cls");
                c.admin();
                break;
            case 2:
            	system("cls");
                c.customer();
                break;
            case 3:
            	system("cls");
            	cout<<"\n\n\t\t\t\t\t\t\t **********Thank you!!**********\n";
                exit(1);
                exit(1);

            default:
                cout<<"\n\t\t\t\t\t\t\t Wrong Input !! PLease choose valid option\n ";
                break;
        }
    }
}
};
//End of Canteen Class 
