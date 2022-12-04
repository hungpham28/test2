#include <fstream>
#include "Services.h"
#include "StringSupport.h"
#include "DatabaseMapping.h"
template<typename T>
int Services<T>::generate_id;
template<typename T>
Services<T>::Services()
{
    string filename(URI_DATABASE+ T::TABLE);
    string line;
    //Mở file bằng ifstream
    ifstream input_file(filename);
    //Kiểm tra file đã mở thành công chưa
    if (!input_file.is_open())
    {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;

    }
    //line first is generate value id
    getline(input_file, line, '\n');
    generate_id=stoi(line);
    //read data
    string* listData;
    while(getline(input_file, line, '\n') && line!="")
    {
        listData=split(line,';');
        this->listObjects.push_back(T(listData));
    }
}
template<typename T>
Services<T>::~Services()
{

}
template<typename T>
string Services<T>::getJSON_Objects()
{
    string JSON="[";
    for(Node<T>* it = listObjects.begin(); it != NULL; it=it->next)
    {
        JSON+=FormatObjectJSON(it->data.toString());
        if(it->next!=NULL) JSON+=",";
    }
    JSON+="]";
    return JSON;
}
template<typename T>
void Services<T>::add(T item)
{
    item.setId(generate_id++);
    this->listObjects.push_back(item);

    save();
};
template<typename T>
T Services<T>::getById(int id)
{
    for(Node<T>* it=listObjects.begin(); it!=NULL; it=it->next)
    {
        if(it->data.getId()==id)
        {
            return it->data;
        }
    }
    return T();
}
template<typename T>
void Services<T>::deleteById( int id)
{
    T t; t.setId(id);
    listObjects.remove(t);
    save();
}
template<typename T>
void Services<T>::update(const T& item)
{
    for(Node<T>* it=listObjects.begin(); it!=NULL; it=it->next)
    {
        if(it->data.getId()==item.getId())
        {
            it->data=item;
        }
    }
    save();
}
template<typename T>
void Services<T>::save()
{
    string filename(URI_DATABASE+ T::TABLE);
    string line;
    //Mở file bằng ofstream
    ofstream output_file(filename);
    output_file<<generate_id<<"\n";
    for(Node<T>* o=listObjects.begin(); o!=NULL; o=o->next)
    {
        output_file<<o->data.toText()<<"\n";
    }
    output_file.close();
}
template<typename T>
LinkedList<T>& Services<T>::getEntities()
{
    return listObjects;
};
template<typename T>
LinkedList<T>& Services<T>::sorting(bool cmp(const T& t1,const T& t2))
{
    return listObjects.sorting(cmp);
};
