#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <stdio.h>
#include <iomanip>
#include <list>


using namespace std;

class PIC
{
public:
    PIC();
    PIC(unsigned int ID, string Name, string ClassName);

public:
    unsigned int id = 0;
    string name;
    string className;
};

PIC::PIC()
{
    name = "a";
    className = "abcd";
}

PIC::PIC(unsigned int ID, string Name, string ClassName)
{
    id = ID;
    name = Name;
    className = ClassName;
}

class Task
{
public:
    Task(std::string CreationTime,unsigned int ID, PIC* Pic, string Title, string Content, string Priority, string Deadline);

public:
    std::string creationTime;
    unsigned int id = 0;
    PIC* pic;
    string title;
    string content;
    string priority;
    string deadline;
    string status;
};

Task::Task(std::string CreationTime,unsigned int ID, PIC* Pic, string Title, string Content, string Priority, string Deadline)
{
    creationTime = CreationTime;
    id = ID;
    pic = Pic;
    title = Title;
    content = Content;
    priority = Priority;
    deadline = Deadline;
    status = "未完了";

}

class TaskManager
{
public:
    TaskManager();
    void AdditionTask();
    void AdditionPIC();
    void ChengStatusTask();
    void ChengPICTask();
    void ChengTitleTask();
    void ChengContentTask();
    void ChengPriorityTask();
    void ChengDeadlineTask();
    void ChengNamePIC();
    void ChengClassNamePIC();
    void DeleteTask();
    void DeletePIC();
    void SaveTaskFile();
    void LoadTaskFile();
    void SavePICFile();
    void LoadPICFile();
    void DrawTask();
    void DrawPIC();

    size_t GetTaskSize() { return tasks.size(); };
    size_t GetPICSize() { return people.size(); };

private:
    std::string GetNowTime();

private:

    list<Task> tasks;
    list<PIC> people;

};

TaskManager::TaskManager()
{
}

void TaskManager::AdditionTask()
{
    int selectNum = 0;

    std::string CreationTime;
    unsigned int ID;
    PIC* pic = nullptr;
    string Title;
    string Content;
    string Priority;
    string Deadline;
    
    std::cout << "[新規タスクの追加]" << '\n';
    std::cout << "このタスクを担当する人をidで指定してください" << '\n';
    std::cout << "戻る:999" << '\n';
    while (true)
    {
        std::cin >> ID;
        std::cin.ignore(1024, '\n');

        if (ID == 999)
        {
            return;
        }

        if (ID<1 or people.size()<ID)
        {
            std::cout << "その担当者は存在しません" << '\n';
            continue;
        }

        for (auto itr = people.begin(); itr != people.end(); itr++)
        {

            if (itr->id == ID)
            {
                pic = &*itr;
            }

        }

        

        break;
    }
    std::cout << "このタスクの題名をつけてください" << '\n';
    
    std::cin >> std::setw(256) >>Title;
    std::cin.ignore(1024, '\n');

    std::cout << "このタスクの内容を書いてください" << '\n';

    std::cin >> std::setw(256) >> Content;
    std::cin.ignore(1024, '\n');

    std::cout << "このタスクの優先度を書いてください" << '\n';

    std::cin >> std::setw(256) >> Priority;
    std::cin.ignore(1024, '\n');

    std::cout << "このタスクの期限を決めてください(〇日後など)" << '\n';

    std::cin >> std::setw(256) >> Deadline;
    std::cin.ignore(1024, '\n');

    CreationTime = GetNowTime();

    Task newTask(CreationTime,(unsigned int)tasks.size()+1, pic, Title, Content, Priority, Deadline);

    tasks.emplace_back(newTask);


    std::cout << "タスクの登録が出来ました" << '\n';

}

void TaskManager::AdditionPIC()
{

    string name;
    string className;

    cout << "[新規担当者の追加]" << '\n';
    cout << "この担当者の名前をいれてください" << '\n';

    std::cin >> std::setw(256) >> name;
    std::cin.ignore(1024, '\n');

    cout << "この担当者のクラスをいれてください" << '\n';

    std::cin >> std::setw(256) >> className;
    std::cin.ignore(1024, '\n');

    PIC newPIC((unsigned int)people.size()+1, name, className);

    people.emplace_back(newPIC);

    cout << "担当者の登録が出来ました ID:"<< newPIC.id << '\n';

}

