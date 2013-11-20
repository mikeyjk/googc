#include <iostream>
#include <vector>
#include "item.h"

// successful solution for: http://code.google.com/codejam/contest/dashboard?c=351101

int main()
{
	int mainItr = 0; // n amount of test cases

	std::cin >> mainItr; // get number of test cases from stdin

	std::vector<std::pair<int, int>> solutions; // vector storing solutions to each test case

	for(int testCases = 0; testCases < mainItr; ++testCases) // for amount of test cases
	{
		int credit = 0; // credit in store
	
		std::cin >> credit; // store credit

		int itemItr = 0; // n amount of items
	
		std::cin >> itemItr; // store amount of items

		std::vector<int> itemList;

		for(int items = 0; items < itemItr; ++items) // for amount of items
		{
			int cost = 0; // cost of item

			std::cin >> cost; // store cost

			itemList.push_back(cost); // store in vec for outside of loop
		} 

		// iterate through array comparing all index's to find solution
		for(int i = 0; i < itemItr; ++i) // for index in array
		{
			for(int j = 0; j < itemItr; ++j) // compare with other index's in the array
			{
				if( (i != j) && (itemList[i] + itemList[j] == credit)) // solution match, can't add the same index to itself
				{
					if(i <= j) // print lowest index of item first
					{
						solutions.push_back(std::make_pair(i+1, j+1));
						i = itemItr; // break loop
						j = itemItr;
					}
					else
					{
						solutions.push_back(std::make_pair(j+1, i+1));	
						i = itemItr; // break loop
						j = itemItr;
					}
				}
			}
		}
	}

	int i = 1;

	for(auto& solPair : solutions) // iterate through solutions
	{
		std::cout << "Case #" << i << ": " << solPair.first << " " << solPair.second << std::endl;
		++i;
	}

	return(1);
}
