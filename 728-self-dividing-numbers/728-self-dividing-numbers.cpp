class Solution {
public:
    vector <int> nums;
    vector<int> selfDividingNumbers(int left, int right) {
        if(left > right){
            return nums;
        }
        string n = to_string(left);
        if(n.find("0") != string::npos){//if it contains a zero
            return selfDividingNumbers(left+1, right);
        }
        
        int temp = left;
        
        while(temp%10 != 0){
            int digit = temp%10;
            
            if(left % digit != 0){
                return selfDividingNumbers(left+1, right);
            }
            
            temp = temp/10;
        }
        
        nums.push_back(left);
        
        return selfDividingNumbers(left+1, right);
    }
};