void TaskManager::ChengStatusTask()
{

    unsigned int ID;
    int status;
    std::cout << "変更するタスクのidを指定してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> ID;
        std::cin.ignore(1024, '\n');

        if (ID == 999)
        {
            return;
        }

        if (ID < 1 or tasks.size() < ID)
        {
            std::cout << "そのタスクは存在しません" << '\n';
            continue;
        }

        break;
    }

    std::cout << "ステータスを変更してください(未終了:0 終了:1)" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> status;
        std::cin.ignore(1024, '\n');

        if (status == 999)
        {
            return;
        }

        if (status != 1 and status != 0)
        {
            std::cout << "1か０で指定してください" << '\n';
            continue;
        }

        for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
        {

            if (itr->id == ID)
            {

                if (status == 1)
                {
                    itr->status = "完了";
                }
                else if (status == 0)
                {
                    itr->status = "未完了";
                }
                

            }

        }

        break;

    }

    if (status == 1)
    {
        std::cout << "ステータスを完了に変更しました" << '\n';
    }
    else if (status == 0)
    {
        std::cout << "ステータスを未完了に変更しました" << '\n';
    }


    

}

void TaskManager::ChengPICTask()
{

    unsigned int ID;
    unsigned int picID;
    PIC* pic = new PIC();
    std::cout << "変更するタスクのidを指定してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> ID;
        std::cin.ignore(1024, '\n');

        if (ID == 999)
        {
            return;
        }

        if (ID < 1 or tasks.size() < ID)
        {
            std::cout << "そのタスクは存在しません" << '\n';
            continue;
        }

        break;
    }

    std::cout << "変更する担当者のidを指定してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> picID;
        std::cin.ignore(1024, '\n');

        if (picID == 999)
        {
            return;
        }

        if (picID < 1 or people.size() < picID)
        {
            std::cout << "その担当者は存在しません" << '\n';
            continue;
        }
        

        for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
        {

            if (itr->id == ID)
            {

                for (auto jtr = people.begin(); jtr != people.end(); jtr++)
                {

                    if (jtr->id == picID)
                    {
                        pic = &*jtr;
                    }

                }

                itr->pic = pic;

                std::cout << "担当者を"<< pic->name <<"に変更しました" << '\n';
            }

        }

        delete(pic);
        break;

    }

    

}

void TaskManager::ChengTitleTask()
{

    unsigned int ID;
    std::string title;
    std::cout << "変更するタスクのidを指定してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> ID;
        std::cin.ignore(1024, '\n');

        if (ID == 999)
        {
            return;
        }

        if (ID < 1 or tasks.size() < ID)
        {
            std::cout << "そのタスクは存在しません" << '\n';
            continue;
        }

        break;
    }

    std::cout << "タイトルを変更してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> std::setw(256) >> title;
        std::cin.ignore(1024, '\n');

        if (title == "999")
        {
            return;
        }

        for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
        {

            if (itr->id == ID)
            {

                itr->title = title;


            }

        }

        break;

    }

    std::cout << "タイトルを" << title << "に変更しました" << '\n';

}

void TaskManager::ChengContentTask()
{

    unsigned int ID;
    std::string content;
    std::cout << "変更するタスクのidを指定してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> ID;
        std::cin.ignore(1024, '\n');

        if (ID == 999)
        {
            return;
        }

        if (ID < 1 or tasks.size() < ID)
        {
            std::cout << "そのタスクは存在しません" << '\n';
            continue;
        }

        break;
    }

    std::cout << "内容を変更してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> std::setw(256) >> content;
        std::cin.ignore(1024, '\n');

        if (content == "999")
        {
            return;
        }

        for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
        {

            if (itr->id == ID)
            {

                itr->content = content;


            }

        }

        break;

    }

    std::cout << "内容を" << content << "に変更しました" << '\n';

}

