#include <iostream>
#include <string>
#include <windows.h>
#define MAX 1000
using namespace std;
void showMenu() {
    cout << "**************************" << endl;
    cout << "*****  1.添加联系人  *****" << endl;
    cout << "*****  2.显示联系人  *****" << endl;
    cout << "*****  3.删除联系人  *****" << endl;
    cout << "*****  4.查找联系人  *****" << endl;
    cout << "*****  5.修改联系人  *****" << endl;
    cout << "*****  6.清空联系人  *****" << endl;
    cout << "*****  0.退出通讯录  *****" << endl;
    cout << "**************************" << endl;
}
struct people {
    string Name;
    int Sex;
    int Age;
    string Phone;
    string Address;
};
struct txl {
    struct people array[MAX];
    int Size;
};
void addPerson(txl *count) {
    if(count->Size == MAX) {
        cout << "通讯录人数已满" << endl;
        return;
    }
    else {
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        count->array[count->Size].Name = name;
        int sex = 0;
        cout << "请输入性别" << endl;
        cout << "1---男" << endl;
        cout << "2---女" << endl;
        while(true) {
            cin >> sex;
            if(sex == 1 || sex == 2) {
                count->array[count->Size].Sex = sex;
                break;
            }
            else {
                cout << "输入有误，请重新输入" << endl;
                continue;
            }
        }
        int age;
        cout << "请输入年龄" << endl;
        cin >> age;
        count->array[count->Size].Age = age;
        string phone;
        cout << "请输入号码" << endl;
        cin >> phone;
        count->array[count->Size].Phone = phone;
        string address;
        cout << "请输入住址" << endl;
        cin >> address;
        count->array[count->Size].Address = address;
        count->Size++;
        system("pause");
        system("cls");
    }
}
void showPeople(txl *count) {
    if(count->Size == 0) {
        cout << "空" << endl;
    }
    else {
        for(int a = 0;a < count->Size;a++) {
            cout << a + 1 << count->array[a].Name << endl;
            cout << "  " << count->array[a].Sex << endl;
            cout << "  " << count->array[a].Age << endl;
            cout << "  " << count->array[a].Phone << endl;
            cout << "  " << count->array[a].Address << endl;
        }
    }
    system("pause");
    system("cls");
}
int main() {
    txl count;
    count.Size = 0;
    int number;
    while(true) {
        showMenu();
        cout << "请输入数字" << endl;
        cin >> number;
        switch(number) {
        case 1:
            addPerson(&count);
            break;
        case 2:
            showPeople(&count);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "请输入正确数字" << endl;
            break;
        }
    }
    return 0;
}