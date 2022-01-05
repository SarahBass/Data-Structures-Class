/************************************************************
 ------------------------------------------------------------
Sarah Bass
Program 4
Hash Table with Collision Resolution
CS 41 Data Structures
Due: 12/8/2021
-------------------------------------------------------------
1. Take input from a file from BORG Program and output Hash
*) START FINISH
*) COM
*) VAR
*) VARIABLE ++
*) VARIABLE --
*) + - / * % ^ Operators
*)PRINT

----EXTRA CREDIT----
Keep Array of errors 
which you could use to
save a copy or print

**)Example input:
    BorgCode.borg
    COM HERE IS OUR FIRST BORG PROGRAM
    COM WHAT A ROBUST LANGUAGE IT IS
    START
    VAR BORAMIR = 25
    VAR LEGOLAS = 101
    PRINT BORAMIR
    BORAMIR ++
    PRINT LEGOLAS
    PRINT GANDALF
    PRINT BORAMIR * 2
    COM
    COM NESTED BLOCK
    COM
    START
    VAR GANDALF = 49
    PRINT GANDALF
    PRINT BORAMIR
    FINISH
    PRINT GANDALF
    START
    LEGOLAS = 1000
    PRINT LEGOLAS
    FINISH
    PRINT LEGOLAS
    LEGOLAS --
    PRINT LEGOLAS
    FINISH

    PomCode.dog
    COM MY POMERANIAN IS SO SMART, HE MADE THIS LANGUAGE
START
VAR RUFF = 200
VAR RUFF = 200
PRINT WALK
VAR WALK = 100
PRINT RUFF
WALK + 20
PRINT WALK
PRINT RUFF * 2
PRINT RUFF ^ 2
PRINT RUFF / 2
PRINT RUFF
FINISH 
PRINT RUFF
VAR FURR = 500
PRINT FURR
START
PRINT FURR
PRINT WALK
FINISH

**)Output:
   Boramir is 25
   Legolas is 101
   Gandalf is undefined
   Boramir *2 is 52
   Gandalf is 49
   Boramir is 26
   Gandalf is undefined
   Legolas is 1000
   Legolas is 1000
   Legolas is 999

    Variable Already Exists
    WALK IS UNDEFINED 
    RUFF IS 200
    WALK
    IS 120
    RUFF* 2 IS 400
    RUFF^ 2 IS 40000
    RUFF/ 2 IS 100
    RUFF IS 200
    RUFF IS UNDEFINED 
    FURR IS 500
    FURR IS 500
    WALK IS 120
-------------------------------------------------------------
************************************************************/
#include <stdio.h> 
#include <iostream> 
#include <string>  
#include <fstream> 
#include <iomanip> 
#include <cmath> 
#include <sstream>

using namespace std; 
const int TABLESIZE = 47;	// a good strong prime number	
const int EMPTY = -1;	// -1 indicates that the cell is empty
#define DISPLAY true	// remove to disable debugging output

class HashTable {
    public:
	string Name;            // Name of stored Variable - Example: Legolas
    int Value;              // number given to String which can be changed with operators
    int Scope;             // Scope 0 or False is pseudo public, Scope 1 or True is pseudo private START
	class HashTable *next;	// Link
   
    HashTable(string name, int data, int start, HashTable *ptr = 0) {
        Name = name;
        Value = data;
        Scope = start;
		next = ptr; 
    }
};


	
class ChainedHashTable{
    public:
        HashTable *table[TABLESIZE];

        ChainedHashTable(){}
	
        bool insert(string Name, int Value, int Scope){
        
            int hashvalue = Hash(Name);
            #ifdef DISPLAY 
			//cout << "Inserting " << Name << " at ";
		    #endif
		    if (table[hashvalue] == NULL) // apply the hash function first
		    {
                #ifdef DISPLAY 
                    //cout << hashvalue << endl;
                #endif
                table[hashvalue] = new HashTable(Name, Value, Scope);
                return true;
                }else {
                return false;//traverse array to add 
            }}

    

            int Alphabetical (string Name, int count){
            char letter;
            int asciiletter;
            letter = Name.at(count);
            asciiletter = int(letter);
            return asciiletter;
		
        }
        //Hash Recipe is variable ABC = (65 * 1 + 66 * 2 + 67 * 3) % TABLESIZE
        int Hash(string Name){
            int data;
            int stringlength = Name.length();
            for (int i=0; i < stringlength; i++){
                data = data + (Alphabetical(Name, i) * i);
            } 
            data= data % TABLESIZE;
            return data;
        }

