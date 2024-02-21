#ifndef SERVO360_FDSH32819
#define SERVO360_FDSH32819 1
#include<Servo.h>
class Servo360: public Servo{
    protected:
        int servoPin;
        int roundtime = 550;
    public:
        void turn(){
            write(180);
            delay(1000);
            write(90);
        }
        void set_round_time(int inp){
            roundtime = inp;
            return;
        }
        void turn30(int dir){
            int turn_time = roundtime * (double(abs(30)) / double(360));
            if(dir){
                write(180);
            }else{
                write(0);
            }
            delay(turn_time);
            write(90);
        }
        void turndeg(int deg){
            int deg_r = deg%30;
            int time_30 = deg/30;
            bool r_c = (deg >= 0);
            for(int a=0;a<time_30;a++){
                turn30(r_c);
                delay(30);
            }
            int turn_time = roundtime * (double(abs(deg_r)) / double(360));
            if(r_c){
                write(180);
            }else{
                write(0);
            }
            Serial.println(turn_time);
            delay(turn_time);
            write(90);
            return;
        }

};
#endif