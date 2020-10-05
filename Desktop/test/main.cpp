#include <iostream>
#include<stdio.h>
#include <iostream>
#include <iomanip>
#include <ctype.h>


const int M = 100;

class string{
    int n;
    char b[M];
public:
    int digitals,letters;
    string(){
        digitals=letters=n=0;
    }  //构造函数 1⃣️与类名相同2⃣️权限必须是public3⃣️没有返回值4⃣️在对象开始起作用时自动调用函数
    //⚠️构造函数前不能➕void int等返回类型，因为构造函数没有返回值

    ~string();//⚠️析构函数前不能➕void int等返回类型，因为析构函数没有返回值
    void getstring();
    void sortchar();
    void display();
};

void string::getstring() {
    char ch;
    std::cout<<"请输入字符串，按enter键结束"<<std::endl;
    for (;;){
        ch = getchar();
        if (ch=='\n')break;
        b[n++]=ch;
    }
}
void string::sortchar() {
    int i;
    for (i=0;i<n;i++){
        if (isdigit(b[i]))
           digitals= digitals+1;
        else if (isalpha(b[i]))
            letters++;
    }
}
void string::display() {
    int i;
    for (i=0;i<n;i++){
        std::cout<<b[i];
    }
    std::cout<<std::endl;
    std::cout<<"读入的字符总数"<<n<<std::endl;
    std::cout<<"其中数字数为"<<digitals<<std::endl;
    std::cout<<"字母数为"<<letters<<std::endl;

}
string::~string() {   //定义析构函数的操作！！
    printf("对象被撤销");
}

int main() {
    string str;
   // str.initial();   //及其重要！！
   //有了构造函数就不需要再str.initial()了！！
    str.getstring();
    str.sortchar();
    str.display();


}
