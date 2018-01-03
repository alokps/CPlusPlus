//
//  main.cpp
//  BinarySearchTree
//
//  Created by Alok PS on 7/18/16.
//  Copyright © 2016 AlokPS. All rights reserved.
//

#include <iostream>
#include "BstHeader.h"

using namespace std;
int arr[] = {0,1,2,3,4,5,6,7,8,9};
vector<int> arr1 = { 8, 58, 71, 18, 31, 32, 63, 92,43, 3, 91, 93, 25, 80, 28 };
int bstArr[] = {4,2,5,1,3};

int main(int argc, const char * argv[]) {

    BsTree myBstree(10),myBstree1;
    myBstree.InsertNode(5);
    myBstree.InsertNode(15);
    myBstree.InsertNode(1);
    myBstree.InsertNode(20);
    /*INORDER TRAVERSAL OF BINARY SEARCH TREE GIVES AN ASCENDING SORT ORDER ARRAY*/
    cout << "InOrder Traversal" << endl;
    myBstree.InOrderTraversal(myBstree.getRootNode());
    cout << endl;
    cout << "PreOrder Traversal" << endl;
    myBstree.PreOrderTraversal(myBstree.getRootNode());
    cout << endl;
    cout << "PostOrder Traversal" << endl;
    myBstree.PostOrderTraversal(myBstree.getRootNode());
    cout << endl;
    
    myBstree.Display(myBstree.getRootNode());
    cout << "The Height of Tree is: " << myBstree.getTreeHeight(myBstree.getRootNode()) << endl;
    myBstree.setRootNode(myBstree.CreateMinimalBst(arr, 0, 9));
    cout << "The Height of Tree is: " << myBstree.getTreeHeight(myBstree.getRootNode()) << endl;
    myBstree.Display(myBstree.getRootNode());
    cout << "Is binary Search Tree "<< myBstree.CheckIsBinarySearchTree(myBstree.getRootNode()) << endl;
    cout << "Node is found ? " << myBstree.SearchBSt(myBstree.getRootNode(),15)<<endl;
    cout << "The Least Common Ancestor Value is: " << (myBstree.findLeastCommonAncestor(myBstree.getRootNode(), 9, 6))->getData()<<endl;
    myBstree1.ReplacewithMinimalRight();
    myBstree.Display(myBstree.getRootNode());
    cout << endl;
    myBstree.PrintBstAscending(bstArr,0,(sizeof(bstArr)/sizeof(bstArr[0])-1));
    myBstree.setRootNode(myBstree.CreateMiniMalBstFromSortedArray(arr, 0, 9));
    myBstree.Display(myBstree.getRootNode());
    cout << myBstree.CheckIsBalanced(myBstree.getRootNode()) << endl;
    vector<list<BstNode*>> mylist = myBstree.CreateLevelLinkedList(myBstree.getRootNode());
    
    
    return 0;
}


void BsTree::InsertNode(int val){
    
    BstNode *temp = new BstNode(val);
    
    if(root == NULL){
        
        root = temp;
        return;
    }
    
    
    BstNode *parent = NULL;
    BstNode *current = root;
    
    while(true){
    
        parent = current;
        if(val < current->getData()){
        
            current = current->getLeftSubTree();
            if(current == NULL){
                parent->setLeftSubTree(temp);
                return;
            }
        
        }else{
        
            current = current->getRightSubTree();
            if(current == NULL){
                
                parent->setRightSubTree(temp);
                return;
            }
        
        }
    }
    
    return ;
}

void BsTree::InsertNodewithSucc(BstNode *troot, int val, BstNode *succ){
    
    BstNode *temp = new BstNode(val);
    
    if(troot == NULL){
        
        troot = temp;
    }
    
    if(val < troot->getData()){
        succ = troot;
        InsertNodewithSucc(troot->getLeftSubTree(), val, succ);
    }
    else if(val > troot->getData()){
        InsertNodewithSucc(troot->getRightSubTree(), val, succ);
    }
    
    
    return ;
}

void BsTree::Display(BstNode *root){
    
    
    if(root != NULL){
        
        Display(root->getLeftSubTree());
        cout << "The data is: " << root->getData() << endl;
        Display(root->getRightSubTree());
    }

}

int BsTree::getTreeHeight(BstNode *root){
   
    if(root == NULL){
        return 0;
    }
    
    return 1+max_height(getTreeHeight(root->getLeftSubTree()),getTreeHeight(root->getRightSubTree()));
    
}

