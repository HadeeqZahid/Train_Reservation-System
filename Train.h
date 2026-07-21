#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Train{
	int tid;
	string tname;
	string source;
	string destination;
	public:
		Train() {
		    tid = 0;
	    	tname = source = destination = "";
		}

		Train(int id,string name,string sre,string des) {
			tid = id;
			tname = name;
			source = sre;
			destination = des;
		}
		
		int getTid() {
			return tid;
		}
		
		void updateTrainName(string newName,string s,string d) {
			tname = newName;
			source = s;
			destination = d;
		}
		
		void display() {
			cout<<"\n\n\t\t\t\t\t\tTrain id = "<<tid<<", Train Name = "<<tname<<" \n\n\t\t\t\t\t\tTrain Source = "<<source<<", Train Destination = "<<destination<<endl;
		}
		
		void writeToFile(ofstream& out) {
			out.write(reinterpret_cast<const char*>(&tid),sizeof(tid));
			
			int len = tname.size();
			out.write(reinterpret_cast<char*>(&len),sizeof(len));
			out.write(tname.c_str(),len);
			
			len = source.size();
			out.write(reinterpret_cast<const char*>(&len),sizeof(len));
			out.write(source.c_str(),len);
			
			len = destination.size();
			out.write(reinterpret_cast<const char*>(&len),sizeof(len));
			out.write(destination.c_str(),len);
		}
		
		bool readFromFile(ifstream& in) {
			if (!in.read(reinterpret_cast<char*>(&tid), sizeof(tid))){
	            return false;
			}
	        int len;
	        char* buffer;

		    in.read(reinterpret_cast<char*>(&len), sizeof(len));
	        buffer = new char[len + 1];
	        in.read(buffer, len);
		    buffer[len] = '\0';
	        tname = string(buffer);
	        delete[] buffer;

	        in.read(reinterpret_cast<char*>(&len), sizeof(len));
	        buffer = new char[len + 1];
	        in.read(buffer, len);
	        buffer[len] = '\0';
	        source = string(buffer);
	        delete[] buffer;

	        in.read(reinterpret_cast<char*>(&len), sizeof(len));
	        buffer = new char[len + 1];
	        in.read(buffer, len);
	        buffer[len] = '\0';
	        destination = string(buffer);
	        delete[] buffer;

	        return true;
    	}
    	string getKey() {
    		return to_string(tid);
		}
    	bool operator<(Train& other) {
        	return tid < other.tid;
    	}
};
