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

		void leftRotate(rbTreeNode<pair< K, E> >* x);//左旋
		void rightRotate(rbTreeNode<pair< K, E> >* x);//右旋
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
	int blackCount = 0; // 记录最左路黑色节点的个数
	int blackCurCount = 0; // 记录当前路径黑色节点的个数
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
		return true; // 没有节点时，满足规则
	}
	if (root->color== black)
	{
		++blackCurCount;
	}
	else
	{
		if (root->parent && root->parent->color == red)
		{
			cout << "不满足条件，根节点不能为红色!"  << endl;
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
			cout << "黑节点数不同" << endl;
			return false;
		}
	}
	return check2(root->leftChild, blackCount, blackCurCount) && check2(root->rightChild, blackCount, blackCurCount);

}


template<class K, class E>
void rbTree<K, E>::insert(const pair< K, E>& thePair)
{
	rbTreeNode<pair< K, E> >* x = NULL;
	//如果创建新的节点失败，返回
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
	rbTreeNode<pair< K, E> > *y = x->rightChild;//设置y为x的右孩子
	 // 将 “y的左孩子” 设为 “x的右孩子”；
	 // 如果y的左孩子非空，将 “x” 设为 “y的左孩子的父亲
	x->rightChild = y->leftChild;
	if(x->rightChild != NULL)
		x->rightChild->parent = x;
	
	if (x->parent == NULL)//如果x的父亲是空节点，则设置y为根节点
	{
		root = y;
		y->parent = NULL;
	}
	else
	{
		if (x->parent->leftChild == x)//如果x是它父亲节点的左孩子，将y作为做孩子
			x->parent->leftChild= y;
		else
			x->parent->rightChild = y;//如果x是它父亲节点的右孩子，将y作为右孩子
	}
	y->parent = x->parent;
	y->leftChild = x;//将x设置为y的右孩子
	x->parent = y;//将y设为x的父亲节点
}


template<class K, class E>
void rbTree<K, E>::rightRotate(rbTreeNode<pair< K, E> >*	x)
{
	rbTreeNode<pair< K, E> >* y = x->leftChild;//设置y为x的左孩子
	x->leftChild = y->rightChild;
	if(x->leftChild != NULL)
		x->leftChild->parent = x;
	if (x->parent == NULL)//如果x的父亲是空节点，则设置y为根节点
	{
		root = y;
	}
	else
		if (x->parent->leftChild == x)//如果x是它父亲节点的左孩子，将y作为左孩子
			x->parent->leftChild = y;
		else
			x->parent->rightChild = y;//如果x是它父亲节点的右孩子，将y作为右孩子
	y->parent = x->parent;
	y->rightChild = x;//将x设置为y的右孩子
	x->parent = y;//将y设为x的父亲节点
}


template<class K, class E>
inline void rbTree<K, E>::insert(rbTreeNode<pair<K, E> >* node)
{
	rbTreeNode<pair< K, E> >* y = NULL;
	rbTreeNode<pair< K, E> >* x = root;
	//查找要插入的位置，将节点插入到二叉树中
	while (x != NULL)
	{
		y = x;
		if ( node->element.first<x->element.first )
			x = x->leftChild;
		else
			x = x->rightChild;
	}
	node->parent = y;
	if (y != NULL)//如果树不为空
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
	//插入之后改变颜色
	node->color = red;

	//调整为二叉搜索树
	insertFixUp(node);
}