void TaskManager::ChengPriorityTask()
{

    unsigned int ID;
    std::string priority;
    std::cout << "変更するタスクのidを指定してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> ID;
        std::cin.ignore(1024, '\n');

        if (ID == 999)
        {
            return;
        }

        if (ID < 1 or tasks.size() < ID)
        {
            std::cout << "そのタスクは存在しません" << '\n';
            continue;
        }

        break;
    }

    std::cout << "優先度を変更してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> std::setw(256) >> priority;
        std::cin.ignore(1024, '\n');

        if (priority == "999")
        {
            return;
        }

        for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
        {

            if (itr->id == ID)
            {

                itr->priority = priority;


            }

        }

        break;

    }

    std::cout << "優先度を" << priority << "に変更しました" << '\n';

}

void TaskManager::ChengDeadlineTask()
{
    unsigned int ID;
    std::string deadline;
    std::cout << "変更するタスクのidを指定してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> ID;
        std::cin.ignore(1024, '\n');

        if (ID == 999)
        {
            return;
        }

        if (ID < 1 or tasks.size() < ID)
        {
            std::cout << "そのタスクは存在しません" << '\n';
            continue;
        }

        break;
    }

    std::cout << "期限を変更してください(〇日後等)" << '\n';
    std::cout << "戻る:abcd" << '\n';

    while (true)
    {
        std::cin >> std::setw(256) >> deadline;
        std::cin.ignore(1024, '\n');

        if (deadline == "abcd")
        {
            return;
        }

        for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
        {

            if (itr->id == ID)
            {

                itr->deadline = deadline;


            }

        }

        break;

    }

    std::cout << "期限を" << deadline << "に変更しました" << '\n';
}

void TaskManager::ChengNamePIC()
{
    unsigned int ID;
    std::string name;
    std::cout << "変更する担当者のidを指定してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> ID;
        std::cin.ignore(1024, '\n');

        if (ID == 999)
        {
            return;
        }

        if (ID < 1 or people.size() < ID)
        {
            std::cout << "その担当者は存在しません" << '\n';
            continue;
        }

        break;
    }

    std::cout << "名前を変更してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> std::setw(256) >> name;
        std::cin.ignore(1024, '\n');

        if (name == "999")
        {
            return;
        }

        for (auto itr = people.begin(); itr != people.end(); itr++)
        {

            if (itr->id == ID)
            {

                itr->name = name;


            }

        }

        break;

    }

    std::cout << "名前を" << name << "に変更しました" << '\n';
}

void TaskManager::ChengClassNamePIC()
{
    unsigned int ID;
    std::string className;
    std::cout << "変更する担当者のidを指定してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> ID;
        std::cin.ignore(1024, '\n');

        if (ID == 999)
        {
            return;
        }

        if (ID < 1 or people.size() < ID)
        {
            std::cout << "その担当者は存在しません" << '\n';
            continue;
        }

        break;
    }

    std::cout << "クラス名を変更してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> std::setw(256) >> className;
        std::cin.ignore(1024, '\n');

        if (className == "999")
        {
            return;
        }

        for (auto itr = people.begin(); itr != people.end(); itr++)
        {

            if (itr->id == ID)
            {

                itr->className = className;


            }

        }

        break;

    }

    std::cout << "クラス名を" << className << "に変更しました" << '\n';
}

void TaskManager::DeleteTask()
{

    unsigned int ID;
    std::cout << "削除するタスクのidを指定してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> ID;
        std::cin.ignore(1024, '\n');

        if (ID == 999)
        {
            return;
        }

        if (ID < 1 or tasks.size() < ID)
        {
            std::cout << "そのタスクは存在しません" << '\n';
            continue;
        }

        break;
    }

    

    for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
    {

        if (itr->id == ID)
        {

            tasks.erase(itr);

            break;
        }

    }

    unsigned int setID=1;

    for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
    {
        itr->id = setID;
        setID++;
    }

    std::cout << ID << "番のタスクを消去しました" << '\n';

}

