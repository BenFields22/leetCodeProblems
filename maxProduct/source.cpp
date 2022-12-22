#include <iostream>
#include <vector>
#include <map>

using namespace std;

std::vector<std::string> parseStringVec(){
    std::vector<std::string> v={};
    std::string input;
    std::cin>>input;
    int start = 0;
    string del = "\",\"";
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
            v.push_back(ss);
        }
        else{
            //cout << input.substr(start, end - start) << endl;
            string ss = input.substr(start, end - start);
            v.push_back(ss);
        }
        start = end + del.size();
        end = input.find(del, start);
    }
    //cout << input.substr(start, end - start);
    string ss2 = input.substr(start, end - start);
    int len2 = ss2.length();
    ss2.erase(ss2.begin() + len2-2, ss2.end());
    //cout<<ss2<<endl;
    v.push_back(ss2);
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

bool isDisjointSet(string one, string two){
 	int arr[26] = {0};
 	for (char c : one) arr[c - 'a']++;

 	for (char c : two) {
 		if (arr[c - 'a']) return false;
 	}
 	return true;
}

int getValue(string a, string b){
    return a.length()*b.length();
}


int maxProduct(vector<string>& words) {
    int max =0;
    for (int i = 0; i < words.size()-1; ++i) {
        for (int j = i+1;  j< words.size(); j++) {
           if (isDisjointSet(words[i],words[j])) {
               int val = getValue(words[i],words[j]);
               if (val>max) {
                   max=val;
               }
           }
        }
    } 
    return max; 
}

int main(int argc, char** argv){
    std::vector<std::string> input = parseStringVec(); 
    int ans = maxProduct(input);
    std::cout << "Ans is: " <<ans<< std::endl; 
	return 0;
}
