#ifndef KINECTMANAGER_H
#define KINECTMANAGER_H

#include <iostream>
#include <string>
#include <libfreenect2/libfreenect2.hpp>
#include <libfreenect2/frame_listener_impl.h>
#include <libfreenect2/registration.h>
#include <libfreenect2/packet_pipeline.h>
#include <libfreenect2/logger.h>

using namespace libfreenect2;

class KinectManager {
    public:
        KinectManager();
        ~KinectManager();
        void connect();
        void captureLoop();

    private:
        Freenect2 freenect;
        Freenect2Device *dev;
        PacketPipeline *pipeline;
        std::string serial;

        //listeners
        SyncMultiFrameListener *listener;
        FrameListener *rgbListener;
        FrameListener *irListener;
        FrameListener *depthListener;
        //bool rgbFrame (Frame::Type type, Frame *frame);
        //bool irFrame (Frame::Type type, Frame *frame);	
        //bool depthFrame (Frame::Type type, Frame *frame);	

        bool connected;
        int mode;
        bool rgbEnabled;
        bool depthEnabled;

        //frames
        FrameMap frameMap;
        Frame *rgb, *ir, *depth;

        bool start();
        void stop();
        void pause(){};


};


#endif