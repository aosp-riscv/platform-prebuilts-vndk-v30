#ifndef HIDL_GENERATED_ANDROID_FRAMEWORKS_DISPLAYSERVICE_V1_0_BNHWDISPLAYEVENTRECEIVER_H
#define HIDL_GENERATED_ANDROID_FRAMEWORKS_DISPLAYSERVICE_V1_0_BNHWDISPLAYEVENTRECEIVER_H

#include <android/frameworks/displayservice/1.0/IHwDisplayEventReceiver.h>

namespace android {
namespace frameworks {
namespace displayservice {
namespace V1_0 {

struct BnHwDisplayEventReceiver : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwDisplayEventReceiver(const ::android::sp<IDisplayEventReceiver> &_hidl_impl);
    explicit BnHwDisplayEventReceiver(const ::android::sp<IDisplayEventReceiver> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwDisplayEventReceiver();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IDisplayEventReceiver Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IDisplayEventReceiver> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::frameworks::displayservice::V1_0::IDisplayEventReceiver follow.
    static ::android::status_t _hidl_init(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_setVsyncRate(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_requestNextVsync(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_close(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::frameworks::displayservice::V1_0::IDisplayEventReceiver follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IDisplayEventReceiver> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace displayservice
}  // namespace frameworks
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_FRAMEWORKS_DISPLAYSERVICE_V1_0_BNHWDISPLAYEVENTRECEIVER_H
