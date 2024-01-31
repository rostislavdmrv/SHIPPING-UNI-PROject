#include <iostream>
#include <windows.h>
#include <string>
#include <cstring> 
#include<fstream>
#include <conio.h>

using namespace std; 
const int MAXSHIPS = 20;

struct Goods
{
    
    char ncontainer[10];
    float  conweight;

};
struct Ship
{
    char nomer[10];
    char name[10];
    float capacity;
    Goods goods[10];
    char date[10];
    float takenCap = 0;
    int countGood = 0;
    double razlika;
};

void switch_function(Ship shiparray[], int& count);
void enter_ship(Ship shiparray[], int& count);
void enter_group_ships(Ship shiparray[],int& count);
void display_ships(Ship shiparray[], int& count);
void sorted_by_max_goods(Ship shiparray[], int& count);
void print_max_goods(Ship shiparray[],int& count);
void print_by_nship(Ship shiparray[], int& count);
void load_ship(Ship shiparray[], int& count);
void distributor(Ship shiparray[], Goods good, int& count);
void canceleted(Ship shiparray[], int& count);
void leave_day(Ship shiparray[], int& count);
void print_leave_day(Ship shiparray[], int& count);
void capacity(Ship shiparray[], int& count);
void print_capacity(Ship shiparray[], int& count);
void content(Ship shiparray[], int& count);
void print_content(Ship shiparray[], int& count);
void difference_capacity_takencapacity(Ship shiparray[], int& count);
void print_difference(Ship shiparray[], int& count);
void save_in_tfile(Ship shiparray[], int& count);
void save_in_bifile(Ship shiparray[], int& count);
void read_in_tfile(Ship shiparray[], int& count);
void read_in_bifile(Ship shiparray[], int& count);

