#include<iostream>
using namespace std;
struct node{
    int val;
    node *left;
    node *right;
};
node * insert(node * root,int val){
    if(root==NULL){
        root=new node;
        root->val=val;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    if(val<=root->val){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}
node *predecessor(node *root){
    node *fix=root;
    root=root->left;
    while(root->right!=NULL && root->right!=fix){
        root=root->right;
    }
    return root;
}
void morrisinorder(node *current){
    while(current!=NULL){
        if(current->left==NULL){
            cout<<current->val<<" ";
            current=current->right;
        }
        else{
            node *pre=predecessor(current);
            if(pre->right==NULL){
                pre->right=current;
                current=current->left;
            }
            else{
                pre->right=NULL;
                cout<<current->val<<" ";
                current=current->right;
            }
        }
    }
}
int main(){
    node *root=NULL;
    root=insert(root,7);
    root=insert(root,9);
    root=insert(root,11);
    root=insert(root,5);
    root=insert(root,2);
    morrisinorder(root);
    return 0;
}
