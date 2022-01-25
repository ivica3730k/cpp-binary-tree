#include "iostream"
#include "tree.h"
int main(){
    Tree dict = Tree();
    dict.insert(31, "Anne");
    dict.insert(7, "John");
    dict.remove(31);
    std::cout<<dict.lookup(7)<<std::endl;

    return 0;
}