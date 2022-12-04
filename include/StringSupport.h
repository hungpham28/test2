#include<LinkedList.h>
#include"Date.h"
#ifndef STRINGSUPPORT_H
#define STRINGSUPPORT_H
string* split(string str,char delimeter);
string FormatStringJSON(string ,bool getNULL=true);
string FormatListJSON(string ,bool getNULL=true);
string FormatObjectJSON(string ,bool getNULL=true);
string FormatStringJSON(string ,string ,bool getNULL=true);
string FormatListJSON(string ,string ,bool getNULL=true);
string FormatObjectJSON(string ,string ,bool getNULL=true );
string mean(string s,int val,bool getNULL=true);
string mean(string s,string data,bool getNULL=true);
string mean(string s,Date date,bool getNULL=true);
bool search(string pat, string txt);
#endif // STRINGSUPPORT_H
