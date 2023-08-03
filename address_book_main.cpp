#include<bits/stdc++.h>
using namespace std;
#ifndef RECORD
#define RECORD
struct record{
    
    string name;
    string address;
    int birth_year;
    string phone_number;
    struct record* next;
};
#endif


#ifndef PROJECT
#define PROJECT
void run_program();//runs the entire program
void debug_function(int,string="",string="",string="",int =0);//displays debug call
void display_commands();//Displays menu
int get_menu_selection();//gets input for menu selection
string get_name();//gets input for name
string get_address();//gets input for address
int get_birth_year();//gets input for birth year
string get_phone_number();//gets input for phone number
string get_file_name();//gets input for file name
#endif



#ifndef L_LIST
class llist{
    private:
        record *start;
        string file_name;
        int read_file();
        int write_file();
        record* reverse_llist(record *);
        void delete_all_records();
    public:
        llist();
        llist(string);
        ~llist();
        int add_record(string,string,int,string);
        int print_record(string);
        int modify_record(string,string,string);
        void print_all_records();
        int delete_records(string);
        void reverse_llist();
};
#endif
void debug_function(int function_call, std::string name, std::string address, int year, std::string phone_number) {
    std::cout << "********************\n";
    if(function_call == 1) {
        std::cout << "llist::addRecord( " << name << ", " << address << ", " << year << ", " << phone_number << " );\n";
    } else if (function_call == 2) {
        std::cout << "llist::printRecord( " << name << " )n";
    } else if(function_call == 3) {
        std::cout << "llist::modifyRecord( " << name << ", " << address << ", " << phone_number << " );\n";
    } else if (function_call == 4) {
        std::cout << "llist::printAll( );\n";
    } else if(function_call == 5) {
        std::cout << "llist::deleteRecord( " << name << " )n";
    } else if(function_call == 6) {
        std::cout << "llist::reverse( );\n";
    } // end if function_call checks
    std::cout << "********************\n";
    return; // debug_function return - end of function
}

void display_commands() {
    std::cout << "Usage: \n";
    std::cout << "\t1: Add a new record into the database.\n";
    std::cout << "\t2: Print information about a record using the name as the key. \n";
    std::cout << "\t3: Modify a record in the database using the name as the key. \n";
    std::cout << "\t4: Print all information in the database.\n";
    std::cout << "\t5: Delete an existing record from the database.\n";
	std::cout << "\t6: Reverse the order of all existing records from the database.\n";
    std::cout << "\t7: Quit the program.\n";
    std::cout << "What would you like to do?\n";
    return; // display_commands return
}
void run_program(){
    llist records(get_file_name());
    string input_name="";
    string input_address="";
    string input_phone="";
    string dummy="";
    int input_year=0;
    int menu_selection=0;

    display_commands();
    do{
        menu_selection=get_menu_selection();
        switch (menu_selection)
        {
        case 1:
        cout << "--------------------\n";
                cout << "Add a new Record\n";
                input_name = get_name();
                input_address = get_address();
                input_year = get_birth_year();
                input_phone = get_phone_number();
                records.add_record(input_name, input_address, input_year, input_phone);
            break;
        case 2: // case 2 - print specific record by name
                cout << "--------------------\n";
                cout << "Print Record(s) with the same name\n";
                input_name = get_name();
                records.print_record(input_name);
                break; // end case 2
            case 3: // case 3 - modify specific record by name
                cout << "--------------------\n";
                cout << "Modify Record(s) with the same name\n";
                input_name = get_name();
                input_address = get_address();
                getline(cin, dummy);
                //std::cin.getline(dummy, 4);
                input_phone = get_phone_number();
                records.modify_record(input_name, input_address, input_phone);
                break; // end case 3
            case 4: // case 4 - print all records
                cout << "--------------------\n";
                cout << "Printing Records...\n";
                records.print_all_records();
                break; // end case 4
            case 5: // case 5 - delete specific record by name
                cout << "--------------------\n";
                cout << "Delete Record(s) with the same name\n";
                input_name = get_name();
                records.delete_records(input_name);
                break; // end case 5
            case 6: // case 6 - recursively reverse order of linked list
                cout << "--------------------\n";
                cout << "Reversing the order of all the Records...\n";
                records.reverse_llist();
                break; // end case 6
        } // end switch (menu_selection)
        if (menu_selection != 7) {
            display_commands();
        } // end if menu_selection != 7
    } while (menu_selection != 7); // end while
    return;
}

