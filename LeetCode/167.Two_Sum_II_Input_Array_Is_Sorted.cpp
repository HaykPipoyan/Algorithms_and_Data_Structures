
vector<int> twoSum(vector<int>& numbers, int target) 
{
	int start = 0;
    int end = numbers.size() - 1;
    while(start < end) 
	{
        int tmp = numbers[start] + numbers[end];
        if(tmp == target) {
            return {start + 1, end + 1};
        } else if(tmp < target) {
            ++start;
        } else {
            --end;
        }
    }
    return {0,0};
}
