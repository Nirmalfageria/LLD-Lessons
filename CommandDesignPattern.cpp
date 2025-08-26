    #include <iostream>
    #include <vector>
    using namespace std;

    class ICommand {
    public:
        virtual void execute() = 0;
        virtual void undo() = 0;
        virtual ~ICommand() {}
    };

    class Light {
    public:
        void on() {
            cout << "Light is ON" << endl;
        }
        void off() {
            cout << "Light is OFF" << endl;
        }
    };

    class Fan {
    public:
        void start() {
            cout << "Fan is STARTED" << endl;
        }
        void stop() {
            cout << "Fan is STOPPED" << endl;
        }
    };

    class LightOnCommand : public ICommand {
        Light* light;
    public:
        LightOnCommand(Light* l) : light(l) {}
        void execute() override {
            light->on();
        }
        void undo() override {
            light->off();
        }
    };

    class FanStartCommand : public ICommand {
        Fan* fan;
    public:
        FanStartCommand(Fan* f) : fan(f) {}
        void execute() override {
            fan->start();
        }
        void undo() override {
            fan->stop();
        }
    };

    class RemoteControl {
        static const int buttons = 2;
        vector<ICommand*> onCommands;
        vector<bool> commandStatus;

    public:
        RemoteControl() {
            onCommands.resize(buttons, nullptr);
            commandStatus.resize(buttons, false);
        }

        void setCommand(int slot, ICommand* command) {
            if (slot >= 0 && slot < buttons) {
                onCommands[slot] = command;
                commandStatus[slot] = false;
            }
        }

        void pressButton(int slot) {
            if (slot >= 0 && slot < buttons && onCommands[slot]) {
                if (commandStatus[slot]) {
                    onCommands[slot]->undo();
                    commandStatus[slot] = false;
                } else {
                    onCommands[slot]->execute();
                    commandStatus[slot] = true;
                }
            }
        }
    };

    int main() {
        RemoteControl* r = new RemoteControl();
        Light* l = new Light();
        Fan* f = new Fan();

        r->setCommand(0, new LightOnCommand(l));
        r->setCommand(1, new FanStartCommand(f));

        r->pressButton(0);
        r->pressButton(1);
        r->pressButton(0);
        r->pressButton(1);

        delete l;
        delete f;
        delete r;
    }
