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
    status = "������";

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
    
    std::cout << "[�V�K�^�X�N�̒ǉ�]" << '\n';
    std::cout << "���̃^�X�N��S������l��id�Ŏw�肵�Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';
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
            std::cout << "���̒S���҂͑��݂��܂���" << '\n';
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
    std::cout << "���̃^�X�N�̑薼�����Ă�������" << '\n';
    
    std::cin >> std::setw(256) >>Title;
    std::cin.ignore(1024, '\n');

    std::cout << "���̃^�X�N�̓��e�������Ă�������" << '\n';

    std::cin >> std::setw(256) >> Content;
    std::cin.ignore(1024, '\n');

    std::cout << "���̃^�X�N�̗D��x�������Ă�������" << '\n';

    std::cin >> std::setw(256) >> Priority;
    std::cin.ignore(1024, '\n');

    std::cout << "���̃^�X�N�̊��������߂Ă�������(�Z����Ȃ�)" << '\n';

    std::cin >> std::setw(256) >> Deadline;
    std::cin.ignore(1024, '\n');

    CreationTime = GetNowTime();

    Task newTask(CreationTime,(unsigned int)tasks.size()+1, pic, Title, Content, Priority, Deadline);

    tasks.emplace_back(newTask);


    std::cout << "�^�X�N�̓o�^���o���܂���" << '\n';

}

void TaskManager::AdditionPIC()
{

    string name;
    string className;

    cout << "[�V�K�S���҂̒ǉ�]" << '\n';
    cout << "���̒S���҂̖��O������Ă�������" << '\n';

    std::cin >> std::setw(256) >> name;
    std::cin.ignore(1024, '\n');

    cout << "���̒S���҂̃N���X������Ă�������" << '\n';

    std::cin >> std::setw(256) >> className;
    std::cin.ignore(1024, '\n');

    PIC newPIC((unsigned int)people.size()+1, name, className);

    people.emplace_back(newPIC);

    cout << "�S���҂̓o�^���o���܂��� ID:"<< newPIC.id << '\n';

}

void TaskManager::ChengStatusTask()
{

    unsigned int ID;
    int status;
    std::cout << "�ύX����^�X�N��id���w�肵�Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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
            std::cout << "���̃^�X�N�͑��݂��܂���" << '\n';
            continue;
        }

        break;
    }

    std::cout << "�X�e�[�^�X��ύX���Ă�������(���I��:0 �I��:1)" << '\n';
    std::cout << "�߂�:999" << '\n';

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
            std::cout << "1���O�Ŏw�肵�Ă�������" << '\n';
            continue;
        }

        for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
        {

            if (itr->id == ID)
            {

                if (status == 1)
                {
                    itr->status = "����";
                }
                else if (status == 0)
                {
                    itr->status = "������";
                }
                

            }

        }

        break;

    }

    if (status == 1)
    {
        std::cout << "�X�e�[�^�X�������ɕύX���܂���" << '\n';
    }
    else if (status == 0)
    {
        std::cout << "�X�e�[�^�X�𖢊����ɕύX���܂���" << '\n';
    }


    

}

void TaskManager::ChengPICTask()
{

    unsigned int ID;
    unsigned int picID;
    PIC* pic = new PIC();
    std::cout << "�ύX����^�X�N��id���w�肵�Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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
            std::cout << "���̃^�X�N�͑��݂��܂���" << '\n';
            continue;
        }

        break;
    }

    std::cout << "�ύX����S���҂�id���w�肵�Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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
            std::cout << "���̒S���҂͑��݂��܂���" << '\n';
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

                std::cout << "�S���҂�"<< pic->name <<"�ɕύX���܂���" << '\n';
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
    std::cout << "�ύX����^�X�N��id���w�肵�Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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
            std::cout << "���̃^�X�N�͑��݂��܂���" << '\n';
            continue;
        }

        break;
    }

    std::cout << "�^�C�g����ύX���Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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

    std::cout << "�^�C�g����" << title << "�ɕύX���܂���" << '\n';

}

