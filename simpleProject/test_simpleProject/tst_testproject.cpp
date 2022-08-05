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

    QString myMessage = "= 69";
    QCOMPARE(myMessage.test_input(), QString("= 69"));
}
void testProject::test_output()
{

}
QTEST_MAIN(testProject)
#include "tst_testproject.moc"
