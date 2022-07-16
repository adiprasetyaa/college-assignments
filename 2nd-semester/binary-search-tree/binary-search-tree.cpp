#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *kiri, *kanan;
};

struct node *new_Node(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->kiri = temp->kanan = NULL;
    return temp;
}

void in_order(struct node *root)
{
    if (root != NULL)
    {
        in_order(root->kiri);
        cout << root->data << endl;
        in_order(root->kanan);
    }
}

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
        return new_Node(data);

    if (data < node->data)
        node->kiri = insert(node->kiri, data);
    else
        node->kanan = insert(node->kanan, data);

    return node;
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    while (current && current->kiri != NULL)
        current = current->kiri;

    return current;
}

struct node *hapusNode(struct node *root, int data)
{

    if (root == NULL)
        return root;

    if (data < root->data)
        root->kiri = hapusNode(root->kiri, data);

    else if (data > root->data)
        root->kanan = hapusNode(root->kanan, data);

    else
    {
        if (root->kiri == NULL and root->kanan == NULL)
            return NULL;

        else if (root->kiri == NULL)
        {
            struct node *temp = root->kanan;
            free(root);
            return temp;
        }
        else if (root->kanan == NULL)
        {
            struct node *temp = root->kiri;
            free(root);
            return temp;
        }

        struct node *temp = minValueNode(root->kanan);

        root->data = temp->data;

        root->kanan = hapusNode(root->kanan, temp->data);
    }
    return root;
}

int main()
{
    /*Insert untuk membuat BST seperti di bawah ini
            50
        /	 \
        30	 70
        / \ / \
    20 40 60 80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Binary Search Tree dengan inorder Transversal berdasarkan intruksi awal :\n";

    /*
               50
            /     \
          30      70
         /  \    /  \
       20   40  60   80
    */
    in_order(root);

    cout << "\nNode yang dihapus cukup dari pohonnya yaitu delete(20)\n";
    root = hapusNode(root, 20);
    cout << "BST setelah dilakukan delete(20) :\n";
    /*
                  50                            50
               /     \         delete(20)      /   \
             30      70        --------->    30     70
            /  \    /  \                       \   /  \
         20   40  60   80                     40 60   80
    */
    in_order(root);

    cout << "\nNode yang dihapus hanya memiliki satu anak, yaitu delete (30)\n";
    root = hapusNode(root, 30);
    cout << "BST setelah dilakukan delete(30) :\n";
    /*
              50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70
            \    /  \                          /  \
            40  60   80                       60   80
*/

    in_order(root);

    cout << "\nNode yang dihapus memiliki dua anak, yaitu delete (50)\n";
    root = hapusNode(root, 50);
    cout << "BST setelah dilakukan delete(50) :\n";

    /*
                  50                            60
               /     \         delete(50)      /   \
              40      70       --------->    40    70
                     /  \                            \
                    60   80                          80
    */

    in_order(root);

    return 0;
}
