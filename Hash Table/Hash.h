#pragma once
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Hash
{
public:
	Hash()
	{
		// Allocation empty vectors
		table = { {}, {}, {}, {}, {} };
	}
	~Hash() { table.clear(); }

	// Hash function
	bool add(pair<string, int> data)
	{
		if (data.second < 0) return false;
		else if (data.first == "") return false;

		// 0 - 17 (Gen Z)
		if (data.second <= 17 && data.second >= 0)
			table[0].push_back(data);
		// 18 - 34 (Millennial)
		else if (data.second <= 34 && data.second >= 18)
			table[1].push_back(data);
		// 35 - 50 (Gen X)
		else if (data.second <= 50 && data.second >= 35)
			table[2].push_back(data);
		// 51 - 69 (Boomer)
		else if (data.second <= 69 && data.second >= 51)
			table[3].push_back(data);
		// 70 - ... (Silent)
		else if (data.second >= 70)
			table[4].push_back(data);

		return true;
	}

	void print()
	{
		for (int i = 0; i < table.size(); i++)
		{
			cout << "i: " << i << endl;

			for (int o = 0; o < table[i].size(); o++)
			{
				cout << "(" << table[i][o].first << ", " << table[i][o].second << ")";

				if (o != (table[i].size() - 1))
					cout << ", ";
				else
					cout << endl;
			}
		}
	}
private:
	vector<vector<pair<string, int>>> table;
};
