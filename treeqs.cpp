int isvalid_bst(Node* root,int count=0)
{
    if(root==NULL) return 0;
    if((root->right==NULL||root->right->data>root->data)&&(root->left==NULL||root->left->data<root->data)) count++;
    
    return count+isvalid_bst(root->right)+isvalid_bst(root->left);
}
