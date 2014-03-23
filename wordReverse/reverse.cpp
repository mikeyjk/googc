#include <iostream> // cout etc
#include <vector> // store sentences and words
#include <memory> // uniq ptr
#include <string> // string handling
#include <cstring> // strtok
#include <limits> // used to clear cin to remove \r\n

constexpr auto maxchar = std::numeric_limits<std::streamsize>::max(); 

const char* delims = " ";

/**
 *
 * Google Code Jam
 * Reverse Word
 * Michael J. Kiernan
 * 15/03/14
 * No tokenising function seems readily available in C++.
 * Not 100% on clearing the input buffer after calling cin.
 *
 * */

int main()
{
	int testCases = 0; // default
	
	// vector of a vector of strings
	std::vector<std::vector<std::string>> solution;
		
	// get test cases
	std::cin >> testCases;

	// clear and ignore newline
	// i'm not actually 100% on this atm
	std::cin.ignore(maxchar, '\n');

	// iterate for amount of cases
	for(int i = 0; i < testCases; ++i)
	{	
	    // vector of strings to store sentence
	    std::vector<std::string> sentence;

	    // get string 
	    std::string input;
	    std::getline(std::cin, input);

	    // convert to cstr for strtok
	    // new[] because it is an array
	    std::unique_ptr<char> cinp{new char[std::strlen(input.c_str())]};
	    
	    std::strncpy(cinp.get(), 
		    input.c_str(), 
		    sizeof(char) * std::strlen(input.c_str()));

	    // store tokens
	    char* tokens = nullptr;
	    tokens = strtok(cinp.get(), delims); 

	    // while there are tokens
	    while(tokens != nullptr)
	    {
		// store tokens in vector
		// emplace -> construct for each element
		sentence.emplace_back(tokens);
		tokens = strtok(nullptr, delims);
	    } 

	    // store sentence
	    // emplace as sentence will be destroyed outside of loop
	    solution.emplace_back(sentence);

	    tokens = nullptr;
	    cinp = nullptr;
	}	

	// iterate through sentences without altering it
	for(auto c = solution.cbegin(); c != solution.cend(); ++c)
	{
	    // iterate through sentence in reverse without altering it
	    for(auto cr = c->crbegin(); cr != c->crend(); ++cr)
	    {
		std::cout << *cr << " "; 
	    }

	    // denote different sentence
	    std::cout << std::endl;
	}

	return(1);
}
