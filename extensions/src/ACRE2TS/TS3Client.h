#pragma once

#include "IClient.h"
#include "TsFunctions.h"
#include <thread>
#include <string>
#include <vector>

class CTS3Client: public IClient {
public:
    
    //static TS3Functions ts3Functions;

    CTS3Client() { };
    ~CTS3Client() { };

    acre_result_t initialize( void );

    acre_result_t setMuted(const acre_id_t id_, const bool muted_);
    acre_result_t setMuted(std::list<acre_id_t> idList_, const bool muted_);

    acre_result_t getMuted(const acre_id_t id_);

    acre_result_t stop();
    acre_result_t start(const acre_id_t id_);

    acre_result_t exPersistVersion( void );

    acre_result_t enableMicrophone(const bool status_);

    bool getInputStatus();

    /*!
    * \brief Handles local player starting speaking.
    *
    * \param[in]    speakingType_    ACRE speaking type
    *
    * \return       acre_result_ok if operation successful
    */
    acre_result_t localStartSpeaking(const acre_speaking_t speakingType_);

    /*!
    * \brief Handles local player starting speaking.
    *
    * \param[in]    speakingType_    ACRE speaking type
    * \param[in]    radioId_         Unique radio ideintifier
    *
    * \return       acre_result_ok if operation successful
    */
    acre_result_t localStartSpeaking(const acre_speaking_t speakingType_, std::string radioId_);

    /*!
     * \brief Handles local player stopping speaking.
     *
     * \param[in]    speakingType_    ACRE speaking type
     *
     * \return       acre_result_ok if operation successful
     */
    acre_result_t localStopSpeaking(const acre_speaking_t speakingType_ );

    std::string getTempFilePath( void );
    std::string getConfigFilePath(void);
    
    acre_result_t playSound(std::string path_, ACRE_VECTOR position_, const float32_t volume_, const int32_t looping_);

    std::string getUniqueId( );

    bool getVAD();

    acre_result_t microphoneOpen(const bool status_);

    acre_result_t unMuteAll( void );

    acre_result_t moveToServerTS3Channel();
    acre_result_t moveToPreviousTS3Channel();
    uint64 findChannelByNames(std::vector<std::string> details_);
    uint32_t getWordMatches(const std::string& string1_, const std::string& string2_);
    uint32_t levenshteinDistance(const std::string& string1_, const std::string& string2_);
    std::string removeSubstrings(std::string string_, std::string substring_);
    acre_result_t updateTs3ChannelDetails(std::vector<std::string> details_);
    acre_result_t updateShouldSwitchTS3Channel(const bool state_);
    BOOL shouldSwitchTS3Channel();
    
    DECLARE_MEMBER(bool, hadVAD);
    DECLARE_MEMBER(bool, InputActive);
    DECLARE_MEMBER(acre_state_t, State);
    DECLARE_MEMBER(bool, OnRadio);
    DECLARE_MEMBER(int32_t, TsSpeakingState);
    DECLARE_MEMBER(bool, RadioPTTDown);
    DECLARE_MEMBER(bool, IntercomPTTDown);
    DECLARE_MEMBER(bool, MainPTTDown);
    DECLARE_MEMBER(bool, DirectFirst);
    DECLARE_MEMBER(bool, HitTSSpeakingEvent);
    DECLARE_MEMBER(bool, IsX3DInitialized);
    DECLARE_MEMBER(uint32_t, SpeakerMask);
    DECLARE_MEMBER(uint64, PreviousTSChannel);
    DECLARE_MEMBER(std::vector<std::string>, Ts3ChannelDetails);
    DECLARE_MEMBER(bool, ShouldSwitchTS3Channel)
protected:
    std::thread m_versionThreadHandle;
    char *m_vadLevel;
};
