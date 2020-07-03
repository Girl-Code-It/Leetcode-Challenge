/* Similar Questions
https://www.sanfoundry.com/c-program-to-find-the-number-of-nodes-in-a-binary-tree/

https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1

https://practice.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree/1

https://www.geeksforgeeks.org/count-full-nodes-binary-tree-iterative-recursive/

https://www.geeksforgeeks.org/count-half-nodes-in-a-binary-tree-iterative-and-recursive/

https://leetcode.com/problems/count-good-nodes-in-binary-tree/
*/

/* Time Complexity :
 Since I halve the tree in every recursive step,
 I have O(log(n)) steps. Finding a height costs O(log(n)). So overall O(log(n)^2).
*/

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
    }
};