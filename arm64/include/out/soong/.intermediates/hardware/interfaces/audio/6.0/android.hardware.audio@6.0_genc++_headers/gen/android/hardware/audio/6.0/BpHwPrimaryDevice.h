#ifndef HIDL_GENERATED_ANDROID_HARDWARE_AUDIO_V6_0_BPHWPRIMARYDEVICE_H
#define HIDL_GENERATED_ANDROID_HARDWARE_AUDIO_V6_0_BPHWPRIMARYDEVICE_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/audio/6.0/IHwPrimaryDevice.h>

namespace android {
namespace hardware {
namespace audio {
namespace V6_0 {

struct BpHwPrimaryDevice : public ::android::hardware::BpInterface<IPrimaryDevice>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwPrimaryDevice(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IPrimaryDevice Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::android::hardware::audio::V6_0::IPrimaryDevice follow.
    static ::android::hardware::Return<::android::hardware::audio::V6_0::Result>  _hidl_setVoiceVolume(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, float volume);
    static ::android::hardware::Return<::android::hardware::audio::V6_0::Result>  _hidl_setMode(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::audio::common::V6_0::AudioMode mode);
    static ::android::hardware::Return<::android::hardware::audio::V6_0::Result>  _hidl_setBtScoHeadsetDebugName(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& name);
    static ::android::hardware::Return<void>  _hidl_getBtScoNrecEnabled(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getBtScoNrecEnabled_cb _hidl_cb);
    static ::android::hardware::Return<::android::hardware::audio::V6_0::Result>  _hidl_setBtScoNrecEnabled(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool enabled);
    static ::android::hardware::Return<void>  _hidl_getBtScoWidebandEnabled(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getBtScoWidebandEnabled_cb _hidl_cb);
    static ::android::hardware::Return<::android::hardware::audio::V6_0::Result>  _hidl_setBtScoWidebandEnabled(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool enabled);
    static ::android::hardware::Return<void>  _hidl_getBtHfpEnabled(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getBtHfpEnabled_cb _hidl_cb);
    static ::android::hardware::Return<::android::hardware::audio::V6_0::Result>  _hidl_setBtHfpEnabled(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool enabled);
    static ::android::hardware::Return<::android::hardware::audio::V6_0::Result>  _hidl_setBtHfpSampleRate(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t sampleRateHz);
    static ::android::hardware::Return<::android::hardware::audio::V6_0::Result>  _hidl_setBtHfpVolume(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, float volume);
    static ::android::hardware::Return<void>  _hidl_getTtyMode(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getTtyMode_cb _hidl_cb);
    static ::android::hardware::Return<::android::hardware::audio::V6_0::Result>  _hidl_setTtyMode(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::audio::V6_0::IPrimaryDevice::TtyMode mode);
    static ::android::hardware::Return<void>  _hidl_getHacEnabled(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getHacEnabled_cb _hidl_cb);
    static ::android::hardware::Return<::android::hardware::audio::V6_0::Result>  _hidl_setHacEnabled(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool enabled);
    static ::android::hardware::Return<::android::hardware::audio::V6_0::Result>  _hidl_updateRotation(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::audio::V6_0::IPrimaryDevice::Rotation rotation);

    // Methods from ::android::hardware::audio::V6_0::IDevice follow.
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> initCheck() override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setMasterVolume(float volume) override;
    ::android::hardware::Return<void> getMasterVolume(getMasterVolume_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setMicMute(bool mute) override;
    ::android::hardware::Return<void> getMicMute(getMicMute_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setMasterMute(bool mute) override;
    ::android::hardware::Return<void> getMasterMute(getMasterMute_cb _hidl_cb) override;
    ::android::hardware::Return<void> getInputBufferSize(const ::android::hardware::audio::common::V6_0::AudioConfig& config, getInputBufferSize_cb _hidl_cb) override;
    ::android::hardware::Return<void> openOutputStream(int32_t ioHandle, const ::android::hardware::audio::common::V6_0::DeviceAddress& device, const ::android::hardware::audio::common::V6_0::AudioConfig& config, ::android::hardware::hidl_bitfield<::android::hardware::audio::common::V6_0::AudioOutputFlag> flags, const ::android::hardware::audio::common::V6_0::SourceMetadata& sourceMetadata, openOutputStream_cb _hidl_cb) override;
    ::android::hardware::Return<void> openInputStream(int32_t ioHandle, const ::android::hardware::audio::common::V6_0::DeviceAddress& device, const ::android::hardware::audio::common::V6_0::AudioConfig& config, ::android::hardware::hidl_bitfield<::android::hardware::audio::common::V6_0::AudioInputFlag> flags, const ::android::hardware::audio::common::V6_0::SinkMetadata& sinkMetadata, openInputStream_cb _hidl_cb) override;
    ::android::hardware::Return<bool> supportsAudioPatches() override;
    ::android::hardware::Return<void> createAudioPatch(const ::android::hardware::hidl_vec<::android::hardware::audio::common::V6_0::AudioPortConfig>& sources, const ::android::hardware::hidl_vec<::android::hardware::audio::common::V6_0::AudioPortConfig>& sinks, createAudioPatch_cb _hidl_cb) override;
    ::android::hardware::Return<void> updateAudioPatch(int32_t previousPatch, const ::android::hardware::hidl_vec<::android::hardware::audio::common::V6_0::AudioPortConfig>& sources, const ::android::hardware::hidl_vec<::android::hardware::audio::common::V6_0::AudioPortConfig>& sinks, updateAudioPatch_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> releaseAudioPatch(int32_t patch) override;
    ::android::hardware::Return<void> getAudioPort(const ::android::hardware::audio::common::V6_0::AudioPort& port, getAudioPort_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setAudioPortConfig(const ::android::hardware::audio::common::V6_0::AudioPortConfig& config) override;
    ::android::hardware::Return<void> getHwAvSync(getHwAvSync_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setScreenState(bool turnedOn) override;
    ::android::hardware::Return<void> getParameters(const ::android::hardware::hidl_vec<::android::hardware::audio::V6_0::ParameterValue>& context, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& keys, getParameters_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setParameters(const ::android::hardware::hidl_vec<::android::hardware::audio::V6_0::ParameterValue>& context, const ::android::hardware::hidl_vec<::android::hardware::audio::V6_0::ParameterValue>& parameters) override;
    ::android::hardware::Return<void> getMicrophones(getMicrophones_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setConnectedState(const ::android::hardware::audio::common::V6_0::DeviceAddress& address, bool connected) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> close() override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> addDeviceEffect(int32_t device, uint64_t effectId) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> removeDeviceEffect(int32_t device, uint64_t effectId) override;

    // Methods from ::android::hardware::audio::V6_0::IPrimaryDevice follow.
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setVoiceVolume(float volume) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setMode(::android::hardware::audio::common::V6_0::AudioMode mode) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setBtScoHeadsetDebugName(const ::android::hardware::hidl_string& name) override;
    ::android::hardware::Return<void> getBtScoNrecEnabled(getBtScoNrecEnabled_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setBtScoNrecEnabled(bool enabled) override;
    ::android::hardware::Return<void> getBtScoWidebandEnabled(getBtScoWidebandEnabled_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setBtScoWidebandEnabled(bool enabled) override;
    ::android::hardware::Return<void> getBtHfpEnabled(getBtHfpEnabled_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setBtHfpEnabled(bool enabled) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setBtHfpSampleRate(uint32_t sampleRateHz) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setBtHfpVolume(float volume) override;
    ::android::hardware::Return<void> getTtyMode(getTtyMode_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setTtyMode(::android::hardware::audio::V6_0::IPrimaryDevice::TtyMode mode) override;
    ::android::hardware::Return<void> getHacEnabled(getHacEnabled_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> setHacEnabled(bool enabled) override;
    ::android::hardware::Return<::android::hardware::audio::V6_0::Result> updateRotation(::android::hardware::audio::V6_0::IPrimaryDevice::Rotation rotation) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;
    ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;
    ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> setHALInstrumentation() override;
    ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;
    ::android::hardware::Return<void> ping() override;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;
    ::android::hardware::Return<void> notifySyspropsChanged() override;
    ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

private:
    std::mutex _hidl_mMutex;
    std::vector<::android::sp<::android::hardware::hidl_binder_death_recipient>> _hidl_mDeathRecipients;
};

}  // namespace V6_0
}  // namespace audio
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_AUDIO_V6_0_BPHWPRIMARYDEVICE_H
