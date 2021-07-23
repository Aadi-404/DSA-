// Implementation of Binary Tree
// min function
// Inorder using iteration
// Preorder using iteration
// Postorder using iteration ----->>>> Use two stack ,one for node and one for output
// Mirror of Binary Tree
// left view of Binary Tree
// right view of Binary Tree
// zig zag traversal level order
// tree balanced or not ?

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
class DLL
{
public:
    int data;
    DLL *prev;
    DLL *next;
    DLL(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
};
// node *create(node *root, int value)
// {
//     root = new node;
//     root->data = value;
//     root->left = NULL;
//     root->right = NULL;
//     return root;
//     cout << root->data << endl;
// }

node *insert(node *&root, int data)
{
    if (root == NULL)
    {
        // root = create(root, data);
        root = new node(data);
    }
    else if (root->data >= data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void min(node *&root)
{
    if (root->left == NULL)
    {
        cout << root->data << endl;
    }
    else
    {
        min(root->left);
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> s;
    while (1)
    {
        if (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            if (s.empty())
            {
                break;
            }
            cout << " , " << s.top()->data;

            root = s.top();
            s.pop();
            root = root->right;
        }
    }
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> s;
    while (1)
    {
        if (root->right != NULL)
            s.push(root->right);

        cout << root->data << " , ";

        if (root->left == NULL)
        {
            if (s.empty())
            {
                break;
            }

            root = s.top();
            s.pop();
        }
        else
            root = root->left;
    }
}
node *mirror(node *root)
{
    if (root == NULL)
    {
        return root;
    }
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);

    return root;
}
void leftView(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        cout << q.front()->data << "  ";
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            node *curr = q.front();
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
            q.pop();
        }
    }
}
void rightView(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        cout << q.front()->data << "  ";
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            node *curr = q.front();
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            q.pop();
        }
    }
}

                        // Zig Zag 
void zigZag(node *root)
{
    bool flag = true;
    if (root == NULL)
        return;
    stack<node *> s1;
    stack<node *> s2;
    // queue<node *> q;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        if (flag)
        {
            if (s1.top()->left != NULL)
                s2.push(s1.top()->left);
            if (s1.top()->right != NULL)
                s2.push(s1.top()->right);
            cout << s1.top()->data << "  ";
            s1.pop();
            if (s1.empty())
            {
                flag = false;
            }
        }
        else
        {
            if (s2.top()->right != NULL)
                s1.push(s2.top()->right);
            if (s2.top()->left != NULL)
                s1.push(s2.top()->left);
            cout << s2.top()->data << "  ";
            s2.pop();
            if (s2.empty())
                flag = true;
        }
    }
}

// Balanced or not =----- checking ...

int diff = 0;
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = height(root->left);
    int r = height(root->right);
    diff = max(diff, abs(l - r));
    return max(l, r) + 1;
}
void balanceCheck(node *root)
{
    if (root == NULL)
    {
        return;
    }
    int h = height(root) - 1;
    if (diff > 1)
    {
        cout << "not balanced" << endl;
    }
}
void diagonalTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    node *curr = q.front();
    while (!q.empty())
    {
        cout << curr->data << "  ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right == NULL)
        {
            q.pop();
            curr = q.front();
        }
        else
        {
            curr = curr->right;
        }
    }
}

// Boundary traversal

void leftBoundary(node *root)
{
    if (!root)
    {
        return;
    }
    if (root->left || root->right)
    {
        cout << root->data << "  ";
    }
    else
    {
        return;
    }

    if (root->left)
    {
        leftBoundary(root->left);
    }
    else
    {
        leftBoundary(root->right);
    }
}
void leaf(node *root)
{
    if (!root)
    {
        return;
    }
    leaf(root->left);
    if (!root->left && !root->right)
    {
        cout << root->data << "  ";
    }
    leaf(root->right);
}
void rightBoundary(node *root)
{
    if (!root)
    {
        return;
    }

    if (root->right)
    {
        rightBoundary(root->right);
    }
    else
    {
        rightBoundary(root->left);
    }
    if (root->left || root->right)
    {
        cout << root->data << "  ";
    }
    else
    {
        return;
    }
}
void BoundaryTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    leftBoundary(root);
    leaf(root->left);
    leaf(root->right);
    rightBoundary(root->right);
}

// Binary To DLL

// DLL *head;
// DLL *curr;
// void LL(int data)
// {
//     DLL *n = new DLL(data);
//     if (head == NULL)
//     {
//         head = n;
//         curr = head;
//     }
//     else
//     {
//         curr->next = n;
//         n->prev = curr;
//         curr = curr->next;
//     }
//     return;
// }
// void BinaryToDLL(node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     BinaryToDLL(root->left);
//     LL(root->data);
//     BinaryToDLL(root->right);
//     return;
// }

void Make(node *root, node *&head, node *&prev)
{
    if (!root)
    {
        return;
    }
    Make(root->left, head, prev);

    if (prev == NULL)
    {
        head = root;
    }
    else
    {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    Make(root->right, head, prev);
    return;
}
void display(node *);

node *bToDLL(node *root)
{
    node *head = NULL;
    node *prev = NULL;

    Make(root, head, prev);
    display(head);
    // return head;
}
void display(node *head)
{
    while (head)
    {
        cout << head->data << "  ";
        head = head->right;
    }
    return;
}

int maxSum = -4534543;
int subTreeMax(node *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->right && !root->left)
    {
        return root->data;
    }
    int l = subTreeMax(root->left);
    int r = subTreeMax(root->right);
    int sum = l + r + root->data;
    maxSum = max(sum, maxSum);
    return sum;
}

