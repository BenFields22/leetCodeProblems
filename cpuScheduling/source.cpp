#include <iostream>
#include "Utils.hpp"
#include <queue>

Logger* g_log = new Logger("MAIN",1,Color::RED);

typedef struct event{
    int index;
    long queuePos;
    long procTime;
}event;

struct less_than_key
{
    inline bool operator() (const event& a, const event& b)
    {
        return (a.queuePos < b.queuePos);
    }
};

class Compare{
    public:
        bool operator() (event a, event b)
        {
            if(a.procTime==b.procTime){
                return a.index>b.index;
            }
            else{
                return a.procTime>b.procTime;
            }
        }
};

std::vector<int> getOrder(std::vector<std::vector<int>>& tasks){
        std::vector<int> ans;
        std::deque<event> deq;
        std::priority_queue<event, std::vector<event>, Compare> avail;
        for(int i=0;i<tasks.size();i++){
            event *tmp = new event();
            tmp->index = i;
            tmp->queuePos=tasks[i][0];
            tmp->procTime=tasks[i][1];
            deq.push_back(*tmp);
        }
        std::sort(deq.begin(),deq.end(),less_than_key());
        long time = 1;
        int processedJobs=0;
        while(processedJobs<tasks.size()){
            int done=0;
            while(!done){
                if(deq.size()==0){
                    done=1;
                    continue;
                }
                else if(deq.front().queuePos <= time){
                    avail.push(deq.front());
                    deq.pop_front();
                }
                else{
                    done=1;
                }
            }
            if(avail.size()==0){
                time=deq.front().queuePos;
                continue;
            }
            event job = avail.top();
            avail.pop();
            ans.push_back(job.index);
            time+=job.procTime;
            processedJobs++;
        }
        return ans;
}

int main(int argc, char** argv){
    int n;
    std::cin>>n;
    for (int i = 0; i < n; ++i) {
        std::cout<<"----------------------------------"<<std::endl;
        std::string l="Test Case "+std::to_string(i+1);
        log(g_log,l);
        std::vector<std::vector<int>> v = parse2DVecInt();
        std::string expected;
        std::cin>>expected;
        std::vector<int> ans = getOrder(v);
        log(g_log,"The index order is:");
        printVecNum(ans);
        log(g_log,expected+" was expected.");
        std::vector<int> expVec = convertToIntVec(expected);
        if(expVec==ans){
            log(g_log,"PASSED");
        }
        else{
            log(g_log,"FAILED");
        }
    }
	return 0;
}