void TaskManager::ChengContentTask()
{

    unsigned int ID;
    std::string content;
    std::cout << "�ύX����^�X�N��id���w�肵�Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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
            std::cout << "���̃^�X�N�͑��݂��܂���" << '\n';
            continue;
        }

        break;
    }

    std::cout << "���e��ύX���Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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

    std::cout << "���e��" << content << "�ɕύX���܂���" << '\n';

}

void TaskManager::ChengPriorityTask()
{

    unsigned int ID;
    std::string priority;
    std::cout << "�ύX����^�X�N��id���w�肵�Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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
            std::cout << "���̃^�X�N�͑��݂��܂���" << '\n';
            continue;
        }

        break;
    }

    std::cout << "�D��x��ύX���Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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

    std::cout << "�D��x��" << priority << "�ɕύX���܂���" << '\n';

}

void TaskManager::ChengDeadlineTask()
{
    unsigned int ID;
    std::string deadline;
    std::cout << "�ύX����^�X�N��id���w�肵�Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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
            std::cout << "���̃^�X�N�͑��݂��܂���" << '\n';
            continue;
        }

        break;
    }

    std::cout << "������ύX���Ă�������(�Z���㓙)" << '\n';
    std::cout << "�߂�:abcd" << '\n';

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

    std::cout << "������" << deadline << "�ɕύX���܂���" << '\n';
}

void TaskManager::ChengNamePIC()
{
    unsigned int ID;
    std::string name;
    std::cout << "�ύX����S���҂�id���w�肵�Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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
            std::cout << "���̒S���҂͑��݂��܂���" << '\n';
            continue;
        }

        break;
    }

    std::cout << "���O��ύX���Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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

    std::cout << "���O��" << name << "�ɕύX���܂���" << '\n';
}

void TaskManager::ChengClassNamePIC()
{
    unsigned int ID;
    std::string className;
    std::cout << "�ύX����S���҂�id���w�肵�Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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
            std::cout << "���̒S���҂͑��݂��܂���" << '\n';
            continue;
        }

        break;
    }

    std::cout << "�N���X����ύX���Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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

    std::cout << "�N���X����" << className << "�ɕύX���܂���" << '\n';
}

void TaskManager::DeleteTask()
{

    unsigned int ID;
    std::cout << "�폜����^�X�N��id���w�肵�Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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
            std::cout << "���̃^�X�N�͑��݂��܂���" << '\n';
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

    std::cout << ID << "�Ԃ̃^�X�N���������܂���" << '\n';

}

