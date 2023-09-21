// Question: given a string, a coupon can be generated as its substring of a certain length.
// For each coupon, its score is calculated as sum of: (score of char) to the power of 
// (number of occurence of this char), where score of 'a' is 1, 'b' is 2, etc.
// Input string s, int k, output maximum score of a coupon with length k. 
// The result can be large so return its modulus of 10^9+7.


const int mod = 1000000007;
int maxCoupon(string coupon, int k) {
    vector<long> dict(26, 0);
    int n = coupon.size();
    int score = 0;
    int as = 0;
    for (int i = 0; i < k; i++) {   // initial coupon starts at 0
        int diff = coupon[i] - 'a';
        if (diff == 0) {
            as++;
            if (as == 1) {
                dict[0] = 1;
                score++;
            }
        } else {
            if (dict[diff] == 0) {
                dict[diff] = (long) diff+1;
                score = (score + dict[diff]) % mod;
            } else {
                long add = (dict[diff] * diff) % mod;
                score = (score + add) % mod;
                dict[diff] = (dict[diff] + add) % mod;
            }
            printf("diff: %d, score: %d\n", diff, score);
        }
        
    }
    int cur_score = score;
    for (int i = 1; i < n - k + 1; i++) {
        int in = coupon[i+k-1] - 'a';
        int out = coupon[i-1] - 'a';
        if (out == 0) {
            as--;
            if (as == 0) {
                dict[0] = 0;
                cur_score--;
            }
        } else if (dict[out] != out + 1){
            cur_score = cur_score - dict[out];
            dict[out] /= (out+1);
            cur_score = (cur_score + dict[out]) % mod;
        } else {
            cur_score -= dict[out];
            dict[out] = 0;
        }
        
        if (in == 0) {
            as++;
            if (as == 1) {
                dict[0] = 1;
                cur_score = (cur_score + 1) % mod;
            }
        } else if (dict[in] == 0) {
            dict[in] = in + 1;
            cur_score = (cur_score + dict[in]) % mod;
        } else {
            cur_score -= dict[in];
            dict[in] = (dict[in] * (in + 1)) % mod;
            cur_score = (cur_score + dict[in]) % mod;
        }
        if (cur_score > score) score = cur_score;
    }
    return score;
}

int main() {
    string c = "zzzzzzzzzzzzzzzzzzzzzzzzz";
    int k = 10;
    int ans = maxCoupon(c, k);
    std::cout << ans << endl;
    
}
