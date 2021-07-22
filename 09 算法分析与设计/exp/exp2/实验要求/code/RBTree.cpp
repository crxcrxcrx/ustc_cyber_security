#include "RBTree.h"

//���ڳ���ͬ����������ο����¹��ں������صĶ������
//����������һ�����������C++������ͬһ�������������������Ƶ�ͬ����������Щͬ���������β��б��������������ͣ�˳�򣩱��벻ͬ������������ʵ�ֹ��������������Ͳ�ͬ�����⡣


/*
 * ���캯��
 */

RBTree ::RBTree() :mRoot(NULL)
{
    mRoot = NULL;
}

/*
 * ��������
 */

RBTree ::~RBTree()
{
    destroy();
}

/*
 * ǰ�����"�����"
 */
void RBTree ::preOrder(RBTNode * tree) const
{
    if (tree != NULL)
    {
        cout << tree->index << " " << tree->mac << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void RBTree ::preOrder()
{
    preOrder(mRoot);
}



/*
 * �������"�����"
 */
void RBTree ::inOrder(RBTNode * tree) const
{
    if (tree != NULL)
    {
        inOrder(tree->left);
        cout << tree->index << " " << tree->mac << endl;
        inOrder(tree->right);
    }
}


void RBTree ::inOrder()
{
    inOrder(mRoot);
}

/*
 * �������"�����"
 */

void RBTree ::postOrder(RBTNode * tree) const
{
    if (tree != NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->index << " " << tree->mac;
    }
}


void RBTree ::postOrder()
{
    postOrder(mRoot);
}

/*
 * (�ݹ�ʵ��)����"�����x"�м�ֵΪindex�Ľڵ�
 */
RBTNode * RBTree ::search(RBTNode * x, int index) const
{
    cout << "��Ҫ��ȫ" << endl;//��ȫ����ɾ������
	return(NULL);
}


RBTNode * RBTree ::search(int index)
{
    RBTNode* x = search(mRoot, index);
    return x;
}


/*
 * �Ժ�����Ľڵ�(x)��������ת
 *
 * ����ʾ��ͼ(�Խڵ�x��������)��
 *      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(����)-->           / \                #
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
 *
 *
 */

void RBTree ::leftRotate(RBTNode *& root, RBTNode * x)
{
    cout << "��Ҫ��ȫ" << endl;//��ȫ����ɾ������;
}

/*
 * �Ժ�����Ľڵ�(y)��������ת
 *
 * ����ʾ��ͼ(�Խڵ�y��������)��
 *            py                               py
 *           /                                /
 *          y                                x
 *         /  \      --(����)-->            /  \                     #
 *        x   ry                           lx   y
 *       / \                                   / \                   #
 *      lx  rx                                rx  ry
 *
 */

void RBTree ::rightRotate(RBTNode *& root, RBTNode * y)
{
    cout << "��Ҫ��ȫ" << endl;//��ȫ����ɾ������
}

/*
 * �����������������
 *
 * ���������в���ڵ�֮��(ʧȥ*��)���ٵ��øú�����
 * Ŀ���ǽ������������һ�ź������
 *
 * ����˵����
 *     root ������ĸ�
 *     node ����Ľ��        // ��Ӧ���㷨���ۡ��е�z
 */

void RBTree ::insertFixUp(RBTNode *& root, RBTNode * node)
{
    cout << "��Ҫ��ȫ" << endl;//��ȫ����ɾ������
}

/*
 * �������뵽�������
 *
 * ����˵����
 *     root ������ĸ����
 *     node ����Ľ��        // ��Ӧ���㷨���ۡ��е�node
 */

void RBTree ::insert(RBTNode *& root, RBTNode * node)
{
    cout << "��Ҫ��ȫ" << endl;//��ȫ����ɾ������
}

/*
 * �����(indexΪ�ڵ��ֵ)���뵽�������
 *
 * ����˵����
 *     tree ������ĸ����
 *     index ������ļ�ֵ
 */

void RBTree::insert(int index, string mac)
{
    RBTNode * z = NULL;

    // ����½����ʧ�ܣ��򷵻ء������������һ���½����ķ�����
    if ((z = new RBTNode (index, mac, BLACK, NULL, NULL, NULL)) == NULL)
        return;

    insert(mRoot, z);
}

/*
 * �����ɾ����������
 *
 * �ڴӺ������ɾ������ڵ�֮��(�����ʧȥƽ��)���ٵ��øú�����
 * Ŀ���ǽ������������һ�ź������
 *
 * ����˵����
 *     root ������ĸ�
 *     node �������Ľڵ�
 */

void RBTree ::removeFixUp(RBTNode *& root, RBTNode * node, RBTNode * parent)
{
    cout << "��Ҫ��ȫ" << endl;//��ȫ����ɾ������
}

/*
 * ɾ�����(node)�������ر�ɾ���Ľ��
 *
 * ����˵����
 *     root ������ĸ����
 *     node ɾ���Ľ��
 */

void RBTree ::remove(RBTNode *& root, RBTNode * node)
{
    cout << "��Ҫ��ȫ" << endl;//��ȫ����ɾ������
}

/*
 * ɾ��������м�ֵΪindex�Ľڵ�
 *
 * ����˵����
 *     tree ������ĸ����
 */

void RBTree ::remove(int index)
{

    // ����index��Ӧ�Ľڵ�(node)���ҵ��Ļ���ɾ���ýڵ㣨����ǰһ��remove������
    cout << "��Ҫ��ȫ" << endl;//��ȫ����ɾ������;

}

/*
 * ���ٺ����
 */

void RBTree ::destroy(RBTNode *& tree)
{
    if (tree == NULL)
        return;

    if (tree->left != NULL)
        return destroy(tree->left);
    if (tree->right != NULL)
        return destroy(tree->right);

    delete tree;
    tree = NULL;
}


void RBTree ::destroy()
{
    destroy(mRoot);
}

/*
 * ��ӡ"���������"
 *
 * index       -- �ڵ�ļ�ֵ
 * direction  --  0����ʾ�ýڵ��Ǹ��ڵ�;
 *               -1����ʾ�ýڵ������ĸ���������;
 *                1����ʾ�ýڵ������ĸ������Һ��ӡ�
 */

void RBTree ::print(RBTNode * tree, int index, int direction)
{
    if (tree != NULL)
    {
        if (direction == 0)    // tree�Ǹ��ڵ�
            cout << setw(2) << tree->index << "(B) is root" << endl;
        else                // tree�Ƿ�֧�ڵ�
            cout << setw(2) << tree->index << (rb_is_red(tree) ? "(R)" : "(B)") << " is " << setw(2) << index << "'s " << setw(12) << (direction == 1 ? "right child" : "left child") << endl;

        print(tree->left, tree->index, -1);
        print(tree->right, tree->index, 1);
    }
}


void RBTree ::print()
{
    if (mRoot != NULL)
        print(mRoot, mRoot->index, 0);
}


