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

        cout << "[—v‘f‚Ì‘€ì]" << '\n';
        cout << "1.—v‘f‚Ìˆê——•\Ž¦" << '\n';
        cout << "2.‡”Ô‚ðŽw’è‚µ‚Ä—v‘f‚ð•\Ž¦" << '\n';
        cout << "9.—v‘f‘€ì‚É–ß‚é" << '\n';

        cout << "\n------------------------------------------" << '\n';
        cout << "‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << '\n';

        std::cin >> selectmenu;
        std::cin.ignore(1024, '\n');

        switch (selectmenu)
        {

        case 1:
            while (true)
            {
                int returnNum = 0;
                cout << "[—v‘f‚Ìˆê——•\Ž¦]" << '\n';
                cout << "—v‘fˆê——:{" << '\n';
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
                cout << "\n—v‘f”:" << a->size() << '\n';

                cout << "\n------------------------------------------" << '\n';
                cout << "1.—v‘f‚Ì•\Ž¦‚É–ß‚é" << '\n';
                cout << "2.—v‘f‚Ì‘€ì‚É–ß‚é" << '\n';

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
                cout << "[‡”Ô‚ðŽw’è‚µ‚Ä—v‘f‚ð•\Ž¦]" << '\n';
                cout << "•\Ž¦‚µ‚½‚¢—v‘f‚Ì”Ô†‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢" << '\n';
                std::cin >> selectNum;
                std::cin.ignore(1024, '\n');
                if (selectNum < a->size()-1 or a->size()-1 < selectNum)
                {
                    cout << "‚»‚Ì—v‘f‚Í‚ ‚è‚Ü‚¹‚ñ" << '\n';
                    continue;
                }
                else
                {
                    cout << selectNum << ':';
                    a->selectDraw(selectNum);
                }

               

                cout << "\n------------------------------------------" << '\n';
                cout << "1.—v‘f‚Ì•\Ž¦‚É–ß‚é" << '\n';
                cout << "2.—v‘f‚Ì‘€ì‚É–ß‚é" << '\n';

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
    cout << "[ƒŠƒXƒg—v‘f‚Ì‘}“ü]" << '\n';
    cout << "—v‘f‚ð’Ç‰Á‚·‚éêŠ‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢BÅŒã”ö‚É’Ç‰Á‚·‚éê‡‚Í‰½‚à“ü—Í‚µ‚È‚¢‚Å‚­‚¾‚³‚¢B" << '\n';
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
    

    cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << '\n';
    std::cin >> std::setw(256) >> b;
    a->insert(b, selectNum);
    std::cin.ignore(1024, '\n');
    if (a->size()>=2)
    {
        selectNum++;
    }

    cout << "—v‘f\"" << b << "\"‚ª" << selectNum << "”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½" << '\n';

    
};

template <typename T>
void menuEdit(DoublyLinkedList<T>* a)
{
    int b;
    std::string c;
    cout << "[—v‘f‚Ì•ÒW]" << '\n';
    cout << "•ÒW‚µ‚½‚¢—v‘f‚Ì”Ô†‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢" << '\n';

    std::cin >> b;
    std::cin.ignore(1024, '\n');
    if (b > a->size() - 1 or b<0)
    {
        cout << b << "”Ô–Ú‚Ì—v‘f‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << '\n';
    }
    else
    {
        cout << b << "”Ô–Ú‚Ì—v‘f‚Ì•ÏX‚·‚é’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << '\n';
        getline(std::cin, c);
        a->edit(c, b);
        cout << b << "”Ô–Ú‚Ì—v‘f‚Ì’l‚ª\""<< c << "\"‚É•ÏX‚³‚ê‚Ü‚µ‚½" << '\n';
        std::cin.ignore(1024, '\n');
    }

    
}

template <typename T>
void menuDelete(DoublyLinkedList<T>* a)
{

    int b;
    std::string c;
    cout << "[—v‘f‚Ìíœ]" << '\n';
    cout << "íœ‚µ‚½‚¢—v‘f‚Ì”Ô†‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢" << '\n';

    std::cin >> b;

    if (b > a->size() - 1 or b < 0)
    {
        cout << b << "”Ô–Ú‚Ì—v‘f‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << '\n';
    }
    else
    {
        cout << b << "”Ô–Ú‚Ì—v‘f\"" << std::flush;
        a->selectDraw(b);
        cout <<"\"‚ðíœ‚µ‚Ü‚µ‚½" << '\n';
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

        cout << "[—v‘f‚Ì‘€ì]" << '\n';
        cout << "1.—v‘f‚Ì•\Ž¦" << '\n';
        cout << "2.—v‘f‚Ì‘}“ü" << '\n';
        if (a.size() != 0)
        {
            cout << "3.—v‘f‚Ì•ÒW" << '\n';
            cout << "4.—v‘f‚Ìíœ" << '\n';
        }
        cout << "‚»‚Ì‘¼:I—¹" << '\n';
        cout << "\n------------------------------------------" << '\n';
        cout << "‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << '\n';

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
            cout << "I—¹‚µ‚Ü‚·" << '\n';
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