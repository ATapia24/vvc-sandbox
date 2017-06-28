#include "KinectManager.h"

//CONSTRUCTOR
KinectManager::KinectManager() {
    dev = NULL;
    pipeline = new CpuPacketPipeline(); //opencl?
    listener = NULL;
    connected = false;
    mode = 0;
    rgbEnabled = true;
    depthEnabled = true;
}

//DECONSTRUCTOR
KinectManager::~KinectManager() {
    delete listener;
}

//CONNECT
void KinectManager::connect() {
    //check if connected
     if(freenect.enumerateDevices() == 0) {
        std::cout << "A Kinect is not connected.\n";
        return;
    }

    //actually connect to kinect
    serial = freenect.getDefaultDeviceSerialNumber();
    dev = freenect.openDevice(serial, pipeline);

    //modes
    if(rgbEnabled)
        mode |= Frame::Color;
    if(depthEnabled)
        mode |= Frame::Depth | Frame::Ir;

    //setup frame listener
    listener = new SyncMultiFrameListener(mode);
    dev->setColorFrameListener(listener);
    dev->setIrAndDepthFrameListener(listener);

    //start capturing
    if(start())
        connected = true;
    else
        std::cout << "Kinect failed to start.\n";

}

//START
bool KinectManager::start() {
    if(rgbEnabled && depthEnabled) {
        if(!dev->start())
            return false;
    } else {
        if(!dev->startStreams(rgbEnabled, depthEnabled))
            return false;
    }
    std::cout << "Kinect Connected\n";
    return true;
}

//STOP
void KinectManager::stop() {
    dev->stop();
    dev->close();
    connected = false;
}

//CAPTURE LOOP
void KinectManager::captureLoop() {

    std::cout << "Started Capturing\n";
    /*/*
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Sandbox");
    sf::Event event;
    int width = 512, height = 424;
    int count = width * height;
    sf::VertexArray points(sf::Points, count);
    int p=0;

    for(int i=0; i<height; i++) {
        for(int j=width; j>0; j--) {
            points[p].position = sf::Vector2f(j, i);
            p++;
        }
    }

    sf::Texture texture;
    texture.create(1920, 1080);
    sf::Image image;
    image.create(1920, 1080, sf::Color::Red);

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(0,0);

    while(connected && window.isOpen()) {
        if(!listener->waitForNewFrame(frameMap, 10000)) {
            std::cout << "Kinect timed out\n";
            connected = false;
            return;
        }

        //tmp
        //poll events
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        //read frames
        rgb = frameMap[Frame::Color];
        ir = frameMap[Frame::Ir];
        depth = frameMap[Frame::Depth];
        
        

        /*ir
        int j=0;
        for(int i=0; i<count; i++) {
            float d = ir->data[j+2];
            points[i].color = sf::Color(d, d, d);
            j+=4;
        }*/

        //depth
        /*int j=0;
        for(int i=0; i<count; i++) {
            float d = depth->data[j+2];
            points[i].color = sf::Color(d, d, d);
            //std::cout << "depth: " << (float)depth->data[j] << ' ' << (float)depth->data[j+1] << ' ' << (float)depth->data[j+2] << '\n';
            //points[i].color = sf::Color((float)depth->data[j], (float)depth->data[j+1], (float)depth->data[j+2]);
            j+=4;
        }*/

        

        /*int j=0;
        for(int i=0; i<count; i++) {
            points[i].color = sf::Color(rgb->data[j], rgb->data[j+1], rgb->data[j+2]);
            j+= 4;
        }*/

        /*
        window.clear(sf::Color::Black);
        window.draw(points);
        window.display();
        */
           // points[i].color = sf::Color((float)ir->data[i], (float)ir->data[i], (float)ir->data[i]);

        //registration->apply(rgb, depth, &undistorted, &registered);      
        listener->release(frameMap);
    //}

    
}


/*
bool KinectManager::rgbFrame (Frame::Type type, Frame *frame) {
    std::cout << "rgb recieved\n";
}

bool KinectManager::irFrame (Frame::Type type, Frame *frame) {

}

bool KinectManager::depthFrame (Frame::Type type, Frame *frame) {

}*/