template<class K, class E>
inline void rbTree<K, E>::insertFixUp(rbTreeNode<pair<K, E> >* theNode)
{
	rbTreeNode<pair< K, E> >  *pu, *gu,*gur;
	while ((pu = rb_parent(theNode))&&rb_is_red(pu)&&(gu = rb_parent(pu)))//祖父节点存在 父亲节点存在并且父亲节点的颜色是红色
	{
		//若父亲节点是祖父节点的左孩子
		if (pu == gu->leftChild)
		{
			gur = gu->rightChild;//祖父节点的右孩子
			//1.祖父节点gu的右孩子gur是红色   LLr/LRr
			//处理方法：将pu和gur设为黑色，如果gu不是根节点，将gu设为红色
			if (gur&&rb_is_red(gur))
			{
				rb_set_black(gur);
				rb_set_black(pu);
				if (gu != root)//如果gu不是根节点，将gu设为红色
					rb_set_red(gu);
				theNode = gu;
				continue;//结束本次循环，将gu作为新的节点node
			}
			//2.gur为黑色，当前结点是左孩子  LLb
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
			//3.gur节点是黑色，且当前节点是右孩子  LRb
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
			//pu节点是gu节点的右孩子
			rbTreeNode<pair< K, E> >* gur = gu->leftChild;
			//1.gur存在，gur节点是红色  RLr，RRr
			if (gur && rb_is_red(gur))
			{
				rb_set_black(gur);
				rb_set_black(pu);
				if (gu != root)//如果gu不是根节点，将gu设为红色
					rb_set_red(gu);
				theNode = gu;
				continue;
			}

			// Case 2条件：叔叔是黑色，且当前节点是左孩子  RRb
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
			//3.gur节点是黑色，且当前节点是右孩子  RLb
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
   {  // 两个孩子
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

   // 最多一个孩子
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
		if(p == p->parent->rightChild){    //p是右孩子
			pBro = p->parent->leftChild;
			if (pBro->color == black) {//p是右孩子，pBro是黑的//Rb型
				if(pBro->leftChild->color == black){//pBro的左孩子是黑的
					if(pBro->rightChild->color == black){//pBro的右孩子是黑的
						if(pBro->parent->color == black){
							pBro->color = red ;	                    //Rb0(i)
							eraseFixUp(p->parent);
						}
						else{
							pBro->color = red ;
							p->parent->color = black;               //Rb0(ii)
						}
					}
					else{  //pBro的左孩子是black,右孩子是red
						leftRotate(pBro);
						rightRotate(pBro->parent->parent);
						pBro->rightChild->color = p->parent->color; //Rb1(ii)
						p->parent->color = black;
					}
				}
				else{  //pBro的左孩子是red右孩子是黑的或左右都是黑的
					pBro->leftChild->color = black;
					pBro->rightChild->color = black;                //Rb1(i)和Rb2
					rightRotate(pBro->parent);
					}
			}//一直到这   p是右孩子，pBro是黑的   //Rb型

			else{//p是右孩子，pBro是red  //Rr型
				if(pBro->leftChild->color == black && pBro->rightChild->color == black){//pBro的两个孩子都是黑的
					if(pBro->rightChild->leftChild->color == black){//pBro->R->L是黑的
						if(pBro->rightChild->rightChild->color == black){//pBro->R->L是黑的，pBro->R->R是黑的
							pBro->rightChild->color = red;
							pBro->color = black;                              //Rr0
							rightRotate(pBro->parent);
						}
						else{//pBro->R->L是黑的，pBro->R->R是红的
							pBro->rightChild->rightChild->color = black;
							leftRotate(pBro->rightChild);                    //Rr1(ii)
							leftRotate(pBro);
							rightRotate(pBro->parent->parent);  //Rr1(ii)
						}
					}
					else{//pBro->R->L是红的
						if(pBro->rightChild->rightChild->color == black){//pBro->R->L是红的，pBro->R->R是黑的
							leftRotate(pBro);
							rightRotate(pBro->parent->parent);               //Rr1(i)
							pBro->rightChild->color = black;
						}
						else{//pBro->R->L是红的，pBro->R->R是红的
							pBro->rightChild->leftChild->color = black;
							pBro->rightChild->rightChild->color = black;
							leftRotate(pBro);
							rightRotate(pBro->parent->parent);               //Rr2

						}
					}
				}//pBro是red，pBro的两个孩子都是黑的，红的不作处理
			}//一直到这p是右孩子，pBro是red    //Rr型
		}//一直到这p是右孩子

		else{//p是左孩子
			pBro = p->parent->rightChild;
			if(pBro->color == black){//pBro是黑的
				if(pBro->leftChild->color == black){//pBro的左孩子是black
					if(pBro->rightChild->color == black){//pBro的右孩子是black
						if(pBro->parent->color == black){
							pBro->color = red;                      //Lb0(i)
							eraseFixUp(p->parent);
						}
						else{
							pBro->color = red;
							pBro->parent->color = black;            //Lb0(ii)
						}
					}//pBro左右孩子都是黑
					else{  //pBro的左孩子是black,右孩子是red
						leftRotate(pBro->parent);
						pBro->rightChild->color = black;            //Lb1(i)
					}
				}
				else{  //pBro的左孩子是red
					if(pBro->rightChild->color == black){//pBro的左孩子是red,右孩子是black
						rightRotate(pBro);
						leftRotate(pBro->parent->parent);
						pBro->parent->color = p->parent->color;
						p->parent->color = black;                    //Lb1(ii)
					}
					else{//pBro的左孩子是red,右孩子是red
						pBro->leftChild->color = black;
						pBro->rightChild->color = black;             //Lb2
						leftRotate(pBro->parent);
					}
				}
			}//一直到这   p是左孩子，pBro是black

			else{//p是左孩子,pBro是红的
				if(pBro->leftChild->color == black && pBro->rightChild->color == black){//pBro的两个孩子都是黑的
					if(pBro->leftChild->leftChild->color == black){//pBro->L->L是黑的
						if(pBro->leftChild->rightChild->color == black){//pBro->L->L是黑的，pBro->L->R是黑的
							pBro->color = black;
							pBro->leftChild->color = red;                        //Lr0
							leftRotate(pBro->parent);
						}
						else{//pBro->L->L是黑的，pBro->L->R是红的
							rightRotate(pBro);
							leftRotate(pBro->parent->parent);
							pBro->leftChild->color = black;                    //Lr1(i)
						}
					}//pBro->L->L是黑的
					else{//pBro->L->L是红的
						if(pBro->leftChild->rightChild->color == black){//pBro->L->L是红的，pBro->L->R是黑的
							rightRotate(pBro->leftChild);
							rightRotate(pBro);
							leftRotate(pBro->parent->parent);                   //Lr1(ii)
							pBro->parent->color = black;
						}//pBro->L->L是红的，pBro->L->R是黑的
						else{//pBro->L->L是红的，pBro->L->R是红的
							pBro->leftChild->leftChild->color = black;
							pBro->leftChild->rightChild->color = black;
							rightRotate(pBro);                                  //Lr2
							leftRotate(pBro->parent->parent);
						}
					}
				}//pBro是red，pBro的两个孩子都是黑的，红的不作处理
			}//一直到这p是左孩子，pBro是red
		}//一直到这p是左孩子
	}
}

// overload << for pair
template <class K, class E>
ostream& operator<<(ostream& out, const pair<K, E>& x)
{
	out << x.first << ' ' << x.second << ' '; return out;
}

#endif
