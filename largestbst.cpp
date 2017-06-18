#include<iostream>
using namespace std;
struct node{
    int val;
    node *left;
    node *right;
};
node *max_root;
int max_size;
node* insert(node* root,int val){
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
    if(val>root->val){
        root->right=insert(root->right,val);
    }
    return root;
}
int largestbst(bool *isbst,node *root,int *minv,int *maxv){
    bool lflag=false,rflag=false;
    if(root==NULL){
        *isbst=1;
        return 0;
    }
    int ls;
    ls=largestbst(isbst,root->left,minv,maxv);
    if((*isbst && root->val>*maxv) || ls==0){
        lflag=true;
    }
    if(root->val>*maxv){
        *maxv=root->val;
    }
    int rs;
    rs=largestbst(isbst,root->right,minv,maxv);
    if((*isbst && root->val<*minv) || rs==0){
        rflag=true;
    }
    if(root->val<*minv){
        *minv=root->val;
    }
    if(lflag && rflag){
        if(ls+rs+1>max_size){
            max_root=root;
            max_size=ls+rs+1;
        }
        return ls+rs+1;
    }
    else{
        *isbst=0;
        return 0;
    }
}
int main(){
    node *root=NULL;
    root=insert(root,7);
    root=insert(root,7);
    root=insert(root,5);
    root=insert(root,8);
    root=insert(root,4);
    root->right=new node;
    root->right->val=4;
    root->right->left=NULL;
    root->right->right=NULL;
    int status;
    int maxv=0,minv=10000;
    bool isbst=0;
    status=largestbst(&isbst,root,&minv,&maxv);
    cout<<max_size<<" "<<max_root->val;
    return 0;
}