    string userinputcleaner (string userinputraw){
        string userinput;
        //remove any punctuation or Numbers 
        char removejunk[16] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '%', '*',
        '-', '+', '/', '='};
        for (int i=0; i<16; i++ ){
        userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), removejunk[i] ),
        userinputraw.end());}
        //You could add to the list to clean out punctuation, commands, and numbers
        string worddeleted[2] = {"VAR ", "PRINT"};
        for (int k = 0; k<2; k++){
        std::string::size_type i = userinputraw.find(worddeleted[k]);
        if (i != std::string::npos)
        userinputraw.erase(i,  worddeleted[k].length());}                                               
         //remove spaces
        std::string::iterator end_pos = std::remove(userinputraw.begin(), 
        userinputraw.end(), ' ');
        userinputraw.erase(end_pos, userinputraw.end());
        //assign new string with clean input
        userinput = userinputraw;
        return userinput;
    }

    int valueassignment (string userinputraw){
        int x;
         //remove spaces
        std::string::iterator end_pos = std::remove(userinputraw.begin(), 
        userinputraw.end(), ' ');
        userinputraw.erase(end_pos, userinputraw.end());
        char removeletters[33]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 
        'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '=', '*', '+', '-',
        '/', '^', '%' };
        for (int i = 0; i<33; i++){
            userinputraw.erase(std::remove(userinputraw.begin(), userinputraw.end(), removeletters[i] ),
            userinputraw.end());}
      stringstream ss;  
      ss << userinputraw;  
      ss >> x;
      return x;
    }

    //TO DO : This only tranverses the first node of the linked list
	bool SearchKey(string input){
		bool found = false;
		int tablelocation;
        tablelocation = Hash(input);
        if(table[tablelocation] == NULL){return found;}
        else if (table[tablelocation]->Name == input){
            found = true;
            return found;} 
        return found;
	}