void TaskManager::DeletePIC()
{

    unsigned int ID;
    std::cout << "削除する担当者のidを指定してください" << '\n';
    std::cout << "戻る:999" << '\n';

    while (true)
    {
        std::cin >> ID;
        std::cin.ignore(1024, '\n');

        if (ID == 999)
        {
            return;
        }

        if (ID < 1 or people.size() < ID)
        {
            std::cout << "その担当者は存在しません" << '\n';
            continue;
        }

        break;
    }



    for (auto itr = people.begin(); itr != people.end(); itr++)
    {

        if (itr->id == ID)
        {

            people.erase(itr);


        }

    }

    unsigned int setID = 1;

    for (auto itr = people.begin(); itr != people.end(); itr++)
    {
        itr->id = setID;
        setID++;
    }

    std::cout << ID << "番のタスクを消去しました" << '\n';

}

void TaskManager::SaveTaskFile()
{

    std::ofstream ofs("task.csv");

    for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
    {

        ofs << "TCT " << itr->creationTime << std::endl;
        ofs << "TID " << itr->id << std::endl;
        ofs << "TPICID " << itr->pic->id << std::endl;
        ofs << "TTI " << itr->title << std::endl;
        ofs << "TCO " << itr->content << std::endl;
        ofs << "TPR " << itr->priority << std::endl;
        ofs << "TDE " << itr->deadline << std::endl;
        ofs << "TST " << itr->status << std::endl;
        ofs << "TEND " << std::endl;

    }

    std::cout << "タスクの保存をしました" << '\n';

}

