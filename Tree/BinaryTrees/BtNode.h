//
//  BtNode.h
//  BinaryTrees
//
//  Created by Alok PS on 7/23/16.
//  Copyright © 2016 AlokPS. All rights reserved.
//

#ifndef BtNode_h
#define BtNode_h

#include <vector>

using namespace std;

class BtNode{
    
private:
    BtNode *lsTree;
    BtNode *rsTree;
    int data;
public:
    BtNode(){
        
        lsTree = NULL;
        rsTree = NULL;
        data = 0;
    }
    
    BtNode(int val){
        
        lsTree = NULL;
        rsTree = NULL;
        data = val;
    }
    
    BtNode *getlsTree(void) const{
        return lsTree;
    }
    
    BtNode *getrsTree(void) const{
        return rsTree;
    }
    
    int getData() const{
        return data;
    }
    
    void setlsTree(BtNode *temp){
        lsTree = temp;
    }
    
    void setrsTree(BtNode *temp){
        rsTree = temp;
    }
    
    void setData(int val){
        data = val;
    }
    
};


class Btree{
    
private:
    BtNode *broot;

public:
    Btree(){
        broot = NULL;
    }
    
    Btree(int val){
        
        BtNode *temp = new BtNode(val);
        broot = temp;
    }
    
    
    BtNode* addNode(BtNode *, int val);
    int SearchNode(BtNode *);
    void deleteNode(BtNode *);
    void DisplayNodes(BtNode *);
    int InOrderTraversal(BtNode *);
    int PreOrderTraversal(BtNode *);
    int PostOrderTraversal(BtNode *);
    bool IsEmpty(BtNode *);
    BtNode *getbRoot() const{
        return broot;
    }
    bool IsBalanced(BtNode *);
    int getHeight(BtNode *);
    int getMaxHeight(int,int);
    int CheckHeight(BtNode *);
    BtNode * ConstructTree(vector<int>,int,int,vector<int>,int,int);
    BtNode * ConstructTree1(vector<int>,int,int,vector<int>,int,int);
    BtNode * findFirstCommonAncestor(BtNode*,BtNode*,BtNode*);
    BtNode * findLeastCommonAncestor(BtNode*,int,int);
    
};


#endif /* BtNode_h */
