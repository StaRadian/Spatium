#include "Kenny.h"

#define KENNYDATASIZE_X 1710
#define KENNYDATASIZE_Y 1018

namespace kenny
{
    struct KennyTexData
    {
        spat::Vec2 size;
        spat::Vec2 sheetPos;
        spat::Vec2 basicPos;
    };

    Kenny::Kenny()
    {
        const KennyTexData data[KENNYDATASIZE] = {
            100,   12,	  0, 1006,   89,  116,    //EyebrowRight 			    
            100,   12,	  0, 1006,  -89,  116,    //EyebrowLeft		    
            120,  120,	  0,  886,  262, -438,    //KennyHandRight_Rock 	
            120,  120,    0,  766, -247, -432,    //KennyHandLeft_Rock	    
            150,  150,    0,  616, -182, -413,    //KennyHandRight_Paper	
            150,  150,    0,  466,  197, -401,    //KennyHandLeft_Paper	    
            665,  668,	150,  350,    0,    0,    //KennyHatFront		    
             24,   24,	120,  994,   45,    5,    //EyeballRight			        
             24,   24,	120,  994,  -45,    5,    //EyeballLEFT	        
            400,  200,    0,  150,    1,    9,    //NormalEyesFront		    
            635,  646,	815,  372,    0,    0,    //Face			        
            180,  200,	400,  150, -225, -325,    //KennyArmRightFrontNomarl
            180,  200,	580,  150,  247, -323,    //KennyArmLeftFrontNomarl	
            500,  300,  760,   50,    1, -371,    //KennyBadyFront		    
            200,  300, 1450,  718, -207, -350,    //KennyArmRight_Bend	    
            200,  300, 1450,  418,  221, -348,    //KennyArmLeft_Bend	    
            250,  150,    0,    0, -251, -318,    //KennyArmRight_Open	    
            250,  150,  250,    0,  263, -314,    //KennyArmLeft_Open	    
            450,  250, 1260,  122,    0, -442     //KennyPantFront		    
        };

        for(int i = 0; i < KENNYDATASIZE; i++)
        {
            m_QuardPS[i].size = data[i].size;
            m_QuardPS[i].pos = data[i].basicPos;
            m_TexPS[i].size.x = (float)(data[i].size.x / KENNYDATASIZE_X);
            m_TexPS[i].size.y = (float)(data[i].size.y / KENNYDATASIZE_Y);
            m_TexPS[i].pos.x = (float)(data[i].sheetPos.x / KENNYDATASIZE_X);
            m_TexPS[i].pos.y = (float)(data[i].sheetPos.y / KENNYDATASIZE_Y);
        }
    }

    Kenny::~Kenny()
    {

    }
}