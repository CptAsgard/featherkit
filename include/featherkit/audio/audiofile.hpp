#pragma once
#include <sndfile.h>
#include <string>
#include <vector>

namespace fea
{
    class AudioFile
    {
        public:
            AudioFile();
            AudioFile(const AudioFile& other) = delete;
            AudioFile(AudioFile&& other);
            AudioFile& operator=(const AudioFile& other) = delete; 
            AudioFile& operator=(AudioFile&& other); 
            ~AudioFile();
            int32_t getChannelCount() const;
            int32_t getSampleRate() const;
            std::vector<int16_t> getSampleData() const;
            void open(const std::string& path);
            void fillBufferFromIndex(std::vector<int16_t>& buffer, size_t sampleIndex);
        private:
            SNDFILE* mFile;
            int32_t mChannelCount;
            int32_t mSampleRate;
            size_t mSampleAmount;
    };
    /** @addtogroup Audio
     *@{
     *  @class AudioFile
     *@}
     ***
     *  @class AudioEffect
     *  @brief Base class for EFX based effects
     *
     *  Effects can be added to slots in the AudioPlayer class. When an audio source sends audio to the effect slot an effect has been added to, the effect is applied.
     *
     *  All the effects are based directly on the <a href="https://docs.google.com/viewer?url=http%3A%2F%2Fzhang.su%2Fseal%2FEffectsExtensionGuide.pdf">EFX specification</a> and are hence not documented here. So have a look there to find out all about what the effects are, and what default values they have and which default values they expect.
     ***
     *  @fn AudioFile::AudioFile()
     *  @brief Construct an AudioFile. 
     ***
     *  @fn AudioFile::AudioFile(const AudioFile& other) = delete
     *  @brief Deleted copy constructor.
     ***
     *  @fn AudioFile::AudioFile(AudioFile&& other)
     *  @brief Move an AudioFile.
     ***
     *  @fn AudioFile::AudioFile& operator=(const AudioFile& other) = delete
     *  @brief Deleted assignment operator.
     ***
     *  @fn AudioFile::AudioFile& operator=(AudioFile&& other)
     *  @brief Move an AudioFile.
     ***
     *  @fn AudioFile::~AudioFile()
     *  @Destroy an AudioFile.
     ***
     *  @fn int32_t AudioFile::getChannelCount() const
     *  @brief Get the amount of audio channels.
     *  @return Amount of channels.
     ***
     *  @fn int32_t AudioFile::getSampleRate() const
     *  @brief Get the sample rate.
     *  @return Sample rate.
     ***
     *  @fn std::vector<int16_t> AudioFile::getSampleData() const
     *  @brief Get the samples.
     *
     *  The samples are represented as a vector of signed 16-bit integer data where 0 is silent.
     *  @return Vector with samples.
     ***
     *  @fn void AudioFile::open(const std::string& path)
     *  @brief Opens the file at the given path.
     *
     *  The file given must be one of the formats supported by libsndfile. This includes all common formats except for mp3. A full list can be seen on the <a href="http://www.mega-nerd.com/libsndfile/#Features">libsndfile homepage</a>.
     *  Throws an AudioFileNotFoundException when the file could not be loaded.
     *  @param path Path to file to load.
     ***
     *  @fn void fillBufferFromIndex(std::vector<int16_t>& buffer, size_t sampleIndex);
     *  @brief Fill a memory buffer with data from a specific point in the file.
     *
     *  Assert/undefined behaviour if this is called when no valid file is loaded.
     *  @param buffer Buffer to fill. The function will try to fill the whole buffer. If the buffer is larger than the amount of available data at the sample index given, the buffer will be downsized to fit the data.
     *  @param sampleIndex Index of the sample to start from.
     ***/
}
