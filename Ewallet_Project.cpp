#include <iostream>   // For input and output operations
#include <string>     // For string handling
#include <vector>     // For using the vector container
#include <ctime>      // For working with date and time functions
#include <cstdlib>    // For using functions such as rand() and srand()
#include <limits>     // For accessing numeric limits
#include <conio.h> 	  // for console input/output functions 
#include <windows.h>  // Specifically for the Sleep() function on Windows platform

using namespace std;

class User {
public:
    string username;
    string password;
    double balance;
    vector<string> transactionHistory;
    string fullName;
    int birthday;
    int age;
	int birth_year;
	int birth_month;
	int birth_day ;
    string address;
    string email;
    string phoneNumber;
    string gen;
    
    User(string uname, string pwd, string fname, int a, int birth_year, int birth_month, int birth_day, string addr, string mail, string phone, string s)
        : username(uname), password(pwd), balance(0.0), fullName(fname), age(a), address(addr), email(mail), phoneNumber(phone), gen(s) {}
};

vector<User> users;

void showLoading(const string &message) {
    for (char c : message) {
        cout << c << flush; // Print each character of the message with flush
        Sleep(50);
    }
    cout << endl;
}

void createAccount() {
    system("cls");
    string uname, pwd, fname, addr, email, phone, gen;
    int age, birth_year, birth_month, birth_day;
    
    cout << "USERNAME            :     ";
    cin >> uname;
    
    // Check if username already exists
    for (const User& existingUser : users) {
        if (existingUser.username == uname) {
            cout << "Username already exists! Please choose a different one.\n";
            return;
        }
    }
    
    cout << "PASSWORD            :     ";
	char ch;
	while (true) {
    	ch = _getch();
    	if (ch == 13) // Enter key
        	break;
    	cout << "*";
   		pwd.push_back(ch);
	}
	cout << endl;
	
	string confirming;
    cout << "\nDo you want to see your password in plain text? (yes/no): ";
    cin >> confirming;
    	if (confirming == "yes"|| confirming == "YES" || confirming == "Y"|| confirming == "y") {
        	cout << "PASSWORD            :     "<< pwd << endl;
    	}
    cout << "FULL NAME           :     ";
    cin.ignore();
    getline(cin, fname);
    cout << "DOB(Ex.2004 06 12)  :     ";
    cin >> birth_year >> birth_month >> birth_day;
    
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    int current_year = 1900 + ltm->tm_year;
    int current_month = 1 + ltm->tm_mon;
    int current_day = ltm->tm_mday;
    
    age = current_year - birth_year;
    
    if (birth_month > current_month || (birth_month == current_month && birth_day > current_day)) {
        age--;
    }
    
    cout << "AGE                 : 	  " << age << "\n";
    cin.ignore();
	cout << "ADDRESS             :     ";
    getline(cin, addr);
    cout << "EMAIL ADDRESS       :     ";
    cin >> email;
    
    if (email.find("@gmail.com")== string::npos ) { 
    	email +="@gmail.com" ; 
    }	
    
    cout << "PHONE NUMBER        :     ";
    cin >> phone;
    
    // Check if username already exists
	for (const User& existingUser : users) {
    	if (existingUser.phoneNumber == phone) {
            cout << "Phone number already exists! Please choose a different one.\n";
            cout << "PHONE NUMBER        :     ";
    		cin >> phone;
            
        }
    }
    
    cout << "GENDER              :     ";
    cin >> gen;
	
        system("cls");
        
    string confirmation;
    bool confirm = false;
    while (!confirm) {
        cout << "\033[1;33m\t\t\t\t\t=======================================================\t\t\t\t\t\t";
        cout << "\t\t\t\t\tREVIEW YOUR INFORMATION:\n";
        cout << "\t\t\t\t\tUSERNAME       :     " << uname << endl;
        cout << "\t\t\t\t\tPASSWORD       :     " ;
        for (size_t i = 0; i < pwd.length(); ++i) {
   			cout << "*";
   			
		}
		cout << endl;
		
		cout << "\t\t\t\t\tFULL NAME      :     " << fname << endl;
        cout << "\t\t\t\t\tBIRTHDAY       :     " << birth_year <<"-"<< birth_month <<"-"<< birth_day << endl;
        cout << "\t\t\t\t\tAGE            :     " << age << endl;
        cout << "\t\t\t\t\tADDRESS        :     " << addr << endl;
        cout << "\t\t\t\t\tEMAIL          :     " << email << endl;
        cout << "\t\t\t\t\tPHONE N0       :     " << phone << endl;
        cout << "\t\t\t\t\tGENDER         :     " << gen <<"\033[0m" << endl;
    	
        cout << "\n\n\t\t\t\t\tIS THE ABOVE INFORMATION CORRECT? (yes/no):  "<< endl;
        cout << "\t\t\t\t\t(NOTE: You can no longer edit the info once you proceed) ";
        
        cin >> confirmation;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        if (confirmation == "yes" || confirmation == "YES" || confirmation == "Y" || confirmation == "y" || confirmation == "Yes")	{
            confirm = true;
            system("cls");
            cout << "\nACCOUNT CREATED SUCCESSFULLY!\n";
        } else if(confirmation == "NO" || confirmation == "no"  || confirmation == "N" || confirmation == "n" || confirmation == "No")	{
            cout << "\nWHICH INFORMATION DO YOU WANT TO EDIT? (username, password, fullname, birthday, address, email, phone, gender): ";
            string field;
            cin >> field;
            system("cls");
            if (field == "username"|| field == "USERNAME") {
                cout << "NEW USERNAME: ";
                cin >> uname;
            } else if (field == "password" || field ==  "PASSWORD") {
                cout << "NEW PASSWORD: ";
                cin >> pwd;
            } else if (field == "fullname" || field == "FULLNAME") {
                cout << "NEW FULL NAME: ";
                cin.ignore();
                getline(cin, fname);
            } else if (field == "birthday" || field ==  "BIRTHDAY") {
                cout << "NEW BIRTHDAY (YYYY-MM-DD): ";
				cin >> birth_year >> birth_month >> birth_day;
				
				// Calculate new age
				time_t now = time(0);
				tm *ltm = localtime(&now);

				int current_year = 1900 + ltm->tm_year;
				int current_month = 1 + ltm->tm_mon;
				int current_day = ltm->tm_mday;

				age = current_year - birth_year;

				if (birth_month > current_month || (birth_month == current_month && birth_day > current_day)) {
   					age--;
				}

            } else if (field == "address" || field == "ADDRESS") {
                cout << "NEW ADDRESS: ";
                cin.ignore();
                getline(cin, addr);
            } else if (field == "email" || field == "EMAIL") {
                cout << "NEW EMAIL: ";
                cin >> email;
            } else if (field == "phone" || field == "PHONE") {
                cout << "NEW PHONE NUMBER: ";
                cin >> phone;
            } else if (field == "gen" || field == "GEN") {
                cout << "NEW GENDER: ";
                cin >> gen;
            } else {
                cout << "INVALID FIELD!\n";
            }
        } else {
                cout << "\n\033[1;33mCHOOSE EITHER YES OR NO 0NLY!\n";
                system("cls");
            }
    }
    users.emplace_back(uname, pwd, fname, birth_year, birth_month, birth_day, age, addr, email, phone, gen);
}


