#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <windows.h>
#include <istream>
#include "Key_Value_Convert.h"
#include "SqList_Creat.h"
#include "Callset.h"
int main() {    
    /*չʾ���е����ݼ�*/
    InitList();
    subsList.display_Subs();
    usersList.display_Users();
    char* num_send;
    char* num_receive;
    int ret;
    num_send = new char[12];
    num_receive = new char[12];
    //������̱��
    while (1) {
        Dial(num_send, num_receive);//��ʼ����
        if ((ret = Sy1(num_send, num_receive)) == 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if ((ret = Sy2(num_send, num_receive)) == 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        Sy3(num_send, num_receive);//���ųɹ�
        if ((ret = ClearLine(num_send, num_receive) == 1)) {
            std::cout << "���ڷ��ء���" << std::endl;
            Sleep(1000);
            std::cout << std::endl;
            subsList.display_Subs();
            usersList.display_Users();
            continue;
        }
        if ((ret = ReLift(num_send, num_receive)) == 0) {
            std::cout << "���ڷ��ء���"<<std::endl;
            Sleep(1000);
            std::cout << std::endl;
            subsList.display_Subs();
            usersList.display_Users();
            continue;
        }
        Clear(num_send, num_receive);
        std::cout << "���ڷ��ء���" << std::endl;
        Sleep(1000);
        std::cout << std::endl;
        subsList.display_Subs();
        usersList.display_Users();
        continue;        
    }
    return 0;
}