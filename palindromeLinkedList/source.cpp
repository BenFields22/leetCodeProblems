#include <iostream>
#include <vector>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode* next;
} ListNode;


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

bool isPalindrome(ListNode* head){
        ListNode* curr = head;
        vector<int> memory;
        while(curr){
            memory.push_back(curr->val);
            curr=curr->next;
        }
        reverse(memory.begin(),memory.end());
        curr=head;
        int index = 0;
        while(curr){
            if(memory[index]==curr->val){
                curr=curr->next;
                index++;
            }
            else{
                return false;
            }
        }
        return true;
}

ListNode* newNode(int key, ListNode* next)
{
    // allocate a new node in a heap and set its data
    ListNode* node = new ListNode();
    node->val = key;

    // set the `.next` pointer of the new node to point to the current
    // // first node of the list.
    node->next = next;

    return node;
}

ListNode* constructList(vector<int> const &keys)
{
    ListNode* head, *node = nullptr;

    // start from the end of the array
    for (int i = keys.size() - 1; i >= 0; i--)
    {
        node = newNode(keys[i], node);
        head = node;
    }

    return head;
}

int main(int argc, char** argv){
    int n;
    cin>>n;
    std::cout << n<<" Test Cases" << std::endl;
    std::cout <<"------------------------" << std::endl;
    for (int i = 0; i < n; ++i) {    
        vector<int> values = parseIntVec();
        ListNode* head = constructList(values); 
        bool result = isPalindrome(head);
        if (result) {
        std::cout << "Yes it is a palindrome." << std::endl; 
        }
        else{
            std::cout << "No it is not a palindrome." << std::endl;
        }
        std::cout <<"------------------------" << std::endl;

    }
    return 0;
}
