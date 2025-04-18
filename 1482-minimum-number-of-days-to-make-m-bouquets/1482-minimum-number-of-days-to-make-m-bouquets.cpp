class Solution {
public:
    bool check(vector<int>&bloomDay,int mid,int m,int k)
{

    int flag=0;
    int boukets=0;
    for(int i=0; i<bloomDay.size(); i++)
    {
        if(bloomDay[i]<=mid)
        {
            flag++;
        }
        else
        {
            boukets+=(flag/k);
            flag=0;
        }
    }

    boukets+=(flag/k);

    return boukets>=m;
}

int minDays(vector<int>& bloomDay, int m, int k)
{

    int left=bloomDay[0];
    int right=bloomDay[bloomDay.size()-1];

    for(int i=0; i<bloomDay.size(); i++)
    {
        if(left>bloomDay[i])
        {
            left=bloomDay[i];
        }

        if(right<bloomDay[i])
        {
            right=bloomDay[i];
        }

    }

    if(bloomDay.size()<((long long)m*(long long)k))return -1;

    while(left<=right)
    {

        int mid=left+(right-left)/2;

        if(check(bloomDay,mid,m,k))
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;

        }
    }

    return left;
}

};