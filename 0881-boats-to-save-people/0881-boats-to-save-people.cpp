class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        
        int min_boats = 0;
        int low = 0;
        int high = people.size() - 1;

        while (low <= high) {
            min_boats++;
            if (people[low] <= limit - people[high]) low++;
            high--;
        }

        return min_boats;
    }
};