int login() {
    system ("cls");
    string uname, pwd;
    cout << "ENTER YOUR USERNAME: ";
    cin >> uname;
    cout << "ENTER YOUR PASSWORD: ";
    cin >> pwd;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].username == uname && users[i].password == pwd) {
            return i;
        }
    }
    return -1;
}

void checkBalance(User &user) {
    cout << "\nCURRENT BALANCE: $" << user.balance << "\n";
}

void deposit(User &user) {
	system("cls");
    double amount;
    int depositMethod;

    cout << "\nSELECT DEPOSIT METHOD:\n";
    cout << "[1] BANK TRANSFER\n[2] CREDIT CARD\n[3] CASH DEPOSIT\nCHOOSE AN OPTION: ";
    cin >> depositMethod;

    string depositType, additionalInfo;
    switch(depositMethod) {
        case 1:
            depositType = "BANK TRANSFER:\n";
            cout << "\nENTER BANK NAME: ";
            cin.ignore();
            getline(cin, additionalInfo);
            break;
        case 2:
            depositType = "CREDIT CARD:\n";
            cout << "\nENTER CARD NUMBER: ";
            cin.ignore();
            getline(cin, additionalInfo);
            break;
        case 3:
            depositType = "CASH DEPOSIT:\n";
            cout << "\nENTER TRANSACTION CODE: ";
            cin.ignore();
            getline(cin, additionalInfo);
            break;
        default:
            
            cout << "\nINVALID OPTION!\n";
            
            return;
    }

    cout << "\nENTER AMOUNT TO DEPOSIT: ";
    cin >> amount;

    user.balance += amount;
    srand(time(0));
    int refNumber = rand() % 10000 + 10000000000;
    user.transactionHistory.push_back(depositType + "	   >DEPOSITED: $" + to_string(amount) + " | Ref: " + to_string(refNumber) + " | " + additionalInfo);

    showLoading("Processing deposit.......");
    system("cls");
    cout << "\nDEPOSIT SUCCESSFUL!\n";
    cout << "REFERENCE NUMBER  :   " << refNumber << "\n";
}

