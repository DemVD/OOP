using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_sem2_lab1{
    class Time{
        private int Hours = 0; // закрытые параметры
        private int Minutes = 0;
        private int Seconds = 0;

        public Time(int H = 0, int M = 0, int S = 0){ // конструктор с параметрами
            this.Hours = H;
            this.Minutes = M;
            this.Seconds = S;
        }
        public int setHours(int Hnum){ //set hours
            this.Hours = Hnum;
            return this.Hours;
        }
        public int setMinutes(int Mnum){ //set minutes, converts to hours if M>59
            if (Mnum > 59){
                this.Hours += Mnum / 60;
                Mnum -= 60 * (Mnum / 60);
                this.Minutes = Mnum;
            }
            else{
                this.Minutes = Mnum;
            }
            return this.Minutes;
        }
        public int setSeconds(int Snum){ //set seconds,converts to hrs and mns if S>59
            if (Snum > 59){
                this.Minutes += Snum / 60;
                setMinutes(this.Minutes);
                Snum -= 60 * (Snum / 60);
                this.Seconds = Snum;
            }
            else{
                this.Seconds = Snum;
            }
            return this.Seconds;
        }
        public int hous(){ return this.Hours; } //return hours
        public int mins(){ return this.Minutes; } //return minutes
        public int secs(){ return this.Seconds; } //return seconds
        public string convToStr(){ //return string with time
            string timeStr = to_string(this.Hours) + ":" + to_string(this.Minutes) + ":" + to_string(this.Seconds);
            return timeStr;
        }
        public void addTime(int H = 0, int M = 0, int S = 0){ // adds time
            this.setHours(this.hous() + H);
            this.setMinutes(this.mins() + M);
            this.setSeconds(this.secs() + S);
        } //potentially, use time0.addTime(time1.getSeconds) to add or subtract
        public int convToSecs(){ // converts H and M to S.
            int buf = this.Hours * 60 * 60 + this.Minutes * 60;
            return buf;
        }
        public float convToMins(){ // converts H and S to M, FP result.
            float buf = this.Hours * 60 + this.Minutes + this.Seconds / 60;
            return buf;
        }
        public float convToHous(){ // converts M and S to H. FP result.
            float buf = this.Minutes / 60 + this.Seconds / 3600 + this.Hours;
            return buf;
        }
    }

    static void Main()
    {
        //Person sam = new Person("Sam", 25)
        Time time1 = new Time(8, 10, 12);
        Time time2 = new Time(0, 0, 59);
        Time time3 = new Time(time1.secs() + time2.secs(), time1.mins() + time2.mins(), time1.hous() + time2.hous());
        cout << "Time3: " << time3.convToStr() << endl;
        Time time4;
        time4.setSeconds(4000);
        cout << "Time4: " << time4.convToStr() << endl;

        Time time5 = new Time(); // объявление объекта и указателя на него
        Time* t5 = new Time();
        time5.setSeconds(59); // прямой доступ к объекту
        cout << "time5: " << time5.convToStr() << endl; // тоже прямой
        t5 = &time5; // присвоение t5 адреса time5
        t5->addTime(0, 0, 6); // доступ к объекту time5 с помощью указателя t5
        cout << "modified time5: " << t5->convToStr() << endl; // тоже к тайм5 через указатель т5
        Time* t6 = new Time(1, 1, 1);
        t6->addTime(1, 1, 1);
        cout << "time6: " << t6->convToStr() << endl;
        delete t6;
    }
}