int get_menu_selection(){
    int selection=0;
    cin>>selection;
    while (std::cin.fail() || selection < 1 || selection > 7) { // while input is not valid
        if (std::cin.fail()) {
            std::cout << "Your input was not an integer. Please enter an integer: ";
        } else if ( selection < 1 || selection > 7) {
            std::cout << "Not a valid choice.\n";
            display_commands();
        } // end if std::cin.fail()
        cin.clear();
        cin.ignore(256, '\n');
        cin >> selection;
    }
    cin.clear();
    return selection;   
    
}

string get_name(){
    string name="";
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Please enter the person's Name: ";
    getline(cin,name);
    return name;
}
string get_address() {
    // get_address
    string address = "";

    cout << "Please enter the person's ADDRESS (Enter '$' when you're finished):\n";
    getline(std::cin, address, '$');
    return address; // get_address return
}

int get_birth_year() {
    // get_birth_year variables
    int birth_year = 0;

    cout << "Please enter the person's BIRTH YEAR: ";
    cin >> birth_year;
    while (cin.fail()) { // while input is invalid
        cout << "Not an integer, please enter an integer: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> birth_year;
    } // end while std::cin.fail()
    cin.clear();
    cin.ignore(256, '\n');
    return birth_year; // get_birth_year return - end of function
}

string get_phone_number() {
    string phone_number = "";

    cout << "Please enter the contact's TELEPHONE NUMBER: ";
    getline(cin, phone_number);
    //std::cin.clear();
    return phone_number; // get_phone_number return - end of function
}

string get_file_name() {

    std::string file_name = "";
    int count;

    cout << "Please enter your FILE NAME ('.txt' file extension will be added): ";
    getline(cin, file_name);
    file_name += ".txt";
    return file_name; // get_file_name return - end of function
}

llist::llist(){
    int records_read=0;
    start=NULL;
    file_name="database.txt";
    records_read=read_file();
    if(records_read<0){
        cout<<"**"<<file_name<<" was not found..\n";
        cout<<"Therefore, no records have been added to the list and "<<file_name<<" will be created.\n"; 
           }
    else if (records_read == 0) { // else if records_read == 0
        cout << "'" << file_name << "' has been found but is empty.\n";
        cout << "Therefore, no records have been added to the database.\n";
    }
    else{
        cout << "'" << file_name << "' has been read. " << records_read << " records have been added to the database.\n";
    }
    cout<<"------------------------\n";
}

llist::llist(string file){
    int records_read=0;
    start=NULL;
    file_name=file;
    records_read=read_file();
    if(records_read<0){
        cout<<"**"<<file_name<<" was not found..\n";
        cout<<"Therefore, no records have been added to the list and "<<file_name<<" will be created.\n"; 
           }
    else if (records_read == 0) { // else if records_read == 0
        cout << "'" << file_name << "' has been found but is empty.\n";
        cout << "Therefore, no records have been added to the database.\n";
    }
    else{
        cout << "'" << file_name << "' has been read. " << records_read << " records have been added to the database.\n";
    }
    cout<<"------------------------\n";
}
//destructor
llist::~llist() {
    write_file();
    delete_all_records();
}

