#include <iostream>
#include <iomanip>
#include <queue>
#include <cstdlib> // Для функции rand()
#include <ctime>   // Для функции time()
#include <string.h>


// Узел бинарного дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    // Вставка значения в бинарное дерево
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Рекурсивная вставка
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    // Определение числа листьев на заданном уровне
    int countLeavesAtLevel(int level) {
        return countLeavesAtLevelRecursive(root, level);
    }

    // Рекурсивное определение числа листьев на заданном уровне
    int countLeavesAtLevelRecursive(TreeNode* root, int level) {
        if (root == nullptr)
            return 0;

        // Если текущий уровень равен 1 и узел не имеет потомков, возвращаем 1
        if (level == 1 && root->left == nullptr && root->right == nullptr)
            return 1;

        // Рекурсивно вызываем функцию для левого и правого поддерева
        return countLeavesAtLevelRecursive(root->left, level - 1) + 
                countLeavesAtLevelRecursive(root->right, level - 1);
    }    

    int countLeavesAtLevelNew(TreeNode* root, int level) {
        if (root == nullptr)
            return 0;

        // Если текущий уровень равен 1 и узел является листом, возвращаем 1
        if (level == 1 && root->left == nullptr && root->right == nullptr)
            return 1;

        // Рекурсивно вызываем функцию для левого и правого поддерева,
        // уменьшая значение level на 1 при каждом вызове
        return countLeavesAtLevelNew(root->left, level - 1) + countLeavesAtLevelNew(root->right, level - 1);
    }

    // Древовидный вывод на консоль
    void printTree() {
        PrintTreeLR(root, 0, "*");
    }

    void PrintTreeLR(TreeNode* Tree, int level , std::string aligment)
    {
    int i;
        if (Tree)
        {
            PrintTreeLR(Tree->right,level+1,"R");
            for (i=0; i<level; i++)
                std::cout << "\t";
            std::cout << Tree->data << "(" << level + 1 << aligment << ")";
            PrintTreeLR(Tree->left, level+1, "L");
        }
        else 
            std::cout << "\n"; //std::endl;
    }
};

int main() {
    BinaryTree tree;

    srand(time(nullptr)); 
        for (int i = 0; i < 14; ++i) {
            tree.insert(rand() % 21); // Вставляем случайное значение от 0 до 20
        }

    // Древовидный вывод
    std::cout << "Binary Tree:\n";
    tree.printTree();

    // Определение числа листьев на уровне 2
    int level = 3;
    int leavesAtLevel = tree.countLeavesAtLevel(level);
    std::cout << "\nNumber of leaves at level " << level << ": " << leavesAtLevel << "\n";

    return 0;
}