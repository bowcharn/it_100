/*
2014.3.14
关于二叉树和BST（Binary Search Tree）的基本操作和常见问题解决，
目前主要应用了递归：
非递归方式暂时没有给出

2014.3.19:
添加了二叉查找树的删除函数




题目：二叉树的结点定义如下：

struct TreeNode
{
    int m_nvalue;
    TreeNode* m_pLeft;
    TreeNode* m_pRight;
};
输入二叉树中的两个结点，输出这两个结点在数中最低的共同父结点。


函数原型：
tree_node* find_nearest_common_parent_node_2(tree_node* root, 
									int node_key1, int node_key2)

*/

#include <iostream>
#include <cassert>
#include <climits>
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

bool search(tree_node* T, int key)
{
	/*
Given a binary tree, return true if a node
with the target data is found in the tree. Recurs
down the tree, chooses the left or right
branch by comparing the target to each node.
*/


	// 1. Base case == empty tree;
	// in that case , the target is not found so return false
	if(T == NULL)
	return false;
	else
	{
		//2. see if found here
		if(key == T->data) return true;
		else 
		{
			//3.otherwise recur down the correct subtree
			if(key < T->data) return search(T->left, key);
			else return search(T->right, key);
		}
	}
}


void insert(tree_node* & T, int data)
{

	tree_node* add_node = new tree_node(data);
	if(T == NULL)
	{
		std::cout<<"insert as Ptr is NULL::::"<< data<<std::endl;
		T = add_node;      
	}

	else if(data <= T->data)
	insert(T->left,data);
	else
	insert(T->right,data);
}


void create_tree(tree_node* & T_root, int ary[], int n)
{
	for(int i = 0; i < n ; ++i)
	insert(T_root, ary[i]);
}

int size(tree_node * T)
{
	/*
	compute the number of nodes in a tree
*/
	if(T!=NULL)
	{
		int l_size = size(T->left);
		int r_size = size(T->right);
		return l_size + r_size +1;
	}
	else
	return 0;
}

int max_depth(tree_node* T)
{
	/*
	Compute the "max depth" of a tree -- the number of nodes along
	the longest path from the root node down to the farthest leaf node
*/
	if(T!=NULL)
	{
		int l_max_depth = max_depth(T->left);
		int r_max_depth = max_depth(T->right);
		
		if(l_max_depth >= r_max_depth)
		return l_max_depth + 1;
		else
		return r_max_depth + 1;
	}
	else
	return 0;
}


int max_value(tree_node* T)
{
	/*
	given  a non-empty binary search tree,
	return the minimum data value found in taht tree.
	Note that the entire tree does not need to be searched
*/
	assert(T!=NULL);

	while(T->right!=NULL)
	T= T->right;

	return T->data;

}

int min_value(tree_node* T)
{
	assert(T!=NULL);

	while(T->left!=NULL)
	T = T->left;

	return T->data;
}

void inorder_traverse(tree_node* T)  // preorder_traverse and postorder_traverse
{
	if(T!=NULL)
	{
		inorder_traverse(T->left);
		std::cout<<T->data<<" ";
		inorder_traverse(T->right);
	}

}

bool has_path_sum(tree_node* T, int sum)
{
	/*
Given a tree and a sum, return true if there is a path from the root
down to a leaf, such that adding up all the values along the path
equals the given sum.
Strategy: subtract the node value from the sum when recurring down,
and check to see if the sum is 0 when you run out of tree.
*/

	bool l_has = false;
	bool r_has = false;
	if(T!=NULL)
	{
		if((T->data == sum) &&(T->left == NULL) &&(T->right == NULL))
		return true;
		l_has = has_path_sum(T->left, sum - T->data);
		r_has = has_path_sum(T->right, sum - T->data);
	}

	return l_has || r_has;
}

void print_each_path(int path[], int path_len)
{
	for(int i = 0; i < path_len; ++i)
	std::cout<<path[i]<<" ";
	std::cout<<std::endl;
}


void print_paths_recursive(tree_node* T, int path[], int path_len)
{

	/* path_len is the position of T->data;*/
	/*
Recursive helper function -- given a node, and an array containing
the path from the root node up to but not including this node,
print out all the root-leaf paths.
*/


	if(T == NULL) return;

	//append this node to the path array  
	path[path_len] = T->data;
	path_len++;

	// it's a leaf , so print the  path that led to here
	if((T->left == NULL)&&(T->right == NULL))  // get leaf node
	print_each_path(path, path_len);
	else
	{
		//otherwise try both subtrees
		print_paths_recursive(T->left, path, path_len);
		print_paths_recursive(T->right, path, path_len);
	}
}



void print_paths(tree_node* T)
{
	/*
	given a binary tree, print out all of its root-to-leaf
	paths, one per line. Uses a recursive helper to do the work
*/
	int tree_size = size(T);
	int* path = new int[tree_size];

	print_paths_recursive(T, path, 0);

	delete [] path;
}