int main()
{ 
	setlocale(LC_ALL, "BG");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
    Ship shiparray[MAXSHIPS];
    int count = 0;
    switch_function(shiparray,count); 
    
    return 0;

}   
void switch_function(Ship shiparray[], int& count)
{ 
    int menu_choice = 0;
    int podmenu_choice = 0;
    int podpodmenu_choice = 0;
    char choice = 'n';
    int index;
    do
    {
        system("cls");
        cout << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "                                  ����                                    " << endl;
        cout << " �������� ����������, ����� ������ �� ��������� �� ������������ � ������ : " << endl;
        cout << endl;

        cout << " (1)��������  �� ���� �����" << endl;
        cout << " (2)�������� �� ������ �� ������ " << endl;
        cout << " (3)��������� �� ������ �������  " << endl;
        cout << " (4)��������� ��  ������� �  ���-����� ������� ���������" << endl;
        cout << " (5)��������� �� ������� �� ��� �� ����� " << endl;
        cout << " (6)����������� �� ����� " << endl;
        cout << " (7)����� �� ������ " << endl;
        cout << " (8)������� �� ������� ������� " << endl;
        cout << " (9)��������� ��� ���� " << endl;
        cout << " (0)����� �� ����������" << endl;
        cout << "--------------------------------------------------------------------------" << endl;

        do
        {
            cout <<endl<< "�������� ���� ����� : ";
            cin >> menu_choice;
        } while (menu_choice < 0 || menu_choice>9);


        cout << endl;
        cout << endl;
        system("cls");
        cout << endl;

        switch (menu_choice) {
        case 1:
            cout << "------------------------" << endl;
            cout << " �������� �� ���� ����� " << endl;
            cout << "------------------------" << endl;
            cout << endl;
            enter_ship(shiparray,count);
            cout << endl;
            cout << endl;
            break;
        case 2:
            cout << "------------------------------" << endl;
            cout << " �������� �� ������ �� ������ " << endl;
            cout << "------------------------------" << endl;
            cout << endl;
            enter_group_ships(shiparray, count);
            cout << endl;
            break;
        case 3:
            cout << "-----------------------------" << endl;
            cout << " ��������� �� ������ ������� " << endl;
            cout << "-----------------------------" << endl;
            cout << endl;
            display_ships(shiparray, count);
            cout << endl;
            break;
        case 4:
            cout << "------------------------------------------------------" << endl;
            cout << " ��������� ��  ������� �  ���-����� ������� ��������� " << endl;
            cout << "------------------------------------------------------" << endl;
            cout << endl;
            sorted_by_max_goods(shiparray, count);
            cout << endl;
            print_max_goods(shiparray, count);
            system("pause");
            break;
        case 5:
            cout << "--------------------------------------" << endl;
            cout << " ��������� �� ������� �� ��� �� ����� " << endl;
            cout << "--------------------------------------" << endl;
            cout << endl;
            print_by_nship(shiparray, count);
            cout << endl;
            system("pause");
            break;
        case 6:
            cout << "----------------------" << endl;
            cout << " ����������� �� ����� " << endl;
            cout << "----------------------" << endl;
            cout << endl;
            load_ship(shiparray, count);
            cout << endl;
            system("pause");
           
            break;
        case 7:
            system("cls");
            cout << "-----------------" << endl;
            cout << " ����� �� ������ " << endl;
            cout << "-----------------" << endl;
            cout << endl;
            canceleted(shiparray, count);
            cout << endl;
            system("pause");
            break;
        case 8:
            cout << "----------------------------" << endl;
            cout << " ������� �� ������� ������� " << endl;
            cout << "----------------------------" << endl;
            cout << endl;

            
            do
            {
                system("cls");
                cout << "-------------------------------------------------------------------------------------------------" << endl;
                cout << "                                  �������                                    " << endl;
                cout << " �������� ����������, ����� ������ �� ��������� �� ������������ � ������ : " << endl;
                cout << endl;
                cout << "(1)��������� �� ������ ������� � �������� ��� �� ��� �� ���������� �� ������ " << endl;
                cout << "(2)��������� �� ������ ������� � �������� ��� �� ������� ��������� �� ������ " << endl;
                cout << "(3)��������� �� �������� ������ � ���-����� ���������� " << endl;
                cout << "(4)��������� �� �������� ������ � ���-������ ������� ����� �������� ��������� � ����������� �����" << endl;
                cout << "(0)������� � ������" << endl;
                cout << "-------------------------------------------------------------------------------------------------" << endl;
                
                do
                {
                    cout << endl << " �������� ���� ����� : ";
                    cin >> podmenu_choice;
                } while (podmenu_choice< 0 || podmenu_choice>4);
                switch (podmenu_choice)
                {
                case 1:leave_day(shiparray, count); print_leave_day( shiparray,count); system("pause"); break;
                case 2:capacity(shiparray, count); print_capacity(shiparray, count); system("pause"); break;
                case 3:content(shiparray, count); print_content(shiparray, count); system("pause"); break;
                case 4:difference_capacity_takencapacity(shiparray, count); print_difference(shiparray, count); system("pause"); break;
                case 0: menu_choice= -1 ; break;
                }
                
            } while (podmenu_choice != 0);
            cout << endl;
            break;
        case 9:
            cout << "--------------------" << endl;
            cout << " ��������� ��� ���� " << endl;
            cout << "--------------------" << endl;
            cout << endl;
            do
            {
                system("cls");
                cout << "-------------------------------------------------------------------------------------------------" << endl;
                cout << "                                  �������                                    " << endl;
                cout << " �������� ����������, ����� ������ �� ��������� �� ������������ � ������ : " << endl;
                cout << endl;
                cout << "(1)��������� � ������� ���� " << endl;
                cout << "(2)������ �� ������� ���� " << endl;
                cout << "(3)��������� � ������� ���� " << endl;
                cout << "(4)������ �� ������� ����" << endl;
                cout << "(0)������� � ������" << endl;
                cout << "-------------------------------------------------------------------------------------------------" << endl;

                do
                {
                    cout << endl << " �������� ���� ����� : ";
                    cin >> podpodmenu_choice;
                } while (podpodmenu_choice < 0 || podpodmenu_choice>4);
                switch (podpodmenu_choice)
                {
                case 1:save_in_tfile(shiparray, count); system("pause"); break;
                case 2:capacity(shiparray, count); print_capacity(shiparray, count); system("pause"); break;
                case 3:save_in_bifile(shiparray, count); system("pause"); break;
                case 4:difference_capacity_takencapacity(shiparray, count); print_difference(shiparray, count); system("pause"); break;
                case 0: menu_choice = -1; break;
                }

            } while (podpodmenu_choice != 0);
            cout << endl;
            break;
            
            break;
        case 0:
            system("cls");
            cout << " ������ �� �� ��������� ���������� [�� - y / �� - n]: ";
            cin >> choice;
            if (choice != 'y' && choice != 'Y')
            {
                menu_choice = -1;
                cout << endl;
                
            }
            if (choice == 'y' || choice == 'Y')
            {
                cout << endl;
                system("cls");
                cout << "---------------------------------------------------------------------" << endl;
                cout << "                           ���������!                                " << endl;
                cout << "---------------------------------------------------------------------" << endl;
                cout << endl;
            }
            break;
            
            
        default:
            cout << endl;
            cout << " ��������� �����! " << endl;
            cout << endl;
            break;
        }
        
    } while (menu_choice != 0);

}


