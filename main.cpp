#include <iostream>
#include <string>
#include <stdexcept>
#include <stdio.h>
#include <iomanip>

using namespace std;
template <typename T>
struct Cell
{
    T value_;
    Cell* prev_;
    Cell* next_;
    Cell()
    {
        prev_ = this;
        next_ = this;
    }
    Cell(T value, Cell* prev, Cell* next)
    {
        value_ = value;
        prev_ = prev;
        next_ = next;
    }
};
template <typename T>

class DoublyLinkedList
{
private:
    Cell<T>* dummy_;
    int size_;
public:
    DoublyLinkedList()
    {
        dummy_ = new Cell<T>();
        size_ = 0;
    }
    ~DoublyLinkedList()
    {
        clear();
    }

    void add(T v, Cell<T>* head)
    {
        // insert a new Cell between the current Cell and the next of current Cell
        Cell<T>* newCell = new Cell<T>(v, head, head->next_);
        head->next_->prev_ = newCell;
        head->next_ = newCell;
        // update the current Cell
        head = newCell;
        size_++;
    }
    void push_front(T value)
    {
        Cell<T>* cur = dummy_;
        add(value, cur);
    }
    void push_back(T value)
    {
        Cell<T>* cur = dummy_->prev_;
        add(value, cur);
    }
    bool empty()
    {
        return dummy_->next_ == dummy_;
    }

    void insert(T value,int insertNum)
    {

        Cell<T>* newCell = dummy_->prev_;
        int num = insertNum;
        while(num != 0)
        {
            newCell = newCell->next_;
            num--;
        }

        add(value, newCell);
        

    }
    
    void selectDelete(int deleteNum)
    {

        if (empty())
        {
            throw std::logic_error("Cell is empty!");
        }
        Cell<T>* ptr = dummy_->next_;
        for (int i = 0; i < deleteNum; i++)
        {
            ptr = ptr->next_;
        }
        ptr->prev_->next_ = ptr->next_;
        ptr->next_->prev_ = ptr->prev_;
        delete ptr;
        size_--;

    }

    T remove(Cell<T>* Cell)
    {
        if (empty())
        {
            throw std::logic_error("Cell is empty!");
        }
        T ret = Cell->value_;
        Cell->prev_->next_ = Cell->next_;
        Cell->next_->prev_ = Cell->prev_;
        delete Cell;
        //Cell = Cell->prev_;
        size_--;
        return ret;
    }
    T pop_front()
    {
        Cell<T>* cur = dummy_->next_;
        return remove(cur);
    }

    T pop_back()
    {
        Cell<T>* cur = dummy_->prev_;
        return remove(cur);
    }

    void selectDraw(int drawNum)
    {
        Cell<T>* ptr = dummy_->next_;

        for (int i = 0; i < drawNum; i++)
        {
            ptr = ptr->next_;
        }

        std::string a = std::string(ptr->value_);

        cout << a << ' ';
        

    }

    void draw()
    {
        Cell<T>* ptr = dummy_->next_;
        while (ptr != dummy_)
        {
            cout << ptr->value_ << ' ';
            ptr = ptr->next_;
            cout << '\n';
        }
        
    }

    void edit(T value, int editNum)
    {
        Cell<T>* ptr = dummy_->next_;
        for (int i = 0; i < editNum; i++)
        {
            ptr = ptr->next_;
        }

        ptr->value_ = value;

    }

    void clear()
    {
        while (!empty())
        {
            pop_front();
        }
    }

    int size()
    {
        return size_;
    }
};

template <typename T>

