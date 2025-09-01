#include <bits/stdc++.h>
using namespace std;

class FileSystem {
public:
    virtual ~FileSystem() {}
    virtual void ls(int indent = 0) = 0;
    virtual void add(FileSystem* f) = 0;
    virtual void remove(FileSystem* f) = 0;
    virtual void openAll(int indent = 0) = 0;
    virtual string getName() = 0;
    virtual FileSystem* cd(const string& name) = 0;
    virtual bool isFolder() = 0;
};

class File : public FileSystem {
    string name;
    int size;
public:
    File(const string& n, int s) : name(n), size(s) {}
    void ls(int indent = 0) override {
        cout << string(indent, ' ') << name << " (" << size << " KB)" << endl;
    }
    void add(FileSystem* f) override {
        cout << "Cannot add to a file." << endl;
    }
    void remove(FileSystem* f) override {
        cout << "Cannot remove from a file." << endl;
    }
    void openAll(int indent = 0) override {
        cout << string(indent, ' ') << "Opening file: " << name << endl;
    }
    string getName() override {
        return name;
    }
    FileSystem* cd(const string& name) override {
        cout << "Cannot change directory into a file." << endl;
        return nullptr;
    }
    bool isFolder() override {
        return false;
    }
};

class Folder : public FileSystem {
    string name;
    vector<FileSystem*> children;
public:
    Folder(const string& n) : name(n) {}
    ~Folder() {
        for (auto child : children) {
            delete child;
        }
    }
    void ls(int indent = 0) override {
        cout << string(indent, ' ') << name << "/" << endl;
        for (auto child : children) {
            child->ls(indent + 2);
        }
    }
    void add(FileSystem* f) override {
        children.push_back(f);
    }
    void remove(FileSystem* f) override {
        children.erase(remove(children.begin(), children.end(), f), children.end());
    }
    void openAll(int indent = 0) override {
        cout << string(indent, ' ') << "Opening folder: " << name << endl;
        for (auto child : children) {
            child->openAll(indent + 2);
        }
    }
    string getName() override {
        return name;
    }
    FileSystem* cd(const string& name) override {
        for (auto child : children) {
            if (child->isFolder() && child->getName() == name) {
                return child;
            }
        }
        cout << "Folder not found: " << name << endl;
        return nullptr;
    }
    bool isFolder() override {
        return true;
    }
};

int main() {
    Folder* root = new Folder("root");
    Folder* home = new Folder("home");
    Folder* user = new Folder("user");
    File* file1 = new File("file1.txt", 10);
    File* file2 = new File("file2.txt", 20);
    File* file3 = new File("file3.txt", 30);

    user->add(file1);
    user->add(file2);
    home->add(user);
    root->add(home);
    root->add(file3);

    root->ls();
    cout << endl << "Opening all files and folders:" << endl;
    root->openAll();

    FileSystem* current = root;
    current = current->cd("home");
    if (current) current = current->cd("user");
    if (current) current->ls();

    delete root;
    return 0;
}