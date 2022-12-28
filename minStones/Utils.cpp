#include "Utils.hpp"

Logger* u_log = new Logger("UTIL",1,Color::BLUE);

#ifdef _WIN32
Logger::Logger(std::string id, int logFlag, int color) {
    loggerId = id;
    loggerFlag = logFlag;
    loggerColor = color;
}

void Logger::print(std::string text) {
    if (loggerFlag == 1) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), loggerColor);
        std::cout << "[" << loggerId << "]";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        std::cout << ": " << text << std::endl;
    }
}
#else
Logger::Logger(std::string id, int logFlag, int color) {
    loggerId = id;
    loggerFlag = logFlag;
    loggerColor = "\033[0;" + std::to_string(color) + "m";
}

void Logger::print(std::string text) {
    if (loggerFlag == 1) {
        std::cout << loggerColor << loggerId << "\033[0;37m" << ": " << text << std::endl;
    }
}

#endif


Logger::~Logger() {
    print("Shutting Down Logger");
}

void log(Logger* log,string s){
    log->print(s);
}

std::vector<int> parseIntVec(){
    vector<int> v;
    std::string input;
    std::cin>>input;
    int start = 0;
    string del = ",";
    int end = input.find(del);
    if(end==-1){
        //log(input);
        string ss = input.substr(1,input.length()-2);
        //log(ss);
        vector<int> v;
        v.push_back(int(stoi(ss)));
        string tmp="Parsed vector ";
        tmp+="[";
        for (int i = 0; i < v.size(); ++i) {
            if (i!=0) {
                tmp+=",";
            }
            tmp+=to_string(v[i]);
        }
        tmp+="]";
        log(u_log,tmp);
        return v;
    }
    int first = 0;
    while (end != -1) {
        if (first==0) {
            first=1;
            string ss = input.substr(start, end - start);
            int len = ss.length();
            ss.erase(ss.begin() + 0, ss.end()-(len-1));
            v.push_back(int(stoi(ss)));
        }
        else{
            vector<string> vi;
            string ss = input.substr(start, end - start);
            v.push_back(int(stoi(ss)));
        }
        start = end + del.size();
        end = input.find(del, start);
    }
    string ss2 = input.substr(start, end - start);
    int len2 = ss2.length();
    ss2.erase(ss2.begin() + len2-1, ss2.end());
    v.push_back(int(stoi(ss2)));
    string tmp="Parsed vector ";
    tmp+="[";
    for (int i = 0; i < v.size(); ++i) {
        if (i!=0) {
            tmp+=",";
        }
        tmp+=to_string(v[i]);
    }
    tmp+="]";
    log(u_log,tmp);
    return v;
}



