#ifndef HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_1_BNHWWIFICHIP_H
#define HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_1_BNHWWIFICHIP_H

#include <android/hardware/wifi/1.1/IHwWifiChip.h>

namespace android {
namespace hardware {
namespace wifi {
namespace V1_1 {

struct BnHwWifiChip : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwWifiChip(const ::android::sp<IWifiChip> &_hidl_impl);
    explicit BnHwWifiChip(const ::android::sp<IWifiChip> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwWifiChip();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IWifiChip Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef ::android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IWifiChip> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::hardware::wifi::V1_1::IWifiChip follow.
    static ::android::status_t _hidl_selectTxPowerScenario(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_resetTxPowerScenario(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::wifi::V1_0::IWifiChip follow.

    // Methods from ::android::hardware::wifi::V1_1::IWifiChip follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IWifiChip> _hidl_mImpl;
};

}  // namespace V1_1
}  // namespace wifi
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_1_BNHWWIFICHIP_H