void viewUserProfile(const User &user) {
    
    cout << "\nUSER PROFILE:\n";
    cout << "FULL NAME   	 :        " << user.fullName << endl;
    cout << "BIRTHDAY   	 :        " << user.birthday << endl;
    cout << "AGE              :        " << user.age << endl;
    cout << "ADDRESS          :        " << user.address << endl;
    cout << "EMAIL		     :        " << user.email << endl;
    cout << "PHONE NUMBER 	 :        " << user.phoneNumber << endl;
    cout << "GENDER		 	 :        " << user.gen<< endl;
   
}

void sendMoney(User &user) {
	system("cls");
    string recipient, recipientName, recipientPhone;
    double amount;
    
while(true) {

    cout << "\nENTER RECIPIENT'S USERNAME: ";
    cin >> recipient;
    
    cout << "ENTER RECIPIENT'S PHONE NUMBER: ";
    cin >> recipientPhone;
    cout << "ENTER AMOUNT TO SEND: ";
    cin >> amount;

    for (int i = 0; i < users.size(); i++) {
        if (users[i].username == recipient && users[i].phoneNumber == recipientPhone) {
            cout << "\nVIEW RECIPIENT PROFILE BEFORE SENDING? (yes/no): ";
            string viewProfile;
            cin >> viewProfile;
            if (viewProfile == "yes" || viewProfile == "Yes" || viewProfile == "YES" || viewProfile == "y" || viewProfile == "Y") {
                viewUserProfile(users[i]);
            }
            cout << "\nCONTINUE SENDING MONEY? (yes/no): ";
            string continueTransfer;
            cin >> continueTransfer;
            if (continueTransfer == "NO" || continueTransfer == "No" || continueTransfer == "no" || continueTransfer == "n") {
                cout << "\nNOT SENT!\n";
                return;
            }
            if (user.balance >= amount) {
                srand(time(0));
                int refNumber = rand() % 10000 + 10000000000;
                user.balance -= amount;
                user.transactionHistory.push_back("SENT: $" + to_string(amount) + " to " + recipient + " | Ref: " + to_string(refNumber));
                users[i].balance += amount;
                users[i].transactionHistory.push_back("RECEIVED: $" + to_string(amount) + " from " + user.username + " | Ref: " + to_string(refNumber));

                showLoading("\nSENDING MONEY.......");
                system("cls");
                cout << "\nTRANSFER SUCCESSFUL!\n";
                cout << "REFERENCE NUMBER: " << refNumber << "\n";
            } else {
                cout << "\nINSUFFICIENT BALANCE!\n";
            }
            return;
        }
    } 
    cout<< "\nMAKE SURE YOU ENTERED THE CORRECT USERNAME OR PHONE NUMBER!\n";
}
        
}

