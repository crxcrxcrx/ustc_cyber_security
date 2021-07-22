#pragma once

#define _RED_BLACK_TREE_HPP_

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

enum RBTColor { RED, BLACK };


class RBTNode {  //����ڵ�
public:
    RBTColor color;    // ��ɫ
    int index;            // �ؼ���(index)
    string mac;           // mac
    RBTNode* left;    // ����
    RBTNode* right;    // �Һ���
    RBTNode* parent; // �����

    RBTNode(int key, string value, RBTColor c, RBTNode* p, RBTNode* l, RBTNode* r) :
        index(key), mac(value), color(c), parent(), left(l), right(r) {}
};



//���ڳ���ͬ����������ο����¹��ں������صĶ������
//����������һ�����������C++������ͬһ�������������������Ƶ�ͬ����������Щͬ���������β��б��������������ͣ�˳�򣩱��벻ͬ������������ʵ�ֹ��������������Ͳ�ͬ�����⡣

class RBTree {   //����RBTree��
private:
    RBTNode * mRoot;    // �����

public:
    RBTree();
    ~RBTree();

    // ǰ�����"�����"
    void preOrder();
    // �������"�����"
    void inOrder();
    // �������"�����"
    void postOrder();

    // (�ݹ�ʵ��)����"�����"�м�ֵΪindex�Ľڵ�
    RBTNode * search(int index);;

    // �����(indexΪ�ڵ��ֵ)���뵽�������
    void insert(int index, string mac);

    // ɾ�����(indexΪ�ڵ��ֵ)
    void remove(int index);//����Ҫ���в�ȫ���ɲο�PPT��

    // ���ٺ����
    void destroy();

    // ��ӡ�����
    void print();
private:
    // ǰ�����"�����"
    void preOrder(RBTNode * tree) const;
    // �������"�����"
    void inOrder(RBTNode * tree) const;
    // �������"�����"
    void postOrder(RBTNode * tree) const;

    // (�ݹ�ʵ��)����"�����x"�м�ֵΪindex�Ľڵ�
    RBTNode * search(RBTNode * x, int index) const;//����Ҫ���в�ȫ���ɲο�PPT��

    // ����
    void leftRotate(RBTNode *& root, RBTNode * x);//����Ҫ���в�ȫ���ɲο�PPT��
    // ����
    void rightRotate(RBTNode *& root, RBTNode * y);//����Ҫ���в�ȫ���ɲο�PPT��
    // ���뺯��
    void insert(RBTNode *& root, RBTNode * node);//����Ҫ���в�ȫ���ɲο�PPT��
    // ������������
    void insertFixUp(RBTNode *& root, RBTNode * node);//����Ҫ���в�ȫ���ɲο�PPT��
    // ɾ������
    void remove(RBTNode *& root, RBTNode * node);//����Ҫ���в�ȫ���ɲο�PPT��
    // ɾ����������
    void removeFixUp(RBTNode *& root, RBTNode * node, RBTNode * parent);//����Ҫ���в�ȫ���ɲο�PPT��

    // ���ٺ����
    void destroy(RBTNode *& tree);

    // ��ӡ�����
    void print(RBTNode * tree, int index, int direction);

#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
// �ṩһЩ�����ĺ궨�壬��ѡ��ʹ�á��Ǳ���ʹ�á�
};