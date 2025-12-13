class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string, string>> validItems;

        for (size_t i = 0; i < code.size(); i++) {
            if (isActive[i] &&
                onlyAlphaNum(code[i]) &&
                isBusinessTrue(businessLine[i])) {
                validItems.push_back({businessLine[i], code[i]});
            }
        }

        sort(validItems.begin(), validItems.end());

        vector<string> result;
        for (const auto& item : validItems) {
            result.push_back(item.second);
        }

        return result;
    }

    bool onlyAlphaNum(const string& s) {
        if (s.empty()) return false;
        for (unsigned char c : s) {
            if (!isalnum(c) && c != '_') return false;
        }
        return true;
    }

    bool isBusinessTrue(const string& s){
        static const unordered_set<string> valid = {
            "electronics",
            "grocery",
            "pharmacy",
            "restaurant"
        };
        return valid.count(s);
    }
};