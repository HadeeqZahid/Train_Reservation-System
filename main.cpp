#include<iostream>
#include"ReservationManager.h"
using namespace std;
void processEnd() {
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

void trainClassMenu(TrainClassManager& trainClassManager,TrainCapacityManager& capacityManager) {
	system("cls");
	int cid;	
	string cname;
	char choice;
	do{
		cout<<"\n\n\n\t\t\t\t\t*==*===*===*===*===*===*===*====*===*===*===*===*===*";
		cout<<"\n\t\t\t\t\t|R A I L W A Y   R E S E R V A T I O N   S Y S T E M|";
		cout<<"\n\t\t\t\t\t*==*===*===*===*===*===*===*====*===*===*===*===*===*"<<endl;
		cout<<"\n\n\t\t\t\t\t---TRAIN CLASS MANAGEMENT---"<<endl;
		cout<<"\n\t\t\t\t\t\t1. ADD TRAIN CLASS. "<<endl;
		cout<<"\t\t\t\t\t\t2. UPDATE TRAIN CLASS NAME."<<endl;
        cout<<"\t\t\t\t\t\t3. Delete Train Class."<<endl;
        cout<<"\t\t\t\t\t\t4. DISPLAY ALL TRAIN CLASSES."<<endl;
        cout<<"\t\t\t\t\t\t5. DISPLAY A SPECIFIC TRAIN CLASS."<<endl;
        cout<<"\t\t\t\t\t\t6. BACK TO MAIN MENU."<<endl;
        cout << "\n\t\t\t\t\t Select Option  :";
        cin >> choice;
        
        switch (choice) {
        	case '1':
        		system("cls");
        		cout << "\n\t\t\t\t\t\t A D D   N E W  T R A I N   C L A S S " << endl;
        		 
                cout << "\n\n\t\t\t\t\t\tEnter Class ID: ";
                cin >> cid;
                cout << "\n\n\t\t\t\t\t\tEnter Class Name: ";
                cin.ignore();
                getline(cin, cname);
                trainClassManager.addTrainClass(cid, cname);
                processEnd();
                system("cls");
                break;
            case '2':
            	system("cls");
            	cout << "\n\t\t\t\t\t\tU P D A T E   T R A I N   C L A S S " << endl;
                cout << "\n\n\t\t\t\t\t\tEnter Class ID to Update: ";
                cin >> cid;
                cout << "\n\n\t\t\t\t\t\tEnter New Class Name: ";
                cin.ignore();
                getline(cin, cname);
                trainClassManager.updateTrainClass(cid, cname);
                processEnd();
                system("cls");
                break;
            case '3':
            	system("cls");
            	cout << "\n\t\t\t\t\t\tD E L E T E   T R A I N   C L A S S " << endl;
                cout << "\n\n\t\t\t\t\t\tEnter Class ID to Delete : ";
                cin >> cid;
                if(capacityManager.classPresentInCapacity(cid)) {
    				cout<<"\n\n\t\t\t\t\t\tError: Train Class is Present in Train Capacity! Cannot be deleted!"<<endl;
				} else {
					trainClassManager.deleteTrainClass(cid);	
				}
                processEnd();
                system("cls");
                break;
            case '4':
            	system("cls");
                trainClassManager.displayAllTrainClasses();
                processEnd();
                system("cls");
                break;
            case '5':
            	system("cls");
            	cout << "\n\t\t\t\t\t\tS E A R C H   T R A I N   C L A S S " << endl;
                cout << "\n\n\t\t\t\t\t\tEnter Class ID to Display : ";
                cin >> cid;
                trainClassManager.displayTrainClass(cid);
                processEnd();
                system("cls");
                break;
            case '6':
				cout<<"\n\n\t\t\t\t\t--- Existing TRAIN CLASS MANAGEMENT---"<<endl;  
				processEnd();
                system("cls");
				break;
		}
	}while(choice != '6');
}


void trainMenu(TrainManager& trainManager,TrainCapacityManager& capacityManager) {
	system("cls");
	int tid;
    string source, destination,cname;
	char choice;
	do{
		cout<<"\n\n\n\t\t\t\t\t*==*===*===*===*===*===*===*====*===*===*===*===*===*";
		cout<<"\n\t\t\t\t\t|R A I L W A Y   R E S E R V A T I O N   S Y S T E M|";
		cout<<"\n\t\t\t\t\t*==*===*===*===*===*===*===*====*===*===*===*===*===*"<<endl;
		cout<<"\n\n\t\t\t\t\t---Train Management---"<<endl;
		cout<<"\n\t\t\t\t\t\t1. ADD TRAIN. "<<endl;
		cout<<"\t\t\t\t\t\t2. UPDATE TRAIN NAME."<<endl;
        cout<<"\t\t\t\t\t\t3. Delete Train."<<endl;
        cout<<"\t\t\t\t\t\t4. DISPLAY ALL TRAINS."<<endl;
        cout<<"\t\t\t\t\t\t5. DISPLAY A SPECIFIC TRAIN."<<endl;
        cout<<"\t\t\t\t\t\t6. BACK TO MAIN MENU."<<endl;
        cout << "\n\t\t\t\t\t Select Option  :";
        cin >> choice;
        
        switch (choice) {
        	case '1':
        		system("cls");
        		cout << "\n\t\t\t\t\t\t A D D   N E W  T R A I N  " << endl;
        		 
                cout << "\n\n\t\t\t\t\t\tEnter Train ID: ";
                cin >> tid;
                cout << "\n\n\t\t\t\t\t\tEnter Train Name: ";
                cin.ignore();
                getline(cin, cname);
                cout << "\n\n\t\t\t\t\t\tEnter Source: ";
                getline(cin, source);
                cout << "\n\n\t\t\t\t\t\tEnter Destination: ";
                getline(cin, destination);
                trainManager.addTrain(tid, cname, source, destination);
                processEnd();
                system("cls");
                break;
            case '2':
            	system("cls");
            	cout << "\n\t\t\t\t\t\tU P D A T E   T R A I N   C L A S S " << endl;
                cout << "\n\n\t\t\t\t\t\tEnter Train ID to Update: ";
                cin >> tid;
                cout << "\n\n\t\t\t\t\t\tEnter New Train Name: ";
                cin.ignore();
                getline(cin, cname);
                cout << "\n\n\t\t\t\t\t\tEnter New Source: ";
                getline(cin, source);
                cout << "\n\n\t\t\t\t\t\tEnter New Destination: ";
                getline(cin, destination);
               	trainManager.updateTrain(tid, cname,source,destination);
                processEnd();
                system("cls");
                break;
            case '3':
            	system("cls");
            	cout << "\n\t\t\t\t\t\tD E L E T E   T R A I N   C L A S S " << endl;
                cout << "\n\n\t\t\t\t\t\tEnter Train ID to Delete : ";
                cin >> tid;
                if(capacityManager.trainPresentInCapacity(tid)) {
    				cout<<"\n\n\t\t\t\t\t\tError: Train is Present in Train Capacity! Cannot be deleted!"<<endl;
				} else {
					trainManager.deleteTrain(tid);	
				}
                processEnd();
                system("cls");
                break;
            case '4':
            	system("cls");
                trainManager.displayAllTrains();
                processEnd();
                system("cls");
                break;
            case '5':
            	system("cls");
            	cout << "\n\t\t\t\t\t\tS E A R C H   T R A I N " << endl;
                cout << "\n\n\t\t\t\t\t\tEnter Class ID to Display : ";
                cin >> tid;
                trainManager.displayTrain(tid);
                processEnd();
                system("cls");
                break;
            case '6':
				cout<<"\n\n\t\t\t\t\t--- Existing TRAIN MANAGEMENT---"<<endl;  
				processEnd();
                system("cls");
				break;
		}
	}while(choice != '6');
}

void trainCapacityMenu(TrainCapacityManager& capacityManager, TrainClassManager& classManager, TrainManager& trainManager,ReservationManager& reservationManager) {
	system("cls");
	int cid, tid, seats, rate;
	
	char choice;
	do{
		cout<<"\n\n\n\t\t\t\t\t*==*===*===*===*===*===*===*====*===*===*===*===*===*";
		cout<<"\n\t\t\t\t\t|R A I L W A Y   R E S E R V A T I O N   S Y S T E M|";
		cout<<"\n\t\t\t\t\t*==*===*===*===*===*===*===*====*===*===*===*===*===*"<<endl;
		cout<<"\n\n\t\t\t\t\t---Train Capacity Management---"<<endl;
		cout<<"\n\t\t\t\t\t\t1. ADD TRAIN CAPACITY. "<<endl;
		cout<<"\t\t\t\t\t\t2. UPDATE TRAIN CAPACITY."<<endl;
        cout<<"\t\t\t\t\t\t3. Delete Train CAPACITY."<<endl;
        cout<<"\t\t\t\t\t\t4. DISPLAY ALL TRAIN CAPACITIES."<<endl;
        cout<<"\t\t\t\t\t\t5. DISPLAY A SPECIFIC TRAIN CAPACITY."<<endl;
        cout<<"\t\t\t\t\t\t6. BACK TO MAIN MENU."<<endl;
        cout << "\n\t\t\t\t\t Select Option  :";
        cin >> choice;
        
        switch (choice) {
        	case '1':
        		system("cls");
        		cout << "\n\t\t\t\t\t\t A D D   N E W  T R A I N   C A P A C I T Y " << endl;
        		classManager.displayAllTrainClasses();
                cout << "\n\n\t\t\t\t\t\tEnter Class ID: ";
                cin >> cid;
                trainManager.displayAllTrains();
                cout << "\n\n\t\t\t\t\t\tEnter Train ID: ";
                cin >> tid;
                cout << "\n\n\t\t\t\t\t\tEnter Total Seats: ";
                cin >> seats;
                cout << "\n\n\t\t\t\t\t\tEnter Ticket Rate: ";
                cin >> rate;
                capacityManager.addTrainCapacity(cid, tid, seats, rate,classManager,trainManager);
                processEnd();
                system("cls");
                break;
            case '2':
            	system("cls");
            	cout << "\n\t\t\t\t\t\tU P D A T E   T R A I N    C A P A C I T Y " << endl;
            	classManager.displayAllTrainClasses();
                cout << "\n\n\t\t\t\t\t\tEnter Class ID to Update: ";
                cin >> cid;
                trainManager.displayAllTrains();
                cout << "\n\n\t\t\t\t\t\tEnter Train ID to Update: ";
                cin >> tid;
                cout << "\n\n\t\t\t\t\t\tEnter New Total Seats: ";
                cin >> seats;
                cout << "\n\n\t\t\t\t\t\tEnter New Ticket Rate: ";
                cin >> rate;
                capacityManager.updateTrainCapacity(cid, tid, seats, rate);
                processEnd();
                system("cls");
                break;
            case '3':
            	system("cls");
            	cout << "\n\t\t\t\t\t\tD E L E T E   T R A I N    C A P A C I T Y " << endl;
            	classManager.displayAllTrainClasses();
                cout << "\n\n\t\t\t\t\t\tEnter Class ID to Delete : ";
                cin >> cid;
                trainManager.displayAllTrains();
                cout << "\n\n\t\t\t\t\t\tEnter Train ID to Delete: ";
                cin >> tid;
                if(reservationManager.capacityPresentInReservation(cid,tid)) {
    				cout<<"\n\n\t\t\t\t\t\tError: Train Capacity is Present in Reservation! Cannot be deleted!"<<endl;
				} else {
					capacityManager.deleteTrainCapacity(cid, tid);	
				}
                processEnd();
                system("cls");
                break;
            case '4':
            	system("cls");
            	cout << "\n\t\t\t\t\t\tA L L   T R A I N    C A P A C I T Y " << endl;
                capacityManager.displayAllTrainCapacities();;
                processEnd();
                system("cls");
                break;
            case '5':
            	cout << "\n\t\t\t\t\t\tS E A R C H   T R A I N    C A P A C I T Y " << endl;
            	classManager.displayAllTrainClasses();
                cout << "\n\n\t\t\t\t\t\tEnter Class ID to Display : ";
                cin >> cid;
                trainManager.displayAllTrains();
                cout << "\n\n\t\t\t\t\t\tEnter Train ID to Display: ";
                cin >> tid;
                capacityManager.displayTrainCapacity(cid, tid);
                processEnd();
                system("cls");
                break;
            case '6':
				cout<<"\n\n\t\t\t\t\t--- Train Capacity Management---"<<endl;  
				processEnd();
                system("cls");
				break;
		}
	}while(choice != '6');
	
}

void reservationMenu(ReservationManager& reservationManager, TrainClassManager& classManager, TrainManager& trainManager, TrainCapacityManager& capacityManager) {
    system("cls");
	int cid, tid, ticketNo;
    string date, CNIC, passengerName;
    
    char choice;
	do{
		cout<<"\n\n\n\t\t\t\t\t*==*===*===*===*===*===*===*====*===*===*===*===*===*";
		cout<<"\n\t\t\t\t\t|R A I L W A Y   R E S E R V A T I O N   S Y S T E M|";
		cout<<"\n\t\t\t\t\t*==*===*===*===*===*===*===*====*===*===*===*===*===*"<<endl;
		cout<<"\n\n\t\t\t\t\t---Reservation Management---"<<endl;
		cout<<"\n\t\t\t\t\t\t1. ADD RESERVATION. "<<endl;
		cout<<"\t\t\t\t\t\t2. UPDATE RESERVATION."<<endl;
        cout<<"\t\t\t\t\t\t3. Delete RESERVATION."<<endl;
        cout<<"\t\t\t\t\t\t4. DISPLAY ALL RESERVATION."<<endl;
        cout<<"\t\t\t\t\t\t5. DISPLAY A SPECIFIC RESERVATION."<<endl;
        cout<<"\t\t\t\t\t\t6. DISPLAY AVAILABLE SEATS."<<endl;
        cout<<"\t\t\t\t\t\t7. BACK TO MAIN MENU."<<endl;
        cout << "\n\t\t\t\t\t Select Option  :";
        cin >> choice;
        
        switch (choice) {
        	case '1':
        		system("cls");
        		cout << "\n\t\t\t\t\t\t A D D   N E W  R E S E R V A T I O N " << endl;
        		cout<<"\n\t\t\t\t\t CNIC 13 - Digit only Applicable. \n";
                cout<<"\n\t\t\t\t\t Enter CNIC = ";
                cin.ignore();
                getline(cin, CNIC);
                if(!isValidCNIC(CNIC)) {
                	cout<<"Invalid CNIC Number Please Try Again!"<<endl;
                	processEnd();
                	system("cls");
                	break;
				}
                cout<<"\n\t\t\t\t\t Passenger Name Alphabats Only\n";
                cout<<"\n\t\t\t\t\t Enter Name = ";
                getline(cin, passengerName);
                if(!isValidPassengerName(passengerName)) {
                	cout<<"Invalid Passenger Name Please Try Again!"<<endl;
                	processEnd();
                	system("cls");
                	break;
				} 
				cout<<"\n\t\t\t\t\t Date Format DD/MM/YYYY only applicble .\n";
				cout<<"\n\t\t\t\t\t Enter Date = ";
                getline(cin, date);
                if(!isValidDate(date)) {
                	cout<<"\n\t\t\t\t\t Invalid Date Format Please Try Again!"<<endl;
                	processEnd();
                	system("cls");
                	break;
				}
                capacityManager.displayAllTrainCapacities();
                cout << "\n\t\t\t\t\t Enter Class ID = ";
				cin>>cid;
				if(!classManager.isValidTrainClass(cid)) {
					cout<<"Error: Invalid Class ID!"<<endl;
					processEnd();
                	system("cls");
                	break;
				}
				cout << "\n\t\t\t\t\t Enter Train ID = ";
				cin>>tid;
				if(!trainManager.isValidTrain(tid)) {
					cout<<"Error: Invalid Train ID!"<<endl;
					processEnd();
                	system("cls");
                	break;
				}
				reservationManager.addReservation(cid,tid,date,CNIC,passengerName,capacityManager);
                processEnd();
                system("cls");
                break;
            case '2':
            	system("cls");
            	cout << "\n\t\t\t\t\t\tU P D A T E   R E S E R V A T I O N " << endl;
                cout << "\n\t\t\t\t\t Enter Class ID = ";
				cin>>cid;
				cout << "\n\t\t\t\t\t Enter Train ID = ";
				cin>>tid;
				cout<<"\n\t\t\t\t\t Enter Ticket Number = ";
				cin>>ticketNo;
				cout<<"\n\t\t\t\t\t Date Format DD/MM/YYYY only applicble .\n";
				cout<<"\n\t\t\t\t\t Enter Date = ";
				cin.ignore();
                getline(cin, date);
                if(!isValidDate(date)) {
                	cout<<"Invalid Date Format Please Try Again!"<<endl;
                	processEnd();
                	system("cls");
                	break;
				}
                cout<<"\n\t\t\t\t\t Enter New CNIC = ";
                
                getline(cin, CNIC);
                if(!isValidCNIC(CNIC)) {
                	cout<<"Invalid CNIC Number Please Try Again!"<<endl;
                	processEnd();
                	system("cls");
                	break;
				}
				cout<<"\n\t\t\t\t\t Enter New Passenger Name = ";
                
                getline(cin, passengerName);
				if(!isValidPassengerName(passengerName)) {
                	cout<<"Invalid Passenger Name Please Try Again!"<<endl;
                	processEnd();
                	system("cls");
                	break;
				}
				reservationManager.updateReservation(cid,tid,ticketNo,date,CNIC,passengerName);
                processEnd();
                system("cls");
                break;
            case '3':
            	system("cls");
            	cout << "\n\t\t\t\t\t\tD E L E T E   R E S E R V A T I O N " << endl;
                cout << "\n\t\t\t\t\tEnter Class ID = ";
				cin>>cid;
				cout << "\n\t\t\t\t\tEnter Train ID = ";
				cin>>tid;
				cout<<"\n\t\t\t\t\tEnter Ticket Number = ";
				cin>>ticketNo;
				cout<<"\n\t\t\t\t\tDate Format DD/MM/YYYY only applicble .\n";
				cout<<"\n\t\t\t\t\tEnter Date = ";
				cin.ignore();
                getline(cin, date);
				if(!isValidDate(date)) {
                	cout<<"Invalid Date Format Please Try Again!"<<endl;
                	processEnd();
                	system("cls");
                	break;
				}
				reservationManager.deleteReservation(cid,tid,ticketNo,date);
                processEnd();
                system("cls");
                break;
            case '4':
            	system("cls");
            	cout << "\n\t\t\t\t\t\tA L L   R E S E R V A T I O N " << endl;
                reservationManager.displayAllReservations();
                processEnd();
                system("cls");
                break;
            case '5':
            	system("cls");
            	cout << "\n\t\t\t\t\t\tS E A R C H   R E S E R V A T I O N " << endl;
                cout << "\n\t\t\t\t\tEnter Class ID = ";
				cin>>cid;
				cout << "\n\t\t\t\t\tEnter Train ID = ";
				cin>>tid;
				cout<<"\n\t\t\t\t\tEnter Ticket Number = ";
				cin>>ticketNo;
				cout<<"\n\t\t\t\t\tDate Format DD/MM/YYYY only applicble .\n";
				cout<<"\n\t\t\t\t\tEnter Date = ";
				cin.ignore();
                getline(cin, date);
                if(!isValidDate(date)) {
                	cout<<"Invalid Date Format Please Try Again!"<<endl;
                	processEnd();
                	system("cls");
                	break;
				}
				reservationManager.displayReservation(cid, tid, ticketNo ,date);
                processEnd();
                system("cls");
                break;
            case '6':
            	system("cls");
            	cout << "\n\t\t\t\t\t\tT O T A L   S E A T S   A V A I L A B L E " << endl;
            	classManager.displayAllTrainClasses();
				cout << "\n\t\t\t\t\tEnter Class ID = ";
				cin>>cid;
				trainManager.displayAllTrains();
				cout << "\n\t\t\t\t\tEnter Train ID = ";
				cin>>tid;
				cout<<"\n\t\t\t\t\tDate Format DD/MM/YYYY only applicble .\n";
				cout<<"\n\t\t\t\t\tEnter Date = ";
				cin.ignore();
                getline(cin, date);
				if(!isValidDate(date)) {
                	cout<<"Invalid Date Format Please Try Again!"<<endl;
                	processEnd();
                	system("cls");
                	break;
				}
				cout<<"\n\t\t\t\t\tTotal Seats Available: "<<reservationManager.totalSeatsAvailable(cid,tid,date,capacityManager)<<endl;  // ? Print result
				processEnd();
                system("cls");
				break;    
            case '7':
				cout<<"\n\n\t\t\t\t\t--- Reservation Management---"<<endl;  
				processEnd();
                system("cls");
				break;
		}
	}while(choice != '7');
}

int main() {
	system("color E2");
	char choice;
	
	//objects (LinkedList) 
	TrainClassManager trainClassManager;
	TrainManager trainManager;
    TrainCapacityManager capacityManager;
    ReservationManager reservationManager;
	//loading data from files
	trainClassManager.loadFromFile();
	trainManager.loadFromFile();
	capacityManager.loadFromFile();
	reservationManager.loadFromFile();
	do{
	//saving data from file
		trainClassManager.saveToFile();
		trainManager.saveToFile();
		capacityManager.saveToFile();
		reservationManager.saveToFile();
		cout<<"\n\n\n\t\t\t\t\t*==*===*===*===*===*===*===*====*===*===*===*===*===*";
		cout<<"\n\t\t\t\t\t|R A I L W A Y   R E S E R V A T I O N   S Y S T E M|";
		cout<<"\n\t\t\t\t\t*==*===*===*===*===*===*===*====*===*===*===*===*===*"<<endl;
		cout<<"\n\n\t\t\t\t\t\t1. MANAGE TRAIN CLASSES." << endl;
		cout<<"\n\n\t\t\t\t\t\t2. MANAGE TRAINS." << endl;
		cout<<"\n\n\t\t\t\t\t\t3. MANAGE TRAIN CAPACITIES." << endl;
		cout<<"\n\n\t\t\t\t\t\t4. MANAGE RESERVATIONS." << endl;
		cout<<"\n\n\t\t\t\t\t\t5. EXIT." << endl;
		cout<<"\n\t\t\t\t\t Select Option  :";
        cin >> choice;
		
		switch(choice) {
			case '1':
				trainClassMenu(trainClassManager,capacityManager);
                break;
            case '2':
				trainMenu(trainManager,capacityManager);
				break; 
			case '3':
				trainCapacityMenu(capacityManager, trainClassManager, trainManager,reservationManager);
                break;	
			case '4':
				reservationMenu(reservationManager,trainClassManager, trainManager, capacityManager);
                break;	
			case '5':
                cout << "Exiting... Thank you for using the Railway Reservation System!\n";
                break;
			default:
                cout << "\n\n\t\t\t\t\t\tInvalid choice! Try again.\n";		   
		}
	} while(choice != '5');
	
	
	return 0;
}