#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//This file is of book class of libary for function of admin which haveing singly Linked List 
//This file contacts the File Handling, typedef also this file haveing queue


//Start Of Book class 
class Book{
    public:
    string title;
    string author;
    string publisher;
    int year;
    string isbn;
    Book* next;
    Book(string, string, string, int, string, Book*);
    void AdminLibarymenu();
};
//End Of Book class 


//Start of class QUEUE
class QUEUE: public Book{
	public:
	int queue[5];  //queue
	int front = -1, rear = -1, n=5; //frontindex & rearindex is inclized by -1 and n is the size of queue

//Funtion to enter new vlaue in queue 
void EQueue(int val) {
   	if ((front == 0 && rear == n-1) || (front == rear+1)) { //Condition to check queue is full or not
      		cout<<"Queue Overflow \n";
      	return;
   		}
   		if (front == -1) {  // if front index is -1 so it means that queue is empty so before user entry its number frontindex & rearindex will become 0
      	front = 0;
      	rear = 0;
   		} 
	else 					// if queue is not full  
	{
      	if (rear == n - 1) 	//if rearindex is full so this condition is true & rearindex will become zero to make our queue circular 
      	rear = 0;
      	else
      	rear = rear + 1; 	//this will increment of one in rearindex
   		}
   queue[rear] = val ;  	//assigend the value of user to rearindex   
	}
	
//Funtion to delete fisrt vlaue of queue
void DeQueue() {
   if (front == -1) {  		//Condition to check queue is full or not
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"Element deleted from queue is : "<<queue[front]<<endl; // show the value which is deleted form queue

   if (front == rear) {  // if frontindex & rearindex is same it means queue have only one value & all other indexes are empty
      front = -1;        //so it will assigemed -1 to both indexes
      rear = -1;
   } 
   else 				// if frontindex & rearindex is not same
   {
      if (front == n - 1)	//if frontindex is equal to size of queue so it the deleting value is last value 
      front = 0;			//if this is true so this will assigened 0 to frontindex
      else
      front = front + 1;
   }
}
//Funtion to display all vlaue of queue
void display() {
   int f = front, r = rear; //initialized frontindex to f & rearindex to r  
   if (front == -1) {		//Checking if the value of fronntindex is -1 its means Queue is empty
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are :\n";  //this line dipaly  all the elements of queue
   if (f <= r) {		  //if fronntindex is greater 0r equal to rearindex it will display the elements of queue
      while (f <= r){		
         cout<<queue[f]<<" ";
         f++;
      }
   } 
   else 
   {
      while (f <= n - 1) {
         cout<<queue[f]<<" ";
         f++;
      }
      f = 0;
      while (f <= r) {
         cout<<queue[f]<<" ";
         f++;
      }
   }
   cout<<endl;
}

//Funtion to display PEEK vlaue of queue
void PEEK(){
	if( front = -1 ){
		cout<<"Queue Underflow"<<endl;
	}
	else {
		cout<<"Peek value of queue is : "<<queue[front]<<endl;
	}
}

};
//End of class QUEUE


//Parameterise Constructor of Book class
Book::Book(string tempTitle, string tempAuthor, string tempPublisher, int tempYear, string tempIsbn, Book* tempNext){
    title=tempTitle;
    author=tempAuthor;
    publisher=tempPublisher;
    year=tempYear;
    isbn=tempIsbn;
    next=tempNext;
}

//Concept of Type Def
typedef Book* bookPtr;		


void getline(istream &stream, string &str, char delimiter){    
   char temp[500];
    stream.get(temp, 500, delimiter);
    stream.ignore(500, delimiter);
    str = temp;
}

void getline(istream &stream, int &num, char delimiter){   
   int temp;
    stream >> temp;
    stream.ignore(500, delimiter);
    num= temp;
}
//All function decleration 
void readFile(bookPtr &root);
void insert (bookPtr &root);
void delTitle(bookPtr &root);
bookPtr locateNode(bookPtr temp, string titl);
void delIsbn(bookPtr &root);
bookPtr locateNodeIsbn(bookPtr temp, string isb);
void searchIsbn(bookPtr temp);
void printList(bookPtr temp);
void printAuthor(bookPtr temp);
void saveFile(bookPtr temp);
int countNodes(bookPtr temp);
void AdminLibarymenu();

void readFile(bookPtr &root){
    int numBooks, yea;
    string titl, aut, pub, isb;
    ifstream infile ("books.txt", ios::in);
    infile >> numBooks;
    infile.ignore(500,'\n');
    for (int count = 0; count < numBooks; count++){
        getline(infile, titl, '\n');
        getline(infile, aut, '\n');
        getline(infile, pub, '\n');
        getline(infile,yea, '\n');
        getline(infile, isb, '\n');

        root = new Book(titl, aut, pub, yea, isb, root);
    }
}

void insert (bookPtr &root){
    string titl, aut, pub, isb;
    int yea;
    cout<<"\t\t\tYou Are Going To Add New Book Please Enter Book Detais"<<endl;
    cout << "Title:\t\t";
    cin.ignore(500,'\n');
    getline(cin, titl, '\n');
    cout << "Author:\t\t";
    getline(cin, aut, '\n');
    cout << "Publisher:\t\t";
    getline(cin,pub, '\n');
    cout << "Year:\t\t";
    getline(cin,yea, '\n');
    cout << "ISBN:\t\t";
    getline(cin, isb, '\n');

    root = new Book(titl, aut, pub, yea, isb, root);
}

void delTitle(bookPtr &root){
    string titl;
    cout<<"\t\t\tYou Are Going To Remove a Book"<<endl;
    cout << "Book Title:\t\t";
    cin.ignore(500,'\n');
    getline(cin, titl, '\n');

    bookPtr p = locateNode(root, titl);

    if (p == NULL)
        cout << "\nDeletion cannot be done.\n\n";
    else if (root == p)
        root = p->next;
    else{
        bookPtr q = root;
        while (q->next != p)
            q = q->next;
        q->next = p->next;
    }
    delete p;
}

bookPtr locateNode(bookPtr temp, string titl){
    while (temp != NULL){
        if (temp->title == titl){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void delIsbn(bookPtr &root){
    string isb;
    cout<<"\t\t\tYou Are Going To Remove a Book"<<endl;
    cout << "Book ISBN:\t\t";
    cin.ignore(500,'\n');
    getline(cin, isb, '\n');

    bookPtr p = locateNodeIsbn(root, isb);

    if (p == NULL)
        cout << "\nDeletion cannot be done.\n\n";
    else if (root == p)
        root = p->next;
    else{
        bookPtr q = root;
        while (q->next != p)
            q = q->next;
        q->next = p->next;
    }
    delete p;
}

bookPtr locateNodeIsbn(bookPtr temp, string isb){
    while (temp != NULL){
        if (temp->isbn == isb){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void searchIsbn(bookPtr temp){
    string isb;
    cout<<"\t\t\tYou Are Going To Sreach a Book Please Enter ISBN Number of that Book to See Deatils"<<endl;
    cout << "Book ISBN:\t\t";
    cin.ignore(500,'\n');
    getline(cin, isb, '\n');

    while (temp != NULL){
        if (isb == temp->isbn){
            cout <<"Title : "<<temp->title << "\n";
            cout <<"Author : "<<temp->author << "\n";
            cout <<"Publisher : "<<temp->publisher << "\n";
            cout <<"Year : "<<temp->year << "\n";
            cout <<"ISBN Number : "<<temp->isbn << "\n\n";
        }
        temp = temp->next;
    }
    cout << "\n";
}

void printList(bookPtr temp){
    cout<<"\t\t\tBook Details "<<endl;
    while (temp != NULL){
        cout <<"Title : "<< temp->title << "\n";
        cout <<"Author : "<< temp->author << "\n";
        cout <<"Publisher : "<<temp->publisher << "\n";
        cout <<"Year : "<< temp->year << "\n";
        cout <<"ISBN Number : "<< temp->isbn << "\n\n";
        temp = temp->next;
    }
    cout << "\n";
}

void printAuthor(bookPtr temp){
    string aut;
    cout<<"\t\t\tBook Details "<<endl;
    cout << "Author name:\t\t\t";
    cin.ignore(500,'\n');
    getline(cin, aut, '\n');

    while (temp != NULL){
        if (temp->author == aut){
            cout <<"Title : "<<temp->title << "\n";
            cout <<"Author : "<< temp->author << "\n";
            cout <<"Publisher : "<< temp->publisher << "\n";
            cout <<"Year : "<< temp->year << "\n";
            cout <<"ISBN Number : "<< temp->isbn << "\n\n";
        }
        temp = temp->next;
    }
    cout << "\n";
}

void saveFile(bookPtr temp){
    int count = countNodes(temp);
    ofstream outFile("saved.txt",ios::out);
    outFile << count << "\n";
    while (temp != NULL){
        outFile << temp->title << "\n";
        outFile << temp->author << "\n";
        outFile << temp->publisher << "\n";
        outFile << temp->year << "\n";
        outFile << temp->isbn << "\n";
        temp = temp->next;
    }
    cout << "\n";
}

//Function that count nodes  
int countNodes(bookPtr temp){
    int countB = 0;
    while (temp != NULL){
        countB++;
        temp = temp->next;
    }
    return countB;
}

//Concept of Quick Sort 
//Start Qucik Sort

// Function of Swap that swap for sorting 
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
//print data after sorting 
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
// Function that do partion in array for sorting 
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

//Concept of Recursion 
//function Quick Sort
void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
//End Qucik Sort

// The Admin Menu for Libary class functions 
void AdminLibarymenu(){
    int choice;
    bookPtr root = NULL;
    readFile(root);

    do{   
        cout << "\t\t<<=========================>>";
        cout << "\n\t\t>>LIBRARY MANAGEMENT SYSTEM<<";
        cout << "\n\t\t<<=========================>>";
        cout << "\n\nMenu: Select your option\n\n";
        cout << "(1) Add a book to the list\n";
        cout << "(2) Delete a book based on Title\n";
        cout << "(3) Delete a book based on ISBN\n";
        cout << "(4) Search for a book by ISBN.\n";
        cout << "(5) List all books.\n";
        cout << "(6) Search all books by an author.\n";
        cout << "(7) Quit.\n\n";
        cout << "Enter your choice ---> ";
        cin >> choice;

        if (1 <= choice && choice <= 6)
        {
            switch (choice)
            {
            case 1:
                system("cls");
                insert(root);
                break;
            case 2:
                system("cls");
                delTitle(root);
                break;
            case 3:
                system("cls");
                delIsbn(root);
                break;
            case 4:
                system("cls");
                searchIsbn(root);
                break;
            case 5:
                system("cls");
                printList(root);
                break;
            case 6:
                system("cls");
                printAuthor(root);
                break;
            default:
                 system("cls");
                cout << "Invalid choice.  Enter again.\n\n";
                break;
            }
        }
    }
    while (choice != 7);
    saveFile(root);
}
