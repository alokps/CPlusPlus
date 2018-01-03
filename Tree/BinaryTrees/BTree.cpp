//
//  main.cpp
//  BinaryTrees
//
//  Created by Alok PS on 7/23/16.
//  Copyright © 2016 AlokPS. All rights reserved.
//

#include <iostream>
#include "BtNode.h"
#include <vector>


using namespace std;

vector<int> InOrderArray;
vector<int> PreOrderArray;
vector<int> PostOrderArray;

int main(int argc, const char * argv[]) {

    Btree *myBtree = new Btree(10);
    myBtree->addNode(myBtree->getbRoot(),20);
    myBtree->addNode(myBtree->getbRoot(),30);
    myBtree->addNode(myBtree->getbRoot(),40);
    myBtree->addNode(myBtree->getbRoot(),50);
    //myBtree->DisplayNodes(myBtree->getbRoot());
    cout << "The Height of Left Tree is: "<< myBtree->getHeight(myBtree->getbRoot()) << endl;
    cout << "The Trees are balanced or not: "<<myBtree->IsBalanced(myBtree->getbRoot()) << endl;
    cout << "#######"<<endl;
    myBtree->InOrderTraversal(myBtree->getbRoot());
    cout << "#######"<<endl;
    myBtree->PostOrderTraversal(myBtree->getbRoot());
    cout << "#######"<<endl;
    myBtree->PreOrderTraversal(myBtree->getbRoot());
    myBtree->DisplayNodes(myBtree->ConstructTree(InOrderArray,0,(int)InOrderArray.size()-1,PostOrderArray,0,(int)PostOrderArray.size()-1));
    cout << "#######"<<endl;
    myBtree->DisplayNodes(myBtree->ConstructTree1(InOrderArray,0,(int)InOrderArray.size()-1,PreOrderArray,0,(int)PreOrderArray.size()-1));
    
    cout<< "The FirstCommonAncestor is: "<< (myBtree->findFirstCommonAncestor(myBtree->getbRoot(),myBtree->getbRoot()->getlsTree(),myBtree->getbRoot()->getrsTree()))->getData() << endl;
    
    
    delete myBtree;
    
    return 0;
}


BtNode* Btree::addNode(BtNode *root,int val){
    
    BtNode *temp = root;
    
    if(temp == NULL){
        
        temp = new BtNode(val);
        
    } else{
        
        if(temp->getrsTree() == NULL){
            temp->setrsTree(addNode(temp->getrsTree(), val));
        }else{
            temp->setlsTree(addNode(temp->getlsTree(), val));
        }
        
    }
    
    return temp;
}

void Btree::DisplayNodes(BtNode * root){
    
    if(root == NULL){
        //cout << "No Nodes to Print" << endl;
        return;
    }else{
    
    DisplayNodes(root->getlsTree());
    cout << "The data is: "<< root->getData() << endl;
    DisplayNodes(root->getrsTree());
    }
    
}


int Btree::InOrderTraversal(BtNode *root){
    
    static int count = 0;
    
    if(root == NULL){
        return 0;
    }

    InOrderTraversal(root->getlsTree());
    cout << "The InOrder data is: " << root->getData() << endl;
    //InOrderArray.at(count++) = root->getData();
    InOrderArray.push_back(root->getData());
    InOrderTraversal(root->getrsTree());
    
    return count;
    
}

bool Btree::IsEmpty(BtNode *root){
    
    return (root == NULL);
}


int Btree::PreOrderTraversal(BtNode *root){
    
    static int count = 0;
    if(root == NULL){
        return 0;
    }
    
    cout << "The PreOrder data is: " << root->getData() << endl;
    //PreOrderArray.at(count++) = root->getData();
    PreOrderArray.push_back(root->getData());
    PreOrderTraversal(root->getlsTree());
    PreOrderTraversal(root->getrsTree());
    return count;
    
}

int Btree::PostOrderTraversal(BtNode *root){
    static int count = 0;
    if(root == NULL){
        return 0;
    }
    
    PostOrderTraversal(root->getlsTree());
    PostOrderTraversal(root->getrsTree());
    //cout << "The data is: " << root->getData() << endl;
    //PostOrderArray.at(count++)=root->getData();
    PostOrderArray.push_back(root->getData());
    return count;
}

int Btree::getHeight(BtNode *root){
   
    int temp = 0;
    
    if(root == NULL){
        return temp;
    }else{
        
        temp = 1+getMaxHeight(getHeight(root->getlsTree()),getHeight(root->getrsTree()));
        //temp = 1+getHeight(root->getlsTree());
    }
    
    return temp;
}

