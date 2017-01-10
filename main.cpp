#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

struct ListNode {
    int val;
    std::shared_ptr<ListNode> next;

    ListNode(int v, const std::shared_ptr<ListNode> & nx = nullptr)
	: val(v), next(nx) {}
};

using pNode = std::shared_ptr<ListNode>;

pNode createList(const std::vector<int> & nums) {
    pNode head = nullptr;
    std::for_each(nums.rbegin(), nums.rend(),
		  [&](int i){
		      head = std::make_shared<ListNode>(i, head);
		  });
    return head;
}

void printList(const pNode & head) {
    if (head != nullptr) {
	std::cout << head->val << "->";
	printList(head->next);
    }
    else
	std::cout << "null\n";
}

class solution {
public:
    solution (const pNode & head)
	: begin(head) {}

    int getRandom() {
	
    }

private:
    pNode curr;
};

