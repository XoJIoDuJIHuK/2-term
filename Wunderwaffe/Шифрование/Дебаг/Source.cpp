#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string line;

    std::ifstream in("D:\\hello.txt"); // �������� ���� ��� ������
    if (in.is_open())
    {
        while (getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();     // ��������� ����
    std::cout << line << std::endl;
    std::cout << "End of program" << std::endl;
    return 0;
}