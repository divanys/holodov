////
//// Created by divan on 11/1/23.
////
//#include <iostream>
//
//using namespace std;
//
//class Device {
//public:
//    int serial_number = 12345678;
//
//    void turn_on() {
//        cout << "Device is on" << endl;
//    }
//};
//
//class Computer : private Device {
//public:
//    void say_hello() {
//        turn_on();
//        cout << "Welcome to Windows 95!" << endl;
//    }
//};
//
//int main() {
//    Device Device_instance;
//    Computer Computer_instance;
//
//    cout << "\t Device" << endl;
//    cout << "Serial number is: " << Device_instance.serial_number << endl;
//    Device_instance.turn_on();
//
//    // cout << "Serial number is: " << Computer_instance.serial_number << endl;
//    // Computer_instance.turn_on();
//    // will cause compile time error
//
//    cout << "\t Computer" << endl;
//    Computer_instance.say_hello();
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class Device {
//public:
//    // constructor
//    Device() {
//        cout << "Device constructor called" << endl;
//    }
//
//    // destructor
//    ~Device() {
//        cout << "Device destructor called" << endl;
//    }
//};
//
//class Computer : public Device {
//public:
//    Computer() {
//        cout << "Computer constructor called" << endl;
//    }
//
//    ~Computer() {
//        cout << "Computer destructor called" << endl;
//    }
//};
//
//class Laptop : public Computer {
//public:
//    Laptop() {
//        cout << "Laptop constructor called" << endl;
//    }
//
//    ~Laptop() {
//        cout << "Laptop destructor called" << endl;
//    }
//};
//
//int main() {
//    cout << "\tConstructors" << endl;
//    Laptop Laptop_instance;
//    cout << "\tDestructors" << endl;
//    return 0;
//}

//
//#include <iostream>
//
//using namespace std;
//
//class Computer {
//public:
//    void turn_on() {
//        cout << "Welcome to Windows 95" << endl;
//    }
//};
//
//class Monitor {
//public:
//    void show_image() {
//        cout << "Imagine image here" << endl;
//    }
//};
//
//class Laptop : public Computer, public Monitor {
//};
//
//int main() {
//    Laptop Laptop_instance;
//    Laptop_instance.turn_on();
//    Laptop_instance.show_image();
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Computer {
//private:
//    void turn_on() {
//        cout << "Computer is on." << endl;
//    }
//};
//
//class Monitor {
//public:
//    void turn_on() {
//        cout << "Monitor is on." << endl;
//    }
//};
//
//class Laptop: public Computer, public Monitor {};
//
//int main() {
//    Laptop Laptop_instance;
//    Laptop_instance.turn_on();
//     will cause compile time error
//    return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//class Device {
//public:
//    void turn_on() {
//        cout << "Device is on." << endl;
//    }
//};
//
//class Computer: public Device {};
//
//class Monitor: public Device {};
//
//class Laptop: public Computer, public Monitor {
//    /*
//    public:
//        void turn_on() {
//            cout << "Laptop is on." << endl;
//        }
//    // uncommenting this function will resolve diamond problem
//    */
//};
//
//int main() {
//    Laptop Laptop_instance;
//
//    // Laptop_instance.turn_on();
//    // will produce compile time error
//    // if Laptop.turn_on function is commented out
//
//    // calling method of specific superclass
//    Laptop_instance.Monitor::turn_on();
//
//    // treating Laptop instance as Monitor instance via static cast
//    static_cast<Monitor&>( Laptop_instance ).turn_on();
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//class Device {
//public:
//    Device() {
//        cout << "Device constructor called" << endl;
//    }
//};
//
//class Computer: public Device {
//public:
//    Computer() {
//        cout << "Computer constructor called" << endl;
//    }
//};
//
//class Monitor: public Device {
//public:
//    Monitor() {
//        cout << "Monitor constructor called" << endl;
//    }
//};
//
//class Laptop: public Computer, public Monitor {};
//
//int main() {
//    Laptop Laptop_instance;
//    return 0;
//}
//
//
//#include <iostream>
//using namespace std;
//
//class Device {
//public:
//    Device() {
//        cout << "Device constructor called" << endl;
//    }
//    void turn_on() {
//        cout << "Device is on." << endl;
//    }
//};
//
//class Computer: virtual public Device {
//public:
//    Computer() {
//        cout << "Computer constructor called" << endl;
//    }
//};
//
//class Monitor: virtual public Device {
//public:
//    Monitor() {
//        cout << "Monitor constructor called" << endl;
//    }
//};
//
//class Laptop: public Computer, public Monitor {};
//
//int main() {
//    Laptop Laptop_instance;
//    Laptop_instance.turn_on();
//    return 0;
//}

#include <iostream>

using namespace std;

class Device {
public:
    void turn_on() {
        cout << "Device is on." << endl;
    }

    virtual void say_hello() = 0;
};

class Laptop : public Device {
public:
    void say_hello() {
        cout << "Hello world!" << endl;
    }
};

int main() {
    Laptop Laptop_instance;
    Laptop_instance.turn_on();
    Laptop_instance.say_hello();

    // Device Device_instance;
    // will cause compile time error
    return 0;
}