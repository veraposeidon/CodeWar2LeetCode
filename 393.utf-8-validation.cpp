/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */
class Solution {
public:
    // 位运算
    bool validUtf8(vector<int>& data) {
        // 如果开头是0，则直接跳过
        
        int cnt = 0;
        for(int i=0;i<data.size();i++){
            if(cnt == 0){
                if(data[i]>>5 == 0b110) cnt=1;
                else if(data[i]>>4 == 0b1110) cnt=2;
                else if(data[i]>>3 == 0b11110) cnt=3;
                else if(data[i]>>7 == 1) return false;
            }else{
                if(data[i] >> 6 !=0b10) return false;
                cnt--;
            }
            
        }
        
        return cnt==0;
    }
};