void mirror(tree_node* T)
{
	/*
Change a tree so that the roles of the
left and right pointers are swapped at every node.
So the tree...
			4
			/ \
			2   5
		/ \
		1   3
is changed to...
			4
			/ \
			5   2
			/ \
			3   1
*/

	if(T!=NULL)
	{
		mirror(T->left);
		mirror(T->right);

		tree_node* swap_node = T->left;
		T->left = T->right;
		T->right = swap_node;
	}
}

void double_tree(tree_node* T)
{
	/*
For each node in a binary search tree,
create a new duplicate node, and insert
the duplicate as the left child of the original node.
The resulting tree should still be a binary search tree.
So the tree...
				2
				/ \
				1   3
Is changed to...
				2
				/ \
				2   3
				/    /
			1    3
			/
			1
*/

	if(T!=NULL)
	{
		tree_node * l_change_node = T -> left;
		tree_node * r_change_node = T ->right; 
		tree_node * add_node = new tree_node(T->data);
		add_node -> left = T->left;
		T->left = add_node;
		double_tree(l_change_node);
		double_tree(r_change_node);
	}
}


bool same_trees(tree_node* a, tree_node* b)
{
	/*
Given two trees, return true if they are
structurally identical.
*/
	if(a==NULL && b==NULL) 
	return true;
	else  if(a!=NULL && b!=NULL)
	{
		return (
		a->data == b->data &&
		same_trees(a->left, b->left)&&
		same_trees(a->right, b->right)
		);
	}
	else 
	return false;

}

int count_trees(int num_keys)
{
	int sum = 0;
	if(num_keys == 1)
	sum = 1;
	else
	{
		sum = 2*count_trees(num_keys-1);
		for(int i = 2; i<=num_keys-1;++i)
		{
			sum+= count_trees(i-1);
			sum+= count_trees(num_keys-i);
			if(i == 2 || i==num_keys-1) sum-=1;
			
		}
	}
	return sum;
}

int count_trees_2(int numKeys) 
{
	/*
For the key values 1...numKeys, how many structurally unique
binary search trees are possible that store those keys.

Strategy: consider that each value could be the root.
Recursively find the size of the left and right subtrees.
*/
	if (numKeys <=1) 
	return(1);
	else 
	{
		// there will be one value at the root, with whatever remains
		// on the left and right each forming their own subtrees.
		// Iterate through all the values that could be the root...
		int sum = 0;
		int left, right, root;
		for (root=1; root<=numKeys; root++) {
			left = count_trees_2(root - 1);
			right = count_trees_2(numKeys - root);
			// number of possible trees with this root == left*right
			sum += left*right;
		}
		return(sum);
	}
}


bool is_bst1(tree_node* T)
{
	/*
Returns true if a binary tree is a binary search tree.
*/

	if(T!=NULL)
	{
		bool is_leaf = (T->left ==NULL) && (T->right == NULL);
		if(is_leaf) 
		return true;

		if(max_value(T) <= T->data && T->right !=NULL)
		return false;
		
		if(min_value(T) > T->data && T->left!=NULL)
		return false;

		if(!is_bst1(T->left))
		return false;

		if(!is_bst1(T->right))
		return false;

		return true;
	}
	else
	return true;
}


bool is_bst_recursive(tree_node* T, int min, int max)
{
	/*
Returns true if the given tree is a BST and its
values are >= min and <= max.
*/
	if(T!=NULL)
	{
		if(!(min<=T->data && max>=T->data))
		return false;
		
		if(!is_bst_recursive(T->right, T->data+1, max))
		return false;

		if(!is_bst_recursive(T->left, min, T->data))
		return false;

		return true;	
	}
	else 
	return true;
}


bool is_bst2(tree_node* T)
{
	return is_bst_recursive(T,INT_MIN,INT_MAX);
}


tree_node* delete_node(tree_node* T, int key)
{
	/*
INPUT:
	tree which a node(node key is 'key') will deleted from 
RETURN:
	a tree_node which has deleted the 'key' node;
	
*/
	if(T == NULL)
	return NULL;
	
	tree_node* current;	
	if(key < T->data)
	T->left = delete_node(T->left, key);   // delete from left child
	else if(key > T->data)
	T->right = delete_node(T->right, key); // delete from right child
	else
	{
		if(T->left == NULL)       // left is NULL, link the T's right child as T's root
		{
			current = T->right;
			delete T;
			T = current;
		}
		else if(T->right == NULL)
		{
			current = T->left;
			delete T;
			T = current;
		}
		else   // two children
		{
			current = T->right;
			tree_node* parent = NULL;
			
			while(current->left!=NULL)
			{
				parent = current;
				current = current->left;
			}
			T->data = current ->data;
			if(parent != NULL)
			parent->left = delete_node(parent->left,parent->left->data);   
			else
			T->right = delete_node(T->right,T->right->data);
			
		}
	}
	return T;
}



