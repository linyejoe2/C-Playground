using namespace std;

#include <stack>

int main()
{
    stack<int> nums;

    nums.push(1);
    nums.push(2);
    nums.top(); // peek top val
    nums.pop(); // pop top val
    nums.empty(); // check nums empty or not.
    nums.size(); // get nums size.
}
