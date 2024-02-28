#include<iostream>
#include<cstdlib>
using namespace std;

struct Record{
	int roll_no;
	int GPA;
	Record* next;
};

int count=0;
int index=0;

//insertion function

void insert(Record* &head){
	Record* ptr = (Record*)malloc(sizeof(Record));
	
	cout<<"Enter roll no :";
	cin>> ptr -> roll_no;
	
	ptr -> next = NULL;
	
	if(head == NULL){
		head = ptr;
		count++;
	}
	else{
		Record* curr= head;
		
		while(curr -> next != NULL){
			curr = curr -> next;
		}
		curr -> next =ptr;
		count++;
	}
		
}


//search function

void search(Record* head, int toSearch){
	Record* curr = head;
	int flag =0;
	while(curr != NULL){
		if(curr -> roll_no == toSearch){
			cout<<curr -> roll_no <<" Found at index of : "<<index;
			flag =1;
			break;
		}
		else{
		curr = curr -> next;
		index++;
	}
		
	}
	
	if (flag == 0){
			cout<<"Roll no is not found\n";
		}
		
}

//Print function

void display(Record* head){
	
	 if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    
	Record* curr = head;
	cout<<"\nThe Single linked list is : ";
	while(curr != NULL){
		cout<< curr -> roll_no <<" ";
		curr = curr -> next;
	}
	curr = NULL;
}

void deleteAthead(Record* &head){
	Record* todelete = head;
	
	head = head -> next;
	delete todelete;
	count--;
}

//Delete function

void deletion(Record* &head , int toDelete){
	
	if(toDelete == head->roll_no){
		deleteAthead(head);
		return;
	}
	Record* curr = head;
	
	if(curr -> next -> roll_no != toDelete){
			curr = curr -> next;
	}
	Record* temp = curr -> next;
	curr -> next = curr -> next -> next;
	count--;
	delete temp;
	
}

//Delete whole list 

void delete_all(Record* head){
	Record* curr = head;
	
	while(curr != NULL){

		Record* todelete = head;
		head = head -> next;
		delete todelete;
		count--;
		
	}
	cout<<"Now The list is empty!";
	
}

//main function

main(){
	Record* head= NULL;
	int choice;
	int toSearch;
	int toDelete;
	int no;

	cout<<"Single Linked List\n~~~~~~~~~~~~~~~\n\n\n\n";
	insert(head);
	int ask;
	cout<<"Do you want to enter more entities (0/1) : ";
	cin>>ask;
	if(ask == 0 || ask == 1){
		while(ask == 1){
		insert(head);
		cout<<"Do you want to enter more entities (Press 0 or 1 only) : ";
		cin>>ask;
	}
	}
	else{
		cout<<"Invalid input\n";
	}

	display(head);
	
	cout<<"\n";
	cout<<"~~~~~~~~~~~~~~~~~~";
	cout<<"\n\nEnter your choice : ";
	
	cout<<"\nPress 1 for search\n";
	cout<<"Press 2 for delete\n";
	cout<<"Press 3 for delete whole list\n";
	cin>>choice;
	
	if(choice == 1){
		cout<<"Which no. you want to search : ";
		cin>>toSearch;
		search(head,toSearch);
	}
	else if(choice == 2){
			cout<<"Which no. you want to delete : ";
			cin>>toDelete;
			deletion(head,toDelete);
	}
	else if(choice == 3){
		delete_all(head);
	}
	cout<<"\nThe no. of elements are : "<<count;
	display(head);
	
	cout<<"\n\n\n^^^^^^^^^^^^^^^^\nEnd of program here!";
	return 0;

}