//能够处理节点在二叉树中的情况
tree_node* find_nearest_common_parent_node(tree_node* root, 
									int node_key1, int node_key2)
{
	if(root == NULL)
	return NULL;
	if(root -> data == node_key1 || root->data == node_key2)
	return root;
	
	tree_node* pleft = find_nearest_common_parent_node(root->left, node_key1,
	node_key2);
	tree_node* pright = find_nearest_common_parent_node(root->right, node_key1,
	node_key2);
	
	if(pleft == NULL)
	return pright;
	else if(pright == NULL)
	return pleft;
	else
	root;
	
	
}


//该方法在树退化为线性表的时候是不对的A->B->C->D时B、C的父节点应该是A而
//不是没有或者是A
tree_node* lca = NULL;
int traverse(tree_node* p, int node_key1, int node_key2) {
	if (!p) return 0;
	if (p ->data== node_key1 || p ->data== node_key2) return 1;
	int res = traverse(p->left, node_key1, node_key2) + 
	traverse(p->right, node_key1, node_key2);
	if (res == 2 && lca == NULL) lca = p;
	return res;
}



#include <vector>

bool get_node_path(tree_node* root, int node_key , std::vector<tree_node*>& tree_path)
{
	if(root == NULL)
		return false;
		
	if(root -> data == node_key)
		return true;
	
	tree_path.push_back(root);
	
	bool found = false;
	if(root->left != NULL)
		found = get_node_path(root->left, node_key, tree_path);
	if(!found && root->right)
		found = get_node_path(root->right, node_key, tree_path);
	
	if(!found)
		tree_path.pop_back();
		
	return found;
}


tree_node* last_common_node(const std::vector<tree_node*>& path1, 
							const std::vector<tree_node*>& path2){
							
	std::vector<tree_node*>::const_iterator iterator1 = path1.begin();
    std::vector<tree_node*>::const_iterator iterator2 = path2.begin();
	
	
	std::cout<<"size ..."<<path1.size()<<"  "<<path2.size()<<std::endl;
	//std::cout<<(*iterator1)->data<<" "<<(*iterator2)->data<<std::endl;
   
    tree_node* pLast = NULL;
 
    while(iterator1 != path1.end() && iterator2 != path2.end())
    {
        if(*iterator1 == *iterator2)
            pLast = *iterator1;
 
        iterator1++;
        iterator2++;
    }
 
    return pLast;						
}


//该函数能够处理所有的情况。。。厉害
tree_node* find_nearest_common_parent_node_2(tree_node* root, 
									int node_key1, int node_key2)
{
    if(root == NULL)
        return NULL;
 
    std::vector<tree_node*> path1;
    get_node_path(root, node_key1, path1);
 
    std::vector<tree_node*> path2;
    get_node_path(root, node_key2, path2);
 
    return last_common_node(path1, path2);
}


int main()
{
	int ary[10] = {9,23,45,1,2,5,21,16,78,43};
	int ary2[10] = {9,23,45,31,2,5,21,16,78,43};
	int ary3[3] = {2,1,3};

	//int ary[3] = {2,1,3};
	tree_node* tree = NULL;
	tree_node* tree2 = NULL;
	tree_node* tree3 = NULL;
	create_tree(tree, ary, 10);
	create_tree(tree2, ary2, 10);
	create_tree(tree3, ary3, 3);

	tree_node* res =  find_nearest_common_parent_node_2(tree, 2, 5);
	/*tree_node* first_node = new tree_node(94);
	tree_node* second_node = new tree_node(5);
	int found = 0;
	tree_node* res = LowestCommonAncestor(tree, first_node, second_node, found);*/
	std::cout<<((res != NULL)? ("find parent"):("can't find one'"))<<std::endl;
	if(res)
	std::cout<<"parent:::"<<res->data<<std::endl;

	// std::cout<<std::endl;
	// tree = delete_node(tree,95);

	// print_paths(tree);
	// std::cout<<std::endl;
	/*
std::cout<<"Size of tree::"<<size(tree)<<std::endl;
std::cout<<"max depth of tree::"<<max_depth(tree)<<std::endl;
std::cout<<"max value of tree::"<<max_value(tree)<<std::endl;
inorder_traverse(tree);
std::cout<<std::endl;
std::cout<<"sum 69 has ? ::"<<(has_path_sum(tree, 69)?"Yes":"No")<<std::endl;

print_paths(tree);


double_tree(tree);
inorder_traverse(tree);
std::cout<<std::endl;


std::cout<<"Are two trees same::"<<(same_trees(tree, tree2)?"Yes":"No")<<std::endl;



std::cout<<"Is tree a bst:::"<<(is_bst2(tree)?"Yes" : "No")<<std::endl;
mirror(tree);
std::cout<<"After mirror operation:: Is tree a bst::"<<(is_bst2(tree)?"Yes" : "No")<<std::endl;


mirror(tree);
print_paths(tree);
inorder_traverse(tree);


std::cout<<"5 num_keys :: trees number:: "<<count_trees(5)<<std::endl;*/


	return 0;
}




