# include <iostream>
# include <string>
# include <vector>
# include <cmath>
using namespace std;
class Solution {
public:
	vector<string> grayCodeStr(int n)
	{
		vector<string> st;
		st.push_back("0");
		st.push_back("1");
		
		for (int i = 2; i < pow(2, n); i = i * 2)
		{
			int j;
			for (j = st.size() - 1; j >= 0; j--)
				st.push_back(st[j]);
			for (j = 0; j < i; j++)
				st[j] = "0" + st[j];
			for (; j < i*2 ; j++)
				st[j] = "1" + st[j];
		}

		return st;
	}
	vector<int> grayCode(int n)
	{
		vector<int> num;
		vector<string> str = grayCodeStr(n);
		for (int i = 0; i < str.size(); i++)
		{
			num.push_back(stoi(str[i], nullptr, 2));
		}
		return num;
	}
};


int main()
{
	Solution s;
	int n = 4;
	vector<int> num = s.grayCode(n);
	cout << endl << "n=" << n << " The Gray Code is: [";
	for (int i = 0; i < num.size(); i++)
		cout << num[i] << "  ";
	cout << "]";
}