void TaskManager::DeletePIC()
{

    unsigned int ID;
    std::cout << "�폜����S���҂�id���w�肵�Ă�������" << '\n';
    std::cout << "�߂�:999" << '\n';

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
            std::cout << "���̒S���҂͑��݂��܂���" << '\n';
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

    std::cout << ID << "�Ԃ̃^�X�N���������܂���" << '\n';

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

    std::cout << "�^�X�N�̕ۑ������܂���" << '\n';

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

    //�t�@�C���X�g���[��
    std::ifstream file;

    file.open("task.csv");

    //�t�@�C���I�[�v�����s���`�F�b�N
    if (file.fail())
    {
        std::cout << "�t�@�C�������݂��Ȃ����ǂݍ��߂܂���" << '\n';
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {

       

        //1�s���̕�������X�g���[���ɕϊ����ĉ�͂��₷������
        std::istringstream lineStream(line);

        //���p�X�y�[�X��؂�ōs�̐擪��������擾
        std::string key;
        std::getline(lineStream, key, ' ');

        //�擪������TCT�Ȃ�쐬����
        if (key == "TCT")
        {

            lineStream >> creationTime;

        }

        //�擪������TID�Ȃ�id
        if (key == "TID")
        {

            lineStream >> id;

        }

        //�擪������TPICID�Ȃ�PIC��id
        if (key == "TPICID")
        {

            lineStream >> picId;
            if (people.size() < picId)
            {
                std::cout << "�^�X�N�Ɋ��蓖�Ă��Ă���S���҂����݂��܂���" << '\n';
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
                    std::cout << "�S���҂����݂��܂���" << '\n';
                    return;
                }
            }

            

        }

        //�擪������TTI�Ȃ�^�C�g��
        if (key == "TTI")
        {

            lineStream >> title;

        }

        //�擪�����񂪂�TCO�Ȃ���e
        if (key == "TCO")
        {

            lineStream >> content;

        }

        //�擪�����񂪂�TPR�Ȃ�D��x
        if (key == "TPR")
        {

            lineStream >> priority;

        }

        //�擪�����񂪂�TDE�Ȃ����
        if (key == "TDE")
        {

            lineStream >> deadline;

        }

        //�擪������TST�Ȃ�X�e�[�^�X
        if (key == "TST")
        {

            lineStream >> status;

        }

        //�擪�����񂪂�TEND�Ȃ����̃f�[�^�I��
        if (key == "TEND")
        {

            Task newTask(creationTime, id, pic, title, content, priority, deadline);
            newTask.status = status;

            tasks.emplace_back(newTask);
        }

        

    }

    file.close();

   

    std::cout << "�^�X�N�̓ǂݍ��݂����܂���" << '\n';

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

    std::cout << "�S���҂̕ۑ������܂���" << '\n';

}

void TaskManager::LoadPICFile()
{

    
    people.clear();
    unsigned int id = 0;
    string name;
    string className;

    //�t�@�C���X�g���[��
    std::ifstream Picfile;

    Picfile.open("PIC.csv");

    //�t�@�C���I�[�v�����s���`�F�b�N
    if (Picfile.fail())
    {
        std::cout << "�t�@�C�������݂��Ȃ����ǂݍ��߂܂���" << '\n';
        return;
    }

    std::string line;
    while (std::getline(Picfile, line))
    {

        


        //1�s���̕�������X�g���[���ɕϊ����ĉ�͂��₷������
        std::istringstream lineStream(line);

        //���p�X�y�[�X��؂�ōs�̐擪��������擾
        std::string key;
        std::getline(lineStream, key, ' ');

        //�擪������PID�Ȃ�id
        if (key == "PID")
        {

            lineStream >> id;


        }

        //�擪������PNA�Ȃ�name
        if (key == "PNA")
        {

            lineStream >> name;

        }

        //�擪������PCN�Ȃ�className
        if (key == "PCN")
        {

            lineStream >> className;

        }

        //�擪������PEND�Ȃ����̃f�[�^�I��
        if (key == "PEND")
        {

            PIC newPIC(id, name, className);

            people.emplace_back(newPIC);


        }
    }

    Picfile.close();

    std::cout << "�S���҂̓ǂݍ��݂����܂���" << '\n';

}

void TaskManager::DrawTask()
{

    for (auto itr = tasks.begin(); itr != tasks.end(); itr++)
    {

        std::cout << "�쐬���� :"<< itr->creationTime << '\n';
        std::cout << "id       :"<< itr->id << '\n';
        std::cout << "�S����   :"<< itr->pic->name << '\n';
        std::cout << "�^�C�g�� :"<< itr->title << '\n';
        std::cout << "���e     :"<< itr->content << '\n';
        std::cout << "�D��x   :"<< itr->priority << '\n';
        std::cout << "����     :"<< itr->deadline << '\n';
        std::cout << "���     :"<< itr->status << '\n';

    }

}

void TaskManager::DrawPIC()
{

    for (auto itr = people.begin(); itr != people.end(); itr++)
    {

        std::cout << "id     :" << itr->id << '\n';
        std::cout << "���O   :" << itr->name << '\n';
        std::cout << "�N���X :" << itr->className << '\n';

    }

}

