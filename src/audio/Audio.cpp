#include "Audio.h"

using namespace light2d::audio;

#include "../third_party/soloud/soloud.h"
#include "../third_party/soloud/soloud_wavstream.h"
#include "../third_party/soloud/soloud_wav.h"
#include "../third_party/soloud/soloud_thread.h"
#include "../third_party/soloud/soloud_bus.h"

#include "../core/Logger.h"

#include <thread>

bool Audio::running = false;
SoLoud::Soloud* Audio::engine = nullptr;
std::mutex Audio::engineLock;
std::mutex Audio::runningLock;
std::thread Audio::handlerThread;


void Audio::init() {
    engine = new SoLoud::Soloud();
    engine->init();
    
    core::Logger::get()->info("Audio backend", engine->getBackendString());
    
    running = true;
    handlerThread = std::thread(engine_handler);
    
}

void Audio::deinit() {
    runningLock.lock();
    running = false;
    runningLock.unlock();
    
    handlerThread.join();
    
    engine->stopAll();
    
    engine->deinit();
    delete engine;
}

void Audio::play(std::string filepath, bool streamed, bool looped) {
    if (engine == nullptr)
        return;
        
    int handler;
    
    SoLoud::AudioSource* source = nullptr;
    
    if (streamed) {
        SoLoud::WavStream* stream = new SoLoud::WavStream();
        stream->load(filepath.c_str());
        
        source = stream;
    }
    else {
        SoLoud::Wav* wav = new SoLoud::Wav();
        wav->load(filepath.c_str());
        
        source = wav;
    }
    
    source->setLooping(looped);
    
    engineLock.lock();
    handler = engine->play(*source);
    engineLock.unlock();
}

void Audio::engine_handler() {
    bool finished = false;
    while (!finished) {
        SoLoud::Thread::sleep(2);
        
        runningLock.lock();
        finished = !running;
        runningLock.unlock();
    }
}