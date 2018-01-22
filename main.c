#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Peter Gibbs
//Todo: finish read file

//the nodes in our tree
typedef struct treeNode treeNode;


struct treeNode{
    char* __word;
    int __count;
    treeNode* __left;
    treeNode* __right;

};


//This function will search the tree for our word and will either increment the node with our current word,
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
    } else if(strcmp(word,root->__word)<0) {
        //if the word we are inserting is "less then" the root
        //we traverse to the left child
        if(root->__left==NULL) {
            //If theres nothing at our left child, we make a new node there
            root->__left = malloc(sizeof(treeNode));
            root->__left->__right=NULL;
            root->__left->__word = NULL;
        }
        addWord(word, root->__left);
        return;
    }else if(strcmp(word,root->__word)==0){
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

        getFinalWordCount(root->__left,outFile);//We first go to the left

        fprintf(outFile,root->__word);//we print our word to the file
        fprintf(outFile,": "); //then the ':'
        fprintf(outFile,"%d",root->__count);//then the count
        fprintf(outFile,"\n");//Then move to the next line

        getFinalWordCount(root->__right,outFile);//We then go to the right node
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
void readFile(const char* filename){
    FILE* file=fopen(filename,"r");
    size_t nread;
    size_t chunkSize=255*sizeof(char);
    char *buf = malloc(chunkSize*2);//we keep our buffer at 2x our read size incase we need to read further to the next word
    char* word;
    size_t wordSize;
    if (file) {

        while ((nread = fread(buf, 1, chunkSize, file)) > 0) {
            //We first walk through our chunk and
            for(int i=0; i<chunkSize; ++i){

            }
        }
        fclose(file);
    }

}
int main(int argc, char **argv) {
    readFile("input02.txt");
    FILE* output=fopen("outputtest.txt","w");
    treeNode* root=malloc(sizeof(treeNode));
    root->__word=NULL;
    root->__count=0;
    root->__left=NULL;
    root->__right=NULL;
    //TEST FOR TREE STUFF!!!
    char* one="one\0";
    char* three="three\0";
    char* years="years\0";



    getFinalWordCount(root,output);
    deleteTree(root);
    free(root);
    fclose(output);



    return 0;
}