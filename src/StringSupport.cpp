#include "StringSupport.h"
#include<vector>
string* split(string str,char delimeter){

    vector<string> listRes;
    string item="";
    for(char c: str)
        if(delimeter==c){
            listRes.push_back(item);
            item="";
        }else{
            item+=c;
        }
    listRes.push_back(item);
    string* listData=new string[listRes.size()];
    int i=0;
    for (auto it = listRes.begin(); it != listRes.end(); ++it,i++)
        listData[i]=*it;
    return listData;
}
string FormatStringJSON(string s,bool getNULL){
    if(s=="" && getNULL) return "null";
    return "\""+s+ "\"";
}
string FormatListJSON(string s,bool getNULL){
    if(s=="" && getNULL) return "null";
    return "["+s+"]";
}
string FormatObjectJSON(string s,bool getNULL){
    if(s=="" && getNULL ) return "null";
    return "{"+s+"}";
}
string FormatStringJSON(string key,string s,bool getNULL){
    if(s=="" && getNULL) return "\""+key+"\":null";
    return "\""+key+"\":\""+s+ "\"";
}
string FormatListJSON(string key,string s,bool getNULL){
    if(s=="" && getNULL) return "\""+key+"\":null";
    return "\""+key+"\":["+s+"]";
}
string FormatObjectJSON(string key,string s,bool getNULL){
    if(s=="" && getNULL) return "\""+key+"\":null";
    return "\""+key+"\":{"+s+"}";
}
string mean(string s,int val,bool getNULL){
    if(val==0 && getNULL)
        return FormatStringJSON(s)+":"+"null";

    return FormatStringJSON(s)+":"+to_string(val);
}
string mean(string s,Date date,bool getNULL){
    if(!date==false && getNULL)return FormatStringJSON(s)+":"+"null";

    return FormatStringJSON(s)+":"+FormatStringJSON(date.getDate());
}
string mean(string s,string data,bool getNULL){
    if(data=="" && getNULL)
        return FormatStringJSON(s)+":"+"null";
    return FormatStringJSON(s)+":"+FormatStringJSON(data);
}

bool search(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (tolower(txt[i + j]) != tolower(pat[j]))
                break;

        if (j== M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            return true;
    }
    return false;
}
