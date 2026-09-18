class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> valToIdx;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (valToIdx.count(val))
            return false;

        nums.push_back(val);
        valToIdx[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!valToIdx.count(val))
            return false;

        int idx = valToIdx[val];
        int lastVal = nums.back();

        nums[idx] = lastVal;
        valToIdx[lastVal] = idx;

        nums.pop_back();
        valToIdx.erase(val);

        return true;
    }

    int getRandom() { return nums[rand() % nums.size()]; }
};