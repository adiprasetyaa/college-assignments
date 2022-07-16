#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int m_data;

    vector<Node> m_cabang;
    Node(int data)
    {
        m_data = data;
    }

    void insert(Node node)
    {

        m_cabang.push_back(node);
    }

    bool deleteNodeIndex(unsigned int index)
    {
        if (m_cabang.empty())
        {
            return false;
        }
        else
        {
            if (m_cabang.size() <= index)
            {
                return false;
            }
            else
            {
                m_cabang.erase(m_cabang.begin() + index);
                return true;
            }
        }
    }

    void _preOrder(unsigned int depth = 0)
    {
        for (unsigned int i = 0; i < depth; i++)
        {
            cout << "--";
        }
        cout << "> " << m_data << '\n';
        for (unsigned int i = 0; i < m_cabang.size(); i++)
        {
            m_cabang[i]._preOrder(depth + 1);
        }
    }

    void preOrder()
    {
        cout << "Preorder Traversal: \n";
        _preOrder();
    }

    void _postOrder(unsigned int depth = 0)
    {
        for (unsigned int i = 0; i < m_cabang.size(); i++)
        {
            m_cabang[i]._postOrder(depth + 1);
        }
        for (unsigned int i = 0; i < depth; i++)
        {
            cout << "--";
        }
        cout << "> " << m_data << '\n';
    }

    void postOrder()
    {
        cout << "Postorder Traversal: \n";
        _postOrder();
    }
};

int main()
{

    // Deklarasi objek-objek node menggunakan variabel root sbg root dan cabang{id} sbg cabangren.
    Node pusat(6);

    Node cabang_0(2);
    Node cabang_1(3);
    Node cabang_2(7);
    Node cabang_3(11);

    Node cabang_4(2);
    Node cabang_5(4);
    Node cabang_6(1);
    Node cabang_7(9);
    Node cabang_8(6);

    Node cabang_9(12);
    Node cabang_10(5);
    Node cabang_11(5);
    Node cabang_12(10);

    Node cabang_13(8);

    // Memasukkan cabang ke parentsnya satu per satu dimulai dari bawah
    // Jawaban untuk soal nomor 1
    cabang_11.insert(cabang_13);

    cabang_4.insert(cabang_9);
    cabang_4.insert(cabang_10);
    cabang_4.insert(cabang_11);
    cabang_4.insert(cabang_12);

    cabang_0.insert(cabang_4);

    cabang_1.insert(cabang_5);
    cabang_1.insert(cabang_6);
    cabang_1.insert(cabang_7);

    cabang_3.insert(cabang_8);

    pusat.insert(cabang_0);
    pusat.insert(cabang_1);
    pusat.insert(cabang_2);
    pusat.insert(cabang_3);

    cout << "Jawaban untuk soal nomor 1 sebagai berikut : \n"
         << endl;
    pusat.preOrder();
    cout << endl;
    pusat.postOrder();

    cout << "\n\nJawaban untuk soal nomor 2 sebagai berikut : \n"
         << endl;

    // Untuk menghapus node dimulai dari yang paling kanan (index yang paling besar)
    pusat.deleteNodeIndex(3);
    pusat.deleteNodeIndex(2);
    pusat.deleteNodeIndex(1);
    pusat.deleteNodeIndex(0);

    // Membuat Node baru untuk memasukkan data yang baru
    Node cabang_14(2);
    Node cabang_15(3);
    Node cabang_16(1);
    Node cabang_17(7);
    Node cabang_18(8);
    Node cabang_19(11);
    Node cabang_20(6);

    // Memasukkan ulang value/data ke dalam node sesuai urutan
    // Dimulai dari data yang paling bawah
    cabang_20.insert(cabang_16);
    cabang_20.insert(cabang_17);
    cabang_20.insert(cabang_18);

    cabang_14.insert(cabang_15);
    cabang_19.insert(cabang_20);

    pusat.insert(cabang_14);
    pusat.insert(cabang_1);
    pusat.insert(cabang_2);
    pusat.insert(cabang_19);

    pusat.preOrder();
    pusat.postOrder();

    return 0;
}