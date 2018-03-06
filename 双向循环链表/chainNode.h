// chain node

#ifndef chainNode_
#define chainNode_

template <class T>
struct chainNode 
{
   // data members
   T element;
   chainNode<T> *next;
   chainNode<T> *prev;

   // methods
   chainNode() {}
   chainNode(const T& element)
   {
	  this->element = element;
	  this->next = NULL;
	  this->prev = NULL;
   }
   chainNode(const T& element, chainNode<T>* next)
      {this->element = element;
       this->next = next;}
};

#endif
