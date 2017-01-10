#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <ctime>
#include <cstdlib>

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
	: begin(head), curr(head) {}

    int getRandom() {
        srand(time(NULL));
        pNode next = curr->next;
        if (next == nullptr)
            next = begin;
        while (next != nullptr) {
            int range = distance(begin,next)+1;
            int rnd = int(rand())%range;
            // std::cout << "range = " << range << ", rnd = " << rnd << "; ";
            if (rnd == 1)
                curr = next;
            next = next->next;
            // std::cout << curr->val << ";";
        }
        return curr->val;
    }

  private:
    int distance(const pNode & head, const pNode & np) {
        int dist = 0;
        pNode p = head;
        while (p != nullptr && p != np) {
            dist++;
            p = p->next;
        }
        return dist;
    }

private:
    pNode begin, curr;
};

int main() {
    std::vector<int> nums{1,2,3,4,5};
    pNode head = createList(nums);
    printList(head);

    solution soln(head);

    for (size_t i = 0; i < nums.size(); i++)
        std::cout << soln.getRandom() << " ";
    std::cout << std::endl;
}
