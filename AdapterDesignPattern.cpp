#include<bits/stdc++.h>
using namespace std;

class IReports{
    public:
    virtual string getJsonReport(const string& data)=0;
        virtual ~IReports(){};
};  

class XmlDataProvider{
    public:
    string getXmlData(const string& data){
        cout<<data<<endl;
        return "<data>"+data+"</data>";
    }
};

class XmlToJsonAdapter:public IReports{
    XmlDataProvider* xmlProvider;
    public:
    XmlToJsonAdapter(XmlDataProvider* provider):xmlProvider(provider){}
    string getJsonReport(const string& data) override{
        string xmlData=xmlProvider->getXmlData(data);
        // Simple conversion for demonstration
        return "{\"data\":\""+data+"\"}";
    }
};

int main(){
    XmlDataProvider* xmlProvider=new XmlDataProvider();
    IReports* reportAdapter=new XmlToJsonAdapter(xmlProvider);
    string jsonReport=reportAdapter->getJsonReport("Sample Data ki report");
    cout<<jsonReport<<endl;

    delete xmlProvider;
    delete reportAdapter;
    return 0;
}