int BsTree::max_height(int a, int b){
    
    if(abs(a - b) > 1){
        return -1;
    }
    return (a >= b) ? a:b;
}
/*Given a Sorted Array,Create a Minimal BSt */
BstNode* BsTree::CreateMinimalBst(int *tarr,int start, int end){
    
    if(end < start){
        return NULL;
    }
    int mid = (start + end)/2;
    
    BstNode *temp = new BstNode(tarr[mid]);
    
    if(temp != NULL){
        temp->setLeftSubTree(CreateMinimalBst(tarr, start, mid -1));
        temp->setRightSubTree(CreateMinimalBst(tarr, mid+1, end));
    }else{
        cout << "Allocation Failed" << endl;
    }
    
    return temp;
    
}

vector<list<BstNode*>> BsTree::CreateLevelLinklist(BstNode *root){
    
    vector<list<BstNode*>> lists;
    CreateLevelList(root,lists,0);
    return lists;
}

void BsTree::CreateLevelList(BstNode *root, vector<list<BstNode*>> tlists,int level){
    
    if(root == NULL){
        return;
    }
    
    list<BstNode *> mlist = (list<BstNode *>)NULL;
    if(tlists.size() == level){
        
        tlists.push_back(mlist);
    }else{
       // mlist = tlists.
    }
    
}

bool BsTree::CheckIsBinarySearchTree(BstNode *root){
    
   // static int last_val = -1;
    
    /*if(root == NULL){
        return true;
    }
    
    //CheckIsBinarySearchTree(root->getLeftSubTree());
    if(!CheckIsBinarySearchTree(root->getLeftSubTree())){
        return false;
    }
    
    if(root->getData() <= last_val){
        return false;
    }
    
    //cout << "root->getData() is: "<< root->getData() << endl;
    last_val = root->getData();
    //cout << "last_val is: " << last_val <<endl;
    //CheckIsBinarySearchTree(root->getRightSubTree());
    
    if(!CheckIsBinarySearchTree(root->getRightSubTree())){
        return false;
    }
    
    return true;*/
    return CheckIsBinarySearchTree(root, -1, 32768);
}

bool BsTree::CheckIsBinarySearchTree(BstNode *root,int min,int max){
    
    if(root == NULL){
        return true;
    }
    
    if(root->getData() <= min || root->getData() >= max){
        return false;
    }
    
    if((!CheckIsBinarySearchTree(root->getLeftSubTree(), min, root->getData())) ||
       (!CheckIsBinarySearchTree(root->getRightSubTree(), root->getData(), max))){
        return false;
    }
    
    return true;
}

bool BsTree::CheckIsSubTree(BstNode *node1, BstNode *node2){
    
    if(node2 == NULL){
        return true; //Null Tree will always be present as a subset
    }
    return subTree(node1,node2);
}

bool BsTree::subTree(BstNode *node1, BstNode *node2){
    
    if(node1 == NULL){
        return true;//Big Tree Empty
    }
    
    if(node1->getData() == node2->getData()){
        if(CheckMatch(node1,node2)){
            return true;
        }
    }
    return (subTree(node1->getLeftSubTree(), node2) || subTree(node1->getRightSubTree(), node2));
}

bool BsTree::CheckMatch(BstNode* node1, BstNode *node2){
    
    if(node1 == NULL && node2 == NULL){
        return true;
    }
    
    if(node1 == NULL || node2 == NULL){
        return false;
    }
    
    if(node1->getData() != node2->getData()){
        return false;
    }else{
        
        return ((CheckMatch(node1->getLeftSubTree(), node2->getLeftSubTree()))&&(CheckMatch(node1->getRightSubTree(), node2->getRightSubTree())));
    }
    
}

bool BsTree::SearchBSt(BstNode* root,int val){
    
    if(root == NULL){
        return false;
    }
    
    if(val == root->getData()){
        cout << "Found the Node" << endl;
        return true;
    }else if(val < root->getData()){
        SearchBSt(root->getLeftSubTree(),val);
    }else{
        SearchBSt(root->getRightSubTree(),val);
    }
    
    return false;
    
}

BstNode* BsTree::findLeastCommonAncestor(BstNode* root,int n1,int n2){
    
    if(root == NULL){
        return NULL;
    }
    
    
    //if n1 and n2 is less then root->data then LCA lies in Left Sub Tree
    if((root->getData() > n1 ) && (root->getData() > n2) ){
        return(findLeastCommonAncestor(root->getLeftSubTree(), n1, n2));
    }
    
    //if n1 and n2 is greater then root->data then LCA lies in right sub Tree
    if((root->getData() < n1) && (root->getData() < n2)){
        return(findLeastCommonAncestor(root->getRightSubTree(), n1, n2));
    }
    
    return root;
}

