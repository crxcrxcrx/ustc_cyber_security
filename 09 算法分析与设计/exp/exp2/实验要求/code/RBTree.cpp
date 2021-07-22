#include "RBTree.h"

//对于出现同名函数，请参考以下关于函数重载的定义理解
//函数重载是一种特殊情况，C++允许在同一作用域中声明几个类似的同名函数，这些同名函数的形参列表（参数个数，类型，顺序）必须不同，常用来处理实现功能类似数据类型不同的问题。


/*
 * 构造函数
 */

RBTree ::RBTree() :mRoot(NULL)
{
    mRoot = NULL;
}

/*
 * 析构函数
 */

RBTree ::~RBTree()
{
    destroy();
}

/*
 * 前序遍历"红黑树"
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
 * 中序遍历"红黑树"
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
 * 后序遍历"红黑树"
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
 * (递归实现)查找"红黑树x"中键值为index的节点
 */
RBTNode * RBTree ::search(RBTNode * x, int index) const
{
    cout << "需要补全" << endl;//补全后请删除此行
	return(NULL);
}


RBTNode * RBTree ::search(int index)
{
    RBTNode* x = search(mRoot, index);
    return x;
}


/*
 * 对红黑树的节点(x)进行左旋转
 *
 * 左旋示意图(对节点x进行左旋)：
 *      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(左旋)-->           / \                #
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
 *
 *
 */

void RBTree ::leftRotate(RBTNode *& root, RBTNode * x)
{
    cout << "需要补全" << endl;//补全后请删除此行;
}

/*
 * 对红黑树的节点(y)进行右旋转
 *
 * 右旋示意图(对节点y进行左旋)：
 *            py                               py
 *           /                                /
 *          y                                x
 *         /  \      --(右旋)-->            /  \                     #
 *        x   ry                           lx   y
 *       / \                                   / \                   #
 *      lx  rx                                rx  ry
 *
 */

void RBTree ::rightRotate(RBTNode *& root, RBTNode * y)
{
    cout << "需要补全" << endl;//补全后请删除此行
}

/*
 * 红黑树插入修正函数
 *
 * 在向红黑树中插入节点之后(失去*衡)，再调用该函数；
 * 目的是将它重新塑造成一颗红黑树。
 *
 * 参数说明：
 *     root 红黑树的根
 *     node 插入的结点        // 对应《算法导论》中的z
 */

void RBTree ::insertFixUp(RBTNode *& root, RBTNode * node)
{
    cout << "需要补全" << endl;//补全后请删除此行
}

/*
 * 将结点插入到红黑树中
 *
 * 参数说明：
 *     root 红黑树的根结点
 *     node 插入的结点        // 对应《算法导论》中的node
 */

void RBTree ::insert(RBTNode *& root, RBTNode * node)
{
    cout << "需要补全" << endl;//补全后请删除此行
}

/*
 * 将结点(index为节点键值)插入到红黑树中
 *
 * 参数说明：
 *     tree 红黑树的根结点
 *     index 插入结点的键值
 */

void RBTree::insert(int index, string mac)
{
    RBTNode * z = NULL;

    // 如果新建结点失败，则返回。【这里提高了一种新建结点的方法】
    if ((z = new RBTNode (index, mac, BLACK, NULL, NULL, NULL)) == NULL)
        return;

    insert(mRoot, z);
}

/*
 * 红黑树删除修正函数
 *
 * 在从红黑树中删除插入节点之后(红黑树失去平衡)，再调用该函数；
 * 目的是将它重新塑造成一颗红黑树。
 *
 * 参数说明：
 *     root 红黑树的根
 *     node 待修正的节点
 */

void RBTree ::removeFixUp(RBTNode *& root, RBTNode * node, RBTNode * parent)
{
    cout << "需要补全" << endl;//补全后请删除此行
}

/*
 * 删除结点(node)，并返回被删除的结点
 *
 * 参数说明：
 *     root 红黑树的根结点
 *     node 删除的结点
 */

void RBTree ::remove(RBTNode *& root, RBTNode * node)
{
    cout << "需要补全" << endl;//补全后请删除此行
}

/*
 * 删除红黑树中键值为index的节点
 *
 * 参数说明：
 *     tree 红黑树的根结点
 */

void RBTree ::remove(int index)
{

    // 查找index对应的节点(node)，找到的话就删除该节点（调用前一个remove函数）
    cout << "需要补全" << endl;//补全后请删除此行;

}

/*
 * 销毁红黑树
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
 * 打印"二叉查找树"
 *
 * index       -- 节点的键值
 * direction  --  0，表示该节点是根节点;
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */

void RBTree ::print(RBTNode * tree, int index, int direction)
{
    if (tree != NULL)
    {
        if (direction == 0)    // tree是根节点
            cout << setw(2) << tree->index << "(B) is root" << endl;
        else                // tree是分支节点
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