void enter_ship(Ship shiparray[], int& count)
{ 
    cin.ignore();
    cout << endl;
    cout << " �������� ����� �� ����� "<< count + 1 <<" :";
    cin.getline(shiparray[count].name,10);
    cout << " �������� ������ �� ����� " << count + 1 << " :";
    cin.getline(shiparray[count].nomer, 10);
    cout << " �������� �������� ��������� �� �����  "<< count + 1  <<" � ������ [0-10]:";
    cin >> shiparray[count].capacity; 
    if (shiparray[count].capacity <0 || shiparray[count].capacity>10)
    {
        cout << " ��������� ����� ! " << endl << " �������� �������� �������� ���������[0-10]: " << endl;;
        cin >> shiparray[count].capacity;
    }
    cout << " �������� ������ �� ����������  �� ������ " << count + 1 << " [dd.mm.yyyy]:";
    cin >> shiparray[count].date;
    count++; 
    cout << endl;
    cout << " ��������� �� ��� ������� ������ [�� - y / �� - n]:" << endl;
    char ch;
    cin >> ch;
    if (ch == 'n'|| ch=='N')
    {
        return;
    }
    else
    {
        enter_ship(shiparray, count);
    }
   
} 
void enter_group_ships(Ship shiparray[], int& count)
{ 
    int input_option, br;
    cout << endl <<" ����� ������ ������ �� �������� ?" << endl;
    cin >> input_option;
    if (count + input_option > 20) 
    { cout << " ������������ ���� ������ � ��������!";
    cout << " ����,�������� ������!";
        return; 
    }
    br = count;
    for (int i = br; i < input_option + br; i++)
    {
        cin.ignore();
        cout << endl;
        cout << " �������� ����� �� ����� " << count + 1 << " :";
        cin.getline(shiparray[count].name, 10);
        cout << " �������� ������ �� ����� " << count + 1 << " :";
        cin.getline(shiparray[count].nomer, 10);
        cout << " �������� �������� ��������� �� ����� " << count + 1 << " � ������[0-10]:";
        cin >> shiparray[count].capacity;
        if (shiparray[count].capacity < 0 || shiparray[count].capacity>10)
        {
            cout << " ��������� ����� ! " << endl << " �������� �������� �������� ���������[0-10]: " << endl;;
            cin >> shiparray[count].capacity;
        }
        cout << " �������� ������ �� ����������  �� ������ " << count + 1 << " [dd.mm.yyyy]:";
        cin >> shiparray[count].date;
        count++;
    }  
    cout << endl;
    cout << " ��������� �� ��� ������� ������ [�� - y / �� - n]:" << endl;
    char ch;
    cin >> ch;
    if (ch == 'n' || ch == 'N')
    {
        return;
    }
    else
    {
        enter_ship(shiparray, count);
    }
}

