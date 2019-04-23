#ifndef CHATBOT_H
#define CHATBOT_H
#include <string>
#include <QDateTime>


using namespace std;


namespace ChatBot_NS{

class ChatBot{
private:
    string _botName; // имя ЧатБота
    string _userName; // имя Пользователя
    string _currentDate; // хранит строку даты
    string _currentTime; // хранит строку времени
public:
    ChatBot();
    void setBotName(const string bn);
    string botName() const;
    void setUserName(const string un);
    string userName() const;
    void setCurrentDate();
    string currentDate() const;
    void setCurrentTime();
    string currentTime() const;
    string processUserMsg(const string msg); // после каждого нажатия ОТПРАВИТЬ будет вызван метод обработки строки
    void userMsgToDisplay(const string msg) const; // передает введенную пользователем строку на дисплей.
};

}
#endif // CHATBOT_H
