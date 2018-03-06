#pragma once
#ifndef rbTree_
#define rbTree_

#include "rbTreeNode.h"
using namespace std;

template <class K,class E>
class rbTree
{
	public:
		rbTree() { root = NULL; treeSize = 0; }
		bool empty() const { return this->treeSize == 0; }
		int size()const {return treeSize;}
		bool check1();

		pair< K, E>* find(const K& theKey) const;
		void ascend() { inOrderOutput(); }
		void insert(const pair< K, E>& thePair);

		void erase(const pair< K, E>& thePair);
		void eraseFixUp(rbTreeNode<pair<K, E> >* p);

	private:
		rbTreeNode<pair< K, E> > *root;
		int treeSize;

		void leftRotate(rbTreeNode<pair< K, E> >* x);//����
		void rightRotate(rbTreeNode<pair< K, E> >* x);//����
		void insert(rbTreeNode<pair< K, E> >* node);
		void insertFixUp(rbTreeNode<pair< K, E> >* theNode);
		void inOrderOutput() { inOrder(root); }
		void inOrder(rbTreeNode<pair<K, E> >* t);
		bool check2(rbTreeNode<pair<K, E> >* root, int blackCount, int blackCurCount);
		#define rb_parent(r)   ((r)->parent)
		#define rb_color(r) ((r)->color)
		#define rb_is_red(r)   ((r)->color==red)
		#define rb_is_black(r)  ((r)->color==black)
		#define rb_set_black(r)  do { (r)->color = black; } while (0)
		#define rb_set_red(r)  do { (r)->color = red; } while (0)
		#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
		#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
};


template<class K, class E>
void rbTree<K, E>::inOrder(rbTreeNode<pair<K, E> >* t)
{
	if (t != NULL)
	{
		inOrder(t->leftChild);
		cout << t->element;
		inOrder(t->rightChild);
	}
}


template<class K, class E>
pair< K, E>* rbTree<K, E>::find(const K & theKey) const
{

	rbTreeNode<pair< K, E> > *p = root;
	while (p != NULL)
	{
		if (theKey < p->element.first)
			p = p->leftChild;
		else
			if (theKey > p->element.first)
				p = p->rightChild;
			else
				return &p->element;
	}
}

template<class K, class E>
bool rbTree<K, E >::check1()
{
	int blackCount = 0; // ��¼����·��ɫ�ڵ�ĸ���
	int blackCurCount = 0; // ��¼��ǰ·����ɫ�ڵ�ĸ���
	rbTreeNode<pair<K, E> >* cur = root;
	while (cur)
	{
		if (cur->color == black) {
			++blackCount;
		}
		cur = cur->leftChild;
	}

	return check2(root, blackCount, blackCurCount);

}


template<class K, class E>
bool rbTree<K, E>::check2(rbTreeNode<pair<K, E> >* root, int blackCount, int blackCurCount)
{
	if (root == NULL)
	{
		return true; // û�нڵ�ʱ���������
	}
	if (root->color== black)
	{
		++blackCurCount;
	}
	else
	{
		if (root->parent && root->parent->color == red)
		{
			cout << "���������������ڵ㲻��Ϊ��ɫ!"  << endl;
			return false;
		}
	}
	if (root->leftChild == NULL && root->rightChild == NULL)
	{
		if (blackCount == blackCurCount)
		{
			return true;
		}
		else
		{
			cout << "�ڽڵ�����ͬ" << endl;
			return false;
		}
	}
	return check2(root->leftChild, blackCount, blackCurCount) && check2(root->rightChild, blackCount, blackCurCount);

}


template<class K, class E>
void rbTree<K, E>::insert(const pair< K, E>& thePair)
{
	rbTreeNode<pair< K, E> >* x = NULL;
	//��������µĽڵ�ʧ�ܣ�����
	if ((x = new rbTreeNode<pair<K, E> >(thePair, black,NULL,NULL,NULL)) == NULL)
		return;
	if(root!=NULL)
		insert(x);
	else
		root = new rbTreeNode<pair<K, E> >(thePair, black, NULL, NULL, NULL);
}


template<class K,class E>
void rbTree<K, E>::leftRotate(rbTreeNode<pair< K, E> >*	x)
{
	rbTreeNode<pair< K, E> > *y = x->rightChild;//����yΪx���Һ���
	 // �� ��y�����ӡ� ��Ϊ ��x���Һ��ӡ���
	 // ���y�����ӷǿգ��� ��x�� ��Ϊ ��y�����ӵĸ���
	x->rightChild = y->leftChild;
	if(x->rightChild != NULL)
		x->rightChild->parent = x;
	
	if (x->parent == NULL)//���x�ĸ����ǿսڵ㣬������yΪ���ڵ�
	{
		root = y;
		y->parent = NULL;
	}
	else
	{
		if (x->parent->leftChild == x)//���x�������׽ڵ�����ӣ���y��Ϊ������
			x->parent->leftChild= y;
		else
			x->parent->rightChild = y;//���x�������׽ڵ���Һ��ӣ���y��Ϊ�Һ���
	}
	y->parent = x->parent;
	y->leftChild = x;//��x����Ϊy���Һ���
	x->parent = y;//��y��Ϊx�ĸ��׽ڵ�
}


