# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int> num, int left, int right)
	{
		int mid = (right + left) / 2;
	if ((mid == 0 || num[mid - 1] <= num[mid]) &&(mid == num.size()-1 || num[mid + 1] <= num[mid]))
		return mid;
	else if (mid > 0 && num[mid - 1] > num[mid])
		return findPeakElement(num, left, (mid - 1));

	else
		return findPeakElement(num, (mid + 1), right);
    }
};
int main()
{
	vector<int> num= { 1,2,1,3,5,6,4 };
	Solution s;
	cout << "Index of a peak element is: "<< s.findPeakElement(num, 0, num.size()-1);
	return 0;
}

