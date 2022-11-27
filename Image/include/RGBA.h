#ifndef RGBA_H
#define RGBA_H
#include<cstdint>
#include<string>

struct RGBA
{
    RGBA() = default;
    RGBA(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a=255):
    r{_r},g{_g},b{_b},a{_a} {}

    RGBA(const std::string &_hex){
        int IntRgba6 [3] = {0};
        int IntRgba8 [4] = {0};
        int index = 0;
        if(_hex.size() == 6){
            for(int i = 0; i < 6; i++){
                //split string
                std::string splitedString = _hex.substr(i,2);
                //string 16 to int 10
                int splitedInt = stoi(splitedString, 0, 16);
                //store in array
                IntRgba6[index] =  splitedInt;
                i++;
                index++;
            } 

            r = IntRgba6[0];
            g = IntRgba6[1];
            b = IntRgba6[2];
            a = IntRgba6[3];
       
        }if(_hex.size() == 8){
            for(int i = 0; i < 8; i++){
                //split string
                std::string splitedString = _hex.substr(i,2);
                //string 16 to int 10
                int splitedInt = stoi(splitedString, 0, 16);
                //store in array
                IntRgba8[index] =  splitedInt;
                i++;
                index++;
            } 

            r = IntRgba8[0];
            g = IntRgba8[1];
            b = IntRgba8[2];
            a = IntRgba8[3];
        }
        // see if we have 6 or 8 for string RGB(a)
        //if(_hex.size() == 6)
    }



    void set(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a=255){
        r= _r;
        g= _g;
        b= _b;
        a= _a;
    }


    union
     {
        uint32_t pixel=0;
        struct
        {
            unsigned char r;
            unsigned char g;
            unsigned char b;
            unsigned char a;
        };
    }; 
};


#endif