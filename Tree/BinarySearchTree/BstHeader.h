//
//  BstHeader.h
//  BinarySearchTree
//
//  Created by Alok PS on 7/18/16.
//  Copyright © 2016 AlokPS. All rights reserved.
//

#ifndef BstHeader_h
#define BstHeader_h
#include <vector>
#include <list>
using namespace std;

class BstNode{
   
private:
    BstNode *LeftSubTree;
    BstNode *RightSubTree;
    int data;

public:
     BstNode(){
        
        LeftSubTree = NULL;
        RightSubTree = NULL;
        data = 0;
    }
    
    BstNode(int val){
        
        LeftSubTree = NULL;
        RightSubTree = NULL;
        data = val;
    }
    
    BstNode * getLeftSubTree() const{
        
        return LeftSubTree;
    }
    
    BstNode * getRightSubTree() const{
        
        return RightSubTree;
    }
    
    void setLeftSubTree(BstNode *lst){
        
        LeftSubTree = lst;
    }
    
    void setRightSubTree(BstNode *rst){
        
        RightSubTree = rst;
    }
    
    int getData() const{
        
        return data;
    }

};

class BsTree{
    
private:
    BstNode *root;
    
public:
    BsTree(){
        root = NULL;
    }
    
    BsTree(int val){
        
        root = new BstNode(val);
    }
    
    BstNode *getRootNode() const{
        return root;
    }
    
    void setRootNode(BstNode *node) {
        root = node;
    }
    
    void InsertNode(int val);
    void InsertNodewithSucc(BstNode *,int val,BstNode *);
    void Display(BstNode *);
    void DeleteNode(BstNode *);
    void FindCommonAncestor(BstNode *);
    void FindCommonParents(BstNode *);
    int getTreeHeight(BstNode *);
    int max_height(int a, int b);
    BstNode * CreateMinimalBst(int *,int,int);
    vector<list<BstNode*>> CreateLevelLinklist(BstNode *);
    void CreateLevelList(BstNode *, vector<list<BstNode*>>,int level);
    bool CheckIsBinarySearchTree(BstNode *);
    bool CheckIsBinarySearchTree(BstNode *,int min,int max);
    bool CheckIsSubTree(BstNode *,BstNode*);
    bool subTree(BstNode*,BstNode*);
    bool CheckMatch(BstNode*,BstNode*);
    bool SearchBSt(BstNode*,int);
    BstNode* findLeastCommonAncestor(BstNode*,int,int);
    void InOrderTraversal(BstNode* root);
    void PreOrderTraversal(BstNode* root);
    void PostOrderTraversal(BstNode* root);
    void ReplacewithMinimalRight();
    void replace(vector<int> myvec);
    void PrintBstAscending(int *arr, int start, int end);
    BstNode* CreateMiniMalBstFromSortedArray(int *arr, int start, int end);
    bool CheckIsBalanced(BstNode *);
    vector<list<BstNode*>> CreateLevelLinkedList(BstNode*);
    void CreateLevelLinkedList(BstNode*, vector<list<BstNode*>> lists, int level);
    
};




#endif /* BstHeader_h */
