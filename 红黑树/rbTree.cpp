
#include <iostream>
#include "rbTree.h"

using namespace std;

int main(void)
{

	rbTree<int, char> y;
////��1
//	y.insert(pair<int, char>(50, 'b'));
//	y.insert(pair<int, char>(40, 'c'));
//	y.insert(pair<int, char>(80, 'd'));
//	y.insert(pair<int, char>(90, 'b'));
//	y.insert(pair<int, char>(70, 'b'));
//	y.insert(pair<int, char>(60, 'c'));
//	y.insert(pair<int, char>(65, 'd'));
//	y.insert(pair<int, char>(62, 'd'));
//	y.insert(pair<int, char>(57, 'b'));
//	y.insert(pair<int, char>(56, 'b'));
//	y.insert(pair<int, char>(58, 'c'));
//	y.insert(pair<int, char>(30, 'c'));
//	y.insert(pair<int, char>(100, 'c'));
//	y.insert(pair<int, char>(75, 'c'));
//	y.insert(pair<int, char>(64, 'b'));
//	y.insert(pair<int, char>(67, 'b'));
//	y.insert(pair<int, char>(66, 'b'));
//	y.insert(pair<int, char>(69, 'b'));
//	y.insert(pair<int, char>(72, 'b'));
//	y.insert(pair<int, char>(88, 'b'));
//	y.insert(pair<int, char>(85, 'b'));
//	y.insert(pair<int, char>(95, 'b'));
//	y.insert(pair<int, char>(45, 'b'));
//	y.insert(pair<int, char>(20, 'b'));
//	y.ascend();
//	cout<<endl;
//	cout<<"after erase"<< endl;
//	y.erase(pair<int, char>(40, 'c'));//Lr2
//	//y.erase(pair<int, char>(50, 'b'));//Lb2
//	//y.erase(pair<int, char>(80, 'd'));//Rb1(ii)
//	//y.erase(pair<int, char>(62, 'd'));//Rb2
//	y.ascend();

//��2
	y.insert(pair<int, char>(50, 'b'));
	y.insert(pair<int, char>(40, 'c'));
	y.insert(pair<int, char>(80, 'd'));
	y.insert(pair<int, char>(90, 'b'));
	y.insert(pair<int, char>(72, 'b'));
	y.insert(pair<int, char>(60, 'c'));
	y.insert(pair<int, char>(65, 'd'));
	y.insert(pair<int, char>(62, 'd'));
	y.insert(pair<int, char>(57, 'b'));
	y.insert(pair<int, char>(56, 'b'));
	y.insert(pair<int, char>(58, 'c'));
	y.insert(pair<int, char>(30, 'c'));
	y.insert(pair<int, char>(100, 'c'));
	y.insert(pair<int, char>(75, 'c'));
	y.insert(pair<int, char>(64, 'b'));
	y.insert(pair<int, char>(68, 'b'));
	y.insert(pair<int, char>(67, 'b'));
	y.insert(pair<int, char>(69, 'b'));
	y.insert(pair<int, char>(74, 'b'));
	y.insert(pair<int, char>(88, 'b'));
	y.insert(pair<int, char>(85, 'b'));
	y.insert(pair<int, char>(95, 'b'));
	y.insert(pair<int, char>(45, 'b'));
	y.insert(pair<int, char>(20, 'b'));
	y.insert(pair<int, char>(66, 'b'));
	y.insert(pair<int, char>(70, 'b'));
	y.insert(pair<int, char>(55, 'b'));//����55֮ǰ������Rb1(i)��Lb0(i)
	y.ascend();
	cout<<endl;
	y.check1();
	cout<<"after erase"<< endl;
	//y.erase(pair<int, char>(90, 'b'));//Rb1(i)
	//y.erase(pair<int, char>(72, 'b'));//Lb0(i)
	//y.erase(pair<int, char>(60, 'c'));//Rb0(ii)1
	//y.erase(pair<int, char>(72, 'b'));//Lb0(ii)
	//y.erase(pair<int, char>(40, 'c'));//Lb1(ii)
	//y.erase(pair<int, char>(80, 'd'));//Rr1(i)1
	y.erase(pair<int, char>(62, 'b'));//Rr2
	//y.erase(pair<int, char>(50, 'b'));//Lr1(ii)1
	y.check1();
	y.ascend();

//��3
//	y.insert(pair<int, char>(50, 'b'));
//	y.insert(pair<int, char>(40, 'c'));
//	y.insert(pair<int, char>(80, 'd'));
//	y.insert(pair<int, char>(90, 'b'));
//	y.insert(pair<int, char>(72, 'b'));
//	y.insert(pair<int, char>(60, 'c'));
//	y.insert(pair<int, char>(65, 'd'));
//	y.insert(pair<int, char>(62, 'd'));
//	y.insert(pair<int, char>(57, 'b'));
//	y.insert(pair<int, char>(56, 'b'));
//	y.insert(pair<int, char>(58, 'c'));
//	y.insert(pair<int, char>(30, 'c'));
//	y.insert(pair<int, char>(100, 'c'));
//	y.insert(pair<int, char>(75, 'c'));
//	y.insert(pair<int, char>(64, 'b'));
//	y.insert(pair<int, char>(68, 'b'));
//	y.insert(pair<int, char>(67, 'b'));
//	y.insert(pair<int, char>(69, 'b'));
//	y.insert(pair<int, char>(74, 'b'));
//	y.insert(pair<int, char>(88, 'b'));
//	y.insert(pair<int, char>(85, 'b'));
//	y.insert(pair<int, char>(95, 'b'));
//	y.insert(pair<int, char>(45, 'b'));
//	y.insert(pair<int, char>(20, 'b'));
//	y.insert(pair<int, char>(66, 'b'));
//	y.insert(pair<int, char>(70, 'b'));
//	y.insert(pair<int, char>(55, 'b'));
//	//cout<<"ɾ��66,67,74�������Lr1(i)"<< endl;
//	y.erase(pair<int, char>(74, 'b'));
//	y.erase(pair<int, char>(66, 'b'));
//	y.erase(pair<int, char>(67, 'b'));
//	cout<<"ɾ��66,67,74�������Lr1(i)"<< endl;
//	y.ascend();
//	//y.erase(pair<int, char>(50, 'b'));//Lr1(i)
//	cout<<endl;

//��4
//	y.insert(pair<int, char>(50, 'b'));
//	y.insert(pair<int, char>(40, 'c'));
//	y.insert(pair<int, char>(80, 'd'));
//	y.insert(pair<int, char>(90, 'b'));
//	y.insert(pair<int, char>(72, 'b'));
//	y.insert(pair<int, char>(60, 'c'));
//	y.insert(pair<int, char>(65, 'd'));
//	y.insert(pair<int, char>(62, 'd'));
//	y.insert(pair<int, char>(57, 'b'));
//	y.insert(pair<int, char>(56, 'b'));
//	y.insert(pair<int, char>(58, 'c'));
//	y.insert(pair<int, char>(30, 'c'));
//	y.insert(pair<int, char>(100, 'c'));
//	y.insert(pair<int, char>(75, 'c'));
//	y.insert(pair<int, char>(64, 'b'));
//	y.insert(pair<int, char>(68, 'b'));
//	y.insert(pair<int, char>(67, 'b'));
//	y.insert(pair<int, char>(69, 'b'));
//	y.insert(pair<int, char>(74, 'b'));
//	y.insert(pair<int, char>(88, 'b'));
//	y.insert(pair<int, char>(85, 'b'));
//	y.insert(pair<int, char>(95, 'b'));
//	y.insert(pair<int, char>(45, 'b'));
//	y.insert(pair<int, char>(20, 'b'));
//	y.insert(pair<int, char>(66, 'b'));
//	y.insert(pair<int, char>(70, 'b'));
//	y.insert(pair<int, char>(55, 'b'));
//	//cout<<"ɾ��66,67�������Lr0"<< endl;
//	y.erase(pair<int, char>(66, 'b'));
//	y.erase(pair<int, char>(67, 'b'));
//	cout<<"ɾ��66,67,74�������Lr0"<< endl;
//	y.ascend();
//	//y.erase(pair<int, char>(50, 'b'));//Lr0
//	cout<<endl;

//��5
//	y.insert(pair<int, char>(50, 'b'));
//	y.insert(pair<int, char>(40, 'c'));
//	y.insert(pair<int, char>(80, 'd'));
//	y.insert(pair<int, char>(90, 'b'));
//	y.insert(pair<int, char>(72, 'b'));
//	y.insert(pair<int, char>(60, 'c'));
//	y.insert(pair<int, char>(65, 'd'));
//	y.insert(pair<int, char>(62, 'd'));
//	y.insert(pair<int, char>(57, 'b'));
//	y.insert(pair<int, char>(56, 'b'));
//	y.insert(pair<int, char>(58, 'c'));
//	y.insert(pair<int, char>(30, 'c'));
//	y.insert(pair<int, char>(100, 'c'));
//	y.insert(pair<int, char>(75, 'c'));
//	y.insert(pair<int, char>(64, 'b'));
//	y.insert(pair<int, char>(68, 'b'));
//	y.insert(pair<int, char>(67, 'b'));
//	y.insert(pair<int, char>(69, 'b'));
//	y.insert(pair<int, char>(74, 'b'));
//	y.insert(pair<int, char>(88, 'b'));
//	y.insert(pair<int, char>(85, 'b'));
//	y.insert(pair<int, char>(95, 'b'));
//	y.insert(pair<int, char>(45, 'b'));
//	y.insert(pair<int, char>(20, 'b'));
//	y.insert(pair<int, char>(66, 'b'));
//	y.insert(pair<int, char>(70, 'b'));
//	y.insert(pair<int, char>(55, 'b'));
//	//cout<<"ɾ��55,56,58�������Rr0"<< endl;
//	y.erase(pair<int, char>(55, 'b'));
//	y.erase(pair<int, char>(56, 'b'));
//	y.erase(pair<int, char>(58, 'c'));
//	cout<<"ɾ��66,67,74�������Rr0"<< endl;
//	y.ascend();
//	//y.erase(pair<int, char>(80, 'd'));//Rr0
//	cout<<endl;

//��6
//	y.insert(pair<int, char>(50, 'b'));
//	y.insert(pair<int, char>(40, 'c'));
//	y.insert(pair<int, char>(80, 'd'));
//	y.insert(pair<int, char>(90, 'b'));
//	y.insert(pair<int, char>(72, 'b'));
//	y.insert(pair<int, char>(60, 'c'));
//	y.insert(pair<int, char>(65, 'd'));
//	y.insert(pair<int, char>(62, 'd'));
//	y.insert(pair<int, char>(57, 'b'));
//	y.insert(pair<int, char>(56, 'b'));
//	y.insert(pair<int, char>(58, 'c'));
//	y.insert(pair<int, char>(30, 'c'));
//	y.insert(pair<int, char>(100, 'c'));
//	y.insert(pair<int, char>(75, 'c'));
//	y.insert(pair<int, char>(64, 'b'));
//	y.insert(pair<int, char>(68, 'b'));
//	y.insert(pair<int, char>(67, 'b'));
//	y.insert(pair<int, char>(69, 'b'));
//	y.insert(pair<int, char>(74, 'b'));
//	y.insert(pair<int, char>(88, 'b'));
//	y.insert(pair<int, char>(85, 'b'));
//	y.insert(pair<int, char>(95, 'b'));
//	y.insert(pair<int, char>(45, 'b'));
//	y.insert(pair<int, char>(20, 'b'));
//	y.insert(pair<int, char>(66, 'b'));
//	y.insert(pair<int, char>(70, 'b'));
//	y.insert(pair<int, char>(55, 'b'));
//	//cout<<"ɾ��58,64�������Lb1(i)"<< endl;
//	y.erase(pair<int, char>(64, 'b'));
//	y.erase(pair<int, char>(58, 'c'));
//	cout<<"ɾ��58,64�������Lb1(i)"<< endl;
//	y.ascend();
//	y.erase(pair<int, char>(40, 'c'));//Lb1(i)
//	cout<<endl;


	return 0;


}
