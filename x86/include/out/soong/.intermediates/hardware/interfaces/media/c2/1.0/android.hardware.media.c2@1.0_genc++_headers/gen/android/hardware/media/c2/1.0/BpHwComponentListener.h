#ifndef HIDL_GENERATED_ANDROID_HARDWARE_MEDIA_C2_V1_0_BPHWCOMPONENTLISTENER_H
#define HIDL_GENERATED_ANDROID_HARDWARE_MEDIA_C2_V1_0_BPHWCOMPONENTLISTENER_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/media/c2/1.0/IHwComponentListener.h>

namespace android {
namespace hardware {
namespace media {
namespace c2 {
namespace V1_0 {

struct BpHwComponentListener : public ::android::hardware::BpInterface<IComponentListener>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwComponentListener(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IComponentListener Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef ::android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    void onLastStrongRef(const void* id) override;

    // Methods from ::android::hardware::media::c2::V1_0::IComponentListener follow.
    static ::android::hardware::Return<void>  _hidl_onWorkDone(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::media::c2::V1_0::WorkBundle& workBundle);
    static ::android::hardware::Return<void>  _hidl_onTripped(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::SettingResult>& settingResults);
    static ::android::hardware::Return<void>  _hidl_onError(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::media::c2::V1_0::Status status, uint32_t errorCode);
    static ::android::hardware::Return<void>  _hidl_onFramesRendered(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::IComponentListener::RenderedFrame>& renderedFrames);
    static ::android::hardware::Return<void>  _hidl_onInputBuffersReleased(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::IComponentListener::InputBuffer>& inputBuffers);

    // Methods from ::android::hardware::media::c2::V1_0::IComponentListener follow.
    ::android::hardware::Return<void> onWorkDone(const ::android::hardware::media::c2::V1_0::WorkBundle& workBundle) override;
    ::android::hardware::Return<void> onTripped(const ::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::SettingResult>& settingResults) override;
    ::android::hardware::Return<void> onError(::android::hardware::media::c2::V1_0::Status status, uint32_t errorCode) override;
    ::android::hardware::Return<void> onFramesRendered(const ::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::IComponentListener::RenderedFrame>& renderedFrames) override;
    ::android::hardware::Return<void> onInputBuffersReleased(const ::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::IComponentListener::InputBuffer>& inputBuffers) override;

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

}  // namespace V1_0
}  // namespace c2
}  // namespace media
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_MEDIA_C2_V1_0_BPHWCOMPONENTLISTENER_H
