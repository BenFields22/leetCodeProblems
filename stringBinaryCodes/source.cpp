#include <iostream>
#include <math.h>
#include <unordered_set>

using namespace std;

bool hasAllCodes(string s, int k) {
        if(s.length()<k)    return false;
        unordered_set<string> store;
        for(int i=0;i<=s.length()-k;i++)
            store.insert(s.substr(i,k));
        return store.size() == pow(2,k);
}


int main(int argc, char** argv){
    std::string input;
    std::cin>>input;
    std::string s = input.substr(1,input.length()-2);
    int k;
    std::cin>>k;
    std::cout << "\nString is: "<<s<<" and k is "<<k << std::endl;

    bool ans = hasAllCodes(s,k);
    std::cout << "ANSWER: "<<ans << std::endl;
    
	return 0;
}