std::string TaskManager::GetNowTime()
{
    //���ݎ��Ԃ������string�ɓ����
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

        cout << "[�^�X�N�Ǘ�]" << '\n';
        cout << "1.�ǉ�" << '\n';
        cout << "2.�`��" << '\n';
        if (1 != 0)
        {
            cout << "3.�ҏW" << '\n';
            cout << "4.�폜" << '\n';
        }
        cout << "5.�ۑ�" << '\n';
        cout << "6.�ǂݍ���" << '\n';
        cout << "���̑�:�I��" << '\n';
        cout << "\n------------------------------------------" << '\n';
        cout << "�����I�����Ă�������" << '\n';

        std::cin >> selectmenu;
        std::cin.ignore(1024, '\n');

        switch (selectmenu)
        {
        case 1:

            
            cout << "[�ǉ�]" << '\n';
            cout << "1.�^�X�N" << '\n';
            cout << "2.�S����" << '\n';

            cout << "���̑�:�߂�" << '\n';
            cout << "\n------------------------------------------" << '\n';
            cout << "�����I�����Ă�������" << '\n';

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
            
            
            cout << "[�`��]" << '\n';
            cout << "1.�^�X�N" << '\n';
            cout << "2.�S����" << '\n';

            cout << "���̑�:�߂�" << '\n';
            cout << "\n------------------------------------------" << '\n';
            cout << "�����I�����Ă�������" << '\n';

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
                    
                    cout << "[�ҏW]" << '\n';
                    cout << "1.�^�X�N" << '\n';
                    cout << "2.�S����" << '\n';

                    cout << "���̑�:�߂�" << '\n';
                    cout << "\n------------------------------------------" << '\n';
                    cout << "�����I�����Ă�������" << '\n';

                    std::cin >> chengSelect;
                    std::cin.ignore(1024, '\n');   

                    if (chengSelect == 1)
                    {
                        int selectCheng = 0;
                        cout << "[�^�X�N�ҏW]" << '\n';
                        cout << "1.�X�e�[�^�X" << '\n';
                        cout << "2.�S����" << '\n';
                        cout << "3.�^�C�g��" << '\n';
                        cout << "4.���e" << '\n';
                        cout << "5.�D��x" << '\n';
                        cout << "6.����" << '\n';

                        cout << "���̑�:�߂�" << '\n';
                        cout << "\n------------------------------------------" << '\n';
                        cout << "�����I�����Ă�������" << '\n';

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
                        cout << "[�S���ҕҏW]" << '\n';
                        cout << "1.���O" << '\n';
                        cout << "2.�N���X" << '\n';

                        cout << "���̑�:�߂�" << '\n';
                        cout << "\n------------------------------------------" << '\n';
                        cout << "�����I�����Ă�������" << '\n';

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
                
                cout << "[�폜]" << '\n';
                cout << "1.�^�X�N" << '\n';
                cout << "2.�S����" << '\n';

                cout << "���̑�:�߂�" << '\n';
                cout << "\n------------------------------------------" << '\n';
                cout << "�����I�����Ă�������" << '\n';

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

            
            cout << "[�ۑ�]" << '\n';
            cout << "1.�^�X�N" << '\n';
            cout << "2.�S����" << '\n';

            cout << "���̑�:�߂�" << '\n';
            cout << "\n------------------------------------------" << '\n';
            cout << "�����I�����Ă�������" << '\n';

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

            
            cout << "[�ǂݍ���]" << '\n';
            if (maneger.GetPICSize() != 0)
            {
                cout << "1.�^�X�N" << '\n';
            }
            cout << "2.�S����" << '\n';

            cout << "���̑�:�߂�" << '\n';
            cout << "\n------------------------------------------" << '\n';
            cout << "�����I�����Ă�������" << '\n';

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
            cout << "�I�����܂�" << '\n';
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