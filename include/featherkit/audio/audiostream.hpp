#pragma once
#include <vector>
#include <queue>
#include <cstring>
#include <featherkit/audio/audiobuffer.hpp>
#include <featherkit/audio/audiodata.hpp>

namespace fea
{
    class AudioStream
    {
        public:
            AudioStream();
            AudioStream(size_t bufferAmount);
            void setStreamProperties(size_t channelCount, size_t sampleRate);
            AudioBuffer* nextReadyBuffer();
            void bufferConsumed();
            virtual AudioData fetchBufferData(size_t bufferIndex) = 0;
        private:
            size_t fillBuffer(AudioBuffer* buffer);
            std::vector<AudioBuffer> mBuffers;
            std::queue<size_t> mReadyBuffers;
            std::queue<size_t> mConsumingBuffers;
            size_t mNextToFill;
            ALenum mFormat;
            size_t mChannelCount;
            size_t mSampleRate;
    };
}
