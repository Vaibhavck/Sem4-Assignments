/*
 * Pqueue.cpp
 *
 *  Created on: 13-Jan-2020
 *      Author: dsflh-10
 */

#include "Pqueue.h"
#include<iostream>
#include<iomanip>
using namespace std;

template <class T>
void Pqueue<T>:: push(T data) {

	Node<T> *newnode;
	newnode = new Node<T>;
	newnode->data=data;
	newnode->next= NULL;

	if(isempty())
	{
		front=newnode;
		Rear=newnode;
	}
	else
	{
		Rear->next=newnode;
		Rear=newnode;
	}

}

template <class T>
void Pqueue<T> ::pop() {

	int priority1,priority2;
			Node<T> *temp1,*temp2;
			T patient_data;
			temp1=front;
			temp2=front;
			if(front==NULL)
				cout<<"Queue is empty!\nPlease add patients in queue first";
			else
			{
				priority1=temp1->data.priority;
				while(temp1!=NULL)
				{
					priority2=temp1->data.priority;
					if(priority2>priority1)
						priority1=priority2;
					temp1=temp1->next;
				}

				temp1=front;
				while(priority1!=temp1->data.priority)
					temp1=temp1->next;

				if(temp1==front)
					front=temp1->next;
				else
				{
					while(temp2->next!=temp1)
						temp2=temp2->next;
					temp2->next=temp1->next;
					if(temp1==Rear)
						Rear=temp2;
				}
				cout<<"\n\nPatient Served\n";
				cout<<"Patient Details:-";
				cout<<"\nNAME:- "<<temp1->data.name;
				cout<<"\nID:- "<<temp1->data.id;
				cout<<"\nBLOOD GROUP:- "<<temp1->data.bloodgroup;
				cout<<"\nILLNESS:- "<<temp1->data.disease<<"\n"<<endl;
				delete temp1;

			}
}

template<class T>
bool Pqueue<T>:: isempty() {

	if(front == NULL){
		return true;
	}

	return false;
}

template<class T>
void Pqueue<T> ::display() {
	int i=1;
			Node<T> *temp;
			temp=front;
			if(front==NULL)
			{
				cout<<"Queue is empty";
				return;
			}
			cout<<"\n\n-------------------------------------------------------";
			cout<<"-------------------------------\n";
			cout<<setw(7)<<"Sr.No."<<setw(10)<<"Name"<<setw(13)<<"Illness";
			cout<<setw(18)<<"Blood Group";
			cout<<"\n----------------------------------------------------------";
			cout<<"----------------------------\n";

			while(temp!=NULL)

			{
				cout<<setw(5)<<i<<setw(12);
				cout<<temp->data.name<<setw(13)<<temp->data.disease<<setw(11);
				cout<<temp->data.bloodgroup<<setw(18)<<endl;
				temp=temp->next;
				i++;
			}
}
