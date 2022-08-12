#include <QtTest>
using namespace std;
// add necessary includes here

class testProject : public QObject
{
    Q_OBJECT

public:
    testProject();
    ~testProject();

private slots:
    void test_input();
    void test_output();
};
testProject::testProject()
{
   QString myMessage;
   QString A;
   QString B;
   QString C;
   C = A + B;

}

testProject::~testProject()
{

}
void testProject::test_input()
{
   // QVERIFY A, B, QCOMPARE C = 69
   // values of A, B, C should be verified also C should be implemented in some way -> C = A + B
    QString myMessage = "= 69"; 
    QCOMPARE(myMessage.test_input(), QString("= 69")); // ".test_input" must be function i which compares expected value of str "= 69" with given message in the output of the program
}
void testProject::test_output()
{

}
QTEST_MAIN(testProject)
#include "tst_testproject.moc"