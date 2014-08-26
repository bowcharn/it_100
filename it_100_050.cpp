/*
Given two binary trees, check if the first tree is subtree of the 
second one. A subtree of a tree T is a tree S consisting of a node in 
T and all of its descendants in T. The subtree corresponding to the 
root node is the entire tree; the subtree corresponding to any other 
node is called a proper subtree.for example:
 Tree S
          10
        /    \
      4       6
       \
        30
Tree T
              26
            /   \
          10     3
        /    \     \
      4       6      3
       \
        30
Strategy:
Traverse the tree T in inorder fashion.  For every visited node in the 
traversal, see if the subtree rooted with this node is identical to S
 
Steps:
1.Check the tree with root as current node
2.If the tree with root as current node doesn't match then
       try left and right subtrees one by one

*/

struct tree_node
{
  tree_node()
  {
    data = 0;
    left = right = NULL;
  }
  tree_node(int init_data){
    data = init_data;
    left = right = NULL;
  }
  int data;   //as Key
  struct tree_node* left;
  struct tree_node* right;
};

bool are_identical(const tree_node* root1, const tree_node* root2)
{
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 == NULL || root2 == NULL)
		return false;
	
	return (root1->data == root2->data &&
			are_identical(root1->left,root2->left)&&
			are_identical(root1->right, root2->right));
}

bool is_subtree(const tree_node* T , const tree_node* S)
{
	if(S == NULL)
		return true;
	if(T == NULL)
		return false;
	
	if(are_identical(T, S))
		return true;
		
	return is_subtree(T->left, S) || is_subtree(T->right, S);
}