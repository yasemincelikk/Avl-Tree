#include <iostream>
#include "Test.hpp"
using namespace std;
Test::Test()
{
    TestEt();
}
void Test::TestEt()
{
    cout << "Enter tusuna basiniz.";
    if(cin.get()!='\n')
    {
        cout << "Yalnizca enter tusuna basiniz.Programi yeniden calistiriniz.";
        exit(0);
    }
}