int llist::read_file(){
    ifstream read_file(file_name.c_str());
    record *temp=nullptr;
    record *index=nullptr;
    record *previous= nullptr;
    int file_char_length=0;
    int record_count=0;
    string dummy="";

    if(!read_file.is_open()){
        read_file.close();
        return -1;
    }
    read_file.seekg(0,read_file.end);//move read pointer to end of the file
    file_char_length=read_file.tellg();//return file ptr position
    if(file_char_length==0){
        read_file.close();
        return 0;
    }
    read_file.seekg(0,read_file.beg);//set file pointer to begining
    do{
        string address="";
        temp = new record;
        index=start;
        getline(read_file,temp->name);
        getline(read_file,temp->address);
        read_file>>temp->birth_year;
        getline(read_file,dummy);
        getline(read_file,temp->phone_number);
        getline(read_file,dummy);
        ++record_count;
        while(index !=nullptr){
            previous=index;
            index=index->next;
        }
        if(previous==nullptr){
            temp->next=start;
            start=temp;
        }
        else{
            previous->next=temp;
            temp->next=index;
        }

    }while(!read_file.eof());
    read_file.close();
    return record_count;
}

int llist::write_file(){
    ofstream write_file(file_name.c_str());
    record *index=start;
    int record_count=0;
    if(start==nullptr){
        cout<<"The database is empty. Therefore, no records have been added to file: " << file_name << '\n';
        write_file.close();
        return -1;
    }
    do{

        write_file<<index->name<<endl;
        write_file<<index->address<<endl;
        write_file<<index->birth_year<<endl;
        if(index->next!=NULL){
            write_file<<index->phone_number<<endl<<endl;
        }
        else{
            write_file<<index->phone_number<<endl;
        }
        index=index->next;
        ++record_count;
    }while(index!=nullptr);
    cout<<record_count<<" records have been recorded to file: " << file_name << "\n";
    write_file.close();
    return 0;
}

record* llist::reverse_llist(record *index) {
    // reverse_llist variables
    struct record *next = NULL;

    if (index->next == NULL) {
        start = index;
        return start;
    } // end if index
    reverse_llist(index->next);
    next = index->next;
    index->next = NULL;
}
void llist::delete_all_records() {
    // delete_all_records variables
    struct record *temp = start;
    struct record *index = NULL;
    int records_deleted = 0;

    std::cout << "--------------------\n";
    if (start != NULL) {
        while (index != NULL) {
            temp = index;
            index = index->next;
            start = index;
            delete temp;
            ++records_deleted;
        } // end while index != NULL
        std::cout << records_deleted << " records removed from the memory.\n";
    } else { // else if start == NULL
        std::cout << "The Database is empty. Therefore, no records have been removed.\n";
    }// end if start != NULL
    std::cout << "--------------------\n";
    return; // delete_all_records return - end of function
}

int llist::add_record(string input_name,string input_address,int input_year,string input_phone){
    record *temp=NULL;
    record *index=start;
    record *previous=nullptr;

    temp = new record;
    temp->name=input_name;
    temp->address=input_address;
    temp->birth_year=input_year;
    temp->phone_number=input_phone;
    while(index!=nullptr){
        previous=index;
        index=index->next;
    }
    if(previous==nullptr){
        temp->next=start;
        start=temp;
    }
    else{
        previous->next=temp;
        temp->next=index;
    }
    cout << "--------------------\n";
    cout << "Record has been added.\n";
    cout << "--------------------\n";
    return 1;
}

int llist::print_record(string input_name){
    record *index =start;
    int records_printed=0;
    cout<<"-------------------------\n";
    if(start==NULL){
        cout << "The Database is empty. Therefore, no records of " << input_name << " exist.\n";
        cout << "--------------------\n";
        return -1;
    }
    while(index!=NULL){
        if(input_name==index->name){
            ++records_printed;
            cout<<"--------------------------\n";
            cout<<"Record #"<<records_printed<< " of:\n";
            cout<<"Name: "<<index->name<<endl;
            cout<<"Address: "<<index->address<<endl;
            cout<<"Year of birth: "<<index->birth_year <<'\n';
            cout<<"Phone number: "<<index->phone_number<<endl;

        }
        index=index->next;
    }
    if(records_printed==0){
        cout<<"No records of " << input_name << " found.\n";
    }
    else{
        cout<<records_printed<<"records of "<<input_name<<" printed"<<endl;
    }
    cout<<"-----------------------------\n";
    return 1;
}

