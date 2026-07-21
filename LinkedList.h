#pragma once
#include<iostream>
#include<fstream>
using namespace std;
template <typename T>
class Node{
	public:
		T data;
		Node<T>* next;
		Node(T value) {
			data = value;
			next = NULL;
		}
};
template <typename T>
class LinkList{
	Node<T>* head;
	public:
		LinkList() {
			head = NULL;
		}
		
		Node<T>* getHead() {
			return head;
		}
		void insert(T value) {
			Node<T>* newNode = new Node<T>(value);
			if(head == NULL || value < head->data) {
				newNode->next = head;
				head = newNode;
				return;
			}
			Node<T>* curr = head;
			while(curr->next != NULL && curr->next->data < value) {
				curr = curr->next;
			}
			newNode->next = curr->next;
			curr->next = newNode;
		}
		
		T* find(string key) {
			Node<T>* temp =head;
			while(temp != NULL) {
				if(temp->data.getKey() == key) {
					return &(temp->data);
				}
				temp = temp->next;
			}
			
			return NULL;
		}
		
		bool remove(string key) {
			Node<T>* curr = head;
			Node<T>* prev = NULL;
			
			while(curr != NULL) {
				if(curr->data.getKey() == key) {
					if(prev != NULL) {
						prev->next = curr->next;
					} else {
						head = curr->next;
					}
						
					delete curr;
					return true;
				}
				prev = curr;
				curr = curr->next;
			}
			
			return false;
		}	
		bool update(string key, T newValue) {
		    T* obj = find(key);
		    if (obj != NULL) {
		        *obj = newValue;
		        return true;
    		}
		    return false;
		}

		
		void displayAll() {
			Node<T>* curr = head;
			while(curr != NULL)  {
				curr->data.display();
				cout<<endl;
				curr = curr->next;
			}
		}
		
		void saveToFile(string fileName) {
			ofstream file(fileName,ios::binary);
			Node<T>* temp = head;
			while(temp != NULL) {
				T obj = temp->data;
				obj.writeToFile(file);
				temp = temp->next;
			}
			file.close();
		}
		
		void loadFromFile(string fileName) {
			ifstream file(fileName,ios::binary);
			if(!file.is_open()) {
				return;
			}
			while(true) {
				T obj;
				if(!obj.readFromFile(file)) {
					break;
				}
				
				insert(obj);
			}
			file.close();
		}
		
		~LinkList() {
			Node<T>* temp;
			while(head != NULL) {
				temp = head;
				head = head->next;
				delete temp;
			}
			head = nullptr;
		}
};
