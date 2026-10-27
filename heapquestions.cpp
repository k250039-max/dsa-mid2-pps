int countNodes(Node* root)
{
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// i = index the node would have in an array (root = 0)
bool isComplete(Node* root, int i, int n)
{
    if (root == NULL) return true;
    if (i >= n) return false;
    return isComplete(root->left, 2*i + 1, n) &&
           isComplete(root->right, 2*i + 2, n);
}

bool isMaxHeapProperty(Node* root)
{
    if (root == NULL) return true;                       // base case

    if (root->left && root->data < root->left->data) return false;
    if (root->right && root->data < root->right->data) return false;

    return isMaxHeapProperty(root->left) && isMaxHeapProperty(root->right);
}

bool IsHeap(Node* root)
{
    int n = countNodes(root);
    return isComplete(root, 0, n) && isMaxHeapProperty(root);
}
// with arr
    bool isHeap(int arr[], int n, int i = 0)
{
    if (i >= n) return true;

    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[i] < arr[l]) return false;
    if (r < n && arr[i] < arr[r]) return false;

    return isHeap(arr, n, l) && isHeap(arr, n, r);
}//for max heap
