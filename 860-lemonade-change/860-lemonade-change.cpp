class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_multiset<int> savedBills;
        for (const auto bill : bills) {
            savedBills.emplace(bill);
            int exchange = bill - 5;
            if (exchange == 0)
                continue;
            while (exchange > 0) {
                auto entry = savedBills.find(exchange);
                if (entry == savedBills.end()) {
                    auto cost = savedBills.find(5);
                    if (cost == savedBills.end())
                        return false;
                    exchange -= *cost;
                    savedBills.erase(cost);
                    continue;
                } else {
                    savedBills.erase(entry);
                    exchange = 0;
                }
            }
        }
        return true;
    }
};