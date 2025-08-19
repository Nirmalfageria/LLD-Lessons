#include<bits/stdc++.h>
using namespace std;
class database{
    public:
    virtual void savetodb(string data) =0;
};
class mongodb : public database{
public:
void savetodb(string data) override{
    cout<<"data saved to the mongo DB"<<endl;
    return ;
}

};
class sql:public database{

    public:
    void savetodb(string data) override{
        cout<<"data saved to the SQL"<<endl;
        return;
    }
};

class user{
    string name;
    database* db;
    public:
    user(string n,database* d){
        this->name = n;
        this->db =d;
    }
    void save(string data){
        cout<<"user "<<name<<" data saving to the db"<<endl;
db->savetodb(data);
    }
};

int main(){
    database* mongo = new mongodb();
    database* mysql = new sql();
    user* u1 = new user("nirmal",mongo);
    u1->save("fageria");
    user* u2 = new user("nirmal",mysql);
    u2->save("fageria");
    delete(u1);
    delete(u2);
    return 0;
}