string SearchName(string name){
		int tablelocation;
        tablelocation = Hash(name);
        if(table[tablelocation]== NULL){return "empty";}
        else {return (table[tablelocation]->Name);}
	}

    void operation(string userinputraw){
        string namenumber;
        namenumber = userinputcleaner(userinputraw); 
        int a = 0;
        int b = 0;
        a = valueassignment(userinputraw);
        int tablelocation;
        tablelocation = Hash(namenumber);
        if(table[tablelocation] == NULL){
            cout << namenumber << endl;
            cout << " IS UNDEFINED " << endl;}
            else{b = table[tablelocation]->Value; }
        if(userinputraw.find(" + ") != std::string::npos){
            table[tablelocation]->Value = b+a;}
        else if((userinputraw.find(" - ") != std::string::npos)){
            table[tablelocation]->Value =  b-a;}
        else if((userinputraw.find(" * ") != std::string::npos)){
            table[tablelocation]->Value =  b*a;}
        else if(userinputraw.find(" / ") != std::string::npos){
            table[tablelocation]->Value =  b/a;}
        else if(userinputraw.find(" ^ ") != std::string::npos){
            table[tablelocation]->Value =  pow(b,a); }
        else if(userinputraw.find(" = ") != std::string::npos){
            table[tablelocation]->Value =  a; }
        else if(userinputraw.find("++") != std::string::npos){
             table[tablelocation]->Value =  b + 1; }
        else if(userinputraw.find("--") != std::string::npos){
            table[tablelocation]->Value =  b - 1; }  
        else{}
}

    void operatorprint(string userinputraw){
    //Perform operations without changing values
        string namenumber;
        namenumber = userinputcleaner(userinputraw); 
        int a = 0;
        int b = 0;
        a = valueassignment(userinputraw);
        int tablelocation;
        tablelocation = Hash(namenumber);
        if(table[tablelocation] == NULL){
            cout << namenumber << endl;
            cout << " IS UNDEFINED " << endl;
        }else{b = table[tablelocation]->Value; }
        cout << namenumber << endl;
        if(userinputraw.find(" + ") != std::string::npos){
        cout << " + " << a << " IS " << b+a;}
        else if((userinputraw.find(" - ") != std::string::npos)){
        cout << " - " << a << " IS " <<   b-a;}
        else if((userinputraw.find(" * ") != std::string::npos)){
        cout << " * " << a << " IS " <<   b*a;}
        else if(userinputraw.find(" / ") != std::string::npos){
        cout << " / " << a << " IS " <<   b/a;}
        else if(userinputraw.find(" ^ ") != std::string::npos){
        cout << " ^ " << a << " IS " <<  pow(b,a); }
        else if(userinputraw.find("++") != std::string::npos){
        cout << " ++ " << a << " IS " <<   b + 1; }
        else if(userinputraw.find("--") != std::string::npos){
        cout << " -- " << a << " IS " <<   b - 1; }  
        else{}
        cout << endl;
    }



    string Translate(string userinputraw){
        string usertype = "unknown";
        string commentcommands[3] = {"COM ", "COM", " COM "}; 
        for (int c = 0; c<3; c++){
            if ( userinputraw.find(commentcommands[c]) != std::string::npos){
                usertype = "comment";
                return usertype;}}    
        string Scopecommands[3] = {"START ", "START", " START "}; 
        for (int j = 0; j<3; j++){
            if ( userinputraw.find(Scopecommands[j]) != std::string::npos){
                usertype = "start";
                return usertype; }}
        string endScopecommands[3] = {"FINISH ", "FINISH", " FINISH "}; 
        for (int l = 0; l<3; l++){
            if ( userinputraw.find(endScopecommands[l]) != std::string::npos){
                usertype = "finish";
                return usertype;}}
        string varcommands[3] = {"VAR ", " VAR", " VAR "}; 
        for (int m = 0; m<3; m++){
            if ( userinputraw.find(varcommands[m]) != std::string::npos){
                usertype = "var";
                return usertype;}}
        string numbercommands[9] = {"=", "*", "+", "-", "^", "/", "--", "++", "%"}; 
        for (int k = 0; k<9; k++){
            if ( userinputraw.find(numbercommands[k]) != std::string::npos){
                usertype = "number";
                return usertype;}}
        return usertype;}

    void Print(string name, int scope){
		int tablelocation;
        tablelocation = Hash(name);
        if(table[tablelocation] == NULL){
            cout << name << endl;
            cout << " IS UNDEFINED " << endl;
        }else if(table[tablelocation]->Scope > scope){
            cout << name << endl;
            cout << " IS UNDEFINED " << endl;}
        else{
        //cout << "Tablelocation : " << tablelocation << endl;
        //cout << "Scope: " << table[tablelocation]->Scope << endl;
		cout<< table[tablelocation]->Name << endl;
        cout << " IS " << table[tablelocation]->Value << endl;
	    }
    }
};


int main(){
    ChainedHashTable* table = new ChainedHashTable();
    int scope = 0;
    string userinputraw;
    string name;
    string intable;
    string lookup;
    int number;
    string usertype;

    //Open Alien file
    string filename = "PomCode.dog";
    //Check file 
    ifstream myfile (filename);
    if (myfile.is_open()){
        while ( getline (myfile,userinputraw) ){
            usertype = table->Translate(userinputraw);
            if (usertype == "comment"){} 
            else if (usertype == "start"){scope++;}
            else if (usertype == "finish"){scope--;}
            else if(usertype == "var"){
                name = table->userinputcleaner(userinputraw);
                intable = table->SearchName(name);
                if (intable == name){
                cout << "ERROR: Variable Already Exists" << endl;} 
                else{number =  table->valueassignment(userinputraw);
                table->insert(name, number, scope);}}
            else if (userinputraw.find("PRINT") != std::string::npos){
                lookup = table->userinputcleaner(userinputraw);
                if (userinputraw.find("*") != std::string::npos ||
                   userinputraw.find("+") != std::string::npos ||
                   userinputraw.find("-") != std::string::npos ||
                   userinputraw.find("%") != std::string::npos ||
                   userinputraw.find("/") != std::string::npos ||
                   userinputraw.find("^") != std::string::npos){
                        table->operatorprint(userinputraw);}
                else {table->Print(lookup, scope);}}
            else if (usertype == "number"){      
                table->operation(userinputraw);}
            else  { cout << " " << endl;}
        }    
    myfile.close();
    }
    return 0;
}

