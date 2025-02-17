//1079. Letter Tile Possibilities
class Solution {
public:
    int solve(string &tiles, vector<int> &freq){

        int ans=0;
        bool f=false;
        for(int i=0;i<26;i++){
            
            if(freq[i]>0){
                f=true;
                freq[i]--;
                ans += 1 + solve(tiles,freq);
                freq[i]++;
            }
        }
        
    if(!f)return 0;
    
    return ans;
    }
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        for(char c : tiles){
            freq[c-'A']++;
        }
        int ans = solve(tiles,freq);
        return ans;
    }
};