template<class K, class E>
void rbTree<K, E>::rightRotate(rbTreeNode<pair< K, E> >*	x)
{
	rbTreeNode<pair< K, E> >* y = x->leftChild;//����yΪx������
	x->leftChild = y->rightChild;
	if(x->leftChild != NULL)
		x->leftChild->parent = x;
	if (x->parent == NULL)//���x�ĸ����ǿսڵ㣬������yΪ���ڵ�
	{
		root = y;
	}
	else
		if (x->parent->leftChild == x)//���x�������׽ڵ�����ӣ���y��Ϊ����
			x->parent->leftChild = y;
		else
			x->parent->rightChild = y;//���x�������׽ڵ���Һ��ӣ���y��Ϊ�Һ���
	y->parent = x->parent;
	y->rightChild = x;//��x����Ϊy���Һ���
	x->parent = y;//��y��Ϊx�ĸ��׽ڵ�
}


template<class K, class E>
inline void rbTree<K, E>::insert(rbTreeNode<pair<K, E> >* node)
{
	rbTreeNode<pair< K, E> >* y = NULL;
	rbTreeNode<pair< K, E> >* x = root;
	//����Ҫ�����λ�ã����ڵ���뵽��������
	while (x != NULL)
	{
		y = x;
		if ( node->element.first<x->element.first )
			x = x->leftChild;
		else
			x = x->rightChild;
	}
	node->parent = y;
	if (y != NULL)//�������Ϊ��
	{
		if (node->element.first < y->element.first)
			y->leftChild = node;
		else
			y->rightChild = node;
	}
	else
	{
		root = node;
	}
	//����֮��ı���ɫ
	node->color = red;

	//����Ϊ����������
	insertFixUp(node);
}

template<class K, class E>
inline void rbTree<K, E>::insertFixUp(rbTreeNode<pair<K, E> >* theNode)
{
	rbTreeNode<pair< K, E> >  *pu, *gu,*gur;
	while ((pu = rb_parent(theNode))&&rb_is_red(pu)&&(gu = rb_parent(pu)))//�游�ڵ���� ���׽ڵ���ڲ��Ҹ��׽ڵ����ɫ�Ǻ�ɫ
	{
		//�����׽ڵ����游�ڵ������
		if (pu == gu->leftChild)
		{
			gur = gu->rightChild;//�游�ڵ���Һ���
			//1.�游�ڵ�gu���Һ���gur�Ǻ�ɫ   LLr/LRr
			//����������pu��gur��Ϊ��ɫ�����gu���Ǹ��ڵ㣬��gu��Ϊ��ɫ
			if (gur&&rb_is_red(gur))
			{
				rb_set_black(gur);
				rb_set_black(pu);
				if (gu != root)//���gu���Ǹ��ڵ㣬��gu��Ϊ��ɫ
					rb_set_red(gu);
				theNode = gu;
				continue;//��������ѭ������gu��Ϊ�µĽڵ�node
			}
			//2.gurΪ��ɫ����ǰ���������  LLb
			if ((theNode == pu->leftChild) && ((gur == NULL)||rb_is_black(gur)))
			{
				//rbTreeNode<pair<const K, E>>* tmp;
				if ((pu->rightChild==NULL))
				{
					rb_set_black(pu);
					rb_set_black(gu);
					rightRotate(gu);
				}
				theNode = gu;
			}
			//3.gur�ڵ��Ǻ�ɫ���ҵ�ǰ�ڵ����Һ���  LRb
			else if ((theNode == pu->rightChild)&&((gu->rightChild == NULL)||rb_is_black(gur)))
				{
					if (pu->leftChild == NULL)
					{
						rb_set_black(theNode);
						rb_set_red(gu);
						leftRotate(pu);
						rightRotate(gu);
					}
					theNode = gu;
				}
		}
		else
		{
			//pu�ڵ���gu�ڵ���Һ���
			rbTreeNode<pair< K, E> >* gur = gu->leftChild;
			//1.gur���ڣ�gur�ڵ��Ǻ�ɫ  RLr��RRr
			if (gur && rb_is_red(gur))
			{
				rb_set_black(gur);
				rb_set_black(pu);
				if (gu != root)//���gu���Ǹ��ڵ㣬��gu��Ϊ��ɫ
					rb_set_red(gu);
				theNode = gu;
				continue;
			}

			// Case 2�����������Ǻ�ɫ���ҵ�ǰ�ڵ�������  RRb
			if ((theNode == pu->rightChild) && ((gu->leftChild == NULL)||rb_is_black(gur)))
			{
				if (pu->leftChild == NULL)
				{
					rb_set_black(pu);
					rb_set_red(gu);
					leftRotate(gu);
				}
				theNode = pu;
			}
			//3.gur�ڵ��Ǻ�ɫ���ҵ�ǰ�ڵ����Һ���  RLb
			else if ((theNode == pu->leftChild) &&((gu->leftChild == NULL)||rb_is_black(gur)))
			{
				if (rb_is_red(pu))
				{
					rb_set_red(pu);
					rb_set_red(gu);
					rightRotate(pu);
					leftRotate(gu);
				}
				theNode = pu;
			}
		}
		rb_set_black(root);
	}
}


