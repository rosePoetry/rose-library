#include <QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    QCoreApplication a(argc, argv);
    int A;
    int B;
    int C;

    string myMessage = "= 69"; // testQString for myMessage

    A = 1;       // QVERIFY A
    B = 68;      // QVERIFY B
    C = A + B;
    cout << C << myMessage;
    // QVERIFY C = 69 / test if message appears
    return a.exec();
}

