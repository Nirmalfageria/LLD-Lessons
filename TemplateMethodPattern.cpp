#include<bits/stdc++.h>
using namespace std;

class DataPipeline{
    protected:
    virtual void readData()=0;
    virtual void processData()=0;
    virtual void writeData()=0;
    public:
    void execute(){
        readData();
        processData();
        writeData();
        saveData();
    }
  
   virtual  void saveData(){
        cout<<"Saving data to default location"<<endl;
    }
        };

class CSVDataPipeline: public DataPipeline{
    public:
    void readData(){
        cout<<"Reading data from CSV file"<<endl;
    }
    void processData(){
        cout<<"Processing CSV data"<<endl;
    }
    void writeData(){
        cout<<"Writing processed data to CSV file"<<endl;
    }
   
};

    class JSONDataPipeline: public DataPipeline{
    public:
    void readData(){
        cout<<"Reading data from JSON file"<<endl;
    }
    void processData(){      
        cout<<"Processing JSON data"<<endl;
    }
    void writeData(){
        cout<<"Writing processed data to JSON file"<<endl;
    }
    void saveData() override{
        cout<<"Saving data to custom JSON location"<<endl;
    }
};

int main(){
    DataPipeline* csvPipeline = new CSVDataPipeline();
    csvPipeline->execute();
    cout<<endl;
    DataPipeline* jsonPipeline = new JSONDataPipeline();
    jsonPipeline->execute();
    return 0;
}