int llist::modify_record(string input_name,string input_address,string input_phone){
    record *index=start;
    int records_modified=0;
    cout<<"----------------------------\n";
    if(start==nullptr){
        cout<<"The Database is empty. Therefore no records of "<<input_name<<" Exist"<<endl;
        cout<<"----------------------------\n";
        return -1;
    }
    while(index !=nullptr){
        if(input_name==index->name){
            index->address=input_address;
            index->phone_number=input_phone;
            ++records_modified;
        }
        index=index->next;

    }
    if(records_modified==0){
        cout<<"No records of "<<input_name<<"found.\n";
    }
    else{
        cout<<records_modified<<"records of "<<input_name<<" modified.\n";
            }
            cout<<"---------------------\n";
            return 1;

}

void llist::print_all_records() {
    // print_all_records variables
    struct record *index = start;
    int record_count = 0;


    std::cout << "--------------------\n";
    if (start == NULL) {
        std::cout << "The Database is empty. Therefore, no records have been _printed.\n";
        std::cout << "--------------------\n";
        return; // print_all_records return
    } // end if start == NULL
    while (index != NULL) {
        ++record_count;
        std::cout << "====================\n";
        std::cout << "Record #" <<  record_count << '\n';
        std::cout << "Name: " <<  index->name << '\n';
        std::cout << "Address: " <<  index->address << '\n';
        std::cout << "Year of Birth: " << index->birth_year << '\n';
        std::cout << "Telephone Number: " << index->phone_number << '\n';
        index = index->next;
    }
    std::cout << record_count << " Records printed.\n";
    std::cout << "--------------------\n";
    return; // print_all_records return - end of function
}

int llist::delete_records(string input_name){
    record *temp=NULL;
    record *index=start;
    record *previous=nullptr;
    int records_deleted=0;
    cout<<"--------------------------\n";
    if(start==nullptr){
        cout << "The Database is empty. Therefore, no records of " << input_name << " exist.\n";
        cout << "--------------------\n";
        return -1;
    }
    while(index!=nullptr){
        if(input_name==index->name){
            temp=index;
            if(index==start){
                index=index->next;
                start=index;
            }
            else{
                index=index->next;
                previous->next=index;
            }
            delete temp;
            ++records_deleted;
        }
        else{
            previous=index;
            index=index->next;
        }
    }
    if(records_deleted==0){
        cout << "No records of " << input_name << " found.\n";
    }
    else{
        cout << records_deleted << " records of " << input_name << " records_deleted.\n";
    }
    cout<<"-------------------------------\n";
    return 1;

}

void llist::reverse_llist(){
    cout<<"--------------------\n";
    if(start==NULL){
        cout << "The Database is empty. Therefore, no records can be reverse_llist.\n";
    }
    else if(start->next==NULL){
        cout << "Only one record exists in the database. Why are you trying to reverse one record?.\n";
    }
    else{
        reverse_llist(start);
        cout << "All Records have been reversed.\n";
    }
    cout<<"-----------------------\n";
    return ;
}

 int main(int argc,char *argv[]){
    if(argc>1){
        cout<<"Application does not take arguments"<<endl;
        return -1;
    }
    // #ifdef DEBUG{
    //     cout<<"*******************************\n";
    //     cout<<"**        DEBUG MODE         **\n";
        
    // }
    // #endif
    cout<< "********************\n";
    cout<<"Welcome user!\n";
    cout<<"This is Harshith's Address Book App!\n";
    cout<<"--------------------------\n";
    run_program();
    cout<<"App terminated\n";
    cout<<"************************\n";
    return 0;
 }
 