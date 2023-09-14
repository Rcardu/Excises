#include"unltle.h"
using namespace std;
int main(int argc,char*argv[]){
    string str="1,2,4,#,#,5,#,#,3,6,#,#,#";
    BinaryTree tree(str);
    cout<<tree.countNodes()<<endl;
    while(getchar()!='\n')continue;
    getchar();
    return 0;
}