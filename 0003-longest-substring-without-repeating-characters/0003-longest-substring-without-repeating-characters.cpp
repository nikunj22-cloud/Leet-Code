class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>st;
        int left = 0;
         int maxlen = 0;
        for( int right = 0 ; right < s.length(); right++){
            while( st.find(s[right]) != st.end()){
                st.erase( s[left]);
                left++;
               
            }
            st.insert(s[right]);
             maxlen = max( maxlen , right-left+1);
        } 
        return maxlen;
    }
};
//bhai hmko full window nikalni h jb tk duplicate ni mile tb tk isliye current window ka size hr bar insert krte hue dekhna pdega na ki kevl duplicate pr dekhna pde duplicate pr dekhnga toh agr current size ni nikal payega kyoki left toh aage bdh jayega 
//Kyun update maxlength har iteration me

// while loop sirf window ko shrink karta hai jab duplicate mile.

// Duplicate milne ya na milne se current substring har step pe valid ho jaata hai.

// Toh abhi ke right aur left ke beech ka window = current non-repeating substring.

// maxlength = max(maxlength, right-left+1);


// Yeh line har iteration me current window ka length check kar raha hai.

// Agar yeh sirf duplicate ke time hota → tu duplicate na aane wale windows ko miss kar dega (jaise pure increasing substring "abc" me).