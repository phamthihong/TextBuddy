//Name: Pham Thi Hong
//Matric number: A0113955A
//CE2 - Group F09 - 1C
//Assumptions: There is no error in openning file. 


#include "TextBuddy.h" 
using namespace std;
list <string> DataList;   // The list used to store the data from the commands
 
TextBuddy::TextBuddy(){
}

TextBuddy::~TextBuddy(){
}

//-------This function is used to extract the keyword :add, delete, clear, display, exit------//
string getKeyword(string userCommand){ 
	string keyword;
	istringstream iss(userCommand);
	iss >> keyword;       /*this is to extract the first word aka keyword from the command*/
	return keyword;
}

//-------This function is used to extract the information from the command-------------------//
string getDetail (string userCommand){
	string detail;
	int len;
	len = userCommand.size();
	int start = userCommand.find_first_not_of(getKeyword(userCommand));
	detail = userCommand.substr(start+1, len);       /*this is to get the detail from the user command (after the keyword)*/
	return detail;
}

//-------This function is to add the information into the file-----------------------------//
void commandAdd (string userCommand, string title){
	string detail = getDetail(userCommand);
	cout << "added to " << title << ": " << detail << endl;
	DataList.push_back(detail);       /*push the detail of the command into the DataList created*/
}

//-------This function is to check if a line contain a word/phrase-------------------------//
bool Search (string line, string detail){
	if (line.find(detail) != string::npos){
		return true;
	}
	else{
		return false;
	}
}

//--------This function is to search for a word & return the lines containing that word-----//
void commandSearch(string userCommand){
	string detail = getDetail(userCommand);
	list<string> tempList = DataList;
	list<string> Line;
	if (tempList.size() == 0){
		cout << "The file is empty"<<endl;
	}
	else{
		int k = tempList.size();
		for (int count =0; count<k; count++){
			string line = tempList.front();       
			if(Search(line,detail)){
				cout << line << endl;
				Line.push_back(line);       /*pushing in the lines that contain the word*/
			}
				tempList.pop_front();
		}
		if (Line.size() == 0){        /*when the list Line is empty, it means that there is no lines containing the word*/
			cout<<"not found" <<endl;
		}
	}
}

//--------This function is to display all the information in position-----------------------//
void commandDisplay(string userCommand){
	int count;
	list <string> tempList = DataList;      /*create a temporary list to perform pop_front() to display the information from DataList*/
	if (tempList.size() == 0){
		cout << "The file is empty"<<endl;
	}
	else{
		int k = tempList.size();
		for (count = 1; count < k+1 ; count++){
			cout << count << "." << tempList.front()<<endl;      /*print out the information stored in tempList with its position (count) */
			tempList.pop_front();
		}
	}
}

//-------This function is to sort the lines in alphabetical order------------------//
void commandSort(){
	list<string> tempList = DataList;
	if (tempList.size() == 0){
		cout << "The file is empty"<<endl;
	}
	else{
		int k = tempList.size();
		tempList.sort();         /*Sorting the lines in alphabetical order*/
		DataList = tempList;        /*Update the DataList as soted list*/
		for (int count = 1; count < k+1 ; count++){
			cout << count << "." << tempList.front()<<endl;      /*print out the information stored in tempList with its position (count) */
			tempList.pop_front();
	}
	}
}

//--------This function is to delete a information line from the file----------------//
void commandDelete(string userCommand, string title){
	list <string> tempList = DataList;        /*create a temporary list to to search and display the information to be deleted from DataList*/
	string detail;
	detail = getDetail(userCommand);
	int numberofdetail;
	stringstream convert(detail);
	if (! (convert >> numberofdetail)){       /*this is to convert the detail from delete command from string to integer (e.g delete 1, 1 will be converted from string to integer) */
		cout << "Error" <<endl;
	}
	else{
		convert >> numberofdetail;
	}
	while (numberofdetail >= 0){
	if (numberofdetail ==1){        /*when the number of detail is equal to 1, meaning delete the first line in DataList*/
	cout << "delete from " << title << ": "<< tempList.front() <<endl;
	DataList.remove(tempList.front());        /*Update the DataList */
}
   else{        /*when the number of detail is more than 1, we will pop out the front value from temporary list, until it reach 1 */
        tempList.pop_front();
        }
        numberofdetail --;
        }
}

//-------This function is to clear all the inforamtion in the file------------------//
void commandClear (string title){
	cout << "all content deleted from " << title << endl;
	DataList.clear();         /*Clear all values in DataList*/
}

//-------This function performs when exit command is called-------------------------//
void commandExit(){
	exit(EXIT_FAILURE);

}

//-------This function is to execute all the commands called-----------------------//
void executeCommand(string userCommand, string title){
	while (userCommand != "exit"){
    string keyword = getKeyword (userCommand);

    if (keyword == "add"){
		commandAdd(userCommand, title);
	}
	else if (keyword == "display"){
		commandDisplay(userCommand);
	}
	else if(keyword == "delete"){
		commandDelete(userCommand, title);
	}
	else if(keyword == "clear"){
		commandClear(title);
	}
	else if(keyword == "sort"){
		commandSort();
	}
	else if(keyword == "search"){
		commandSearch(userCommand);
	}
	else{
		cout << "Error" <<endl;
	}

	cout << "command: ";
    getline(cin, userCommand);
	}
		commandExit();
}

//-------This is the main function-------------------------------------------------//
int main(int argc, char* argv[]){
    list <string> DataList;
    cout << "Welcome to TextBuddy. " << argv[1] << "is ready for use";
    cout <<endl;
    string title = argv[1];
    ofstream Data_output;
    Data_output.open(argv[1]);
    
    string userCommand;  
    cout << "command: ";
    getline(cin, userCommand);

	executeCommand(userCommand, title);      /*Call executeCommand function to perfrom the command called*/

		getchar();
		return 0;
}

        

    
        