void menuDraw(DoublyLinkedList<T>* a)
{
    int selectmenu = 0;

    bool isEnd = false;
    while (true)
    {

        cout << "[要素の操作]" << '\n';
        cout << "1.要素の一覧表示" << '\n';
        cout << "2.順番を指定して要素を表示" << '\n';
        cout << "9.要素操作に戻る" << '\n';

        cout << "\n------------------------------------------" << '\n';
        cout << "操作を選択してください" << '\n';

        std::cin >> selectmenu;
        std::cin.ignore(1024, '\n');

        switch (selectmenu)
        {

        case 1:
            while (true)
            {
                int returnNum = 0;
                cout << "[要素の一覧表示]" << '\n';
                cout << "要素一覧:{" << '\n';
                for (int i = 0; i < a->size(); i++)
                {
                    cout << i << "\"";
                    a->selectDraw(i);
                    cout << "\"";
                    if (i != a->size() - 1)
                    {
                        cout << ",\n";
                    }
                }
                cout << "\n}" << '\n';
                cout << "\n要素数:" << a->size() << '\n';

                cout << "\n------------------------------------------" << '\n';
                cout << "1.要素の表示に戻る" << '\n';
                cout << "2.要素の操作に戻る" << '\n';

                std::cin >> returnNum;
                std::cin.ignore(1024, '\n');
                if (returnNum == 1)
                {
                    break;
                }
                else if (returnNum == 2)
                {
                    isEnd = true;
                    break;
                }
            }
                break;

        case 2:
            while (true)
            {
                int returnNum = 0;
                int selectNum = 0;
                cout << "[順番を指定して要素を表示]" << '\n';
                cout << "表示したい要素の番号を指定してください" << '\n';
                std::cin >> selectNum;
                std::cin.ignore(1024, '\n');
                if (selectNum < a->size()-1 or a->size()-1 < selectNum)
                {
                    cout << "その要素はありません" << '\n';
                    continue;
                }
                else
                {
                    cout << selectNum << ':';
                    a->selectDraw(selectNum);
                }

               

                cout << "\n------------------------------------------" << '\n';
                cout << "1.要素の表示に戻る" << '\n';
                cout << "2.要素の操作に戻る" << '\n';

                std::cin >> returnNum;
                std::cin.ignore(1024, '\n');
                if (returnNum == 1)
                {
                    break;
                }
                else if (returnNum == 2)
                {
                    isEnd = true;
                    break;
                }
            }

            break;

        case 9:
            isEnd = true;
            break;

        default:
            break;
        }
        if (isEnd)
        {
            break;
        }

    }

};
template <typename T>
void menuInsert(DoublyLinkedList<T>* a)
{
    int selectNum = 0;
    T insertNum;
    std::string b;
    std::string c;
    cout << "[リスト要素の挿入]" << '\n';
    cout << "要素を追加する場所を指定してください。最後尾に追加する場合は何も入力しないでください。" << '\n';
    //std::cin.getline(b, 256);
    getline(std::cin, c);
   
    if (c == "\0")
    {
       
        selectNum = a->size()-1;
        
    }
    else
    {
        selectNum = std::stoi(c);
    }

    if (selectNum > a->size() - 1)
    {
        selectNum = a->size() - 1;
    }

    if (selectNum < 0)
    {
        selectNum = 0;
    }
    
    //std::cin.ignore(1024, '\n');
    

    cout << "追加する要素の値を入力してください" << '\n';
    std::cin >> std::setw(256) >> b;
    a->insert(b, selectNum);
    std::cin.ignore(1024, '\n');
    if (a->size()>=2)
    {
        selectNum++;
    }

    cout << "要素\"" << b << "\"が" << selectNum << "番目に挿入されました" << '\n';

    
};

template <typename T>
void menuEdit(DoublyLinkedList<T>* a)
{
    int b;
    std::string c;
    cout << "[要素の編集]" << '\n';
    cout << "編集したい要素の番号を指定してください" << '\n';

    std::cin >> b;
    std::cin.ignore(1024, '\n');
    if (b > a->size() - 1 or b<0)
    {
        cout << b << "番目の要素が見つかりませんでした" << '\n';
    }
    else
    {
        cout << b << "番目の要素の変更する値を入力してください" << '\n';
        getline(std::cin, c);
        a->edit(c, b);
        cout << b << "番目の要素の値が\""<< c << "\"に変更されました" << '\n';
        std::cin.ignore(1024, '\n');
    }

    
}

template <typename T>
void menuDelete(DoublyLinkedList<T>* a)
{

    int b;
    std::string c;
    cout << "[要素の削除]" << '\n';
    cout << "削除したい要素の番号を指定してください" << '\n';

    std::cin >> b;

    if (b > a->size() - 1 or b < 0)
    {
        cout << b << "番目の要素が見つかりませんでした" << '\n';
    }
    else
    {
        cout << b << "番目の要素\"" << std::flush;
        a->selectDraw(b);
        cout <<"\"を削除しました" << '\n';
        a->selectDelete(b);
    }

}


int main()
{
    DoublyLinkedList<std::string> a;

    int selectmenu = 0;

    bool isEnd = false;

    while (true)
    {

        cout << "[要素の操作]" << '\n';
        cout << "1.要素の表示" << '\n';
        cout << "2.要素の挿入" << '\n';
        if (a.size() != 0)
        {
            cout << "3.要素の編集" << '\n';
            cout << "4.要素の削除" << '\n';
        }
        cout << "その他:終了" << '\n';
        cout << "\n------------------------------------------" << '\n';
        cout << "操作を選択してください" << '\n';

        std::cin >> selectmenu;
        std::cin.ignore(1024, '\n');

        switch (selectmenu)
        {
        case 1:
            menuDraw(&a);
            break;

        case 2:
            menuInsert(&a);
            break;
        case 3:
            if (a.size() != 0)
            {
                menuEdit(&a);
            }
            break;
        case 4:
            if (a.size() != 0)
            {
                menuDelete(&a);
            }
            break;
        default:
            cout << "終了します" << '\n';
            isEnd = true;
            break;
        }
        if (isEnd)
        {
            break;
        }

    }
    system("pause");
    return 0;
}