#include "LinkedList.h"
#include <fstream>
template <typename T>
Node<T>::Node(T d)
{
    data = d;
    next = NULL;
    prev=NULL;
}
template <typename T>
Node<T>::~Node()
{

}
template <typename T>
void Node<T>::insert_back(Node<T>& ptr)
{
    if(this->next!=NULL) (this->next)->prev=&ptr;
    if(ptr.prev!=NULL) {
        this->prev=ptr.prev;
        ptr.prev->next=this;
    }else{
        ptr.next=this->next;
    }
    ptr.prev=this;

    this->next=&ptr;

}
template <typename T>
void Node<T>::remove()
{
    if(this->prev!=NULL) (this->prev)->next=(this->next);

    if(this->next!=NULL)(this->next)->prev=(this->prev);

    delete this;
}
template <typename T>
void Node<T>::operator+(Node<T>& ptr)
{
    insert_back(ptr);
}
template<typename T>
LinkedList<T>::LinkedList()
{
    length=0;
    head=NULL;
    tail=NULL;
}
template<typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* ptr = head;
    Node<T>* next = head;
    while(ptr!=NULL)
    {
        next=ptr->next;
        delete ptr;
        ptr=next;
    }
}
template<typename T>
void LinkedList<T>::push_back(T new_data)
{
    Node<T>* newNode = new Node<T>(new_data);
    if(head==NULL)
    {
        head = newNode;
        tail=head;
    }
    else
    {
        tail->next=newNode;
        newNode->prev=tail;
        tail=tail->next;
    }
    length++;
}
template<typename T>
void LinkedList<T>::push_front(T new_data)
{
    Node<T>* newNode = new Node<T>(new_data);
    if(head==NULL)
    {
        head = newNode;
        tail=head;
    }
    else
    {
        head->prev=newNode;
        newNode->next=head;
        head=head->prev;
    }
    length++;
}
template<typename T>
void LinkedList<T>::pop_back()
{
    tail=tail->prev;
    delete tail->next;
    tail->next=NULL;
}
template<typename T>
void LinkedList<T>::pop_front()
{
    head=head->next;
    delete head->prev;
    head->prev=NULL;
}
template<typename T>
void LinkedList<T>::remove(const T& item)
{
    while(item==head->data)
        pop_front();
    while(item==tail->data)
        pop_back();

    for(Node<T>* it=head; it!=NULL; it=it->next)
        if(item==(it->data))
            it->remove();
}
template<typename T>
void LinkedList<T>::update(const T& item)
{
    Node<T>* it=head;
    for(Node<T>* it=head; it!=NULL; it=it->next)
        if(item==(it->data))
            it->data=item;
}
template<typename T>
Node<T>* LinkedList<T>::begin()
{
    return head;
}
template<typename T>
Node<T>* LinkedList<T>::end()
{
    return tail;
}
template<typename T>
int LinkedList<T>::getLength()
{
    return length;
}
template<typename T>
string LinkedList<T>::toString()
{
    string res="[";
    if(head!=NULL)
        try
        {
            Node<T>* n;
            for( n=this->head; n->next!=NULL; n=n->next)
            {
                res+=n->data.toString()+",";
            }
            res+=n->data.toString();
        }
        catch (const std::exception &exc)
        {
            // catch anything thrown within try block that derives from std::exception
            std::cerr << exc.what();
        }
    res+="]";
    return res;
}
template<typename O>
ofstream& operator<<(ofstream& out, const LinkedList<O>& l)
{

    out<<"[";

    if(l.head!=NULL)
        try
        {
            Node<O>* n;
            for( n=l.head; n->next!=NULL; n=n->next)
            {
                out<<n->data<<",";
            }
            out<<n->data;
        }
        catch (const std::exception &exc)
        {
            // catch anything thrown within try block that derives from std::exception
            std::cerr << exc.what();
        }
    out<<"]";
    return out;
}
template<typename T>
void LinkedList<T>::reset()
{
    head=NULL;
    tail=NULL;
}
template<typename T>
LinkedList<T>& LinkedList<T>::sorting(bool cmp(const T&,const T& ) )
{
    static LinkedList<T> listSort;
    listSort.reset();
    listSort.push_back(head->data);
    for (Node<T>* it=head->next; it!=NULL; it=it->next)
    {
        Node<T>* itT=listSort.begin();
        while(itT!=NULL && cmp(itT->data,it->data))
        {
            itT=itT->next;
        }
        if(itT!=NULL){
            if(itT==listSort.begin()){
                listSort.push_front(it->data);
            }else{
                Node<T>* temp=new Node<T>(it->data);
                (*temp)+(*itT);
            }
        }else{
            listSort.push_back(it->data);
        }
    }
    return listSort;
}
