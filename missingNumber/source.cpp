#include <iostream>
#include <vector>

using namespace std;

vector<int> parseIntVec(){
    vector<int> v;
    std::string input;
    std::cin>>input;
    int start = 0;
    string del = ",";
    int end = input.find(del);
    int first = 0;
    while (end != -1) {
        if (first==0) {
            first=1;
            string ss = input.substr(start, end - start);
            //std::cout << ss << std::endl;
            int len = ss.length();
            ss.erase(ss.begin() + 0, ss.end()-(len-1));
            //cout<<ss<<endl;
            v.push_back(int(stoi(ss)));
        }
        else{
            //cout << input.substr(start, end - start) << endl;
            vector<string> vi;
            string ss = input.substr(start, end - start);
            v.push_back(int(stoi(ss)));
        }
        start = end + del.size();
        end = input.find(del, start);
    }
    //cout << input.substr(start, end - start);
    string ss2 = input.substr(start, end - start);
    int len2 = ss2.length();
    ss2.erase(ss2.begin() + len2-1, ss2.end());
    //cout<<ss2<<endl;
    v.push_back(int(stoi(ss2)));
    std::cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        if (i!=0) {
            std::cout <<",";
        }
        std::cout << v[i];
    }
    std::cout << "]" << std::endl;
    return v;
}

int missingNumber(vector<int>& nums){
     sort(nums.begin(),nums.end());
     for (int i = 0; i < nums.size(); ++i) {
        if (i!=nums[i]) {
           return i; 
        } 
     }
     return nums.size();   int sum = 0;
}

int main(int argc, char *argv[])
{
    vector<int> v = parseIntVec();
    int ans = missingNumber(v);
    std::cout << "Missing number is " <<ans<< std::endl;
    return 0;
}
