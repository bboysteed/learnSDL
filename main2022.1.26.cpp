//
// Created by steed on 2022/1/25.
//
#include <unordered_map>
#include "iostream"
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    unordered_map<Node*,Node*> cacheMap;
    Node* copyRandomList1(Node* now) { //using recursion and hash list
        if (!now) return nullptr;
        if (!cacheMap.count(now)){//该节点没有被创建
            auto newnow = new Node(now->val);
            cacheMap[now] = newnow;
            newnow->next = copyRandomList1(now->next);
            newnow->random = copyRandomList1(now->random);
        }

        return cacheMap[now];//已创建 直接返回该节点

    }
    Node* copyRandomList2(Node* head) { //using hash list
        if (!head) return nullptr;
        auto cur=head;
        while(cur){
            auto newHead = new Node(cur->val);
            cacheMap[cur] = newHead;
            cur = cur->next;
        }//先遍历  创建所有节点

        //接下来再增加指向关系
        cur = head;
        while(cur){
            cacheMap[cur]->next = cacheMap[cur->next];
            cacheMap[cur]->random = cacheMap[cur->random];
            cur = cur->next;
        }
        return cacheMap[head];

    }
};
int main(){
//    cout<<"jell"<<endl;
//    unordered_map<int,int> map;
//    map[3]=4;
//    for (const auto &item: map) {
//        cout<<item.first<<endl;
//        cout<<item.second<<endl;
//    }
//    cout<<map.count(3)<<endl;
}
