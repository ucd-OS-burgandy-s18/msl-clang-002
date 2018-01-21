#include <stdio.h>
#include <stdlib.h>
//Peter Gibbs
//Todo: add reading files
//todo: make it work
//the nodes in our tree
typedef struct treeNode treeNode;


struct treeNode{
    char* __word;
    int __count;
    treeNode* __left;
    treeNode* __right;

};
//returns 1 if lhs<rhs 2 if lhs==rhs and 0 otherwise
int compareWord(const char* lhs,const char* rhs){
    //TODO: add a check so it wont fail when comparing words like (start and starting)
    //we use this to compare our words in alphabetical order
    int index=0;


    while(1){
        if(lhs[index]<rhs[index]){
            return 1;
        }
        if(rhs[index]>lhs[index]){
            return 0;
        }
        if(rhs[index]=='\0'&lhs[index]=='\0'){
            return 2;
        }
        index++;

    }

}

//This function will traverse the tree and will either increment the node with our current word,
//or will add a new node
void addWord(char* word,treeNode* root){

    if(root==NULL) {
        //if we hit an empty node, we create a new node
        root = malloc(sizeof(treeNode));
        root->__count = 1;
        root->__word = word;
        root->__word=NULL;
        root->__left=NULL;
        root->__right=NULL;

    }else if(root->__word==NULL){
        //we check if the word in our node is null, and fill it with our new word
        //this should only happen when the root is created but no word has been loaded in
        root->__count = 1;
        root->__word = word;
        root->__left=NULL;
        root->__right=NULL;
        return;
    } else if(compareWord(word,root->__word)==1) {
        //if the word we are inserting is "less then" the root
        //we traverse to the left child
        if(root->__left==NULL) {
            root->__left = malloc(sizeof(treeNode));
            root->__left->__right=NULL;
            root->__left->__word = NULL;
        }
        addWord(word, root->__left);
        return;
    }else if(compareWord(word,root->__word)==2){
        root->__count++;
    }else{
        //if the word is not equal to current node, and it is not to the left
        //our only option is to traverse to the right
        if(root->__right==NULL) {
            root->__right = malloc(sizeof(treeNode));
            root->__right->__left=NULL;
            root->__right->__word = NULL;
        }
        addWord(word, root->__right);
        return;
    }

}
//this function takes the tree, traverses it and writes it to a file

void getFinalWordCount(treeNode* root,FILE *outFile){
    if(root!=NULL){
        getFinalWordCount(root->__left,outFile);
        getFinalWordCount(root->__right,outFile);
        //we print our word
        fprintf(outFile,root->__word);
        //then the ':'
        fprintf(outFile,": ");
        //then the count
        fprintf(outFile,"%d",root->__count);
        fprintf(outFile,"\n");
    }
}
//destroys the tree and everything in it
void deleteTree(treeNode* root){
    if(root!=NULL) {
        deleteTree(root->__left);
        deleteTree(root->__right);
        //free(root->__word);
        free(root);
    }
}

int main(int argc, char **argv) {

    FILE* output=fopen("outputtest.txt","w");
    treeNode* root=malloc(sizeof(treeNode));
    root->__word=NULL;
    root->__count=0;
    root->__left=NULL;
    root->__right=NULL;
    //TEST FOR TREE STUFF!!!
    char* one="one\0";
    char* three="three\0";
    char* four="years\0";
    addWord(three, root);
    addWord(one, root);



    addWord(one, root);
    addWord(three, root);
    //addWord(one, root);
//addWord(one, root);
    getFinalWordCount(root,output);
// deleteTree(root);
    fclose(output);
    //free(root);


    return 0;
}