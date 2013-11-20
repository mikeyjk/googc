#ifndef item_h
#define item_h

class Item
{
	private:

		int m_cost;
	
	public:

		explicit Item(int cost);
		
		int getCost() const;
		void setCost(const int cost);
};

#endif
