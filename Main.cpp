#include"unltle.h"
using namespace std;
int main(int argc,char*argv[]){
    Cleanup obj;
    for(int val:obj.RandVector(10,0,10)){
        cout<<val<<"  ";
    }
    cout<<endl;

    while(getchar()!='\n')continue;
    getchar();
    return 0;
}