int Btree::getMaxHeight(int a, int b){
    
    return (a > b)? a: b;
    
}

bool Btree::IsBalanced(BtNode *root){
    
    if(root == NULL){
        return true;
    }
   /* Method 1 = O(N2) due to same Nodes getting called agaiin by height function
    int height_diff = abs(getHeight(root->getlsTree()) - getHeight(root->getrsTree()));
    
    if(height_diff > 1){
        return false;
    }else{
        return IsBalanced(root->getrsTree()) && IsBalanced(root->getlsTree());
    }*/
    
    //Method2 : O(N) and O(H) where H is height of the Tree
    if(CheckHeight(root) == -1){
        return false;
    }else{
        return true;
    }
    
}

int Btree::CheckHeight(BtNode *root){
    
    if(root == NULL){
        return 0;
    }
    
    int leftHeight = CheckHeight(root->getlsTree());
    if(leftHeight == -1){
        return  -1;
    }
    
    int rightHeight = CheckHeight(root->getrsTree());
    
    if(rightHeight == -1){
        return  -1;
    }
    
    int heightDiff = abs(leftHeight - rightHeight);
    
    if(heightDiff > 1){
        return -1; //Not Balanced
    }else{
        
        return (1+ getMaxHeight(getHeight(root->getlsTree()),getHeight(root->getrsTree())));
        
    }
    
    
}
/*From the post-order array, we know that last element is the root. We can find the root in in-order array. 
 Then we can identify the left and right sub-trees of the root from in-order array.*/

BtNode * Btree::ConstructTree(vector<int> arr1,int instart, int inlength,vector<int> arr2,int posstart,int postlength){

    if  ((instart > inlength)||(posstart > postlength)){
        return NULL;
    }
    
    int rootVal = arr2[postlength];
    BtNode* temp = new BtNode(rootVal);
    
    int k = 0;
    for(int i=0;i<arr1.size();i++){
        
        if(rootVal == arr1[i]){
            k = i; //Found the root in the Inorder Array
            break;
        }
    }
    
    
    temp->setlsTree(ConstructTree(arr1, instart, k-1, arr2, posstart, k - (instart + 1)));
    temp->setrsTree(ConstructTree(arr1, k+1, inlength, arr2, k-(instart), postlength-1));
    
    return temp;
}

/*From the pre-order array, we know that first element is the root. We can find the root in in-order array. 
 Then we can identify the left and right sub-trees of the root from in-order array.*/

BtNode * Btree::ConstructTree1(vector<int> arr1,int instart, int inlength,vector<int> arr2,int prestart,int prelength){
    
    if  ((instart > inlength)||(prestart > prelength)){
        return NULL;
    }
    
    int rootVal = arr2[prestart];
    BtNode* temp = new BtNode(rootVal);
    
    int k = 0;
    for(int i=0;i<arr1.size();i++){
        
        if(rootVal == arr1[i]){
            k = i; //Found the root in the Inorder Array
            break;
        }
    }
    
    
    temp->setlsTree(ConstructTree1(arr1, instart, k-1, arr2, prestart+1, prestart+ (k - instart)));
    temp->setrsTree(ConstructTree1(arr1, k+1, inlength, arr2, prestart+ k-(instart)+1, prelength));
    
    return temp;
}

bool Covers(BtNode* root, BtNode* p){
    
    if(root == NULL){
        return false;
    }
    
    if(root == p){
        return true;
    }
    
    return (Covers(root->getlsTree(),p) || Covers(root->getrsTree(), p));
    
}

BtNode * Btree::findFirstCommonAncestor(BtNode* root,BtNode* p,BtNode* q){
    
    if(root == NULL){
        return NULL;
    }
    
    if(!Covers(root, p) || !Covers(root, q)){
        return NULL;
    }
    
    if(root == p || root == q){
        return root;
    }
    
    bool is_p_on_left = Covers(root->getlsTree(),p);
    bool is_q_on_left = Covers(root->getlsTree(),q);
    
    //If they are not on same side
    if(is_p_on_left != is_q_on_left){
        return root;
    }
    
    //They are on same side, traverse this side
    BtNode *child_side = is_p_on_left ? root->getlsTree() : root->getrsTree();
    return findFirstCommonAncestor(child_side, p, q);
    
    
}

/*
 Method 1 (By Storing root to n1 and root to n2 paths):
 Following is simple O(n) algorithm to find LCA of n1 and n2.
 1) Find path from root to n1 and store it in a vector or array.
 2) Find path from root to n2 and store it in another vector or array.
 3) Traverse both paths till the values in arrays are same. Return the common element just before the mismatch.
*/

//int findPath
