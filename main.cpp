#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Logger {
private:
    std::ostream* out;
public:
    Logger(std::ostream* out) {
        this->out = out;
    }

    Logger& log(const std::string& header, const int& data) {
        *(this->out) << "[" << header << "]" << data << endl;
        return *this;
    }

    Logger& log(const int& data) {
        *(this->out) << "[Int data]" << data << endl;
        return *this;
    }

    Logger& log(const std::string& header, const std::string& message) {
        *(this->out) << "[" << header << "]" << message << endl;
        return *this;
    }

    Logger& log(const std::string& message) {
        *(this->out) << "[ String data ]" << message << endl;
        return *this;
    }

    friend Logger& operator<<(Logger& logger, const string& data);
    friend Logger& operator<<(Logger& logger, const int& data);
};

Logger& operator<<(Logger& logger, const string& data) {
    return logger.log(data);
}


Logger& operator<<(Logger& logger, const int& data) {
    return logger.log(data);
}

long sum_of_array(int* a, int size) {
    long sum = 0;
    for (int i = 0; i < size; i += 2)
    {
        if (a[i] % 2 == 0)
        {
            sum += a[i];
        }
    }

    return sum;
}

static std::ofstream log_file("log.txt");

static Logger logger(&log_file);

int main()
{   
    logger << "-----------Start-----------";

    int a[] = { -5,1,2,7,33,9 };
    char a1[] = { 'A','B','V' };

    int size = sizeof(a) / sizeof(a[0]);

    cout << "Size:" << size << endl;
    logger << "Size:" << size;
    auto sum = sum_of_array(a, size);

    cout << "Sum " << sum << endl;
    logger << "Sum: " << sum;

    logger << "-----------Finish-----------";

    return 0;
}