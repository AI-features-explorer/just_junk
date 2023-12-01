# This is lab. work

`Task: Write a binary tree. search and count leaves at the current level`

*main mthod realiation:*

```cpp

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

```
