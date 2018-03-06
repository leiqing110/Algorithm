// circularList list with header node

#ifndef doubleDirectCircularListWithHeader_
#define doubleDirectCircularListWithHeader_

#include<iostream>
#include<sstream>
#include<string>
#include "chainNode.h"
#include "myExceptions.h"
#include "linearList.h"

using namespace std;

template<class T>
class doubleDirectCircularListWithHeader: public linearList<T>
{
   public:
      // constructor
	  doubleDirectCircularListWithHeader();//��Ĺ��캯��
	  bool empty() const { return listSize == 0; };//�ж��Ƿ��ǿյ�
	  T& get(int theIndex) const;//����ָ��Ԫ�ص�����
      // some methods
      int size() const {return listSize;}//��ȡ����ĳ��ȴ�С
      int indexOf(const T& theElement) const;//����ָ��Ԫ�ص�����
      void insert(int theIndex, const T& theElement);//����ĳ��Ԫ��
      void output(ostream& out) const;//���������
	  void erase(int theIndex);//ɾ��ָ��������Ԫ��
	  chainNode<T>* find(int theIndex) const;//����Ԫ������λ�ã������һ��Ǵ��ҵ���

   protected:
      void checkIndex(int theIndex) const;
            // throw illegalIndex if theIndex invalid
      chainNode<T>* headerNode;  // pointer to header node
      int listSize;              // number of elements in list
};

template<class T>
chainNode<T>* doubleDirectCircularListWithHeader<T>::find(int theIndex) const
{
	chainNode<T> *p = headerNode;
	if (theIndex < listSize / 2)
	{
		for (int i = 0; i <theIndex; i++)
			p = p->next;
	}
	else
		for (int i = 0; i < listSize - theIndex + 1; i++)
			p = p->prev;
	return p;
}
template<class T>
T& doubleDirectCircularListWithHeader<T> ::get(int theIndex) const
{
	chainNode<T> *p = headerNode;
	p = find(theIndex);
	p = p->next;

	return p->element;
}

//T& get(int theIndex);
template<class T>
doubleDirectCircularListWithHeader<T> ::doubleDirectCircularListWithHeader()
{// Constructor.
   headerNode = new chainNode<T>();
   headerNode->next = headerNode;
   headerNode->prev = headerNode;
   listSize = 0;
}

template<class T>
void doubleDirectCircularListWithHeader<T>::checkIndex(int theIndex) const
{// Verify that theIndex is between 0 and listSize - 1.
   if (theIndex < 0 || theIndex >= listSize)
   {ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
   }

}

template<class T>
int doubleDirectCircularListWithHeader<T>::indexOf(const T& theElement) const
{// Return index of first occurrence of theElement.
 // Return -1 if theElement not in list.

 // Put theElement in header node
	headerNode->element = theElement;

	// search the chain for theElement
	chainNode<T>* currentNode = headerNode->next;
	int index = 0;  // index of currentNode
	while (currentNode->element != theElement)
	{
		// move to next node
		currentNode = currentNode->next;
		index++;
	}

	// make sure we found matching element
	if (currentNode == headerNode)
		return -1;
	else
		return index;
}

template<class T>
void doubleDirectCircularListWithHeader<T>::insert(int theIndex, const T& theElement)
{// Insert theElement so that its index is theIndex.
   if (theIndex < 0 || theIndex > listSize)
   {// invalid index
      ostringstream s;
      s << "index = " << theIndex << " size = " << listSize;
      throw illegalIndex(s.str());
   }

   // find predecessor of new element
   chainNode<T>* p = headerNode;
   chainNode<T>* s = new chainNode<T>(theElement);
   p = find(theIndex);

   s->next = p->next;
   s->prev = p;
   p->next = s;
   s->next->prev= s;
   
   listSize++;
}
template<class T>
void doubleDirectCircularListWithHeader<T>::erase(int theIndex)
{
	//checkIndex(theIndex);
	chainNode<T> *p;
	chainNode<T> *q = headerNode;
	p = find(theIndex);//�ҵ�Ҫɾ��λ�õ�ǰһ��
	q = p->next;
	p->next = q->next;
	q->next->prev = p;
	delete q;
	listSize--;
}

template<class T>
void doubleDirectCircularListWithHeader<T>::output(ostream& out) const
{// Put the list into the stream out.
   for (chainNode<T>* currentNode = headerNode->next;
                      currentNode != headerNode;
                      currentNode = currentNode->next)
      out << currentNode->element << "  ";
}

// overload <<
template <class T>
ostream& operator<<(ostream& out, const doubleDirectCircularListWithHeader<T>& x)
{x.output(out); return out;}

#endif