template<class K, class E>
void rbTree<K, E>::erase(const pair< K, E>& thePair)
{// Delete the pair, if any, whose key equals theKey.
   rbTreeNode<pair<K, E> > *p = this->root, *pp = NULL;
   while (p != NULL && p->element.first != thePair.first)
   {
      pp = p;
      if (thePair.first < p->element.first)
         p = p->leftChild;
      else
         p = p->rightChild;
   }
   if (p == NULL)
      return; // no pair with key theKey

   // restructure tree
   if (p->leftChild != NULL && p->rightChild != NULL)
   {  // ��������
      rbTreeNode<pair<K, E> > *s = p->leftChild,
                                       *ps = p;  // parent of s
      while (s->rightChild != NULL)
      {// move to larger element
         ps = s;
         s = s->rightChild;
      }

      // p->element = s->element as key is const
      rbTreeNode<pair<K, E> > *q =
         new rbTreeNode<pair<K, E> >(s->element,p->color,NULL,p->leftChild, p->rightChild);
      if(pp == NULL)
         this->root = q;
      else{
    	  if(p == pp->leftChild)
              pp->leftChild = q;
           else
              pp->rightChild = q;
      }
      if (ps == p) pp = q;
      else pp = ps;
      delete p;
      p = s;
   }

   // ���һ������
   rbTreeNode<pair<K, E> > *c;
   if (p->leftChild != NULL)
      c = p->leftChild;
   else
      c = p->rightChild;

   // delete p
   if (p == this->root)
      this->root = c;
   else
   {// is p left or right child of pp
      if (p == pp->leftChild)
         pp->leftChild = c;
      else pp->rightChild = c;
   }

   if(p->color == black){
	   if(c!=NULL && c->color == red)
		   c->color = black;
	   else
		   eraseFixUp(c);
   }
//   else{
//	   eraseFixUp(c);
//   }

   this->treeSize--;
   delete p;
}


