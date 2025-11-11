class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int right = s.length()-1;
        while(right >= 0 ){
            if( s[right] != ' '){
                ans++;
            }
            else if( ans > 0) return ans;
            right--;
        } 
        return ans;
    }
}; 
//Maan lo string hai:

// "Hello World   "
//                ↑
//             right pointer yaha hai


// Yaha last character space hai.

// while loop start:
// s[right] = ' '   (space)


// Ab agar code me sirf else return ans; hota:

// else return ans;  // ans = 0 yaha


// To yahi pe return 0 ho jata (galat), kyunki abhi word count shuru hi nahi hua.

// ✅ Lekin kya karna chahiye?

// Last wale spaces ko ignore karna hai.

// Isi liye yeh condition dala:

// else if(ans > 0) return ans;

// Matlab:

// Agar space mila aur ans == 0 → ignore kar (kyunki abhi word count shuru nahi hua)

// Agar space mila aur ans > 0 → return ans (kyunki word khatam ho chuka hai)

// Ab point ko example se LOCK karte hain:
// "Hello World   "
//                ↑ start here