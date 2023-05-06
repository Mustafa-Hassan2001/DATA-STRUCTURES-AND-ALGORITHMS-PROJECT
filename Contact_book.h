#include<iostream>
#include<fstream>
#include <sstream>
using namespace std;

//This file is of Contact Book class which haveing circular Doubly Linked List, 
//this list have just two data one is the name of contact and other is number
//This file contacts the File Handling with circular Doubly Linked List & bubble Sort with try throw & catch Functions 
 
//Concepts of Circular Doubly Linked List
//Start Structure of Circular Doubly Linked List
struct Node{
	string name;                
	long long int phone_number; 
	Node *next;
	Node *prev;
};

//Start of Contact Book List 
class ContactBook{
	Node *head;
	string name;
	long long int number;
	public:
		//constructor of ContactBook class
		ContactBook(){
			head=NULL;
			name="";
			number=0;
		}
		// create function of duobly linked list for store the number of name 
    	void CreateNode(){
	    	if(head==NULL){
    	    	Node *newer= new Node;
	    	   
			    cout<<"  Name of Contact : ";
		        cin>>name;
		        newer->name=name;

    		    cout<<"  Phone Number : ";
	    	    cin>>number;
		        newer->phone_number=number;
	
		        newer->next=NULL;
		        newer->prev==NULL;
		        head=newer;
		        
		        cout<<"  Contact Added"<<endl;
		    }
		    else{
		        Node *newer= new Node;
	    	    
				cout<<"  Name of Contact : ";
		        cin>>name;
		        newer->name=name;

    		    cout<<"  Phone Number : ";
	    	    cin>>number;
		        newer->phone_number=number;
		        
		        newer->next=NULL;
		        
		    	Node *temp=head;
		    	while(temp->next!=NULL){
		    		temp=temp->next;
		    	}
		    	temp->next=newer;
		    	newer->prev=temp;
		    	cout<<"  Contact Added"<<endl;
			}
		}
		//This Function display the data of List
    	void Display(){
	    	Node *temp=head;
	    	int count=0;
	    	
	    	if(temp==NULL){
		    	cout<<"  No Contacts... Please Add Some Contacts"<<endl;
		    	cout<<"  Thanks"<<endl;
	    	}
	    	else{
	    		BubbleSort();
	    		cout<<"  Name : "<<"      Number : \n"<<endl;
	        	while(temp!=NULL){
	        	    count++;
		        	cout<<"  "<<temp->name;
		        	cout<<"          "<<temp->phone_number<<endl;
    		    	temp=temp->next;		
	        	}
	        	cout<<"  Total contacts : "<<count<<endl;
	    	}
    	}
    	