template <class K, class E>
void rbTree<K, E>::eraseFixUp(rbTreeNode<pair<K, E> >* p){
	rbTreeNode<pair<K, E> > *pBro;
	while(p != root) {
		if(p == p->parent->rightChild){    //p���Һ���
			pBro = p->parent->leftChild;
			if (pBro->color == black) {//p���Һ��ӣ�pBro�Ǻڵ�//Rb��
				if(pBro->leftChild->color == black){//pBro�������Ǻڵ�
					if(pBro->rightChild->color == black){//pBro���Һ����Ǻڵ�
						if(pBro->parent->color == black){
							pBro->color = red ;	                    //Rb0(i)
							eraseFixUp(p->parent);
						}
						else{
							pBro->color = red ;
							p->parent->color = black;               //Rb0(ii)
						}
					}
					else{  //pBro��������black,�Һ�����red
						leftRotate(pBro);
						rightRotate(pBro->parent->parent);
						pBro->rightChild->color = p->parent->color; //Rb1(ii)
						p->parent->color = black;
					}
				}
				else{  //pBro��������red�Һ����ǺڵĻ����Ҷ��Ǻڵ�
					pBro->leftChild->color = black;
					pBro->rightChild->color = black;                //Rb1(i)��Rb2
					rightRotate(pBro->parent);
					}
			}//һֱ����   p���Һ��ӣ�pBro�Ǻڵ�   //Rb��

			else{//p���Һ��ӣ�pBro��red  //Rr��
				if(pBro->leftChild->color == black && pBro->rightChild->color == black){//pBro���������Ӷ��Ǻڵ�
					if(pBro->rightChild->leftChild->color == black){//pBro->R->L�Ǻڵ�
						if(pBro->rightChild->rightChild->color == black){//pBro->R->L�Ǻڵģ�pBro->R->R�Ǻڵ�
							pBro->rightChild->color = red;
							pBro->color = black;                              //Rr0
							rightRotate(pBro->parent);
						}
						else{//pBro->R->L�Ǻڵģ�pBro->R->R�Ǻ��
							pBro->rightChild->rightChild->color = black;
							leftRotate(pBro->rightChild);                    //Rr1(ii)
							leftRotate(pBro);
							rightRotate(pBro->parent->parent);  //Rr1(ii)
						}
					}
					else{//pBro->R->L�Ǻ��
						if(pBro->rightChild->rightChild->color == black){//pBro->R->L�Ǻ�ģ�pBro->R->R�Ǻڵ�
							leftRotate(pBro);
							rightRotate(pBro->parent->parent);               //Rr1(i)
							pBro->rightChild->color = black;
						}
						else{//pBro->R->L�Ǻ�ģ�pBro->R->R�Ǻ��
							pBro->rightChild->leftChild->color = black;
							pBro->rightChild->rightChild->color = black;
							leftRotate(pBro);
							rightRotate(pBro->parent->parent);               //Rr2

						}
					}
				}//pBro��red��pBro���������Ӷ��Ǻڵģ���Ĳ�������
			}//һֱ����p���Һ��ӣ�pBro��red    //Rr��
		}//һֱ����p���Һ���

		else{//p������
			pBro = p->parent->rightChild;
			if(pBro->color == black){//pBro�Ǻڵ�
				if(pBro->leftChild->color == black){//pBro��������black
					if(pBro->rightChild->color == black){//pBro���Һ�����black
						if(pBro->parent->color == black){
							pBro->color = red;                      //Lb0(i)
							eraseFixUp(p->parent);
						}
						else{
							pBro->color = red;
							pBro->parent->color = black;            //Lb0(ii)
						}
					}//pBro���Һ��Ӷ��Ǻ�
					else{  //pBro��������black,�Һ�����red
						leftRotate(pBro->parent);
						pBro->rightChild->color = black;            //Lb1(i)
					}
				}
				else{  //pBro��������red
					if(pBro->rightChild->color == black){//pBro��������red,�Һ�����black
						rightRotate(pBro);
						leftRotate(pBro->parent->parent);
						pBro->parent->color = p->parent->color;
						p->parent->color = black;                    //Lb1(ii)
					}
					else{//pBro��������red,�Һ�����red
						pBro->leftChild->color = black;
						pBro->rightChild->color = black;             //Lb2
						leftRotate(pBro->parent);
					}
				}
			}//һֱ����   p�����ӣ�pBro��black

			else{//p������,pBro�Ǻ��
				if(pBro->leftChild->color == black && pBro->rightChild->color == black){//pBro���������Ӷ��Ǻڵ�
					if(pBro->leftChild->leftChild->color == black){//pBro->L->L�Ǻڵ�
						if(pBro->leftChild->rightChild->color == black){//pBro->L->L�Ǻڵģ�pBro->L->R�Ǻڵ�
							pBro->color = black;
							pBro->leftChild->color = red;                        //Lr0
							leftRotate(pBro->parent);
						}
						else{//pBro->L->L�Ǻڵģ�pBro->L->R�Ǻ��
							rightRotate(pBro);
							leftRotate(pBro->parent->parent);
							pBro->leftChild->color = black;                    //Lr1(i)
						}
					}//pBro->L->L�Ǻڵ�
					else{//pBro->L->L�Ǻ��
						if(pBro->leftChild->rightChild->color == black){//pBro->L->L�Ǻ�ģ�pBro->L->R�Ǻڵ�
							rightRotate(pBro->leftChild);
							rightRotate(pBro);
							leftRotate(pBro->parent->parent);                   //Lr1(ii)
							pBro->parent->color = black;
						}//pBro->L->L�Ǻ�ģ�pBro->L->R�Ǻڵ�
						else{//pBro->L->L�Ǻ�ģ�pBro->L->R�Ǻ��
							pBro->leftChild->leftChild->color = black;
							pBro->leftChild->rightChild->color = black;
							rightRotate(pBro);                                  //Lr2
							leftRotate(pBro->parent->parent);
						}
					}
				}//pBro��red��pBro���������Ӷ��Ǻڵģ���Ĳ�������
			}//һֱ����p�����ӣ�pBro��red
		}//һֱ����p������
	}
}

// overload << for pair
template <class K, class E>
ostream& operator<<(ostream& out, const pair<K, E>& x)
{
	out << x.first << ' ' << x.second << ' '; return out;
}

#endif
