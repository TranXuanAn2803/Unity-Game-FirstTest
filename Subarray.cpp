# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
	int findLength(vector<int>& num1, vector<int>& num2, int i, int j, int count)
	{
		if (i == 0 || j == 0)
			return count;
		if (num1[i - 1] == num2[j - 1]) 
		{
			count = findLength(num1, num2, i - 1, j - 1, count + 1);
		}
		
		count = max(count, max(findLength(num1, num2, i, j - 1, 0),findLength(num1, num2, i - 1, j, 0)));
		return count;
	}
};
int main()
{
	int n, m;
	Solution s;
	vector<int> num1 = { 1,2,3,2,1 };
	vector<int> num2 = { 3,2,1,4,7 };
	cout << endl << "Maximum Length of Repeated Subarray: " << s.findLength(num1, num2, num1.size(), num2.size(), 0);
	return 0;
}
