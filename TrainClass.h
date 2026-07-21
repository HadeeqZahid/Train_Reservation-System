#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class TrainClass{
	
	int cid;
	string cname;
	public:
		TrainClass() {
			cid = 0;
			cname = "";
		}
		TrainClass(int id,string name) {
			cid = id;
			cname = name;
		}
		int getCid() {
			return cid;
		}
		void update(string newName) {
			cname = newName;
		} 
		
		void display() {
			cout<<"\n\n\t\t\t\t\t\tClass ID = "<<cid<<", Class Name = "<<cname<<endl;
		}
		
		void  writeToFile(ofstream& out) {
			out.write(reinterpret_cast<const char*>(&cid), sizeof(cid));
        	int len = cname.size();
        	out.write(reinterpret_cast<const char*>(&len), sizeof(len));
        	out.write(cname.c_str(), len);
		}
		
		bool readFromFile(ifstream& in) {
			if(!in.read(reinterpret_cast<char*>(&cid), sizeof(cid))) {
				return false;
			}
			
			int len;
			
			in.read(reinterpret_cast<char*>(&len), sizeof(len));
			char* buffer = new char[len+1];
			in.read(buffer,len);
			buffer[len] = '\0';
			cname = string(buffer);
			delete buffer;
			return true;
		}
		string getKey() {
    		return to_string(cid);
		}
		bool operator < (TrainClass& other) {
			return cid < other.cid;
		}	
};