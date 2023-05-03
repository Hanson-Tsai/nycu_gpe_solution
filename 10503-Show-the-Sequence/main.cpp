#include <iostream>
#include <cctype>
#include <vector>
#include <stack>

using namespace std;

void parse(string &s, int n){
    vector<long long> result(n, 0);
    stack<char> oper;
    stack<int> dig;

    // cout << "Start parsing" << endl;

    for(int i=0; i<s.size(); ++i){
        if(s[i] == ']' || s[i] == '['){
            continue;
        }else if(s[i] == '-'){
            i++;
            int num = 0;
            while(isdigit(s[i]) && i<s.size()){
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            dig.push(num * (-1));
            // cout << (-1) * num << endl;
        }else if(isdigit(s[i])){
            int num = 0;
            while(isdigit(s[i]) && i<s.size()){
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            dig.push(num);
            // cout << num << endl;
        }else if(s[i] == '+'){
            oper.push('+');
            // cout << '+' << endl;
        }else if(s[i] == '*'){
            oper.push('*');
            // cout << '*' << endl;
        }else{
            cout << "Unknown input char" << endl;
        }
    }

    int base = dig.top();
    dig.pop();
    for(int i=0; i<result.size(); ++i){
        result[i] = (long long)base;
    }

    while(!oper.empty() || !dig.empty()){
        int num = dig.top();
        char op = oper.top();
        dig.pop();
        oper.pop();

        long long prev;

        if(op == '+'){
            for(int i=0; i<result.size(); i++){
                if(i==0){
                    long long tmp = result[i];
                    result[i] = (long long)num;
                    prev = tmp;
                }else{
                    long long tmp = result[i];
                    result[i] = result[i-1] + prev;
                    prev = tmp;
                }
            }
        }else if(op == '*'){
            for(int i=0; i<result.size(); i++){
                if(i==0){
                    result[i] = (long long)num * result[i];
                }else{
                    result[i] = (long long)result[i-1] * result[i];
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
        printf("%lld%c", result[i], i == n - 1 ? '\n' : ' ');

    return;
}

int main() {
    string s;
    int n;

    while(cin >> s){
        cin >> n;
        parse(s, n);
    }

    return 0;
}