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
        cout << "                                  МЕНЮ                                    " << endl;
        cout << " Посочете операцията, която искате да извършите от предложените в менюто : " << endl;
        cout << endl;

        cout << " (1)Добавяне  по един кораб" << endl;
        cout << " (2)Добавяне на списък от кораби " << endl;
        cout << " (3)Извеждане на всички превози  " << endl;
        cout << " (4)Извеждане на  превози с  най-голям товарен капацитет" << endl;
        cout << " (5)Извеждане на превози по име на кораб " << endl;
        cout << " (6)Натоварване на кораб " << endl;
        cout << " (7)Отказ от превоз " << endl;
        cout << " (8)Справки за корабни превози " << endl;
        cout << " (9)Записване във файл " << endl;
        cout << " (0)Изход от програмата" << endl;
        cout << "--------------------------------------------------------------------------" << endl;

        do
        {
            cout <<endl<< "Въведете своя избор : ";
            cin >> menu_choice;
        } while (menu_choice < 0 || menu_choice>9);


        cout << endl;
        cout << endl;
        system("cls");
        cout << endl;

        switch (menu_choice) {
        case 1:
            cout << "------------------------" << endl;
            cout << " Добавяне по един кораб " << endl;
            cout << "------------------------" << endl;
            cout << endl;
            enter_ship(shiparray,count);
            cout << endl;
            cout << endl;
            break;
        case 2:
            cout << "------------------------------" << endl;
            cout << " Добавяне на списък от кораби " << endl;
            cout << "------------------------------" << endl;
            cout << endl;
            enter_group_ships(shiparray, count);
            cout << endl;
            break;
        case 3:
            cout << "-----------------------------" << endl;
            cout << " Извеждане на всички превози " << endl;
            cout << "-----------------------------" << endl;
            cout << endl;
            display_ships(shiparray, count);
            cout << endl;
            break;
        case 4:
            cout << "------------------------------------------------------" << endl;
            cout << " Извеждане на  превози с  най-голям товарен капацитет " << endl;
            cout << "------------------------------------------------------" << endl;
            cout << endl;
            sorted_by_max_goods(shiparray, count);
            cout << endl;
            print_max_goods(shiparray, count);
            system("pause");
            break;
        case 5:
            cout << "--------------------------------------" << endl;
            cout << " Извеждане на превози по име на кораб " << endl;
            cout << "--------------------------------------" << endl;
            cout << endl;
            print_by_nship(shiparray, count);
            cout << endl;
            system("pause");
            break;
        case 6:
            cout << "----------------------" << endl;
            cout << " Натоварване на кораб " << endl;
            cout << "----------------------" << endl;
            cout << endl;
            load_ship(shiparray, count);
            cout << endl;
            system("pause");
           
            break;
        case 7:
            system("cls");
            cout << "-----------------" << endl;
            cout << " Отказ от превоз " << endl;
            cout << "-----------------" << endl;
            cout << endl;
            canceleted(shiparray, count);
            cout << endl;
            system("pause");
            break;
        case 8:
            cout << "----------------------------" << endl;
            cout << " Справки за корабни превози " << endl;
            cout << "----------------------------" << endl;
            cout << endl;

            
            do
            {
                system("cls");
                cout << "-------------------------------------------------------------------------------------------------" << endl;
                cout << "                                  ПОДМЕНЮ                                    " << endl;
                cout << " Посочете операцията, която искате да извършите от предложените в менюто : " << endl;
                cout << endl;
                cout << "(1)Извеждане на всички превози в подреден ред по ден за заминаване на кораба " << endl;
                cout << "(2)Извеждане на всички превози в подреден ред по товарен капацитет на кораба " << endl;
                cout << "(3)Извеждане на корабния превоз с най-малка вместимост " << endl;
                cout << "(4)Извеждане на товарния превоз с най-голяма разлика между товарния капацитет и натоварения товар" << endl;
                cout << "(0)Връщане в менюто" << endl;
                cout << "-------------------------------------------------------------------------------------------------" << endl;
                
                do
                {
                    cout << endl << " Въведете своя избор : ";
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
            cout << " Записване във файл " << endl;
            cout << "--------------------" << endl;
            cout << endl;
            do
            {
                system("cls");
                cout << "-------------------------------------------------------------------------------------------------" << endl;
                cout << "                                  ПОДМЕНЮ                                    " << endl;
                cout << " Посочете операцията, която искате да извършите от предложените в менюто : " << endl;
                cout << endl;
                cout << "(1)Записване в текстов файл " << endl;
                cout << "(2)Четене от текстов файл " << endl;
                cout << "(3)Записване в двоичен файл " << endl;
                cout << "(4)Четене от двоичен файл" << endl;
                cout << "(0)Връщане в менюто" << endl;
                cout << "-------------------------------------------------------------------------------------------------" << endl;

                do
                {
                    cout << endl << " Въведете своя избор : ";
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
            cout << " Искате ли да напуснете програмата [ДА - y / Не - n]: ";
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
                cout << "                           Довиждане!                                " << endl;
                cout << "---------------------------------------------------------------------" << endl;
                cout << endl;
            }
            break;
            
            
        default:
            cout << endl;
            cout << " Невалиден избор! " << endl;
            cout << endl;
            break;
        }
        
    } while (menu_choice != 0);

}


void enter_ship(Ship shiparray[], int& count)
{ 
    cin.ignore();
    cout << endl;
    cout << " Въведете името на кораб "<< count + 1 <<" :";
    cin.getline(shiparray[count].name,10);
    cout << " Въведете номера на кораб " << count + 1 << " :";
    cin.getline(shiparray[count].nomer, 10);
    cout << " Въведете товарния капацитет на кораб  "<< count + 1  <<" в тонове [0-10]:";
    cin >> shiparray[count].capacity; 
    if (shiparray[count].capacity <0 || shiparray[count].capacity>10)
    {
        cout << " Невалиден товар ! " << endl << " Въведете правилно товарния капацитет[0-10]: " << endl;;
        cin >> shiparray[count].capacity;
    }
    cout << " Въведете датата на заминаване  на кораба " << count + 1 << " [dd.mm.yyyy]:";
    cin >> shiparray[count].date;
    count++; 
    cout << endl;
    cout << " Създаване на нов корабен превоз [ДА - y / Не - n]:" << endl;
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
    cout << endl <<" Колко кораби искате да добавите ?" << endl;
    cin >> input_option;
    if (count + input_option > 20) 
    { cout << " Максималният брой кораби е надвишен!";
    cout << " Моля,опитайте отново!";
        return; 
    }
    br = count;
    for (int i = br; i < input_option + br; i++)
    {
        cin.ignore();
        cout << endl;
        cout << " Въведете името на кораб " << count + 1 << " :";
        cin.getline(shiparray[count].name, 10);
        cout << " Въведете номера на кораб " << count + 1 << " :";
        cin.getline(shiparray[count].nomer, 10);
        cout << " Въведете товарния капацитет на кораб " << count + 1 << " в тонове[0-10]:";
        cin >> shiparray[count].capacity;
        if (shiparray[count].capacity < 0 || shiparray[count].capacity>10)
        {
            cout << " Невалиден товар ! " << endl << " Въведете правилно товарния капацитет[0-10]: " << endl;;
            cin >> shiparray[count].capacity;
        }
        cout << " Въведете датата на заминаване  на кораба " << count + 1 << " [dd.mm.yyyy]:";
        cin >> shiparray[count].date;
        count++;
    }  
    cout << endl;
    cout << " Създаване на нов корабен превоз [ДА - y / Не - n]:" << endl;
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
        cout << "Кораб " << i + 1 << " : " << endl;
        cout << "Името на кораба " << i + 1 << ":" << shiparray[i].name << endl;
        cout << "Номера  на кораба " << i + 1 << ":" << shiparray[i].nomer << endl;
        cout << "Товарен капацитет на кораба" << i + 1 << " :" << shiparray[i].capacity << endl;
        cout << "Дата на заминаване " << i + 1 << ":" << shiparray[i].date << endl; 
        for (int j = 0; j < shiparray[i].countGood; j++)
        {
            cout << "Номер на контейнер :" << shiparray[i].goods[j].ncontainer << endl;
            cout << "Теглото на на контейнер до 1 тон:" << shiparray[i].goods[j].conweight << endl;
        }
        cout << endl << " Желаете ли да преминете към следващия кораб " << endl;
        cin >> ch;
        if (ch == 'n' || ch == 'N')
        {
            cout << endl << " Желания от Вас кораб беше изведен!" << endl;
            cout << endl;
            break;
        }  
            system("cls");
        
    } 
    cout << endl <<" Всички превози са изведени!" << endl;
    
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
                cout << "Кораб  : " << endl;
                cout << "Името на кораба :" << shiparray[i].name << endl;
                cout << "Номера  на кораба :" << shiparray[i].nomer << endl;
                cout << "Товарен капацитет на кораба :" << shiparray[i].capacity << endl;
                cout << "Дата на заминаване :" << shiparray[i].date << endl;
            }
        }

    
} 
void print_by_nship(Ship shiparray[], int& count)
{  
    cin.ignore();
    char name_ship[10];
    cout << endl<< " Въведете името на желания от Вас кораб:";
    cin.getline(name_ship, 10);
    bool flag = false;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(shiparray[i].name ,name_ship)==0)
        {
            cout << endl;
            cout << "Името на кораба :" << shiparray[i].name << endl;
            cout << "Номера  на кораба :" << shiparray[i].nomer << endl;
            cout << "Товарен капацитет на кораба :" << shiparray[i].capacity << endl;
            cout << "Дата на заминаване :" << shiparray[i].date << endl;
            cout << endl;
            flag = true;
        } 
        
        
    }
    if (flag == false)
    {
        cout << " Грешно въведено име на кораб !" << endl;
        cout << " Моля, опитайте пак !" << endl;
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
        cout << " Въведете номер на контейнер :";
        cin.getline(good.ncontainer,10);
        cout << " Въведете теглото на контейнера :";
        cin >> good.conweight;
        if (good.conweight <= 1 && good.conweight >0)
        {
            break; 
        }
        cout << endl;
        cout << " Невалидно тегло ! Въведете правилно теглото на контейнера [0-1] !" << endl;
        cout << endl;
       
    } while (true); 

    cout << endl << " Извеждане на наличните номера на корабите :" << endl;
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
        cout << " Въведете  номера на желания от Вас кораб:";
        cin.getline(nomer_ship, 10);
        for (int i = 0; i < count; i++)
        {
            if (strcmp(shiparray[i].nomer, nomer_ship) == 0)
            {
                if (shiparray[i].takenCap + good.conweight <= shiparray[i].capacity && shiparray[i].countGood < 10)
                {
                    shiparray[i].goods[shiparray[i].countGood] = good;//на създадения ми масив shiparray,сопетатора дот достигам до масива goods , създавам нова стойност на една от клетките в него,като знам позиция и достъпя до елемента 
                    shiparray[i].countGood++; // инкрементиране 
                    shiparray[i].takenCap += good.conweight;
                    cout << endl;
                    cout << " Корабът е натоварен!" << endl;
                }
                else
                {
                    cout << endl<< " В избрания кораб , няма свободни места !" << endl;
                }
                return;
            }

        }
        cout <<  endl;
        cout << "Такъв кораб с такова име не беше намерен!Моля ,опитайте отново! " << endl;
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
        cout <<endl<< " Това са карабите , където може да се разпредели товара!" << endl;
        cout <<endl<< " Съгласни ли сте с разпределението [Да-y/Не-n]" << endl;
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
                        shiparray[i].goods[shiparray[i].countGood].conweight = shiparray[i].capacity - shiparray[i].takenCap;//на създадения ми масив shiparray,сопетатора дот достигам до масива goods , създавам нова стойност на една от клетките в него,като знам позиция и достъпя до елемента 
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
        cout <<endl<< " Няма да можеда бъде разпределен !" << endl;
    }
}
void canceleted(Ship shiparray[], int& count)
{  
    cout << endl << " Извеждане на наличните номера на корабите :"<<endl;
    for (int i = 0; i < count; i++)
    {
        cout << shiparray[i].nomer<<endl;
        
    }
    cin.ignore();
    char cnomer_ship[10];
    cout <<endl<< " Въведете  номера на желания от Вас кораб:";
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
                            cout << endl << " Успешно пренатоварване !" << endl;
                            return;
                        }
                    }  
                    

                }
                if (flag == false)
                {
                    break;
                }
            } 
            

                cout << endl << " Желаете ли да създадете нов корабен превоз [Да-y/Не-n]" << endl;
                char ch;
                cin >> ch;
                if (ch == 'n' || ch == 'N')
                {
                    break;
                }
                cin.ignore();
                cout << endl;
                cout << " Въведете името на кораб " << count + 1 << " :";
                cin.getline(shiparray[count].name, 10);
                cout << " Въведете номера на кораб " << count + 1 << ":";
                cin.getline(shiparray[count].nomer, 10);
                cout << " Въведете датата на заминаване  на кораб " << count + 1 << " [dd.mm.yyyy]:";
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
        cout << "Кораб " << i + 1 << " : " << endl;
        cout << "Името на кораба " << i + 1 << ":" << shiparray[i].name << endl;
        cout << "Номера  на кораба " << i + 1 << ":" << shiparray[i].nomer << endl;
        cout << "Товарен капацитет на кораба" << i + 1 << " :" << shiparray[i].capacity << endl;
        cout << "Дата на заминаване " << i + 1 << ":" << shiparray[i].date << endl;

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
        cout << "Кораб " << i + 1 << " : " << endl;
        cout << "Името на кораб " << i + 1 << ":" << shiparray[i].name << endl;
        cout << "Номера  на кораб " << i + 1 << ":" << shiparray[i].nomer << endl;
        cout << "Товарен капацитет на кораб " << i + 1 << " :" << shiparray[i].capacity << endl;
        cout << "Дата на заминаване " << i + 1 << ":" << shiparray[i].date << endl;

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
            cout << "Кораб  : " << endl;
            cout << "Името на кораб :" << shiparray[i].name << endl;
            cout << "Номера  на кораб :" << shiparray[i].nomer << endl;
            cout << "Товарен капацитет на кораб :" << shiparray[i].capacity << endl;
            cout << "Дата на заминаване :" << shiparray[i].date << endl;
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
            cout << "Кораб  : " << endl;
            cout << "Името на кораб :" << shiparray[i].name << endl;
            cout << "Номера  на кораб :" << shiparray[i].nomer << endl;
            cout << "Товарен капацитет на кораб :" << shiparray[i].capacity << endl;
            cout << "Дата на заминаване :" << shiparray[i].date << endl;
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
        cout << endl << " Информацията e успешно  записана в текстовия файл!" << endl;
        ShipsFile.close();
    } 
    else
    {
        cout << endl << " Има грешка при отварянето на файла!" << endl;
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
        cout << endl << " Информацията e успешно  записана в двоичния файл!" << endl;
        ShipsFile.close();
    }
    else
    {
        cout << endl<< " Има грешка при отварянето на файла!" << endl;
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
        cout << endl << " Информацията e успешно  записана в текстовия файл!" << endl;
        ShipsFile.close();
    }
    else
    {
        cout << endl << " Има грешка при отварянето на файла!" << endl;
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
        cout << endl << " Информацията e успешно  записана в двоичния файл!" << endl;
        ShipsFile.close();
    }
    else
    {
        cout << endl << " Има грешка при отварянето на файла!" << endl;
        exit(1);
    }
}