		//This Function Search the data from List by name & number
    	int Search(){
    		bool check=false;
	    	Node *temp=head;
	    	cout<<"***********"<<endl;
	    	cout<<"  Press 1 if you want to Search By Name."<<endl;
	    	cout<<"  Press 2 if you want to Search By Number."<<endl;
	    	int command;
	    	cout<<"  Enter the Command: ";
	    	cin>>command;
	  
	    	if(command==1 && temp!=NULL){
	    		cout<<"  Enter the Name to Search : ";
	    		cin>>name;
		    	while(temp!=NULL){
		        	if(temp->name==name){
		        		cout<<"***********"<<endl;
		        		cout<<"  Name : "<<temp->name<<endl;
		        		cout<<"  Phone Number : "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		check=true;
		        		break;
		        	}
		        	temp=temp->next;
	        	}
	        	if(check==false){
	        		cout<<"  Name Not Found"<<endl;
				}
	    	}
	    	else if(command==2){
	    		cout<<"  Enter the Number to Search : ";
	    		cin>>number;
				
	    		while(temp!=NULL){
	    	    	if(temp->phone_number==number){
		        		cout<<"***********"<<endl;
		        		cout<<"  Name : "<<temp->name<<endl;
		        		cout<<"  Phone Number : "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		check=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
				if(check==false){
					cout<<"  Number Not Found"<<endl;	
				}	
	    	}
	    }
	    
	    //This function can delete all the contacts from the book (list)
	    void DeleteAllContacts(){
	    	Node *temp=head;
	    	Node *temp2;
	    	if(head==NULL){
	    		cout<<"  Already Contact Book is Empty"<<endl;
	    		cout<<"***********"<<endl;
			}
			else{
				while(temp!=NULL){
					temp2=temp;
					temp=temp->next;
					delete temp2;
				}
				head=NULL;
				cout<<"  Successfully Deleted All Contacts"<<endl;
	    		cout<<"***********"<<endl;
			}
		}
		
		//This Function can delete the data of any particular 
		int DeleteContactBySearch(){
	    	Node *temp=head;
	    	
	    	cout<<"***********"<<endl;
	    	cout<<"  Press 1 if you want to Search By name"<<endl;
	    	cout<<"  Press 2 if you want to Search By Number"<<endl;
	    	int command;
	    	cout<<"  Enter the Command : ";
	    	cin>>command;
	  
	    	if(command==1){
	    		bool Dcheck=false;
	    		cout<<"  Enter the Name to Delete : ";
	    		cin>>name;
	    		while(temp!=NULL){
	    	    	if(temp->name==name){
		        		cout<<"***********"<<endl;
		        		cout<<"  Name : "<<temp->name<<endl;
		        		cout<<"  Phone Number : "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		Dcheck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(Dcheck==true){
	            	int command;
	            	cout<<"  Press 1 to Delete the Contact : ";
	            	cin>>command;
	            	if(command==1 & temp==head){
	            		Node *temp1;
	            		temp1=temp;
	            		temp=temp->next;
	            		delete temp1;
	        		
	            		temp->prev=NULL;
	            		head=temp;
	            		cout<<"  Contact Deleted Success Fully"<<endl;
			    	}
			    	else if(command==1 & temp->next==NULL){
			    		temp->prev->next=NULL;
			    		delete temp;
			    		cout<<"  Contact Deleted Success Fully"<<endl;
			    	}
			    	else if(command==1){
			    		Node *temp1;
			    		temp1=temp;
			    		temp->prev->next=temp1->next;
			    		temp->next->prev=temp1->prev;
			    		delete temp1;
			    		cout<<"  Contact Deleted Success Fully"<<endl;	
			    	}
			    	else{
			    		cout<<"  You Enter Wrong Command ... Try Again"<<endl;
		    		}
	            }
	            else if(Dcheck==false){
					cout<<"  Contact of This Name Not Found."<<endl;
			    }  
	    	}
	    	else if(command==2){
	    		bool Dcheck=false;
	    		cout<<"  Enter the Number to Delete : ";
	    		cin>>number;
	    		while(temp!=NULL){
	    	    	if(temp->phone_number==number){
		        		cout<<"***********"<<endl;
		        		cout<<"Name : "<<temp->name<<endl;
		        		cout<<"Phone Number : "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		Dcheck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	
	        	if(Dcheck==true){
	            	int command;
	            	cout<<"  Press 1 to Delete the Contact : ";
	        	    cin>>command;
    	        	if(command==1 & temp==head){
	            		Node *temp1;
	            		temp1=temp;
	        	    	temp=temp->next;
	        		    delete temp1;
	        		
    	        		temp->prev=NULL;
	            		head=temp;
	            		cout<<"  Contact Deleted Success Fully"<<endl;
			    	}
				    else if(command==1 & temp->next==NULL){
	    				temp->prev->next=NULL;
		    			delete temp;
			    		cout<<"  Contact Deleted Success Fully"<<endl;
				    }
				    else if(command==1)
    				{
	    				Node *temp1;
		    			temp1=temp;
			    		temp->prev->next=temp1->next;
				    	temp->next->prev=temp1->prev;
					    delete temp1;
		    			cout<<"  Contact Deleted Success Fully"<<endl;	
			    	}
				    else{
				    	cout<<"  You Enter Wrong Command ... Try Again"<<endl;
				    }
	            }
	            else if(Dcheck==false){
					cout<<"  Contact of This Name Not Found."<<endl;
				}
	    	}
	    	else{
	    		cout<<"  You Enter wrong Command"<<endl;
			}
	    }
	    //Concept of Bubble Sort
	    void BubbleSort(){
        	Node *temp=head;
            Node *i,*j;
            string n;
            long long int n2;
            if(temp=NULL)
            {
            	cout<<"  Empty contact Book"<<endl;
			}
			else
			{
                for(i=head;i->next!=NULL;i=i->next)
                {
                    for(j=i->next;j!=NULL;j=j->next)
                    {
                        if(i->name>j->name)
		                {
                            n=i->name;
                            i->name=j->name;
                            j->name=n;
             
                            n2=i->phone_number;
                            i->phone_number=j->phone_number;
                            j->phone_number=n2;
                        }
                    }
                }
            }
        }
        
        //This function that can edit (edited name or number or both) the data of list cntact book
        int EditContacts(){
	    	Node *temp=head;
	    	cout<<"***********"<<endl;
	    	cout<<"  Press 1 if you want to Search By Name"<<endl;
	    	cout<<"  Press 2 if you want to Search By Number"<<endl;
	    	int Ecommand;
	    	cout<<"  Enter the Command : ";
	    	cin>>Ecommand;
	  
	    	if(Ecommand==1){
	    		bool Echeck=false;
	    		cout<<"  Enter the Name to Edit : ";
	    		cin>>name;
	    		while(temp!=NULL){
	    	    	if(temp->name==name){
		        		cout<<"***********"<<endl;
		        		cout<<"Name : "<<temp->name<<endl;
		        		cout<<"Phone Number : "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		Echeck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}				
	        	if(Echeck==true){
	            	int command;
	        	    cout<<"  Press 1 to Edit the Contact : ";
	            	cin>>command;
	        	    if(command==1){
	        		    cout<<"  Enter New Name : ";
    	        		cin>>name;
	            		cout<<"  Enter New Number : ";
	            		cin>>number;
	        		
	            		temp->name=name;
	        	    	temp->phone_number=number;
	        		
	        		    cout<<"  Contact Edited Success Fully"<<endl;
			    	}
			    	else{
					    cout<<"  You Enter Wrong Command ... Try Again"<<endl;
	    	        }
	    	    }
	    	    else if(Echeck==false){
	    	    	cout<<"  Contact Not Found"<<endl;
				}
	        }
	    	else if(Ecommand==2){
	    		bool Echeck=false;
	    		cout<<"  Enter the Number to Edit : ";
	    		cin>>number;
	    		while(temp!=NULL){
	    	    	if(temp->phone_number==number){
		        		cout<<"***********"<<endl;
		        		cout<<"Name : "<<temp->name<<endl;
		        		cout<<"Phone Number : "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		Echeck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(Echeck==true){
	            	int command;
	        	    cout<<"  Press 1 to Edit the Contact : ";
	            	cin>>command;
	        	    if(command==1){
	        		    cout<<"  Enter New Name : ";
    	        		cin>>name;
	            		cout<<"  Enter New Number : ";
	            		cin>>number;
	        		
	            		temp->name=name;
	        	    	temp->phone_number=number;
	        		
	        		    cout<<"  Contact Edited Success Fully"<<endl;
			    	}
			    	else{
					    cout<<"  You Enter Wrong Command"<<endl;
	    	        }
	        	}
	        	else if(Echeck==false){
	        	    cout<<"  There is No Contact of this Number."<<endl;
	            }
	        }
	        else{
			    cout<<"  You Enter Wrong Command ... Try Again"<<endl;
			}
	    }
		
		//Function that Store the data of list in text file 	
    	void OflineSave(){
    		Node *temp=head;
    		ofstream myfile ("contactbook.txt");
            if (myfile.is_open()){
            	while(temp!=NULL){
	        	    myfile<<temp->name<<endl;
		        	myfile<<temp->phone_number<<endl;
    		    	temp=temp->next;		
	        	}
                myfile.close();
                Menu();
            }
            else{
           	 cout<<"  Thanks file is empty."<<endl;
			}
		}
		
		void reopenCB(){
			bool isEmpty;
			ifstream myfile ("contactbook.txt");
            if (myfile.is_open() & myfile.peek() != EOF){
                int i=0;
                while(getline(myfile,name)){	
                    if(i % 2 == 0){
						if(head==NULL){
    	                  Node *newer= new Node;
                          newer->name=name;
		         
	                      newer->next=NULL;
	                      newer->prev==NULL;
	                      head=newer;
		                }
						else{
							Node *newer= new Node;
							
							newer->name=name;
							newer->next=NULL;
							
							Node *temp=head;
		                	while(temp->next!=NULL){
		                		temp=temp->next;
		                	}
		                	temp->next=newer;
		                	newer->prev=temp;		
						} 
                    }
                   else{
                    	Node *temp=head;
                    	if(temp->phone_number==0){
                    		
                    		 stringstream convert(name);
			       	         convert>>number;
                             temp->phone_number=number;
						}
						else{
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	
		                	stringstream convert(name);
			       	        convert>>number;
		                	temp->phone_number=number;
							
						}
                       
				    }
                    i++;
                }
            	myfile.close();
            }
            else
            {
            	cout<<"  File is Empty so Cannot open...Sorry"<<endl;
			}
		}
		
		//Menu for Admin that can change , add, delete and display the list
		void Menu(){
	    	cout<<"***********"<<endl;
	    	cout<<"  1. Add Contact"<<endl;
	    	cout<<"  2. Edit the Contact"<<endl;
	    	cout<<"  3. Delete Contact"<<endl;
	    	cout<<"  4. Search Contact"<<endl;
	    	cout<<"  5. Display All Contacts"<<endl;
	    	cout<<"  6. Delete All Contacts"<<endl;
	    	cout<<"***********"<<endl;
		
	    	int Scommand;
	    	cout<<"  Enter the Command: ";
	    	cin>>Scommand;
	    	try{
	    		if(Scommand>=1&&Scommand<=6){
	    			if(Scommand==1){
	    				system("cls");
	            		CreateNode();
	            		OflineSave();
	            		system("cls");
	    	        	Menu();
	            	}
	            	else if(Scommand==2){
	            		system("cls");
		        		EditContacts();
		        		OflineSave();
		        		system("cls");
		        		Menu();
			        }
	            	else if(Scommand==3){
	            		system("cls");
	    	        	DeleteContactBySearch();
	    	        	system("cls");
	    	        	Menu();
	            	}
	            	else if(Scommand==4){
	            		system("cls");
	            		Search();
	            		system("cls");
	            		Menu();
	            	}
	            	else if(Scommand==5){
						system("cls");      		
	            		Display();
	            		OflineSave();
	            		system("cls");
	            		Menu();
	            	}
	            	else if(Scommand==6){
	            		system("cls");
	            		DeleteAllContacts();
	            		OflineSave();
	            		system("cls");
	            		Menu();	
		        	}
				}
				else{
					throw(Scommand);
				}
			}
			catch(int Scommand){
				cout<<"  You Enter wrong Command... Run the Code Again"<<endl;
				Menu();
			}	
	    }
    
    //Main Function of this class 
void contactBookmenu(){   
    ContactBook cb;
    cb.reopenCB();
	string n;
	cout<<"  What is Your Name : ";
	cin>>n;
	system("cls");
    cout<<"***********"<<endl;
	cout<<"  "<<n<<"  WELCOME TO CONTACTBOOK      "<<endl;
	cout<<"***********"<<endl;
	cb.Menu();
	
}	
};
//End  of Contact Book List 