void display_ships(Ship shiparray[], int& count)
{
    char ch;
    for (int i = 0; i < count; i++)
    {
        cout << endl;
        cout << "����� " << i + 1 << " : " << endl;
        cout << "����� �� ������ " << i + 1 << ":" << shiparray[i].name << endl;
        cout << "������  �� ������ " << i + 1 << ":" << shiparray[i].nomer << endl;
        cout << "������� ��������� �� ������" << i + 1 << " :" << shiparray[i].capacity << endl;
        cout << "���� �� ���������� " << i + 1 << ":" << shiparray[i].date << endl; 
        for (int j = 0; j < shiparray[i].countGood; j++)
        {
            cout << "����� �� ��������� :" << shiparray[i].goods[j].ncontainer << endl;
            cout << "������� �� �� ��������� �� 1 ���:" << shiparray[i].goods[j].conweight << endl;
        }
        cout << endl << " ������� �� �� ��������� ��� ��������� ����� " << endl;
        cin >> ch;
        if (ch == 'n' || ch == 'N')
        {
            cout << endl << " ������� �� ��� ����� ���� �������!" << endl;
            cout << endl;
            break;
        }  
            system("cls");
        
    } 
    cout << endl <<" ������ ������� �� ��������!" << endl;
    
} 
void sorted_by_max_goods(Ship shiparray[], int& count)
{ 
    bool sorted = true;
    for (int i = 0; i < count; i++)
    {
        if (sorted == false)
            break;
        else sorted = false;
        for (int j = 0; j < count - i - 1; j++)
        {
            if (shiparray[j].capacity < shiparray[j + 1].capacity)
            {
                Ship tmp = shiparray[j];
                shiparray[j] = shiparray[j + 1];
                shiparray[j + 1] = tmp;
                sorted = true;
            }
        }
    }
} 
void print_max_goods(Ship shiparray[], int& count)
{
        
        for (int i = 0; i < count; i++)
        {
            if (shiparray[0].capacity== shiparray[i].capacity)
            {
                cout << endl;
                cout << "�����  : " << endl;
                cout << "����� �� ������ :" << shiparray[i].name << endl;
                cout << "������  �� ������ :" << shiparray[i].nomer << endl;
                cout << "������� ��������� �� ������ :" << shiparray[i].capacity << endl;
                cout << "���� �� ���������� :" << shiparray[i].date << endl;
            }
        }

    
} 
void print_by_nship(Ship shiparray[], int& count)
{  
    cin.ignore();
    char name_ship[10];
    cout << endl<< " �������� ����� �� ������� �� ��� �����:";
    cin.getline(name_ship, 10);
    bool flag = false;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(shiparray[i].name ,name_ship)==0)
        {
            cout << endl;
            cout << "����� �� ������ :" << shiparray[i].name << endl;
            cout << "������  �� ������ :" << shiparray[i].nomer << endl;
            cout << "������� ��������� �� ������ :" << shiparray[i].capacity << endl;
            cout << "���� �� ���������� :" << shiparray[i].date << endl;
            cout << endl;
            flag = true;
        } 
        
        
    }
    if (flag == false)
    {
        cout << " ������ �������� ��� �� ����� !" << endl;
        cout << " ����, �������� ��� !" << endl;
    }

   
}  
void load_ship(Ship shiparray[], int& count)
{  
    char arrayn[10];
    float w;
    string s;
    Goods good;
    do
    { 
    
        cin.ignore();
        cout << endl;
        cout << " �������� ����� �� ��������� :";
        cin.getline(good.ncontainer,10);
        cout << " �������� ������� �� ���������� :";
        cin >> good.conweight;
        if (good.conweight <= 1 && good.conweight >0)
        {
            break; 
        }
        cout << endl;
        cout << " ��������� ����� ! �������� �������� ������� �� ���������� [0-1] !" << endl;
        cout << endl;
       
    } while (true); 

    cout << endl << " ��������� �� ��������� ������ �� �������� :" << endl;
    int br = 0;
    for (int i = 0; i < count; i++)
    { 
       
        if (shiparray[i].takenCap+ good.conweight<=shiparray[i].capacity && shiparray[i].countGood<10)
        { 
            cout << shiparray[i].nomer << endl;
            br++;
        }
        

    } 
    if (br > 0)
    {
        cin.ignore();
        char nomer_ship[10];
        cout <<  endl;
        cout << " ��������  ������ �� ������� �� ��� �����:";
        cin.getline(nomer_ship, 10);
        for (int i = 0; i < count; i++)
        {
            if (strcmp(shiparray[i].nomer, nomer_ship) == 0)
            {
                if (shiparray[i].takenCap + good.conweight <= shiparray[i].capacity && shiparray[i].countGood < 10)
                {
                    shiparray[i].goods[shiparray[i].countGood] = good;//�� ���������� �� ����� shiparray,���������� ��� �������� �� ������ goods , �������� ���� �������� �� ���� �� �������� � ����,���� ���� ������� � ������� �� �������� 
                    shiparray[i].countGood++; // �������������� 
                    shiparray[i].takenCap += good.conweight;
                    cout << endl;
                    cout << " ������� � ���������!" << endl;
                }
                else
                {
                    cout << endl<< " � �������� ����� , ���� �������� ����� !" << endl;
                }
                return;
            }

        }
        cout <<  endl;
        cout << "����� ����� � ������ ��� �� ���� �������!���� ,�������� ������! " << endl;
    }
    else 
    { 
        distributor(shiparray,good,count);
        return;
    }
    
   
         
    
}  
void distributor(Ship shiparray[], Goods good, int& count)
{   
    float weight = good.conweight;
    int br = 0;
    for (int i = 0; i < count; i++)
    { 
        if (shiparray[i].takenCap < shiparray[i].capacity && shiparray[i].countGood < 10)
        { 
            cout << shiparray[i].nomer << endl;
            weight -= shiparray[i].capacity - shiparray[i].takenCap;
            br++;
        }

    } 
    if (br > 0)
    {
        cout <<endl<< " ���� �� �������� , ������ ���� �� �� ���������� ������!" << endl;
        cout <<endl<< " �������� �� ��� � ��������������� [��-y/��-n]" << endl;
        char ch;
        cin >> ch;
        if (ch == 'y'|| ch=='Y')
        {
            for (int i = 0; i < count; i++)
            {
                if (shiparray[i].takenCap < shiparray[i].capacity && shiparray[i].countGood < 10)
                {
                    if (good.conweight > shiparray[i].capacity - shiparray[i].takenCap)
                    {
                        shiparray[i].takenCap = shiparray[i].capacity;
                        shiparray[i].goods[shiparray[i].countGood] = good;
                        shiparray[i].goods[shiparray[i].countGood].conweight = shiparray[i].capacity - shiparray[i].takenCap;//�� ���������� �� ����� shiparray,���������� ��� �������� �� ������ goods , �������� ���� �������� �� ���� �� �������� � ����,���� ���� ������� � ������� �� �������� 
                        shiparray[i].countGood++;
                        good.conweight -= shiparray[i].capacity - shiparray[i].takenCap;
                    }
                    else
                    {
                        shiparray[i].takenCap += good.conweight;
                        shiparray[i].goods[shiparray[i].countGood] = good;
                        shiparray[i].countGood++;
                        break;
                    }

                }

            }
        }
    }
    else
    {
        cout <<endl<< " ���� �� ������ ���� ����������� !" << endl;
    }
}
void canceleted(Ship shiparray[], int& count)
{  
    cout << endl << " ��������� �� ��������� ������ �� �������� :"<<endl;
    for (int i = 0; i < count; i++)
    {
        cout << shiparray[i].nomer<<endl;
        
    }
    cin.ignore();
    char cnomer_ship[10];
    cout <<endl<< " ��������  ������ �� ������� �� ��� �����:";
    cin.getline(cnomer_ship, 10);
    
    for (int i = 0; i < count; i++)
    {
        if (strcmp(shiparray[i].nomer, cnomer_ship) == 0)
        {
           
            bool flag = false;
            for (int r = 0; r < shiparray[i].countGood; r++)
            { 
                flag = false;
                for (int j = 0; j < count; j++)
                { 
                    if (shiparray[j].takenCap + shiparray[i].goods[r].conweight<=shiparray[j].capacity && shiparray[j].countGood +1 <= 10)
                    { 
                        shiparray[j].takenCap += shiparray[i].goods[r].conweight;
                        shiparray[j].goods[shiparray[j].countGood] = shiparray[i].goods[r];
                        shiparray[j].countGood++;
                        flag = true;
                        if (flag == true)
                        {
                            cout << endl << " ������� �������������� !" << endl;
                            return;
                        }
                    }  
                    

                }
                if (flag == false)
                {
                    break;
                }
            } 
            

                cout << endl << " ������� �� �� ��������� ��� ������� ������ [��-y/��-n]" << endl;
                char ch;
                cin >> ch;
                if (ch == 'n' || ch == 'N')
                {
                    break;
                }
                cin.ignore();
                cout << endl;
                cout << " �������� ����� �� ����� " << count + 1 << " :";
                cin.getline(shiparray[count].name, 10);
                cout << " �������� ������ �� ����� " << count + 1 << ":";
                cin.getline(shiparray[count].nomer, 10);
                cout << " �������� ������ �� ����������  �� ����� " << count + 1 << " [dd.mm.yyyy]:";
                cin >> shiparray[count].date;
                shiparray[count].capacity = shiparray[i].capacity;
                shiparray[count].takenCap = shiparray[i].takenCap;
                shiparray[count].countGood = shiparray[i].countGood;
                copy(begin(shiparray[i].goods), end(shiparray[i].goods), begin(shiparray[count].goods));
                count++;
           


            
        }

    }
    


} 
void leave_day(Ship shiparray[], int& count)
{
    bool sorted = true;
    for (int i = 0; i < count; i++)
    {
        if (sorted == false)
            break;
        else
            sorted = false;
        for (int j = 0; j < count - i - 1; j++)
        {
            if (shiparray[j].date > shiparray[j + 1].date)
            
            {
                Ship tmp = shiparray[j];
                shiparray[j] = shiparray[j + 1];
                shiparray[j + 1] = tmp;
                sorted = true;
            }
        }
    }
}
void print_leave_day(Ship shiparray[], int& count)
{ 
    for (int i = 0; i < count; i++)
    {
        cout << endl;
        cout << "����� " << i + 1 << " : " << endl;
        cout << "����� �� ������ " << i + 1 << ":" << shiparray[i].name << endl;
        cout << "������  �� ������ " << i + 1 << ":" << shiparray[i].nomer << endl;
        cout << "������� ��������� �� ������" << i + 1 << " :" << shiparray[i].capacity << endl;
        cout << "���� �� ���������� " << i + 1 << ":" << shiparray[i].date << endl;

    }
}
void capacity(Ship shiparray[], int& count)
{ 
    bool sorted = true;
    for (int i = 0; i < count; i++)
    {
        if (sorted == false)
            break;
        else sorted = false;
        for (int j = 0; j < count - i - 1; j++)
        {
            if (shiparray[j].capacity < shiparray[j + 1].capacity)
            {
                Ship tmp = shiparray[j];
                shiparray[j] = shiparray[j + 1];
                shiparray[j + 1] = tmp;
                sorted = true;
            }
        }
    }

}
void print_capacity(Ship shiparray[], int& count)
{ 
    for (int i = 0; i < count; i++)
    {
        cout << endl;
        cout << "����� " << i + 1 << " : " << endl;
        cout << "����� �� ����� " << i + 1 << ":" << shiparray[i].name << endl;
        cout << "������  �� ����� " << i + 1 << ":" << shiparray[i].nomer << endl;
        cout << "������� ��������� �� ����� " << i + 1 << " :" << shiparray[i].capacity << endl;
        cout << "���� �� ���������� " << i + 1 << ":" << shiparray[i].date << endl;

    }
}
void content(Ship shiparray[], int& count)
{ 
    bool sorted = true;
    for (int i = 0; i < count; i++)
    {
        if (sorted == false)
            break;
        else sorted = false;
        for (int j = 0; j < count - i - 1; j++)
        {
            if (shiparray[j].takenCap > shiparray[j + 1].takenCap)
            {
                Ship tmp = shiparray[j];
                shiparray[j] = shiparray[j + 1];
                shiparray[j + 1] = tmp;
                sorted = true;
            }
        }
    }
}
void print_content(Ship shiparray[], int& count)
{ 
    for (int i = 0; i < count; i++)
    {
        if (shiparray[0].takenCap == shiparray[i].takenCap)
        {
            cout << endl;
            cout << "�����  : " << endl;
            cout << "����� �� ����� :" << shiparray[i].name << endl;
            cout << "������  �� ����� :" << shiparray[i].nomer << endl;
            cout << "������� ��������� �� ����� :" << shiparray[i].capacity << endl;
            cout << "���� �� ���������� :" << shiparray[i].date << endl;
        }
    }


}
void difference_capacity_takencapacity(Ship shiparray[], int& count)
{
    for (int i = 0; i < count; i++)
    {
        shiparray[i].razlika = shiparray[i].capacity-shiparray[i].takenCap;
    }
    bool sorted = true;
    for (int i = 0; i < count; i++)
    {
        if (sorted == false)
            break;
        else sorted = false;
        for (int j = 0; j < count - i - 1; j++)
        {
            if (shiparray[j].razlika < shiparray[j + 1].razlika)
            {
                Ship tmp = shiparray[j];
                shiparray[j] = shiparray[j + 1];
                shiparray[j + 1] = tmp;
                sorted = true;
            }
        }
    }
}
void print_difference(Ship shiparray[], int& count)
{  
    
    for (int i = 0; i < count; i++)
    {
        if (shiparray[0].razlika == shiparray[i].razlika)
        {
            cout << endl;
            cout << "�����  : " << endl;
            cout << "����� �� ����� :" << shiparray[i].name << endl;
            cout << "������  �� ����� :" << shiparray[i].nomer << endl;
            cout << "������� ��������� �� ����� :" << shiparray[i].capacity << endl;
            cout << "���� �� ���������� :" << shiparray[i].date << endl;
        }
    }
} 
void save_in_tfile(Ship shiparray[], int& count)
{ 
    fstream ShipsFile;
    ShipsFile.open("Ships.txt",  ios::out);
    if (ShipsFile.is_open())
    {
        for (int i = 0; i <count ; i++)
        { 
            ShipsFile << shiparray[i].name << endl;
            ShipsFile << shiparray[i].nomer << endl;
            ShipsFile << shiparray[i].capacity << endl;
            ShipsFile << shiparray[i].date << endl; 
            for (int j = 0; j < shiparray[i].countGood; j++)
            {
                ShipsFile << shiparray[i].goods[j].ncontainer << endl;
                ShipsFile << shiparray[i].goods[j].conweight << endl;
            }
            
            
            
        } 
        cout << endl << " ������������ e �������  �������� � ��������� ����!" << endl;
        ShipsFile.close();
    } 
    else
    {
        cout << endl << " ��� ������ ��� ���������� �� �����!" << endl;
        exit(1);
    }
} 
void save_in_bifile(Ship shiparray[], int& count)
{ 
    fstream ShipsFile;
    ShipsFile.open("Ship.txt", ios::binary | ios::out);
    if (ShipsFile.is_open())
    {
        ShipsFile.write((char*)shiparray,count *(sizeof(Ship)));
        cout << endl << " ������������ e �������  �������� � �������� ����!" << endl;
        ShipsFile.close();
    }
    else
    {
        cout << endl<< " ��� ������ ��� ���������� �� �����!" << endl;
        exit(1);
    }
} 
void read_in_tfile(Ship shiparray[], int& count)
{
    fstream ShipsFile;
    ShipsFile.open("Ships.txt", ios::in);
    if (ShipsFile.is_open())
    {
        for (int i = 0; i < count; i++)
        {
            ShipsFile >> shiparray[i].name;
            ShipsFile >> shiparray[i].nomer;
            ShipsFile >> shiparray[i].capacity;
            ShipsFile >> shiparray[i].date;
            for (int j = 0; j < shiparray[i].countGood; j++)
            {
                ShipsFile >> shiparray[i].goods[j].ncontainer;
                ShipsFile >> shiparray[i].goods[j].conweight;
            }
            ShipsFile.ignore();


        }
        cout << endl << " ������������ e �������  �������� � ��������� ����!" << endl;
        ShipsFile.close();
    }
    else
    {
        cout << endl << " ��� ������ ��� ���������� �� �����!" << endl;
        exit(1);
    }
}
void read_in_bifile(Ship shiparray[], int& count)
{ 
    fstream ShipsFile;
    ShipsFile.open("Ship.txt", ios::binary | ios::in);
    if (ShipsFile.is_open())
    {
        ShipsFile.seekg(0L,ios::end);
        long pos = (long)ShipsFile.tellg();
        ShipsFile.close();
        int n = pos / (sizeof(Ship));
        ShipsFile.open("Ship.txt", ios::binary | ios::in);
        ShipsFile.read((char*)shiparray,n *(sizeof(Ship)));
        cout << endl << " ������������ e �������  �������� � �������� ����!" << endl;
        ShipsFile.close();
    }
    else
    {
        cout << endl << " ��� ������ ��� ���������� �� �����!" << endl;
        exit(1);
    }
}

