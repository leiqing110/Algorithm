#ifndef rbTreeNode_
#define rbTreeNode_

#include<iostream>
using namespace std;
enum colorType
{
	red,
	black
};
template <class T>
struct rbTreeNode
{
   T element;
   colorType color;
   rbTreeNode<T> *leftChild,   // left subtree
	   *rightChild,  // right subtree
	   *parent;

   rbTreeNode() {
	leftChild = rightChild = NULL;
   parent = NULL;
   //color = black;
   }
   rbTreeNode(const T& theElement):element(theElement)
   {
      leftChild = rightChild = parent = NULL;
      //color = black;
   }
   rbTreeNode(const T& theElement,
				colorType theColor,
					rbTreeNode *theParent,
						rbTreeNode *theLeftChild,
								rbTreeNode *theRightChild)
   {
	  element = theElement;
      leftChild = theLeftChild;
      rightChild = theRightChild;
	  parent = theParent;
	  color = theColor;
   }
};

#endif
