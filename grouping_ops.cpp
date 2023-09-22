int calculate(int pos, int prev, int left, int k)
{
    // Base Case
    if (pos == k) {
        if (left == 0)
            return 1;
        else
            return 0;
    }
 
    // if N is divides completely
    // into less than k groups
    if (left == 0)
        return 0;
 
    int answer = 0;
     
    // put all possible values
    // greater equal to prev
    for (int i = prev; i <= left; i++) {
        answer += calculate(pos + 1, i,
                          left - i, k);
    }
    return answer;
}
