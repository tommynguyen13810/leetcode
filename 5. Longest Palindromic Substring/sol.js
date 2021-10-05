/**
 * @param {string} s
 * @return {string}
 */
 var longestPalindrome = function(s) {
    if(s.length <=1)
            return s;
    let start = 0;
    let maxLen = 0;
    
    for(let i=0;i<s.length;i++) {
        let len1 = expand(s, i, i);
        let len2 = expand(s, i, i+1);
        const len = Math.max(len1, len2);
        if(len>maxLen) {
            maxLen = len;
            start = i - Math.floor((len-1)/2);
        }
    }
    return s.substr(start, maxLen);
};

var expand = function(str, left, right) {
    while(left >= 0 && right < str.length && str[left] === str[right]) {
        left--;
        right++;
    }
    return right - left -1;
}