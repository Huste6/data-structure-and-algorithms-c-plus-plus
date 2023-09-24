//tim chuoi con dai nhat khong lap lai ki tu
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxlength=0;
        set<char> st;
        int left=0;
        for(int right=0;right<n;right++){
            if(st.count(s[right])==0){
                st.insert(s[right]);
                maxlength=max(maxlength,right-left+1);                
            }else{
                while(st.count(s[right])){
                    st.erase(s[left]);
                    left++;
                }
                st.insert(s[right]);
            }
        }
        return maxlength;
    }
};
        l
a,b,c,a,a,b,c,d,a
              r
check[l,r] if(repeat char) erase and l++
maxlength = [r-l+1,maxlength] 2->3->4
set={a,b,c,d};

