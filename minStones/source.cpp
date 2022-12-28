#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include "Utils.hpp"
Logger* g_log = new Logger("MAIN",1,Color::RED);

int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> heap(piles.begin(), piles.end());
    int totalSum = accumulate(piles.begin(), piles.end(), 0);
    for (int i = 0; i < k; i++) {
        int curr = heap.top();
        heap.pop();
        int remove = curr / 2;
        totalSum -= remove;
        heap.push(curr - remove);
    }
    
    return totalSum;
}

int main(int argc, char** argv){
    int n;
    std::cin>>n;
    std::cout << std::endl;
    log(g_log,"Running "+to_string(n)+" Test Cases");
    for (int i = 0; i < n; ++i) {
        log(g_log,"----------------------------");
        string t ="";
        t="Case "+to_string(i+1)+" inputs:";
        log(g_log,t);
        std::vector<int> v = parseIntVec();
        int k;
        std::cin>>k;
        log(g_log,to_string(k));
        t="";
        int ans = minStoneSum(v,k);
        t="Answer: "+to_string(ans);
        log(g_log,t);
    }
    log(g_log,"----------------------------");
	return 0;
}
