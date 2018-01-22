# C Programming Assignment 1

The program is designed to take input from a file in the form of a tree of chars, and print out the tree, in addition to the word count for the file.  In order to ensure space delimited content, we used the C function "isspace".

To start out with, a struct called treenode was created.  This will be the nodes of our tree, and allows us to branch from parent node to child nodes.

Next is the addword function which will search the tree for our word and either increment the node or add a new node for a new word.  The algorithm for this is a simple Binary Search Tree algorithm.

Our getFinalWordCount function will traverse the tree and write it to a file.  It will also give the magnitude of our nodes by showing the word count number.

DeleteTree will delete the tree and everything in it.

readFile will go till the end of file, and in conjunction with the isspace function native to C, it will also ensure that it will read space delimited files.
