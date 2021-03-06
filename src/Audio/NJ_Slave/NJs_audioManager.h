//
//  NJs_audioManager.h
//  
//
//  Created by Sarah Denoux on 15/07/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

// NJs_audioManager controls 2 NJs_audioFader. It can switch from one to another with a crossfade or it can act like a simple netjack-dsp

#ifndef _NJs_audioManager_h
#define _NJs_audioManager_h

#include "AudioManager.h"

class NJs_audioFader;

class NJs_audioManager : public AudioManager {

    private:
    
        Q_OBJECT
        
        //Settings are common to the 2 audioFader that can co-exist during a crossfade
        int                     fCV;
        QString                  fIP;
        int                     fPort;
        int                     fMTU;
        int                     fLatency;
        
        int                     fBufSize;
        int                     fSplRate;
        
        const char*             fName;
        bool                    fInit; //Indicator of which init has been used
        
        NJs_audioFader*          fCurrentAudio;
        NJs_audioFader*          fFadeInAudio;
    
    public:
    
        NJs_audioManager(AudioShutdownCallback cb, void* arg);
        virtual ~NJs_audioManager();
    
        virtual bool initAudio(QString& error, const char* name, bool midi);
        virtual bool initAudio(QString& error, const char* name, const char* port_name, int numInputs, int numOutputs, bool midi);
        virtual bool setDSP(QString& error, dsp* DSP, const char* port_name);
        
        virtual bool init(const char*, dsp* DSP);
        virtual bool start();
        virtual void stop();
    
        virtual bool init_FadeAudio(QString& error, const char* name, dsp* DSP);
        virtual void start_Fade();
        virtual void wait_EndFade();
    
        virtual int get_buffer_size();
        virtual int get_sample_rate();
    
    private slots:
    
        void send_Error(const char*);
    
};

#endif
