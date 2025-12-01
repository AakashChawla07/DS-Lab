#include "1b.cpp";
#include "1.cpp";
#include<iostream>
using namespace std;

class CirLL : public CLL{
    public:
    int size(){
        if(head==NULL)
            return 0;
        Node* temp=head;int c=1;
        while(temp->next!=head){
            ++c;
            temp=temp->next;
        }
        return c;
    }
};
class DbLL : public DLL{
    public:
    int size(){
        if(head==NULL)
            return 0;
        Node* temp=head;int c=1;
        while(temp!=tail){
            ++c;
            temp=temp->next;
        }
        return c;
    }
};
int main(){
    CirLL l1;
    DbLL l2;
    l1.addBeg(10); l1.addBeg(30); l1.addBeg(40); l1.addEnd(100); l1.addEnd(200); l1.addEnd(300);
    l2.addBeg(10); l2.addBeg(30); l2.addBeg(40); l2.addEnd(100); l2.addEnd(200); l2.addEnd(300);
    cout<<"Size of CLL : "<<(l1.size())<<endl;
    cout<<"Size of DLL : "<<(l2.size())<<endl;
    return 0;
}