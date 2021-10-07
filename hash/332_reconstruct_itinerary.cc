class Solution {
public:
    vector<vector<string>> getNextTickets(unordered_set<vector<string>>& hashset, string aimAirport) {
        vector<vector<string>> nextTickets;
        for (auto ticket = hashset.begin(); ticket != hashset.end(); ticket++) {
            if (aimAirport == ticket[0]) {

            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> hash; // begin, end belong to this begin
        for (auto ticket : tickets) {
            hash[ticket[0]].insert(ticket[1]);
        }
        vector<string> itinerary;
        itinerary.push_back("JFK");
        while (!hash.empty()) {
            string cur = itinerary.back();
            if (hash[cur].empty()) {
                cout << "err\n";
            } else {
                multiset<string>::iterator next = hash[cur].begin();
                itinerary.push_back(*next);
                hash[cur].erase(next);                
            }
        }
        return itinerary;
    }
};
