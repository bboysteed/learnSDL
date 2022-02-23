/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//#include <iostream>
//#include <vector>
//struct ListNode {
//    int val;
//    ListNode *next;
//
//    ListNode(int x) : val(x), next(NULL) {}
//};
//using namespace std;
//class Solution {
//public:
//    vector<int> tmp;
//    vector<int> ans;
//
//    vector<int> reversePrint(ListNode *now) {
//        while (now) {
//            tmp.push_back(now->val);
//            now = now->next;
//        }
//        while(!tmp.empty()){
//            int num = tmp.at(tmp.size()-1);
//            tmp.pop_back();
//            ans.push_back(num);
//        }
//        return ans;
//    };
//};
//
//int main(){
//    auto *list = new ListNode(1);
//    list->next = new ListNode(3);
//    list->next->next = new ListNode(2);
//    Solution sln;
//    auto res = sln.reversePrint(list);
//    for (int i = 0; i < res.size(); ++i) {
//        cout<<res.at(i)<<endl;
//    }
//
//}


//**************************************************************************************************************
#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> tmp;
    ListNode* reverseList1(ListNode* now) { //myself
        while(now){
            tmp.push_back(now->val);
            now = now->next;
        }
        auto *shao = new ListNode(-1);
        ListNode *now=shao;

        while(!tmp.empty()){

            auto *tmpNode = new ListNode(tmp[tmp.size()-1]);
            tmp.pop_back();
            // now->next = new ListNode(num);
            now->next = tmpNode;
            now = now->next;
        }
        return shao->next;

    }
    ListNode *reverseListNode2(ListNode *now){ //use two pointer
        ListNode *pre= nullptr;
        ListNode *cur = now;
        while(cur){
            auto tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    ListNode* recur(ListNode *node,ListNode *node2){
        if (node){  //5,4  //4,3   3,2     2,1   1,nullptr
            auto ans = recur(node->next,node);
            node->next = node2;
//            cout<<ans->val<<endl;
            return ans;
        }else{
            return node2;
        }
    }
    ListNode *reverseListNode3(ListNode *now){ //use recursion
        return recur(now, nullptr);

    }
};

int main(){
    Solution sln;
    auto *now = new ListNode(1);
    now->next = new ListNode(2);
    now->next->next = new ListNode(3);
    now->next->next->next = new ListNode(4);
    now->next->next->next->next = new ListNode(5);

    auto ans = sln.reverseListNode3(now);
    while(ans){
        cout<<ans->val<<endl;
        ans = ans->next;
    }
    return 0;
}