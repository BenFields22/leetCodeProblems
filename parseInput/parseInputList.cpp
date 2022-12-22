#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <stdio.h>
using namespace std;

int bSearch(vector<int>& vec, int maxVal, vector<vector<int>>& envelopes, int i){
    int l = 0;
    int r = maxVal;
        
    int temp = maxVal;
        
    while(l <= r){
        int mid = l + (r - l) / 2;
            
        if(vec[mid] < envelopes[i][1])
            l = mid + 1;
            
        else {
            temp = mid;
            r = mid - 1;
        }
    }
        
    return temp;
}
    
    // to sort in decreasing order
static bool decSort(vector<int>& v1, vector<int>& v2) {
    if(v1[0] == v2[0])
        return v1[1] > v2[1];
        
    return v1[0] < v2[0];
}
    
int maxEnvelopes(vector<vector<int>>& envelopes) {
    int siz = envelopes.size();
        
    if(siz == 0)
        return 0;
        
    sort(envelopes.begin(), envelopes.end(), decSort);
        
    vector<int> vec(siz, 0);
    int maxVal = 0;
        
    for(int i = 0; i < siz; i++) {
        int pos = bSearch(vec, maxVal, envelopes, i);
            
        vec[pos] = envelopes[i][1];
            
        if(pos == maxVal)
            maxVal++;
    }
        
    return maxVal;
}

void SplitString(string s, vector<string> &v,char del){
	
	string temp = "";
	for(int i=0;i<s.length();++i){
		
		if((char)s[i]==del){
			v.push_back(temp);
			temp = "";
		}
		else{
			temp.push_back(s[i]);
		}
		
	}
	v.push_back(temp);
}

vector<int> convertStoI(vector<string> v){
    vector<int> vi;
    for (int i = 0; i < v.size(); i++) {
        vi.push_back(stoi(v[i]));
    }
    return vi;
}

vector<vector<int>> parseInput(){
    std::string input;
    std::cin>>input;
    std::vector<std::vector<int> > v;
    int start = 0;
    string del = "],[";
    int end = input.find(del);
    int first = 0;
    while (end != -1) {
        if (first==0) {
            first=1;
            string ss = input.substr(start, end - start);
            //std::cout << ss << std::endl;
            int len = ss.length();
            ss.erase(ss.begin() + 0, ss.end()-(len-2));
            //cout<<ss<<endl;
            vector<string> vi;
            SplitString(ss,vi,',');
            vector<int> t = convertStoI(vi);
            v.push_back(t);
        }
        else{
            //cout << input.substr(start, end - start) << endl;
            vector<string> vi;
            string ss = input.substr(start, end - start);
            SplitString(ss,vi,',');
            vector<int> t = convertStoI(vi);
            v.push_back(t);
        }
        start = end + del.size();
        end = input.find(del, start);
    }
    //cout << input.substr(start, end - start);
    string ss2 = input.substr(start, end - start);
    int len2 = ss2.length();
    ss2.erase(ss2.begin() + len2-2, ss2.end());
    //cout<<ss2<<endl;
    vector<string> vi;
    SplitString(ss2,vi,',');
    vector<int> t = convertStoI(vi);
    v.push_back(t);
    for (int i = 0; i < v.size(); ++i) {
        std::cout << "["<<v[i][0]<<","<<v[i][1]<<"]"; 
    }
    std::cout  << std::endl;
    return v;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> v = parseInput();
    int ans = maxEnvelopes(v);
    std::cout<<"\nMax dolls v1 is "<<ans<<std::endl;
    
    return 0;
}
