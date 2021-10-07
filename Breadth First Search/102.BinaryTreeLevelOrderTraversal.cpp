vector<vector<int>> levelOrder(TreeNode *root)
{
    if (!root)
        return {}; // return if root is null
    queue<TreeNode *> q;
    q.push(root);            //push the root node.
    vector<vector<int>> out; //result vector

    /*
		 * Idea is to create a vector for every level based on the queue size.
		 * eg: if a level has four elements say 1, 2, 3, 4 -> Then create a vector of size 4.
		 * 
		 * note: size of the queue is computed before the loop, so that we don't consider 
		 * newly pushed elements.
		 */

    while (!q.empty())
    {

        int sz = q.size();    /* current queue size */
        vector<int> curr(sz); /* vector of size sz */

        for (int i = 0; i < sz; i++)
        {
            TreeNode *tmp = q.front();
            q.pop();
            curr[i] = tmp->val; /* insert to the correct index */

            /* Add the left & right nodes to the queue in the loop. */
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
        out.push_back(curr); /* once the level is done, push the vector to output vector. */
    }
    return out;
}