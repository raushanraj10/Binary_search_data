#include<iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *right;
    Node *left;
};
class BST
{
private:
    Node *root;
protected:
void preorder_traversing(Node *t);
    void inorder_traversing(Node *t);
void postorder_traversing(Node *);
Node * delete_data_recursion(int,Node *);
Node *searchdata(int,Node*);
public:
    BST(){root=NULL;}
    bool isempty(){return root==NULL;}
    void insert(int data);
   void displaypre(); 
    void displayin();
    void displaypost();
    void deletenode(int);
    void del(int); 
    Node *srch(int data);
};
void BST::insert(int data)
{
    Node *n;
    n=new Node;
    n->val=data;
    n->right=NULL;
    n->left=NULL;
    if(root==NULL)
        root=n;
    else
    {
       Node *t=root,*r;
       while(t!=NULL){
       if(t->val>n->val)
       {r=t;
        t=t->left;}
       else
        {r=t;
       t=t->right;}}
       if(r->val>n->val)
        r->left=n;
       else
        r->right=n;
    }
}
void BST::preorder_traversing(Node *t)
{
    if(t)
    {
        cout<<" "<<t->val;
        preorder_traversing(t->left);
        preorder_traversing(t->right);
    }
}
void BST::displaypre()
{
    preorder_traversing(root);
}
void BST::inorder_traversing(Node *t)
{
    if(t){
    inorder_traversing(t->left);
    cout<<" "<<t->val;
    inorder_traversing(t->right);}
}
void BST::displayin()
{
    inorder_traversing(root);
}
void BST::displaypost()
{
    postorder_traversing(root);
}
void BST::postorder_traversing(Node *t)
{
    if(t)
    {
        postorder_traversing(t->left);
        postorder_traversing(t->right);
        cout<<" "<<t->val;
    }
}
void BST::deletenode(int data)
{
    if(root!=NULL)
    {
        Node *t=root,*r=root,*u;
        while(t!=NULL&&t->val!=data)
        {
            if(t->val>data)
            {
                r=t;
                t=t->left;
            }
            else
            {
                r=t;
                t=t->right;
            }
        }
        if(t!=NULL)
        {
          if(t->left==NULL||t->right==NULL)
          {

            if(t->left==NULL&&t->right==NULL)
            {
               if(r->left==t)
                    {r->left=NULL;
                    delete t;}
               else
                {r->right=NULL;
                delete t;}
            }
            else
            {
                if(t->left==NULL)
                {
                    u=t;
                    t=t->right;
                    if(r->left==u)
                        {r->left=t;
                        delete u;}
                        else
                        {r->right=t;
                        delete t;}
                }
                else
                {
                    u=t;
                    t=t->left;
                    if(r->left==u)
                        {r->left=t;
                        delete u;}
                        else
                        {r->right=t;
                        delete t;}
                }
            }
        }
        else
        {
            r=t;
            while(t->right!=NULL)
            {
                u=t;
                t=t->right;
            }
            r->val=t->val;
            u->right=NULL;
            delete t;
        }


    }
   }
}
void BST::del(int data)
{
         delete_data_recursion(data,root);
}
Node *BST::delete_data_recursion(int data,Node *t)
{
    if(t==NULL)
        return root;
    else if(t->val>data)
            {t->left=delete_data_recursion(data,t->left);
            return t;}
        else if(t->val<data)
            {t->right=delete_data_recursion(data,t->right);
            return t;}
        else
        {

           if(t->left==NULL&&t->right==NULL)
           {
              delete t;
              return nullptr;
           }
           if(t->left==NULL||t->right==NULL)
           {
               Node *n=!NULL?t->left:t->right;
               delete t;
               return n;
           }
           else
           {
               Node *u=t,*r=t;
               t=r->left;
               while(t->right!=NULL)
               {
                   u=t;
                   t=t->right;
               }
               r->val=t->val;

                if(u==r)
                {
                    if(t->left==NULL)
                    {
                        delete t;
                        u->left=NULL;
                        return r;
                    }
                    else
                    {
                        u->left=t->left;
                        delete t;
                        return r;
                    }
                }
                else
                {
                    if(t->left==NULL)
                    {
                        delete t;
                        u->right=NULL;
                        return r;
                    }
                    else
                    {
                        u->right=t->left;
                        delete t;
                        return r;
                    }

                }
            }



           }
}
Node *BST::searchdata(int data,Node *t)
{
    if(t!=NULL)
    {
        while(t->val!=data&&t!=NULL)
        {
            if(t->val>data)
                t=t->right;
            else
                t=t->left;
        }
        if(t==NULL)
            return nullptr;
        else
            return t;
    }
}
Node * BST::srch(int data)
{
    Node *n=searchdata(data,root);
    return n;
}
