#include <string>
#include <iostream>
#include <cstdlib>   // for rand()
#include <cctype>    // for isalnum()   
#include <algorithm> // for back_inserter
#include <ctime>
#include <map>
using namespace std;


string random_string( size_t length ){
	srand(time(NULL)); 

	//Lookup table for char storage
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

   //Indexing for limiting char search results to num. of chars in table
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    string str(length,0);

    //Generates the random alpha-numeric string of given size
    generate_n( str.begin(), length, randchar );
    return str;
}



void print_map(std::map<int, std::string>& name_map){
	
	for ( map<int, string>::iterator i = name_map.begin(); i != name_map.end(); ++i){
		cout<< i->first << "=>" << i->second <<endl;
	}
}



int main(){

map<int, string > contact_map;


int pointer = 0;

bool b;

cin >> b;


//Creates randomly generated code and stores in in a map until a boolean value (0 || 1) input is entered
//Note: Inputs have to be solely numerical! Else program runs infinitely

	while (cin.fail()){

		cin.clear();

		string part1 = random_string(7);
		string part2 = random_string(8);

		string final = part1+part2;


		cout<< final << endl;

		contact_map.insert(pair<int, string>(pointer, final));

		pointer++;


		cin >> b;
	}


	print_map(contact_map);





}