void TaskManager::LoadTaskFile()
{

    tasks.clear();

    std::string creationTime;
    unsigned int id = 0;
    unsigned int picId = 0;
    PIC* pic = nullptr;
    string title;
    string content;
    string priority;
    string deadline;
    string status;

    //ファイルストリーム
    std::ifstream file;

    file.open("task.csv");

    //ファイルオープン失敗をチェック
    if (file.fail())
    {
        std::cout << "ファイルが存在しないか読み込めません" << '\n';
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {

       

        //1行分の文字列をストリームに変換して解析しやすくする
        std::istringstream lineStream(line);

        //半角スペース区切りで行の先頭文字列を取得
        std::string key;
        std::getline(lineStream, key, ' ');

        //先頭文字列がTCTなら作成時間
        if (key == "TCT")
        {

            lineStream >> creationTime;

        }

        //先頭文字列がTIDならid
        if (key == "TID")
        {

            lineStream >> id;

        }

        //先頭文字列がTPICIDならPICのid
        if (key == "TPICID")
        {

            lineStream >> picId;
            if (people.size() < picId)
            {
                std::cout << "タスクに割り当てられている担当者が存在しません" << '\n';
                return;
            }
            else
            {
                if (people.size() != 0)
                {
                    for (auto itr = people.begin(); itr != people.end(); itr++)
                    {

                        if (itr->id == picId)
                        {
                            pic = &*itr;
                        }

                    }
                }
                else
                {
                    std::cout << "担当者が存在しません" << '\n';
                    return;
                }
            }

            

        }

        //先頭文字列がTTIならタイトル
        if (key == "TTI")
        {

            lineStream >> title;

        }

        //先頭文字列ががTCOなら内容
        if (key == "TCO")
        {

            lineStream >> content;

        }

        //先頭文字列ががTPRなら優先度
        if (key == "TPR")
        {

            lineStream >> priority;

        }

        //先頭文字列ががTDEなら期限
        if (key == "TDE")
        {

            lineStream >> deadline;

        }

        //先頭文字列がTSTならステータス
        if (key == "TST")
        {

            lineStream >> status;

        }

        //先頭文字列ががTENDなら一つ分のデータ終了
        if (key == "TEND")
        {

            Task newTask(creationTime, id, pic, title, content, priority, deadline);
            newTask.status = status;

            tasks.emplace_back(newTask);
        }

        

    }

    file.close();

   

    std::cout << "タスクの読み込みをしました" << '\n';

}

void TaskManager::SavePICFile()
{

    
    std::ofstream ofs("PIC.csv");


    for (auto itr = people.begin(); itr != people.end(); itr++)
    {

        ofs << "PID " << itr->id << std::endl;
        ofs << "PNA " << itr->name << std::endl;
        ofs << "PCN " << itr->className << std::endl;
        ofs << "PEND " << std::endl;

    }

    std::cout << "担当者の保存をしました" << '\n';

}

void TaskManager::LoadPICFile()
{

    
    people.clear();
    unsigned int id = 0;
    string name;
    string className;

    //ファイルストリーム
    std::ifstream Picfile;

    Picfile.open("PIC.csv");

    //ファイルオープン失敗をチェック
    if (Picfile.fail())
    {
        std::cout << "ファイルが存在しないか読み込めません" << '\n';
        return;
    }

    std::string line;
    while (std::getline(Picfile, line))
    {

        


        //1行分の文字列をストリームに変換して解析しやすくする
        std::istringstream lineStream(line);

        //半角スペース区切りで行の先頭文字列を取得
        std::string key;
        std::getline(lineStream, key, ' ');

        //先頭文字列がPIDならid
        if (key == "PID")
        {

            lineStream >> id;


        }

        //先頭文字列がPNAならname
        if (key == "PNA")
        {

            lineStream >> name;

        }

        //先頭文字列がPCNならclassName
        if (key == "PCN")
        {

            lineStream >> className;

        }

        //先頭文字列がPENDなら一個分のデータ終了
        if (key == "PEND")
        {

            PIC newPIC(id, name, className);

            people.emplace_back(newPIC);


        }
    }

    Picfile.close();

    std::cout << "担当者の読み込みをしました" << '\n';

}

void TaskManager::DrawTask()
{

    for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
    {

        std::cout << "作成時間 :"<< itr->creationTime << '\n';
        std::cout << "id       :"<< itr->id << '\n';
        std::cout << "担当者   :"<< itr->pic->name << '\n';
        std::cout << "タイトル :"<< itr->title << '\n';
        std::cout << "内容     :"<< itr->content << '\n';
        std::cout << "優先度   :"<< itr->priority << '\n';
        std::cout << "期限     :"<< itr->deadline << '\n';
        std::cout << "状態     :"<< itr->status << '\n';

    }

}

void TaskManager::DrawPIC()
{

    for (auto itr = people.begin(); itr != people.end(); itr++)
    {

        std::cout << "id     :" << itr->id << '\n';
        std::cout << "名前   :" << itr->name << '\n';
        std::cout << "クラス :" << itr->className << '\n';

    }

}

std::string TaskManager::GetNowTime()
{
    //現在時間を取ってstringに入れる
    std::time_t t = std::time(nullptr);
    std::tm* now = new tm();

    localtime_s(now,&t);

    char buffer[128];
    strftime(buffer, sizeof(buffer), "%Y-%d-%m %X", now);
    delete(now);
    return buffer;

}

int main()
{
    

    int selectmenu = 0;
    int addSelect = 0;
    int drawSelect = 0;
    int chengSelect = 0;
    int deleteSelect = 0;
    int saveSelect = 0;
    int loadSelect = 0;

    bool isEnd = false;

    TaskManager maneger;

    while (true)
    {

        cout << "[タスク管理]" << '\n';
        cout << "1.追加" << '\n';
        cout << "2.描画" << '\n';
        if (1 != 0)
        {
            cout << "3.編集" << '\n';
            cout << "4.削除" << '\n';
        }
        cout << "5.保存" << '\n';
        cout << "6.読み込み" << '\n';
        cout << "その他:終了" << '\n';
        cout << "\n------------------------------------------" << '\n';
        cout << "操作を選択してください" << '\n';

        std::cin >> selectmenu;
        std::cin.ignore(1024, '\n');

        switch (selectmenu)
        {
        case 1:

            
            cout << "[追加]" << '\n';
            cout << "1.タスク" << '\n';
            cout << "2.担当者" << '\n';

            cout << "その他:戻る" << '\n';
            cout << "\n------------------------------------------" << '\n';
            cout << "操作を選択してください" << '\n';

            std::cin >> addSelect;
            std::cin.ignore(1024, '\n');

            if (addSelect == 1)
            {
                maneger.AdditionTask();
            }
            else if (addSelect == 2)
            {
                maneger.AdditionPIC();
            }
            
            break;

        case 2:
            
            
            cout << "[描画]" << '\n';
            cout << "1.タスク" << '\n';
            cout << "2.担当者" << '\n';

            cout << "その他:戻る" << '\n';
            cout << "\n------------------------------------------" << '\n';
            cout << "操作を選択してください" << '\n';

            std::cin >> drawSelect;
            std::cin.ignore(1024, '\n');

            if (drawSelect == 1)
            {
                maneger.DrawTask();
            }
            else if (drawSelect == 2)
            {
                maneger.DrawPIC();
            }
            
            break;
        case 3:
            if (1 != 0)
            {
                while (true)
                {
                    
                    cout << "[編集]" << '\n';
                    cout << "1.タスク" << '\n';
                    cout << "2.担当者" << '\n';

                    cout << "その他:戻る" << '\n';
                    cout << "\n------------------------------------------" << '\n';
                    cout << "操作を選択してください" << '\n';

                    std::cin >> chengSelect;
                    std::cin.ignore(1024, '\n');   

                    if (chengSelect == 1)
                    {
                        int selectCheng = 0;
                        cout << "[タスク編集]" << '\n';
                        cout << "1.ステータス" << '\n';
                        cout << "2.担当者" << '\n';
                        cout << "3.タイトル" << '\n';
                        cout << "4.内容" << '\n';
                        cout << "5.優先度" << '\n';
                        cout << "6.期限" << '\n';

                        cout << "その他:戻る" << '\n';
                        cout << "\n------------------------------------------" << '\n';
                        cout << "操作を選択してください" << '\n';

                        switch (selectCheng)
                        {
                        case 1:
                            maneger.ChengStatusTask();
                            break;
                        case 2:
                            maneger.ChengPICTask();
                            break;
                        case 3:
                            maneger.ChengTitleTask();
                            break;
                        case 4:
                            maneger.ChengContentTask();
                            break;
                        case 5:
                            maneger.ChengPriorityTask();
                            break;
                        case 6:
                            maneger.ChengDeadlineTask();
                            break;
                        default:
                            break;
                        }

                    }
                    else if (chengSelect == 2)
                    {
                        int selectCheng = 0;
                        cout << "[担当者編集]" << '\n';
                        cout << "1.名前" << '\n';
                        cout << "2.クラス" << '\n';

                        cout << "その他:戻る" << '\n';
                        cout << "\n------------------------------------------" << '\n';
                        cout << "操作を選択してください" << '\n';

                        if (selectCheng == 1)
                        {
                            maneger.ChengNamePIC();
                        }
                        else if (selectCheng == 2)
                        {
                            maneger.ChengClassNamePIC();
                        }
                        
                    }
                    else
                    {
                        break;
                    }
                }

            }
            break;
        case 4:
            if (1 != 0)
            {
                
                cout << "[削除]" << '\n';
                cout << "1.タスク" << '\n';
                cout << "2.担当者" << '\n';

                cout << "その他:戻る" << '\n';
                cout << "\n------------------------------------------" << '\n';
                cout << "操作を選択してください" << '\n';

                std::cin >> deleteSelect;
                std::cin.ignore(1024, '\n');

                if (deleteSelect == 1)
                {

                    maneger.DeleteTask();

                }
                else if (deleteSelect == 2)
                {
                    maneger.DeletePIC();
                }
            }
            break;

        case 5:

            
            cout << "[保存]" << '\n';
            cout << "1.タスク" << '\n';
            cout << "2.担当者" << '\n';

            cout << "その他:戻る" << '\n';
            cout << "\n------------------------------------------" << '\n';
            cout << "操作を選択してください" << '\n';

            std::cin >> saveSelect;
            std::cin.ignore(1024, '\n');

            if (saveSelect == 1)
            {
                maneger.SaveTaskFile();
            }
            else if (saveSelect == 2)
            {
                maneger.SavePICFile();
            }

            break;
        case 6:

            
            cout << "[読み込み]" << '\n';
            if (maneger.GetPICSize() != 0)
            {
                cout << "1.タスク" << '\n';
            }
            cout << "2.担当者" << '\n';

            cout << "その他:戻る" << '\n';
            cout << "\n------------------------------------------" << '\n';
            cout << "操作を選択してください" << '\n';

            std::cin >> loadSelect;
            std::cin.ignore(1024, '\n');

            if (loadSelect == 1)
            {
                if (maneger.GetPICSize() != 0)
                {
                    maneger.LoadTaskFile();
                }
            }
            else if (loadSelect == 2)
            {
                maneger.LoadPICFile();
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