void transferMoney(User &user) {
    string recipient;
    double amount;
    int choice;
    string recipientIdentifier;

    cout << "\nTRANSFER TO:\n";
    cout << "1. PayPal\n";
    cout << "2. PayMaya\n";
    cout << "3. GCash\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            recipient = "PayPal";
            recipientIdentifier = "PayPal phone number";
            break;
        case 2:
            recipient = "PayMaya";
            recipientIdentifier = "PayMaya phone number";
            break;
        case 3:
            recipient = "GCash";
            recipientIdentifier = "GCash phone number";
            break;
        default:
            cout << "Invalid choice.\n";
            return;
    }

    cout << "\nEnter " << recipientIdentifier << ": ";
    cin >> recipient;

    cout << "Enter amount to transfer: ";
    cin >> amount;

    // Perform the transfer
    if (user.balance >= amount) {
        srand(time(0));
        int refNumber = rand() % 10000 + 10000000000;
        user.balance -= amount;
        user.transactionHistory.push_back("TRANSFERRED: $" + to_string(amount)+ "       | Ref:   " + to_string(refNumber)  + "     | " + recipient );

        showLoading("\n\nLinking account.......");
        system("cls");
        cout << "\nTRANSFER SUCCESSFUL!"<<endl;
        cout << "REFERENCE NUMBER: " << refNumber << "\n";
    } else {
        cout << "\nINSUFFICIENT BALANCE!\n";
    }
}
void viewTransactionHistory(User &user) {
    int choice;
    cout << "\nSELECT TRANSACTION TYPE TO VIEW:\n";
    cout << "[1] ALL TRANSACTIONS\n[2] DEPOSITS\n[3] TRANSFERS\n[4] BILL PAYMENTS\nCHOOSE AN OPTION: ";
    cin >> choice;


    cout << "\nTRANSACTION HISTORY:\n";
    for (const auto &trans : user.transactionHistory) {
        bool display = false;
        switch (choice) {
            case 1:
                display = true;
                break;
            case 2:
                if (trans.find("DEPOSITED:") != string::npos) {
                    display = true;
                }
                break;
             case 3:
                if (trans.find("TRANSFERRED:") != string::npos) {
                    display = true;
                }
                break;    
            case 4:
                if (trans.find("PAID:") != string::npos) {
                    display = true;
                }
               break;
            default:
                
                cout << "\nINVALID OPTION!\n";
               
                return;
        }
        if (display) {
            cout << trans << endl;
        }
    }
}

