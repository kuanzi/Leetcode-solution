// example： 3[a2[c]b] 
// 我的答案！
class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;
        
        int num = 0;
        string str = "";
        for(int i = 0; i < s.length(); i++){ // 字符串的基本操作
            if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');  //这里一定要记得减去'0'
            }
            else if(isalpha(s[i])){
                str += s[i];
            }
            else if(s[i] == '['){
                nums.push(num);
                strs.push(str);
                num = 0;
                str = "";
            }
            else{
                int times = nums.top();
                nums.pop();
                while(times--){   // 注意这个！如果是times--，结果会停在times=-1； 如果是--times，结果 会停在times=0,但是循环次数会少掉1次！
                    strs.top() += str;
                }
                str = strs.top();
                strs.pop();
            }
        }
        return  str;
    }
};

// 我的答案2：递归
class Solution{
public:
    string decodeString(string s) {
        if(s.empty()) return "";
        int start = 0;
        string res = decomp(s, start);
        return res;
    }

    string decomp(string s, int& i){ // 为什么要单独出helper函数呢？因为有其他要传递的数据
        if(s.empty()) return "";

        int num = 0;
        string str = "";
        for(; i < s.length() && s[i] != ']'; ++i){
            if(isdigit(s[i])){
                num = num * 10 + s[i] - '0';
            }
            else if(isalpha(s[i])){
                str += s[i];
            }
            else if(s[i] == '['){
                i = i + 1;
                string sb = decomp(s, i);
                while(num--){
                    str += sb;
                }
                num = 0;
            }
        }
        return str;
    }
};




// 递归法
// https://leetcode.com/problems/decode-string/discuss/87552/c-0ms-recursion
class Solution {
public:
    string decodeString(string s) {
        if(s.empty()) return "";
        string res = "";
        int i = 0, j = 0;
        while(j < s.size()){
            
            // 对字母
            while(j < s.size() && isalpha(s[j])) j++;
            res += s.substr(i, j - i);
            i = j;
            if(j == s.size()) break;
            
            
            while(isdigit(s[j])) j++;
            int k = stoi(s.substr(i, j - i));  //在新建工程中点击settings ——>global compiler settings, choose -std=c++11
            int cnt = 1;
            i = j + 1;
            while(cnt != 0)
                if(s[++j] == ']') cnt--;
                else if(s[j] == '[') cnt++;
            while(k--) res += decodeString(s.substr(i, j - i));  // 放入[a2[c]b]
            i = ++j;
        }
        return res;
    }
};

//数字栈+字符串栈
class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack <int> nums;
        stack <string> strs;
        int num = 0;
        int len = s.size();
        for(int i = 0; i < len; ++ i)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + s[i] - '0';
            }
            else if((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z'))
            {
                res = res + s[i];
            }
            else if(s[i] == '[') //将‘[’前的数字压入nums栈内， 字母字符串压入strs栈内
            {
                nums.push(num);
                num = 0;
                strs.push(res); 
                res = "";
            }
            else //遇到‘]’时，操作与之相配的‘[’之间的字符，使用分配律
            {
                int times = nums.top();
                nums.pop();
                for(int j = 0; j < times; ++ j)
                    strs.top() += res;
                res = strs.top(); //之后若还是字母，就会直接加到res之后，因为它们是同一级的运算
                                  //若是左括号，res会被压入strs栈，作为上一层的运算
                strs.pop();
            }
        }
        return res;
    }
};

// 作者：youlookdeliciousc
// 链接：https://leetcode-cn.com/problems/two-sum/solution/ti-jie-czhan-by-youlookdeliciousc/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


// 单个栈，思路是一样的
class Solution {
public:
    struct Iterator
    {
        int count;
        string str;
        Iterator(int c):count(c), str() {}
    };

    string decodeString(string s) {
        int count=0;
        stack<Iterator> ss;
        ss.push(Iterator(1));
        for (int i=0; i<s.length(); ++i) {
            if (s[i]>='0' && s[i]<='9') {
                count = count*10+s[i]-'0';
            } else if (s[i] == '[') {
                ss.push(Iterator(count));
                count = 0;
            } else if (s[i] == ']') {
                auto cur = ss.top(); 
                ss.pop();
                while (cur.count>0) {
                    ss.top().str += cur.str;  // point
                    cur.count--;
                }
            } else {
                ss.top().str += s[i];
            }   
        }

        return ss.top().str;
    }
};


// 这个题解也不错
// https://blog.csdn.net/NichChen/article/details/78090356 [递归 + stack]
