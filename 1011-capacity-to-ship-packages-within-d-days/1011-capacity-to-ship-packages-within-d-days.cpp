class Solution {
public:
    
int check(vector<int> &weights, int cap)
{
    int days = 1;
    int load = 0;
    int n = weights.size();
    for (int i = 0; i < n; i++)
    {
        if (load + weights[i] > cap)
        {
            days += 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return days;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int low=INT_MIN;
    int sum=0;
    for(int i=0; i<weights.size(); i++)
    {
        low=max(low,weights[i]);
        sum+=weights[i];
    }
    int high=sum;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int numberOfDays = check(weights, mid);
        if (numberOfDays <= days)
        {

            high = mid - 1;
        }
        else
        {

            low = mid + 1;
        }
    }
    return low;
}
};