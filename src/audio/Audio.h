#ifndef AUDIO_H
#define AUDIO_H

#include <string>
#include <mutex>
#include <thread>

namespace SoLoud {
    class Soloud;
}

namespace light2d {
    namespace audio {
        class Audio {
        public:
            static void init();
            static void deinit();
            
            static void play(std::string filepath, bool streamed, bool looped);
        private:
            static bool running;
            static SoLoud::Soloud* engine;
            
            static std::mutex engineLock;
            static std::mutex runningLock;
            static std::thread handlerThread;
            
            static void engine_handler();
        };
    }
}

#endif /* AUDIO_H */