void payBills(User &user) {
    double amount;
    int billChoice;

    cout << "\nSELECT BILL TYPE TO PAY:\n";
    cout << "[1] Electricity\n[2] Water\n[3] Internet\n[4] Rent\nCHOOSE AN OPTION: ";
    cin >> billChoice;

    string billType, accountNumber;
    switch(billChoice) {
        case 1:
            cout << "\nSELECT PROVIDER:\n";
            cout << "[1] Noreco 1\n[2] Noreco 2\nCHOOSE AN OPTION: ";
            int elecChoice;
            cin >> elecChoice;
            if (elecChoice == 1) {
                billType = "MERALCO Electricity";
            } else if (elecChoice == 2) {
                billType = "Noreco 2 Electricity";
            } else {
                
                cout << "INVALID OPTION!\n";
                
                return;
            }
            break;
        case 2:
            cout << "\nSELECT PROVIDER:\n";
            cout << "[1] BAWAD\n[2] SWASCO\nCHOOSE AN OPTION: ";
            int waterChoice;
            cin >> waterChoice;
            if (waterChoice == 1) {
                billType = "BAWAD Water";
            } else if (waterChoice == 2) {
                billType = "SWASCO Water";
            } else {
               
                cout << "INVALID OPTION!\n";
                
                return;
            }
            break;
        case 3:
            cout << "\nSELECT PROVIDER:\n";
            cout << "[1] Smart\n[2] Globe\n[3] PLDT\n[4] TNT\n[5] TM\nCHOOSE AN OPTION: ";
            int internetChoice;
            cin >> internetChoice;
            if (internetChoice == 1) {
                billType = "Smart Internet";
            } else if (internetChoice == 2) {
                billType = "Globe Internet";
            } else if (internetChoice == 3) {
                billType = "PLDT Internet";
            } else if (internetChoice == 4) {
                billType = "TNT Internet";
            } else if (internetChoice == 5) {
                billType = "TM Internet";
            } else {
               
                cout << "\nINVALID OPTION!\n";
                
                return;
            }
            break;
        case 4:
            cout << "\nSELECT TYPE:\n";
            cout << "[1] House Rent\n[2] Motor Rent\nCHOOSE AN OPTION: ";
            int rentChoice;
            cin >> rentChoice;
            if (rentChoice == 1) {
                billType = "House Rent";
            } else if (rentChoice == 2) {
                billType = "Motor Rent";
            } else {
                
                cout << "\nINVALID OPTION!\n";
                
                return;
            }
            break;
        default:
            
            cout << "\nINVALID OPTION!\n";
           
            return;
    }

    cout << "ENTER ACCOUNT/BILL NUMBER: ";
    cin.ignore();
    getline(cin, accountNumber);
    cout << "ENTER AMOUNT TO PAY: ";
    cin >> amount;

    if (user.balance >= amount) {
        user.balance -= amount;
        
        srand(time(0));
        int refNumber = rand() % 10000 + 10000000000;

        user.transactionHistory.push_back("	   >PAID: " + billType + " BILL: $" + to_string(amount) + " | Ref: " + to_string(refNumber) + " | Account: " + accountNumber);

        showLoading("\n\nProcessing bill payment.......");
        system("cls");
        cout << "\n" << billType << " BILL PAID SUCCESSFULLY!\n";
        cout << "REFERENCE NUMBER: " << refNumber << "\n";
    } else {
        cout << "\nINSUFFICIENT BALANCE!\n";
    }
}

