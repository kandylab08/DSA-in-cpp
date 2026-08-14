class Solution
{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        vector<pair<int, int>> p;
        vector<float> rem_time;

        int n = position.size();
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            p.push_back({position[i], i});
            rem_time.push_back(
                (float)(target - position[i]) / speed[i]
            );
        }

        sort(p.begin(), p.end(),
             [](pair<int, int> a, pair<int, int> b)
             {
                 return a.first < b.first;
             });

        while (!p.empty())
        {
            if (p.size() == 1)
            {
                p.pop_back();
                res++;
                break;
            }

            int car_no = p.back().second;
            p.pop_back();
            res++;

            while (!p.empty())
            {
                int car_back = p.back().second;

                if (rem_time[car_no] >= rem_time[car_back])
                {
                    p.pop_back();
                }
                else
                {
                    break;
                }
            }
        }

        return res;
    }
};