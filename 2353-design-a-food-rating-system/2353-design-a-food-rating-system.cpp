class FoodRatings
{
public:
    struct Comp
    {
        bool operator()(pair<int, string> l, pair<int, string> r)
        {
            if (l.first != r.first)
            {
                return l.first < r.first;
            }
            return l.second > r.second;
        }
    };

    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, Comp>> c_f_r;
    unordered_map<string, pair<int, string>> c_r;
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            c_r[foods[i]] = {ratings[i], cuisines[i]};
            c_f_r[cuisines[i]].push({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        c_r[food].first = newRating;
        string NewCuisine = c_r[food].second;
        c_f_r[NewCuisine].push({newRating, food});
    }

    string highestRated(string cuisine)
    {
        pair<int, string> highest = c_f_r[cuisine].top();
        while (c_f_r[cuisine].top().first != c_r[highest.second].first)
        {
            c_f_r[cuisine].pop();
            highest = c_f_r[cuisine].top();
        }
        return highest.second;
    }
};