void userMenu(User &user) {
    bool loggedIn = true;
    while (loggedIn) {
        cout << "\033[1;34m\t\t\t\t==========================================\033[0m\n";
        cout << "\033[1;34m\t\t\t\t||\033[0m\t\t\033[1;31mUSER MENU\033[0m\t\t\033[1;34m||\033[0m\n";
        cout << "\033[1;34m\t\t\t\t|========================================|\033[0m\n";
        cout << "\033[1;34m\t\t\t\t|\033[0m\t[1] \033[36mCHECK BALANCE\033[0m\t\t \033[1;34m|\033[0m\n";
        cout << "\033[1;34m\t\t\t\t|\033[0m\t[2] \033[36mDEPOSIT MONEY\033[0m\t\t \033[1;34m|\033[0m\n";
        cout << "\033[1;34m\t\t\t\t|\033[0m\t[3] \033[36mSEND MONEY\033[0m\t\t\t \033[1;34m|\033[0m\n";
        cout << "\033[1;34m\t\t\t\t|\033[0m\t[4] \033[36mTRANSFER MONEY\033[0m\t\t \033[1;34m|\033[0m\n";
        cout << "\033[1;34m\t\t\t\t|\033[0m\t[5] \033[36mVIEW TRANSACTION HISTORY\033[0m\t \033[1;34m|\033[0m\n";
        cout << "\033[1;34m\t\t\t\t|\033[0m\t[6] \033[36mPAY BILLS\033[0m\t\t\t \033[1;34m|\033[0m\n";
        cout << "\033[1;34m\t\t\t\t|\033[0m\t[7] \033[36mVIEW PROFILE\033[0m\t\t \033[1;34m|\033[0m\n";
        cout << "\033[1;34m\t\t\t\t|\033[0m\t[8] \033[1;31mLOG OUT\033[0m\t\t\t \033[1;34m|\033[0m\n";
        cout << "\033[1;34m\t\t\t\t==========================================\033[0m";
        cout << "\033[33m\n\t\t\t\tCHOOSE AN OPTION: \033[0m";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance(user);
                break;
            case 2:
                deposit(user);
                break;
            case 3:
                sendMoney(user);
                break;
            case 4:
                transferMoney(user);
                break;
            case 5:
                viewTransactionHistory(user);
                break;
            case 6:
                payBills(user);
                break;
            case 7:
                viewUserProfile(user);
                break;
            case 8:
                cout << "\033[1;34m==============================================\033[0m\n";
                showLoading("\033[1;34m||\033[31m\tLogging out ");
                cout << "\n\033[1;34m=================================================\033[0m\n";
                system("cls");
                cout << "\033[1;34m==============================================\033[0m\n";
                cout << "\033[1;34m\tLOGGED OUT SUCCESSFULLY!\033[0m\n";
                cout << "\033[1;34m==============================================\033[0m\n";
                loggedIn = false;
                break;    
            default:
                cout << "\033[1;31m\nINVALID OPTION!\033[0m\n";
        }
    }    
}

int main() {
	system("cls");
	cout << "\033[1;34m\t\t\t\t==========================================================================\033[0m\n";
    showLoading("\033[1;34m\t\t\t\t||\033[0m\t\033[1;35m	      WELCOME TO OUR E-WALLET SYSTEM        \033[1;34m\t\t||");
    cout << "\033[1;34m\t\t\t\t==========================================================================\033[0m";
    
    while (true) {
        cout << "\n\n\033[1;34m\t\t\t\t\t\t\t==========================";
        cout << "\n\033[1;34m\t\t\t\t\t\t\t||\t\033[1;31mMAIN MENU:\033[0m\t\033[1;34m||\033[0m\n";
        cout << "\033[1;34m\t\t\t\t\t\t\t|========================|\033[0m\n";
        cout << "\033[1;34m\t\t\t\t\t\t\t|\033[0m    [1] \033[36mCREATE ACCOUNT\033[0m\t \033[1;34m|\033[0m\n";
        cout << "\033[1;34m\t\t\t\t\t\t\t|\033[0m    [2] \033[34mLOGIN\033[m\t\t \033[1;34m|\033[0m\n";
        cout << "\033[1;34m\t\t\t\t\t\t\t|\033[0m    [3] \033[31mEXIT\033[0m\t\t \033[1;34m|\033[0m\n";
        cout << "\033[1;34m\t\t\t\t\t\t\t==========================\033[0m\n";

        int choice;
        cout << "\n\033[33mCHOOSE AN OPTION  : \033[0m";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2: {
                int userIndex = login();
                if (userIndex == -1) {
                    system ("cls");
                    cout << "\n\033[1;31mINVALID USERNAME OR PASSWORD!\033[0m\nMAKE SURE YOU'VE CREATED AN ACCOUNT\n\n";
                    break;
                }
                User & user = users[userIndex];
                userMenu(user);
                break;
            }
            case 3:
                cout << "\033[36m\nTHANK YOU FOR USING THE SYSTEM!\033[0m\n";
                return 0;
            default:
            	system("cls");
                cout << "\n\033[1;31mINVALID OPTION!\033[0m\nPLEASE ENTER A NUMBER BETWEEN \033[1;31m1\033[0m AND \033[1;31m3\033[0m\n";
               
        }
    }
    return 0; 
}