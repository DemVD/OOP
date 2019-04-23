#include "chatbot.h"

using namespace ChatBot_NS;


ChatBot::ChatBot(){ // конструктор по умолчанию.
    _botName = "PROBOT";
    _userName = "USER";
    _currentDate = QDate::currentDate().toString().toStdString();
    _currentTime = QTime::currentTime().toString().toStdString();
}

void ChatBot::setBotName(const string bn){
    _botName = bn;
}

string ChatBot::botName() const{
    return _botName;
}

void ChatBot::setUserName(const string un){
    _userName = un;
}

string ChatBot::userName() const{
    return _userName;
}

void ChatBot::setCurrentDate(){

}

string ChatBot::currentDate() const{
    return _currentDate;
}

void ChatBot::setCurrentTime(){

}

string ChatBot::currentTime() const{
    return _currentTime;
}

string ChatBot::processUserMsg(const string msg){ // после каждого нажатия ОТПРАВИТЬ будет вызван метод обработки строки

}

void ChatBot::userMsgToDisplay(const string msg) const{ // передает введенную пользователем строку на дисплей.

}