// Maximum sum of nodes such that no two are adjacent nodes

int sumAlternate(node *root)
{
    if (!root)
    {
        return 0;
    }

    int IncSum = root->data;

    if (root->left)
    {
        IncSum += sumAlternate(root->left->left);
        IncSum += sumAlternate(root->left->right);
    }
    if (root->right)
    {
        IncSum += sumAlternate(root->right->left);
        IncSum += sumAlternate(root->right->right);
    }
    return IncSum;
}
int func(node *root)
{
    if (!root)
    {
        return NULL;
    }
    int sum1 = sumAlternate(root);
    int sum2 = sumAlternate(root->left);
    sum2 += sumAlternate(root->right);
    return max(sum1, sum2);
}
// unordered_map<node *, int> dp;
// int maxSumOfNode(node *root)
// {
//     if (!root)
//     {
//         return 0;
//     }
//     if (dp[root])
//         return dp[root];

//     int IncSum = root->data;
//     int ExcSum;

//     if (root->left)
//     {
//         IncSum += maxSumOfNode(root->left->left);
//         IncSum += maxSumOfNode(root->left->right);
//     }
//     if (root->right)
//     {
//         IncSum += maxSumOfNode(root->right->left);
//         IncSum += maxSumOfNode(root->right->right);
//     }
//     ExcSum = maxSumOfNode(root->left);
//     ExcSum += maxSumOfNode(root->right);

//     dp[root] = max(ExcSum, IncSum);
//     return dp[root];
// }
void printfunc(vector<int> &v, int k)
{
    int sum = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        sum += v[i];
        if (sum == k)
        {
            for (int j = i; j < v.size(); j++)
            {
                cout << v[j] << " ";
            }
            cout << endl;
        }
    }
}
void PathOfSumK(node *root, vector<int> &v, int k)
{
    if (!root)
    {
        return;
    }
    v.push_back(root->data);
    // if (!root->left && !root->right)
    // {
    //     printfunc(v,k);
    // }

    PathOfSumK(root->left, v, k);
    PathOfSumK(root->right, v, k);
    printfunc(v, k);
    v.pop_back();
}
node *findKthAncesstor(node *root, int n, int &k)
{
    if (!root)
    {
        return NULL;
    }
    node *l, *r;
    if (root->data == n || (l = findKthAncesstor(root->left, n, k)) || (r = findKthAncesstor(root->right, n, k)))
    {
        if (k > 0)
        {
            k--;
        }
        else if (k == 0)
        {
            cout << "Kth Ancestor is : " << root->data << endl;
            return NULL;
        }
        return root;
    }
    return NULL;
}

// Kth largest number of BST.

int ans = -1;
void FindKthLargest(node *root, int &k)
{
    if (!root)
        return;
    FindKthLargest(root->right, k);
    // cout<<root->data<<" passed "<<"  value of K : "<<k<<endl;
    if (k == 1)
    {
        ans = root->data;
        k--;
        return;
    }

    k--;
    FindKthLargest(root->left, k);
    return;
}
int kthLargest(node *root, int K)
{
    FindKthLargest(root, K);
    return ans;
    //Your code here
}

//  Getting median

void countForMedian(node *root, int &n)
{
    if (!root)
        return;
    countForMedian(root->left, n);
    n++;
    countForMedian(root->right, n);
}
void GetMedian(node *root, int &m, int n, int &sum)
{
    if (!root)
        return;
    GetMedian(root->left, m, n, sum);
    m++;
    if (n & 1)
    {
        if (m == (n / 2) + 1)
        {
            sum = root->data;
            return;
        }
    }
    else
    {
        if (m == n / 2 )
        {
            sum = root->data;
        }
        if(m == (n / 2) + 1){
            sum += root->data;
            sum /=2;
        }

    }

    GetMedian(root->right, m, n, sum);
}
int Findmedian(node *root)
{
    int n = 0;
    countForMedian(root, n);
    int m = 0;
    int sum = 0;
    GetMedian(root, m, n, sum);
    return sum;
}

main()
{
    node *root = NULL;
    root = insert(root, 56);
    insert(root, 34);
    insert(root, 86);
    insert(root, 25);
    insert(root, 51);
    insert(root, 58);
    insert(root, 59);
    insert(root, 21);
    // insert(root, 4);

    // cout << root->data << endl;
    // cout << root->left->left->left->data << endl;

    // min(root);

    // inorder(root);
    // cout << endl;
    // inorder(mirror(root));
    // cout << endl;
    // preorder(root);
    // rightView(root);
    // leftView(root);

    // zigZag(root);
    // balanceCheck(root);

    // diagonalTraversal(root);
    // bToDLL(root);
    // display(head);
    // BoundaryTraversal(root);
    // cout<<subTreeMax(root);
    // cout << func(root);
    // vector<int> v;
    // int k = 56;
    // PathOfSumK(root, v, k);
    // int k = 2;
    // if (findKthAncesstor(root, 58, k))
    // {
    //     cout << "Not found" << endl;
    // }
    // int k = 2;
    // cout<<kthLargest(root,k)<<endl;
    cout << Findmedian(root) << endl;
}