void BsTree::InOrderTraversal(BstNode* root){
    
    if(root == NULL){
        
        return;
    }
    
    InOrderTraversal(root->getLeftSubTree());
    cout << root->getData() << " ";
    InOrderTraversal(root->getRightSubTree());
    
}

void BsTree::PreOrderTraversal(BstNode* root){
    if(root == NULL){
        
        return;
    }
    
    cout << root->getData() << " ";
    PreOrderTraversal(root->getLeftSubTree());
    PreOrderTraversal(root->getRightSubTree());
    

}

void BsTree::PostOrderTraversal(BstNode* root){
    if(root == NULL){
        
        return;
    }
    
    PostOrderTraversal(root->getLeftSubTree());
    PostOrderTraversal(root->getRightSubTree());
    cout << root->getData() << " ";
    
    
}

void BsTree::replace(vector<int> myvec){
    
    for(auto x= myvec.rbegin(); x != myvec.rend(); x++){
        
        BstNode *succ = NULL;
        
 
        if(x == myvec.rbegin()){
         setRootNode(new BstNode(*x));
        }

        
        InsertNodewithSucc(getRootNode(), *x, succ);
        
        if(succ){
            *x = succ->getData();
        }else{
            *x = -1;
        }
        
    }
    
    
}

//{4,2,5,1,3};

void BsTree::PrintBstAscending(int *arr,int start, int end){
    
    if(start > end){
        return;
    }
    
    PrintBstAscending(arr,start*2+1, end);
    
    cout << start << "->" << arr[start] << endl;
    
    PrintBstAscending(arr, start*2+2, end);
    
}



/*REPLACE EVERY ELEMENT IN THE ARRAY WITH LEAST GREATER ELEMENT ON THE RIGHT*/

/*ALGORITHM IS TO ADD THE ARRAY ELEMENTS FROM THE RIGHT TO BST AND FOR EVERY ELEMENT ADDED TO BST
  REPLACE THE CORRESPONDING ELEMENT IN THE ARRAY WITH THE SUCCESSOR ELEMENT IN THE BST*/
void BsTree::ReplacewithMinimalRight(){
    
    cout << "Arr1 before is: " << endl;

    for(auto x=arr1.begin(); x != arr1.end(); x++){
        
        cout << *x << " ";
    }
    
    cout << endl;
    
    replace(arr1);
    
    cout << "Arr1 after is: " << endl;
    
    for(auto x=arr1.begin(); x != arr1.end(); x++){
        
        cout << *x << " ";
    }
    
    
}

BstNode* BsTree::CreateMiniMalBstFromSortedArray(int *karr, int start, int end){
    
    if(end < start){
        return NULL;
    }
    
    int mid = (start + end)/2;
    
    BstNode* temp = new BstNode(karr[mid]);
    
    if(temp != NULL){
        
        temp->setLeftSubTree(CreateMiniMalBstFromSortedArray(arr, start, mid-1));
        temp->setRightSubTree(CreateMiniMalBstFromSortedArray(arr, mid+1, end));
    }
    
    return temp;
}


bool BsTree::CheckIsBalanced(BstNode * root){
    
    //Null Tree is always Balanced
    if(root == NULL){
        return true;
    }
    
    int bstHeight = getTreeHeight(root);
    
    if(bstHeight == -1){
        return false;
    }else{
        return true;
    }
    
}


/*Given a binary tree, design an algorithm which creates a linked list of all the nodes at
 each depth (e.g., if you have a tree with depth D, you'll have D linked lists).*/

vector<list<BstNode*>> BsTree::CreateLevelLinkedList(BstNode* root){
    
    vector<list<BstNode*>> lists;
    
    CreateLevelLinkedList(root, lists, 0);
    
    return lists;
}


void BsTree::CreateLevelLinkedList(BstNode *root, vector<list<BstNode*> > lists, int level){
    
    if(root == NULL){
        return;
    }
    
    list<BstNode*> mlist;
    
    
    if(lists.size() == level){
        
        lists.push_back(mlist);

    }else{
        
        mlist = lists[level];
        
    }
    mlist.push_back(root);
    
    CreateLevelLinkedList(root->getLeftSubTree(),lists,level+1);
    CreateLevelLinkedList(root->getRightSubTree(), lists, level+1);
    
}










